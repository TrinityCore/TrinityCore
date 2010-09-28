DELETE FROM `playercreateinfo_action` WHERE `type` = 0 AND `action` = 28734;
DELETE FROM `playercreateinfo_spell` WHERE `spell` = 28734;
DELETE FROM `playercreateinfo_spell_custom` WHERE `spell` = 28734;
UPDATE `playercreateinfo_action` SET `button` = 3 WHERE `race` = 10 AND `class` IN (2, 3, 5, 8, 9) AND `action` = 28730 AND `type` = 0;
UPDATE `playercreateinfo_action` SET `button` = 4 WHERE `race` = 10 AND `class` = 4 AND `action` = 25046 AND `type` = 0;
