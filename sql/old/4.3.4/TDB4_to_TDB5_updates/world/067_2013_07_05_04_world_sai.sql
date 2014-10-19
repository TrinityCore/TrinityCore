DELETE FROM `disables` WHERE `sourcetype`=0 AND `entry`=53038 AND `flags`=64;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,53038,64, '', '', 'Disable Vmaps for Didgeridoo of Contemplation');

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (29056,29057,29069,29058);
UPDATE `creature_template` SET `ainame`='SmartAI',`scriptname`='' WHERE `entry` IN (29056,29057,29069,29058); 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29056,29057,29069,29058) AND `source_type`=0;
INSERT INTO `smart_scripts` VALUES
(29056,0,0,0,8,0,100,0,53038,0,0,0,33,29056,0,0,0,0,0,7,0,0,0,0,0,0,0,'Glimmering Pillar Credit - On Spell Hit - Give Quest Credit'),
(29057,0,0,0,8,0,100,0,53038,0,0,0,33,29057,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mosslight Pillar Credit - On Spell Hit - Give Quest Credit'),
(29069,0,0,0,8,0,100,0,53038,0,0,0,33,29069,0,0,0,0,0,7,0,0,0,0,0,0,0,'Skyreach Pillar Credit - On Spell Hit - Give Quest Credit'),
(29058,0,0,0,8,0,100,0,53038,0,0,0,33,29058,0,0,0,0,0,7,0,0,0,0,0,0,0,'Suntouched Pillar Credit - On Spell Hit - Give Quest Credit');
