-- 界面
local m_Dlg = nil;
local m_uiTypeName = nil; --UnityEngine.GameObject
local m_uiLeftNation = nil; --UnityEngine.GameObject
local m_uiRightNation = nil; --UnityEngine.GameObject
local m_uiLeftName = nil; --UnityEngine.GameObject
local m_uiRightName = nil; --UnityEngine.GameObject
local m_uiLeftHeroList = nil; --UnityEngine.GameObject
local m_uiRightHeroList = nil; --UnityEngine.GameObject
local m_uiLeftHp = nil; --UnityEngine.GameObject
local m_uiRightHp = nil; --UnityEngine.GameObject
local m_uiSkipDesc = nil; --UnityEngine.GameObject
local m_uiSkipBtn = nil; --UnityEngine.GameObject
local m_uiLeftPk = nil; --UnityEngine.GameObject
local m_uiRightPk = nil; --UnityEngine.GameObject
local m_uiPkIcon = nil; --UnityEngine.GameObject
local m_uiTop = nil; --UnityEngine.GameObject
local m_uiBottom = nil; --UnityEngine.GameObject
local m_uiLeftHpEffect = nil; --UnityEngine.GameObject
local m_uiRightHpEffect = nil; --UnityEngine.GameObject
local m_uiLeftMissEffect = nil; --UnityEngine.GameObject
local m_uiRightMissEffect = nil; --UnityEngine.GameObject
local m_uiResultLayer = nil; --UnityEngine.GameObject
local m_uiTitle = nil; --UnityEngine.GameObject
local m_uiPicWin = nil; --UnityEngine.GameObject
local m_uiPicLose = nil; --UnityEngine.GameObject
local m_uiAwardGrid = nil; --UnityEngine.GameObject
local m_uiHeroList = nil; --UnityEngine.GameObject
local m_uiCloseBtn = nil; --UnityEngine.GameObject
local m_uiReturnCityBtn = nil; --UnityEngine.GameObject
local m_uiReturnStoryBtn = nil; --UnityEngine.GameObject

local m_recvValue = nil;
local m_jsonFightInfo = nil
local m_assetBundleName = ""

local m_uiLeftHeroCache = {} -- 左面武将信息缓存
local m_uiRightHeroCache = {}-- 右面武将信息缓存
local m_playing = 0;


-- 打开界面
function FightDlgOpen()
	m_Dlg = eye.uiManager:Open( "FightDlg" );
end

-- 隐藏界面
function FightDlgClose()
	if m_Dlg == nil then
		return;
	end
	for i=0, 3, 1 do
		local uiObj = m_uiHeroList.transform:GetChild( i )
		SetProgressStop( uiObj.transform:Find("Progress") )
	end	
	m_playing = 0;
	eye.uiManager:Close( "FightDlg" );
	FightScene.Delete()
end

-- 删除界面
function FightDlgDestroy()
	GameObject.Destroy( m_Dlg );
	m_Dlg = nil;
	Invoke( function() 
			ResourceManager.UnloadAssetBundleImmediately( "_ab_char_shape_infantry" )
		end, 0.3 );
end

----------------------------------------
-- 事件
----------------------------------------

-- 所属按钮点击时调用
function FightDlgOnEvent( nType, nControlID, value, gameObject )
	if nType == UI_EVENT_CLICK then
        if nControlID == -1 then
            FightDlgClose();
		
		-- 跳过战斗
		elseif nControlID == 1 then
			FightDlgResultLayerShow()
		
		-- 返回城池	
		elseif nControlID == 2 then
			FightDlgClose();
			
		-- 返回副本
		elseif nControlID == 3 then	
			FightDlgClose();
			
        end
		
	elseif nType == UI_EVENT_TWEENFINISH then
		if nControlID == 101 then
			SetFalse( m_uiLeftHpEffect )
		elseif nControlID == 102 then
			SetFalse( m_uiRightHpEffect )
		end
	end
end

