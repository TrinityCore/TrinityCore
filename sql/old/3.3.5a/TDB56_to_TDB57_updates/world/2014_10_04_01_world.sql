UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN(164885,164886,164887,164888,171939,171942,173284,173324,173327,174594,174595,174596,174597,174598,174599,174600,174601,174602,174603,174604,174605,174606,174607,174608,174684,174686,174708,174709,174712,174713,191124);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN(29525,29863,24198,23698,21611,21503);
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN(8978,2706) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN(4675,28156) AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=21057 AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=25806 AND `source_type`=0 AND `id`=2;
