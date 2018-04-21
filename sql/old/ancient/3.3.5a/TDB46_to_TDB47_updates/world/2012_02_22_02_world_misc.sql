-- Mounting Hodir's Helm (12987)

-- cleanup after Discovered
-- clean all related to npc Hodir's Helm KC Bunny
DELETE FROM `smart_scripts` WHERE `entryorguid`=30210 AND `source_type`=0;
DELETE FROM `creature` WHERE `id`=30210;
DELETE FROM `creature_text` WHERE `entry`=30210;

SET @HELM                     := 192080; -- Hodir's Helm
SET @TEMP                     := 300230; -- TEMP Northern Ice Spike
SET @BUNNY_TARGET             := 30215; -- Ice Spike Target Bunny
SET @GUID_GO                  := 270; -- set by TDB
SET @GUID_NPC                 := 40514; -- set by TDB
SET @SPELL_READ_PRONOUNCEMENT := 56278;
SET @QUEST                    := 12987;
SET @AREA                     := 4438; -- Dun Niffelem
SET @SPELL_AREA               := 56305; -- See Quest Invisibility 1 (Ice Spike Bunny)
SET @QUEST                    := 13006; -- Polishing the Helm

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432|256,`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=@BUNNY_TARGET;

UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=@HELM;
UPDATE `gameobject` SET `phaseMask`=4 WHERE `id`=@TEMP;

DELETE FROM `gameobject` WHERE `guid`=@GUID_GO;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID_GO,@HELM,571,1,4,7390.143,-2725.382,874.2561,-3.089183,0,0,-0.9996567,0.02620165,600,255,1);

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID_NPC+0 AND @GUID_NPC+1;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID_NPC+0,@BUNNY_TARGET,571,1,4,0,0,7386.51,-2726.489,872.5089,5.88176,300,0,0,4979,0,0,0,0,0),
(@GUID_NPC+1,@BUNNY_TARGET,571,1,4,0,0,7388.424,-2724.909,869.8643,0.5934119,300,0,0,4979,0,0,0,0,0);

DELETE FROM `creature_template_addon` WHERE `entry`=@BUNNY_TARGET;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@BUNNY_TARGET,0,0,65536,1,0, '61333 56304 61334'); -- Gigantic Helm Sparkle / Hodir's Helm Bunny: Invisibility / Extra Large Helm Sparkle

DELETE FROM `spell_script_names` WHERE `spell_id`=@SPELL_READ_PRONOUNCEMENT;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(@SPELL_READ_PRONOUNCEMENT, 'spell_q12987_read_pronouncement');

DELETE FROM `spell_area` WHERE `spell`=@SPELL_AREA;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(@SPELL_AREA,@AREA,@QUEST,1,@QUEST,0,0,2,1);

-- relation for the daily quest that should be available after finishing Mounting Hodir's Helm

-- removing flag 4 or else player can't interract with Q giver
UPDATE `gameobject_template` SET `flags`=`flags`&~4 WHERE `entry`=@HELM;

DELETE FROM `gameobject_questrelation` WHERE `id`=@HELM;
INSERT INTO `gameobject_questrelation` (`id`,`quest`) VALUES
(@HELM,@QUEST);

DELETE FROM `gameobject_involvedrelation` WHERE `id`=@HELM;
INSERT INTO `gameobject_involvedrelation` (`id`,`quest`) VALUES
(@HELM,@QUEST);
