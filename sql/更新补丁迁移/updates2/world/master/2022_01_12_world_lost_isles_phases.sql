/*
**************************
*    BfaCore Reforged    *
**************************
*/

UPDATE `creature_template` SET `flags_extra`='128' WHERE (`entry`='35238');
UPDATE `gameobject` SET `PhaseId`='169' WHERE (`guid`='21003514');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4721', '170', 'Lost Isles - Shipwreck Shore');
UPDATE `quest_template_addon` SET `NextQuestID`='14001' WHERE (`ID`='14239');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4778', '170', 'Lost Isles - Kaja\'mite Cavern');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4779', '170', 'Lost Isles - Horde Base Camp');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4780', '170', 'Lost Isles - The Vicious Vale');
REPLACE INTO `disables` (`sourceType`, `entry`, `flags`, `comment`) VALUES ('0', '69010', '1', 'Near Death');
UPDATE `creature_template` SET `unit_flags`='768' WHERE (`entry`='36471');
UPDATE `creature` SET `PhaseId`='0' WHERE (`guid`='40002538');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4899', '182', 'Lost Isles - Lost Peak');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4901', '182', 'Lost Isles - Ooostan Sor');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4900', '182', 'Lost Isles - Oostan Nord');
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4902', '182', 'Lost Isles - Oostan Ost');