-- 载入时调用
function FightDlgOnAwake( gameObject )
	-- 控件赋值	
	local objs = gameObject:GetComponent( typeof(UISystem) ).relatedGameObject;	
	m_uiTypeName = objs[0];
	m_uiLeftNation = objs[1];
	m_uiRightNation = objs[2];
	m_uiLeftName = objs[3];
	m_uiRightName = objs[4];
	m_uiLeftHeroList = objs[5];
	m_uiRightHeroList = objs[6];
	m_uiLeftHp = objs[7];
	m_uiRightHp = objs[8];
	m_uiSkipDesc = objs[9];
	m_uiSkipBtn = objs[10];
	m_uiLeftPk = objs[11];
	m_uiRightPk = objs[12];
	m_uiPkIcon = objs[13];
	m_uiTop = objs[14];
	m_uiBottom = objs[15];
	m_uiLeftHpEffect = objs[16];
	m_uiRightHpEffect = objs[17];
	m_uiLeftMissEffect = objs[18];
	m_uiRightMissEffect = objs[19];
	m_uiResultLayer = objs[20];
	m_uiTitle = objs[21];
	m_uiPicWin = objs[22];
	m_uiPicLose = objs[23];
	m_uiAwardGrid = objs[24];
	m_uiHeroList = objs[25];
	m_uiCloseBtn = objs[26];
	m_uiReturnCityBtn = objs[27];
	m_uiReturnStoryBtn = objs[28];
end

-- 界面初始化时调用
function FightDlgOnStart( gameObject )
	
end

-- 界面显示时调用
function FightDlgOnEnable( gameObject )
	
end

-- 界面隐藏时调用
function FightDlgOnDisable( gameObject )
	
end

-- 界面删除时调用
function FightDlgOnDestroy( gameObject )
	m_Dlg = nil;
end

-- 每帧调用
function FightDlgOnLogic( gameObject )
	
end


----------------------------------------
-- 自定
----------------------------------------
function FightDlgShow( recvValue )
	FightDlgOpen()
	SetFalse( m_uiTop )
	SetFalse( m_uiBottom )
	SetFalse( m_uiLeftHpEffect );
	SetFalse( m_uiRightHpEffect );
	SetFalse( m_uiResultLayer )
	
	m_playing = 0;
	m_recvValue = recvValue;
	local info = json.decode( m_recvValue.m_fight_content );
	m_jsonFightInfo = info;
	
	-- 显示战前信息
	FightInfoDlgShow( info );
	
	-- 战斗类型	
	local fighttype = info["ft"]
	if fighttype == nil then
		SetText( m_uiTypeName, "" )
	else
		SetText( m_uiTypeName, T(2000+fighttype-1) )
	end
	
	-- 战场对象初始化
	FightScene.Create()
	
	-- 战场初始化
	fight_init( info["randspeed"] );
	
	-- 我是攻击方，攻击方显示左面
	local my = m_recvValue.m_content_json["my"];
	if my == nil or my == 1 then
		-- 攻击方
		SetText( m_uiLeftName, FightInfoDlgGetName( info["a_type"], info["a_name"] ) );
		if info["a_nation"] > 0 then
			SetTrue( m_uiLeftNation )
			SetImage( m_uiLeftNation, NationSprite( info["a_nation"] ) );
		else
			SetFalse( m_uiLeftNation )
		end
		-- 防御方
		SetText( m_uiRightName, FightInfoDlgGetName( info["d_type"], info["d_name"] ) );
		if info["d_nation"] > 0 then
			SetTrue( m_uiRightNation )
			SetImage( m_uiRightNation, NationSprite( info["d_nation"] ) );
		else
			SetFalse( m_uiRightNation )
		end

		-- 攻击方对象
		for i=1, #info["a_unit"], 1 do
			local v =  info["a_unit"][i]
			fight_add_unit( FIGHT_ATTACK, v.i, v.t, v.kd, v.sp, v.lv, v.cr, v.cs, v.a1, v.a2, v.mhp, v.a3, v.a4, v.a5, v.a6, v.a7, v.a8, v.a9 )
		end
		
		-- 防御方对象
		for i=1, #info["d_unit"], 1 do
			local v =  info["d_unit"][i]
			fight_add_unit( FIGHT_DEFENSE, v.i, v.t, v.kd, v.sp, v.lv, v.cr, v.cs, v.a1, v.a2, v.mhp, v.a3, v.a4, v.a5, v.a6, v.a7, v.a8, v.a9 )
		end
	
	-- 我是防御方，防御方显示左面
	else
		-- 攻击方
		SetText( m_uiLeftName, FightInfoDlgGetName( info["d_type"], info["d_name"] ) );
		if info["d_nation"] > 0 then
			SetTrue( m_uiLeftNation )
			SetImage( m_uiLeftNation, NationSprite( info["d_nation"] ) );
		else
			SetFalse( m_uiLeftNation )
		end
		-- 防御方
		SetText( m_uiRightName, FightInfoDlgGetName( info["a_type"], info["a_name"] ) );
		if info["a_nation"] > 0 then
			SetTrue( m_uiRightNation )
			SetImage( m_uiRightNation, NationSprite( info["a_nation"] ) );
		else
			SetFalse( m_uiRightNation )
		end
			
		-- 攻击方对象
		for i=1, #info["d_unit"], 1 do
			local v =  info["d_unit"][i]
			fight_add_unit( FIGHT_ATTACK, v.i, v.t, v.kd, v.sp, v.lv, v.cr, v.cs, v.a1, v.a2, v.mhp, v.a3, v.a4, v.a5, v.a6, v.a7, v.a8, v.a9 )
		end
		
		-- 防御方对象
		for i=1, #info["a_unit"], 1 do
			local v =  info["a_unit"][i]
			fight_add_unit( FIGHT_DEFENSE, v.i, v.t, v.kd, v.sp, v.lv, v.cr, v.cs, v.a1, v.a2, v.mhp, v.a3, v.a4, v.a5, v.a6, v.a7, v.a8, v.a9 )
		end
	end
	FightDlgUnitUpdate()
