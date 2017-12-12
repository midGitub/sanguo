FIGHTTYPE_STORY		=	1 -- 副本战
FIGHTTYPE_CITY		=	2 -- 城战
FIGHTTYPE_NATION	=	3 -- 国战
FIGHTTYPE_ENEMY		=	4 -- 流寇战
FIGHTTYPE_RES		=	5 -- 资源战
FIGHTTYPE_WORLDBOSS	=	6 -- 世界boss
FIGHTTYPE_KINGWAR	=	7 -- 皇城血战

FIGHT_UNIT_MAX		=	256
FIGHT_TURNS_MAX		=	8192
FIGHT_INT			=	100
FIGHT_FLOAT			=	100.0
FIGHT_WIN			=	1	
FIGHT_LOSE			=	2
FIGHT_ATTACK		=	1	
FIGHT_DEFENSE		=	2

g_hero_corpsmul_maxnum = 3;
g_hero_skill_maxnum = #g_hero_skill
s_fight_posname = { [0]="", [1]="attack", [2]="defense" };

-- 一个战斗单元结构
FightUnit = class("FightUnit")
function FightUnit:ctor()
	self:empty();
end

function FightUnit:empty()
	
	self.offset = 0;

	self.type = 0;				-- 
	self.kind = 0;				-- 

	self.shape = 0;				-- 形象
	self.level = 0;				-- 等级
	self.color = 0;				-- 颜色
	self.corps = 0;				-- 兵种
	
	self.attack = 0;			-- 攻击
	self.defense = 0;			-- 防御
	self.hp = 0;				-- 当前血
	self.maxhp = 0;				-- 参战时血
	self.troops = 0;			-- 血上限
	self.attack_increase = 0;	-- 攻击增强
	self.defense_increase = 0;	-- 防御增强
	self.assault = 0;			-- 攻城
	self.defend = 0;			-- 守城
	self.line = 0;				-- 带兵排数
	self.skillid = 0;			-- 武将技

	self.line_left = 0;			-- 当前剩余排数
	self.line_hp = 0;			-- 当前排剩余兵力
	self.damage = 0;			-- 总伤害
	return self;
end

-- 全局战场
g_fight = {};
g_fight.playing = 0
g_fight.frame = 0;
g_fight.frame_max = 1
function fight_init( randspeed )
	g_fight.turns = 0;
	g_fight.randspeed = randspeed;
	g_fight.frame = 0;
	g_fight.frame_max = 1
	g_fight.playing = 0
	g_fight.attack_unit = {}
	g_fight.defense_unit ={}
	for i=0, FIGHT_UNIT_MAX-1, 1 do
		g_fight.attack_unit[i] = FightUnit.new();	-- 攻击方单元列表
		g_fight.defense_unit[i] = FightUnit.new();	-- 防御方单元列表
	end

	g_fight.attack_unit_num = 0;	-- 攻击方单元数量
	g_fight.defense_unit_num = 0;	-- 防御方单元数量

	g_fight.attack_unit_index = 0;	-- 攻击方当前出战单元
	g_fight.defense_unit_index = 0;	-- 防御方当前出战单元

	g_fight.attack_total_hp = 0;
	g_fight.defense_total_hp = 0;

	g_fight.attack_total_maxhp = 0;
	g_fight.defense_total_maxhp = 0;

	g_fight.attack_total_damage = 0;
	g_fight.defense_total_damage = 0;
end

