-- DB update 2021_04_14_02 -> 2021_04_16_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_14_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_14_02 2021_04_16_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1605009324701425500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1605009324701425500');

SET @NPC_JONATHAN := 28136;
SET @NPC_LAMOOF := 28142;
SET @NPC_JOSEPHINE := 28148;

UPDATE `creature_template` SET `gossip_menu_id`=9660 WHERE `entry`=@NPC_JONATHAN;
UPDATE `creature_template` SET `gossip_menu_id`=9659 WHERE `entry`=@NPC_LAMOOF;
UPDATE `creature_template` SET `gossip_menu_id`=9658 WHERE `entry`=@NPC_JOSEPHINE;
UPDATE `creature_template` SET `faction`=2070, `npcflag`=1, `unit_flags`=32768, `AIName`='SmartAI' WHERE `entry` IN (@NPC_JONATHAN,@NPC_LAMOOF,@NPC_JOSEPHINE);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_JONATHAN,@NPC_LAMOOF,@NPC_JOSEPHINE);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@NPC_JONATHAN*100,@NPC_LAMOOF*100,@NPC_JOSEPHINE*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@NPC_JONATHAN,0,0,1,54,0,100,0,0,0,0,0,11,50665,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - Just summoned - Spellcast Bleeding Out'),
(@NPC_JONATHAN,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Jonathan - Just summoned - Store targetlist'),
(@NPC_JONATHAN,0,2,3,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Jonathan - Just summoned - Follow envoker'),
(@NPC_JONATHAN,0,3,4,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - Just summoned - Set phase 1'),
(@NPC_JONATHAN,0,4,0,61,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - Just summoned - Reset unit_field_bytes1'),
(@NPC_JONATHAN,0,5,0,23,1,100,1,50665,0,0,0,80,@NPC_JONATHAN*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - Aura Bleeding Out missing (phase 1) - Call timed actionlist'),
(@NPC_JONATHAN,0,6,7,40,0,100,1,5,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On WP 5 reached - Set unit_field_bytes1'),
(@NPC_JONATHAN,0,7,0,61,0,100,0,0,0,0,0,41,20000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On WP 5 reached - Despawn after 20 seconds'),
(@NPC_JONATHAN,0,8,9,8,1,100,0,50669,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Set phase 2'),
(@NPC_JONATHAN,0,9,10,61,0,100,0,0,0,0,0,11,50671,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Cast Kill Credit Jonathan 01'),
(@NPC_JONATHAN,0,10,11,61,0,100,0,0,0,0,0,11,50709,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Cast Strip Aura Jonathan 01'),
(@NPC_JONATHAN,0,11,12,61,0,100,0,0,0,0,0,86,50680,0,12,1,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Crosscast Kill Credit Jonathan'),
(@NPC_JONATHAN,0,12,13,61,0,100,0,0,0,0,0,86,50710,0,12,1,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Crosscast Strip Aura Jonanthan'),
(@NPC_JONATHAN,0,13,14,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Stop follow'),
(@NPC_JONATHAN,0,14,15,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Say text'),
(@NPC_JONATHAN,0,15,16,61,0,100,0,0,0,0,0,53,0,@NPC_JONATHAN,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Start WP movement'),
(@NPC_JONATHAN,0,16,0,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan - On spellhit Quest Credit - Remove npcflag'),
(@NPC_JONATHAN*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan script - Say text'),
(@NPC_JONATHAN*100,9,1,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan script - Set phase 2'),
(@NPC_JONATHAN*100,9,2,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Crusader Jonathan script - Stop follow'),
(@NPC_JONATHAN*100,9,3,0,0,0,100,0,2000,2000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonathan script - Die'),

(@NPC_LAMOOF,0,0,1,54,0,100,0,0,0,0,0,11,50681,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - Just summoned - Spellcast Bleeding Out'),
(@NPC_LAMOOF,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Lamoof - Just summoned - Store targetlist'),
(@NPC_LAMOOF,0,2,3,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Lamoof - Just summoned - Follow envoker'),
(@NPC_LAMOOF,0,3,4,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - Just summoned - Set phase 1'),
(@NPC_LAMOOF,0,4,0,61,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - Just summoned - Reset unit_field_bytes1'),
(@NPC_LAMOOF,0,5,0,23,1,100,1,50681,0,0,0,80,@NPC_LAMOOF*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - Aura Bleeding Out missing (phase 1) - Call timed actionlist'),
(@NPC_LAMOOF,0,6,7,40,0,100,1,5,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On WP 5 reached - Set unit_field_bytes1'),
(@NPC_LAMOOF,0,7,0,61,0,100,0,0,0,0,0,41,20000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On WP 5 reached - Despawn after 20 seconds'),
(@NPC_LAMOOF,0,8,9,8,1,100,0,50669,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Set phase 2'),
(@NPC_LAMOOF,0,9,10,61,0,100,0,0,0,0,0,11,50683,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Cast Kill Credit Lamoof 01'),
(@NPC_LAMOOF,0,10,11,61,0,100,0,0,0,0,0,11,50723,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Cast Strip Aura Lamoof 01'),
(@NPC_LAMOOF,0,11,12,61,0,100,0,0,0,0,0,86,50684,0,12,1,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Crosscast Kill Credit Lamoof'),
(@NPC_LAMOOF,0,12,13,61,0,100,0,0,0,0,0,86,50722,0,12,1,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Crosscast Strip Aura Lamoof'),
(@NPC_LAMOOF,0,13,14,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Stop follow'),
(@NPC_LAMOOF,0,14,15,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Say text'),
(@NPC_LAMOOF,0,15,16,61,0,100,0,0,0,0,0,53,0,@NPC_LAMOOF,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Start WP movement'),
(@NPC_LAMOOF,0,16,0,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spellhit Quest Credit - Remove npcflag'),
(@NPC_LAMOOF*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof script - Say text'),
(@NPC_LAMOOF*100,9,1,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof script - Set phase 2'),
(@NPC_LAMOOF*100,9,2,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Crusader Lamoof script - Stop follow'),
(@NPC_LAMOOF*100,9,3,0,0,0,100,0,2000,2000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof script - Die'),

(@NPC_JOSEPHINE,0,0,1,54,0,100,0,0,0,0,0,11,50695,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - Just summoned - Spellcast Bleeding Out'),
(@NPC_JOSEPHINE,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Josephine - Just summoned - Store targetlist'),
(@NPC_JOSEPHINE,0,2,3,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Josephine - Just summoned - Follow envoker'),
(@NPC_JOSEPHINE,0,3,4,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - Just summoned - Set phase 1'),
(@NPC_JOSEPHINE,0,4,0,61,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - Just summoned - Reset unit_field_bytes1'),
(@NPC_JOSEPHINE,0,5,0,23,1,100,1,50695,0,0,0,80,@NPC_JOSEPHINE*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - Aura Bleeding Out missing (phase 1) - Call timed actionlist'),
(@NPC_JOSEPHINE,0,6,7,40,0,100,1,4,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On WP 4 reached - Set unit_field_bytes1'),
(@NPC_JOSEPHINE,0,7,0,61,0,100,0,0,0,0,0,41,20000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On WP 4 reached - Despawn after 20 seconds'),
(@NPC_JOSEPHINE,0,8,9,8,1,100,0,50669,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Set phase 2'),
(@NPC_JOSEPHINE,0,9,10,61,0,100,0,0,0,0,0,11,50698,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Cast Kill Credit Jospehine 01'),
(@NPC_JOSEPHINE,0,10,11,61,0,100,0,0,0,0,0,11,50711,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Cast Strip Aura Josephine 01'),
(@NPC_JOSEPHINE,0,11,12,61,0,100,0,0,0,0,0,86,50699,0,12,1,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Crosscast Kill Credit Josephine'),
(@NPC_JOSEPHINE,0,12,13,61,0,100,0,0,0,0,0,86,50712,0,12,1,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Crosscast Strip Aura Josephine'),
(@NPC_JOSEPHINE,0,13,14,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Stop follow'),
(@NPC_JOSEPHINE,0,14,15,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Say text'),
(@NPC_JOSEPHINE,0,15,16,61,0,100,0,0,0,0,0,53,0,@NPC_JOSEPHINE,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Start WP movement'),
(@NPC_JOSEPHINE,0,16,0,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spellhit Quest Credit - Remove npcflag'),
(@NPC_JOSEPHINE*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine script - Say text'),
(@NPC_JOSEPHINE*100,9,1,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine script - Set phase 2'),
(@NPC_JOSEPHINE*100,9,2,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Crusader Josephine script - Stop follow'),
(@NPC_JOSEPHINE*100,9,3,0,0,0,100,0,2000,2000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine script - Die');

DELETE FROM `waypoints` WHERE `entry` IN (@NPC_JONATHAN,@NPC_LAMOOF,@NPC_JOSEPHINE);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`) VALUES
(@NPC_JONATHAN,1,5257.454,-3500.14,291.6933),
(@NPC_JONATHAN,2,5253.089,-3516.885,291.6786),
(@NPC_JONATHAN,3,5255.452,-3523.673,291.6932),
(@NPC_JONATHAN,4,5262.733,-3527.41,291.6934),
(@NPC_JONATHAN,5,5261.445,-3528.885,291.6929),

(@NPC_LAMOOF,1,5257.454,-3500.14,291.6933),
(@NPC_LAMOOF,2,5253.089,-3516.885,291.6786),
(@NPC_LAMOOF,3,5255.452,-3523.673,291.6932),
(@NPC_LAMOOF,4,5260.741,-3525.38,291.69343),
(@NPC_LAMOOF,5,5259.029,-3527.101,291.4913),

(@NPC_JOSEPHINE,1,5257.454,-3500.14,291.6933),
(@NPC_JOSEPHINE,2,5253.089,-3516.885,291.6786),
(@NPC_JOSEPHINE,3,5257.784,-3521.994,291.6931),
(@NPC_JOSEPHINE,4,5256.293,-3523.494,291.6933);

DELETE FROM `creature_text` WHERE `creatureid` IN (@NPC_JONATHAN,@NPC_LAMOOF,@NPC_JOSEPHINE) AND `groupid`=1;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_JONATHAN,1,0,'<sigh>... This is the end of me.',12,0,100,1,0,0,''),
(@NPC_LAMOOF,1,0,'<sigh>... This is the end of me.',12,0,100,1,0,0,''),
(@NPC_JOSEPHINE,1,0,'Ohhh, I... cannot go on....',12,0,100,1,0,0,'');

DELETE FROM `gossip_menu` WHERE `menuid` IN (9658,9659,9660);
INSERT INTO `gossip_menu` (`menuid`,`textid`) VALUES
(9658,13081),
(9659,13083),
(9660,13082);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (50709,50710,50711,50712,50722,50723);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(50709,-50665,1,'Strip Aura Jonathan 01 remove aura Bleeding Out'),
(50710,-50666,1,'Strip Aura Jonathan remove aura Jonathan Dying from player'),
(50711,-50695,1,'Strip Aura Josephine 01 remove aura Bleeding Out'),
(50712,-50693,1,'Strip Aura Josephine remove aura Josephine Dying from player'),
(50722,-50679,1,'Strip Aura Lamoof remove aura Lamoof Dying from player'),
(50723,-50681,1,'Strip Aura Lamoof 01 remove aura Bleeding Out');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
