SET
@Entry = 190010,
@Name = "Warpweaver Izmir";

INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `AIName`, `MovementType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(@Entry, 19646, 0, @Name, "Transmogrifier", NULL, 0, 80, 80, 2, 35, 1, 1, 0, 0, 2000, 0, 1, 0, 7, 138936390, 0, 0, 0, '', 0, 1, 0, 0, 1, 0, 0, 'Creature_Transmogrify');


INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `Title`, `VerifiedBuild`) VALUES
(@Entry, 'frFR', 'Tisse-dimensions Izmir', 'Transmogrifieur', 18019);

INSERT INTO `creature`
(
`id`,
`map`,
`zoneId`,
`areaId`,
`spawnMask`,
`phaseMask`,
`modelid`,
`equipment_id`,
`position_x`,
`position_y`,
`position_z`,
`orientation`,
`spawntimesecs`,
`spawndist`,
`currentwaypoint`,
`curhealth`,
`curmana`,
`MovementType`,
`npcflag`,
`unit_flags`,
`dynamicflags`,
`ScriptName`,
`VerifiedBuild`)
VALUES
(190010,530,0,0,1,1,0,0,9632.56,-7153.52,14.3241,4.03709,300,0,0,16379,0,0,0,0,0,'',0),
(190010,530,0,0,1,1,0,0,-4002.08,-11737.4,-151.624,2.7214,300,0,0,16379,0,0,0,0,0,'',0);