-- 向战场里添加一个战斗单元
function fight_add_unit( pos, offset, type, kind, shape, level, color, corps, attack, defense, hp, troops, attack_increase, defense_increase, assault, defend, line, skillid )
	local pUnit = nil;
	if  pos == FIGHT_ATTACK then
		if offset < FIGHT_UNIT_MAX - 1 then
			pUnit = g_fight.attack_unit[offset];
			g_fight.attack_unit_num = g_fight.attack_unit_num + 1;
			g_fight.attack_total_hp = g_fight.attack_total_hp + hp;
			g_fight.attack_total_maxhp = g_fight.attack_total_maxhp + hp;
		end
	else
		if offset < FIGHT_UNIT_MAX - 1 then
			pUnit = g_fight.defense_unit[offset];
			g_fight.defense_unit_num = g_fight.defense_unit_num + 1;
			g_fight.defense_total_hp = g_fight.defense_total_hp + hp;
			g_fight.defense_total_maxhp = g_fight.defense_total_maxhp + hp;
		end
	end
	if pUnit == nil then
		return -1;
	end
	
	pUnit.offset = offset;
	pUnit.type = type;
	pUnit.index = index;
	pUnit.kind = kind;
	pUnit.shape = shape;
	pUnit.level = level;
	pUnit.color = color;
	pUnit.corps = corps;
	pUnit.attack = attack;
	pUnit.defense = defense;
	pUnit.hp = hp;
	pUnit.maxhp = hp;
	pUnit.troops = troops;
	pUnit.attack_increase = attack_increase;
	pUnit.defense_increase = defense_increase;
	pUnit.assault = assault;
	pUnit.defend = defend;
	pUnit.line = line;
	pUnit.skillid = skillid;
	pUnit.line_left = line;
	pUnit.line_hp = math.ceil( hp / line );
	pUnit.damage = 0;
	return 0;
end

function fight_destory()
	InvokeStop("Fight_Start")
	InvokeStop("Fight_Invoke_0")
	InvokeStop("Fight_Invoke_1")
	InvokeStop("Fight_Invoke_2")
	InvokeStop("Fight_Invoke_3")
	InvokeStop("Fight_Invoke_11")
	InvokeStop("Fight_Invoke_12")
	InvokeStop("Fight_Invoke_13")
	InvokeStop("Fight_Invoke_20")
	g_fight.playing = 0
end

function fight_start()
	g_fight.playing = 1
end

function fight_stop()
	g_fight.playing = 0
end

function fight_logic()
	if g_fight.playing == 0 then
		return
	end
	
	-- 战斗速度控制
	g_fight.frame = g_fight.frame + 1;
	if g_fight.frame < g_fight.frame_max then
		return
	end
	g_fight.frame = 0
	
	local result = fight_oneturn()
	if result > 0 then
		if  result == FIGHT_WIN then
			fight_debug( "[ATK WIN]" );
		elseif result == FIGHT_LOSE then
			fight_debug( "[DEF WIN]" );
		end
		FightDlgResultLayerShow()
	end
	