end

-- 更新英雄阵列显示
function FightDlgUnitUpdate()
	for i=0, 3, 1 do
		local uiLeftObj = m_uiLeftHeroList.transform:GetChild(i)
		SetFalse( uiLeftObj.transform:GetChild(1) )
		SetFalse( uiLeftObj.transform:GetChild(2) )
		SetFalse( uiLeftObj.transform:GetChild(3) )
		SetFalse( uiLeftObj.transform:GetChild(4) )
		
		local uiRightObj = m_uiRightHeroList.transform:GetChild(i)
		SetFalse( uiRightObj.transform:GetChild(1) )
		SetFalse( uiRightObj.transform:GetChild(2) )
		SetFalse( uiRightObj.transform:GetChild(3) )
		SetFalse( uiRightObj.transform:GetChild(4) )
	end
	
	local index = 0;
	for i=1, g_fight.attack_unit_num, 1 do
		local unit = g_fight.attack_unit[i-1]
		if unit.line_left > 0 then
			FightDlgUnit( m_uiLeftHeroList.transform:GetChild(index), index, unit.type, unit.kind, unit.shape, unit.color, unit.corps, unit.level, unit.maxhp, unit.hp )
			index = index + 1
			if index >= 4 then
				break;
			end
		end
	end
	
	index = 0;
	for i=1, g_fight.defense_unit_num, 1 do
		local unit = g_fight.defense_unit[i-1]
		if unit.line_left > 0 then
			FightDlgUnit( m_uiRightHeroList.transform:GetChild(index), index, unit.type, unit.kind, unit.shape, unit.color, unit.corps, unit.level, unit.maxhp, unit.hp )
			index = index + 1
			if index >= 4 then
				break;
			end
		end
	end
	
	-- 对战信息
	FightDlgUnitVsUpdateName()
	FightDlgUnitVsUpdateHp()
	FightDlgUnitVsUpdateLayer()
end

-- 设置一个unit信息
function FightDlgUnit( uiObj, index, unittype, kind, shape, color, corps, level, maxhp, hp )
	SetTrue( uiObj.transform:GetChild(1) )
	SetTrue( uiObj.transform:GetChild(2) )
	SetTrue( uiObj.transform:GetChild(3) )
	
	SetImage( uiObj.transform:GetChild(1), FightDlgUnitShape( unittype, kind, shape ) );
	SetImage( uiObj.transform:GetChild(2), ItemColorSprite( color ) );
	SetImage( uiObj.transform:GetChild(3), CorpsSprite( corps ) );
	
	if index == 0 then
		SetFalse( uiObj.transform:GetChild(4) )
	else
		SetTrue( uiObj.transform:GetChild(4) )
		SetText( uiObj.transform:GetChild(4), FightDlgUnitName( unittype, kind ) );
	end
			
end

-- 设置战斗单元名称
function FightDlgUnitName( unittype, kind )
	-- 玩家 部队 资源点
	if unittype == FIGHT_UNITTYPE_LEADER_HERO or unittype == FIGHT_UNITTYPE_HERO then
		return HeroName( kind );
			
	-- 城镇
	elseif unittype == FIGHT_UNITTYPE_GUARD then
		return T( 1119 )
		
	-- 流寇
	elseif unittype == FIGHT_UNITTYPE_MONSTER then
		return EnemyName( kind )
	end
	return ""
end

