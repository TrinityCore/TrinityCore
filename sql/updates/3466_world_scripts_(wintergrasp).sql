DELETE FROM `spell_script_target` WHERE entry IN
(56575,56661,56663,56665,56667,56669,61408);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(56575, 1, 27852),
(56661, 1, 27852),
(56663, 1, 27852),
(56665, 1, 27852),
(56667, 1, 27852),
(56669, 1, 27852),
(61408, 1, 27852);


update creature_template set maxhealth = 133525, minhealth = 133525, maxmana = 51360, minmana = 51360, spell1 = 53114, spell2 = 53112, spell3=53110 where entry = 28670;
update creature_template set maxhealth = 30000, minhealth = 30000, speed = 2, spell1=50025, spell2=50989, VehicleId = 36 where entry = 27881;
update creature_template set maxhealth = 50000, minhealth = 50000, speed = 1.6, spell1=50896, spell2=50652, VehicleId = 106 where entry = 28094;
update creature_template set maxhealth = 75000, minhealth = 75000, speed = 1, spell1=51678, VehicleId = 117 where entry IN (28312,32627);
update creature_template set maxhealth = 50000, minhealth = 50000, spell1=51362, VehicleId = 116 where entry IN (28319,32629);

update creature_template set scriptname = "npc_demolisher_engineerer" where entry in (30400,30499);