-- Hot On The Trail (A:24849 H:24851)

SET @QUEST_A               := 24849;
SET @QUEST_H               := 24851;

SET @BUNNY_BANK            := 38340; -- [DND] Holiday - Love - Bank Bunny
SET @BUNNY_BANK_SW_GUID    := 208836;
SET @BUNNY_BANK_ORG_GUID   := 208835;
SET @BUNNY_AH              := 38341; -- [DND] Holiday - Love - AH Bunny
SET @BUNNY_AH_SW_GUID      := 208837;
SET @BUNNY_AH_ORG_GUID     := 208838;
SET @BUNNY_BARBER          := 38342; -- [DND] Holiday - Love - Barber Bunny
SET @BUNNY_BARBER_SW_GUID  := 208839;
SET @BUNNY_BARBER_ORG_GUID := 208840;

SET @TRIGGER_BANK_SW       := 5710;
SET @TRIGGER_AH_SW         := 5711;
SET @TRIGGER_BARBER_SW     := 5712;
SET @TRIGGER_BANK_ORG      := 5715;
SET @TRIGGER_AH_ORG        := 5714;
SET @TRIGGER_BARBER_ORG    := 5716;

SET @SPELL_BANK_SW         := 71713; -- Searching the Bank
SET @SPELL_BANK_ORG        := 71759;
SET @SPELL_AH_SW           := 71745; -- Searching the Auction House
SET @SPELL_AH_ORG          := 71760;
SET @SPELL_BARBER_SW       := 71752; -- Searching the Barber Shop
SET @SPELL_BARBER_ORG      := 71758;

-- spells to 'trick' the player
SET @SPELL_ROCKET          := 71715; -- Snivel's Rocket (bank)
SET @SPELL_BLIND           := 71750; -- Blind! (ah)
SET @SPELL_VANISH          := 24222; -- Vanish Visual (barber)

SET @SNIVEL_BANK_SW        := 38334; -- Snivel Rustrocket <Venture Co.>
SET @SNIVEL_BANK_ORG       := 38337;
SET @SNIVEL_AH_SW          := 38335;
SET @SNIVEL_AH_ORG         := 38338;
SET @SNIVEL_BARBER_SW      := 38336;
SET @SNIVEL_BARBER_ORG     := 38339;

SET @SPELL_SUM_SW_BANK     := 71712; -- Summon Snivel
SET @SPELL_SUM_ORG_BANK    := 71762;
SET @SPELL_SUM_SW_AH       := 71744;
SET @SPELL_SUM_ORG_AH      := 71763;
SET @SPELL_SUM_SW_BARBER   := 71751;
SET @SPELL_SUM_ORG_BARBER  := 71765;

UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id` IN (@QUEST_A,@QUEST_H);

DELETE FROM `areatrigger_involvedrelation` WHERE `id` IN (@TRIGGER_BANK_SW,@TRIGGER_AH_SW,@TRIGGER_BARBER_SW,@TRIGGER_BANK_ORG,@TRIGGER_AH_ORG,@TRIGGER_BARBER_ORG);
INSERT INTO `areatrigger_involvedrelation` (`id`,`quest`) VALUES
(@TRIGGER_BANK_SW,@QUEST_A),
(@TRIGGER_AH_SW,@QUEST_A),
(@TRIGGER_BARBER_SW,@QUEST_A),
--
(@TRIGGER_BANK_ORG,@QUEST_H),
(@TRIGGER_AH_ORG,@QUEST_H),
(@TRIGGER_BARBER_ORG,@QUEST_H);


DELETE FROM `areatrigger_scripts` WHERE `entry` IN (@TRIGGER_BANK_SW,@TRIGGER_AH_SW,@TRIGGER_BARBER_SW,@TRIGGER_BANK_ORG,@TRIGGER_AH_ORG,@TRIGGER_BARBER_ORG);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(@TRIGGER_BANK_SW,'SmartTrigger'),
(@TRIGGER_AH_SW,'SmartTrigger'),
(@TRIGGER_BARBER_SW,'SmartTrigger'),
--
(@TRIGGER_BANK_ORG,'SmartTrigger'),
(@TRIGGER_AH_ORG,'SmartTrigger'),
(@TRIGGER_BARBER_ORG,'SmartTrigger');


-- area trigger scripts
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@TRIGGER_BANK_SW,@TRIGGER_AH_SW,@TRIGGER_BARBER_SW,@TRIGGER_BANK_ORG,@TRIGGER_AH_ORG,@TRIGGER_BARBER_ORG) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGGER_BANK_SW,2,0,1,46,0,100,0,@TRIGGER_BANK_SW,0,0,0,86,@SPELL_BANK_SW,0,10,@BUNNY_BANK_SW_GUID,@BUNNY_BANK,0,7,0,0,0,0,0,0,0,'On Trigger - Crosscast - Invoker'),
(@TRIGGER_BANK_SW,2,1,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,@BUNNY_BANK_SW_GUID,@BUNNY_BANK,0,0,0,0,0,'Link - Kill - Bunny'),
--
(@TRIGGER_AH_SW,2,0,1,46,0,100,0,@TRIGGER_AH_SW,0,0,0,86,@SPELL_AH_SW,0,10,@BUNNY_AH_SW_GUID,@BUNNY_AH,0,7,0,0,0,0,0,0,0,'On Trigger - Crosscast - Invoker'),
(@TRIGGER_AH_SW,2,1,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,@BUNNY_AH_SW_GUID,@BUNNY_AH,0,0,0,0,0,'Link - Kill - Bunny'),
--
(@TRIGGER_BARBER_SW,2,0,1,46,0,100,0,@TRIGGER_BARBER_SW,0,0,0,86,@SPELL_BARBER_SW,0,10,@BUNNY_BARBER_SW_GUID,@BUNNY_BARBER,0,7,0,0,0,0,0,0,0,'On Trigger - Crosscast - Invoker'),
(@TRIGGER_BARBER_SW,2,1,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,@BUNNY_BARBER_SW_GUID,@BUNNY_BARBER,0,0,0,0,0,'Link - Kill - Bunny'),
-- --
(@TRIGGER_BANK_ORG,2,0,1,46,0,100,0,@TRIGGER_BANK_ORG,0,0,0,86,@SPELL_BANK_ORG,0,10,@BUNNY_BANK_ORG_GUID,@BUNNY_BANK,0,7,0,0,0,0,0,0,0,'On Trigger - Crosscast - Invoker'),
(@TRIGGER_BANK_ORG,2,1,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,@BUNNY_BANK_ORG_GUID,@BUNNY_BANK,0,0,0,0,0,'Link - Kill - Bunny'),
--
(@TRIGGER_AH_ORG,2,0,1,46,0,100,0,@TRIGGER_AH_ORG,0,0,0,86,@SPELL_AH_ORG,0,10,@BUNNY_AH_ORG_GUID,@BUNNY_AH,0,7,0,0,0,0,0,0,0,'On Trigger - Crosscast - Invoker'),
(@TRIGGER_AH_ORG,2,1,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,@BUNNY_AH_ORG_GUID,@BUNNY_AH,0,0,0,0,0,'Link - Kill - Bunny'),
--
(@TRIGGER_BARBER_ORG,2,0,1,46,0,100,0,@TRIGGER_BARBER_ORG,0,0,0,86,@SPELL_BARBER_ORG,0,10,@BUNNY_BARBER_ORG_GUID,@BUNNY_BARBER,0,7,0,0,0,0,0,0,0,'On Trigger - Crosscast - Invoker'),
(@TRIGGER_BARBER_ORG,2,1,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,@BUNNY_BARBER_ORG_GUID,@BUNNY_BARBER,0,0,0,0,0,'Link - Kill - Bunny');


-- Snivel Rustrocket scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@SNIVEL_BANK_SW,@SNIVEL_AH_SW,@SNIVEL_BARBER_SW,@SNIVEL_BANK_ORG,@SNIVEL_AH_ORG,@SNIVEL_BARBER_ORG);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SNIVEL_BANK_SW,@SNIVEL_AH_SW,@SNIVEL_BARBER_SW,@SNIVEL_BANK_ORG,@SNIVEL_AH_ORG,@SNIVEL_BARBER_ORG) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SNIVEL_BANK_SW*100,@SNIVEL_AH_SW*100,@SNIVEL_BARBER_SW*100,@SNIVEL_BANK_ORG*100,@SNIVEL_AH_ORG*100,@SNIVEL_BARBER_ORG*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SNIVEL_BANK_SW,0,0,0,54,0,100,0,0,0,0,0,80,@SNIVEL_BANK_SW*100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On sumoned - Run script - Self'),
(@SNIVEL_BANK_SW,0,1,0,58,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On WP ended - Despawn - Self'),
--
(@SNIVEL_BANK_SW*100,9,0,0,0,0,100,0,2000,2000,0,0,5,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BANK_SW*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BANK_SW*100,9,2,0,0,0,100,0,2000,2000,0,0,5,11,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BANK_SW*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BANK_SW*100,9,4,0,0,0,100,0,1000,1000,0,0,11,@SPELL_ROCKET,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'On script - Cast - Invoker'),
(@SNIVEL_BANK_SW*100,9,5,0,0,0,100,0,1000,1000,0,0,53,1,@SNIVEL_BANK_SW,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Start WP - Self'),
-- --
(@SNIVEL_AH_SW,0,0,0,54,0,100,0,0,0,0,0,80,@SNIVEL_AH_SW*100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On sumoned - Run script - Self'),
(@SNIVEL_AH_SW,0,1,0,58,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On WP ended - Despawn - Self'),
--
(@SNIVEL_AH_SW*100,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_AH_SW*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_AH_SW*100,9,2,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_AH_SW*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_AH_SW*100,9,4,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_AH_SW*100,9,5,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_AH_SW*100,9,6,0,0,0,100,0,1000,1000,0,0,11,@SPELL_BLIND,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'On script - Cast - Invoker'),
(@SNIVEL_AH_SW*100,9,7,0,0,0,100,0,1000,1000,0,0,53,1,@SNIVEL_AH_SW,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Start WP - Self'),
-- --
(@SNIVEL_BARBER_SW,0,0,0,54,0,100,0,0,0,0,0,80,@SNIVEL_BARBER_SW*100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On sumoned - Run script - Self'),
--
(@SNIVEL_BARBER_SW*100,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BARBER_SW*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_SW*100,9,2,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BARBER_SW*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_SW*100,9,4,0,0,0,100,0,2000,2000,0,0,5,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BARBER_SW*100,9,5,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_SW*100,9,6,0,0,0,100,0,1000,1000,0,0,11,@SPELL_VANISH,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Cast - Self'),
(@SNIVEL_BARBER_SW*100,9,7,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_SW*100,9,8,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Despawn - Self'),
-- -- --
(@SNIVEL_BANK_ORG,0,0,0,54,0,100,0,0,0,0,0,80,@SNIVEL_BANK_ORG*100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On sumoned - Run script - Self'),
(@SNIVEL_BANK_ORG,0,1,0,58,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On WP ended - Despawn - Self'),
--
(@SNIVEL_BANK_ORG*100,9,0,0,0,0,100,0,2000,2000,0,0,5,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BANK_ORG*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BANK_ORG*100,9,2,0,0,0,100,0,2000,2000,0,0,5,11,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BANK_ORG*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BANK_ORG*100,9,4,0,0,0,100,0,1000,1000,0,0,11,@SPELL_ROCKET,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'On script - Cast - Invoker'),
(@SNIVEL_BANK_ORG*100,9,5,0,0,0,100,0,1000,1000,0,0,53,1,@SNIVEL_BANK_ORG,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Start WP - Self'),
-- --
(@SNIVEL_AH_ORG,0,0,0,54,0,100,0,0,0,0,0,80,@SNIVEL_AH_ORG*100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On sumoned - Run script - Self'),
(@SNIVEL_AH_ORG,0,1,0,58,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On WP ended - Despawn - Self'),
--
(@SNIVEL_AH_ORG*100,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_AH_ORG*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_AH_ORG*100,9,2,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_AH_ORG*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_AH_ORG*100,9,4,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_AH_ORG*100,9,5,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_AH_ORG*100,9,6,0,0,0,100,0,1000,1000,0,0,11,@SPELL_BLIND,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'On script - Cast - Invoker'),
(@SNIVEL_AH_ORG*100,9,7,0,0,0,100,0,1000,1000,0,0,53,1,@SNIVEL_AH_ORG,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Start WP - Self'),
-- --
(@SNIVEL_BARBER_ORG,0,0,0,54,0,100,0,0,0,0,0,80,@SNIVEL_BARBER_ORG*100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On sumoned - Run script - Self'),
--
(@SNIVEL_BARBER_ORG*100,9,0,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BARBER_ORG*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_ORG*100,9,2,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BARBER_ORG*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_ORG*100,9,4,0,0,0,100,0,2000,2000,0,0,5,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Emote - Self'),
(@SNIVEL_BARBER_ORG*100,9,5,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_ORG*100,9,6,0,0,0,100,0,1000,1000,0,0,11,@SPELL_VANISH,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Cast - Self'),
(@SNIVEL_BARBER_ORG*100,9,7,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Talk - Self'),
(@SNIVEL_BARBER_ORG*100,9,8,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On script - Despawn - Self');


DELETE FROM `creature_text` WHERE `entry` IN (@SNIVEL_BANK_SW,@SNIVEL_AH_SW,@SNIVEL_BARBER_SW,@SNIVEL_BANK_ORG,@SNIVEL_AH_ORG,@SNIVEL_BARBER_ORG);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SNIVEL_BANK_SW,0,0,'What are you staring at? Haven''t you ever seen a genius before?',12,0,100,0,0,0,'say text'),
(@SNIVEL_BANK_SW,1,0,'This''ll teach you to mind your own business!',12,0,100,0,0,0,'say text'),
--
(@SNIVEL_AH_SW,0,0,'That''s right, I''d like to list some of these ''fireworks''.',12,0,100,0,0,0,'say text'),
(@SNIVEL_AH_SW,1,0,'Those''ll net me a nice profit when I return from the South Seas.''.',12,0,100,0,0,0,'say text'),
(@SNIVEL_AH_SW,2,0,'You... Don''t think I don''t see you. Leave me alone!.',12,0,100,0,0,0,'say text'),
--
(@SNIVEL_BARBER_SW,0,0,'Thanks for the great cut and shave, buddy.',12,0,100,0,0,0,'say text'),
(@SNIVEL_BARBER_SW,1,0,'Here''s a little somethin'' extra since I''ll be away.',12,0,100,0,0,0,'say text'),
(@SNIVEL_BARBER_SW,2,0,'On second thought, keep the whole bag. I have to, uh, get going.',12,0,100,0,0,0,'say text'),
(@SNIVEL_BARBER_SW,3,0,'Did you really think you could corner me this easily?',12,0,100,0,0,0,'say text'),
-- --
(@SNIVEL_BANK_ORG,0,0,'What are you staring at? Haven''t you ever seen a genius before?',12,0,100,0,0,0,'say text'),
(@SNIVEL_BANK_ORG,1,0,'This''ll teach you to mind your own business!',12,0,100,0,0,0,'say text'),
--
(@SNIVEL_AH_ORG,0,0,'That''s right, I''d like to list some of these ''fireworks''.',12,0,100,0,0,0,'say text'),
(@SNIVEL_AH_ORG,1,0,'Those''ll net me a nice profit when I return from the South Seas.''.',12,0,100,0,0,0,'say text'),
(@SNIVEL_AH_ORG,2,0,'You... Don''t think I don''t see you. Leave me alone!.',12,0,100,0,0,0,'say text'),
--
(@SNIVEL_BARBER_ORG,0,0,'Thanks for the great cut and shave, buddy.',12,0,100,0,0,0,'say text'),
(@SNIVEL_BARBER_ORG,1,0,'Here''s a little somethin'' extra since I''ll be away.',12,0,100,0,0,0,'say text'),
(@SNIVEL_BARBER_ORG,2,0,'On second thought, keep the whole bag. I have to, uh, get going.',12,0,100,0,0,0,'say text'),
(@SNIVEL_BARBER_ORG,3,0,'Did you really think you could corner me this easily?',12,0,100,0,0,0,'say text');


DELETE FROM `waypoints` WHERE `entry` IN (@SNIVEL_BANK_SW,@SNIVEL_AH_SW,@SNIVEL_BARBER_SW,@SNIVEL_BANK_ORG,@SNIVEL_AH_ORG,@SNIVEL_BARBER_ORG);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
-- need proper 3.3.5a WPs
(@SNIVEL_BANK_SW,1,-8922.295,620.7185,99.9155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,2,-8910.545,627.2185,99.9155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,3,-8902.795,631.2185,99.9155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,4,-8901.045,631.9685,99.9155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,5,-8898.795,633.2185,99.9155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,6,-8897.045,633.9685,99.4155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,7,-8895.545,634.7185,99.4155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,8,-8894.295,635.2185,99.4155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,9,-8892.045,636.2185,99.4155,'Snivel Rustrocket'),
(@SNIVEL_BANK_SW,10,-8890.389,637.309,99.52265,'Snivel Rustrocket'),
-- need proper 3.3.5a WPs
(@SNIVEL_AH_SW,1,-8806.079,665.8424,96.2017,'Snivel Rustrocket'),
(@SNIVEL_AH_SW,2,-8807.825,653.1030,96.1965,'Snivel Rustrocket'),
(@SNIVEL_AH_SW,3,-8829.964,634.2772,94.3178,'Snivel Rustrocket'),
(@SNIVEL_AH_SW,4,-8838.774,616.6351,92.8850,'Snivel Rustrocket'),
-- need proper 3.3.5a WPs
(@SNIVEL_BANK_ORG,1,1615.59,-4379.849,12.610,'Snivel Rustrocket'),
(@SNIVEL_BANK_ORG,2,1603.85,-4393.092,9.837,'Snivel Rustrocket'),
(@SNIVEL_BANK_ORG,3,1576.08,-4410.980,6.569,'Snivel Rustrocket'),
-- need proper 3.3.5a WPs
(@SNIVEL_AH_ORG,1,1669.29,-4433.413,19.643,'Snivel Rustrocket'),
(@SNIVEL_AH_ORG,2,1652.96,-4419.120,16.705,'Snivel Rustrocket'),
(@SNIVEL_AH_ORG,3,1627.23,-4427.485,13.353,'Snivel Rustrocket');


DELETE FROM `spell_target_position` WHERE `id` IN (@SPELL_SUM_SW_BANK,@SPELL_SUM_SW_AH,@SPELL_SUM_SW_BARBER,@SPELL_SUM_ORG_BANK,@SPELL_SUM_ORG_AH,@SPELL_SUM_ORG_BARBER);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(@SPELL_SUM_SW_BANK,0,-8922.7,620.628,100.225,0),
(@SPELL_SUM_SW_AH,0,-8815.04,662.193,95.4238,0),
(@SPELL_SUM_SW_BARBER,0,-8745.29,656.266,105.091,0),
--
(@SPELL_SUM_ORG_BANK,1,1624.64,-4375.8662,12.0282,0),
(@SPELL_SUM_ORG_AH,1,1678.29,-4451.2597,19.2568,0),
(@SPELL_SUM_ORG_BARBER,1,1764.49,-4345.9306,-7.7980,0);


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@TRIGGER_BANK_SW,@TRIGGER_AH_SW,@TRIGGER_BARBER_SW,@TRIGGER_BANK_ORG,@TRIGGER_AH_ORG,@TRIGGER_BARBER_ORG);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@TRIGGER_BANK_SW,2,0,9,0,@QUEST_A,0,0,0,0,'','execute sai only if player has quest taken'),
(22,1,@TRIGGER_AH_SW,2,0,9,0,@QUEST_A,0,0,0,0,'','execute sai only if player has quest taken'),
(22,1,@TRIGGER_BARBER_SW,2,0,9,0,@QUEST_A,0,0,0,0,'','execute sai only if player has quest taken'),
--
(22,1,@TRIGGER_BANK_ORG,2,0,9,0,@QUEST_H,0,0,0,0,'','execute sai only if player has quest taken'),
(22,1,@TRIGGER_AH_ORG,2,0,9,0,@QUEST_H,0,0,0,0,'','execute sai only if player has quest taken'),
(22,1,@TRIGGER_BARBER_ORG,2,0,9,0,@QUEST_H,0,0,0,0,'','execute sai only if player has quest taken');
