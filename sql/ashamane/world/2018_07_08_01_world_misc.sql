
-- midsummer misc changes

-- -- Freewind Post in Thousand Needles 187973  45339 this position is under water, old content from 335
-- http://www.wowhead.com/npc=25945/thousand-needles-flame-keeper
-- http://www.wowhead.com/object=187973/horde-bonfire  thousand-needles
DELETE FROM gameobject WHERE id=187973 AND guid=45339;
DELETE FROM gameobject_addon WHERE guid=45339;
DELETE FROM game_event_gameobject WHERE guid=45339;

DELETE FROM creature WHERE id=25945 AND guid=82189;
DELETE FROM creature_addon WHERE guid=82189;
DELETE FROM game_event_creature WHERE guid=82189;


-- Dragonblight 194037  197221
-- Move NPC: 26482 Arctic Grizzly
UPDATE creature SET position_x = 3722.041504, position_y = 1438.191895, position_z = 95.381996, orientation = 0.675007 WHERE guid = 97946;

-- Blasted Lands  207989  194730
-- Delete NPC: 8301 Clack the Reaver
DELETE FROM creature WHERE id=8301 AND guid = 313936;
DELETE FROM creature_addon WHERE guid=313936;

-- Delete NPC: 5985 Snickerfang Hyena
DELETE FROM creature WHERE id=5985 AND guid = 164193;
DELETE FROM creature_addon WHERE guid=164193;

-- Delete NPC: 5985 Snickerfang Hyena
DELETE FROM creature WHERE id=5985 AND guid = 164371;
DELETE FROM creature_addon WHERE guid=164371;

-- Western Plaguelands  207990  193337
-- Move NPC: 44473 Shaggy Black Bear
UPDATE creature SET position_x = 1758.760742, position_y = -839.606201, position_z = 60.280636, orientation = 3.492409 WHERE guid = 194611;

-- Un'Goro Crater 207992  195387
-- Delete NPC: 9162 Young Diemetradon
DELETE FROM creature WHERE id=9162 AND guid = 282036;
DELETE FROM creature_addon WHERE guid=282036;

-- Southern Barrens 207986  195323
-- Move NPC: 37208 Thunderhead
UPDATE creature SET position_x = -3088.155518, position_y = -1673.074219, position_z = 91.783806, orientation = 3.755690 WHERE guid = 269427;

-- Move NPC: 11724 Hive'Ashi Swarmer
UPDATE creature SET position_x = -7052.108398, position_y = 922.357483, position_z = 8.292094, orientation = 6.036217 WHERE guid = 268821;

-- Delete NPC: 19827 Dark Conclave Ravenguard
DELETE FROM creature WHERE id=19827 AND guid = 77349;
DELETE FROM creature_addon WHERE guid=77349;

-- Move NPC: 22408 Furious Nether-wraith
UPDATE creature SET position_x = 2883.638428, position_y = 3753.060791, position_z = 156.406906, orientation = 0.773603 WHERE guid = 124369;

-- Delete NPC: 5990 Redstone Basilisk
DELETE FROM creature WHERE id=5990 AND guid = 164351;
DELETE FROM creature_addon WHERE guid=164351;

-- Delete NPC: 5992 Ashmane Boar
DELETE FROM creature WHERE id=5992 AND guid = 163837;
DELETE FROM creature_addon WHERE guid=163837;

-- Delete NPC: 5990 Redstone Basilisk
DELETE FROM creature WHERE id=5990 AND guid = 164362;
DELETE FROM creature_addon WHERE guid=164362;

-- Delete NPC: 5992 Ashmane Boar
DELETE FROM creature WHERE id=5992 AND guid = 164359;
DELETE FROM creature_addon WHERE guid=164359;

-- Delete NPC: 44473 Shaggy Black Bear
DELETE FROM creature WHERE id=44473 AND guid = 194611;
DELETE FROM creature_addon WHERE guid=194611;

-- Move NPC: 44473 Shaggy Black Bear
UPDATE creature SET position_x = 1765.478149, position_y = -891.917969, position_z = 64.795013, orientation = 5.938915 WHERE guid = 212864;

-- Delete NPC: 44473 Shaggy Black Bear
DELETE FROM creature WHERE id=44473 AND guid = 212897;
DELETE FROM creature_addon WHERE guid=212897;

-- Move NPC: 3252 Silithid Swarmer
UPDATE creature SET position_x = -3084.029785, position_y = -1706.388428, position_z = 91.871315, orientation = 2.881532 WHERE guid = 310907;

-- Move NPC: 3252 Silithid Swarmer
UPDATE creature SET position_x = -3088.409668, position_y = -1702.307129, position_z = 92.448997, orientation = 3.615880 WHERE guid = 310906;

-- Move NPC: 3252 Silithid Swarmer
UPDATE creature SET position_x = -3083.397461, position_y = -1718.156738, position_z = 91.725761, orientation = 0.427159 WHERE guid = 310908;

-- Move NPC: 3252 Silithid Swarmer
UPDATE creature SET position_x = -3097.278809, position_y = -1713.348389, position_z = 93.580391, orientation = 5.363390 WHERE guid = 310905;

-- Move NPC: 15650 Crazed Dragonhawk
UPDATE creature SET position_x = 9366.141602, position_y = -6741.563965, position_z = 21.314964, orientation = 1.416789 WHERE guid = 55447;

-- Delete NPC: 11735 Stonelash Scorpid
DELETE FROM creature WHERE id=11735 AND guid = 268340;
DELETE FROM creature_addon WHERE guid=268340;

