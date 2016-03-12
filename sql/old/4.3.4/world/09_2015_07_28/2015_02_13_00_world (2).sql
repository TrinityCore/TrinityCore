SET @NPC_BLACK_KNIGHT := 33785;
SET @NPC_CAVIN := 33522;
SET @SPELL_CHARGE := 63003;
SET @SPELL_SHIELD_BREAKER := 65147;
SET @SPELL_DARK_SHIELD := 64505;
SET @SPELL_BLACK_NIGHT_TRANSFORM := 64490; -- Apply Aura: Change Model (34104)
SET @SPELL_BLACK_NIGHT_TRANSFORM_2 := 64498; -- Apply Aura: Increase Max Health
SET @SPELL_FULL_HEAL := 25840;
SET @GOSSIP := 10383;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_BLACK_KNIGHT, @NPC_CAVIN);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_BLACK_KNIGHT;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@NPC_BLACK_KNIGHT*100;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@NPC_BLACK_KNIGHT*100+1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_CAVIN;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@NPC_CAVIN*100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_CAVIN,0,0,1,62,0,100,0,@GOSSIP,0,0,0,80,@NPC_CAVIN*100,0,2,0,0,0,1,0,0,0,0,0,0,0,'Cavin - On gossip option select - Run script'),
(@NPC_CAVIN,0,1,2,61,0,100,0,0,0,0,0,12,@NPC_BLACK_KNIGHT,1,120000,0,0,0,8,0,0,0,8482.370117, 964.506653, 547.292908, 3.253865,'Cavin - On gossip option select - Summon the Black Knight'),
(@NPC_CAVIN,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cavin - On gossip option select - Close gossip'),
(@NPC_CAVIN*100,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cavin - On Script - Turn off Gossip & Gossip flags'),
(@NPC_CAVIN*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cavin - On Script - Say text 0'),
(@NPC_CAVIN*100,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cavin - On Script - Say text 1'),
(@NPC_BLACK_KNIGHT,0,0,0,54,0,100,1,0,0,0,0,80,@NPC_BLACK_KNIGHT*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - Just Summoned - Mount to entry'),
(@NPC_BLACK_KNIGHT*100+1,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,8426.153320, 962.307861, 544.675293, 6.273711,'Blackknight - On Script - MOVE TO POS'),
(@NPC_BLACK_KNIGHT*100+1,9,1,0,0,0,100,0,10000,10000,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - REMOVE IMMUNE TO PC'),
(@NPC_BLACK_KNIGHT*100+1,9,2,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - REMOVE IMMUNE TO PC'),
(@NPC_BLACK_KNIGHT*100+1,9,3,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,33782,25,0,0,0,0,0,'Blackknight - On Script - attack'),
(@NPC_BLACK_KNIGHT,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackknight - On Aggro - Cast Charge'),
(@NPC_BLACK_KNIGHT,0,2,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Aggro - Set Phase 1'),
(@NPC_BLACK_KNIGHT,0,3,0,0,1,100,0,10000,10000,15000,15000,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - In Phase 1 - Flee for assist'),
(@NPC_BLACK_KNIGHT,0,4,0,9,1,100,0,5,30,1000,1000,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackknight - In Phase 1& On Range - Cast Charge'),
(@NPC_BLACK_KNIGHT,0,5,0,9,1,100,0,3,30,1500,2000,11,@SPELL_SHIELD_BREAKER,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackknight - In Phase 1 & On Range - Cast Shield Breaker'),
(@NPC_BLACK_KNIGHT,0,6,0,6,0,100,0,0,0,0,0,81,1,0,0,0,0,0,10,85140,@NPC_CAVIN,0,0,0,0,0,'Blackknight - On Death - Turn on Gossip & Gossip flags on Cavin'),
(@NPC_BLACK_KNIGHT,0,7,8,1,0,100,0,20000,20000,20000,20000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - Out Of Combat after 20s - Despawn'),
(@NPC_BLACK_KNIGHT,0,8,0,61,0,100,0,0,0,0,0,81,1,0,0,0,0,0,10,85140,@NPC_CAVIN,0,0,0,0,0,'Blackknight - Out Of Combat after 20s - Turn on Gossip & Gossip flags on Cavin'),
(@NPC_BLACK_KNIGHT,0,9,0,2,1,100,1,0,25,0,0,80,@NPC_BLACK_KNIGHT*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On 25% health - Run script'),
(@NPC_BLACK_KNIGHT*100,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - State passive'),
(@NPC_BLACK_KNIGHT*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Say text 0'),
(@NPC_BLACK_KNIGHT*100,9,2,0,0,0,100,0,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Unmount'),
(@NPC_BLACK_KNIGHT*100,9,3,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,33782,30,0,0,0,0,0,'Blackknight - On Script - Unmount player'),
(@NPC_BLACK_KNIGHT*100,9,4,0,0,0,100,0,0,0,0,0,11,@SPELL_DARK_SHIELD,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Cast Dark Shield'),
(@NPC_BLACK_KNIGHT*100,9,5,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Aggro - Set Phase 0'),
(@NPC_BLACK_KNIGHT*100,9,6,0,0,0,100,0,6000,6000,0,0,11,@SPELL_BLACK_NIGHT_TRANSFORM,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Apply Aura'),
(@NPC_BLACK_KNIGHT*100,9,7,0,0,0,100,0,0,0,0,0,11,@SPELL_FULL_HEAL,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Full hp'),
(@NPC_BLACK_KNIGHT*100,9,8,0,0,0,100,0,1000,1000,0,0,11,@SPELL_BLACK_NIGHT_TRANSFORM_2,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Increase Max Health'),
(@NPC_BLACK_KNIGHT*100,9,9,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - State Aggresive'),
(@NPC_BLACK_KNIGHT*100,9,10,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackknight - On Script - Say text 1'),
(@NPC_BLACK_KNIGHT*100,9,11,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,15,0,0,0,0,0,0,'Blackknight - On Script - Start Attack');

DELETE FROM `creature_text` WHERE `entry`IN (@NPC_BLACK_KNIGHT, @NPC_CAVIN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(@NPC_BLACK_KNIGHT,0,0,'Get off that horse and fight me man-to-man!',14,0,100,0,0,0,'yell',34169),
(@NPC_BLACK_KNIGHT,1,0,'I will not fail you, master!',14,0,100,0,0,0,'yell',34185),
(@NPC_CAVIN,0,0,'$N challenges the Black Knight to trial by combat!',14,0,100,0,0,0,'yell',33803),
(@NPC_CAVIN,1,0,'Good luck, $N.',12,0,100,0,0,0,'say',33804);

UPDATE `conditions` SET `ConditionValue2`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10383 AND `SourceEntry`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=1 AND `ConditionValue1`=63663;
