CREATE TABLE `army_group` (
  `index` int(11) NOT NULL DEFAULT '0' COMMENT '集结索引',
  `id` int(11) NOT NULL DEFAULT '0' COMMENT '集结唯一ID,合法性验证',
  `state` tinyint(3) NOT NULL DEFAULT '0' COMMENT '集结状态',
  `statetime` int(11) NOT NULL DEFAULT '0' COMMENT '状态时间戳',
  `stateduration` int(11) NOT NULL DEFAULT '0' COMMENT '状态持续多少秒',
  `from_type` tinyint(3) NOT NULL DEFAULT '0' COMMENT '发起者的对象类型',
  `from_id` int(11) NOT NULL DEFAULT '0' COMMENT '发起者的对象ID',
  `from_index` int(11) NOT NULL DEFAULT '0' COMMENT '发起者的对象索引',
  `from_posx` smallint(6) NOT NULL DEFAULT '0' COMMENT '发起者的对象坐标',
  `from_posy` smallint(6) NOT NULL DEFAULT '0' COMMENT '发起者的对象坐标',
  `to_type` tinyint(3) NOT NULL DEFAULT '0' COMMENT '目的对象类型',
  `to_id` int(11) NOT NULL DEFAULT '0' COMMENT '目的对象ID',
  `to_index` int(11) NOT NULL DEFAULT '0' COMMENT '目的对象索引',
  `to_posx` smallint(6) NOT NULL DEFAULT '0' COMMENT '目的对象坐标',
  `to_posy` smallint(6) NOT NULL DEFAULT '0' COMMENT '目的对象坐标',
  `leader_index` int(11) NOT NULL DEFAULT '0' COMMENT '队长索引',
  `attack_armyindex` varbinary(512) NOT NULL DEFAULT '' COMMENT '临时存储攻击方集结部队索引',
  `defense_armyindex` varbinary(512) NOT NULL DEFAULT '' COMMENT '临时存储防御方集结部队索引',
  PRIMARY KEY (`index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