-- Move NPC: 11735 Stonelash Scorpid
UPDATE creature SET position_x = -6740.333984, position_y = 564.333557, position_z = 4.310019, orientation = 3.963197 WHERE guid = 268568;

-- Move NPC: 9697 Giant Ember Worg Burning Steppes
UPDATE creature SET position_x = -8310.723633, position_y = -2572.412842, position_z = 135.058304, orientation = 5.254300 WHERE guid = 166446;

-- Move NPC: 48432 Blackrock Invader Burning Steppes
UPDATE creature SET position_x = -8304.607422, position_y = -2575.518555, position_z = 134.393463, orientation = 5.309266 WHERE guid = 313294;

-- Move NPC: 48432 Blackrock Invader Burning Steppes
UPDATE creature SET position_x = -8308.962891, position_y = -2582.161621, position_z = 136.524979, orientation = 0.306277 WHERE guid = 313442;

-- Delete NPC: 26807 Fizzcrank Bomber Flyby 01 Borean Tundra
DELETE FROM creature WHERE id=26807 AND guid = 102578;
DELETE FROM creature_addon WHERE guid=102578;

-- Move NPC: 32801 Borean Tundra Flame Warden Borean Tundra
UPDATE creature SET position_x = 4133.192383, position_y = 5395.344727, position_z = 25.494473, orientation = 2.114895 WHERE guid = 370657;

-- Delete NPC: 28011 Emperor Cobra Sholazar Basin
DELETE FROM creature WHERE id=28011 AND guid = 97002;

-- Delete NPC: 28011 Emperor Cobra Sholazar Basin
DELETE FROM creature WHERE id=28011 AND guid = 97003;

-- Move NPC: 32447 Zul'drak Sentinel Zul'Drak
UPDATE creature SET position_x = 5564.854004, position_y = -2616.365479, position_z = 292.420013, orientation = 6.222978 WHERE guid = 77176;

-- Move NPC: 24206 Prowling Worg Howling Fjord
UPDATE creature SET position_x = 2415.109863, position_y = -4823.185547, position_z = 246.972946, orientation = 2.813472 WHERE guid = 117405;

-- Move NPC: 21419 Infernal Attacker Wildhammer Stronghold
UPDATE creature SET position_x = -3989.601563, position_y = 1981.687012, position_z = 96.571106, orientation = 0.306716 WHERE guid = 74017;

-- NPC: 21419 Infernal Attacker Wildhammer Stronghold, the other modelid is invisible
update creature set modelid=17312 where id=21419;

-- Move NPC: 18062 Enraged Crusher Nagrand
UPDATE creature SET position_x = -2449.215332, position_y = 7563.344238, position_z = -1.236855, orientation = 0.387456 WHERE guid = 69184;

-- Move NPC: 18130 Marshfang Ripper Zangarmarsh
UPDATE creature SET position_x = 186.704773, position_y = 5933.279297, position_z = 22.073875, orientation = 3.485405 WHERE guid = 64681;

-- Move NPC: 18130 Marshfang Ripper: is not flying Zangarmarsh
UPDATE creature_template Set InhabitType=4 where entry=18130;

-- Delete NPC: 21022 Grovestalker Lynx Blade's Edge Mountains
DELETE FROM creature WHERE id=21022 AND guid = 62276;

-- Move NPC: 22408 Furious Nether-wraith Netherstorm
UPDATE creature SET position_x = 3153.821533, position_y = 3759.805664, position_z = 138.632034, orientation = 1.095192 WHERE guid = 124363;

-- Move NPC: 22408 Furious Nether-wraith Netherstorm
UPDATE creature SET position_x = 3104.014648, position_y = 3783.468262, position_z = 143.171387, orientation = 2.622792 WHERE guid = 124364;

-- Move NPC: 2734 Ridge Stalker Patriarch Dragon's Mouth
UPDATE creature SET position_x = -6944.237305, position_y = -2511.647949, position_z = 241.502213, orientation = 6.106462 WHERE guid = 162427;

-- double spawned and directly into midsummer area The Marsh
-- Delete NPC: 9162 Young Diemetradon
DELETE FROM creature WHERE id=9162 AND guid = 282129;
-- Delete NPC: 9163 Diemetradon
DELETE FROM creature WHERE id=9163 AND guid = 281978;
-- Delete NPC: 9162 Young Diemetradon
DELETE FROM creature WHERE id=9162 AND guid = 282182;
-- Delete NPC: 9162 Young Diemetradon
DELETE FROM creature WHERE id=9162 AND guid = 281874;
-- Delete NPC: 9162 Young Diemetradon
DELETE FROM creature WHERE id=9162 AND guid = 282183;
-- Delete NPC: 9162 Young Diemetradon
DELETE FROM creature WHERE id=9162 AND guid = 282137;
-- Delete NPC: 9163 Diemetradon
DELETE FROM creature WHERE id=9163 AND guid = 282148;
-- Delete NPC: 9163 Diemetradon
DELETE FROM creature WHERE id=9163 AND guid = 282153;

-- Move NPC: 37208 Thunderhead -- directly spawned into midsummer area Southern Barrens
UPDATE creature SET position_x = -3312.682617, position_y = -2200.256104, position_z = 92.184845, orientation = 5.684101 WHERE guid = 270411;
-- Delete NPC: 37208 Thunderhead
DELETE FROM creature WHERE id=37208 AND guid = 270408;