-- 设置战斗单元名称
function FightDlgUnitShape( unittype, kind, shape )
	-- 玩家 部队 资源点
	if unittype == FIGHT_UNITTYPE_LEADER_HERO or unittype == FIGHT_UNITTYPE_HERO then
		return HeroHeadSprite( kind )
			
	-- 城镇
	elseif unittype == FIGHT_UNITTYPE_GUARD then
		return GuardSprite( shape )
		
	-- 流寇
	elseif unittype == FIGHT_UNITTYPE_MONSTER then
		return EnemyHeadSprite( shape )
	end
	return ""
end

-- 对战者名称
function FightDlgUnitVsUpdateName()
	local unit = fight_nextptr( FIGHT_ATTACK )
	if unit ~= nil then
		SetText( m_uiLeftHp.transform:Find("Name"), FightDlgUnitName( unit.type, unit.kind ) )
	end
	
	unit = fight_nextptr( FIGHT_DEFENSE )
	if unit ~= nil then
		SetText( m_uiRightHp.transform:Find("Name"), FightDlgUnitName( unit.type, unit.kind ) )
	end
end

-- 对战者血量
function FightDlgUnitVsUpdateHp()
	local unit = fight_nextptr( FIGHT_ATTACK )
	if unit ~= nil then
		SetText( m_uiLeftHp.transform:Find("Text"), unit.hp )
		SetProgress( m_uiLeftHp.transform:Find("Progress"), unit.hp/unit.maxhp )
	end
	
	unit = fight_nextptr( FIGHT_DEFENSE )
	if unit ~= nil then
		SetText( m_uiRightHp.transform:Find("Text"), unit.hp )
		SetProgress( m_uiRightHp.transform:Find("Progress"), unit.hp/unit.maxhp )
	end
end

-- 创建对战页信息
function FightDlgUnitVsUpdateLayer()
	local unit = fight_nextptr( FIGHT_ATTACK )
	if unit ~= nil then
		SetImage( m_uiLeftPk.transform:Find("UIP_Hero/Shape"), FightDlgUnitShape( unit.type, unit.kind, unit.shape ) )
		SetImage( m_uiLeftPk.transform:Find("UIP_Hero/Color"), ItemColorSprite( unit.color ) )
		SetImage( m_uiLeftPk.transform:Find("UIP_Hero/Corps"), CorpsSprite( unit.corps ) )
		SetText( m_uiLeftPk.transform:Find("Name"), FightDlgUnitName( unit.type, unit.kind ) )
		SetText( m_uiLeftPk.transform:Find("Hp/Text"), unit.hp )
	end
	
	unit = fight_nextptr( FIGHT_DEFENSE )
	if unit ~= nil then
		SetImage( m_uiRightPk.transform:Find("UIP_Hero/Shape"), FightDlgUnitShape( unit.type, unit.kind, unit.shape ) )
		SetImage( m_uiRightPk.transform:Find("UIP_Hero/Color"), ItemColorSprite( unit.color ) )
		SetImage( m_uiRightPk.transform:Find("UIP_Hero/Corps"), CorpsSprite( unit.corps ) )
		SetText( m_uiRightPk.transform:Find("Name"), FightDlgUnitName( unit.type, unit.kind ) )
		SetText( m_uiRightPk.transform:Find("Hp/Text"), unit.hp )
	end
end

-- 双方当前对战武将详情
function FightDlgUnitVsLayerShow()
	local leftTween = m_uiLeftPk.transform:GetComponent( "UITweenRectPosition" )
	leftTween:Play( true )
	
	local rightTween = m_uiRightPk.transform:GetComponent( "UITweenRectPosition" )
	rightTween:Play( true )
	
	Invoke( function() 
		SetTrue( m_uiPkIcon )
	end, 0.5 );
		
	Invoke( function() 
		SetFalse( m_uiPkIcon )
		leftTween:Play( false )
		rightTween:Play( false )
	end, 1.5 );
end

