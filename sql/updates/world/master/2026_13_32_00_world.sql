-- Evacuate the Merchant Square 14098: knock summons land on the door's trigger, the Rampaging Worgen gets a script
-- 68087 (Frightened Citizen 34981), 68070 (Frightened Citizen 35836 + trigger 80281) and 80281 (Rampaging Worgen 35660)
-- target TARGET_DEST_NEARBY_ENTRY: give them the door's Generic Trigger LAB - Multiphase 35374 inside the house
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (68087,68070,80281);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,68087,0,0,31,0,3,35374,0,0,0,0,'','Summon Frightened Citizen - Target Generic Trigger LAB - Multiphase'),
(13,3,68070,0,0,31,0,3,35374,0,0,0,0,'','Summon Frightened Citizen and Worgen - Target Generic Trigger LAB - Multiphase'),
(13,1,80281,0,0,31,0,3,35374,0,0,0,0,'','Summon Rampaging Worgen - Target Generic Trigger LAB - Multiphase');

-- Rampaging Worgen 35660: C++ script instead of SmartAI, created immune to PC and NPC (unit_flags 33536)
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_rampaging_worgen_evacuation', `unit_flags`=`unit_flags`|0x300 WHERE `entry`=35660;
DELETE FROM `smart_scripts` WHERE `entryorguid`=35660 AND `source_type`=0;

-- Frightened Citizen 35836 cowers with its line
UPDATE `creature_text` SET `Emote`=430 WHERE `CreatureID`=35836 AND `GroupID`=0;

-- Frightened Citizen 34981: missing line
DELETE FROM `creature_text` WHERE `CreatureID`=34981 AND `GroupID`=0 AND `ID`=7;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`SoundPlayType`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(34981,0,7,'Thank you!',12,0,100,1,0,0,0,35230,0,'Frightened Citizen to Player');
