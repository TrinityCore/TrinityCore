DELETE FROM gameobject_template_addon WHERE entry = 195430;
REPLACE INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES ('4761', '179', 'Light\'s Dawn Cathedral - Gilneas');
UPDATE `gameobject` SET `PhaseGroup`='0', `state`='0' WHERE (`guid`='20406509');
UPDATE `gameobject` SET `PhaseGroup`='0', `state`='0' WHERE (`guid`='20406513');
UPDATE `creature_text` SET `Text`='Let the scythe unleash that which should not be bound! Let the soul dominate the beast, so that the beast does not dominate the soul!' WHERE (`CreatureID`='36814') AND (`GroupID`='0') AND (`ID`='0');
UPDATE `creature_text` SET `Text`='So is it true? Even the victims of the curse fight the Forsaken!' WHERE (`CreatureID`='37694') AND (`GroupID`='0') AND (`ID`='0');
UPDATE `creature_text` SET `Text`='The Forsaken will pay for what they have done!' WHERE (`CreatureID`='37694') AND (`GroupID`='1') AND (`ID`='0');
UPDATE `creature_text` SET `Text`='Thank you!' WHERE (`CreatureID`='37694') AND (`GroupID`='2') AND (`ID`='0');
UPDATE `creature_template` SET `ScriptName`='npc_lorna_crowley_43727' WHERE (`entry`='43727');
