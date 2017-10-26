CREATE TABLE `army_group` (
  `index` int(11) NOT NULL DEFAULT '0' COMMENT '��������',
  `id` int(11) NOT NULL DEFAULT '0' COMMENT '����ΨһID,�Ϸ�����֤',
  `state` tinyint(3) NOT NULL DEFAULT '0' COMMENT '����״̬',
  `statetime` int(11) NOT NULL DEFAULT '0' COMMENT '״̬ʱ���',
  `stateduration` int(11) NOT NULL DEFAULT '0' COMMENT '״̬����������',
  `type` tinyint(3) NOT NULL DEFAULT '0' COMMENT '��������',
  `from_type` tinyint(3) NOT NULL DEFAULT '0' COMMENT '�����ߵĶ�������',
  `from_id` int(11) NOT NULL DEFAULT '0' COMMENT '�����ߵĶ���ID',
  `from_index` int(11) NOT NULL DEFAULT '0' COMMENT '�����ߵĶ�������',
  `from_posx` smallint(6) NOT NULL DEFAULT '0' COMMENT '�����ߵĶ�������',
  `from_posy` smallint(6) NOT NULL DEFAULT '0' COMMENT '�����ߵĶ�������',
  `from_nation` tinyint(3) NOT NULL DEFAULT '0' COMMENT '�����ߵĹ���',
  `from_helpnum` tinyint(3) NOT NULL DEFAULT '0' COMMENT '����������ʣ�����',
  `to_type` tinyint(3) NOT NULL DEFAULT '0' COMMENT 'Ŀ�Ķ�������',
  `to_id` int(11) NOT NULL DEFAULT '0' COMMENT 'Ŀ�Ķ���ID',
  `to_index` int(11) NOT NULL DEFAULT '0' COMMENT 'Ŀ�Ķ�������',
  `to_posx` smallint(6) NOT NULL DEFAULT '0' COMMENT 'Ŀ�Ķ�������',
  `to_posy` smallint(6) NOT NULL DEFAULT '0' COMMENT 'Ŀ�Ķ�������',
  `to_nation` tinyint(3) NOT NULL DEFAULT '0' COMMENT 'Ŀ�Ĺ���',
  `to_helpnum` tinyint(3) NOT NULL DEFAULT '0' COMMENT 'Ŀ������ʣ�����',
  `leader_index` int(11) NOT NULL DEFAULT '0' COMMENT '�ӳ�����',
  `attack_armyindex` varbinary(512) NOT NULL DEFAULT '' COMMENT '��ʱ�洢���������Ჿ������',
  `defense_armyindex` varbinary(512) NOT NULL DEFAULT '' COMMENT '��ʱ�洢���������Ჿ������',
  PRIMARY KEY (`index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;