-- 播放血动画
function FightDlgPlayHpEffect( pos, hp, crit )
	local uiObj = nil
	if pos == FIGHT_ATTACK then
		uiObj = m_uiLeftHpEffect
	else
		uiObj = m_uiRightHpEffect
	end
	
	SetFalse( uiObj );
	for i=0, uiObj.transform.childCount-1, 1 do
		SetFalse( uiObj.transform:GetChild(i) );
	end
	
	SetTrue( uiObj );
	
	uiObj.transform.localScale = Vector3.New( 1, 1, 1 );
	local color = NameColor( 4 )
	if crit == 1 then
		color = Hex2Color( 0xECC244FF )
		uiObj.transform.localScale = Vector3.New( 1.5, 1.5, 1 );
	end
	
	-- 计算位数 +1减号算一位
	local hpstr = "-"..hp
	local hpnum = string.len( hpstr )
	local offset = math.floor( (10-hpnum)/2 )
	
	local index = 1;
	for i=offset, offset+hpnum, 1 do
		SetText( uiObj.transform:GetChild(i), string.sub( hpstr, index,index ), color )
		uiObj.transform:GetChild(i).transform:GetComponent( "UITweenRectPosition" ).delay = (index-1)*0.1
		SetTrue( uiObj.transform:GetChild(i) );
		index = index + 1
	end
	
	Invoke( function()
			SetFalse( uiObj );
	end, 1 )
end


-- 播放Miss动画
function FightDlgPlayMissEffect( pos )
	if pos == FIGHT_ATTACK then
		SetFalse( m_uiLeftMissEffect );
		SetTrue( m_uiLeftMissEffect );
		Invoke( function()
			SetFalse( m_uiLeftMissEffect );
		end, 0.8 )
	else
		SetFalse( m_uiRightMissEffect );
		SetTrue( m_uiRightMissEffect );
		Invoke( function()
			SetFalse( m_uiRightMissEffect );
		end, 0.8 )
	end
end

-- 启动战斗
function FightDlgStart()
	if m_playing == 1 then
		return
	end
	SetTrue( m_uiTop )
	SetTrue ( m_uiBottom )
	m_playing = 1;
	
	FightDlgUnitVsLayerShow()
	
	-- 进场音效
	eye.audioManager:Play(301);
	
	-- 创建军阵
	FightScene.UnitCreate( FIGHT_ATTACK, fight_nextptr( FIGHT_ATTACK ) )
	FightScene.UnitCreate( FIGHT_DEFENSE, fight_nextptr( FIGHT_DEFENSE ) )
	
	-- 军阵移动
	FightScene.UnitWalk( FIGHT_ATTACK, fight_nextptr( FIGHT_ATTACK ) )
	FightScene.UnitWalk( FIGHT_DEFENSE, fight_nextptr( FIGHT_DEFENSE ) )
	
	-- 战斗逻辑启动
	Invoke( function()
		g_fight.frame_max = 2;
		fight_start()
	end, 2, nil, "Fight_Start" )
end

