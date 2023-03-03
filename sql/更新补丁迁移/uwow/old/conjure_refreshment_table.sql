DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_mage_conjure_refreshment_table';
REPLACE INTO `spell_script_names` VALUES
(43987, 'spell_mage_conjure_refreshment_table');

REPLACE INTO gameobject_template (entry, type, displayId, name, IconName, castBarCaption, unk1, faction, flags, size, questItem1, questItem2, questItem3, questItem4, questItem5, questItem6, data0, data1, data2, data3, data4, data5, data6, data7, data8, data9, data10, data11, data12, data13, data14, data15, data16, data17, data18, data19, data20, data21, data22, data23, data24, data25, data26, data27, data28, data29, data30, data31, unkInt32, AIName, ScriptName, WDBVerified) VALUES
(186811, 18, 7620, 'Refreshment Portal', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 43985, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
(207385, 18, 7620, 'Refreshment Portal', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 92823, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
(207388, 18, 7620, 'Refreshment Portal', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 92830, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0),
(211362, 18, 7620, 'Refreshment Portal', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 116134, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0);