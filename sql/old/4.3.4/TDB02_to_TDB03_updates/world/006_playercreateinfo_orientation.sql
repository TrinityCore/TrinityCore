-- Set Orientation for Human Characters
UPDATE `playercreateinfo` SET `orientation`=5.138057 WHERE `race`=1 AND `map`=0;
-- Set Orientation for Orc Characters
UPDATE `playercreateinfo` SET `orientation`=4.72222 WHERE `race`=2 AND `map`=1;
-- Set Orientation for Undead Characters
UPDATE `playercreateinfo` SET `orientation`=4.88839 WHERE `race`=5 AND `map`=0;
-- Set Orientation for Tauren Characters
UPDATE `playercreateinfo` SET `orientation`=0.302378 WHERE `race`=6 AND `map`=1;
-- Set Orientation for Gnome Characters
UPDATE `playercreateinfo` SET `orientation`=3.06393 WHERE `race`=7 AND `map`=0;
-- Set Orientation for Troll Characters
UPDATE `playercreateinfo` SET `orientation`=5.789449 WHERE `race`=8 AND `map`=1;
-- Set Orientation for Goblin Characters
UPDATE `playercreateinfo` SET `orientation`=1.55428 WHERE `race`=9 AND `map`=648;
-- Set Orientation for Worgen Characters
UPDATE `playercreateinfo` SET `orientation`=0.3338466 WHERE `race`=22 AND `map`=654;
-- Set Orientation and Zone for Deathknights
UPDATE `playercreateinfo` SET `zone`=4298, `orientation`=3.93485 WHERE `class`=6 AND `map`=609;
