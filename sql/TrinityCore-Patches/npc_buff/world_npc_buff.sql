DROP TABLE IF EXISTS `npc_buff_spells`;

CREATE TABLE `npc_buff_spells` (
  `spell_id` int(5) NOT NULL default '0' COMMENT 'Spell entry number',
  `cat_number` int(5) NOT NULL default '0' COMMENT '0-small buff 1-great buff 2-gm buff 3-player tools',
  `cost` int(10) NOT NULL default '0' COMMENT 'cost amount in copper',
  `name` text COMMENT 'Name of spell',
  PRIMARY KEY  (`spell_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

/*Data for the table `npc_buff_spells` */

INSERT INTO `npc_buff_spells` (`spell_id`, `cat_number`, `cost`, `name`) VALUES
-- Small Buff
(48469,1001,10000,"Mark of the Wild"),
(53307,1002,10000,"Thorns"),
(43017,1003,10000,"Amplify Magic"),
(42995,1004,10000,"Arcane Intellect"),
(61024,1005,10000,"Dalaran Intellect"),
(43015,1006,10000,"Dampen Magic"),
(20217,1007,10000,"Blessing of Kings"),
(48932,1008,10000,"Blessing of Might"),
(48936,1009,10000,"Blessing of Wisdom"),
(48072,1010,10000,"Divine Spirit"),
(48161,1011,10000,"Power Word: Fortitude"),
(48169,1012,10000,"Shadow Protection"),
-- Great Buff
(48470,2001,100000,"Gift of the Wild"),
(43002,2002,100000,"Arcane Brilliance"),
(61316,2003,100000,"Dalaran Brilliance"),
(25898,2004,100000,"Greater Blessing of Kings"),
(48934,2005,100000,"Greater Blessing of Might"),
(25899,2006,100000,"Greater Blessing of Sanctuary"),
(48938,2007,100000,"Greater Blessing of Wisdom"),
(48162,2008,100000,"Prayer of Fortitude"),
(48170,2009,100000,"Prayer of Shadow Protection"),
(48074,2010,100000,"Prayer of Spirit"),
-- GM Buff
(17013,3001,0,"Agamaggan's Agility"),
(16612,3002,0,"Agamaggan's Strength"),
(58453,3003,0,"Armor Magic"),
(34106,3004,0,"Armor Penetration"),
(25661,3005,0,"Increased Stamina"),
(16610,3006,0,"Razorhide"),
(10767,3007,0,"Rising Spirit"),
(16618,3008,0,"Spirit of the Wind"),
(7764,3009,0,"Wisdom of Agamaggan"),
-- Player Tools
(46642,4001,0,"Give me Gold"),
(24827,4002,0,"Give me Soul Shards"),
(38588,4003,0,"Heal me please"),
(53251,4004,0,"Heal me and party members Please"),
(42956,4005,0,"Conjure Refreshment"),
(42985,4006,0,"Conjure Mana Gem");

DELETE FROM `creature_template` WHERE `entry` = 60002;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('60002','0','0','0','0','0','18','0','18','0','LordPsyan','Buffs master','','0','59','61','0','35','1','1.48','1.14286','0','0','0','1500','1900','1','1','1','0','0','0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','1','3','1','1','1','1','1','1','0','0','1','0','0','npc_buff','1');

REPLACE INTO `npc_text` (`ID`, `text0_0`) VALUES
   (100002, 'Choose your Buff Type.'),
   (100003, 'Choose your Buff.');