end
-- 一回合
function fight_oneturn()
	local attack_damage = 0;
	local defense_damage = 0;
	local attack_crit = 0;
	local defense_crit = 0;
	local result = 0;
	local left_change_line = 0;
	local left_change_unit = 0;
	local right_change_line = 0;
	local right_change_unit = 0;
	g_fight.frame_max = 2;
	
	g_fight.turns = g_fight.turns + 1;
	fight_debug( "--------------------------- [turns-%d] ---------------------------", g_fight.turns );

	-- 攻击方当前出手英雄
	local pAttackUnit = fight_nextptr( FIGHT_ATTACK );
	if pAttackUnit == nil then
		return FIGHT_LOSE
	end

	-- 防守方当前出手英雄
	local pDefenseUnit = fight_nextptr( FIGHT_DEFENSE );
	if pDefenseUnit == nil then
		return FIGHT_WIN;
	end
	
	-- 双方使用出场技能
	attack_damage = fight_useskill( FIGHT_ATTACK, pAttackUnit, pDefenseUnit );
	defense_damage = fight_useskill( FIGHT_DEFENSE, pDefenseUnit, pAttackUnit );
	if attack_damage > 0 then	
		result, right_change_line, right_change_unit = fight_changehp( FIGHT_ATTACK, pDefenseUnit, attack_damage );
		if result > 0 then
			return result;
		end
	end
	if defense_damage > 0 then
		result, left_change_line, left_change_unit  = fight_changehp( FIGHT_DEFENSE, pAttackUnit, defense_damage );
		if result > 0 then
			return result;
		end
	end
	
	-- 播放动画-攻击
	FightScene.UnitAttack( FIGHT_ATTACK )
	FightScene.UnitAttack( FIGHT_DEFENSE )
		
	Invoke( function() 
					
		-- 双方出手攻击
		attack_damage, attack_crit = fight_damage( FIGHT_ATTACK, pAttackUnit, pDefenseUnit );
		defense_damage, defense_crit = fight_damage( FIGHT_DEFENSE, pDefenseUnit, pAttackUnit );
		
		-- 攻击音效
		if attack_crit == 1 or defense_crit == 1 then
			eye.audioManager:Play(306);
		else
			eye.audioManager:Play(307);
		end
				
		-- 播放伤害
		if attack_damage <= 0 then
			FightDlgPlayMissEffect( FIGHT_DEFENSE )
		else
			FightDlgPlayHpEffect( FIGHT_DEFENSE, attack_damage, attack_crit )
		end
		if defense_damage <= 0 then
			FightDlgPlayMissEffect( FIGHT_ATTACK )
		else
			FightDlgPlayHpEffect( FIGHT_ATTACK, defense_damage, defense_crit )
		end
		
		if attack_damage > 0 then
			result, right_change_line, right_change_unit  = fight_changehp( FIGHT_ATTACK, pDefenseUnit, attack_damage );
			if result > 0 then
				-- 删除一排部队
				FightScene.UnitDead( FIGHT_DEFENSE )
				-- 更新界面显示
				FightDlgUnitUpdate()
				return result;
			end
			
			-- 播放动画-排数改变
			if right_change_line == 1 then
				-- 删除一排部队
				FightScene.UnitDead( FIGHT_DEFENSE )
				-- 后续排前进
				Invoke( function() 
					-- 上前音效
					eye.audioManager:Play(305);
					FightScene.UnitWalk( FIGHT_DEFENSE, pDefenseUnit )
				end, 2, nil, "Fight_Invoke_1" );
				g_fight.frame_max = 4;
				
			end
			-- 播放动画-武将改变
			if right_change_unit == 1 and result <= 0 then
				-- 创建军阵
				Invoke( function() 
					-- 进场音效
					eye.audioManager:Play(301);
					FightScene.UnitCreate( FIGHT_DEFENSE, fight_nextptr( FIGHT_DEFENSE ) )
				end, 2, nil, "Fight_Invoke_2" );
				-- 移动军阵
				Invoke( function() 
					FightScene.UnitWalk( FIGHT_DEFENSE, fight_nextptr( FIGHT_DEFENSE ) )
				end, 2, nil, "Fight_Invoke_3" );
				g_fight.frame_max = 5;
			end
			-- 更新界面显示
			FightDlgUnitUpdate()
		end
	
		if defense_damage > 0 then
			result, left_change_line, left_change_unit  = fight_changehp( FIGHT_DEFENSE, pAttackUnit, defense_damage );
			if result > 0 then
				-- 删除一排部队
				FightScene.UnitDead( FIGHT_ATTACK )
				-- 更新界面显示
				FightDlgUnitUpdate()
				return result;
			end
			
			-- 播放动画-排数改变
			if left_change_line == 1 then
				-- 删除一排部队
				FightScene.UnitDead( FIGHT_ATTACK )
				-- 后续排前进
				Invoke( function()
					-- 上前音效
					eye.audioManager:Play(305);
					FightScene.UnitWalk( FIGHT_ATTACK, pAttackUnit )
				end, 2, nil, "Fight_Invoke_11" );
				g_fight.frame_max = 4;
				
			end
			-- 播放动画-武将改变
			if left_change_unit == 1 and result <= 0 then
				-- 创建军阵
				Invoke( function() 
					-- 进场音效
					eye.audioManager:Play(301);
					FightScene.UnitCreate( FIGHT_ATTACK, fight_nextptr( FIGHT_ATTACK ) )
				end, 2, nil, "Fight_Invoke_12" );
				-- 移动军阵
				Invoke( function() 
					FightScene.UnitWalk( FIGHT_ATTACK, fight_nextptr( FIGHT_ATTACK ) )
				end, 2, nil, "Fight_Invoke_13" );
				g_fight.frame_max = 5;
			end
			-- 更新界面显示
			FightDlgUnitUpdate()
		end
		
		-- 对战界面对战信息页
		if left_change_unit == 1 or right_change_unit == 1 then
			Invoke( function() 
				FightDlgUnitVsUpdateLayer()
				FightDlgUnitVsLayerShow()
				-- 更新界面显示
				FightDlgUnitUpdate()
			end, 3, nil, "Fight_Invoke_20" );
		end
	end, 0.6, nil, "Fight_Invoke_0" );
	return 0;
end

