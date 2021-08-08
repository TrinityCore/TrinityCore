-- damage of Shuriken Toss
UPDATE `spell_bonus_data` SET `ap_bonus`='0.6' WHERE `entry`='114014';

-- damage of Execute
UPDATE `spell_bonus_data` SET `ap_bonus`='2.55' WHERE `entry`='5308';

-- Daybreak for Holy Shock damage spell
INSERT INTO `spell_script_names` VALUES (25912, 'spell_pal_holy_shock_heal');

-- fix removing of Holy Spark (Item : S12 2P bonus - Heal)
INSERT INTO `spell_script_names` VALUES (2060, 'spell_pri_holy_spark');  -- Greater Heal
INSERT INTO `spell_script_names` VALUES (88684, 'spell_pri_holy_spark'); -- Holy Word: Serenity
INSERT INTO `spell_script_names` VALUES (2061, 'spell_pri_holy_spark');  -- Flash heal
