-- Servant of Razelikh
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (7668,7669,7670,7671);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (7668,7669,7670,7671) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=766800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7668,0,0,0,25,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Razelikh - On Reset - Set Invincibility at 1 HP"),
(7668,0,1,0,2,0,100,1,0,5,0,0,11,10794,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Razelikh - Between 0-5% Health - Cast 'Spirit Shock' (No Repeat)"),
(7668,0,2,0,2,0,100,1,0,5,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Razelikh - Between 0-5% Health - Say Line 0 (No Repeat)"),
(7668,0,3,0,2,0,100,1,0,5,0,0,106,16,0,0,0,0,0,15,141812,10,0,0,0,0,0,"Servant of Razelikh - Between 0-5% Health - Remove Gameobject Flag 'Not Selectable' (Stone of Binding)"),
(7668,0,4,0,8,0,100,1,10805,0,0,0,80,766800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Razelikh - On spell hit - Run Script"),
(7669,0,0,0,25,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Grol - On Reset - Set Invincibility at 1 HP"),
(7669,0,1,0,2,0,100,1,0,5,0,0,11,10794,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Grol - Between 0-5% Health - Cast 'Spirit Shock' (No Repeat)"),
(7669,0,2,0,2,0,100,1,0,5,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Grol - Between 0-5% Health - Say Line 0 (No Repeat)"),
(7669,0,3,0,2,0,100,1,0,5,0,0,106,16,0,0,0,0,0,15,141857,10,0,0,0,0,0,"Servant of Grol - Between 0-5% Health - Remove Gameobject Flag 'Not Selectable' (Stone of Binding)"),
(7669,0,4,0,8,0,100,1,10834,0,0,0,80,766800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Grol - On spell hit - Run Script"),
(7670,0,0,0,25,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Allistarj - On Reset - Set Invincibility at 1 HP"),
(7670,0,1,0,2,0,100,1,0,5,0,0,11,10794,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Allistarj - Between 0-5% Health - Cast 'Spirit Shock' (No Repeat)"),
(7670,0,2,0,2,0,100,1,0,5,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Allistarj - Between 0-5% Health - Say Line 0 (No Repeat)"),
(7670,0,3,0,2,0,100,1,0,5,0,0,106,16,0,0,0,0,0,15,141858,10,0,0,0,0,0,"Servant of Allistarj - Between 0-5% Health - Remove Gameobject Flag 'Not Selectable' (Stone of Binding)"),
(7670,0,4,0,8,0,100,1,10835,0,0,0,80,766800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Allistarj - On spell hit - Run Script"),
(7671,0,0,0,25,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Sevine - On Reset - Set Invincibility at 1 HP"),
(7671,0,1,0,2,0,100,1,0,5,0,0,11,10794,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Sevine - Between 0-5% Health - Cast 'Spirit Shock' (No Repeat)"),
(7671,0,2,0,2,0,100,1,0,5,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Sevine - Between 0-5% Health - Say Line 0 (No Repeat)"),
(7671,0,3,0,2,0,100,1,0,5,0,0,106,16,0,0,0,0,0,15,141859,10,0,0,0,0,0,"Servant of Sevine - Between 0-5% Health - Remove Gameobject Flag 'Not Selectable' (Stone of Binding)"),
(7671,0,4,0,8,0,100,1,10836,0,0,0,80,766800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Sevine - On spell hit - Run Script"),
(766800,9,0,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Razelikh - On Spellhit 'Shackle Shatter' - Say Line 2"),
(766800,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Razelikh - On Spellhit 'Shackle Shatter' - Say Line 1"),
(766800,9,2,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Razelikh - On Spellhit 'Shackle Shatter' - Kill Self");

-- Stone of Binding
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (141812,141857,141858,141859);
UPDATE `gameobject_template_addon` SET `flags`=20 WHERE `entry` IN (141812,141857,141858,141859);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (141812,141857,141858,141859) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(141812,1,0,0,70,0,100,0,2,0,0,0,11,10805,0,0,0,0,0,19,7668,10,0,0,0,0,0,"Stone of Binding - On Gameobject State Changed - Cast 'Shackle Shatter'"),
(141857,1,0,0,70,0,100,0,2,0,0,0,11,10834,0,0,0,0,0,19,7669,10,0,0,0,0,0,"Stone of Binding - On Gameobject State Changed - Cast 'Shackle Shatter'"),
(141858,1,0,0,70,0,100,0,2,0,0,0,11,10835,0,0,0,0,0,19,7670,10,0,0,0,0,0,"Stone of Binding - On Gameobject State Changed - Cast 'Shackle Shatter'"),
(141859,1,0,0,70,0,100,0,2,0,0,0,11,10836,0,0,0,0,0,19,7671,10,0,0,0,0,0,"Stone of Binding - On Gameobject State Changed - Cast 'Shackle Shatter'");

-- Spell "Shackle Shatter"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (10805,10834,10835,10836);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,10805,0,0,31,0,3,7668,0,0,0,0,"","Spell 'Shackle Shatter' can only hit Servant of Razelikh"),
(13,3,10834,0,1,31,0,3,7669,0,0,0,0,"","Spell 'Shackle Shatter' can only hit Servant of Grol"),
(13,3,10835,0,2,31,0,3,7670,0,0,0,0,"","Spell 'Shackle Shatter' can only hit Servant of Allistarj"),
(13,3,10836,0,2,31,0,3,7671,0,0,0,0,"","Spell 'Shackle Shatter' can only hit Servant of Sevine");

DELETE FROM `creature_text` WHERE `CreatureID` IN (7668,7669,7670,7671);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7668,0,0,"%s's physical form is weakened. You notice the Stone of Binding near the creature is glowing! Strike now!",41,0,100,0,0,0,3642,0,"Servant of Razelikh"),
(7668,1,0,"FREEEEEEEEEEDDOOOOMM!",14,0,100,0,0,0,3641,0,"Servant of Razelikh"),
(7668,1,1,"Finally, the agony ceases....",12,0,100,0,0,0,3681,0,"Servant of Razelikh"),
(7668,1,2,"Give my regards to Commander Trebor.",12,0,100,0,0,0,3682,0,"Servant of Razelikh"),
(7668,1,3,"The Defiler... must warn Thrall...",12,0,100,0,0,0,3683,0,"Servant of Razelikh"),
(7668,1,4,"It was not his fault. Tell him that...",12,0,100,0,0,0,3684,0,"Servant of Razelikh"),
(7668,1,5,"Finally, released from his cursed grasp. Father, I come...",12,0,100,0,0,0,3685,0,"Servant of Razelikh"),
(7668,2,0,"Stone of Binding shatters, releasing the soul which it held.",16,0,100,0,0,0,0,0,"Servant of Razelikh"),
(7669,0,0,"%s's physical form is weakened. You notice the Stone of Binding near the creature is glowing! Strike now!",41,0,100,0,0,0,3642,0,"Servant of Grol"),
(7669,1,0,"FREEEEEEEEEEDDOOOOMM!",14,0,100,0,0,0,3641,0,"Servant of Grol"),
(7669,1,1,"Finally, the agony ceases....",12,0,100,0,0,0,3681,0,"Servant of Grol"),
(7669,1,2,"Give my regards to Commander Trebor.",12,0,100,0,0,0,3682,0,"Servant of Grol"),
(7669,1,3,"The Defiler... must warn Thrall...",12,0,100,0,0,0,3683,0,"Servant of Grol"),
(7669,1,4,"It was not his fault. Tell him that...",12,0,100,0,0,0,3684,0,"Servant of Grol"),
(7669,1,5,"Finally, released from his cursed grasp. Father, I come... ",12,0,100,0,0,0,3685,0,"Servant of Grol"),
(7669,2,0,"Stone of Binding shatters, releasing the soul which it held.",16,0,100,0,0,0,0,0,"Servant of Grol"),
(7670,0,0,"%s's physical form is weakened. You notice the Stone of Binding near the creature is glowing! Strike now!",41,0,100,0,0,0,3642,0,"Servant of Allistarj"),
(7670,1,0,"FREEEEEEEEEEDDOOOOMM!",14,0,100,0,0,0,3641,0,"Servant of Allistarj"),
(7670,1,1,"Finally, the agony ceases....",12,0,100,0,0,0,3681,0,"Servant of Allistarj"),
(7670,1,2,"Give my regards to Commander Trebor.",12,0,100,0,0,0,3682,0,"Servant of Allistarj"),
(7670,1,3,"The Defiler... must warn Thrall...",12,0,100,0,0,0,3683,0,"Servant of Allistarj"),
(7670,1,4,"It was not his fault. Tell him that...",12,0,100,0,0,0,3684,0,"Servant of Allistarj"),
(7670,1,5,"Finally, released from his cursed grasp. Father, I come... ",12,0,100,0,0,0,3685,0,"Servant of Allistarj"),
(7670,2,0,"Stone of Binding shatters, releasing the soul which it held.",16,0,100,0,0,0,0,0,"Servant of Allistarj"),
(7671,0,0,"%s's physical form is weakened. You notice the Stone of Binding near the creature is glowing! Strike now!",41,0,100,0,0,0,3642,0,"Servant of Sevine"),
(7671,1,0,"FREEEEEEEEEEDDOOOOMM!",14,0,100,0,0,0,3641,0,"Servant of Sevine"),
(7671,1,1,"Finally, the agony ceases....",12,0,100,0,0,0,3681,0,"Servant of Sevine"),
(7671,1,2,"Give my regards to Commander Trebor.",12,0,100,0,0,0,3682,0,"Servant of Sevine"),
(7671,1,3,"The Defiler... must warn Thrall...",12,0,100,0,0,0,3683,0,"Servant of Sevine"),
(7671,1,4,"It was not his fault. Tell him that...",12,0,100,0,0,0,3684,0,"Servant of Sevine"),
(7671,1,5,"Finally, released from his cursed grasp. Father, I come... ",12,0,100,0,0,0,3685,0,"Servant of Sevine"),
(7671,2,0,"Stone of Binding shatters, releasing the soul which it held.",16,0,100,0,0,0,0,0,"Servant of Sevine");