-- 兵种相克系数
function _corpsmul( corps, target_corps )
	if corps < 0 or corps >= g_hero_corpsmul_maxnum then
		return FIGHT_INT;
	end
	if target_corps < 0 or target_corps >= g_hero_corpsmul_maxnum then
		return FIGHT_INT;
	end
	if target_corps == 0 then
		return g_hero_corpsmul[corps].target_corps0
	elseif target_corps == 1 then
		return g_hero_corpsmul[corps].target_corps1
	else
		return g_hero_corpsmul[corps].target_corps2
	end
end

-- 自定义随机
function random_custom( minv, maxv )
	local value = (maxv - minv + 1);
	if value <= 0 then
		value = 1;
	end
	g_fight.randspeed = (7 * g_fight.randspeed) % 65535;
	local v = minv + g_fight.randspeed % value;
	fight_debug( "random_custom:%d,%d,min:%d,value:%d",g_fight.randspeed, v, minv, value );
	return v;
end

function fight_debug( msg, ... )
	local str = string.format( msg, ... );
	--LogUtil.GetInstance():WriteGame( str );
	--print( str )
end

-- 使用出场技能
function fight_useskill( pos, pUnit, pTargetUnit )
	local true_damage = 0;
	local damage = 0;
	local skillid = pUnit.skillid;
	if skillid > 0 and skillid < g_hero_skill_maxnum then
		-- 攻击方释放武将技
		local randomv = random_custom( g_hero_skill[skillid].randmin, g_hero_skill[skillid].randmax );
		damage = math.ceil( ( pUnit.hp * (g_hero_skill[skillid].value / FIGHT_FLOAT) * (randomv / FIGHT_FLOAT)) );
		true_damage = damage;
		damage = math.min( damage, pTargetUnit.line_hp );
		fight_debug( "[%s](skill) idx:%d,kind:%d,damage:%d(%d),target_idx:%d,target_kind:%d,line_left:%d,line_hp:(%d-%d=%d)", s_fight_posname[pos], pUnit.offset, pUnit.kind, damage, true_damage, pTargetUnit.offset, pTargetUnit.kind, pTargetUnit.line_left, pTargetUnit.line_hp, damage, pTargetUnit.line_hp - damage );
		pUnit.skillid = 0;
		pUnit.damage = pUnit.damage + damage;
	end
	return damage;
end

-- 普通攻击
function fight_damage( pos, pUnit, pTargetUnit )
	local true_damage = 0;
	local damage = 0;
	local crit = 0;
	-- 1.首先判断是否闪避
	local dodge = random_custom( 1, 100 );
	if dodge <= global.fight_dodge then
		-- 闪避了
		fight_debug( "[%s](miss) idx:%d,kind:%d,damage:%d,target_idx:%d,target_kind:%d,line_left:%d,line_hp:%d", s_fight_posname[pos], pUnit.offset, pUnit.kind, 0, pTargetUnit.offset, pTargetUnit.kind, pTargetUnit.line_left, pTargetUnit.line_hp );
	else
		-- 2.计算基础伤害
		-- 基础伤害=（攻方攻击力-防方防御力）*（0.5+0.5*攻方当前兵力/防方当前兵力）*兵种克制系数*战斗节奏控制系数+攻方强攻-防方强防+攻方攻城-防方守城
		damage = math.ceil( (pUnit.attack - pTargetUnit.defense) * ((global.fight_v1 / FIGHT_FLOAT) + (global.fight_v2 / FIGHT_FLOAT) * pUnit.line_hp / pTargetUnit.line_hp) * (_corpsmul( pUnit.corps, pTargetUnit.corps ) / FIGHT_FLOAT) * (global.fight_control_value / FIGHT_FLOAT) );
		damage = damage + (pUnit.attack_increase - pTargetUnit.defense_increase);
		damage = damage + (pUnit.assault - pTargetUnit.defend);

		-- 3.设定保底伤害
		-- 基础保底伤害 = Max（攻方攻击 * 5 % ，基础伤害）
		damage = math.max( math.ceil( pUnit.attack * (global.fight_attackmin_value / FIGHT_FLOAT) ), damage );

		-- 4.计算暴击伤害
		local randomv = random_custom( global.fight_damage_randmin, global.fight_damage_randmax );
		local crit_odds = random_custom( 1, 100 );
		if crit_odds <= global.fight_crit_odds then
			crit = 1;
			damage = math.ceil( damage * (global.fight_crit_damage / FIGHT_FLOAT) * (randomv / FIGHT_FLOAT) );
			true_damage = damage;
			damage = math.min( damage, pTargetUnit.line_hp );
			fight_debug( "[%s](crit) idx:%d,kind:%d,damage:%d(%d),target_idx:%d,target_kind:%d,line_left:%d,line_hp:(%d-%d=%d)", s_fight_posname[pos], pUnit.offset, pUnit.kind, damage, true_damage, pTargetUnit.offset, pTargetUnit.kind, pTargetUnit.line_left, pTargetUnit.line_hp, damage, pTargetUnit.line_hp - damage );
		else
		-- 没暴击
			damage = math.ceil( damage * (randomv / FIGHT_FLOAT) );
			true_damage = damage;
			damage = math.min( damage, pTargetUnit.line_hp );
			fight_debug( "[%s](default) idx:%d,kind:%d,damage:%d(%d),target_idx:%d,target_kind:%d,line_left:%d,line_hp:(%d-%d=%d)", s_fight_posname[pos], pUnit.offset, pUnit.kind, damage, true_damage, pTargetUnit.offset, pTargetUnit.kind, pTargetUnit.line_left, pTargetUnit.line_hp, damage, pTargetUnit.line_hp - damage );
		end
		pUnit.damage = pUnit.damage + damage;
	end
	return damage, crit;
