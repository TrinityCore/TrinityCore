--
UPDATE `creature_text` SET `Text` = "I SAID GOOD DAY!", `BroadcastTextId` = 11060 WHERE `CreatureID` = 15481 AND `GroupID` = 0 AND `ID` = 0;
-- Someone forgot to add BroadcastTextId? No difference between current text and broadcast text & locales
UPDATE `creature_text` SET `BroadcastTextId` = 29523 WHERE `CreatureID` = 27692 AND `GroupID` = 10 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 29523 WHERE `CreatureID` = 27755 AND `GroupID` = 10 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 29523 WHERE `CreatureID` = 27756 AND `GroupID` = 10 AND `ID` = 0;

UPDATE `creature_text` SET `Text` = "Oh yes. Immensely. The pain will probably render you unconscious - hence the vat of slime you're floating in!", `BroadcastTextId` = 29647 WHERE `CreatureID` = 29112 AND `GroupID` = 2 AND `ID` = 0;
-- The text is slightly different https://youtu.be/hGtfsKWCmoE?t=333
UPDATE `creature_text` SET `Text` = "We will triumph. It is only a matter... of time.", `BroadcastTextId` = 16830 WHERE `CreatureID` = 17881 AND `GroupID` = 4 AND `ID` = 0;

UPDATE `creature_text` SET `Text` = "No more meddling for you!", `BroadcastTextId` = 16662 WHERE `CreatureID` = 17848 AND `GroupID` = 2 AND `ID` = 0;
UPDATE `creature_text` SET `Text` = "Go ahead and take forty winks.", `BroadcastTextId` = 15131 WHERE `CreatureID` = 17546 AND `GroupID` = 2 AND `ID` = 0;
-- Why not used? Because of ,,, istead of ...?
UPDATE `creature_text` SET `Text` = "I'm so tired. We really shouldn't have stayed up so late last night,,, well this morning. But it was fun! You do throw the best soirees milord.", `BroadcastTextId` = 11994 WHERE `CreatureID` = 16147 AND `GroupID` = 0 AND `ID` = 4;

UPDATE `creature_text` SET `Text` = "All of your efforts have been in vain, for the draining of the World Tree has already begun!  Soon the heart of your world will beat no more!", `BroadcastTextId` = 20432 WHERE `CreatureID` = 13083 AND `GroupID` = 0 AND `ID` = 0;
UPDATE `creature_text` SET `Text` = "Anu'dorini Talah. Ru shallora enudoril.", `BroadcastTextId` = 7416 WHERE `CreatureID` = 12152 AND `GroupID` = 20 AND `ID` = 0;
