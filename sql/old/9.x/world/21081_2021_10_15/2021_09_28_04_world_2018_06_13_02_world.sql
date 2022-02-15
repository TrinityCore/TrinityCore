-- Zeth'Gor Must Burn! (10792)
DELETE FROM `gameobject` WHERE `id`=183816;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20813,20814,20815,20816) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20813,0,0,1,8,0,100,512,35724,0,0,0,0,33,20813,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, Barracks - On Spellhit \'Throw Torch\' - Quest Credit (No Repeat)'),
(20813,0,1,2,61,0,100,512,0,0,0,0,0,41,0,0,0,0,0,0,15,183816,75,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, Barracks - On Spellhit \'Throw Torch\' - Despawn Game Object'),
(20813,0,2,0,61,0,100,512,0,0,0,0,0,11,36325,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, Barracks - On Spellhit \'Throw Torch\' - Spawn Game Object'),
(20814,0,0,1,8,0,100,512,35724,0,0,0,0,33,20814,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, Stable - On Spellhit \'Throw Torch\' - Quest Credit (No Repeat)'),
(20814,0,1,2,61,0,100,512,0,0,0,0,0,41,0,0,0,0,0,0,15,183816,20,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, Stable - On Spellhit \'Throw Torch\' - Despawn Game Object'),
(20814,0,2,0,61,0,100,512,0,0,0,0,0,11,36325,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, Stable - On Spellhit \'Throw Torch\' - Spawn Game Object'),
(20815,0,0,1,8,0,100,512,35724,0,0,0,0,33,20815,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, East Hovel - On Spellhit \'Throw Torch\' - Kill Credit (No Repeat)'),
(20815,0,1,2,61,0,100,512,0,0,0,0,0,41,0,0,0,0,0,0,15,183816,20,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, East Hovel - On Spellhit \'Throw Torch\' - Despawn Game Object'),
(20815,0,2,0,61,0,100,512,0,0,0,0,0,11,36325,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, East Hovel - On Spellhit \'Throw Torch\' - Spawn Game Object'),
(20816,0,0,1,8,0,100,512,35724,0,0,0,0,33,20816,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, West Hovel - On Spellhit \'Throw Torch\' - Quest Credit (No Repeat)'),
(20816,0,1,2,61,0,100,512,0,0,0,0,0,41,0,0,0,0,0,0,15,183816,20,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, West Hovel - On Spellhit \'Throw Torch\' - Despawn Game Object'),
(20816,0,2,0,61,0,100,512,0,0,0,0,0,11,36325,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zeth\'Gor Quest Credit Marker, West Hovel - On Spellhit \'Throw Torch\' - Spawn Game Object');

DELETE  FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=36325;