end

-- 减血
function fight_changehp( pos, pTargetUnit, damage )
	local change_line = 0; -- 排数是否改变
	local change_unit = 0; -- 武将是否改变
	-- 总击杀和总死亡
	if pos == FIGHT_ATTACK then
		g_fight.defense_total_hp = g_fight.defense_total_hp - damage;
		g_fight.attack_total_damage = g_fight.attack_total_damage + damage;
	else
		g_fight.attack_total_hp = g_fight.attack_total_hp - damage;
		g_fight.defense_total_damage = g_fight.defense_total_damage + damage;
	end

	pTargetUnit.hp = pTargetUnit.hp - damage;
	if pTargetUnit.hp < 0 then
		pTargetUnit.hp = 0;
	end
	pTargetUnit.line_hp = pTargetUnit.line_hp - damage;
	if pTargetUnit.line_hp <= 0 then
		pTargetUnit.line_left = pTargetUnit.line_left - 1;
		change_line = 1; -- 排数是否改变
		if pTargetUnit.line_left > 0 then
			-- 减少一排
			pTargetUnit.line_hp = math.ceil( pTargetUnit.maxhp / pTargetUnit.line );
		else
			pTargetUnit.hp = 0;
			if pos == FIGHT_ATTACK then
				local nextunit = fight_nextptr( FIGHT_DEFENSE )
				if nextunit == nil then
					return FIGHT_WIN, change_line, change_unit;
				end
				change_unit = 1; -- 武将改变
				fight_debug( "[%s](up) idx:%d,kind:%d", s_fight_posname[FIGHT_DEFENSE], nextunit.offset, nextunit.kind );
			else
				local nextunit = fight_nextptr( FIGHT_ATTACK )
				if nextunit == nil then
					return FIGHT_LOSE, change_line, change_unit;
				end
				change_unit = 1; -- 武将改变
				fight_debug( "[%s](up) idx:%d,kind:%d", s_fight_posname[FIGHT_ATTACK], nextunit.offset, nextunit.kind );
			end
		end
	end
	return 0, change_line, change_unit;
end

-- 出阵英雄
function fight_nextptr( pos )
	if pos == FIGHT_ATTACK then
		if g_fight.attack_unit_index >= 0 and g_fight.attack_unit_index < FIGHT_UNIT_MAX then
			for tmpi = g_fight.attack_unit_index, g_fight.attack_unit_num-1, 1 do
				if g_fight.attack_unit[tmpi].hp > 0 then
					g_fight.attack_unit_index = tmpi;
					return g_fight.attack_unit[tmpi];
				end
			end
		end
	else
		if g_fight.defense_unit_index >= 0 and g_fight.defense_unit_index < FIGHT_UNIT_MAX then
			for tmpi = g_fight.defense_unit_index,  g_fight.defense_unit_num-1, 1 do
				if g_fight.defense_unit[tmpi].hp > 0 then
					g_fight.defense_unit_index = tmpi;
					return g_fight.defense_unit[tmpi];
				end
			end
		end
	end
	return nil;
end