-- 战斗结束页
function FightDlgResultLayerShow()
	if m_jsonFightInfo == nil then
		FightDlgClose()
		return
	end
	eye.audioManager:Stop(202);
	eye.audioManager:Stop(301);
	eye.audioManager:Stop(305);
	fight_destory()
	SetTrue( m_uiResultLayer )
	
	-- 战斗类型	
	local fighttype = m_jsonFightInfo["ft"]
	if fighttype == nil then
		SetText( m_uiTitle.transform:Find("Text"), "" )
	else
		SetText( m_uiTitle.transform:Find("Text"), T(2000+fighttype-1) )
	end
	
	-- 战斗结果
	local my = m_recvValue.m_content_json["my"];
	local fightResult = m_jsonFightInfo["fr"]
	if fightResult == 1 then
		-- 如果是攻击方
		if my == nil or my == 1 then
			SetTrue( m_uiPicWin ) 
			SetFalse( m_uiPicLose ) 
			eye.audioManager:Play(408);
		else
			SetTrue( m_uiPicLose ) 
			SetFalse( m_uiPicWin )
			eye.audioManager:Play(409);
		end
	else
		if my == nil or my == 1 then
			SetTrue( m_uiPicLose ) 
			SetFalse( m_uiPicWin )
			eye.audioManager:Play(409);
		else
			SetTrue( m_uiPicWin ) 
			SetFalse( m_uiPicLose ) 
			eye.audioManager:Play(408);
		end
	end
	
	for i=0, 3, 1 do
		SetFalse( m_uiAwardGrid.transform:GetChild( i ) )
	end	
	for i=0, 3, 1 do
		SetFalse( m_uiHeroList.transform:GetChild( i ) )
	end	
	
	local index = 0
	local awardTable = {}
	-- 经验奖励	
	local exp = m_recvValue.m_content_json["exp"]
	if exp ~= nil then
		awardTable[index] = { kind = AWARDKIND_EXP, num = exp }
		index = index + 1
	end
	
	-- 资源奖励
	local silver = m_recvValue.m_content_json["silver"]
	if silver ~= nil then
		awardTable[index] = { kind = AWARDKIND_SILVER, num = silver }
		index = index + 1
	end
	
	local wood = m_recvValue.m_content_json["wood"]
	if wood ~= nil then
		awardTable[index] = { kind = AWARDKIND_WOOD, num = wood }
		index = index + 1
	end
	
	local food = m_recvValue.m_content_json["food"]
	if food ~= nil then
		awardTable[index] = { kind = AWARDKIND_FOOD, num = food }
		index = index + 1
	end
	
	local people = m_recvValue.m_content_json["people"]
	if people ~= nil then
		awardTable[index] = { kind = AWARDKIND_PEOPLE, num = people }
		index = index + 1
	end

	-- 道具奖励
	local awardstr = ""
	local award = m_recvValue.m_content_json["award"];
	if award ~= nil then
		local awardList = string.split( award, '@' )
		for i= 1, #awardList, 1 do
			local awardinfo = string.split( awardList[i], ',' )
			if #awardinfo == 2 then
				local kind = tonumber(awardinfo[1]);
				local num = tonumber(awardinfo[2]);
				awardTable[index] = { kind = kind, num = num }
				index = index + 1
			end
		end
	end	
	
	if index > 3 then
		index = 3
	end
	for i=0, index-1, 1 do
		local sprite, color, name = AwardInfo( awardTable[i].kind )
		local uiAward = m_uiAwardGrid.transform:GetChild( i )
		SetTrue( uiAward )
		SetImage( uiAward.transform:Find("Icon"), sprite );
		SetText( uiAward.transform:Find("Name"), name.."x"..awardTable[i].num  )
	end			
	
	-- 英雄
	-- m_uiHeroList = objs[25];
	local unitlist = nil
	local my = m_recvValue.m_content_json["my"];
	if my == nil or my == 1 then
		-- 攻击方对象
		unitlist = m_jsonFightInfo["a_unit"];
	else
		-- 防御方对象
		unitlist = m_jsonFightInfo["d_unit"];
	end
	
	local index = 0;
	for k, v in pairs(unitlist) do
		if v.t == FIGHT_UNITTYPE_LEADER_HERO then
			local uiObj = m_uiHeroList.transform:GetChild( index )
			SetImage( uiObj.transform:Find("Shape"), HeroHeadSprite( v.kd ) )
			SetImage( uiObj.transform:Find("Color"), ItemColorSprite( v.cr ) )
			
			-- 获取经验
			if v.exp ~= nil then 
				SetText( uiObj.transform:Find("Exp"), "+"..v.exp )
			else
				SetText( uiObj.transform:Find("Exp"), "+0" )
			end
			
			-- 检查是否升级
			local beginvalue = v.mexp/hero_getexp_max( v.lv, v.cr );
			local playcount = 1;
			local isup = 0;
			local level =  v.lv;
			v.mexp = v.mexp + v.exp;
			while v.mexp >= hero_getexp_max( v.lv, v.cr ) do
				local curlevel = v.lv;
				-- 可以升级
				if curlevel >= global.actorlevel_max then
					break
				end
				v.lv = v.lv + 1;
				v.mexp = v.mexp - hero_getexp_max( curlevel, v.cr );
				isup = isup + 1;
				playcount = playcount + 1
			end
			local endvalue = v.mexp/hero_getexp_max( v.lv, v.cr );
			
			-- 进度条SetProgressPlay( transform, beginvalue, endvalue, duration, playcount )
			if v.mexp ~= nil then
				SetProgressPlay( uiObj.transform:Find("Progress"), beginvalue, endvalue, 2, playcount, function() 
					-- 名称+等级
					level = level + 1
					if level > v.lv then
						level = v.lv
					end
					SetText( uiObj.transform:Find("Name"), HeroNameLv( v.kd, level ) )
				end )
			else
				SetProgress( uiObj.transform:Find("Progress"), 0 )
			end
			
			SetTrue( uiObj )
			index = index + 1
			if index >= 4 then
				break
			end
		end
	end
			
	-- 副本战斗返回按钮
	if fighttype == FIGHTTYPE_STORY then
		SetFalse( m_uiCloseBtn )
		SetTrue( m_uiReturnCityBtn )
		SetTrue( m_uiReturnStoryBtn )
	else
		SetTrue( m_uiCloseBtn )
		SetFalse( m_uiReturnCityBtn )
		SetFalse( m_uiReturnStoryBtn )
	end
end
