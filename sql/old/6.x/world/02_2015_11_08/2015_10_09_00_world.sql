UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE `entry` IN (69668, 56467, 56113, 56112, 67997, 65673, 65671, 65670, 65656, 65558, 65454, 64562, 65365, 65253, 65674, 65679, 65723, 67138, 67091, 66949, 66853, 66581, 66574, 66478, 66422, 66292, 66137, 65975, 64855, 64854, 63876, 63750, 63624, 63623, 63622, 63217, 63335, 63332, 63331, 63328, 63955, 64337, 64838, 64827, 64738, 64705, 64672, 64569, 64563, 64542, 64540, 64399, 63307, 67153, 73335, 68463, 68399, 68375, 68370, 68337, 68287, 68106, 68077, 68072, 68025, 68464, 68538, 73318, 72754, 72751, 70371, 70370, 68987, 68939, 68687, 68651, 68586, 68023, 68004, 67734, 67716, 67554, 67553, 67537, 67534, 67533, 67528, 67508, 67503, 67834, 67840, 68003, 67999, 67998, 67986, 67985, 67948, 67867, 67866, 67865, 67844, 67498, 63080, 60578, 59377, 59189, 59188, 59138, 58785, 58745, 58735, 58721, 58607, 58384, 59391, 59411, 60566, 60175, 59856, 59855, 59822, 59806, 59719, 59704, 59608, 59550, 58376, 58206, 58160, 56287, 55789, 55768, 55614, 55497, 55438, 55274, 55122, 54961, 54617, 56366, 56432, 58114, 58113, 57108, 56787, 56786, 56784, 56782, 56490, 56434, 56433, 43929, 60622, 62802, 62202, 62166, 61847, 61823, 61822, 61820, 61819, 61816, 61796, 61693, 62227, 62232, 62786, 62736, 62444, 62436, 62379, 62378, 62295, 62275, 62274, 62273, 61503, 61496, 61482, 61016, 60970, 60903, 60864, 60857, 60785, 60688, 60687, 60684, 60678, 61020, 61021, 61469, 61468, 61454, 61371, 61297, 61261, 61218, 61066, 61065, 61026, 60677);

DELETE FROM `creature_queststarter` WHERE `id` IN (43929, 54614, 54615, 54616, 54617, 54697, 54854, 54870, 54913, 54915, 54917, 54918, 54922, 54926, 54960, 54961, 54998, 55009, 55054, 55094, 55122, 55135, 55172, 55180, 55196, 55209, 55234, 55274, 55282, 55283, 55284, 55333, 55403, 55438, 55480, 55497, 55521, 55614, 55646, 55647, 55648, 55768, 55789, 55809, 56062, 56063, 56064, 56065, 56110, 56111, 56112, 56113, 56114, 56115, 56133, 56138, 56204, 56205, 56207, 56208, 56222, 56287, 56312, 56313, 56327, 56336, 56339, 56346, 56347, 56348, 56351, 56358, 56366, 56406, 56432, 56433, 56434, 56440, 56465, 56467, 56474, 56490, 56707, 56708, 56714, 56720, 56773, 56774, 56782, 56784, 56786, 56787, 56802, 57108, 57198, 57209, 57211, 57242, 57298, 57319, 57324, 57385, 57401, 57402, 57405, 57407, 57408, 57424, 57744, 58113, 58114, 58160, 58206, 58225, 58228, 58278, 58376, 58384, 58413, 58420, 58421, 58422, 58434, 58506, 58508, 58509, 58510, 58511, 58547, 58564, 58607, 58609, 58630, 58646, 58647, 58704, 58705, 58706, 58707, 58708, 58709, 58710, 58712, 58713, 58714, 58715, 58716, 58717, 58718, 58721, 58735, 58736, 58743, 58745, 58761, 58779, 58785, 58821, 58919, 58920, 58962, 59058, 59073, 59076, 59077, 59138, 59173, 59178, 59188, 59189, 59263, 59272, 59273, 59353, 59354, 59371, 59377, 59383, 59391, 59402, 59405, 59411, 59418, 59441, 59442, 59448, 59449, 59450, 59451, 59452, 59517, 59533, 59550, 59569, 59573, 59584, 59585, 59586, 59594, 59597, 59608, 59620, 59636, 59695, 59696, 59701, 59703, 59704, 59716, 59719, 59806, 59821, 59822, 59855, 59856, 59894, 59899, 60135, 60136, 60139, 60161, 60173, 60175, 60178, 60180, 60182, 60436, 60503, 60506, 60528, 60529, 60566, 60570, 60578, 60596, 60622, 60673, 60674, 60675, 60677, 60678, 60679, 60684, 60687, 60688, 60694, 60735, 60785, 60795, 60857, 60864, 60903, 60968, 60970, 60973, 60981, 61016, 61020, 61021, 61026, 61065, 61066, 61161, 61218, 61261, 61297, 61371, 61454, 61467, 61468, 61469, 61470, 61482, 61495, 61496, 61503, 61512, 61539, 61580, 61581, 61583, 61584, 61585, 61625, 61693, 61716, 61724, 61796, 61816, 61819, 61820, 61822, 61823, 61847, 61880, 61881, 61962, 62092, 62112, 62124, 62151, 62166, 62180, 62202, 62203, 62227, 62232, 62236, 62273, 62274, 62275, 62278, 62295, 62304, 62321, 62322, 62377, 62378, 62379, 62385, 62436, 62444, 62538, 62573, 62666, 62667, 62668, 62736, 62771, 62772, 62774, 62779, 62786, 62802, 62810, 62859, 62872, 62923, 63009, 63013, 63014, 63061, 63070, 63071, 63072, 63073, 63075, 63077, 63080, 63083, 63086, 63194, 63217, 63218, 63238, 63258, 63272, 63285, 63296, 63307, 63310, 63315, 63317, 63327, 63328, 63331, 63332, 63335, 63349, 63367, 63484, 63498, 63535, 63542, 63596, 63614, 63622, 63623, 63624, 63626, 63721, 63748, 63750, 63751, 63754, 63758, 63778, 63784, 63785, 63822, 63876, 63955, 63983, 63984, 63994, 63996, 64001, 64002, 64007, 64010, 64011, 64028, 64029, 64030, 64031, 64032, 64033, 64036, 64041, 64058, 64085, 64101, 64231, 64259, 64315, 64330, 64337, 64344, 64395, 64399, 64432, 64448, 64464, 64467, 64484, 64488, 64508, 64517, 64521, 64531, 64533, 64534, 64540, 64542, 64562, 64563, 64566, 64569, 64572, 64582, 64596, 64597, 64599, 64610, 64672, 64691, 64705, 64738, 64764, 64815, 64827, 64838, 64854, 64855, 65253, 65289, 65341, 65365, 65395, 65454, 65528, 65558, 65648, 65651, 65655, 65656, 65669, 65670, 65671, 65672, 65673, 65674, 65679, 65723, 65724, 65910, 65975, 65998, 65999, 66126, 66135, 66136, 66137, 66190, 66199, 66260, 66292, 66352, 66372, 66412, 66422, 66436, 66442, 66452, 66466, 66478, 66512, 66515, 66518, 66520, 66522, 66550, 66551, 66552, 66553, 66557, 66574, 66581, 66635, 66636, 66638, 66639, 66646, 66656, 66657, 66659, 66660, 66662, 66667, 66675, 66730, 66733, 66734, 66738, 66739, 66741, 66815, 66819, 66822, 66824, 66825, 66838, 66841, 66845, 66853, 66918, 66949, 66998, 67091, 67138, 67153, 67370, 67386, 67402, 67444, 67498, 67503, 67508, 67528, 67533, 67534, 67535, 67537, 67542, 67553, 67554, 67562, 67565, 67581, 67603, 67608, 67618, 67628, 67630, 67631, 67660, 67662, 67663, 67673, 67716, 67734, 67767, 67834, 67840, 67844, 67847, 67865, 67866, 67867, 67880, 67939, 67940, 67948, 67976, 67983, 67984, 67985, 67986, 67989, 67990, 67992, 67993, 67994, 67995, 67996, 67997, 67998, 67999, 68003, 68004, 68023, 68025, 68072, 68077, 68106, 68166, 68182, 68274, 68275, 68287, 68337, 68370, 68375, 68392, 68399, 68417, 68462, 68463, 68464, 68465, 68526, 68538, 68586, 68651, 68687, 68908, 68939, 68987, 69371, 69389, 69413, 69418, 69425, 69433, 69529, 69533, 69535, 69536, 69550, 69551, 69572, 69668, 69670, 69673, 69674, 69675, 69677, 69678, 70022, 70160, 70297, 70316, 70358, 70360, 70370, 70371, 70398, 70517, 70520, 70751, 70752, 70980, 72426, 72751, 72754, 72870, 73082, 73303, 73318, 73335, 73348, 73353, 73570, 73626, 73657, 73691);

DELETE FROM `creature_questender` WHERE `id` IN (43929, 54614, 54615, 54616, 54617, 54697, 54854, 54870, 54913, 54915, 54917, 54918, 54922, 54960, 54961, 55009, 55054, 55094, 55122, 55135, 55172, 55180, 55196, 55234, 55274, 55282, 55283, 55284, 55333, 55403, 55497, 55521, 55614, 55646, 55647, 55648, 55768, 55789, 56062, 56063, 56064, 56065, 56110, 56111, 56112, 56113, 56114, 56115, 56133, 56138, 56204, 56205, 56207, 56208, 56222, 56287, 56312, 56313, 56336, 56339, 56346, 56347, 56348, 56358, 56406, 56432, 56433, 56434, 56440, 56465, 56467, 56474, 56490, 56708, 56714, 56720, 56773, 56782, 56784, 56786, 56787, 56802, 57108, 57198, 57209, 57211, 57242, 57298, 57319, 57324, 57385, 57401, 57402, 57405, 57407, 57408, 57424, 57744, 58113, 58114, 58160, 58206, 58225, 58228, 58278, 58376, 58384, 58413, 58420, 58421, 58422, 58434, 58506, 58547, 58564, 58607, 58609, 58646, 58647, 58704, 58705, 58706, 58707, 58708, 58709, 58710, 58712, 58713, 58714, 58715, 58716, 58717, 58721, 58735, 58736, 58743, 58745, 58761, 58779, 58785, 58821, 58919, 58920, 58962, 59058, 59073, 59076, 59077, 59138, 59178, 59263, 59272, 59273, 59353, 59354, 59371, 59391, 59402, 59411, 59418, 59441, 59442, 59448, 59449, 59450, 59451, 59452, 59533, 59550, 59569, 59573, 59584, 59586, 59597, 59608, 59636, 59695, 59696, 59701, 59703, 59704, 59716, 59719, 59821, 59894, 60135, 60136, 60139, 60161, 60173, 60175, 60182, 60436, 60503, 60506, 60528, 60529, 60566, 60570, 60578, 60596, 60622, 60673, 60674, 60675, 60679, 60684, 60687, 60688, 60694, 60735, 60785, 60795, 60857, 60864, 60968, 60970, 60973, 60981, 61016, 61020, 61021, 61065, 61066, 61161, 61218, 61261, 61297, 61371, 61454, 61467, 61468, 61469, 61470, 61482, 61495, 61496, 61503, 61539, 61580, 61581, 61583, 61584, 61585, 61625, 61693, 61716, 61724, 61796, 61816, 61819, 61820, 61822, 61823, 61847, 61880, 61881, 61962, 62092, 62112, 62124, 62151, 62166, 62180, 62202, 62203, 62227, 62232, 62236, 62273, 62274, 62275, 62278, 62295, 62304, 62321, 62377, 62378, 62379, 62385, 62436, 62444, 62538, 62573, 62666, 62667, 62668, 62736, 62771, 62772, 62774, 62779, 62786, 62802, 62810, 62859, 62923, 63009, 63014, 63061, 63070, 63071, 63072, 63073, 63075, 63077, 63080, 63083, 63086, 63194, 63217, 63218, 63238, 63258, 63272, 63285, 63296, 63307, 63310, 63317, 63327, 63328, 63331, 63332, 63335, 63349, 63367, 63484, 63535, 63542, 63596, 63614, 63622, 63623, 63624, 63626, 63721, 63750, 63751, 63754, 63758, 63784, 63785, 63822, 63876, 63955, 63983, 63984, 63994, 63996, 64028, 64029, 64058, 64085, 64101, 64231, 64259, 64315, 64330, 64337, 64344, 64395, 64399, 64432, 64467, 64517, 64540, 64542, 64562, 64563, 64569, 64572, 64582, 64597, 64599, 64672, 64705, 64738, 64764, 64815, 64827, 64838, 64854, 64855, 65253, 65289, 65341, 65365, 65395, 65454, 65558, 65648, 65651, 65655, 65656, 65669, 65670, 65671, 65672, 65673, 65674, 65679, 65723, 65724, 65910, 65975, 65998, 65999, 66126, 66135, 66136, 66137, 66190, 66199, 66260, 66292, 66352, 66372, 66412, 66422, 66436, 66442, 66452, 66466, 66478, 66512, 66515, 66518, 66520, 66522, 66550, 66551, 66552, 66553, 66557, 66581, 66635, 66636, 66638, 66639, 66646, 66656, 66667, 66675, 66730, 66733, 66734, 66738, 66739, 66741, 66815, 66819, 66822, 66824, 66845, 66918, 66949, 66998, 67091, 67138, 67153, 67370, 67386, 67402, 67444, 67533, 67534, 67535, 67537, 67542, 67553, 67554, 67565, 67581, 67603, 67608, 67618, 67628, 67630, 67631, 67660, 67662, 67663, 67673, 67716, 67734, 67767, 67834, 67840, 67844, 67847, 67866, 67880, 67939, 67948, 67976, 67983, 67984, 67985, 67986, 67989, 67990, 67992, 67993, 67994, 67995, 67996, 67997, 67998, 67999, 68003, 68004, 68025, 68072, 68077, 68106, 68166, 68182, 68274, 68275, 68287, 68337, 68370, 68375, 68399, 68417, 68462, 68463, 68464, 68465, 68526, 68538, 68586, 68651, 68687, 68939, 68987, 69371, 69389, 69418, 69425, 69551, 69572, 69668, 69670, 69673, 69674, 69675, 69677, 70022, 70160, 70316, 70358, 70360, 70398, 70517, 70520, 70751, 70752, 70980, 72426, 72751, 72754, 72870, 73082, 73303, 73318, 73348, 73353, 73570, 73626, 73657, 73691);

INSERT INTO `creature_queststarter` VALUES
(43929, 31752), -- Blingtron 4000, Blingtron 4000
(54614, 29552), -- Mishka, Critical Condition
(54615, 29553), -- Nodd Codejack, The Missing Admiral
(54616, 30069), -- Sully "The Pickle" McLeary, No Plan Survives Contact with the Enemy
(54616, 30070), -- Sully "The Pickle" McLeary, The Fall of Ga'trul
(54616, 31734), -- Sully "The Pickle" McLeary, Welcome Wagons
(54617, 31736), -- Rell Nightwind, Envoy of the Alliance
(54617, 31742), -- Rell Nightwind, Fractured Forces
(54617, 31745), -- Rell Nightwind, Onward and Inward
(54617, 31743), -- Rell Nightwind, Smoke Before Fire
(54617, 31737), -- Rell Nightwind, The Cost of War
(54617, 31735), -- Rell Nightwind, The Right Tool For The Job
(54697, 29578), -- Shao the Defiant, Defiance
(54697, 29579), -- Shao the Defiant, Rally the Survivors
(54854, 29580), -- Gentle Mother Hanae, Orchard-Supplied Hardware
(54854, 29585), -- Gentle Mother Hanae, Spitfire
(54870, 31853), -- General Nazgrim, All Aboard!
(54913, 29619), -- Lin Tenderpaw, A Courteous Guest
(54913, 29620), -- Lin Tenderpaw, The Great Banquet
(54913, 29618), -- Lin Tenderpaw, The High Elder
(54915, 29627), -- Groundskeeper Wu, A Proper Weapon
(54915, 29629), -- Groundskeeper Wu, A Steady Hand
(54915, 29628), -- Groundskeeper Wu, A Strong Back
(54915, 29630), -- Groundskeeper Wu, And a Heavy Fist
(54915, 29646), -- Groundskeeper Wu, Flying Colors
(54917, 29624), -- Instructor Xann, Attention
(54917, 29639), -- Instructor Xann, Flying Colors
(54917, 29623), -- Instructor Xann, Perfection
(54918, 29647), -- Instructor Myang, Flying Colors
(54918, 29637), -- Instructor Myang, The Rumpus
(54922, 29636), -- Master Stone Fist, A Test of Endurance
(54922, 29632), -- Master Stone Fist, Becoming Battle-Ready
(54922, 29634), -- Master Stone Fist, Husshun, the Wizened
(54922, 29635), -- Master Stone Fist, Xiao, the Eater
(54922, 29633), -- Master Stone Fist, Zhi-Zhi, the Dextrous
(54926, 29626), -- Xiao, Groundskeeper Wu
(54926, 29622), -- Xiao, Your Training Starts Now
(54960, 29922), -- Elder Lusshan, In Search of Wisdom
(54961, 31130), -- Lorewalker Cho, A Visit with Lorewalker Cho
(54998, 29617), -- Apprentice Yufi, Tian Monastery
(55009, 29670), -- Shao the Defiant, Maul Gormal
(55009, 29587), -- Shao the Defiant, Unbound
(55054, 29690), -- General Nazgrim, Into the Mists
(55094, 29631), -- Guard Shan Long, Burning Bright
(55122, 30568), -- Admiral Taylor, Helping the Cause
(55135, 31765), -- General Nazgrim, Paint it Red!
(55172, 29822), -- General Nazgrim, Lay of the Land
(55180, 29827), -- Shademaster Kiryn, Acid Rain
(55180, 29815), -- Shademaster Kiryn, Forensic Science
(55196, 29560), -- Bold Karasshi, Ancient Power
(55196, 29559), -- Bold Karasshi, Freeing Our Brothers
(55196, 29562), -- Bold Karasshi, Jailbreak
(55196, 29759), -- Bold Karasshi, Kung Din
(55196, 29558), -- Bold Karasshi, The Path of War
(55209, 29586), -- Traumatized Nectarbreeze Farmer, The Splintered Path
(55234, 29716), -- An Windfur, The Double Hozen Dare
(55234, 29723), -- An Windfur, The Jade Witch
(55274, 29717), -- An Windfur, Down Kitty!
(55274, 29723), -- An Windfur, The Jade Witch
(55282, 29725), -- Sully "The Pickle" McLeary, SI:7 Report: Fire From the Sky
(55283, 29727), -- Amber Kearnen, SI:7 Report: Take No Prisoners
(55284, 29726), -- Little Lu, SI:7 Report: Hostile Natives
(55333, 29733), -- Rell Nightwind, SI:7 Report: Lost in the Woods
(55403, 29765), -- Zin'Jun, Cryin' My Eyes Out
(55403, 29804), -- Zin'Jun, Seein' Red
(55438, 29745), -- Outcast Sprite, The Sprites' Plight
(55480, 29749), -- Pei-Zhi, An Urgent Plea
(55497, 29804), -- Zin'Jun, Seein' Red
(55521, 31777), -- Rivett Clutchpop, Choppertunity
(55521, 29821), -- Rivett Clutchpop, Missed Me By... That Much!
(55614, 29756), -- Pei-Zhi, A Humble Offering
(55614, 29753), -- Pei-Zhi, Back to Nature
(55614, 29751), -- Pei-Zhi, Ritual Artifacts
(55614, 29752), -- Pei-Zhi, The Wayward Dead
(55614, 29754), -- Pei-Zhi, To Bridge Earth and Sky
(55614, 29750), -- Pei-Zhi, Vessels of the Spirit
(55646, 29731), -- Shademaster Kiryn, Scouting Report: On the Right Track
(55647, 29824), -- Shokia, Scouting Report: Like Jinyu in a Barrel
(55648, 29730), -- Riko, Scouting Report: Hostile Natives
(55648, 29823), -- Riko, Scouting Report: The Friend of My Enemy
(55768, 31132), -- Lorewalker Cho, A Mile in My Shoes
(55768, 31121), -- Lorewalker Cho, Stay a While, and Listen
(55789, 29548), -- Rell Nightwind, The Mission
(55809, 31392), -- Peiji Goldendraft, Temple of the White Tiger
(55809, 31393), -- Peiji Goldendraft, Temple of the White Tiger
(56062, 29865), -- Tzu the Ironbelly, The Silkwood Road
(56063, 29882), -- Inkmaster Jo Po, Quill of Stingers
(56064, 29881), -- Inkmaster Glenzu, The Perfect Color
(56065, 31539), -- Inkmaster Wei, A Thing of Beauty
(56065, 29995), -- Inkmaster Wei, Shrine of the Dawn
(56110, 29871), -- Xiao, Clever Ashyo
(56110, 29874), -- Xiao, Kang Bramblestaff
(56110, 29875), -- Xiao, Kang Bramblestaff
(56110, 29873), -- Xiao, Ken-Ken
(56110, 29872), -- Xiao, Lin Tenderpaw
(56110, 30086), -- Xiao, The Search for the Hidden Master
(56111, 29981), -- Lin Tenderpaw, Stemming the Swarm
(56111, 29992), -- Lin Tenderpaw, Tenderpaw By Name, Tender Paw By Reputation
(56111, 29990), -- Lin Tenderpaw, Training and Discipline
(56112, 30230), -- Kang Bramblestaff, Re-Reclaim
(56112, 30123), -- Kang Bramblestaff, Skitterer Stew
(56112, 30129), -- Kang Bramblestaff, The Mogu Agenda
(56113, 29577), -- Clever Ashyo, Ashyo's Vision
(56114, 30351), -- Kang Bramblestaff, Lotus Tea
(56114, 30355), -- Kang Bramblestaff, Re-Reclaim
(56114, 30350), -- Kang Bramblestaff, Squirmy Delight
(56115, 30089), -- Ken-Ken, Apply Directly to the Forehead
(56115, 30081), -- Ken-Ken, Materia Medica
(56115, 30079), -- Ken-Ken, What's Eating Zhu's Watch?
(56115, 30088), -- Ken-Ken, Why So Serious?
(56115, 30090), -- Ken-Ken, Zhu's Despair
(56133, 29952), -- Chen Stormstout, Broken Dreams
(56133, 29907), -- Chen Stormstout, Chen and Li Li
(56133, 30046), -- Chen Stormstout, Chen's Resolution
(56133, 30078), -- Chen Stormstout, Cleaning House
(56133, 30075), -- Chen Stormstout, Clear the Way
(56133, 30049), -- Chen Stormstout, Doesn't Hold Water
(56133, 29919), -- Chen Stormstout, Great Minds Drink Alike
(56133, 30053), -- Chen Stormstout, Hop Hunting
(56133, 30085), -- Chen Stormstout, Into the Brewery
(56133, 30074), -- Chen Stormstout, Knocking on the Door
(56133, 29944), -- Chen Stormstout, Leaders Among Breeders
(56133, 29949), -- Chen Stormstout, Legacy
(56133, 30048), -- Chen Stormstout, Li Li and the Grain
(56133, 30073), -- Chen Stormstout, The Emperor
(56133, 29946), -- Chen Stormstout, The Warren-Mother
(56138, 30077), -- Li Li, Barrels, Man
(56138, 29947), -- Li Li, Crouching Carrot, Hidden Turnip
(56138, 29950), -- Li Li, Li Li's Day Off
(56138, 30031), -- Li Li, Taste Test
(56138, 30047), -- Li Li, The Chen Taste Test
(56138, 29945), -- Li Li, Yellow and Red Make Orange
(56204, 29908), -- Pang Thunderfoot, A Seemingly Endless Nuisance
(56204, 29909), -- Pang Thunderfoot, Low Turnip Turnout
(56204, 29912), -- Pang Thunderfoot, The Fabulous Miss Fanny
(56205, 29915), -- Liang Thunderfoot, A Neighbor's Duty
(56205, 29914), -- Liang Thunderfoot, Back to the Sty
(56205, 29913), -- Liang Thunderfoot, The Meat They'll Eat
(56207, 29911), -- Ang Thunderfoot, Practically Perfect Produce
(56207, 29940), -- Ang Thunderfoot, Taking a Crop
(56208, 29917), -- Francis the Shepherd Boy, Lupello
(56208, 29916), -- Francis the Shepherd Boy, Piercing Talons and Slavering Jaws
(56222, 29762), -- Bold Karasshi, Family Heirlooms
(56222, 29888), -- Bold Karasshi, Seek Out the Lorewalker
(56287, 29892), -- Lorewalker Cho, Body
(56287, 29890), -- Lorewalker Cho, Finding Your Center
(56287, 29893), -- Lorewalker Cho, Hue
(56287, 29891), -- Lorewalker Cho, Potency
(56312, 29918), -- Shang Thunderfoot, A Lesson in Bravery
(56313, 29935), -- Tooki Tooki, Orders are Orders
(56327, 29924), -- Nibi Nibi, Kill Kher Shan
(56336, 29936), -- Chief Kah Kah, Instant Messaging
(56336, 31239), -- Chief Kah Kah, What's in a Name Name?
(56339, 29941), -- General Nazgrim, Beyond the Horizon
(56339, 29966), -- General Nazgrim, Burning Down the House
(56339, 30015), -- General Nazgrim, Dawn's Blossom
(56339, 29943), -- General Nazgrim, Guerrillas in our Midst
(56346, 29926), -- Foreman Mann, Calamity Jade
(56346, 29928), -- Foreman Mann, I Have No Jade And I Must Scream
(56346, 29927), -- Foreman Mann, Mann's Man
(56346, 29931), -- Foreman Mann, The Serpent's Heart
(56347, 29929), -- Hao Mann, Trapped!
(56348, 29925), -- Toya, All We Can Spare
(56348, 31230), -- Toya, Welcome to Dawn's Blossom
(56351, 29933), -- Bo Bo, The Bees' Knees
(56358, 29942), -- Eekle Eekle, Silly Wikket, Slickies are for Hozen
(56366, 29762), -- Bold Karasshi, Family Heirlooms
(56406, 29939), -- Rivett Clutchpop, Boom Bait
(56406, 29967), -- Rivett Clutchpop, Boom Goes the Doonamite!
(56406, 29937), -- Rivett Clutchpop, Furious Fowl
(56406, 29968), -- Rivett Clutchpop, Green-ish Energy
(56406, 29971), -- Rivett Clutchpop, The Scouts Return
(56432, 29899), -- Ren Whitepaw, Rest in Peace
(56433, 29900), -- Lina Whitepaw, An Ancient Legend
(56434, 29898), -- Anduin Wrynn, Sacred Waters
(56440, 29877), -- Muno the Farmhand, A Poor Grasp of the Basics
(56465, 29910), -- Ana Thunderfoot, Rampaging Rodents
(56467, 29930), -- Hao Mann, What's Mined Is Yours
(56474, 30172), -- Mudmug, Barreling Along
(56474, 30624), -- Mudmug, It Does You No Good In The Keg
(56474, 30653), -- Mudmug, It Does You No Good In The Keg
(56474, 29951), -- Mudmug, Muddy Water
(56474, 30076), -- Mudmug, The Fanciest Water
(56474, 30051), -- Mudmug, The Great Water Hunt
(56474, 29948), -- Mudmug, Thieves to the Core
(56490, 29966), -- General Nazgrim, Burning Down the House
(56707, 31486), -- Chin, Everything I Know About Cooking
(56708, 29920), -- Syra Goldendraft, Getting Permission
(56714, 29988), -- Master Bruised Paw, A Taste For Eggs
(56714, 29986), -- Master Bruised Paw, Fog Wards
(56714, 29985), -- Master Bruised Paw, They Will Be Mist
(56714, 29984), -- Master Bruised Paw, Unyielding Fists: Trial of Bamboo
(56714, 29989), -- Master Bruised Paw, Unyielding Fists: Trial of Stone
(56714, 29987), -- Master Bruised Paw, Unyielding Fists: Trial of Wood
(56720, 29982), -- Loon Mai, Evacuation Orders
(56720, 30628), -- Loon Mai, The Gratitude of Stoneplow
(56720, 29983), -- Loon Mai, The Hidden Master
(56720, 30622), -- Loon Mai, The Swarm Begins
(56773, 29757), -- Yan, Bottletoads
(56774, 32018), -- Bolo, His Name Was... Stormstout
(56782, 29998), -- Elder Sage Rain-Zhu, The Librarian's Quandary
(56782, 29997), -- Elder Sage Rain-Zhu, The Scryer's Dilemma
(56782, 32019), -- Elder Sage Rain-Zhu, They Call Him... Stormstout
(56784, 30005), -- Fei, Lighting Up the Sky
(56784, 30000), -- Fei, The Jade Serpent
(56784, 29999), -- Fei, The Rider's Bind
(56786, 30004), -- Lorewalker Stonestep, Everything In Its Place
(56786, 30001), -- Lorewalker Stonestep, Moth-Ridden
(56786, 30002), -- Lorewalker Stonestep, Pages of History
(56787, 30011), -- Wise Mari, A New Vision
(56802, 29600), -- Zhang Yue, Snap Judgment
(56802, 29581), -- Zhang Yue, The Golden Dream
(57108, 30484), -- General Nazgrim, Gauging Our Progress
(57108, 30466), -- General Nazgrim, Sufficient Motivation
(57198, 30626), -- Guard Captain Oakenshield, Retreat!
(57198, 30625), -- Guard Captain Oakenshield, Students No More
(57209, 30030), -- Grainer Pan, Out of Sprite
(57211, 30028), -- Grainlord Kai, Grain Recovery
(57211, 30032), -- Grainlord Kai, The Quest for Better Barley
(57211, 30029), -- Grainlord Kai, Wee Little Shenanigans
(57242, 30498), -- Elder Sage Wind-Yi, Get Back Here!
(57242, 30499), -- Elder Sage Wind-Yi, Get Back Here!
(57298, 30419), -- Farmer Fung, A Blue Feather for Farmer Fung
(57298, 30421), -- Farmer Fung, A Dish for Farmer Fung
(57298, 30418), -- Farmer Fung, A Jade Cat for Farmer Fung
(57298, 30417), -- Farmer Fung, A Lovely Apple for Farmer Fung
(57298, 30420), -- Farmer Fung, A Marsh Lily for Farmer Fung
(57298, 30416), -- Farmer Fung, A Ruby Shard for Farmer Fung
(57298, 30518), -- Farmer Fung, Farmer Fung's Vote II: On the Loose
(57298, 31947), -- Farmer Fung, Farmer Fung's Vote III: Crazy For Cabbage
(57298, 30317), -- Farmer Fung, Water, Water Everywhere
(57319, 30063), -- Elder Sage Storm-Sing, Behind the Masks
(57319, 30064), -- Elder Sage Storm-Sing, Saving the Sutras
(57324, 30065), -- Elder Sage Tai-Feng, Arrows of Fortune
(57324, 30068), -- Elder Sage Tai-Feng, Flames of the Void
(57324, 30066), -- Elder Sage Tai-Feng, Hidden Power
(57324, 30006), -- Elder Sage Tai-Feng, The Darkness Around Us
(57324, 30067), -- Elder Sage Tai-Feng, The Shadow of Doubt
(57385, 30516), -- Gai Lan, Growing the Farm I: A Little Problem
(57385, 30052), -- Gai Lan, Weed War
(57401, 30054), -- Mung-Mung, Enough is Ookin' Enough
(57401, 30259), -- Mung-Mung, Mung-Mung's Vote II: Rotten to the Core
(57401, 31946), -- Mung-Mung, Mung-Mung's Vote III: The Great Carrot Caper
(57402, 30412), -- Haohan Mudclaw, A Blue Feather for Haohan
(57402, 30414), -- Haohan Mudclaw, A Dish for Haohan
(57402, 30411), -- Haohan Mudclaw, A Jade Cat for Haohan
(57402, 30410), -- Haohan Mudclaw, A Lovely Apple for Haohan
(57402, 30413), -- Haohan Mudclaw, A Marsh Lily for Haohan
(57402, 30409), -- Haohan Mudclaw, A Ruby Shard for Haohan
(57402, 30522), -- Haohan Mudclaw, Haohan's Vote II: The Real Culprits
(57402, 30319), -- Haohan Mudclaw, Pest Problems
(57405, 30072), -- Silkmaster Tsai, Where Silk Comes From
(57407, 30058), -- Master Goh, Mothallus!
(57408, 30057), -- Mina Mudclaw, Seeing Orange
(57424, 30059), -- Journeyman Chu, The Moth Rebellion
(57744, 30084), -- Mei Barrelbottom, Borderlands
(57744, 30080), -- Mei Barrelbottom, Finding Yi-Mo
(57744, 30133), -- Mei Barrelbottom, Into the Wilds
(57744, 30178), -- Mei Barrelbottom, Into the Wilds
(57744, 30461), -- Mei Barrelbottom, Into the Wilds
(57744, 30462), -- Mei Barrelbottom, Into the Wilds
(57744, 30083), -- Mei Barrelbottom, Securing the Province
(57744, 30091), -- Mei Barrelbottom, Tears of Pandaria
(58113, 30132), -- Sunwalker Dezco, Going West
(58113, 30464), -- Sunwalker Dezco, Going West
(58113, 30130), -- Sunwalker Dezco, Herbal Remedies
(58113, 30131), -- Sunwalker Dezco, Life
(58113, 30121), -- Sunwalker Dezco, Search Party
(58114, 30124), -- Kor Bloodtusk, Blind Them!
(58114, 30163), -- Kor Bloodtusk, For the Tribe
(58114, 30229), -- Kor Bloodtusk, The Greater Danger
(58114, 30127), -- Kor Bloodtusk, Threat from Dojan
(58160, 30179), -- Chezin Dawnchaser, Poisoned!
(58206, 30128), -- Kang Bramblestaff, The Pools of Youth
(58225, 30135), -- Instructor Tong, Beating the Odds
(58225, 30138), -- Instructor Tong, Choosing the One
(58225, 30137), -- Instructor Tong, Egg Collection
(58225, 30136), -- Instructor Tong, Empty Nests
(58225, 30139), -- Instructor Tong, The Rider's Journey
(58225, 30140), -- Instructor Tong, The Rider's Journey
(58225, 30141), -- Instructor Tong, The Rider's Journey
(58228, 31707), -- Instructor Skythorn, A Tangled Web
(58228, 30158), -- Instructor Skythorn, Disarming the Enemy
(58228, 30142), -- Instructor Skythorn, It's A...
(58228, 31712), -- Instructor Skythorn, Monkey Mischief
(58228, 30155), -- Instructor Skythorn, Restoring the Balance
(58228, 31698), -- Instructor Skythorn, Thinning The Pack
(58228, 31706), -- Instructor Skythorn, Weeping Widows
(58278, 30169), -- Tired Shushen, Raid Leader Slovan
(58278, 30168), -- Tired Shushen, Thieving Raiders
(58376, 30082), -- Yi-Mo Longbrow, Cheer Up, Yi-Mo
(58384, 31704), -- Azure Hatchling, Pooped
(58384, 30150), -- Azure Hatchling, Sweet as Honey
(58413, 30149), -- Jenova Longeye, A Feast for the Senses
(58413, 30147), -- Jenova Longeye, Fragments of the Past
(58413, 30148), -- Jenova Longeye, Just a Flesh Wound
(58413, 30146), -- Jenova Longeye, Snack Time
(58420, 30145), -- Instructor Windblade, Flight Training: Full Speed Ahead
(58420, 30187), -- Instructor Windblade, Flight Training: In Due Course
(58420, 30144), -- Instructor Windblade, Flight Training: Ring Round-Up
(58420, 30152), -- Instructor Windblade, The Sky Race
(58421, 30184), -- Hemet Nesingwary, Mushan Mastery: Darkhide
(58422, 30181), -- Hemet Nesingwary Jr., Mushan Mastery
(58422, 30186), -- Hemet Nesingwary Jr., Parental Mastery
(58422, 30185), -- Hemet Nesingwary Jr., Tortoise Mastery
(58434, 32038), -- Matt "Lucky" Gotcher, Stag Mastery
(58506, 31713), -- Ace Longpaw, The Big Brew-haha
(58508, 31709), -- Big Bao, Lingering Doubt
(58509, 31699), -- Ningna Darkwheel, Sprite Fright
(58509, 31700), -- Ningna Darkwheel, The Shoe Is On The Other Foot
(58510, 30157), -- Suchi the Sweet, Emptier Nests
(58510, 30159), -- Suchi the Sweet, Preservation
(58511, 31714), -- Qua-Ro Whitebrow, Saving the Serpents
(58511, 31708), -- Qua-Ro Whitebrow, Serpent's Scale
(58547, 30269), -- Koro Mistwalker, Unsafe Passage
(58564, 33250), -- Elder Anli, A Time-Lost Treasure
(58564, 31701), -- Elder Anli, Dark Huntress
(58564, 31703), -- Elder Anli, Madcap Mayhem
(58564, 31705), -- Elder Anli, Needle Me Not
(58564, 31702), -- Elder Anli, On The Prowl
(58564, 31784), -- Elder Anli, Onyx To Goodness
(58564, 30188), -- Elder Anli, Riding the Skies
(58564, 31810), -- Elder Anli, Riding the Skies
(58564, 31811), -- Elder Anli, Riding the Skies
(58564, 31194), -- Elder Anli, Slitherscale Suppression
(58564, 31715), -- Elder Anli, The Big Kah-Oona
(58564, 31711), -- Elder Anli, The Seed of Doubt
(58564, 31717), -- Elder Anli, The Trainer's Challenge: Ace Longpaw
(58564, 31718), -- Elder Anli, The Trainer's Challenge: Big Bao
(58564, 31719), -- Elder Anli, The Trainer's Challenge: Ningna Darkwheel
(58564, 31721), -- Elder Anli, The Trainer's Challenge: Qua-Ro Whitebrow
(58564, 31720), -- Elder Anli, The Trainer's Challenge: Suchi the Sweet
(58564, 30143), -- Elder Anli, They Grow Like Weeds
(58564, 30134), -- Elder Anli, Wild Things
(58607, 30174), -- Sunwalker Dezco, For Family
(58607, 30164), -- Sunwalker Dezco, The Stoneplow Convoy
(58607, 30241), -- Sunwalker Dezco, Warn Stoneplow
(58609, 30268), -- Anduin Wrynn, The Murksweats
(58630, 30175), -- Ambassador Han, The Mantid
(58630, 30361), -- Ambassador Han, The Mantid
(58646, 31672), -- Farmer Yoon, A Pumpkin-y Perfume
(58646, 30517), -- Farmer Yoon, Farmer Fung's Vote I: Yak Attack
(58646, 30260), -- Farmer Yoon, Growing the Farm I: The Weeds
(58646, 30523), -- Farmer Yoon, Growing the Farm II: The Broken Wagon
(58646, 30529), -- Farmer Yoon, Growing the Farm III: The Mossy Boulder
(58646, 30521), -- Farmer Yoon, Haohan's Vote I: Bungalow Break-In
(58646, 30525), -- Farmer Yoon, Haohan's Vote III: Pure Poison
(58646, 30527), -- Farmer Yoon, Haohan's Vote IV: Melons For Felons
(58646, 30528), -- Farmer Yoon, Haohan's Vote V: Chief Yip-Yip
(58646, 31942), -- Farmer Yoon, It's Melon Time
(58646, 30535), -- Farmer Yoon, Learn and Grow I: Seeds
(58646, 30254), -- Farmer Yoon, Learn and Grow II: Tilling and Planting
(58646, 30255), -- Farmer Yoon, Learn and Grow III: Tending Crops
(58646, 30256), -- Farmer Yoon, Learn and Grow IV: Harvesting
(58646, 30257), -- Farmer Yoon, Learn and Grow V: Halfhill Market
(58646, 30258), -- Farmer Yoon, Mung-Mung's Vote I: A Hozen's Problem
(58646, 30519), -- Farmer Yoon, Nana's Vote I: Nana's Secret Recipe
(58646, 31673), -- Farmer Yoon, Red Blossom Leeks, You Make the Croc-in' World Go Down
(58646, 30337), -- Farmer Yoon, Simian Sabotage
(58646, 31941), -- Farmer Yoon, Squash Those Foul Odors
(58646, 30335), -- Farmer Yoon, Stalling the Ravage
(58646, 30334), -- Farmer Yoon, Stealing is Bad... Re-Stealing is OK
(58646, 31670), -- Farmer Yoon, That Dangling Carrot
(58646, 31669), -- Farmer Yoon, The Cabbage Test
(58646, 30336), -- Farmer Yoon, The Kunzen Hunter-Chief
(58646, 30333), -- Farmer Yoon, The Lesser of Two Evils
(58646, 31674), -- Farmer Yoon, The Pink Turnip Challenge
(58646, 31675), -- Farmer Yoon, The White Turnip Treatment
(58646, 31943), -- Farmer Yoon, Which Berries? Witchberries.
(58646, 31671), -- Farmer Yoon, Why Not Scallions?
(58647, 30382), -- Ella, A Blue Feather for Ella
(58647, 30386), -- Ella, A Dish for Ella
(58647, 30381), -- Ella, A Jade Cat for Ella
(58647, 30189), -- Ella, A Lovely Apple for Ella
(58647, 30383), -- Ella, A Marsh Lily for Ella
(58647, 30160), -- Ella, A Ruby Shard for Ella
(58647, 31538), -- Ella, A Worthy Brew
(58647, 31537), -- Ella, Ella's Taste Test
(58647, 31534), -- Ella, The Beginner's Brew
(58647, 30327), -- Ella, You Have to Burn the Ropes
(58704, 30261), -- Kelari Featherfoot, Roll Club: Serpent's Spine
(58705, 30425), -- Fish Fellreed, A Blue Feather for Fish
(58705, 30427), -- Fish Fellreed, A Dish for Fish
(58705, 30424), -- Fish Fellreed, A Jade Cat for Fish
(58705, 30423), -- Fish Fellreed, A Lovely Apple for Fish
(58705, 30426), -- Fish Fellreed, A Marsh Lily for Fish
(58705, 30422), -- Fish Fellreed, A Ruby Shard for Fish
(58705, 30524), -- Fish Fellreed, Growing the Farm II: Knock on Wood
(58705, 31313), -- Fish Fellreed, Just A Folk Story
(58705, 31314), -- Fish Fellreed, Old Man Thistle's Treasure
(58705, 30326), -- Fish Fellreed, The Kunzen Legend-Chief
(58706, 30388), -- Gina Mudclaw, A Blue Feather for Gina
(58706, 30390), -- Gina Mudclaw, A Dish for Gina
(58706, 30387), -- Gina Mudclaw, A Jade Cat for Gina
(58706, 30380), -- Gina Mudclaw, A Lovely Apple for Gina
(58706, 30389), -- Gina Mudclaw, A Marsh Lily for Gina
(58706, 30379), -- Gina Mudclaw, A Ruby Shard for Gina
(58706, 31945), -- Gina Mudclaw, Learn and Grow VI: Gina's Vote
(58706, 30322), -- Gina Mudclaw, Money Matters
(58707, 30394), -- Old Hillpaw, A Blue Feather for Old Hillpaw
(58707, 30396), -- Old Hillpaw, A Dish for Old Hillpaw
(58707, 30393), -- Old Hillpaw, A Jade Cat for Old Hillpaw
(58707, 30392), -- Old Hillpaw, A Lovely Apple for Old Hillpaw
(58707, 30395), -- Old Hillpaw, A Marsh Lily for Old Hillpaw
(58707, 30391), -- Old Hillpaw, A Ruby Shard for Old Hillpaw
(58707, 30318), -- Old Hillpaw, Chasing the Chicken
(58708, 30406), -- Sho, A Blue Feather for Sho
(58708, 30408), -- Sho, A Dish for Sho
(58708, 30405), -- Sho, A Jade Cat for Sho
(58708, 30404), -- Sho, A Lovely Apple for Sho
(58708, 30407), -- Sho, A Marsh Lily for Sho
(58708, 30403), -- Sho, A Ruby Shard for Sho
(58708, 31531), -- Sho, Mission: Aerial Threat
(58708, 31529), -- Sho, Mission: Culling The Vermin
(58708, 31532), -- Sho, Mission: Predator of the Cliffs
(58708, 30325), -- Sho, Where It Counts
(58709, 30400), -- Chee Chee, A Blue Feather for Chee Chee
(58709, 30402), -- Chee Chee, A Dish for Chee Chee
(58709, 30399), -- Chee Chee, A Jade Cat for Chee Chee
(58709, 30398), -- Chee Chee, A Lovely Apple for Chee Chee
(58709, 30401), -- Chee Chee, A Marsh Lily for Chee Chee
(58709, 30397), -- Chee Chee, A Ruby Shard for Chee Chee
(58709, 31341), -- Chee Chee, A Wolf In Sheep's Clothing
(58709, 31338), -- Chee Chee, Lost Sheepie
(58709, 31339), -- Chee Chee, Lost Sheepie... Again
(58709, 30324), -- Chee Chee, Not in Chee-Chee's Backyard
(58709, 31340), -- Chee Chee, Oh Sheepie...
(58710, 30437), -- Jogu the Drunk, A Blue Feather for Jogu
(58710, 30439), -- Jogu the Drunk, A Dish for Jogu
(58710, 30436), -- Jogu the Drunk, A Jade Cat for Jogu
(58710, 30435), -- Jogu the Drunk, A Lovely Apple for Jogu
(58710, 30438), -- Jogu the Drunk, A Marsh Lily for Jogu
(58710, 30434), -- Jogu the Drunk, A Ruby Shard for Jogu
(58710, 31323), -- Jogu the Drunk, Buy A Fish A Brewery?
(58710, 31320), -- Jogu the Drunk, Buy A Fish A Drink?
(58710, 31322), -- Jogu the Drunk, Buy A Fish A Keg?
(58710, 31321), -- Jogu the Drunk, Buy A Fish A Round?
(58710, 30321), -- Jogu the Drunk, Weed War II
(58712, 30332), -- Kol Ironpaw, Fatty Goatsteak
(58712, 31467), -- Kol Ironpaw, Strong as a Tiger
(58713, 31471), -- Anthea Ironpaw, Agile as a Tiger
(58713, 30329), -- Anthea Ironpaw, Cindergut Peppers
(58714, 30331), -- Mei Mei Ironpaw, The Mile-High Grub
(58714, 31474), -- Mei Mei Ironpaw, The Soup of Contemplation
(58715, 31476), -- Yan Ironpaw, The Spirit of Cooking
(58715, 30328), -- Yan Ironpaw, The Thousand-Year Dumpling
(58716, 31477), -- Jian Ironpaw, Endurance
(58716, 30330), -- Jian Ironpaw, The Truffle Shuffle
(58717, 31480), -- Bobo Ironpaw, Have a Drink
(58718, 32189), -- Merchant Greenfield, A Shabby New Face
(58721, 30252), -- Farmer Yoon, A Helping Hand
(58735, 30384), -- Lyalia, Blind Them!
(58735, 30363), -- Lyalia, Going on the Offensive
(58735, 30465), -- Lyalia, Going on the Offensive
(58735, 30349), -- Lyalia, Threat from Dojan
(58736, 30267), -- Gladecaster Lang, Watery Woes
(58743, 30242), -- Yumi Goldenpaw, Survival Ring: Blades
(58743, 30240), -- Yumi Goldenpaw, Survival Ring: Flame
(58745, 30348), -- Lorekeeper Vaeldrin, Immortality?
(58745, 30359), -- Lorekeeper Vaeldrin, The Lord Reclaimer
(58745, 30344), -- Lorekeeper Vaeldrin, The Lost Dynasty
(58745, 30347), -- Lorekeeper Vaeldrin, The Pools of Youth
(58745, 30357), -- Lorekeeper Vaeldrin, The Stoneplow Convoy
(58745, 30445), -- Lorekeeper Vaeldrin, The Waters of Youth
(58745, 30346), -- Lorekeeper Vaeldrin, Where are the Pools
(58761, 30431), -- Tina Mudclaw, A Blue Feather for Tina
(58761, 30433), -- Tina Mudclaw, A Dish for Tina
(58761, 30430), -- Tina Mudclaw, A Jade Cat for Tina
(58761, 30429), -- Tina Mudclaw, A Lovely Apple for Tina
(58761, 30432), -- Tina Mudclaw, A Marsh Lily for Tina
(58761, 30428), -- Tina Mudclaw, A Ruby Shard for Tina
(58761, 30323), -- Tina Mudclaw, They Don't Even Wear Them
(58779, 30352), -- Daggle Bombstrider, Crane Mastery
(58779, 31262), -- Daggle Bombstrider, Crane Mastery: Needlebeak
(58779, 30353), -- Daggle Bombstrider, Profit Mastery
(58779, 31260), -- Daggle Bombstrider, Profit Mastery: Chasheen
(58785, 30172), -- Mudmug, Barreling Along
(58821, 30354), -- Lyalia, No Sister Left Behind
(58821, 30356), -- Lyalia, Sever Their Supply Line
(58821, 30360), -- Lyalia, Warn Stoneplow
(58919, 30277), -- Anji Autumnlight, The Crumbling Hall
(58919, 30280), -- Anji Autumnlight, The Thunder Below
(58920, 30266), -- Kun Autumnlight, Bloodied Skies
(58920, 30243), -- Kun Autumnlight, Mantid Under Fire
(58962, 30306), -- Hai-Me Heavyhands, The Battle Ring
(59058, 29894), -- Pearlkeeper Fujin, Spirits of the Water
(59058, 29887), -- Pearlkeeper Fujin, The Elder's Instruments
(59073, 30507), -- Mayor Bramblestaff, Admiral Taylor has Awakened
(59073, 30457), -- Mayor Bramblestaff, Call Out Their Leader
(59073, 30510), -- Mayor Bramblestaff, General Nazgrim has Awakened
(59076, 30506), -- Commander Hsieh, Admiral Taylor has Awakened
(59076, 30459), -- Commander Hsieh, All of the Arrows
(59076, 30509), -- Commander Hsieh, General Nazgrim has Awakened
(59077, 30508), -- Apothecary Cheng, Admiral Taylor has Awakened
(59077, 30511), -- Apothecary Cheng, General Nazgrim has Awakened
(59077, 30460), -- Apothecary Cheng, Hit Medicine
(59138, 30695), -- Koro Mistwalker, Ahead on the Way
(59138, 30270), -- Koro Mistwalker, Blinding the Riverblades
(59138, 30272), -- Koro Mistwalker, Striking the Rain
(59138, 30694), -- Koro Mistwalker, Tread Lightly
(59173, 29993), -- Kai Wanderbrew, Find the Boy
(59178, 29866), -- Lo Wanderbrew, The Threads that Stick
(59188, 30271), -- Anduin Wrynn, Sha Can Awe
(59189, 30271), -- Anduin Wrynn, Sha Can Awe
(59263, 30467), -- Merchant Shi, My Son...
(59263, 30469), -- Merchant Shi, Repossession
(59272, 30834), -- Wu-Peng, Father and Child Reunion
(59273, 30468), -- Swordmistress Mei, Enraged Vengeance
(59353, 30489), -- Lao Muskpaw, Fresh Needle Scent
(59353, 30804), -- Lao Muskpaw, The Fearmaster
(59353, 30488), -- Lao Muskpaw, The Missing Muskpaw
(59354, 30492), -- Muskpaw Jr., Back in Yak
(59371, 30808), -- Lucky Eightcoins, A Grummle's Luck
(59377, 30485), -- Lorewalker Cho, Last Piece of the Puzzle
(59383, 29576), -- Old Man Misteye, An Air of Worry
(59391, 30495), -- Foreman Raike, Love's Labor
(59391, 29932), -- Foreman Raike, The Temple of the Jade Serpent
(59402, 30614), -- Slimy Inkstain, Oil Stop
(59405, 31279), -- Li Goldendraft, Everything I Know About Cooking
(59411, 31303), -- Lorewalker Cho, The Seal is Broken
(59418, 30504), -- Lorewalker Cho, Emergency Response
(59418, 31319), -- Lorewalker Cho, Emergency Response
(59418, 30502), -- Lorewalker Cho, Jaded Heart
(59418, 30500), -- Lorewalker Cho, Residual Fallout
(59441, 30652), -- Admiral Taylor, In Tents Channeling
(59441, 30575), -- Admiral Taylor, Round 'Em Up
(59441, 31455), -- Admiral Taylor, The Shado-Pan
(59441, 30512), -- Admiral Taylor, Westwind Rest
(59442, 30513), -- General Nazgrim, Eastwind Rest
(59442, 30657), -- General Nazgrim, In Tents Channeling
(59442, 31256), -- General Nazgrim, Round 'Em Up
(59442, 31453), -- General Nazgrim, The Shado-Pan
(59448, 30656), -- Rivett Clutchpop, Barrels of Fun
(59448, 31251), -- Rivett Clutchpop, Best Meals Anywhere!
(59449, 31459), -- Shademaster Kiryn, Cho's Missive
(59449, 30594), -- Shademaster Kiryn, Deanimate the Reanimated
(59450, 30651), -- Sully "The Pickle" McLeary, Barrels of Fun
(59450, 30583), -- Sully "The Pickle" McLeary, Blue Dwarf Needs Food Badly
(59451, 31460), -- Mishka, Cho's Missive
(59451, 30593), -- Mishka, Deanimate the Reanimated
(59452, 30599), -- Brother Rabbitsfoot, A Monkey Idol
(59452, 30604), -- Brother Rabbitsfoot, Breaking Broketooth
(59452, 30605), -- Brother Rabbitsfoot, Bros Before Hozen
(59452, 30600), -- Brother Rabbitsfoot, No Pack Left Behind
(59452, 30612), -- Brother Rabbitsfoot, The Leader Hozen
(59452, 30611), -- Brother Rabbitsfoot, Unleash The Yeti!
(59517, 30326), -- Fish Fellreed, The Kunzen Legend-Chief
(59533, 30526), -- Lost Dog, Lost and Lonely
(59550, 30565), -- Sully "The Pickle" McLeary, An Unexpected Advantage
(59569, 30567), -- Brewmaster Blanche, Blanche's Boomer Brew
(59573, 31253), -- Farmer Chow, Back to Eastwind Rest
(59573, 31252), -- Farmer Chow, Back to Westwind Rest
(59573, 30571), -- Farmer Chow, Farmhand Freedom
(59584, 30586), -- Fisherman Haito, Jagged Abalone
(59584, 30584), -- Fisherman Haito, Shocking!
(59585, 32035), -- Lolo Lio, Got Silk?
(59586, 30588), -- Angler Shen, Fishing for a Bruising
(59586, 30700), -- Angler Shen, Snapclaw
(59594, 30319), -- Haohan Mudclaw, Pest Problems
(59597, 30617), -- Smokey Sootassle, Roadside Assistance
(59597, 30616), -- Smokey Sootassle, Traffic Issues
(59608, 30273), -- Anduin Wrynn, In the House of the Red Crane
(59608, 30271), -- Anduin Wrynn, Sha Can Awe
(59620, 31362), -- Lorewalker Cho, Last Piece of the Puzzle
(59636, 30581), -- Uyen Chow, ... and the Pot, Too!
(59695, 30618), -- Big Sal, Resupplying One Keg
(59696, 30487), -- Uncle Cloverleaf, Comin' Round the Mountain
(59696, 30601), -- Uncle Cloverleaf, Instant Courage
(59701, 30592), -- Brother Lintpocket, The Burlap Trail: To Burlap Waystation
(59703, 30692), -- Brother Trailscenter, The Burlap Trail: To Kota Basecamp
(59703, 30602), -- Brother Trailscenter, The Rabbitsfoot
(59704, 31327), -- Chen Stormstout, Trouble Brewing
(59716, 30621), -- Ji-Lu the Lucky, They Stole My Luck!
(59719, 30376), -- Chi-Ji, Hope Springs Eternal
(59806, 30603), -- Brother Rabbitsfoot, The Broketooth Ravage
(59821, 30595), -- Bao Jian, Profiting off of the Past
(59822, 31324), -- Auntie Stormstout, Family Secrets
(59855, 30623), -- Mei Barrelbottom, The Mantidote
(59856, 30627), -- Master Bruised Paw, The Savior of Stoneplow
(59894, 30610), -- Brother Yakshoe, Grummle! Grummle! Grummle!
(59894, 30607), -- Brother Yakshoe, Hozen Love Their Keys
(59894, 30608), -- Brother Yakshoe, The Snackrifice
(59894, 30606), -- Brother Yakshoe, Thumping Knucklethump
(59899, 30648), -- Fei, Moving On
(60135, 30613), -- Trawler Yotimo, Armored Carp
(60135, 30658), -- Trawler Yotimo, Huff &amp; Puff
(60136, 30678), -- Fiznix, Like Bombing Fish In A Barrel
(60136, 30698), -- Fiznix, Scavenger Hunt
(60139, 30672), -- Wise Ana Wu, Balance
(60139, 30691), -- Wise Ana Wu, Misery
(60139, 30671), -- Wise Ana Wu, Wisdom Has A Price
(60161, 30665), -- Shado-Master Chong, The Defense of Shado-Pan Fallback
(60161, 30699), -- Shado-Master Chong, To Winter's Blossom
(60161, 30670), -- Shado-Master Chong, Turnabout
(60161, 30690), -- Shado-Master Chong, Unmasking the Yaungol
(60173, 30668), -- Jay Cloudfall, Build Your Own Raft
(60173, 30666), -- Jay Cloudfall, Sudden, Unexpected Crocolisk Aggression
(60173, 30669), -- Jay Cloudfall, The Lorewalker on the Lake
(60175, 30683), -- Lucky Bluestring, One Traveler's Misfortune
(60175, 30684), -- Lucky Bluestring, Seeker's Folly
(60178, 30682), -- Sya Zhong, Holed Up
(60180, 31306), -- Lucky Bluestring, Seeker's Folly
(60182, 30667), -- Tony Tuna, Particular Plumage
(60436, 30820), -- Li Hai, A Funeral
(60436, 30816), -- Li Hai, Checking In
(60503, 30746), -- Uncle Keenbean, A Fair Trade
(60503, 30744), -- Uncle Keenbean, Kota Blend
(60503, 30745), -- Uncle Keenbean, Trouble Brewing
(60506, 30740), -- Thelonius, Champion of Chi-Ji
(60506, 30730), -- Thelonius, Dextrous Izissha
(60506, 30725), -- Thelonius, Ellia Ravenmane
(60506, 30739), -- Thelonius, Ellia Ravenmane: Redemption
(60506, 30727), -- Thelonius, Ellia Ravenmane: Rematch
(60506, 30732), -- Thelonius, Ellia Ravenmane: Revenge
(60506, 30728), -- Thelonius, Fat Long-Fat
(60506, 30737), -- Thelonius, Fat Long-Fat: Rematch
(60506, 30734), -- Thelonius, Huck Wheelbarrow
(60506, 30729), -- Thelonius, Julia Bates
(60506, 30731), -- Thelonius, Kuo-Na Quillpaw
(60506, 30735), -- Thelonius, Mindel Sunspeaker
(60506, 30726), -- Thelonius, Minh Do-Tan
(60506, 30718), -- Thelonius, Students of Chi-Ji
(60506, 30738), -- Thelonius, Thelonius
(60506, 30733), -- Thelonius, Tukka-Tuk
(60506, 30736), -- Thelonius, Yan Quillpaw
(60528, 30716), -- Kuo-Na Quillpaw, Chasing Hope
(60529, 30717), -- Yan Quillpaw, Gifts of the Great Crane
(60566, 30987), -- Aysa Cloudsinger, Joining the Alliance
(60570, 31012), -- Ji Firepaw, Joining the Horde
(60578, 31355), -- Priestess Summerpetal, Restoring Jade's Purity
(60596, 30743), -- Cousin Gootfur, Gourmet Kafa
(60596, 30742), -- Cousin Gootfur, Shut it Down
(60622, 30791), -- Orbiss, Arconiss Thirsts
(60622, 30790), -- Orbiss, Golgoss Hungers
(60622, 30793), -- Orbiss, Mists' Opportunity
(60622, 30792), -- Orbiss, Orbiss Fades
(60673, 30585), -- Elder Fisherman Rassan, What Lurks Below
(60673, 30598), -- Elder Fisherman Rassan, Who Knew Fish Liked Eggs?
(60674, 30754), -- John "Big Hook" Marsock, Bright Bait
(60674, 30753), -- John "Big Hook" Marsock, Jumping the Shark
(60675, 30763), -- Fo Fook, Piranha!
(60675, 30701), -- Fo Fook, Viseclaw Soup
(60677, 30825), -- Uncle Tallmug, Kota Blend
(60677, 30826), -- Uncle Tallmug, Trouble Brewing
(60678, 30824), -- Cousin Littlebrew, Gourmet Kafa
(60678, 30823), -- Cousin Littlebrew, Shut it Down
(60679, 30747), -- Nephew Burrberry, The Burlap Grind
(60679, 30821), -- Nephew Burrberry, The Burlap Grind
(60684, 30776), -- Suna Silentstrike, Jung Duk
(60684, 30774), -- Suna Silentstrike, Ranger Rescue
(60684, 30772), -- Suna Silentstrike, Seeing Red
(60687, 30777), -- Ban Bearheart, In Search of Suna
(60687, 30773), -- Ban Bearheart, Pitching In
(60688, 30814), -- Taran Zhu, A Foot in the Door
(60688, 30769), -- Taran Zhu, First Assault
(60688, 30771), -- Taran Zhu, Perfect Pitch
(60688, 30770), -- Taran Zhu, Running Rampant
(60694, 30794), -- Sage Liao, Emergency Care
(60735, 30775), -- Katak the Defeated, The Exile
(60785, 30807), -- Sage Liao, By the Falls, For the Fallen
(60785, 30805), -- Sage Liao, Justice
(60785, 30819), -- Sage Liao, Preparing the Remains
(60785, 30806), -- Sage Liao, The Scent of Life
(60795, 30795), -- Lorewalker Cho, Staying Connected
(60795, 30829), -- Lorewalker Cho, The Tongue of Ba-Shon
(60857, 30786), -- Orbiss, A Spear Through My Side, A Chain Through My Soul
(60857, 30789), -- Orbiss, Arconiss
(60857, 30788), -- Orbiss, Golgoss
(60857, 30815), -- Orbiss, The Death of Me
(60857, 30787), -- Orbiss, The Torches
(60864, 31894), -- Yalia Sagewhisper, A Delicate Balance
(60864, 30783), -- Yalia Sagewhisper, Hatred Becomes Us
(60864, 30780), -- Yalia Sagewhisper, Totemic Research
(60864, 30827), -- Yalia Sagewhisper, What Lies Beneath
(60903, 30781), -- Xiao Tu, Last Toll of the Yaungol
(60968, 31517), -- Xuen, Contending With Bullies
(60968, 30879), -- Xuen, Round 1: Brewmaster Chani
(60968, 30880), -- Xuen, Round 1: The Streetfighter
(60968, 30881), -- Xuen, Round 2: Clever Ashyo &amp; Ken-Ken
(60968, 30882), -- Xuen, Round 2: Kang Bramblestaff
(60968, 30885), -- Xuen, Round 3: Master Boom Boom
(60968, 30883), -- Xuen, Round 3: The Wrestler
(60968, 30902), -- Xuen, Round 4: Master Windfur
(60968, 30907), -- Xuen, Round 4: The P.U.G.
(60970, 29903), -- Admiral Taylor, A Perfect Match
(60970, 29904), -- Admiral Taylor, Bigger Fish to Fry
(60970, 29906), -- Admiral Taylor, Carp Diem
(60970, 29905), -- Admiral Taylor, Let Them Burn
(60973, 30828), -- Waterspeaker Gorai, Cleansing the Mere
(60973, 30967), -- Waterspeaker Gorai, Free the Dissenters
(60973, 30480), -- Waterspeaker Gorai, The Ritual
(60973, 30496), -- Waterspeaker Gorai, The Waterspeaker's Staff
(60981, 31492), -- Lin Tenderpaw, The Torch of Strength
(61016, 30975), -- Lao-Chin the Iron Belly, The Taking of Dusklight Bridge
(61020, 30979), -- Hawkmaster Nurong, Devastation Below
(61020, 30978), -- Hawkmaster Nurong, Hostile Skies
(61021, 30900), -- Taoshi, Terror of the Dread Wastes
(61026, 30117), -- Emmi, Stoneplow Thirsts
(61065, 30855), -- Waterspeaker Gorai, The Fall of Shai Hu
(61066, 30901), -- Taran Zhu, Along the Southern Front
(61066, 30884), -- Taran Zhu, Behind the Battlefront
(61066, 30898), -- Taran Zhu, Cutting the Swarm
(61066, 30895), -- Taran Zhu, Improvised Ammunition
(61066, 30893), -- Taran Zhu, The Endless Swarm
(61161, 30929), -- Bluesaddle, Bad Yak
(61161, 30930), -- Bluesaddle, Pick a Yak
(61218, 29892), -- Lorewalker Cho, Body
(61218, 29893), -- Lorewalker Cho, Hue
(61218, 29891), -- Lorewalker Cho, Potency
(61261, 30778), -- Ban Bearheart, Dust to Dust
(61261, 30785), -- Ban Bearheart, Gao-Ran Battlefront
(61261, 30779), -- Ban Bearheart, Slaying the Scavengers
(61261, 30782), -- Ban Bearheart, Spiteful Spirits
(61261, 30784), -- Ban Bearheart, The Point of No Return
(61297, 30796), -- Image of Lorewalker Cho, An End to Everything
(61297, 30798), -- Image of Lorewalker Cho, Breaking the Emperor's Shield
(61297, 30802), -- Image of Lorewalker Cho, Chasing the Storm
(61297, 30935), -- Image of Lorewalker Cho, Fisherman's Tale
(61297, 30801), -- Image of Lorewalker Cho, Lessons from History
(61297, 30800), -- Image of Lorewalker Cho, Stealing Their Thunder King
(61297, 30799), -- Image of Lorewalker Cho, The Tomb of Shadows
(61371, 31011), -- Lorewalker Cho, Enemies At Our Door
(61371, 30944), -- Lorewalker Cho, It Takes A Village
(61454, 30994), -- Suna Silentstrike, Lao-Chin's Gambit
(61454, 30768), -- Suna Silentstrike, My Husband...
(61454, 30750), -- Suna Silentstrike, Off the Wall!
(61467, 30889), -- Mao the Lookout, Trap Setting
(61468, 30888), -- Taoshi, Breach in the Defenses
(61468, 30960), -- Taoshi, Returning from the Pass
(61468, 30890), -- Taoshi, The Restless Watch
(61469, 30887), -- Taoshi, Unwelcome Intruders
(61470, 30892), -- Septi the Herbalist, Back on Their Feet
(61470, 30894), -- Septi the Herbalist, Rummaging Through the Remains
(61470, 30891), -- Septi the Herbalist, Treatment for the Troops
(61482, 30923), -- Tai Ho, Set the Mantid Back
(61482, 30921), -- Tai Ho, The Motives of the Mantid
(61482, 30924), -- Tai Ho, The Wisdom of Niuzao
(61495, 30943), -- Elder Shu, Handle With Care
(61496, 30945), -- Steelbender Doshu, What's Yours Is Mine
(61503, 30942), -- Shomi, Make A Fighter Out of Me
(61512, 31847), -- Kite Master Len, Better Dead than Dread
(61539, 30931), -- Ku-Mo, My Father's Crossbow
(61580, 30956), -- Ogo the Elder, The Siege Swells
(61580, 30926), -- Ogo the Elder, The Terrible Truth
(61580, 30952), -- Ogo the Elder, The Unending Siege
(61581, 30954), -- Ogo the Younger, A Blade is a Blade
(61581, 30925), -- Ogo the Younger, Niuzao's Price
(61581, 30959), -- Ogo the Younger, The Big Guns
(61583, 30958), -- High Adept Paosha, In Battle's Shadow
(61583, 30955), -- High Adept Paosha, Paying Tribute
(61584, 31895), -- Sentinel Commander Qipan, Better Off Dread
(61584, 30932), -- Sentinel Commander Qipan, Father's Footsteps
(61584, 30927), -- Sentinel Commander Qipan, Give Them Peace
(61584, 30957), -- Sentinel Commander Qipan, The Overwhelming Swarm
(61585, 30928), -- Yak-Keeper Kyana, A Trail of Fear
(61585, 30953), -- Yak-Keeper Kyana, Fallen Sentinels
(61625, 30964), -- Provisioner Bamfu, A Proper Poultice
(61625, 30922), -- Provisioner Bamfu, Natural Antiseptic
(61625, 30963), -- Provisioner Bamfu, The Field Armorer
(61693, 30491), -- Muskpaw Jr., At the Yak Wash
(61716, 30969), -- Invoker Xorenth, A New Enemy
(61716, 30983), -- Invoker Xorenth, The Dark Shaman
(61724, 30982), -- Commander Bagran, Animal Control
(61724, 30984), -- Commander Bagran, No Orc Left Behind
(61796, 30989), -- King Varian Wrynn, An Old Pit Fighter
(61816, 30723), -- Lin Silentstrike, Honor, Even in Death
(61816, 30724), -- Lin Silentstrike, To the Wall!
(61819, 30715), -- Ban Bearheart, A Line Unbroken
(61819, 31031), -- Ban Bearheart, Into the Monastery
(61819, 30752), -- Ban Bearheart, Unbelievable!
(61819, 30993), -- Ban Bearheart, Where are My Reinforcements?
(61820, 30751), -- Lao-Chin the Iron Belly, A Terrible Sacrifice
(61820, 30991), -- Lao-Chin the Iron Belly, Do a Barrel Roll!
(61820, 30992), -- Lao-Chin the Iron Belly, Finish This!
(61822, 30997), -- SI:7 Field Commander Dirken, Animal Control
(61822, 30995), -- SI:7 Field Commander Dirken, No Man Left Behind
(61823, 30998), -- High Sorceress Aryna, A New Enemy
(61823, 30996), -- High Sorceress Aryna, The Dark Shaman
(61847, 30999), -- Lorewalker Cho, Path Less Traveled
(61880, 30897), -- Initiate Chao, In the Wrong Hands
(61881, 30896), -- Initiate Feng, Thieves and Troublemakers
(61962, 32806), -- Lorewalker Cho, The King and the Council
(61962, 32807), -- Lorewalker Cho, The Warchief and the Darkness
(61962, 31015), -- Lorewalker Cho, Your Private Collection
(62092, 31014), -- Garrosh Hellscream, Hellscream's Gift
(62112, 31001), -- Bowmistress Li, Falling Down
(62112, 31002), -- Bowmistress Li, Nope
(62124, 30972), -- Initiate Pao-Me, Joining the Fight
(62124, 30971), -- Initiate Pao-Me, Taking Stock
(62151, 31210), -- Xaril the Poisoned Mind, A Shade of Dread
(62151, 31216), -- Xaril the Poisoned Mind, Dark Skies
(62151, 31209), -- Xaril the Poisoned Mind, Dark Wings, Dark Things
(62151, 31211), -- Xaril the Poisoned Mind, The Poisoned Mind
(62151, 31208), -- Xaril the Poisoned Mind, Venomous Intent
(62166, 31003), -- Marksman Lann, Psycho Mantid
(62180, 31232), -- Korven the Prime, An Ancient Empire
(62180, 31507), -- Korven the Prime, Meltdown
(62180, 31496), -- Korven the Prime, Sampling the Empire's Finest
(62180, 31233), -- Korven the Prime, Sap Tapping
(62180, 31270), -- Korven the Prime, The Fight Against Fear
(62180, 31269), -- Korven the Prime, The Scale-Lord
(62202, 31676), -- Kil'ruk the Wind-Reaver, Ancient Vengeance
(62202, 31006), -- Kil'ruk the Wind-Reaver, The Klaxxi Council
(62202, 31005), -- Kil'ruk the Wind-Reaver, Wakening Sickness
(62203, 31004), -- Klaxxi'va Tik, Preserved in Amber
(62227, 31030), -- Ban Bearheart, Into the Monastery
(62232, 31020), -- Klaxxi Warrior, Feeding the Beast
(62232, 31022), -- Klaxxi Warrior, Kypari Zar
(62232, 31021), -- Klaxxi Warrior, Living Amber
(62232, 31026), -- Klaxxi Warrior, The Root of the Problem
(62236, 30757), -- Ban Bearheart, Lord of the Shado-Pan
(62273, 30973), -- Taran Zhu, Up In Flames
(62274, 31065), -- Taran Zhu, Buried Beneath
(62274, 30899), -- Taran Zhu, In Skilled Hands
(62274, 31063), -- Taran Zhu, Lao-Chin and Serevex
(62274, 31064), -- Taran Zhu, Nurong and Rothek
(62274, 30981), -- Taran Zhu, Taoshi and Korvexxis
(62275, 30968), -- Taran Zhu, The Sha of Hatred
(62278, 30977), -- Rensai Oakhide, Grounded Welcome
(62278, 31688), -- Rensai Oakhide, The Search for Restless Leng
(62278, 31687), -- Rensai Oakhide, Thinning the Sik'thik
(62295, 31049), -- Omnia Mage, In Sprite Of Everything
(62295, 31061), -- Omnia Mage, Riding the Storm
(62295, 31062), -- Omnia Mage, When The Dead Speak
(62304, 31047), -- Ban Bearheart, Born Free
(62304, 31044), -- Ban Bearheart, Bronze Claws
(62304, 31043), -- Ban Bearheart, Dark Arts
(62304, 31041), -- Ban Bearheart, Egg Rescue!
(62304, 31048), -- Ban Bearheart, Grave Consequences
(62304, 31045), -- Ban Bearheart, Illusions Of The Past
(62304, 31049), -- Ban Bearheart, In Sprite Of Everything
(62304, 31046), -- Ban Bearheart, Little Hatchlings
(62304, 31042), -- Ban Bearheart, Onyx Hearts
(62304, 31061), -- Ban Bearheart, Riding the Storm
(62304, 31040), -- Ban Bearheart, Spiteful Sprites
(62304, 31038), -- Ban Bearheart, The Challenger's Ring: Snow Blossom
(62304, 31104), -- Ban Bearheart, The Challenger's Ring: Yalia Sagewhisper
(62304, 31039), -- Ban Bearheart, The Mogu Menace
(62304, 31105), -- Ban Bearheart, The Mogu Menace
(62304, 31106), -- Ban Bearheart, The Mogu Menace
(62304, 31062), -- Ban Bearheart, When The Dead Speak
(62321, 31613), -- Brewmaster Tzu, Volatile Greenstone Brew
(62322, 31279), -- Graceful Swan, Everything I Know About Cooking
(62377, 30050), -- Gardener Fran, Gardener Fran and the Watering Can
(62378, 31049), -- Omnia Priest, In Sprite Of Everything
(62378, 31061), -- Omnia Priest, Riding the Storm
(62378, 31062), -- Omnia Priest, When The Dead Speak
(62379, 31049), -- Omnia Mage, In Sprite Of Everything
(62379, 31061), -- Omnia Mage, Riding the Storm
(62379, 31062), -- Omnia Mage, When The Dead Speak
(62385, 30056), -- Den Mudclaw, The Farmer's Daughter
(62436, 30970), -- Taoshi, Enraged By Hatred
(62444, 30900), -- Taoshi, Terror of the Dread Wastes
(62538, 31730), -- Kil'ruk the Wind-Reaver, A Not So Friendly Request
(62538, 31019), -- Kil'ruk the Wind-Reaver, Amber Is Life
(62538, 31018), -- Kil'ruk the Wind-Reaver, Beneath the Heart of Fear
(62538, 31109), -- Kil'ruk the Wind-Reaver, Culling the Swarm
(62538, 31231), -- Kil'ruk the Wind-Reaver, Dreadspinner Extermination
(62538, 31111), -- Kil'ruk the Wind-Reaver, Eradicating the Zan'thik
(62538, 31267), -- Kil'ruk the Wind-Reaver, Mistblade Destruction
(62538, 31235), -- Kil'ruk the Wind-Reaver, Nope Nope Nope
(62538, 31660), -- Kil'ruk the Wind-Reaver, Not Fit to Swarm
(62538, 31612), -- Kil'ruk the Wind-Reaver, Shadow of the Empire
(62538, 31175), -- Kil'ruk the Wind-Reaver, Skeer the Bloodseeker
(62538, 31007), -- Kil'ruk the Wind-Reaver, The Dread Clutches
(62538, 31505), -- Kil'ruk the Wind-Reaver, Vess-Guard Duty
(62573, 31032), -- Marksman Ye, Choking the Skies
(62666, 31086), -- Sapmaster Vu, Blood of Ancients
(62666, 31069), -- Sapmaster Vu, Bound With Shade
(62666, 31073), -- Sapmaster Vu, Bound With Wood
(62666, 31075), -- Sapmaster Vu, Sunset Kings
(62666, 31067), -- Sapmaster Vu, The Heavens Hum With War
(62667, 31000), -- Lya of Ten Songs, Dread Space
(62667, 31085), -- Lya of Ten Songs, Fires and Fears of Old
(62667, 31081), -- Lya of Ten Songs, Incantations Fae and Primal
(62667, 32030), -- Lya of Ten Songs, Once in a Hundred Lifetimes
(62667, 31072), -- Lya of Ten Songs, Rending Daggers
(62667, 31074), -- Lya of Ten Songs, Wood and Shade
(62668, 31070), -- Olon, Daggers of the Great Ones
(62668, 31080), -- Olon, Fiery Wings
(62736, 30976), -- Taran Zhu, Joining the Hunt
(62771, 31084), -- Chief Rikkitun, Bind the Glamour
(62771, 31082), -- Chief Rikkitun, Great Vessel of Salvation
(62772, 31079), -- Boggeo, The Horror Comes A-Rising
(62774, 31107), -- Malik the Unscathed, Citizens of a New Empire
(62774, 31689), -- Malik the Unscathed, The Dreadsworn
(62774, 31959), -- Malik the Unscathed, The Empress' Gambit
(62779, 31076), -- Chen Stormstout, Fate of the Stormstouts
(62779, 31129), -- Chen Stormstout, Fate of the Stormstouts
(62786, 30980), -- Hawkmaster Nurong, Heroes of the Shado-Pan
(62802, 31656), -- Taoshi, The Threat in the South
(62810, 31110), -- Moshu the Arcane, Through the Portal
(62859, 31071), -- Thirsty Missho, I Bring Us Great Shame
(62872, 31486), -- Cranfur the Noodler, Everything I Know About Cooking
(62923, 31112), -- Empty Package, They're So Thorny!
(63009, 31114), -- Master Snowdrift, Assault Deadtalker's Plateau
(63009, 31113), -- Master Snowdrift, Assault Fire Camp Gai-Cho
(63009, 31120), -- Master Snowdrift, Cheng Bo!
(63009, 31266), -- Master Snowdrift, Mogu Incursions
(63009, 31116), -- Master Snowdrift, Spirit Dust
(63009, 31277), -- Master Snowdrift, Surprise Attack!
(63009, 31127), -- Master Snowdrift, The Challenger's Ring: Chao the Voice
(63009, 31128), -- Master Snowdrift, The Challenger's Ring: Lao-Chin the Iron Belly
(63009, 31118), -- Master Snowdrift, The Deadtalker Cipher
(63009, 31119), -- Master Snowdrift, The Enemy of My Enemy... Is Still My Enemy!
(63009, 31117), -- Master Snowdrift, Uruk!
(63013, 31486), -- Sway Dish Chef, Everything I Know About Cooking
(63014, 31550), -- Marcus Jensen, Got one!
(63014, 31308), -- Marcus Jensen, Learning the Ropes
(63014, 31785), -- Marcus Jensen, Level Up!
(63014, 31309), -- Marcus Jensen, On The Mend
(63061, 31570), -- Narzak, Got one!
(63061, 31571), -- Narzak, Learning the Ropes
(63061, 31830), -- Narzak, Level Up!
(63070, 31555), -- Valeena, Got one!
(63071, 31178), -- Skeer the Bloodseeker, A Bloody Delight
(63071, 31176), -- Skeer the Bloodseeker, A Strange Appetite
(63071, 31177), -- Skeer the Bloodseeker, Fine Dining
(63071, 31179), -- Skeer the Bloodseeker, The Scent of Blood
(63072, 31271), -- Rik'kal the Dissector, Bad Genes
(63072, 31509), -- Rik'kal the Dissector, Fear Takes Root
(63072, 31234), -- Rik'kal the Dissector, Putting An Eye Out
(63072, 31503), -- Rik'kal the Dissector, Shortcut to Ruin
(63072, 31508), -- Rik'kal the Dissector, Specimen Request
(63072, 31502), -- Rik'kal the Dissector, Wing Clip
(63073, 31823), -- Ansel Fincap, Level Up!
(63075, 31822), -- Grady Bannson, Level Up!
(63077, 31825), -- Lehna, Level Up!
(63080, 31579), -- Jarson Everlong, Learning the Ropes
(63083, 31584), -- Will Larsons, Got one!
(63083, 31832), -- Will Larsons, Level Up!
(63086, 31585), -- Matty, Learning the Ropes
(63086, 31828), -- Matty, Level Up!
(63194, 31728), -- Steven Lisbane, Bill Buckler
(63194, 31852), -- Steven Lisbane, Steven Lisbane
(63217, 31134), -- Lorewalker Cho, If These Stones Could Speak
(63217, 31152), -- Lorewalker Cho, Peering Into the Past
(63218, 31133), -- Defender Azzo, Kor'thik Aggression
(63238, 31138), -- Xi, Friend to the Small, The Arts of a Monk
(63258, 31143), -- Bao, Join the Battle!
(63258, 31142), -- Bao, Palm of the Tiger
(63272, 31147), -- Ting, Strong of Stomach, Tiger Palm
(63285, 31151), -- Lo, Kick, Punch, It's All in the Mind
(63296, 31157), -- Gato, Tiger Palm
(63307, 31167), -- Lorewalker Cho, Family Tree
(63307, 29879), -- Lorewalker Cho, Swallowed Whole
(63310, 31160), -- Zabrax, A Rough Start
(63310, 31163), -- Zabrax, More Than Expected
(63310, 31161), -- Zabrax, Proving Pit
(63310, 31158), -- Zabrax, The Basics: Hitting Things
(63315, 31207), -- Gurgthock, The Arena of Annihilation
(63317, 31184), -- Captain "Soggy" Su-Dao, Old Age and Treachery
(63317, 31190), -- Captain "Soggy" Su-Dao, The Mariner's Revenge
(63317, 31185), -- Captain "Soggy" Su-Dao, Walking Dog
(63327, 31166), -- Shoyu, Tiger Palm
(63328, 31020), -- Klaxxi Warrior, Feeding the Beast
(63328, 31022), -- Klaxxi Warrior, Kypari Zar
(63328, 31021), -- Klaxxi Warrior, Living Amber
(63328, 31026), -- Klaxxi Warrior, The Root of the Problem
(63331, 31169), -- Laoxi, The Art of the Monk
(63332, 31171), -- Pao, Tiger Palm
(63335, 31173), -- Mojo Stormstout, The Tiger Palm
(63349, 31181), -- Deck Boss Arie, Fresh Pots
(63349, 31354), -- Deck Boss Arie, Mazu's Bounty
(63349, 31265), -- Deck Boss Arie, Mazu's Breath
(63349, 31183), -- Deck Boss Arie, Meet the Cap'n
(63349, 31187), -- Deck Boss Arie, On the Crab
(63349, 31189), -- Deck Boss Arie, Reeltime Strategy
(63349, 31188), -- Deck Boss Arie, Shark Week
(63349, 31182), -- Deck Boss Arie, You Otter Know
(63367, 31611), -- Brewmaster Boof, The Kun-Lai Kicker
(63367, 31285), -- Brewmaster Boof, The Spring Drifter
(63484, 31287), -- Len the Whisperer, Educating Saurok
(63484, 31286), -- Len the Whisperer, Robbing Robbers of Robbers
(63498, 31886), -- Min the Breeze Rider, Dread Space
(63535, 31695), -- Elder Shiao, Beyond the Wall
(63535, 30515), -- Elder Shiao, Challenge Accepted
(63535, 30620), -- Elder Shiao, Mogu?! Oh No-gu!
(63535, 30655), -- Elder Shiao, Pandaren Prisoners
(63535, 31451), -- Elder Shiao, The Missing Merchant
(63542, 31695), -- Elder Tsulan, Beyond the Wall
(63542, 30514), -- Elder Tsulan, Challenge Accepted
(63542, 30619), -- Elder Tsulan, Mogu?! Oh No-gu!
(63542, 30650), -- Elder Tsulan, Pandaren Prisoners
(63542, 31452), -- Elder Tsulan, The Missing Merchant
(63596, 32008), -- Audrey Burnhep, Audrey Burnhep
(63596, 31966), -- Audrey Burnhep, Battle Pet Tamers: Cataclysm
(63596, 31902), -- Audrey Burnhep, Battle Pet Tamers: Eastern Kingdoms
(63596, 31889), -- Audrey Burnhep, Battle Pet Tamers: Kalimdor
(63596, 31927), -- Audrey Burnhep, Battle Pet Tamers: Northrend
(63596, 31919), -- Audrey Burnhep, Battle Pet Tamers: Outland
(63596, 31930), -- Audrey Burnhep, Battle Pet Tamers: Pandaria
(63596, 31593), -- Audrey Burnhep, Got one!
(63596, 31316), -- Audrey Burnhep, Julia, The Pet Tamer
(63596, 31591), -- Audrey Burnhep, Learning the Ropes
(63596, 31821), -- Audrey Burnhep, Level Up!
(63596, 31592), -- Audrey Burnhep, On The Mend
(63596, 32863), -- Audrey Burnhep, What We've Been Training For
(63614, 31198), -- Ling of the Six Pools, A Morale Victory
(63614, 31199), -- Ling of the Six Pools, Destroy the Siege Weapons!
(63614, 31201), -- Ling of the Six Pools, Friends, Not Food!
(63614, 31200), -- Ling of the Six Pools, Fumigation
(63614, 31196), -- Ling of the Six Pools, Sra'vess Wetwork
(63614, 31204), -- Ling of the Six Pools, Target of Opportunity: Sra'thik Hivelord
(63614, 31203), -- Ling of the Six Pools, Target of Opportunity: Sra'thik Swarmlord
(63614, 31197), -- Ling of the Six Pools, The Bigger They Come...
(63614, 31220), -- Ling of the Six Pools, The Challenger's Ring: Hawkmaster Nurong
(63614, 31221), -- Ling of the Six Pools, The Challenger's Ring: Tenwu of the Red Smoke
(63622, 31204), -- Wu Kao Rogue, Target of Opportunity: Sra'thik Hivelord
(63622, 31203), -- Wu Kao Rogue, Target of Opportunity: Sra'thik Swarmlord
(63623, 31204), -- Wu Kao Assassin, Target of Opportunity: Sra'thik Hivelord
(63623, 31203), -- Wu Kao Assassin, Target of Opportunity: Sra'thik Swarmlord
(63624, 31204), -- Wu Kao Hawkmaster, Target of Opportunity: Sra'thik Hivelord
(63624, 31203), -- Wu Kao Hawkmaster, Target of Opportunity: Sra'thik Swarmlord
(63626, 31967), -- Varzok, Battle Pet Tamers: Cataclysm
(63626, 31903), -- Varzok, Battle Pet Tamers: Eastern Kingdoms
(63626, 31891), -- Varzok, Battle Pet Tamers: Kalimdor
(63626, 31929), -- Varzok, Battle Pet Tamers: Northrend
(63626, 31921), -- Varzok, Battle Pet Tamers: Outland
(63626, 31952), -- Varzok, Battle Pet Tamers: Pandaria
(63626, 31590), -- Varzok, Got one!
(63626, 31588), -- Varzok, Learning the Ropes
(63626, 31827), -- Varzok, Level Up!
(63626, 31589), -- Varzok, On The Mend
(63626, 32009), -- Varzok, Varzok
(63626, 32863), -- Varzok, What We've Been Training For
(63626, 31812), -- Varzok, Zunta, The Pet Tamer
(63721, 36609), -- Nat Pagle, The Great Angler Returns
(63721, 36882), -- Nat Pagle, The Great Angler Returns
(63748, 31241), -- Jeek Jeek, Wicked Wikkets
(63750, 30946), -- Lorewalker Cho, Revelations
(63751, 31457), -- Farmhand Ko, Muskpaw Ranch
(63751, 31393), -- Farmhand Ko, Temple of the White Tiger
(63751, 30570), -- Farmhand Ko, Trouble on the Farmstead
(63754, 31456), -- Farmhand Bo, Muskpaw Ranch
(63754, 31392), -- Farmhand Bo, Temple of the White Tiger
(63754, 30569), -- Farmhand Bo, Trouble on the Farmstead
(63758, 31268), -- Kaz'tik the Manipulator, A Little Brain Work
(63758, 31238), -- Kaz'tik the Manipulator, Brain Food
(63758, 31494), -- Kaz'tik the Manipulator, Free From Her Clutches
(63758, 31024), -- Kaz'tik the Manipulator, Kunchong Treats
(63758, 31808), -- Kaz'tik the Manipulator, Rampage Against the Machine
(63758, 31506), -- Kaz'tik the Manipulator, Shackles of Manipulation
(63758, 31487), -- Kaz'tik the Manipulator, Sonic Disruption
(63778, 31254), -- Messenger Grummle, The Road to Kun-Lai
(63778, 31255), -- Messenger Grummle, The Road to Kun-Lai
(63784, 31228), -- Lorewalker Cho, Prophet Khar'zul
(63784, 30946), -- Lorewalker Cho, Revelations
(63785, 31237), -- Hisek the Swarmkeeper, Debugging the Terrace
(63785, 31272), -- Hisek the Swarmkeeper, Infection
(63785, 31504), -- Hisek the Swarmkeeper, Ordnance Disposal
(63785, 31510), -- Hisek the Swarmkeeper, Quiet Now
(63822, 30182), -- Tani, Fox Mastery
(63822, 30183), -- Tani, Stalker Mastery
(63876, 31091), -- Kaz'tik the Manipulator, Reunited
(63955, 31186), -- Dog, Dog Food
(63983, 31291), -- Ms. Thai, Uncovering the Past
(63984, 31288), -- Master Liu, Research Project: The Mogu Dynasties
(63994, 31528), -- Challenger Wuli, A Worthy Challenge: Darkmaster Gandling
(63994, 31526), -- Challenger Wuli, A Worthy Challenge: Durand
(63994, 31527), -- Challenger Wuli, A Worthy Challenge: Flameweaver Koegler
(63994, 31524), -- Challenger Wuli, A Worthy Challenge: Raigonn
(63994, 31520), -- Challenger Wuli, A Worthy Challenge: Sha of Doubt
(63994, 31522), -- Challenger Wuli, A Worthy Challenge: Sha of Hatred
(63994, 31525), -- Challenger Wuli, A Worthy Challenge: Wing Leader Ner'onok
(63994, 31523), -- Challenger Wuli, A Worthy Challenge: Xin the Weaponmaster
(63994, 31519), -- Challenger Wuli, A Worthy Challenge: Yan-zhu the Uncasked
(63996, 33133), -- Elder Liao, Warforged Seals
(64001, 31377), -- Sage Lotusbloom, Attack At The Temple of the Jade Serpent
(64001, 31379), -- Sage Lotusbloom, Challenge At The Temple of the Red Crane
(64001, 31383), -- Sage Lotusbloom, Defense At Niuzao Temple
(64001, 31381), -- Sage Lotusbloom, Trial At The Temple of the White Tiger
(64002, 31388), -- Sang-Bo, The Shado-Pan Offensive
(64002, 31389), -- Sang-Bo, Understanding The Shado-Pan
(64007, 31385), -- Weng the Merciful, The Golden Lotus
(64010, 31370), -- Master Angler Karu, The Anglers
(64011, 31374), -- Farmhand Dooka, The Tillers
(64028, 32007), -- Challenger Soong, A Worthy Challenge: Darkmaster Gandling
(64028, 32005), -- Challenger Soong, A Worthy Challenge: Durand
(64028, 32006), -- Challenger Soong, A Worthy Challenge: Flameweaver Koegler
(64028, 32003), -- Challenger Soong, A Worthy Challenge: Raigonn
(64028, 31998), -- Challenger Soong, A Worthy Challenge: Sha of Doubt
(64028, 32001), -- Challenger Soong, A Worthy Challenge: Sha of Hatred
(64028, 32004), -- Challenger Soong, A Worthy Challenge: Wing Leader Ner'onok
(64028, 32002), -- Challenger Soong, A Worthy Challenge: Xin the Weaponmaster
(64028, 32000), -- Challenger Soong, A Worthy Challenge: Yan-zhu the Uncasked
(64029, 33134), -- Elder Lin, Warforged Seals
(64030, 31386), -- Lao Lang, The Shado-Pan Offensive
(64030, 31387), -- Lao Lang, Understanding The Shado-Pan
(64031, 31384), -- Xari the Kind, The Golden Lotus
(64032, 31376), -- Sage Whiteheart, Attack At The Temple of the Jade Serpent
(64032, 31378), -- Sage Whiteheart, Challenge At The Temple of the Red Crane
(64032, 31382), -- Sage Whiteheart, Defense At Niuzao Temple
(64032, 31380), -- Sage Whiteheart, Trial At The Temple of the White Tiger
(64033, 31369), -- Master Angler Marina, The Anglers
(64036, 31372), -- Tang Ironhoe, The Tillers
(64041, 31279), -- Mifan, Everything I Know About Cooking
(64058, 32726), -- Jorunga Stonehoof, So You Want to Be a Blacksmith...
(64085, 32683), -- Cullen Hammerbrow, So You Want to Be a Blacksmith...
(64101, 32900), -- Taijing the Cyclone, Heroic Deeds
(64101, 33248), -- Taijing the Cyclone, Proving Grounds
(64231, 33022), -- Sungshin Ironpaw, Catch and Carry
(64231, 33024), -- Sungshin Ironpaw, Is That A Real Measurement?
(64231, 33146), -- Sungshin Ironpaw, Noodle Time
(64231, 33358), -- Sungshin Ironpaw, Noodle Time: Bonus
(64231, 31302), -- Sungshin Ironpaw, Ready for Greatness
(64231, 31281), -- Sungshin Ironpaw, So You Want to Be a Chef...
(64231, 33027), -- Sungshin Ironpaw, The Secret Ingredient Is...
(64231, 33026), -- Sungshin Ironpaw, These Aren't Your Fatty Goatsteaks
(64231, 31521), -- Sungshin Ironpaw, To Be a Master
(64231, 31479), -- Sungshin Ironpaw, Way of the Brew
(64231, 31311), -- Sungshin Ironpaw, Way of the Grill
(64231, 31478), -- Sungshin Ironpaw, Way of the Oven
(64231, 31472), -- Sungshin Ironpaw, Way of the Pot
(64231, 31475), -- Sungshin Ironpaw, Way of the Steamer
(64231, 31470), -- Sungshin Ironpaw, Way of the Wok
(64231, 32684), -- Sungshin Ironpaw, You Want Fish?
(64259, 32030), -- Master Angler Ju Lien, Once in a Hundred Lifetimes
(64259, 31188), -- Master Angler Ju Lien, Shark Week
(64315, 32045), -- Stonecarver Mac, Children of the Water
(64330, 31693), -- Julia Stevens, Julia Stevens
(64330, 31724), -- Julia Stevens, Old MacDonald
(64337, 31820), -- Nomi, A Present for Teacher
(64337, 31337), -- Nomi, A Token of Appreciation
(64337, 31332), -- Nomi, Lesson 1: Sliced Peaches
(64337, 31333), -- Nomi, Lesson 2: Instant Noodles
(64337, 31334), -- Nomi, Lesson 3: Toasted Fish Jerky
(64337, 31335), -- Nomi, Lesson 4: Dried Needle Mushrooms
(64337, 31336), -- Nomi, Lesson 5: Pounded Rice Cake
(64344, 31092), -- Kaz'tik the Manipulator, Feed or Be Eaten
(64344, 31359), -- Kaz'tik the Manipulator, The Kunchong Whisperer
(64395, 31536), -- Nam Ironpaw, Preserving Freshness
(64395, 31535), -- Nam Ironpaw, Replenishing the Pantry
(64399, 31356), -- Master Windstrong, Deep Doubts, Deep Wisdom
(64432, 31360), -- Sinan the Dreamer, A New Lesson for the Master
(64432, 31357), -- Sinan the Dreamer, Relics of the Four Kings
(64448, 31392), -- Hopsmaster Chang, Temple of the White Tiger
(64448, 31393), -- Hopsmaster Chang, Temple of the White Tiger
(64464, 30471), -- Andi, A Gift For Chee Chee
(64464, 30474), -- Andi, A Gift For Ella
(64464, 30473), -- Andi, A Gift For Fish
(64464, 30475), -- Andi, A Gift For Fung
(64464, 30479), -- Andi, A Gift For Gina
(64464, 30477), -- Andi, A Gift For Haohan
(64464, 30478), -- Andi, A Gift For Jogu
(64464, 30476), -- Andi, A Gift For Old Hillpaw
(64464, 30472), -- Andi, A Gift For Sho
(64464, 30470), -- Andi, A Gift For Tina
(64467, 31363), -- Bowmistress Li, Lighting the Way
(64467, 31364), -- Bowmistress Li, That's a Big Bug!
(64484, 31373), -- Instructor Windspear, The Order of the Cloud Serpent
(64488, 31390), -- Riki the Shifting Shadow, The Klaxxi
(64508, 31367), -- Scrollmaker Resshi, The Lorewalkers
(64517, 31365), -- Shado-Master Chum Kiu, Somewhere Inside
(64517, 31366), -- Shado-Master Chum Kiu, Take Down the Wing Leader
(64521, 31392), -- Wanderer Chu, Temple of the White Tiger
(64521, 31393), -- Wanderer Chu, Temple of the White Tiger
(64531, 31368), -- Lena Stonebrush, The Lorewalkers
(64533, 31375), -- Wei Lakebreeze, The Order of the Cloud Serpent
(64534, 31391), -- Bowmaster Ku, The Klaxxi
(64540, 31394), -- Anduin Wrynn, A Celestial Experience
(64540, 31512), -- Anduin Wrynn, A Witness to History
(64542, 31395), -- Sunwalker Dezco, A Celestial Experience
(64542, 31511), -- Sunwalker Dezco, A Witness to History
(64562, 31447), -- Talking Skull, An End to the Suffering
(64562, 31440), -- Talking Skull, The Four Tomes
(64563, 31448), -- Talking Skull, An End to the Suffering
(64563, 31442), -- Talking Skull, The Four Tomes
(64566, 32249), -- Sunwalker Dezco, Meet the Scout
(64566, 32678), -- Sunwalker Dezco, Thunder Calls
(64569, 31441), -- Hisek the Swarmkeeper, Corruption Runs Deep
(64572, 32603), -- Sara Finkleswitch, Beasts of Fable
(64572, 32604), -- Sara Finkleswitch, Beasts of Fable Book I
(64572, 32868), -- Sara Finkleswitch, Beasts of Fable Book II
(64572, 32869), -- Sara Finkleswitch, Beasts of Fable Book III
(64572, 32428), -- Sara Finkleswitch, Pandaren Spirit Tamer
(64572, 32863), -- Sara Finkleswitch, What We've Been Training For
(64582, 32603), -- Gentle San, Beasts of Fable
(64582, 32604), -- Gentle San, Beasts of Fable Book I
(64582, 32868), -- Gentle San, Beasts of Fable Book II
(64582, 32869), -- Gentle San, Beasts of Fable Book III
(64582, 32428), -- Gentle San, Pandaren Spirit Tamer
(64582, 32863), -- Gentle San, What We've Been Training For
(64596, 31739), -- Teng Applebloom, Priorities!
(64597, 32682), -- Nana Mudclaw, Inherit the Earth
(64597, 31948), -- Nana Mudclaw, Nana's Vote II: The Sacred Springs
(64597, 31949), -- Nana Mudclaw, Nana's Vote III: Witchberry Julep
(64599, 31008), -- Ambersmith Zikk, Amber Arms
(64599, 31108), -- Ambersmith Zikk, Concentrated Fear
(64599, 31727), -- Ambersmith Zikk, Gambling Problem
(64599, 31603), -- Ambersmith Zikk, Seeds of Fear
(64599, 31609), -- Ambersmith Zikk, The Wrath of Shek'zeer
(64610, 32246), -- Lyalia, Meet the Scout
(64610, 32679), -- Lyalia, Thunder Calls
(64672, 31441), -- Hisek the Swarmkeeper, Corruption Runs Deep
(64691, 31876), -- Lorewalker Huynh, The Inkmasters of the Arboretum
(64705, 31458), -- Hisek the Swarmkeeper, Damage Control
(64705, 31465), -- Hisek the Swarmkeeper, Extracting Answers
(64738, 31493), -- Hooded Crusader, Just for Safekeeping, Of Course
(64738, 31490), -- Hooded Crusader, Rank and File
(64764, 31497), -- Hooded Crusader, Just for Safekeeping, Of Course
(64764, 31495), -- Hooded Crusader, Rank and File
(64815, 31066), -- Kor'ik, A Cry From Darkness
(64815, 31009), -- Kor'ik, Dead Zone
(64815, 31439), -- Kor'ik, Dropping Our Signal
(64815, 31087), -- Kor'ik, Extending Our Coverage
(64815, 31605), -- Kor'ik, The Zan'thik Dig
(64827, 31513), -- Hooded Crusader, Blades of the Anointed
(64838, 31515), -- Hooded Crusader, Blades of the Anointed
(64854, 31514), -- Blade of the Anointed, Unto Dust Thou Shalt Return
(64855, 31516), -- Blade of the Anointed, Unto Dust Thou Shalt Return
(65253, 31606), -- Rik'kal the Dissector, The Dissector Wakens
(65289, 31058), -- Brewmaster Bo, The Funky Monkey Brew
(65341, 30933), -- Ku-Mo, Seeking Father
(65365, 31090), -- Kor'ik, Better With Age
(65365, 31089), -- Kor'ik, By the Sea, Nevermore
(65365, 31088), -- Kor'ik, Crime and Punishment
(65395, 31782), -- Klaxxi'va Ik, Overthrone
(65454, 31458), -- Hisek the Swarmkeeper, Damage Control
(65454, 31465), -- Hisek the Swarmkeeper, Extracting Answers
(65528, 31279), -- Nan Thunderfoot, Everything I Know About Cooking
(65558, 29784), -- Huojin Monk, Balanced Perspective
(65648, 31725), -- Old MacDonald, Lindsay
(65648, 31780), -- Old MacDonald, Old MacDonald
(65651, 31726), -- Lindsay, Eric Davidson
(65651, 31781), -- Lindsay, Lindsay
(65655, 31850), -- Eric Davidson, Eric Davidson
(65655, 31729), -- Eric Davidson, Steven Lisbane
(65656, 31917), -- Bill Buckler, A Tamer's Homecoming
(65656, 31851), -- Bill Buckler, Bill Buckler
(65669, 30151), -- Your Hatchling, Catch!
(65669, 30156), -- Your Hatchling, Feeding Time
(65669, 31704), -- Your Hatchling, Pooped
(65669, 30150), -- Your Hatchling, Sweet as Honey
(65669, 30154), -- Your Hatchling, The Easiest Way To A Serpent's Heart
(65670, 30151), -- Your Hatchling, Catch!
(65670, 30156), -- Your Hatchling, Feeding Time
(65670, 31704), -- Your Hatchling, Pooped
(65670, 30150), -- Your Hatchling, Sweet as Honey
(65670, 30154), -- Your Hatchling, The Easiest Way To A Serpent's Heart
(65671, 30151), -- Your Hatchling, Catch!
(65671, 30156), -- Your Hatchling, Feeding Time
(65671, 31704), -- Your Hatchling, Pooped
(65671, 30150), -- Your Hatchling, Sweet as Honey
(65671, 30154), -- Your Hatchling, The Easiest Way To A Serpent's Heart
(65672, 30156), -- Your Cloud Serpent, Feeding Time
(65672, 31716), -- Your Cloud Serpent, Pooped
(65672, 30154), -- Your Cloud Serpent, The Easiest Way To A Serpent's Heart
(65672, 31710), -- Your Cloud Serpent, Tiny Treats
(65673, 30156), -- Your Cloud Serpent, Feeding Time
(65673, 31716), -- Your Cloud Serpent, Pooped
(65673, 30154), -- Your Cloud Serpent, The Easiest Way To A Serpent's Heart
(65673, 31710), -- Your Cloud Serpent, Tiny Treats
(65674, 30156), -- Your Cloud Serpent, Feeding Time
(65674, 31716), -- Your Cloud Serpent, Pooped
(65674, 30154), -- Your Cloud Serpent, The Easiest Way To A Serpent's Heart
(65674, 31710), -- Your Cloud Serpent, Tiny Treats
(65679, 31716), -- Golden Hatchling, Pooped
(65679, 30154), -- Golden Hatchling, The Easiest Way To A Serpent's Heart
(65679, 31710), -- Golden Hatchling, Tiny Treats
(65723, 31716), -- Jade Hatchling, Pooped
(65723, 30154), -- Jade Hatchling, The Easiest Way To A Serpent's Heart
(65723, 31710), -- Jade Hatchling, Tiny Treats
(65724, 30156), -- Azure Hatchling, Feeding Time
(65724, 31716), -- Azure Hatchling, Pooped
(65724, 30154), -- Azure Hatchling, The Easiest Way To A Serpent's Heart
(65724, 31710), -- Azure Hatchling, Tiny Treats
(65910, 31738), -- Sunke Khang, Pillaging Peons
(65910, 31741), -- Sunke Khang, Twinspire Keep
(65910, 31744), -- Sunke Khang, Unfair Trade
(65975, 31681), -- Zer'ik, Better With Age
(65975, 31682), -- Zer'ik, By the Sea, Nevermore
(65975, 31680), -- Zer'ik, Crime and Punishment
(65998, 31778), -- Merchant Zin, Unreliable Allies
(65999, 31775), -- General Nazgrim, Assault on the Airstrip
(65999, 31776), -- General Nazgrim, Strongarm Tactics
(65999, 31779), -- General Nazgrim, The Darkness Within
(66126, 31813), -- Zunta, Dagra the Fierce
(66126, 31818), -- Zunta, Zunta
(66135, 31814), -- Dagra the Fierce, Analynn
(66135, 31819), -- Dagra the Fierce, Dagra the Fierce
(66136, 31854), -- Analynn, Analynn
(66136, 31815), -- Analynn, Zonya the Sadist
(66137, 31817), -- Zonya the Sadist, Merda Stronghoof
(66137, 31862), -- Zonya the Sadist, Zonya the Sadist
(66190, 31767), -- General Nazgrim, Finish Them!
(66190, 31768), -- General Nazgrim, Fire Is Always the Answer
(66199, 31740), -- Lin Applebloom, Koukou's Rampage
(66260, 31834), -- Master Hight, Begin Your Training: Master Cheng
(66260, 31944), -- Master Hight, Complete Your Training: The Final Test
(66260, 31837), -- Master Hight, Continue Your Training: Master Cheng
(66260, 31839), -- Master Hight, Continue Your Training: Master Hsu
(66260, 31835), -- Master Hight, Continue Your Training: Master Kistane
(66260, 31838), -- Master Hight, Continue Your Training: Master Tsang
(66260, 31833), -- Master Hight, Continue Your Training: Master Woo
(66260, 31836), -- Master Hight, Continue Your Training: Master Yoon
(66260, 31840), -- Master Hight, Practice Makes Perfect: Master Cheng
(66260, 31844), -- Master Hight, Practice Makes Perfect: Master Cheng
(66260, 31846), -- Master Hight, Practice Makes Perfect: Master Hsu
(66260, 31842), -- Master Hight, Practice Makes Perfect: Master Kistane
(66260, 31845), -- Master Hight, Practice Makes Perfect: Master Tsang
(66260, 31841), -- Master Hight, Practice Makes Perfect: Master Woo
(66260, 31843), -- Master Hight, Practice Makes Perfect: Master Yoon
(66292, 29556), -- Sky Admiral Rogers, Hozen Aren't Your Friends, Hozen Are Your Enemies
(66292, 29555), -- Sky Admiral Rogers, The White Pawn
(66292, 31733), -- Sky Admiral Rogers, Touching Ground
(66292, 31732), -- Sky Admiral Rogers, Unleash Hell
(66352, 31871), -- Traitor Gluk, Traitor Gluk
(66372, 31870), -- Merda Stronghoof, Cassandra Kaboom
(66372, 31872), -- Merda Stronghoof, Merda Stronghoof
(66412, 31908), -- Elena Flutterfly, Elena Flutterfly
(66422, 31918), -- Cassandra Kaboom, A Tamer's Homecoming
(66422, 31904), -- Cassandra Kaboom, Cassandra Kaboom
(66436, 31905), -- Grazzle the Great, Grazzle the Great
(66442, 31907), -- Zoltan, Zoltan
(66452, 31906), -- Kela Grimtotem, Kela Grimtotem
(66466, 31897), -- Stone Cold Trixxy, Grand Master Trixxy
(66466, 31909), -- Stone Cold Trixxy, Grand Master Trixxy
(66466, 31977), -- Stone Cold Trixxy, The Returning Champion
(66478, 31910), -- David Kosse, David Kosse
(66512, 31911), -- Deiza Plaguehorn, Deiza Plaguehorn
(66515, 31912), -- Kortas Darkhammer, Kortas Darkhammer
(66518, 31913), -- Everessa, Everessa
(66520, 31914), -- Durin Darkhammer, Durin Darkhammer
(66522, 31915), -- Lydia Accoste, Grand Master Lydia Accoste
(66522, 31916), -- Lydia Accoste, Grand Master Lydia Accoste
(66522, 31976), -- Lydia Accoste, The Returning Champion
(66522, 31980), -- Lydia Accoste, The Returning Champion
(66550, 31922), -- Nicki Tinytech, Nicki Tinytech
(66551, 31923), -- Ras'an, Ras'an
(66552, 31924), -- Narrok, Narrok
(66553, 31925), -- Morulu The Elder, Morulu The Elder
(66557, 31981), -- Bloodknight Antari, Exceeding Expectations
(66557, 31982), -- Bloodknight Antari, Exceeding Expectations
(66557, 31920), -- Bloodknight Antari, Grand Master Antari
(66557, 31926), -- Bloodknight Antari, Grand Master Antari
(66574, 29552), -- Mishka, Critical Condition
(66581, 31745), -- Rell Nightwind, Onward and Inward
(66635, 31931), -- Beegle Blastfuse, Beegle Blastfuse
(66636, 31932), -- Nearly Headless Jacob, Nearly Headless Jacob
(66638, 31933), -- Okrut Dragonwaste, Okrut Dragonwaste
(66639, 31934), -- Gutretch, Gutretch
(66646, 31769), -- General Nazgrim, The Final Blow!
(66656, 29694), -- General Nazgrim, Regroup!
(66656, 31770), -- General Nazgrim, You're Either With Us Or...
(66657, 31771), -- Taran Zhu, Face to Face With Consequence
(66659, 31773), -- Sue-Ji the Tender, Prowler Problems
(66660, 31772), -- Ellie Honeypaw, Priorities!
(66662, 31978), -- Gi-Oh, Priorities!
(66667, 31766), -- Rivett Clutchpop, Touching Ground
(66675, 31983), -- Major Payne, A Brief Reprieve
(66675, 31984), -- Major Payne, A Brief Reprieve
(66675, 31928), -- Major Payne, Grand Master Payne
(66675, 31935), -- Major Payne, Grand Master Payne
(66730, 31953), -- Hyuna of the Shrines, Grand Master Hyuna
(66733, 31954), -- Mo'ruk, Grand Master Mo'ruk
(66734, 31955), -- Farmer Nishi, Grand Master Nishi
(66738, 31956), -- Courageous Yon, Grand Master Yon
(66739, 31957), -- Wastewalker Shu, Grand Master Shu
(66741, 31958), -- Aki the Chosen, Grand Master Aki
(66815, 31973), -- Bordin Steadyfist, Bordin Steadyfist
(66819, 31972), -- Brok, Brok
(66822, 31974), -- Goz Banefury, Goz Banefury
(66824, 31970), -- Obalis, Grand Master Obalis
(66824, 31971), -- Obalis, Grand Master Obalis
(66824, 31985), -- Obalis, The Triumphant Return
(66824, 31986), -- Obalis, The Triumphant Return
(66825, 31772), -- Ellie Honeypaw, Priorities!
(66838, 31773), -- Kai-Lin Honeydew, Prowler Problems
(66841, 31773), -- Kai-Lin Honeydew, Prowler Problems
(66845, 31774), -- Sergeant Gorrok, Seeking Zin'jun
(66853, 31773), -- Kai-Lin Honeydew, Prowler Problems
(66918, 31991), -- Seeker Zusshi, Grand Master Zusshi
(66949, 29885), -- Rell Nightwind, Road Rations
(66949, 29883), -- Rell Nightwind, The Pearlfin Situation
(66998, 32901), -- Jinho the Wind Breaker, Heroic Deeds
(66998, 33249), -- Jinho the Wind Breaker, Proving Grounds
(67091, 31271), -- Rik'kal the Dissector, Bad Genes
(67091, 31509), -- Rik'kal the Dissector, Fear Takes Root
(67091, 31234), -- Rik'kal the Dissector, Putting An Eye Out
(67091, 31503), -- Rik'kal the Dissector, Shortcut to Ruin
(67091, 31508), -- Rik'kal the Dissector, Specimen Request
(67091, 31502), -- Rik'kal the Dissector, Wing Clip
(67138, 31077), -- Chen Stormstout, Evie Stormstout
(67138, 31078), -- Chen Stormstout, Han Stormstout
(67153, 29804), -- Zin'Jun, Seein' Red
(67370, 32175), -- Jeremy Feasel, Darkmoon Pet Battle!
(67386, 32146), -- Sky Admiral Rogers, Hammer to Fall
(67386, 32157), -- Sky Admiral Rogers, The Only Good Goblin...
(67386, 32142), -- Sky Admiral Rogers, We Will Rock You
(67402, 32130), -- Zazzix "Toasty" Sparkrocket, Good Luck, Have Fun
(67402, 32134), -- Zazzix "Toasty" Sparkrocket, Hard Counter
(67402, 32131), -- Zazzix "Toasty" Sparkrocket, We Require More Minerals!
(67444, 32156), -- Mishka, It's Only Right
(67444, 32144), -- Mishka, Under Pressure
(67498, 32182), -- Krasari Elder, Beastmaster's Quarry: The Tiger
(67498, 32185), -- Krasari Elder, Beastmaster's Quarry: The Tiger
(67503, 32181), -- Ancient Bloodcrown Crane, Beastmaster's Quarry: The Crane
(67503, 32184), -- Ancient Bloodcrown Crane, Beastmaster's Quarry: The Crane
(67508, 32183), -- Colossal Viseclaw, Beastmaster's Quarry: The Crab
(67508, 32186), -- Colossal Viseclaw, Beastmaster's Quarry: The Crab
(67528, 32145), -- Sully "The Pickle" McLeary, Don't Lose Your Head
(67533, 32238), -- Bixy Buzzsaw, Universal Remote-Explode
(67534, 32139), -- Zino "The Shredder" Quickchop, Stacked!
(67535, 32136), -- Boss-Lady Trixel, Work Order: Fuel
(67535, 32140), -- Boss-Lady Trixel, Work Order: Iron
(67535, 32138), -- Boss-Lady Trixel, Work Order: Lumber
(67537, 32141), -- Daxil "The Gem" Oregrind, Power Metal
(67542, 32137), -- Grizzle Gearslip, Runnin' On Empty
(67553, 32237), -- Bixy Buzzsaw, Precious Resource
(67554, 32236), -- Bixy Buzzsaw, Bug Off!
(67562, 32199), -- Duke, Krasarang Steampot
(67562, 32197), -- Duke, Mystery Meatloaf
(67565, 32198), -- Barnaby Fletcher, One Magical, Flying Kingdom's Trash...
(67581, 32192), -- Lor'themar Theron, Bloodlines
(67603, 32191), -- Fanlyr Silverthorn, Ancient Guardians
(67603, 32244), -- Fanlyr Silverthorn, The Korune
(67608, 32214), -- Rivett Clutchpop, Bilgewater Infiltrators
(67608, 32221), -- Rivett Clutchpop, Storming the Beach
(67618, 32123), -- Shokia, Death on Two Legs
(67628, 32135), -- Shademaster Kiryn, Hero Killer
(67628, 32133), -- Shademaster Kiryn, Sentry Wards
(67628, 32132), -- Shademaster Kiryn, Worker Harassment
(67630, 32149), -- Mishka, Resource Gathering
(67630, 32150), -- Mishka, Supply Block
(67631, 32148), -- Marshal Troteman, Attack! Move!
(67631, 32153), -- Marshal Troteman, Hero Killer
(67631, 32116), -- Marshal Troteman, Priorities, People!
(67631, 32152), -- Marshal Troteman, Siege Damage
(67631, 32151), -- Marshal Troteman, Tower Defense
(67660, 32293), -- Archmage Aethas Sunreaver, Among the Bones
(67660, 32520), -- Archmage Aethas Sunreaver, Competing Magic
(67660, 32561), -- Archmage Aethas Sunreaver, Competing Magic
(67660, 32255), -- Archmage Aethas Sunreaver, De-Constructed
(67660, 32521), -- Archmage Aethas Sunreaver, Encroaching Force
(67660, 32522), -- Archmage Aethas Sunreaver, Imposing Threat
(67660, 32562), -- Archmage Aethas Sunreaver, Imposing Threat
(67660, 32254), -- Archmage Aethas Sunreaver, Manipulating the Saurok
(67660, 32605), -- Archmage Aethas Sunreaver, Subtle Encouragement
(67660, 32523), -- Archmage Aethas Sunreaver, The Beast Pens
(67660, 32524), -- Archmage Aethas Sunreaver, The Beating of Troll Drums
(67660, 32204), -- Archmage Aethas Sunreaver, The Skumblade Threat
(67662, 32265), -- High Arcanist Savor, Charged Moganite
(67662, 32287), -- High Arcanist Savor, Enemies Beneath the Tower
(67662, 32303), -- High Arcanist Savor, Made for War
(67662, 32264), -- High Arcanist Savor, Spellbound
(67662, 32285), -- High Arcanist Savor, The Sleepless Legion
(67663, 32506), -- Magister Hathorel, A Wing to Fly On
(67663, 32288), -- Magister Hathorel, Bolstering the Defenses
(67663, 32262), -- Magister Hathorel, Captive Audience
(67663, 32300), -- Magister Hathorel, Disarming Irony
(67663, 32730), -- Magister Hathorel, Ihgaluk Crag
(67663, 32305), -- Magister Hathorel, Overpowered
(67673, 32269), -- Girana the Blooded, Breaking Down the Defenses
(67673, 32302), -- Girana the Blooded, Desconstruction
(67673, 32266), -- Girana the Blooded, Mana Manifestations
(67673, 32268), -- Girana the Blooded, Tactical Mana Bombs
(67673, 32728), -- Girana the Blooded, The Court of Bones
(67673, 32228), -- Girana the Blooded, The Shuddering Moor
(67673, 32230), -- Girana the Blooded, The Zandalari Colossus
(67716, 32243), -- Hilda Hornswaggle, The Source of Korune Power
(67734, 32194), -- Sarannha Skyglaive, Bad Blood
(67734, 32394), -- Sarannha Skyglaive, The Divine Bell
(67767, 32127), -- Brolic, All Dead, All Dead
(67767, 32126), -- Brolic, Tear It Up
(67834, 32257), -- Fanlyr Silverthorn, Voice of the Gods
(67840, 32242), -- Garrosh Hellscream, Buried Secrets
(67844, 32399), -- Malkorok, Breath of Darkest Shadow
(67847, 32118), -- Belloc Brightblade, Taking Advantage
(67865, 32284), -- Messenger Grummle, Someone You Should See
(67866, 32318), -- Chen Stormstout, Regeneration Takes Time
(67867, 32250), -- Garrosh Hellscream, The Might of the Warchief
(67880, 32128), -- Blood Guard Gro'tash, Another One Bites the Dust
(67880, 32235), -- Blood Guard Gro'tash, Flash! Aaaaaahhhh!
(67880, 32449), -- Blood Guard Gro'tash, The Ruins of Ogudei
(67880, 32450), -- Blood Guard Gro'tash, The Time Is Now!
(67939, 32251), -- General Nazgrim, Dagger in the Dark
(67939, 32351), -- General Nazgrim, Echoes of Thunder
(67939, 32329), -- General Nazgrim, Get My Results!
(67939, 32326), -- General Nazgrim, Insertion
(67939, 32256), -- General Nazgrim, Rise Of An Empire
(67939, 32398), -- General Nazgrim, The Bell Speaks
(67939, 32363), -- General Nazgrim, The Kun-Lai Expedition
(67939, 32391), -- General Nazgrim, The Ruins of Korune
(67939, 32402), -- General Nazgrim, The Situation In Dalaran
(67939, 32190), -- General Nazgrim, To Mogujia
(67939, 32376), -- General Nazgrim, To the Valley!
(67940, 32248), -- Admiral Taylor, A Little Patience
(67940, 32315), -- Admiral Taylor, Anduin's Plea
(67940, 32414), -- Admiral Taylor, Darnassus Attacked?
(67940, 32382), -- Admiral Taylor, He's In Deep
(67940, 32400), -- Admiral Taylor, The Bell Speaks
(67940, 32380), -- Admiral Taylor, The Best Around
(67940, 32355), -- Admiral Taylor, The Harmonic Mallet
(67940, 32331), -- Admiral Taylor, The Kirin Tor
(67940, 32370), -- Admiral Taylor, The Kun-Lai Expedition
(67940, 32393), -- Admiral Taylor, The Ruins of Korune
(67940, 32193), -- Admiral Taylor, To Mogujia
(67948, 32316), -- Anduin Wrynn, Heart Of The Alliance
(67976, 32143), -- Tinkmaster Overspark, A Kind of Magic
(67983, 32218), -- Captain Aerthas Firehawk, Ashes of the Enemy
(67983, 32220), -- Captain Aerthas Firehawk, Soul Surrender
(67984, 32227), -- Kethiel Sunlance, Preventing a Future Threat
(67984, 32216), -- Kethiel Sunlance, Pterrible Ptorment
(67985, 32282), -- Scout Captain Elsia, Compy Stomp
(67985, 32298), -- Scout Captain Elsia, Dino Might
(67985, 32563), -- Scout Captain Elsia, Encroaching Force
(67985, 32565), -- Scout Captain Elsia, Encroaching Force
(67985, 32294), -- Scout Captain Elsia, Raining Bones
(67985, 32206), -- Scout Captain Elsia, This Just Won't Do
(67985, 32233), -- Scout Captain Elsia, Very Disarming
(67985, 32232), -- Scout Captain Elsia, What's Inside Counts
(67985, 32564), -- Scout Captain Elsia, Zandalari on the Rise
(67986, 32297), -- Magister Edien Sunhollow, Direhorn or Devilsaur
(67986, 32234), -- Magister Edien Sunhollow, Knowledge Is Power
(67986, 32283), -- Magister Edien Sunhollow, Loa-saur
(67986, 32208), -- Magister Edien Sunhollow, Maximum Capacitor
(67986, 32494), -- Magister Edien Sunhollow, Power Play
(67986, 32207), -- Magister Edien Sunhollow, Saur Loser
(67986, 32209), -- Magister Edien Sunhollow, Save Our Scouts!
(67986, 32493), -- Magister Edien Sunhollow, They All Fall Down
(67989, 32293), -- Grand Magister Rommath, Among the Bones
(67989, 32265), -- Grand Magister Rommath, Charged Moganite
(67989, 32520), -- Grand Magister Rommath, Competing Magic
(67989, 32561), -- Grand Magister Rommath, Competing Magic
(67989, 32521), -- Grand Magister Rommath, Encroaching Force
(67989, 32201), -- Grand Magister Rommath, Grave Circumstances
(67989, 32522), -- Grand Magister Rommath, Imposing Threat
(67989, 32562), -- Grand Magister Rommath, Imposing Threat
(67989, 32523), -- Grand Magister Rommath, The Beast Pens
(67989, 32524), -- Grand Magister Rommath, The Beating of Troll Drums
(67989, 32495), -- Grand Magister Rommath, The Bloodletter
(67989, 32225), -- Grand Magister Rommath, The Call of Thunder
(67990, 32709), -- Lor'themar Theron, Allies in the Shadows
(67990, 32293), -- Lor'themar Theron, Among the Bones
(67990, 32520), -- Lor'themar Theron, Competing Magic
(67990, 32521), -- Lor'themar Theron, Encroaching Force
(67990, 32304), -- Lor'themar Theron, High Recognition
(67990, 32522), -- Lor'themar Theron, Imposing Threat
(67990, 32589), -- Lor'themar Theron, Life Blood
(67990, 32213), -- Lor'themar Theron, Old Enemies
(67990, 32276), -- Lor'themar Theron, Tear Down This Wall!
(67990, 32212), -- Lor'themar Theron, The Assault on Zeb'tula
(67990, 32523), -- Lor'themar Theron, The Beast Pens
(67990, 32524), -- Lor'themar Theron, The Beating of Troll Drums
(67990, 32279), -- Lor'themar Theron, The Fall of Shan Bu
(67990, 32277), -- Lor'themar Theron, To the Skies!
(67990, 32729), -- Lor'themar Theron, Za'Tual
(67992, 32706), -- Lady Jaina Proudmoore, Allies in the Shadows
(67992, 32578), -- Lady Jaina Proudmoore, Among the Bones
(67992, 32485), -- Lady Jaina Proudmoore, Bolstering the Defenses
(67992, 32636), -- Lady Jaina Proudmoore, Captive Audience
(67992, 32579), -- Lady Jaina Proudmoore, Competing Magic
(67992, 32580), -- Lady Jaina Proudmoore, Encroaching Force
(67992, 32635), -- Lady Jaina Proudmoore, Enough with the Bombs!
(67992, 32631), -- Lady Jaina Proudmoore, High Recognition
(67992, 32581), -- Lady Jaina Proudmoore, Imposing Threat
(67992, 32568), -- Lady Jaina Proudmoore, No Time To Rest
(67992, 32637), -- Lady Jaina Proudmoore, Overpowered
(67992, 32599), -- Lady Jaina Proudmoore, Securing A Future
(67992, 32654), -- Lady Jaina Proudmoore, Tear Down This Wall!
(67992, 32644), -- Lady Jaina Proudmoore, The Assault on Shaol'mara
(67992, 32567), -- Lady Jaina Proudmoore, The Beast Pens
(67992, 32656), -- Lady Jaina Proudmoore, The Fall of Shan Bu
(67992, 32652), -- Lady Jaina Proudmoore, To the Skies!
(67992, 32733), -- Lady Jaina Proudmoore, Za'Tual
(67993, 32301), -- Vereesa Windrunner, Old Enemies
(67993, 32731), -- Vereesa Windrunner, The Court of Bones
(67993, 32574), -- Vereesa Windrunner, The Shuddering Moor
(67993, 32575), -- Vereesa Windrunner, The Zandalari Colossus
(67994, 32571), -- Warmage Yurias, A Wing to Fly On
(67994, 32627), -- Warmage Yurias, Charged Moganite
(67994, 32632), -- Warmage Yurias, Made for War
(67994, 32633), -- Warmage Yurias, Spellbound
(67995, 32634), -- Captain Elleane Wavecrest, Breaking Down the Defenses
(67995, 32639), -- Captain Elleane Wavecrest, Deconstruction
(67995, 32573), -- Captain Elleane Wavecrest, Enemies Beneath the Tower
(67995, 32732), -- Captain Elleane Wavecrest, Ihgaluk Crag
(67995, 32638), -- Captain Elleane Wavecrest, Mana Scavengers
(67995, 32628), -- Captain Elleane Wavecrest, Tactical Mana Bombs
(67995, 32572), -- Captain Elleane Wavecrest, The Sleepless Legion
(67996, 32578), -- Archmage Modera, Among the Bones
(67996, 32576), -- Archmage Modera, Competing Magic
(67996, 32579), -- Archmage Modera, Competing Magic
(67996, 32537), -- Archmage Modera, De-Constructed
(67996, 32580), -- Archmage Modera, Encroaching Force
(67996, 32577), -- Archmage Modera, Imposing Threat
(67996, 32581), -- Archmage Modera, Imposing Threat
(67996, 32536), -- Archmage Modera, Manipulating the Saurok
(67996, 32568), -- Archmage Modera, No Time To Rest
(67996, 32606), -- Archmage Modera, Subtle Encouragement
(67996, 32567), -- Archmage Modera, The Beast Pens
(67996, 32535), -- Archmage Modera, The Skumblade Threat
(67997, 32578), -- Narasi Snowdawn, Among the Bones
(67997, 32576), -- Narasi Snowdawn, Competing Magic
(67997, 32579), -- Narasi Snowdawn, Competing Magic
(67997, 32580), -- Narasi Snowdawn, Encroaching Force
(67997, 32527), -- Narasi Snowdawn, Grave Circumstances
(67997, 32577), -- Narasi Snowdawn, Imposing Threat
(67997, 32581), -- Narasi Snowdawn, Imposing Threat
(67997, 32568), -- Narasi Snowdawn, No Time To Rest
(67997, 32526), -- Narasi Snowdawn, Soul Surrender
(67997, 32567), -- Narasi Snowdawn, The Beast Pens
(67998, 32551), -- Scout Captain Daelin, Compy Stomp
(67998, 32554), -- Scout Captain Daelin, Dino Might
(67998, 32584), -- Scout Captain Daelin, Encroaching Force
(67998, 32585), -- Scout Captain Daelin, Encroaching Force
(67998, 32559), -- Scout Captain Daelin, Even Giants Fall
(67998, 32560), -- Scout Captain Daelin, Keep It Secret
(67998, 32557), -- Scout Captain Daelin, Out of Enemy Hands
(67998, 32582), -- Scout Captain Daelin, Raining Bones
(67998, 32550), -- Scout Captain Daelin, Saur Loser
(67998, 32583), -- Scout Captain Daelin, Zandalari on the Rise
(67999, 32558), -- Miura Brightweaver, All In the Family
(67999, 32555), -- Miura Brightweaver, Centuries in Sentries
(67999, 32553), -- Miura Brightweaver, Direhorn vs Devilsaur
(67999, 32552), -- Miura Brightweaver, Loa-saur
(67999, 32586), -- Miura Brightweaver, Maximum Capacitor
(67999, 32588), -- Miura Brightweaver, On Her Magic-ey Secret Service
(67999, 32556), -- Miura Brightweaver, The More You Know
(68003, 32332), -- The Monkey King, The First Riddle: Mercy
(68003, 32333), -- The Monkey King, The Second Riddle: Fellowship
(68003, 32334), -- The Monkey King, The Third Riddle: Strength
(68004, 32321), -- Anduin Wrynn, The Monkey King
(68023, 32319), -- Vol'jin, Find Thrall!
(68025, 32372), -- Thrall, De-Subjugation
(68025, 32320), -- Thrall, The Horde Is Family
(68072, 32108), -- Kor'kron Bodyguard, Domination Point
(68072, 32250), -- Kor'kron Bodyguard, The Might of the Warchief
(68077, 32327), -- Fanlyr Silverthorn, The Darnassus Mission
(68077, 32328), -- Fanlyr Silverthorn, Victorious Return
(68106, 32362), -- Anduin Wrynn, The Fate of Dalaran
(68166, 32154), -- Sully "The Pickle" McLeary, Burn Out!
(68166, 32446), -- Sully "The Pickle" McLeary, Dis-Assembly Required
(68182, 32158), -- Seraphine of the Winter, Two Step Program
(68274, 32344), -- Kaelis Sunsoar, It Is A Mystery
(68274, 32348), -- Kaelis Sunsoar, Kick 'em While They're Down
(68274, 32120), -- Kaelis Sunsoar, Legacy of Ogudei
(68274, 32343), -- Kaelis Sunsoar, Ogudei's Lieutenants
(68274, 32342), -- Kaelis Sunsoar, The Spirit Trap
(68274, 32345), -- Kaelis Sunsoar, We're Not Monsters!
(68275, 32347), -- Hilda Hornswaggle, Eviction Notice
(68275, 32119), -- Hilda Hornswaggle, It Is A Mystery
(68275, 32122), -- Hilda Hornswaggle, Ogudei's Lieutenants
(68275, 32346), -- Hilda Hornswaggle, Oi Ain't Afraid o' No Ghosts!
(68275, 32115), -- Hilda Hornswaggle, Shackles of the Past
(68275, 32121), -- Hilda Hornswaggle, The Spirit Trap
(68287, 32352), -- Baine Bloodhoof, A Gathering Storm
(68287, 32368), -- Baine Bloodhoof, Memory Wine
(68287, 32448), -- Baine Bloodhoof, Ties with the Past
(68337, 32392), -- Ishi, The Divine Bell
(68370, 32378), -- Lor'themar Theron, Clearing a Path
(68370, 32379), -- Lor'themar Theron, Legacy of the Korune
(68370, 32384), -- Lor'themar Theron, Trapping the Leader
(68375, 32377), -- Agent Connelly, A Kor'kron In Our Midst
(68375, 32371), -- Agent Connelly, Memory Wine
(68392, 32247), -- King Varian Wrynn, A King Among Men
(68399, 32247), -- 7th Legion Champion, A King Among Men
(68399, 32109), -- 7th Legion Champion, Lion's Landing
(68417, 32383), -- Cousin Goottooth, Bugging Out
(68417, 32397), -- Cousin Goottooth, He Won't Even Miss It
(68462, 32439), -- Flowing Pandaren Spirit, Flowing Pandaren Spirit
(68463, 32434), -- Burning Pandaren Spirit, Burning Pandaren Spirit
(68464, 32440), -- Whispering Pandaren Spirit, Whispering Pandaren Spirit
(68465, 32441), -- Thundering Pandaren Spirit, Thundering Pandaren Spirit
(68526, 32426), -- Barkeep Townsley, Stirred, Not Shaken
(68526, 32381), -- Barkeep Townsley, To Catch A Spy
(68538, 32335), -- The Monkey King, The Greatest Prank
(68538, 32336), -- The Monkey King, The Handle
(68538, 32338), -- The Monkey King, The Harmonic Ointment
(68538, 32337), -- The Monkey King, The Head
(68586, 32413), -- Grand Magister Rommath, A Return to Krasarang
(68586, 32406), -- Grand Magister Rommath, A Tactical Assault
(68586, 32405), -- Grand Magister Rommath, Hand of the Silver Covenant
(68586, 32403), -- Grand Magister Rommath, It Starts in the Sewers
(68586, 32410), -- Grand Magister Rommath, Krasus' Landing
(68586, 32412), -- Grand Magister Rommath, One Last Grasp
(68586, 32409), -- Grand Magister Rommath, The Kirin Tor's True Colors
(68586, 32411), -- Grand Magister Rommath, The Remaining Sunreavers
(68586, 32408), -- Grand Magister Rommath, The Silver Covenant's Stronghold
(68586, 32404), -- Grand Magister Rommath, Violence in the Arena
(68651, 32416), -- Lady Jaina Proudmoore, Jaina's Resolution
(68651, 32460), -- Lady Jaina Proudmoore, Tracking the Thieves
(68687, 32420), -- Vereesa Windrunner, Cashing Out
(68687, 32419), -- Vereesa Windrunner, Nowhere to Hide
(68687, 32421), -- Vereesa Windrunner, Nowhere to Run
(68687, 32417), -- Vereesa Windrunner, Sewer Cleaning
(68687, 32418), -- Vereesa Windrunner, Unfair Trade
(68687, 32423), -- Vereesa Windrunner, What Had To Be Done
(68908, 32452), -- Amber Kearnen, And Then There Were Goblins
(68908, 32451), -- Amber Kearnen, Send A Message
(68939, 32401), -- Anduin Wrynn, Breath of Darkest Shadow
(68987, 32455), -- Anduin Wrynn, The Silence
(69371, 32299), -- Amalia Penshire, Just Some Light Clean-Up Work
(69371, 32491), -- Amalia Penshire, Left To Rot
(69371, 32489), -- Amalia Penshire, The Creeping Carpet of Ihgaluk
(69389, 32226), -- Ryshelle Brightlock, Into the Crypts
(69389, 32224), -- Ryshelle Brightlock, Rise No More!
(69389, 32219), -- Ryshelle Brightlock, Stone Cold
(69389, 32517), -- Ryshelle Brightlock, The Conquest of Stone
(69413, 32607), -- Taoshi, Extended Shore Leave
(69413, 32676), -- Taoshi, Extended Shore Leave
(69413, 32608), -- Taoshi, Raiding the Vault
(69413, 32677), -- Taoshi, Raiding the Vault
(69418, 32217), -- Elina Zaralae, Dark Offerings
(69418, 32215), -- Elina Zaralae, Heinous Sacrifice
(69425, 32274), -- Sunwalker Dezco, The Residents of Ihgaluk
(69433, 32507), -- Magistrix Saia, Skin of the Saurok
(69529, 32498), -- Jade Forest Flame Guardian, Honor the Flame
(69533, 32499), -- Krasarang Wilds Flame Guardian, Honor the Flame
(69535, 32500), -- Kun-Lai Summit Flame Guardian, Honor the Flame
(69536, 32501), -- Townlong Steppes Flame Guardian, Honor the Flame
(69550, 32502), -- Valley of the Four Winds Flame Guardian, Honor the Flame
(69551, 32509), -- Vale of Eternal Blossoms Flame Keeper, Honor the Flame
(69572, 32510), -- Vale of Eternal Blossoms Flame Warden, Honor the Flame
(69668, 32525), -- Danara Silverglass, Ashes of the Enemy
(69668, 32528), -- Danara Silverglass, Into the Crypts
(69668, 32532), -- Danara Silverglass, Rise No More!
(69668, 32533), -- Danara Silverglass, Stone Cold
(69670, 32530), -- Vylene Amaranth, The Bloodletter
(69670, 32529), -- Vylene Amaranth, The Call of Thunder
(69670, 32531), -- Vylene Amaranth, The Conquest of Stone
(69673, 32541), -- Ako, Preventing a Future Threat
(69673, 32544), -- Ako, Pterrible Ptorment
(69674, 32539), -- Dalvin Jaacor, Dark Offerings
(69674, 32538), -- Dalvin Jaacor, Heinous Sacrifice
(69675, 32545), -- Lyalia, The Residents of Ihgaluk
(69677, 32546), -- Sanitation Sorcerer Stephen Litmatch, Just Some Light Clean-Up Work
(69677, 32548), -- Sanitation Sorcerer Stephen Litmatch, Left To Rot
(69677, 32547), -- Sanitation Sorcerer Stephen Litmatch, The Creeping Carpet of Ihgaluk
(69678, 32549), -- Image of Archmage Vargoth, Skin of the Saurok
(70022, 32616), -- Ku'ma, A Large Pile of Giant Dinosaur Bones
(70022, 32617), -- Ku'ma, A Mountain of Giant Dinosaur Bones
(70022, 32613), -- Ku'ma, Giant Dinosaur Bone
(70022, 32615), -- Ku'ma, Many More Giant Dinosaur Bones
(70022, 32614), -- Ku'ma, More Giant Dinosaur Bones
(70160, 32640), -- Taran Zhu, Champions of the Thunder King
(70160, 32641), -- Taran Zhu, Champions of the Thunder King
(70160, 32707), -- Taran Zhu, Secrets in the Isle of Thunder
(70160, 32708), -- Taran Zhu, Setting the Trap
(70297, 32655), -- Taoshi, A Bold Idea
(70297, 32278), -- Taoshi, Decisive Action
(70316, 32296), -- Taoshi, Treasures of the Thunder King
(70358, 32680), -- Scout Captain Elsia, The Storm Gathers
(70360, 32681), -- Vereesa Windrunner, The Storm Gathers
(70370, 32706), -- Lady Jaina Proudmoore, Allies in the Shadows
(70370, 32644), -- Lady Jaina Proudmoore, The Assault on Shaol'mara
(70370, 32733), -- Lady Jaina Proudmoore, Za'Tual
(70371, 32709), -- Lor'themar Theron, Allies in the Shadows
(70371, 32212), -- Lor'themar Theron, The Assault on Zeb'tula
(70371, 32729), -- Lor'themar Theron, Za'Tual
(70398, 32685), -- Ben of the Booming Voice, No Fishing Pole Necessary!
(70517, 32578), -- Archmage Lan'dalock, Among the Bones
(70517, 32576), -- Archmage Lan'dalock, Competing Magic
(70517, 32579), -- Archmage Lan'dalock, Competing Magic
(70517, 32543), -- Archmage Lan'dalock, Dangers of Za'Tual
(70517, 32580), -- Archmage Lan'dalock, Encroaching Force
(70517, 32540), -- Archmage Lan'dalock, Harbingers of the Loa
(70517, 32577), -- Archmage Lan'dalock, Imposing Threat
(70517, 32581), -- Archmage Lan'dalock, Imposing Threat
(70517, 32568), -- Archmage Lan'dalock, No Time To Rest
(70517, 32542), -- Archmage Lan'dalock, Surgical Strike
(70517, 32567), -- Archmage Lan'dalock, The Beast Pens
(70520, 32293), -- Halduron Brightwing, Among the Bones
(70520, 32520), -- Halduron Brightwing, Competing Magic
(70520, 32561), -- Halduron Brightwing, Competing Magic
(70520, 32200), -- Halduron Brightwing, Dangers of Za'Tual
(70520, 32521), -- Halduron Brightwing, Encroaching Force
(70520, 32252), -- Halduron Brightwing, Harbingers of the Loa
(70520, 32522), -- Halduron Brightwing, Imposing Threat
(70520, 32562), -- Halduron Brightwing, Imposing Threat
(70520, 32275), -- Halduron Brightwing, Surgical Death
(70520, 32523), -- Halduron Brightwing, The Beast Pens
(70520, 32524), -- Halduron Brightwing, The Beating of Troll Drums
(70751, 32851), -- Card Trader Ami, Blingtron 3000
(70751, 32849), -- Card Trader Ami, Dippy and Doopy
(70751, 32837), -- Card Trader Ami, Grandpa Grumplefloot
(70751, 32841), -- Card Trader Ami, Master Boom Boom
(70751, 32847), -- Card Trader Ami, Mecha-Bruce
(70751, 32853), -- Card Trader Ami, Mingus Diggs
(70751, 32843), -- Card Trader Ami, Razorgrin
(70751, 32857), -- Card Trader Ami, Ro-Shambo
(70751, 32845), -- Card Trader Ami, Splat
(70751, 32839), -- Card Trader Ami, The Bear and the Lady Fair
(70751, 32855), -- Card Trader Ami, The Blind Hero
(70751, 32859), -- Card Trader Ami, Ty'thar
(70752, 32851), -- Card Trader Leila, Blingtron 3000
(70752, 32849), -- Card Trader Leila, Dippy and Doopy
(70752, 32837), -- Card Trader Leila, Grandpa Grumplefloot
(70752, 32841), -- Card Trader Leila, Master Boom Boom
(70752, 32847), -- Card Trader Leila, Mecha-Bruce
(70752, 32853), -- Card Trader Leila, Mingus Diggs
(70752, 32843), -- Card Trader Leila, Razorgrin
(70752, 32857), -- Card Trader Leila, Ro-Shambo
(70752, 32845), -- Card Trader Leila, Splat
(70752, 32839), -- Card Trader Leila, The Bear and the Lady Fair
(70752, 32855), -- Card Trader Leila, The Blind Hero
(70752, 32859), -- Card Trader Leila, Ty'thar
(70980, 32816), -- Seer Hao Pham Roo, Path of the Last Emperor
(72426, 33020), -- Lin Chao-Wei, The Lost Secret of the Secret Ingredient
(72751, 32975), -- Mound of Dirt, Rolo's Riddle
(72754, 32976), -- Mound of Dirt, Rolo's Riddle
(72870, 33161), -- Kairoz, A Timeless Tour
(72870, 33337), -- Kairoz, A Vision in Time
(72870, 33378), -- Kairoz, Courting Destiny
(72870, 33338), -- Kairoz, Empowering the Hourglass
(72870, 33377), -- Kairoz, Hidden Threads
(72870, 33332), -- Kairoz, Hints From The Past
(72870, 33379), -- Kairoz, One Final Turn
(72870, 33375), -- Kairoz, Refining The Vision
(72870, 33376), -- Kairoz, Seeking Fate
(72870, 33334), -- Kairoz, Strong Enough To Survive
(72870, 33336), -- Kairoz, The Essence of Time
(72870, 33335), -- Kairoz, The Last Emperor
(72870, 33228), -- Kairoz, Time In Your Hands
(72870, 33333), -- Kairoz, Timeless Treasures
(73082, 33137), -- Master Li, The Celestial Tournament
(73082, 33136), -- Master Li, The Rainy Day is Here
(73303, 33342), -- Emperor Shaohao, Drive Back The Flame
(73303, 33374), -- Emperor Shaohao, Path of the Mistwalker
(73303, 33343), -- Emperor Shaohao, The Archiereus Of Flame
(73303, 33340), -- Emperor Shaohao, Timeless Nutriment
(73303, 33341), -- Emperor Shaohao, Wayshrines Of The Celestials
(73318, 33138), -- Lorewalker Cho, Why Do We Fight?
(73335, 33147), -- Fading Breath, The Last Gasp of Y'Shaarj
(73348, 33160), -- Watcher Lara, Time Keeper Kairoz
(73353, 33156), -- Watcher Alundra, Time Keeper Kairoz
(73570, 33211), -- Senior Historian Evelyna, A Timeless Question
(73626, 33222), -- Little Tommy Newcomer, Little Tommy Newcomer
(73657, 33235), -- Great Chef Woo, Great Turtle Meat
(73657, 33236), -- Great Chef Woo, Heavy Yak Flank
(73657, 33234), -- Great Chef Woo, Meaty Crane Leg
(73657, 33239), -- Great Chef Woo, Pristine Firestorm Egg
(73657, 33238), -- Great Chef Woo, Thick Tiger Haunch
(73691, 33231), -- Chromie, Journey to the Timeless Isle
(73691, 33232); -- Chromie, Journey to the Timeless Isle

INSERT INTO `creature_questender` VALUES
(43929, 31752), -- Blingtron 4000, Blingtron 4000
(54614, 29552), -- Mishka, Critical Condition
(54615, 29556), -- Nodd Codejack, Hozen Aren't Your Friends, Hozen Are Your Enemies
(54615, 29555), -- Nodd Codejack, The White Pawn
(54616, 31742), -- Sully "The Pickle" McLeary, Fractured Forces
(54616, 31743), -- Sully "The Pickle" McLeary, Smoke Before Fire
(54616, 31733), -- Sully "The Pickle" McLeary, Touching Ground
(54616, 31741), -- Sully "The Pickle" McLeary, Twinspire Keep
(54616, 31744), -- Sully "The Pickle" McLeary, Unfair Trade
(54617, 30069), -- Rell Nightwind, No Plan Survives Contact with the Enemy
(54617, 30070), -- Rell Nightwind, The Fall of Ga'trul
(54617, 31735), -- Rell Nightwind, The Right Tool For The Job
(54617, 31734), -- Rell Nightwind, Welcome Wagons
(54697, 29576), -- Shao the Defiant, An Air of Worry
(54697, 29578), -- Shao the Defiant, Defiance
(54697, 29579), -- Shao the Defiant, Rally the Survivors
(54854, 29580), -- Gentle Mother Hanae, Orchard-Supplied Hardware
(54854, 29585), -- Gentle Mother Hanae, Spitfire
(54870, 29611), -- General Nazgrim, The Art of War
(54870, 29612), -- General Nazgrim, The Art of War
(54913, 29619), -- Lin Tenderpaw, A Courteous Guest
(54913, 29617), -- Lin Tenderpaw, Tian Monastery
(54915, 29627), -- Groundskeeper Wu, A Proper Weapon
(54915, 29629), -- Groundskeeper Wu, A Steady Hand
(54915, 29628), -- Groundskeeper Wu, A Strong Back
(54915, 29630), -- Groundskeeper Wu, And a Heavy Fist
(54915, 29626), -- Groundskeeper Wu, Groundskeeper Wu
(54917, 29624), -- Instructor Xann, Attention
(54917, 29623), -- Instructor Xann, Perfection
(54917, 29622), -- Instructor Xann, Your Training Starts Now
(54918, 29636), -- Instructor Myang, A Test of Endurance
(54918, 29637), -- Instructor Myang, The Rumpus
(54922, 29632), -- Master Stone Fist, Becoming Battle-Ready
(54922, 29634), -- Master Stone Fist, Husshun, the Wizened
(54922, 29635), -- Master Stone Fist, Xiao, the Eater
(54922, 29633), -- Master Stone Fist, Zhi-Zhi, the Dextrous
(54960, 29906), -- Elder Lusshan, Carp Diem
(54960, 29905), -- Elder Lusshan, Let Them Burn
(54961, 29889), -- Lorewalker Cho, Borrowed Brew
(55009, 29670), -- Shao the Defiant, Maul Gormal
(55009, 29586), -- Shao the Defiant, The Splintered Path
(55009, 29587), -- Shao the Defiant, Unbound
(55054, 31853), -- General Nazgrim, All Aboard!
(55094, 29631), -- Guard Shan Long, Burning Bright
(55122, 30498), -- Admiral Taylor, Get Back Here!
(55122, 30568), -- Admiral Taylor, Helping the Cause
(55135, 29690), -- General Nazgrim, Into the Mists
(55172, 31999), -- General Nazgrim, Nazgrim's Command
(55180, 29827), -- Shademaster Kiryn, Acid Rain
(55180, 29815), -- Shademaster Kiryn, Forensic Science
(55196, 29560), -- Bold Karasshi, Ancient Power
(55196, 29559), -- Bold Karasshi, Freeing Our Brothers
(55196, 29759), -- Bold Karasshi, Kung Din
(55196, 29558), -- Bold Karasshi, The Path of War
(55234, 29717), -- An Windfur, Down Kitty!
(55234, 29716), -- An Windfur, The Double Hozen Dare
(55274, 29717), -- An Windfur, Down Kitty!
(55274, 29716), -- An Windfur, The Double Hozen Dare
(55282, 29725), -- Sully "The Pickle" McLeary, SI:7 Report: Fire From the Sky
(55283, 29727), -- Amber Kearnen, SI:7 Report: Take No Prisoners
(55284, 29726), -- Little Lu, SI:7 Report: Hostile Natives
(55333, 29733), -- Rell Nightwind, SI:7 Report: Lost in the Woods
(55403, 29765), -- Zin'Jun, Cryin' My Eyes Out
(55403, 31774), -- Zin'Jun, Seeking Zin'jun
(55497, 29765), -- Zin'Jun, Cryin' My Eyes Out
(55521, 31777), -- Rivett Clutchpop, Choppertunity
(55521, 31112), -- Rivett Clutchpop, They're So Thorny!
(55614, 29756), -- Pei-Zhi, A Humble Offering
(55614, 29749), -- Pei-Zhi, An Urgent Plea
(55614, 29753), -- Pei-Zhi, Back to Nature
(55614, 29751), -- Pei-Zhi, Ritual Artifacts
(55614, 29752), -- Pei-Zhi, The Wayward Dead
(55614, 29750), -- Pei-Zhi, Vessels of the Spirit
(55646, 29731), -- Shademaster Kiryn, Scouting Report: On the Right Track
(55647, 29824), -- Shokia, Scouting Report: Like Jinyu in a Barrel
(55647, 29971), -- Shokia, The Scouts Return
(55648, 29730), -- Riko, Scouting Report: Hostile Natives
(55648, 29823), -- Riko, Scouting Report: The Friend of My Enemy
(55768, 29822), -- Lorewalker Cho, Lay of the Land
(55768, 31121), -- Lorewalker Cho, Stay a While, and Listen
(55789, 29547), -- Rell Nightwind, The King's Command
(56062, 29865), -- Tzu the Ironbelly, The Silkwood Road
(56063, 31691), -- Inkmaster Jo Po, Inscribed Crane Staff
(56063, 29882), -- Inkmaster Jo Po, Quill of Stingers
(56064, 31690), -- Inkmaster Glenzu, Inscribed Tiger Staff
(56064, 29881), -- Inkmaster Glenzu, The Perfect Color
(56065, 31539), -- Inkmaster Wei, A Thing of Beauty
(56065, 29993), -- Inkmaster Wei, Find the Boy
(56065, 31692), -- Inkmaster Wei, Inscribed Serpent Staff
(56065, 31876), -- Inkmaster Wei, The Inkmasters of the Arboretum
(56110, 30086), -- Xiao, The Search for the Hidden Master
(56111, 29872), -- Lin Tenderpaw, Lin Tenderpaw
(56111, 29992), -- Lin Tenderpaw, Tenderpaw By Name, Tender Paw By Reputation
(56112, 29875), -- Kang Bramblestaff, Kang Bramblestaff
(56112, 30230), -- Kang Bramblestaff, Re-Reclaim
(56112, 30123), -- Kang Bramblestaff, Skitterer Stew
(56113, 29871), -- Clever Ashyo, Clever Ashyo
(56114, 29874), -- Kang Bramblestaff, Kang Bramblestaff
(56114, 30351), -- Kang Bramblestaff, Lotus Tea
(56114, 30355), -- Kang Bramblestaff, Re-Reclaim
(56114, 30350), -- Kang Bramblestaff, Squirmy Delight
(56115, 30089), -- Ken-Ken, Apply Directly to the Forehead
(56115, 29873), -- Ken-Ken, Ken-Ken
(56115, 30081), -- Ken-Ken, Materia Medica
(56115, 30079), -- Ken-Ken, What's Eating Zhu's Watch?
(56115, 30088), -- Ken-Ken, Why So Serious?
(56115, 30090), -- Ken-Ken, Zhu's Despair
(56133, 30172), -- Chen Stormstout, Barreling Along
(56133, 29952), -- Chen Stormstout, Broken Dreams
(56133, 30046), -- Chen Stormstout, Chen's Resolution
(56133, 30078), -- Chen Stormstout, Cleaning House
(56133, 30075), -- Chen Stormstout, Clear the Way
(56133, 32018), -- Chen Stormstout, His Name Was... Stormstout
(56133, 38935), -- Chen Stormstout, His Name Was... Stormstout
(56133, 30074), -- Chen Stormstout, Knocking on the Door
(56133, 29944), -- Chen Stormstout, Leaders Among Breeders
(56133, 30055), -- Chen Stormstout, Stormstout's Hops
(56133, 30047), -- Chen Stormstout, The Chen Taste Test
(56133, 30073), -- Chen Stormstout, The Emperor
(56133, 29946), -- Chen Stormstout, The Warren-Mother
(56133, 32019), -- Chen Stormstout, They Call Him... Stormstout
(56138, 30077), -- Li Li, Barrels, Man
(56138, 29947), -- Li Li, Crouching Carrot, Hidden Turnip
(56138, 29949), -- Li Li, Legacy
(56138, 30048), -- Li Li, Li Li and the Grain
(56138, 29950), -- Li Li, Li Li's Day Off
(56138, 30031), -- Li Li, Taste Test
(56138, 30032), -- Li Li, The Quest for Better Barley
(56138, 29945), -- Li Li, Yellow and Red Make Orange
(56204, 29908), -- Pang Thunderfoot, A Seemingly Endless Nuisance
(56204, 29907), -- Pang Thunderfoot, Chen and Li Li
(56204, 29911), -- Pang Thunderfoot, Practically Perfect Produce
(56205, 29914), -- Liang Thunderfoot, Back to the Sty
(56205, 29912), -- Liang Thunderfoot, The Fabulous Miss Fanny
(56205, 29913), -- Liang Thunderfoot, The Meat They'll Eat
(56207, 29909), -- Ang Thunderfoot, Low Turnip Turnout
(56207, 29940), -- Ang Thunderfoot, Taking a Crop
(56208, 29915), -- Francis the Shepherd Boy, A Neighbor's Duty
(56208, 29917), -- Francis the Shepherd Boy, Lupello
(56208, 29916), -- Francis the Shepherd Boy, Piercing Talons and Slavering Jaws
(56222, 29762), -- Bold Karasshi, Family Heirlooms
(56222, 29562), -- Bold Karasshi, Jailbreak
(56222, 29894), -- Bold Karasshi, Spirits of the Water
(56287, 31130), -- Lorewalker Cho, A Visit with Lorewalker Cho
(56287, 29892), -- Lorewalker Cho, Body
(56287, 29893), -- Lorewalker Cho, Hue
(56287, 29891), -- Lorewalker Cho, Potency
(56312, 29918), -- Shang Thunderfoot, A Lesson in Bravery
(56313, 29879), -- Tooki Tooki, Swallowed Whole
(56336, 31261), -- Chief Kah Kah, Captain Jack's Dead
(56336, 29935), -- Chief Kah Kah, Orders are Orders
(56336, 29933), -- Chief Kah Kah, The Bees' Knees
(56336, 31239), -- Chief Kah Kah, What's in a Name Name?
(56336, 31241), -- Chief Kah Kah, Wicked Wikkets
(56339, 29941), -- General Nazgrim, Beyond the Horizon
(56339, 29966), -- General Nazgrim, Burning Down the House
(56339, 29943), -- General Nazgrim, Guerrillas in our Midst
(56339, 29936), -- General Nazgrim, Instant Messaging
(56346, 29926), -- Foreman Mann, Calamity Jade
(56346, 29928), -- Foreman Mann, I Have No Jade And I Must Scream
(56346, 29930), -- Foreman Mann, What's Mined Is Yours
(56347, 29927), -- Hao Mann, Mann's Man
(56348, 31230), -- Toya, Welcome to Dawn's Blossom
(56358, 29942), -- Eekle Eekle, Silly Wikket, Slickies are for Hozen
(56406, 29939), -- Rivett Clutchpop, Boom Bait
(56406, 29937), -- Rivett Clutchpop, Furious Fowl
(56406, 29968), -- Rivett Clutchpop, Green-ish Energy
(56432, 29900), -- Ren Whitepaw, An Ancient Legend
(56432, 29899), -- Ren Whitepaw, Rest in Peace
(56433, 29898), -- Lina Whitepaw, Sacred Waters
(56434, 29890), -- Anduin Wrynn, Finding Your Center
(56440, 29877), -- Muno the Farmhand, A Poor Grasp of the Basics
(56465, 29910), -- Ana Thunderfoot, Rampaging Rodents
(56467, 29929), -- Hao Mann, Trapped!
(56474, 30049), -- Mudmug, Doesn't Hold Water
(56474, 29919), -- Mudmug, Great Minds Drink Alike
(56474, 29951), -- Mudmug, Muddy Water
(56474, 30076), -- Mudmug, The Fanciest Water
(56474, 30051), -- Mudmug, The Great Water Hunt
(56474, 29948), -- Mudmug, Thieves to the Core
(56490, 29943), -- General Nazgrim, Guerrillas in our Midst
(56708, 29995), -- Syra Goldendraft, Shrine of the Dawn
(56714, 29988), -- Master Bruised Paw, A Taste For Eggs
(56714, 29986), -- Master Bruised Paw, Fog Wards
(56714, 29983), -- Master Bruised Paw, The Hidden Master
(56714, 29985), -- Master Bruised Paw, They Will Be Mist
(56714, 29984), -- Master Bruised Paw, Unyielding Fists: Trial of Bamboo
(56714, 29989), -- Master Bruised Paw, Unyielding Fists: Trial of Stone
(56714, 29987), -- Master Bruised Paw, Unyielding Fists: Trial of Wood
(56720, 29982), -- Loon Mai, Evacuation Orders
(56720, 30376), -- Loon Mai, Hope Springs Eternal
(56720, 30626), -- Loon Mai, Retreat!
(56720, 29981), -- Loon Mai, Stemming the Swarm
(56720, 30117), -- Loon Mai, Stoneplow Thirsts
(56720, 30627), -- Loon Mai, The Savior of Stoneplow
(56720, 29990), -- Loon Mai, Training and Discipline
(56720, 30241), -- Loon Mai, Warn Stoneplow
(56720, 30360), -- Loon Mai, Warn Stoneplow
(56773, 30275), -- Yan, A Crocolisk Tale
(56773, 29757), -- Yan, Bottletoads
(56773, 29758), -- Yan, Guess Whose Back
(56773, 29581), -- Yan, The Golden Dream
(56782, 30011), -- Elder Sage Rain-Zhu, A New Vision
(56782, 30004), -- Elder Sage Rain-Zhu, Everything In Its Place
(56782, 29932), -- Elder Sage Rain-Zhu, The Temple of the Jade Serpent
(56784, 30005), -- Fei, Lighting Up the Sky
(56784, 29999), -- Fei, The Rider's Bind
(56786, 30001), -- Lorewalker Stonestep, Moth-Ridden
(56786, 30002), -- Lorewalker Stonestep, Pages of History
(56786, 29998), -- Lorewalker Stonestep, The Librarian's Quandary
(56787, 29997), -- Wise Mari, The Scryer's Dilemma
(56802, 29577), -- Zhang Yue, Ashyo's Vision
(56802, 29600), -- Zhang Yue, Snap Judgment
(57108, 30484), -- General Nazgrim, Gauging Our Progress
(57108, 30499), -- General Nazgrim, Get Back Here!
(57108, 30466), -- General Nazgrim, Sufficient Motivation
(57198, 30625), -- Guard Captain Oakenshield, Students No More
(57198, 30622), -- Guard Captain Oakenshield, The Swarm Begins
(57209, 30030), -- Grainer Pan, Out of Sprite
(57211, 30028), -- Grainlord Kai, Grain Recovery
(57211, 30029), -- Grainlord Kai, Wee Little Shenanigans
(57242, 30000), -- Elder Sage Wind-Yi, The Jade Serpent
(57298, 30419), -- Farmer Fung, A Blue Feather for Farmer Fung
(57298, 30421), -- Farmer Fung, A Dish for Farmer Fung
(57298, 30475), -- Farmer Fung, A Gift For Fung
(57298, 30418), -- Farmer Fung, A Jade Cat for Farmer Fung
(57298, 30417), -- Farmer Fung, A Lovely Apple for Farmer Fung
(57298, 30420), -- Farmer Fung, A Marsh Lily for Farmer Fung
(57298, 30416), -- Farmer Fung, A Ruby Shard for Farmer Fung
(57298, 30517), -- Farmer Fung, Farmer Fung's Vote I: Yak Attack
(57298, 30518), -- Farmer Fung, Farmer Fung's Vote II: On the Loose
(57298, 31947), -- Farmer Fung, Farmer Fung's Vote III: Crazy For Cabbage
(57298, 30317), -- Farmer Fung, Water, Water Everywhere
(57319, 30063), -- Elder Sage Storm-Sing, Behind the Masks
(57319, 30064), -- Elder Sage Storm-Sing, Saving the Sutras
(57324, 30065), -- Elder Sage Tai-Feng, Arrows of Fortune
(57324, 31376), -- Elder Sage Tai-Feng, Attack At The Temple of the Jade Serpent
(57324, 31377), -- Elder Sage Tai-Feng, Attack At The Temple of the Jade Serpent
(57324, 30068), -- Elder Sage Tai-Feng, Flames of the Void
(57324, 30066), -- Elder Sage Tai-Feng, Hidden Power
(57324, 30006), -- Elder Sage Tai-Feng, The Darkness Around Us
(57324, 30067), -- Elder Sage Tai-Feng, The Shadow of Doubt
(57385, 30516), -- Gai Lan, Growing the Farm I: A Little Problem
(57385, 30260), -- Gai Lan, Growing the Farm I: The Weeds
(57385, 30052), -- Gai Lan, Weed War
(57401, 30054), -- Mung-Mung, Enough is Ookin' Enough
(57401, 30258), -- Mung-Mung, Mung-Mung's Vote I: A Hozen's Problem
(57401, 30259), -- Mung-Mung, Mung-Mung's Vote II: Rotten to the Core
(57401, 31946), -- Mung-Mung, Mung-Mung's Vote III: The Great Carrot Caper
(57402, 30412), -- Haohan Mudclaw, A Blue Feather for Haohan
(57402, 30414), -- Haohan Mudclaw, A Dish for Haohan
(57402, 30477), -- Haohan Mudclaw, A Gift For Haohan
(57402, 30411), -- Haohan Mudclaw, A Jade Cat for Haohan
(57402, 30410), -- Haohan Mudclaw, A Lovely Apple for Haohan
(57402, 30413), -- Haohan Mudclaw, A Marsh Lily for Haohan
(57402, 30409), -- Haohan Mudclaw, A Ruby Shard for Haohan
(57402, 30529), -- Haohan Mudclaw, Growing the Farm III: The Mossy Boulder
(57402, 30521), -- Haohan Mudclaw, Haohan's Vote I: Bungalow Break-In
(57402, 30319), -- Haohan Mudclaw, Pest Problems
(57405, 32035), -- Silkmaster Tsai, Got Silk?
(57405, 30072), -- Silkmaster Tsai, Where Silk Comes From
(57407, 30058), -- Master Goh, Mothallus!
(57408, 30056), -- Mina Mudclaw, The Farmer's Daughter
(57424, 30059), -- Journeyman Chu, The Moth Rebellion
(57744, 30084), -- Mei Barrelbottom, Borderlands
(57744, 30082), -- Mei Barrelbottom, Cheer Up, Yi-Mo
(57744, 30083), -- Mei Barrelbottom, Securing the Province
(57744, 30091), -- Mei Barrelbottom, Tears of Pandaria
(58113, 30130), -- Sunwalker Dezco, Herbal Remedies
(58113, 30131), -- Sunwalker Dezco, Life
(58113, 30179), -- Sunwalker Dezco, Poisoned!
(58113, 30128), -- Sunwalker Dezco, The Pools of Youth
(58114, 30124), -- Kor Bloodtusk, Blind Them!
(58114, 30163), -- Kor Bloodtusk, For the Tribe
(58114, 30132), -- Kor Bloodtusk, Going West
(58114, 30464), -- Kor Bloodtusk, Going West
(58114, 30229), -- Kor Bloodtusk, The Greater Danger
(58114, 30127), -- Kor Bloodtusk, Threat from Dojan
(58160, 30121), -- Chezin Dawnchaser, Search Party
(58206, 30129), -- Kang Bramblestaff, The Mogu Agenda
(58225, 30135), -- Instructor Tong, Beating the Odds
(58225, 30138), -- Instructor Tong, Choosing the One
(58225, 30137), -- Instructor Tong, Egg Collection
(58225, 30136), -- Instructor Tong, Empty Nests
(58225, 30134), -- Instructor Tong, Wild Things
(58228, 30142), -- Instructor Skythorn, It's A...
(58228, 31373), -- Instructor Skythorn, The Order of the Cloud Serpent
(58228, 31375), -- Instructor Skythorn, The Order of the Cloud Serpent
(58228, 30139), -- Instructor Skythorn, The Rider's Journey
(58228, 30140), -- Instructor Skythorn, The Rider's Journey
(58228, 30141), -- Instructor Skythorn, The Rider's Journey
(58278, 30169), -- Tired Shushen, Raid Leader Slovan
(58278, 30168), -- Tired Shushen, Thieving Raiders
(58376, 30080), -- Yi-Mo Longbrow, Finding Yi-Mo
(58384, 31704), -- Azure Hatchling, Pooped
(58384, 30150), -- Azure Hatchling, Sweet as Honey
(58413, 30149), -- Jenova Longeye, A Feast for the Senses
(58413, 30147), -- Jenova Longeye, Fragments of the Past
(58413, 30148), -- Jenova Longeye, Just a Flesh Wound
(58413, 30146), -- Jenova Longeye, Snack Time
(58420, 30145), -- Instructor Windblade, Flight Training: Full Speed Ahead
(58420, 30187), -- Instructor Windblade, Flight Training: In Due Course
(58420, 30144), -- Instructor Windblade, Flight Training: Ring Round-Up
(58420, 30143), -- Instructor Windblade, They Grow Like Weeds
(58421, 30184), -- Hemet Nesingwary, Mushan Mastery: Darkhide
(58421, 30186), -- Hemet Nesingwary, Parental Mastery
(58422, 30181), -- Hemet Nesingwary Jr., Mushan Mastery
(58422, 30185), -- Hemet Nesingwary Jr., Tortoise Mastery
(58434, 32038), -- Matt "Lucky" Gotcher, Stag Mastery
(58506, 31713), -- Ace Longpaw, The Big Brew-haha
(58547, 30133), -- Koro Mistwalker, Into the Wilds
(58547, 30178), -- Koro Mistwalker, Into the Wilds
(58547, 30461), -- Koro Mistwalker, Into the Wilds
(58547, 30462), -- Koro Mistwalker, Into the Wilds
(58564, 31707), -- Elder Anli, A Tangled Web
(58564, 33250), -- Elder Anli, A Time-Lost Treasure
(58564, 30151), -- Elder Anli, Catch!
(58564, 31701), -- Elder Anli, Dark Huntress
(58564, 30158), -- Elder Anli, Disarming the Enemy
(58564, 30157), -- Elder Anli, Emptier Nests
(58564, 30156), -- Elder Anli, Feeding Time
(58564, 31709), -- Elder Anli, Lingering Doubt
(58564, 31703), -- Elder Anli, Madcap Mayhem
(58564, 31712), -- Elder Anli, Monkey Mischief
(58564, 31705), -- Elder Anli, Needle Me Not
(58564, 31702), -- Elder Anli, On The Prowl
(58564, 31784), -- Elder Anli, Onyx To Goodness
(58564, 30159), -- Elder Anli, Preservation
(58564, 30155), -- Elder Anli, Restoring the Balance
(58564, 30188), -- Elder Anli, Riding the Skies
(58564, 31810), -- Elder Anli, Riding the Skies
(58564, 31811), -- Elder Anli, Riding the Skies
(58564, 31714), -- Elder Anli, Saving the Serpents
(58564, 31194), -- Elder Anli, Slitherscale Suppression
(58564, 31699), -- Elder Anli, Sprite Fright
(58564, 31715), -- Elder Anli, The Big Kah-Oona
(58564, 30154), -- Elder Anli, The Easiest Way To A Serpent's Heart
(58564, 31711), -- Elder Anli, The Seed of Doubt
(58564, 31700), -- Elder Anli, The Shoe Is On The Other Foot
(58564, 30152), -- Elder Anli, The Sky Race
(58564, 31717), -- Elder Anli, The Trainer's Challenge: Ace Longpaw
(58564, 31718), -- Elder Anli, The Trainer's Challenge: Big Bao
(58564, 31719), -- Elder Anli, The Trainer's Challenge: Ningna Darkwheel
(58564, 31721), -- Elder Anli, The Trainer's Challenge: Qua-Ro Whitebrow
(58564, 31720), -- Elder Anli, The Trainer's Challenge: Suchi the Sweet
(58564, 31698), -- Elder Anli, Thinning The Pack
(58564, 31706), -- Elder Anli, Weeping Widows
(58607, 30174), -- Sunwalker Dezco, For Family
(58607, 30164), -- Sunwalker Dezco, The Stoneplow Convoy
(58609, 30268), -- Anduin Wrynn, The Murksweats
(58646, 31937), -- Farmer Yoon, "Thunder King" Pest Repellers
(58646, 30252), -- Farmer Yoon, A Helping Hand
(58646, 31672), -- Farmer Yoon, A Pumpkin-y Perfume
(58646, 30522), -- Farmer Yoon, Haohan's Vote II: The Real Culprits
(58646, 30525), -- Farmer Yoon, Haohan's Vote III: Pure Poison
(58646, 30527), -- Farmer Yoon, Haohan's Vote IV: Melons For Felons
(58646, 30528), -- Farmer Yoon, Haohan's Vote V: Chief Yip-Yip
(58646, 31942), -- Farmer Yoon, It's Melon Time
(58646, 30535), -- Farmer Yoon, Learn and Grow I: Seeds
(58646, 30254), -- Farmer Yoon, Learn and Grow II: Tilling and Planting
(58646, 30255), -- Farmer Yoon, Learn and Grow III: Tending Crops
(58646, 30256), -- Farmer Yoon, Learn and Grow IV: Harvesting
(58646, 31673), -- Farmer Yoon, Red Blossom Leeks, You Make the Croc-in' World Go Down
(58646, 30337), -- Farmer Yoon, Simian Sabotage
(58646, 31941), -- Farmer Yoon, Squash Those Foul Odors
(58646, 30335), -- Farmer Yoon, Stalling the Ravage
(58646, 30334), -- Farmer Yoon, Stealing is Bad... Re-Stealing is OK
(58646, 31670), -- Farmer Yoon, That Dangling Carrot
(58646, 31938), -- Farmer Yoon, The "Earth-Slasher" Master Plow
(58646, 31936), -- Farmer Yoon, The "Jinyu Princess" Irrigation System
(58646, 31669), -- Farmer Yoon, The Cabbage Test
(58646, 30336), -- Farmer Yoon, The Kunzen Hunter-Chief
(58646, 30333), -- Farmer Yoon, The Lesser of Two Evils
(58646, 31674), -- Farmer Yoon, The Pink Turnip Challenge
(58646, 31675), -- Farmer Yoon, The White Turnip Treatment
(58646, 31943), -- Farmer Yoon, Which Berries? Witchberries.
(58646, 31671), -- Farmer Yoon, Why Not Scallions?
(58647, 30382), -- Ella, A Blue Feather for Ella
(58647, 30386), -- Ella, A Dish for Ella
(58647, 30474), -- Ella, A Gift For Ella
(58647, 30381), -- Ella, A Jade Cat for Ella
(58647, 30189), -- Ella, A Lovely Apple for Ella
(58647, 30383), -- Ella, A Marsh Lily for Ella
(58647, 30160), -- Ella, A Ruby Shard for Ella
(58647, 31538), -- Ella, A Worthy Brew
(58647, 31537), -- Ella, Ella's Taste Test
(58647, 31534), -- Ella, The Beginner's Brew
(58647, 30327), -- Ella, You Have to Burn the Ropes
(58704, 30261), -- Kelari Featherfoot, Roll Club: Serpent's Spine
(58705, 30425), -- Fish Fellreed, A Blue Feather for Fish
(58705, 30427), -- Fish Fellreed, A Dish for Fish
(58705, 30473), -- Fish Fellreed, A Gift For Fish
(58705, 30424), -- Fish Fellreed, A Jade Cat for Fish
(58705, 30423), -- Fish Fellreed, A Lovely Apple for Fish
(58705, 30426), -- Fish Fellreed, A Marsh Lily for Fish
(58705, 30422), -- Fish Fellreed, A Ruby Shard for Fish
(58705, 30524), -- Fish Fellreed, Growing the Farm II: Knock on Wood
(58705, 30523), -- Fish Fellreed, Growing the Farm II: The Broken Wagon
(58705, 31313), -- Fish Fellreed, Just A Folk Story
(58705, 30326), -- Fish Fellreed, The Kunzen Legend-Chief
(58705, 31312), -- Fish Fellreed, The Old Map
(58706, 30388), -- Gina Mudclaw, A Blue Feather for Gina
(58706, 30390), -- Gina Mudclaw, A Dish for Gina
(58706, 30479), -- Gina Mudclaw, A Gift For Gina
(58706, 30387), -- Gina Mudclaw, A Jade Cat for Gina
(58706, 30380), -- Gina Mudclaw, A Lovely Apple for Gina
(58706, 30389), -- Gina Mudclaw, A Marsh Lily for Gina
(58706, 30379), -- Gina Mudclaw, A Ruby Shard for Gina
(58706, 30257), -- Gina Mudclaw, Learn and Grow V: Halfhill Market
(58706, 31945), -- Gina Mudclaw, Learn and Grow VI: Gina's Vote
(58706, 30322), -- Gina Mudclaw, Money Matters
(58707, 30394), -- Old Hillpaw, A Blue Feather for Old Hillpaw
(58707, 30396), -- Old Hillpaw, A Dish for Old Hillpaw
(58707, 30476), -- Old Hillpaw, A Gift For Old Hillpaw
(58707, 30393), -- Old Hillpaw, A Jade Cat for Old Hillpaw
(58707, 30392), -- Old Hillpaw, A Lovely Apple for Old Hillpaw
(58707, 30395), -- Old Hillpaw, A Marsh Lily for Old Hillpaw
(58707, 30391), -- Old Hillpaw, A Ruby Shard for Old Hillpaw
(58707, 30318), -- Old Hillpaw, Chasing the Chicken
(58708, 30406), -- Sho, A Blue Feather for Sho
(58708, 30408), -- Sho, A Dish for Sho
(58708, 30472), -- Sho, A Gift For Sho
(58708, 30405), -- Sho, A Jade Cat for Sho
(58708, 30404), -- Sho, A Lovely Apple for Sho
(58708, 30407), -- Sho, A Marsh Lily for Sho
(58708, 30403), -- Sho, A Ruby Shard for Sho
(58708, 31531), -- Sho, Mission: Aerial Threat
(58708, 31529), -- Sho, Mission: Culling The Vermin
(58708, 31532), -- Sho, Mission: Predator of the Cliffs
(58708, 30325), -- Sho, Where It Counts
(58709, 30400), -- Chee Chee, A Blue Feather for Chee Chee
(58709, 30402), -- Chee Chee, A Dish for Chee Chee
(58709, 30471), -- Chee Chee, A Gift For Chee Chee
(58709, 30399), -- Chee Chee, A Jade Cat for Chee Chee
(58709, 30398), -- Chee Chee, A Lovely Apple for Chee Chee
(58709, 30401), -- Chee Chee, A Marsh Lily for Chee Chee
(58709, 30397), -- Chee Chee, A Ruby Shard for Chee Chee
(58709, 31341), -- Chee Chee, A Wolf In Sheep's Clothing
(58709, 31338), -- Chee Chee, Lost Sheepie
(58709, 31339), -- Chee Chee, Lost Sheepie... Again
(58709, 30324), -- Chee Chee, Not in Chee-Chee's Backyard
(58709, 31340), -- Chee Chee, Oh Sheepie...
(58710, 30437), -- Jogu the Drunk, A Blue Feather for Jogu
(58710, 30439), -- Jogu the Drunk, A Dish for Jogu
(58710, 30478), -- Jogu the Drunk, A Gift For Jogu
(58710, 30436), -- Jogu the Drunk, A Jade Cat for Jogu
(58710, 30435), -- Jogu the Drunk, A Lovely Apple for Jogu
(58710, 30438), -- Jogu the Drunk, A Marsh Lily for Jogu
(58710, 30434), -- Jogu the Drunk, A Ruby Shard for Jogu
(58710, 31323), -- Jogu the Drunk, Buy A Fish A Brewery?
(58710, 31320), -- Jogu the Drunk, Buy A Fish A Drink?
(58710, 31322), -- Jogu the Drunk, Buy A Fish A Keg?
(58710, 31321), -- Jogu the Drunk, Buy A Fish A Round?
(58710, 30321), -- Jogu the Drunk, Weed War II
(58712, 30332), -- Kol Ironpaw, Fatty Goatsteak
(58712, 31467), -- Kol Ironpaw, Strong as a Tiger
(58712, 31311), -- Kol Ironpaw, Way of the Grill
(58713, 31471), -- Anthea Ironpaw, Agile as a Tiger
(58713, 30329), -- Anthea Ironpaw, Cindergut Peppers
(58713, 31470), -- Anthea Ironpaw, Way of the Wok
(58714, 30331), -- Mei Mei Ironpaw, The Mile-High Grub
(58714, 31474), -- Mei Mei Ironpaw, The Soup of Contemplation
(58714, 31472), -- Mei Mei Ironpaw, Way of the Pot
(58715, 31476), -- Yan Ironpaw, The Spirit of Cooking
(58715, 30328), -- Yan Ironpaw, The Thousand-Year Dumpling
(58715, 31475), -- Yan Ironpaw, Way of the Steamer
(58716, 31477), -- Jian Ironpaw, Endurance
(58716, 30330), -- Jian Ironpaw, The Truffle Shuffle
(58716, 31478), -- Jian Ironpaw, Way of the Oven
(58717, 31480), -- Bobo Ironpaw, Have a Drink
(58717, 31479), -- Bobo Ironpaw, Way of the Brew
(58721, 31372), -- Farmer Yoon, The Tillers
(58721, 31374), -- Farmer Yoon, The Tillers
(58735, 30384), -- Lyalia, Blind Them!
(58735, 30349), -- Lyalia, Threat from Dojan
(58736, 30267), -- Gladecaster Lang, Watery Woes
(58743, 30242), -- Yumi Goldenpaw, Survival Ring: Blades
(58743, 30240), -- Yumi Goldenpaw, Survival Ring: Flame
(58745, 30348), -- Lorekeeper Vaeldrin, Immortality?
(58745, 30274), -- Lorekeeper Vaeldrin, The Arcanic Oubliette
(58745, 30359), -- Lorekeeper Vaeldrin, The Lord Reclaimer
(58745, 30344), -- Lorekeeper Vaeldrin, The Lost Dynasty
(58745, 30347), -- Lorekeeper Vaeldrin, The Pools of Youth
(58745, 30357), -- Lorekeeper Vaeldrin, The Stoneplow Convoy
(58745, 30346), -- Lorekeeper Vaeldrin, Where are the Pools
(58761, 31329), -- Tina Mudclaw, A Beautiful Brooch
(58761, 30431), -- Tina Mudclaw, A Blue Feather for Tina
(58761, 30433), -- Tina Mudclaw, A Dish for Tina
(58761, 30470), -- Tina Mudclaw, A Gift For Tina
(58761, 30430), -- Tina Mudclaw, A Jade Cat for Tina
(58761, 30429), -- Tina Mudclaw, A Lovely Apple for Tina
(58761, 30432), -- Tina Mudclaw, A Marsh Lily for Tina
(58761, 30428), -- Tina Mudclaw, A Ruby Shard for Tina
(58761, 31325), -- Tina Mudclaw, A Very Nice Necklace
(58761, 31328), -- Tina Mudclaw, An Exquisite Earring
(58761, 30323), -- Tina Mudclaw, They Don't Even Wear Them
(58761, 31326), -- Tina Mudclaw, Tina's Tasteful Tiara
(58779, 30352), -- Daggle Bombstrider, Crane Mastery
(58779, 31262), -- Daggle Bombstrider, Crane Mastery: Needlebeak
(58779, 30353), -- Daggle Bombstrider, Profit Mastery
(58779, 31260), -- Daggle Bombstrider, Profit Mastery: Chasheen
(58785, 30051), -- Mudmug, The Great Water Hunt
(58821, 30363), -- Lyalia, Going on the Offensive
(58821, 30465), -- Lyalia, Going on the Offensive
(58821, 30354), -- Lyalia, No Sister Left Behind
(58821, 30356), -- Lyalia, Sever Their Supply Line
(58821, 30445), -- Lyalia, The Waters of Youth
(58919, 30277), -- Anji Autumnlight, The Crumbling Hall
(58919, 31384), -- Anji Autumnlight, The Golden Lotus
(58919, 31385), -- Anji Autumnlight, The Golden Lotus
(58919, 30280), -- Anji Autumnlight, The Thunder Below
(58920, 30266), -- Kun Autumnlight, Bloodied Skies
(58920, 30243), -- Kun Autumnlight, Mantid Under Fire
(58962, 30306), -- Hai-Me Heavyhands, The Battle Ring
(59058, 29887), -- Pearlkeeper Fujin, The Elder's Instruments
(59073, 30457), -- Mayor Bramblestaff, Call Out Their Leader
(59073, 31254), -- Mayor Bramblestaff, The Road to Kun-Lai
(59073, 31255), -- Mayor Bramblestaff, The Road to Kun-Lai
(59073, 38936), -- Mayor Bramblestaff, The Road to Kun-Lai
(59076, 30459), -- Commander Hsieh, All of the Arrows
(59077, 30460), -- Apothecary Cheng, Hit Medicine
(59138, 30270), -- Koro Mistwalker, Blinding the Riverblades
(59138, 30694), -- Koro Mistwalker, Tread Lightly
(59138, 30269), -- Koro Mistwalker, Unsafe Passage
(59178, 29866), -- Lo Wanderbrew, The Threads that Stick
(59263, 30834), -- Merchant Shi, Father and Child Reunion
(59263, 30469), -- Merchant Shi, Repossession
(59263, 31451), -- Merchant Shi, The Missing Merchant
(59263, 31452), -- Merchant Shi, The Missing Merchant
(59272, 30467), -- Wu-Peng, My Son...
(59273, 30468), -- Swordmistress Mei, Enraged Vengeance
(59353, 30489), -- Lao Muskpaw, Fresh Needle Scent
(59353, 31456), -- Lao Muskpaw, Muskpaw Ranch
(59353, 31457), -- Lao Muskpaw, Muskpaw Ranch
(59353, 30804), -- Lao Muskpaw, The Fearmaster
(59353, 30582), -- Lao Muskpaw, The Late Mrs. Muskpaw
(59353, 30587), -- Lao Muskpaw, Yakity Yak
(59354, 30491), -- Muskpaw Jr., At the Yak Wash
(59371, 30808), -- Lucky Eightcoins, A Grummle's Luck
(59371, 30492), -- Lucky Eightcoins, Back in Yak
(59391, 30495), -- Foreman Raike, Love's Labor
(59391, 29931), -- Foreman Raike, The Serpent's Heart
(59402, 30614), -- Slimy Inkstain, Oil Stop
(59411, 30485), -- Lorewalker Cho, Last Piece of the Puzzle
(59411, 31362), -- Lorewalker Cho, Last Piece of the Puzzle
(59418, 30504), -- Lorewalker Cho, Emergency Response
(59418, 31319), -- Lorewalker Cho, Emergency Response
(59418, 30502), -- Lorewalker Cho, Jaded Heart
(59418, 30500), -- Lorewalker Cho, Residual Fallout
(59418, 31303), -- Lorewalker Cho, The Seal is Broken
(59441, 30506), -- Admiral Taylor, Admiral Taylor has Awakened
(59441, 30507), -- Admiral Taylor, Admiral Taylor has Awakened
(59441, 30508), -- Admiral Taylor, Admiral Taylor has Awakened
(59441, 30650), -- Admiral Taylor, Pandaren Prisoners
(59441, 30575), -- Admiral Taylor, Round 'Em Up
(59441, 30660), -- Admiral Taylor, The Ordo Warbringer
(59441, 30662), -- Admiral Taylor, The Ordo Warbringer
(59442, 30509), -- General Nazgrim, General Nazgrim has Awakened
(59442, 30510), -- General Nazgrim, General Nazgrim has Awakened
(59442, 30511), -- General Nazgrim, General Nazgrim has Awakened
(59442, 30655), -- General Nazgrim, Pandaren Prisoners
(59442, 31256), -- General Nazgrim, Round 'Em Up
(59442, 30661), -- General Nazgrim, The Ordo Warbringer
(59442, 30663), -- General Nazgrim, The Ordo Warbringer
(59448, 30656), -- Rivett Clutchpop, Barrels of Fun
(59448, 31251), -- Rivett Clutchpop, Best Meals Anywhere!
(59449, 30594), -- Shademaster Kiryn, Deanimate the Reanimated
(59450, 30651), -- Sully "The Pickle" McLeary, Barrels of Fun
(59450, 30583), -- Sully "The Pickle" McLeary, Blue Dwarf Needs Food Badly
(59451, 30593), -- Mishka, Deanimate the Reanimated
(59452, 30599), -- Brother Rabbitsfoot, A Monkey Idol
(59452, 30604), -- Brother Rabbitsfoot, Breaking Broketooth
(59452, 30600), -- Brother Rabbitsfoot, No Pack Left Behind
(59452, 30603), -- Brother Rabbitsfoot, The Broketooth Ravage
(59452, 30612), -- Brother Rabbitsfoot, The Leader Hozen
(59452, 30602), -- Brother Rabbitsfoot, The Rabbitsfoot
(59452, 30606), -- Brother Rabbitsfoot, Thumping Knucklethump
(59452, 30611), -- Brother Rabbitsfoot, Unleash The Yeti!
(59533, 30526), -- Lost Dog, Lost and Lonely
(59550, 30565), -- Sully "The Pickle" McLeary, An Unexpected Advantage
(59569, 30567), -- Brewmaster Blanche, Blanche's Boomer Brew
(59573, 30571), -- Farmer Chow, Farmhand Freedom
(59573, 30569), -- Farmer Chow, Trouble on the Farmstead
(59573, 30570), -- Farmer Chow, Trouble on the Farmstead
(59584, 30586), -- Fisherman Haito, Jagged Abalone
(59584, 30584), -- Fisherman Haito, Shocking!
(59584, 31369), -- Fisherman Haito, The Anglers
(59584, 31370), -- Fisherman Haito, The Anglers
(59586, 30588), -- Angler Shen, Fishing for a Bruising
(59586, 30700), -- Angler Shen, Snapclaw
(59597, 30616), -- Smokey Sootassle, Traffic Issues
(59608, 30695), -- Anduin Wrynn, Ahead on the Way
(59608, 30271), -- Anduin Wrynn, Sha Can Awe
(59608, 30272), -- Anduin Wrynn, Striking the Rain
(59636, 30581), -- Uyen Chow, ... and the Pot, Too!
(59695, 30618), -- Big Sal, Resupplying One Keg
(59696, 30601), -- Uncle Cloverleaf, Instant Courage
(59696, 30999), -- Uncle Cloverleaf, Path Less Traveled
(59701, 30617), -- Brother Lintpocket, Roadside Assistance
(59703, 30592), -- Brother Trailscenter, The Burlap Trail: To Burlap Waystation
(59704, 30085), -- Chen Stormstout, Into the Brewery
(59716, 30621), -- Ji-Lu the Lucky, They Stole My Luck!
(59719, 30273), -- Chi-Ji, In the House of the Red Crane
(59821, 30595), -- Bao Jian, Profiting off of the Past
(59894, 30605), -- Brother Yakshoe, Bros Before Hozen
(59894, 30610), -- Brother Yakshoe, Grummle! Grummle! Grummle!
(59894, 30607), -- Brother Yakshoe, Hozen Love Their Keys
(59894, 30608), -- Brother Yakshoe, The Snackrifice
(60135, 30613), -- Trawler Yotimo, Armored Carp
(60135, 30658), -- Trawler Yotimo, Huff &amp; Puff
(60136, 30678), -- Fiznix, Like Bombing Fish In A Barrel
(60136, 30698), -- Fiznix, Scavenger Hunt
(60139, 30691), -- Wise Ana Wu, Misery
(60139, 30669), -- Wise Ana Wu, The Lorewalker on the Lake
(60139, 30671), -- Wise Ana Wu, Wisdom Has A Price
(60161, 30682), -- Shado-Master Chong, Holed Up
(60161, 30665), -- Shado-Master Chong, The Defense of Shado-Pan Fallback
(60161, 31453), -- Shado-Master Chong, The Shado-Pan
(60161, 31455), -- Shado-Master Chong, The Shado-Pan
(60161, 30670), -- Shado-Master Chong, Turnabout
(60161, 30690), -- Shado-Master Chong, Unmasking the Yaungol
(60173, 30672), -- Jay Cloudfall, Balance
(60173, 30668), -- Jay Cloudfall, Build Your Own Raft
(60173, 30666), -- Jay Cloudfall, Sudden, Unexpected Crocolisk Aggression
(60175, 30487), -- Lucky Bluestring, Comin' Round the Mountain
(60175, 30683), -- Lucky Bluestring, One Traveler's Misfortune
(60182, 30667), -- Tony Tuna, Particular Plumage
(60436, 30819), -- Li Hai, Preparing the Remains
(60503, 30745), -- Uncle Keenbean, Trouble Brewing
(60503, 30826), -- Uncle Keenbean, Trouble Brewing
(60506, 31378), -- Thelonius, Challenge At The Temple of the Red Crane
(60506, 31379), -- Thelonius, Challenge At The Temple of the Red Crane
(60506, 30740), -- Thelonius, Champion of Chi-Ji
(60506, 30730), -- Thelonius, Dextrous Izissha
(60506, 30725), -- Thelonius, Ellia Ravenmane
(60506, 30739), -- Thelonius, Ellia Ravenmane: Redemption
(60506, 30727), -- Thelonius, Ellia Ravenmane: Rematch
(60506, 30732), -- Thelonius, Ellia Ravenmane: Revenge
(60506, 30728), -- Thelonius, Fat Long-Fat
(60506, 30737), -- Thelonius, Fat Long-Fat: Rematch
(60506, 30734), -- Thelonius, Huck Wheelbarrow
(60506, 30729), -- Thelonius, Julia Bates
(60506, 30731), -- Thelonius, Kuo-Na Quillpaw
(60506, 30735), -- Thelonius, Mindel Sunspeaker
(60506, 30726), -- Thelonius, Minh Do-Tan
(60506, 30718), -- Thelonius, Students of Chi-Ji
(60506, 30738), -- Thelonius, Thelonius
(60506, 30733), -- Thelonius, Tukka-Tuk
(60506, 30736), -- Thelonius, Yan Quillpaw
(60528, 30716), -- Kuo-Na Quillpaw, Chasing Hope
(60529, 30717), -- Yan Quillpaw, Gifts of the Great Crane
(60566, 31450), -- Aysa Cloudsinger, A New Fate
(60570, 31450), -- Ji Firepaw, A New Fate
(60578, 31355), -- Priestess Summerpetal, Restoring Jade's Purity
(60596, 30743), -- Cousin Gootfur, Gourmet Kafa
(60596, 30824), -- Cousin Gootfur, Gourmet Kafa
(60596, 30742), -- Cousin Gootfur, Shut it Down
(60596, 30823), -- Cousin Gootfur, Shut it Down
(60622, 30791), -- Orbiss, Arconiss Thirsts
(60622, 30790), -- Orbiss, Golgoss Hungers
(60622, 30793), -- Orbiss, Mists' Opportunity
(60622, 30792), -- Orbiss, Orbiss Fades
(60622, 30815), -- Orbiss, The Death of Me
(60673, 30585), -- Elder Fisherman Rassan, What Lurks Below
(60673, 30598), -- Elder Fisherman Rassan, Who Knew Fish Liked Eggs?
(60674, 30754), -- John "Big Hook" Marsock, Bright Bait
(60674, 30753), -- John "Big Hook" Marsock, Jumping the Shark
(60675, 30763), -- Fo Fook, Piranha!
(60675, 30701), -- Fo Fook, Viseclaw Soup
(60679, 30746), -- Nephew Burrberry, A Fair Trade
(60679, 30747), -- Nephew Burrberry, The Burlap Grind
(60679, 30821), -- Nephew Burrberry, The Burlap Grind
(60684, 30769), -- Suna Silentstrike, First Assault
(60684, 30768), -- Suna Silentstrike, My Husband...
(60687, 30776), -- Ban Bearheart, Jung Duk
(60687, 30771), -- Ban Bearheart, Perfect Pitch
(60687, 30773), -- Ban Bearheart, Pitching In
(60687, 30774), -- Ban Bearheart, Ranger Rescue
(60687, 30770), -- Ban Bearheart, Running Rampant
(60687, 30772), -- Ban Bearheart, Seeing Red
(60688, 30814), -- Taran Zhu, A Foot in the Door
(60688, 31695), -- Taran Zhu, Beyond the Wall
(60688, 39127), -- Taran Zhu, Beyond the Wall
(60688, 31386), -- Taran Zhu, The Shado-Pan Offensive
(60688, 31388), -- Taran Zhu, The Shado-Pan Offensive
(60694, 30816), -- Sage Liao, Checking In
(60735, 30775), -- Katak the Defeated, The Exile
(60785, 30807), -- Sage Liao, By the Falls, For the Fallen
(60785, 30794), -- Sage Liao, Emergency Care
(60785, 30805), -- Sage Liao, Justice
(60785, 30806), -- Sage Liao, The Scent of Life
(60795, 30684), -- Lorewalker Cho, Seeker's Folly
(60795, 31306), -- Lorewalker Cho, Seeker's Folly
(60795, 30829), -- Lorewalker Cho, The Tongue of Ba-Shon
(60857, 31894), -- Orbiss, A Delicate Balance
(60857, 30786), -- Orbiss, A Spear Through My Side, A Chain Through My Soul
(60857, 30789), -- Orbiss, Arconiss
(60857, 30788), -- Orbiss, Golgoss
(60857, 30787), -- Orbiss, The Torches
(60864, 30783), -- Yalia Sagewhisper, Hatred Becomes Us
(60864, 30780), -- Yalia Sagewhisper, Totemic Research
(60864, 30827), -- Yalia Sagewhisper, What Lies Beneath
(60968, 31517), -- Xuen, Contending With Bullies
(60968, 30879), -- Xuen, Round 1: Brewmaster Chani
(60968, 30880), -- Xuen, Round 1: The Streetfighter
(60968, 30881), -- Xuen, Round 2: Clever Ashyo &amp; Ken-Ken
(60968, 30882), -- Xuen, Round 2: Kang Bramblestaff
(60968, 30885), -- Xuen, Round 3: Master Boom Boom
(60968, 30883), -- Xuen, Round 3: The Wrestler
(60968, 30902), -- Xuen, Round 4: Master Windfur
(60968, 30907), -- Xuen, Round 4: The P.U.G.
(60968, 31380), -- Xuen, Trial At The Temple of the White Tiger
(60968, 31381), -- Xuen, Trial At The Temple of the White Tiger
(60970, 29903), -- Admiral Taylor, A Perfect Match
(60970, 29901), -- Admiral Taylor, Anduin's Decision
(60970, 29904), -- Admiral Taylor, Bigger Fish to Fry
(60973, 30967), -- Waterspeaker Gorai, Free the Dissenters
(60973, 30855), -- Waterspeaker Gorai, The Fall of Shai Hu
(60973, 30480), -- Waterspeaker Gorai, The Ritual
(60973, 30496), -- Waterspeaker Gorai, The Waterspeaker's Staff
(60981, 31492), -- Lin Tenderpaw, The Torch of Strength
(61016, 30972), -- Lao-Chin the Iron Belly, Joining the Fight
(61020, 30978), -- Hawkmaster Nurong, Hostile Skies
(61020, 30899), -- Hawkmaster Nurong, In Skilled Hands
(61021, 30898), -- Taoshi, Cutting the Swarm
(61065, 30828), -- Waterspeaker Gorai, Cleansing the Mere
(61066, 30785), -- Taran Zhu, Gao-Ran Battlefront
(61066, 30895), -- Taran Zhu, Improvised Ammunition
(61066, 30960), -- Taran Zhu, Returning from the Pass
(61066, 30900), -- Taran Zhu, Terror of the Dread Wastes
(61066, 30893), -- Taran Zhu, The Endless Swarm
(61161, 30929), -- Bluesaddle, Bad Yak
(61161, 30930), -- Bluesaddle, Pick a Yak
(61218, 31130), -- Lorewalker Cho, A Visit with Lorewalker Cho
(61261, 30778), -- Ban Bearheart, Dust to Dust
(61261, 30777), -- Ban Bearheart, In Search of Suna
(61261, 30781), -- Ban Bearheart, Last Toll of the Yaungol
(61261, 30779), -- Ban Bearheart, Slaying the Scavengers
(61261, 30782), -- Ban Bearheart, Spiteful Spirits
(61261, 30784), -- Ban Bearheart, The Point of No Return
(61297, 30796), -- Image of Lorewalker Cho, An End to Everything
(61297, 30798), -- Image of Lorewalker Cho, Breaking the Emperor's Shield
(61297, 30802), -- Image of Lorewalker Cho, Chasing the Storm
(61297, 30797), -- Image of Lorewalker Cho, It Was Almost Alive
(61297, 30801), -- Image of Lorewalker Cho, Lessons from History
(61297, 30795), -- Image of Lorewalker Cho, Staying Connected
(61297, 30800), -- Image of Lorewalker Cho, Stealing Their Thunder King
(61297, 30799), -- Image of Lorewalker Cho, The Tomb of Shadows
(61371, 30935), -- Lorewalker Cho, Fisherman's Tale
(61371, 30944), -- Lorewalker Cho, It Takes A Village
(61454, 30750), -- Suna Silentstrike, Off the Wall!
(61454, 30724), -- Suna Silentstrike, To the Wall!
(61467, 30889), -- Mao the Lookout, Trap Setting
(61468, 30888), -- Taoshi, Breach in the Defenses
(61468, 30890), -- Taoshi, The Restless Watch
(61468, 30887), -- Taoshi, Unwelcome Intruders
(61469, 30884), -- Taoshi, Behind the Battlefront
(61470, 30892), -- Septi the Herbalist, Back on Their Feet
(61470, 30894), -- Septi the Herbalist, Rummaging Through the Remains
(61470, 30891), -- Septi the Herbalist, Treatment for the Troops
(61482, 30923), -- Tai Ho, Set the Mantid Back
(61482, 30921), -- Tai Ho, The Motives of the Mantid
(61482, 30926), -- Tai Ho, The Terrible Truth
(61495, 30943), -- Elder Shu, Handle With Care
(61496, 30945), -- Steelbender Doshu, What's Yours Is Mine
(61503, 30942), -- Shomi, Make A Fighter Out of Me
(61539, 30932), -- Ku-Mo, Father's Footsteps
(61539, 30931), -- Ku-Mo, My Father's Crossbow
(61580, 31382), -- Ogo the Elder, Defense At Niuzao Temple
(61580, 31383), -- Ogo the Elder, Defense At Niuzao Temple
(61580, 30956), -- Ogo the Elder, The Siege Swells
(61580, 30952), -- Ogo the Elder, The Unending Siege
(61581, 30954), -- Ogo the Younger, A Blade is a Blade
(61581, 30925), -- Ogo the Younger, Niuzao's Price
(61581, 30959), -- Ogo the Younger, The Big Guns
(61581, 30924), -- Ogo the Younger, The Wisdom of Niuzao
(61583, 30955), -- High Adept Paosha, Paying Tribute
(61584, 30927), -- Sentinel Commander Qipan, Give Them Peace
(61584, 30957), -- Sentinel Commander Qipan, The Overwhelming Swarm
(61585, 30928), -- Yak-Keeper Kyana, A Trail of Fear
(61585, 30953), -- Yak-Keeper Kyana, Fallen Sentinels
(61585, 30958), -- Yak-Keeper Kyana, In Battle's Shadow
(61625, 30964), -- Provisioner Bamfu, A Proper Poultice
(61625, 30922), -- Provisioner Bamfu, Natural Antiseptic
(61625, 30963), -- Provisioner Bamfu, The Field Armorer
(61693, 30488), -- Muskpaw Jr., The Missing Muskpaw
(61716, 30969), -- Invoker Xorenth, A New Enemy
(61716, 30983), -- Invoker Xorenth, The Dark Shaman
(61724, 30982), -- Commander Bagran, Animal Control
(61724, 31034), -- Commander Bagran, Enemies Below
(61724, 31036), -- Commander Bagran, Enemies Below
(61724, 31037), -- Commander Bagran, Enemies Below
(61724, 30984), -- Commander Bagran, No Orc Left Behind
(61796, 30988), -- King Varian Wrynn, The Alliance Way
(61816, 30723), -- Lin Silentstrike, Honor, Even in Death
(61816, 30699), -- Lin Silentstrike, To Winter's Blossom
(61819, 30715), -- Ban Bearheart, A Line Unbroken
(61819, 30992), -- Ban Bearheart, Finish This!
(61819, 30993), -- Ban Bearheart, Where are My Reinforcements?
(61820, 30751), -- Lao-Chin the Iron Belly, A Terrible Sacrifice
(61820, 30991), -- Lao-Chin the Iron Belly, Do a Barrel Roll!
(61820, 30994), -- Lao-Chin the Iron Belly, Lao-Chin's Gambit
(61822, 30997), -- SI:7 Field Commander Dirken, Animal Control
(61822, 30995), -- SI:7 Field Commander Dirken, No Man Left Behind
(61823, 30998), -- High Sorceress Aryna, A New Enemy
(61823, 30996), -- High Sorceress Aryna, The Dark Shaman
(61847, 31459), -- Lorewalker Cho, Cho's Missive
(61847, 31460), -- Lorewalker Cho, Cho's Missive
(61880, 30897), -- Initiate Chao, In the Wrong Hands
(61881, 30896), -- Initiate Feng, Thieves and Troublemakers
(61962, 31055), -- Lorewalker Cho, Between a Saurok and a Hard Place
(61962, 31094), -- Lorewalker Cho, Fish Tales
(61962, 32602), -- Lorewalker Cho, Gods and Monsters
(61962, 31097), -- Lorewalker Cho, Heart of the Mantid Swarm
(61962, 31093), -- Lorewalker Cho, Hozen in the Mist
(61962, 32601), -- Lorewalker Cho, Rumbles of Thunder
(61962, 31103), -- Lorewalker Cho, The Ballad of Liu Lang
(61962, 31095), -- Lorewalker Cho, The Dark Heart of the Mogu
(61962, 32806), -- Lorewalker Cho, The King and the Council
(61962, 31367), -- Lorewalker Cho, The Lorewalkers
(61962, 31368), -- Lorewalker Cho, The Lorewalkers
(61962, 31102), -- Lorewalker Cho, The Seven Burdens of Shaohao
(61962, 31100), -- Lorewalker Cho, The Song of the Yaungol
(61962, 32807), -- Lorewalker Cho, The Warchief and the Darkness
(61962, 32600), -- Lorewalker Cho, The Zandalari Prophecy
(61962, 31096), -- Lorewalker Cho, What is Worth Fighting For
(61962, 31015), -- Lorewalker Cho, Your Private Collection
(62092, 31014), -- Garrosh Hellscream, Hellscream's Gift
(62092, 31013), -- Garrosh Hellscream, The Horde Way
(62112, 31847), -- Bowmistress Li, Better Dead than Dread
(62112, 31895), -- Bowmistress Li, Better Off Dread
(62112, 31000), -- Bowmistress Li, Dread Space
(62112, 31886), -- Bowmistress Li, Dread Space
(62112, 31390), -- Bowmistress Li, The Klaxxi
(62112, 31391), -- Bowmistress Li, The Klaxxi
(62112, 31656), -- Bowmistress Li, The Threat in the South
(62124, 30971), -- Initiate Pao-Me, Taking Stock
(62151, 31210), -- Xaril the Poisoned Mind, A Shade of Dread
(62151, 31018), -- Xaril the Poisoned Mind, Beneath the Heart of Fear
(62151, 31216), -- Xaril the Poisoned Mind, Dark Skies
(62151, 31209), -- Xaril the Poisoned Mind, Dark Wings, Dark Things
(62151, 31211), -- Xaril the Poisoned Mind, The Poisoned Mind
(62151, 31208), -- Xaril the Poisoned Mind, Venomous Intent
(62166, 31001), -- Marksman Lann, Falling Down
(62166, 31002), -- Marksman Lann, Nope
(62180, 31232), -- Korven the Prime, An Ancient Empire
(62180, 31507), -- Korven the Prime, Meltdown
(62180, 31496), -- Korven the Prime, Sampling the Empire's Finest
(62180, 31233), -- Korven the Prime, Sap Tapping
(62180, 31270), -- Korven the Prime, The Fight Against Fear
(62180, 31269), -- Korven the Prime, The Scale-Lord
(62202, 31676), -- Kil'ruk the Wind-Reaver, Ancient Vengeance
(62202, 31004), -- Kil'ruk the Wind-Reaver, Preserved in Amber
(62202, 31005), -- Kil'ruk the Wind-Reaver, Wakening Sickness
(62203, 31003), -- Klaxxi'va Tik, Psycho Mantid
(62227, 30752), -- Ban Bearheart, Unbelievable!
(62232, 31020), -- Klaxxi Warrior, Feeding the Beast
(62232, 31022), -- Klaxxi Warrior, Kypari Zar
(62232, 31021), -- Klaxxi Warrior, Living Amber
(62232, 31026), -- Klaxxi Warrior, The Root of the Problem
(62236, 31030), -- Ban Bearheart, Into the Monastery
(62236, 31031), -- Ban Bearheart, Into the Monastery
(62273, 30973), -- Taran Zhu, Up In Flames
(62274, 31065), -- Taran Zhu, Buried Beneath
(62274, 30980), -- Taran Zhu, Heroes of the Shado-Pan
(62274, 30976), -- Taran Zhu, Joining the Hunt
(62275, 31063), -- Taran Zhu, Lao-Chin and Serevex
(62275, 31064), -- Taran Zhu, Nurong and Rothek
(62275, 30981), -- Taran Zhu, Taoshi and Korvexxis
(62278, 30977), -- Rensai Oakhide, Grounded Welcome
(62278, 31688), -- Rensai Oakhide, The Search for Restless Leng
(62278, 31687), -- Rensai Oakhide, Thinning the Sik'thik
(62295, 31047), -- Omnia Mage, Born Free
(62295, 31044), -- Omnia Mage, Bronze Claws
(62295, 31043), -- Omnia Mage, Dark Arts
(62295, 31041), -- Omnia Mage, Egg Rescue!
(62295, 31048), -- Omnia Mage, Grave Consequences
(62295, 31045), -- Omnia Mage, Illusions Of The Past
(62295, 31046), -- Omnia Mage, Little Hatchlings
(62295, 31042), -- Omnia Mage, Onyx Hearts
(62295, 31040), -- Omnia Mage, Spiteful Sprites
(62295, 31039), -- Omnia Mage, The Mogu Menace
(62295, 31105), -- Omnia Mage, The Mogu Menace
(62295, 31106), -- Omnia Mage, The Mogu Menace
(62304, 31047), -- Ban Bearheart, Born Free
(62304, 31044), -- Ban Bearheart, Bronze Claws
(62304, 31043), -- Ban Bearheart, Dark Arts
(62304, 31041), -- Ban Bearheart, Egg Rescue!
(62304, 31048), -- Ban Bearheart, Grave Consequences
(62304, 31045), -- Ban Bearheart, Illusions Of The Past
(62304, 31049), -- Ban Bearheart, In Sprite Of Everything
(62304, 31046), -- Ban Bearheart, Little Hatchlings
(62304, 31042), -- Ban Bearheart, Onyx Hearts
(62304, 31809), -- Ban Bearheart, Remnants of Anger
(62304, 31061), -- Ban Bearheart, Riding the Storm
(62304, 31040), -- Ban Bearheart, Spiteful Sprites
(62304, 31277), -- Ban Bearheart, Surprise Attack!
(62304, 31038), -- Ban Bearheart, The Challenger's Ring: Snow Blossom
(62304, 31104), -- Ban Bearheart, The Challenger's Ring: Yalia Sagewhisper
(62304, 31039), -- Ban Bearheart, The Mogu Menace
(62304, 31105), -- Ban Bearheart, The Mogu Menace
(62304, 31106), -- Ban Bearheart, The Mogu Menace
(62304, 31387), -- Ban Bearheart, Understanding The Shado-Pan
(62304, 31389), -- Ban Bearheart, Understanding The Shado-Pan
(62304, 31062), -- Ban Bearheart, When The Dead Speak
(62321, 31613), -- Brewmaster Tzu, Volatile Greenstone Brew
(62377, 30050), -- Gardener Fran, Gardener Fran and the Watering Can
(62378, 31047), -- Omnia Priest, Born Free
(62378, 31044), -- Omnia Priest, Bronze Claws
(62378, 31043), -- Omnia Priest, Dark Arts
(62378, 31041), -- Omnia Priest, Egg Rescue!
(62378, 31048), -- Omnia Priest, Grave Consequences
(62378, 31045), -- Omnia Priest, Illusions Of The Past
(62378, 31046), -- Omnia Priest, Little Hatchlings
(62378, 31042), -- Omnia Priest, Onyx Hearts
(62378, 31040), -- Omnia Priest, Spiteful Sprites
(62378, 31039), -- Omnia Priest, The Mogu Menace
(62378, 31105), -- Omnia Priest, The Mogu Menace
(62378, 31106), -- Omnia Priest, The Mogu Menace
(62379, 31047), -- Omnia Mage, Born Free
(62379, 31044), -- Omnia Mage, Bronze Claws
(62379, 31043), -- Omnia Mage, Dark Arts
(62379, 31041), -- Omnia Mage, Egg Rescue!
(62379, 31048), -- Omnia Mage, Grave Consequences
(62379, 31045), -- Omnia Mage, Illusions Of The Past
(62379, 31046), -- Omnia Mage, Little Hatchlings
(62379, 31042), -- Omnia Mage, Onyx Hearts
(62379, 31040), -- Omnia Mage, Spiteful Sprites
(62379, 31039), -- Omnia Mage, The Mogu Menace
(62379, 31105), -- Omnia Mage, The Mogu Menace
(62379, 31106), -- Omnia Mage, The Mogu Menace
(62385, 30057), -- Den Mudclaw, Seeing Orange
(62436, 30901), -- Taoshi, Along the Southern Front
(62436, 30970), -- Taoshi, Enraged By Hatred
(62444, 30898), -- Taoshi, Cutting the Swarm
(62538, 31109), -- Kil'ruk the Wind-Reaver, Culling the Swarm
(62538, 31231), -- Kil'ruk the Wind-Reaver, Dreadspinner Extermination
(62538, 31111), -- Kil'ruk the Wind-Reaver, Eradicating the Zan'thik
(62538, 31267), -- Kil'ruk the Wind-Reaver, Mistblade Destruction
(62538, 31235), -- Kil'ruk the Wind-Reaver, Nope Nope Nope
(62538, 31660), -- Kil'ruk the Wind-Reaver, Not Fit to Swarm
(62538, 31612), -- Kil'ruk the Wind-Reaver, Shadow of the Empire
(62538, 31007), -- Kil'ruk the Wind-Reaver, The Dread Clutches
(62538, 31006), -- Kil'ruk the Wind-Reaver, The Klaxxi Council
(62538, 31179), -- Kil'ruk the Wind-Reaver, The Scent of Blood
(62538, 31677), -- Kil'ruk the Wind-Reaver, The Warlord's Ashes
(62538, 31609), -- Kil'ruk the Wind-Reaver, The Wrath of Shek'zeer
(62538, 31505), -- Kil'ruk the Wind-Reaver, Vess-Guard Duty
(62573, 31032), -- Marksman Ye, Choking the Skies
(62666, 31730), -- Sapmaster Vu, A Not So Friendly Request
(62666, 31086), -- Sapmaster Vu, Blood of Ancients
(62666, 31069), -- Sapmaster Vu, Bound With Shade
(62666, 31073), -- Sapmaster Vu, Bound With Wood
(62666, 31075), -- Sapmaster Vu, Sunset Kings
(62666, 31067), -- Sapmaster Vu, The Heavens Hum With War
(62667, 31085), -- Lya of Ten Songs, Fires and Fears of Old
(62667, 31081), -- Lya of Ten Songs, Incantations Fae and Primal
(62667, 31072), -- Lya of Ten Songs, Rending Daggers
(62667, 31068), -- Lya of Ten Songs, Sacred Recipe
(62667, 31074), -- Lya of Ten Songs, Wood and Shade
(62668, 31070), -- Olon, Daggers of the Great Ones
(62668, 31080), -- Olon, Fiery Wings
(62736, 30975), -- Taran Zhu, The Taking of Dusklight Bridge
(62771, 31084), -- Chief Rikkitun, Bind the Glamour
(62771, 31082), -- Chief Rikkitun, Great Vessel of Salvation
(62771, 31083), -- Chief Rikkitun, Promises of Gold
(62772, 31079), -- Boggeo, The Horror Comes A-Rising
(62774, 31107), -- Malik the Unscathed, Citizens of a New Empire
(62774, 31010), -- Malik the Unscathed, In Her Clutch
(62774, 31689), -- Malik the Unscathed, The Dreadsworn
(62779, 31076), -- Chen Stormstout, Fate of the Stormstouts
(62779, 31129), -- Chen Stormstout, Fate of the Stormstouts
(62779, 31078), -- Chen Stormstout, Han Stormstout
(62786, 30979), -- Hawkmaster Nurong, Devastation Below
(62802, 30968), -- Taoshi, The Sha of Hatred
(62810, 31110), -- Moshu the Arcane, Through the Portal
(62859, 31071), -- Thirsty Missho, I Bring Us Great Shame
(62923, 29821), -- Empty Package, Missed Me By... That Much!
(63009, 31114), -- Master Snowdrift, Assault Deadtalker's Plateau
(63009, 31113), -- Master Snowdrift, Assault Fire Camp Gai-Cho
(63009, 31120), -- Master Snowdrift, Cheng Bo!
(63009, 31266), -- Master Snowdrift, Mogu Incursions
(63009, 31116), -- Master Snowdrift, Spirit Dust
(63009, 31127), -- Master Snowdrift, The Challenger's Ring: Chao the Voice
(63009, 31128), -- Master Snowdrift, The Challenger's Ring: Lao-Chin the Iron Belly
(63009, 31118), -- Master Snowdrift, The Deadtalker Cipher
(63009, 31119), -- Master Snowdrift, The Enemy of My Enemy... Is Still My Enemy!
(63009, 31117), -- Master Snowdrift, Uruk!
(63014, 31550), -- Marcus Jensen, Got one!
(63014, 31308), -- Marcus Jensen, Learning the Ropes
(63014, 31785), -- Marcus Jensen, Level Up!
(63014, 31309), -- Marcus Jensen, On The Mend
(63061, 31570), -- Narzak, Got one!
(63061, 31571), -- Narzak, Learning the Ropes
(63061, 31830), -- Narzak, Level Up!
(63061, 31572), -- Narzak, On The Mend
(63070, 31555), -- Valeena, Got one!
(63070, 31552), -- Valeena, Learning the Ropes
(63070, 31826), -- Valeena, Level Up!
(63070, 31553), -- Valeena, On The Mend
(63071, 31178), -- Skeer the Bloodseeker, A Bloody Delight
(63071, 31176), -- Skeer the Bloodseeker, A Strange Appetite
(63071, 31177), -- Skeer the Bloodseeker, Fine Dining
(63071, 31175), -- Skeer the Bloodseeker, Skeer the Bloodseeker
(63072, 31271), -- Rik'kal the Dissector, Bad Genes
(63072, 31509), -- Rik'kal the Dissector, Fear Takes Root
(63072, 31234), -- Rik'kal the Dissector, Putting An Eye Out
(63072, 31503), -- Rik'kal the Dissector, Shortcut to Ruin
(63072, 31508), -- Rik'kal the Dissector, Specimen Request
(63072, 31606), -- Rik'kal the Dissector, The Dissector Wakens
(63072, 31502), -- Rik'kal the Dissector, Wing Clip
(63073, 31578), -- Ansel Fincap, Got one!
(63073, 31576), -- Ansel Fincap, Learning the Ropes
(63073, 31823), -- Ansel Fincap, Level Up!
(63073, 31577), -- Ansel Fincap, On The Mend
(63075, 31551), -- Grady Bannson, Got one!
(63075, 31548), -- Grady Bannson, Learning the Ropes
(63075, 31822), -- Grady Bannson, Level Up!
(63075, 31549), -- Grady Bannson, On The Mend
(63077, 31569), -- Lehna, Got one!
(63077, 31556), -- Lehna, Learning the Ropes
(63077, 31825), -- Lehna, Level Up!
(63077, 31568), -- Lehna, On The Mend
(63080, 31581), -- Jarson Everlong, Got one!
(63080, 31579), -- Jarson Everlong, Learning the Ropes
(63080, 31824), -- Jarson Everlong, Level Up!
(63080, 31580), -- Jarson Everlong, On The Mend
(63083, 31584), -- Will Larsons, Got one!
(63083, 31582), -- Will Larsons, Learning the Ropes
(63083, 31832), -- Will Larsons, Level Up!
(63083, 31583), -- Will Larsons, On The Mend
(63086, 31587), -- Matty, Got one!
(63086, 31585), -- Matty, Learning the Ropes
(63086, 31828), -- Matty, Level Up!
(63086, 31586), -- Matty, On The Mend
(63194, 31729), -- Steven Lisbane, Steven Lisbane
(63194, 31852), -- Steven Lisbane, Steven Lisbane
(63217, 31132), -- Lorewalker Cho, A Mile in My Shoes
(63217, 31134), -- Lorewalker Cho, If These Stones Could Speak
(63218, 31133), -- Defender Azzo, Kor'thik Aggression
(63238, 31138), -- Xi, Friend to the Small, The Arts of a Monk
(63238, 31135), -- Xi, Friend to the Small, The Future of Gnomeregan
(63258, 31141), -- Bao, Calligraphed Letter
(63258, 31142), -- Bao, Palm of the Tiger
(63272, 31146), -- Ting, Strong of Stomach, Scribbled Scroll
(63272, 31147), -- Ting, Strong of Stomach, Tiger Palm
(63285, 31150), -- Lo, Elegant Rune
(63285, 31151), -- Lo, Kick, Punch, It's All in the Mind
(63296, 31156), -- Gato, Calligraphed Parchment
(63296, 31157), -- Gato, Tiger Palm
(63307, 31167), -- Lorewalker Cho, Family Tree
(63307, 31152), -- Lorewalker Cho, Peering Into the Past
(63310, 31160), -- Zabrax, A Rough Start
(63310, 31161), -- Zabrax, Proving Pit
(63310, 31162), -- Zabrax, The Arts of a Monk
(63310, 31158), -- Zabrax, The Basics: Hitting Things
(63310, 31159), -- Zabrax, The Rise of the Darkspear
(63317, 31183), -- Captain "Soggy" Su-Dao, Meet the Cap'n
(63317, 31184), -- Captain "Soggy" Su-Dao, Old Age and Treachery
(63317, 31190), -- Captain "Soggy" Su-Dao, The Mariner's Revenge
(63317, 31185), -- Captain "Soggy" Su-Dao, Walking Dog
(63327, 31165), -- Shoyu, Calligraphed Note
(63327, 31166), -- Shoyu, Tiger Palm
(63328, 31020), -- Klaxxi Warrior, Feeding the Beast
(63328, 31022), -- Klaxxi Warrior, Kypari Zar
(63328, 31021), -- Klaxxi Warrior, Living Amber
(63328, 31026), -- Klaxxi Warrior, The Root of the Problem
(63331, 31168), -- Laoxi, Calligraphed Sigil
(63331, 31169), -- Laoxi, The Art of the Monk
(63332, 31170), -- Pao, Monk Training
(63332, 31171), -- Pao, Tiger Palm
(63335, 31173), -- Mojo Stormstout, The Tiger Palm
(63349, 31181), -- Deck Boss Arie, Fresh Pots
(63349, 31727), -- Deck Boss Arie, Gambling Problem
(63349, 31265), -- Deck Boss Arie, Mazu's Breath
(63349, 31187), -- Deck Boss Arie, On the Crab
(63349, 31189), -- Deck Boss Arie, Reeltime Strategy
(63349, 31188), -- Deck Boss Arie, Shark Week
(63349, 31182), -- Deck Boss Arie, You Otter Know
(63367, 31611), -- Brewmaster Boof, The Kun-Lai Kicker
(63367, 31285), -- Brewmaster Boof, The Spring Drifter
(63484, 31287), -- Len the Whisperer, Educating Saurok
(63484, 31286), -- Len the Whisperer, Robbing Robbers of Robbers
(63535, 30515), -- Elder Shiao, Challenge Accepted
(63535, 30513), -- Elder Shiao, Eastwind Rest
(63535, 30620), -- Elder Shiao, Mogu?! Oh No-gu!
(63542, 30514), -- Elder Tsulan, Challenge Accepted
(63542, 30619), -- Elder Tsulan, Mogu?! Oh No-gu!
(63542, 30512), -- Elder Tsulan, Westwind Rest
(63596, 31984), -- Audrey Burnhep, A Brief Reprieve
(63596, 31917), -- Audrey Burnhep, A Tamer's Homecoming
(63596, 32008), -- Audrey Burnhep, Audrey Burnhep
(63596, 31981), -- Audrey Burnhep, Exceeding Expectations
(63596, 31593), -- Audrey Burnhep, Got one!
(63596, 31591), -- Audrey Burnhep, Learning the Ropes
(63596, 31821), -- Audrey Burnhep, Level Up!
(63596, 31592), -- Audrey Burnhep, On The Mend
(63596, 31975), -- Audrey Burnhep, The Returning Champion
(63596, 31976), -- Audrey Burnhep, The Returning Champion
(63596, 31985), -- Audrey Burnhep, The Triumphant Return
(63596, 32863), -- Audrey Burnhep, What We've Been Training For
(63614, 31198), -- Ling of the Six Pools, A Morale Victory
(63614, 31199), -- Ling of the Six Pools, Destroy the Siege Weapons!
(63614, 31201), -- Ling of the Six Pools, Friends, Not Food!
(63614, 31200), -- Ling of the Six Pools, Fumigation
(63614, 31196), -- Ling of the Six Pools, Sra'vess Wetwork
(63614, 31204), -- Ling of the Six Pools, Target of Opportunity: Sra'thik Hivelord
(63614, 31203), -- Ling of the Six Pools, Target of Opportunity: Sra'thik Swarmlord
(63614, 31197), -- Ling of the Six Pools, The Bigger They Come...
(63614, 31220), -- Ling of the Six Pools, The Challenger's Ring: Hawkmaster Nurong
(63614, 31221), -- Ling of the Six Pools, The Challenger's Ring: Tenwu of the Red Smoke
(63622, 31198), -- Wu Kao Rogue, A Morale Victory
(63622, 31199), -- Wu Kao Rogue, Destroy the Siege Weapons!
(63622, 31201), -- Wu Kao Rogue, Friends, Not Food!
(63622, 31200), -- Wu Kao Rogue, Fumigation
(63622, 31196), -- Wu Kao Rogue, Sra'vess Wetwork
(63622, 31197), -- Wu Kao Rogue, The Bigger They Come...
(63623, 31198), -- Wu Kao Assassin, A Morale Victory
(63623, 31199), -- Wu Kao Assassin, Destroy the Siege Weapons!
(63623, 31201), -- Wu Kao Assassin, Friends, Not Food!
(63623, 31200), -- Wu Kao Assassin, Fumigation
(63623, 31196), -- Wu Kao Assassin, Sra'vess Wetwork
(63623, 31197), -- Wu Kao Assassin, The Bigger They Come...
(63624, 31198), -- Wu Kao Hawkmaster, A Morale Victory
(63624, 31199), -- Wu Kao Hawkmaster, Destroy the Siege Weapons!
(63624, 31201), -- Wu Kao Hawkmaster, Friends, Not Food!
(63624, 31200), -- Wu Kao Hawkmaster, Fumigation
(63624, 31196), -- Wu Kao Hawkmaster, Sra'vess Wetwork
(63624, 31197), -- Wu Kao Hawkmaster, The Bigger They Come...
(63626, 31983), -- Varzok, A Brief Reprieve
(63626, 31918), -- Varzok, A Tamer's Homecoming
(63626, 31982), -- Varzok, Exceeding Expectations
(63626, 31590), -- Varzok, Got one!
(63626, 31588), -- Varzok, Learning the Ropes
(63626, 31827), -- Varzok, Level Up!
(63626, 31589), -- Varzok, On The Mend
(63626, 31977), -- Varzok, The Returning Champion
(63626, 31980), -- Varzok, The Returning Champion
(63626, 31986), -- Varzok, The Triumphant Return
(63626, 32009), -- Varzok, Varzok
(63626, 32863), -- Varzok, What We've Been Training For
(63721, 36608), -- Nat Pagle, Finding Nat Pagle
(63721, 31443), -- Nat Pagle, Flying Tiger Gourami
(63721, 31446), -- Nat Pagle, Mimic Octopus
(63721, 31444), -- Nat Pagle, Spinefish Alpha
(63750, 31011), -- Lorewalker Cho, Enemies At Our Door
(63751, 31253), -- Farmhand Ko, Back to Eastwind Rest
(63754, 31252), -- Farmhand Bo, Back to Westwind Rest
(63758, 31268), -- Kaz'tik the Manipulator, A Little Brain Work
(63758, 31238), -- Kaz'tik the Manipulator, Brain Food
(63758, 31398), -- Kaz'tik the Manipulator, Falling to Pieces
(63758, 31092), -- Kaz'tik the Manipulator, Feed or Be Eaten
(63758, 31494), -- Kaz'tik the Manipulator, Free From Her Clutches
(63758, 31024), -- Kaz'tik the Manipulator, Kunchong Treats
(63758, 31808), -- Kaz'tik the Manipulator, Rampage Against the Machine
(63758, 31506), -- Kaz'tik the Manipulator, Shackles of Manipulation
(63758, 31487), -- Kaz'tik the Manipulator, Sonic Disruption
(63758, 31359), -- Kaz'tik the Manipulator, The Kunchong Whisperer
(63784, 31228), -- Lorewalker Cho, Prophet Khar'zul
(63784, 30946), -- Lorewalker Cho, Revelations
(63785, 31458), -- Hisek the Swarmkeeper, Damage Control
(63785, 31237), -- Hisek the Swarmkeeper, Debugging the Terrace
(63785, 31465), -- Hisek the Swarmkeeper, Extracting Answers
(63785, 31272), -- Hisek the Swarmkeeper, Infection
(63785, 31504), -- Hisek the Swarmkeeper, Ordnance Disposal
(63785, 31510), -- Hisek the Swarmkeeper, Quiet Now
(63822, 30182), -- Tani, Fox Mastery
(63822, 30183), -- Tani, Stalker Mastery
(63876, 31089), -- Kaz'tik the Manipulator, By the Sea, Nevermore
(63955, 31186), -- Dog, Dog Food
(63983, 31291), -- Ms. Thai, Uncovering the Past
(63984, 31288), -- Master Liu, Research Project: The Mogu Dynasties
(63994, 31528), -- Challenger Wuli, A Worthy Challenge: Darkmaster Gandling
(63994, 31526), -- Challenger Wuli, A Worthy Challenge: Durand
(63994, 31527), -- Challenger Wuli, A Worthy Challenge: Flameweaver Koegler
(63994, 31524), -- Challenger Wuli, A Worthy Challenge: Raigonn
(63994, 31520), -- Challenger Wuli, A Worthy Challenge: Sha of Doubt
(63994, 31522), -- Challenger Wuli, A Worthy Challenge: Sha of Hatred
(63994, 31525), -- Challenger Wuli, A Worthy Challenge: Wing Leader Ner'onok
(63994, 31523), -- Challenger Wuli, A Worthy Challenge: Xin the Weaponmaster
(63994, 31519), -- Challenger Wuli, A Worthy Challenge: Yan-zhu the Uncasked
(63996, 33133), -- Elder Liao, Warforged Seals
(64028, 32007), -- Challenger Soong, A Worthy Challenge: Darkmaster Gandling
(64028, 32005), -- Challenger Soong, A Worthy Challenge: Durand
(64028, 32006), -- Challenger Soong, A Worthy Challenge: Flameweaver Koegler
(64028, 32003), -- Challenger Soong, A Worthy Challenge: Raigonn
(64028, 31998), -- Challenger Soong, A Worthy Challenge: Sha of Doubt
(64028, 32001), -- Challenger Soong, A Worthy Challenge: Sha of Hatred
(64028, 32004), -- Challenger Soong, A Worthy Challenge: Wing Leader Ner'onok
(64028, 32002), -- Challenger Soong, A Worthy Challenge: Xin the Weaponmaster
(64028, 32000), -- Challenger Soong, A Worthy Challenge: Yan-zhu the Uncasked
(64029, 33134), -- Elder Lin, Warforged Seals
(64058, 32726), -- Jorunga Stonehoof, So You Want to Be a Blacksmith...
(64085, 32683), -- Cullen Hammerbrow, So You Want to Be a Blacksmith...
(64101, 32900), -- Taijing the Cyclone, Heroic Deeds
(64231, 33022), -- Sungshin Ironpaw, Catch and Carry
(64231, 31279), -- Sungshin Ironpaw, Everything I Know About Cooking
(64231, 31486), -- Sungshin Ironpaw, Everything I Know About Cooking
(64231, 33024), -- Sungshin Ironpaw, Is That A Real Measurement?
(64231, 33146), -- Sungshin Ironpaw, Noodle Time
(64231, 33358), -- Sungshin Ironpaw, Noodle Time: Bonus
(64231, 31302), -- Sungshin Ironpaw, Ready for Greatness
(64231, 33021), -- Sungshin Ironpaw, Secrets Lost, Forever?
(64231, 31281), -- Sungshin Ironpaw, So You Want to Be a Chef...
(64231, 33027), -- Sungshin Ironpaw, The Secret Ingredient Is...
(64231, 33026), -- Sungshin Ironpaw, These Aren't Your Fatty Goatsteaks
(64231, 31521), -- Sungshin Ironpaw, To Be a Master
(64259, 31354), -- Master Angler Ju Lien, Mazu's Bounty
(64315, 32045), -- Stonecarver Mac, Children of the Water
(64330, 31693), -- Julia Stevens, Julia Stevens
(64330, 31316), -- Julia Stevens, Julia, The Pet Tamer
(64337, 31820), -- Nomi, A Present for Teacher
(64337, 31337), -- Nomi, A Token of Appreciation
(64337, 31332), -- Nomi, Lesson 1: Sliced Peaches
(64337, 31333), -- Nomi, Lesson 2: Instant Noodles
(64337, 31334), -- Nomi, Lesson 3: Toasted Fish Jerky
(64337, 31335), -- Nomi, Lesson 4: Dried Needle Mushrooms
(64337, 31336), -- Nomi, Lesson 5: Pounded Rice Cake
(64344, 31091), -- Kaz'tik the Manipulator, Reunited
(64395, 31536), -- Nam Ironpaw, Preserving Freshness
(64395, 31535), -- Nam Ironpaw, Replenishing the Pantry
(64399, 31356), -- Master Windstrong, Deep Doubts, Deep Wisdom
(64432, 31360), -- Sinan the Dreamer, A New Lesson for the Master
(64432, 31357), -- Sinan the Dreamer, Relics of the Four Kings
(64467, 31363), -- Bowmistress Li, Lighting the Way
(64467, 31364), -- Bowmistress Li, That's a Big Bug!
(64517, 31365), -- Shado-Master Chum Kiu, Somewhere Inside
(64517, 31366), -- Shado-Master Chum Kiu, Take Down the Wing Leader
(64540, 31394), -- Anduin Wrynn, A Celestial Experience
(64540, 31392), -- Anduin Wrynn, Temple of the White Tiger
(64542, 31395), -- Sunwalker Dezco, A Celestial Experience
(64542, 31393), -- Sunwalker Dezco, Temple of the White Tiger
(64562, 31447), -- Talking Skull, An End to the Suffering
(64562, 31440), -- Talking Skull, The Four Tomes
(64563, 31448), -- Talking Skull, An End to the Suffering
(64563, 31442), -- Talking Skull, The Four Tomes
(64569, 31439), -- Hisek the Swarmkeeper, Dropping Our Signal
(64572, 32603), -- Sara Finkleswitch, Beasts of Fable
(64572, 32604), -- Sara Finkleswitch, Beasts of Fable Book I
(64572, 32868), -- Sara Finkleswitch, Beasts of Fable Book II
(64572, 32869), -- Sara Finkleswitch, Beasts of Fable Book III
(64572, 32428), -- Sara Finkleswitch, Pandaren Spirit Tamer
(64572, 32863), -- Sara Finkleswitch, What We've Been Training For
(64582, 32603), -- Gentle San, Beasts of Fable
(64582, 32604), -- Gentle San, Beasts of Fable Book I
(64582, 32868), -- Gentle San, Beasts of Fable Book II
(64582, 32869), -- Gentle San, Beasts of Fable Book III
(64582, 32428), -- Gentle San, Pandaren Spirit Tamer
(64582, 32863), -- Gentle San, What We've Been Training For
(64597, 32682), -- Nana Mudclaw, Inherit the Earth
(64597, 30519), -- Nana Mudclaw, Nana's Vote I: Nana's Secret Recipe
(64597, 31948), -- Nana Mudclaw, Nana's Vote II: The Sacred Springs
(64597, 31949), -- Nana Mudclaw, Nana's Vote III: Witchberry Julep
(64599, 31661), -- Ambersmith Zikk, A Source of Terrifying Power
(64599, 31008), -- Ambersmith Zikk, Amber Arms
(64599, 31108), -- Ambersmith Zikk, Concentrated Fear
(64599, 31598), -- Ambersmith Zikk, Kypa'rak's Core
(64599, 31023), -- Ambersmith Zikk, Relics of the Swarm
(64599, 31603), -- Ambersmith Zikk, Seeds of Fear
(64599, 31599), -- Ambersmith Zikk, The Matriarch's Maw
(64672, 31439), -- Hisek the Swarmkeeper, Dropping Our Signal
(64705, 31441), -- Hisek the Swarmkeeper, Corruption Runs Deep
(64738, 31493), -- Hooded Crusader, Just for Safekeeping, Of Course
(64738, 31490), -- Hooded Crusader, Rank and File
(64764, 31497), -- Hooded Crusader, Just for Safekeeping, Of Course
(64764, 31495), -- Hooded Crusader, Rank and File
(64815, 31066), -- Kor'ik, A Cry From Darkness
(64827, 31514), -- Hooded Crusader, Unto Dust Thou Shalt Return
(64838, 31516), -- Hooded Crusader, Unto Dust Thou Shalt Return
(64854, 31513), -- Blade of the Anointed, Blades of the Anointed
(64855, 31515), -- Blade of the Anointed, Blades of the Anointed
(65253, 31605), -- Rik'kal the Dissector, The Zan'thik Dig
(65289, 31058), -- Brewmaster Bo, The Funky Monkey Brew
(65341, 30933), -- Ku-Mo, Seeking Father
(65365, 31090), -- Kor'ik, Better With Age
(65365, 31088), -- Kor'ik, Crime and Punishment
(65365, 31087), -- Kor'ik, Extending Our Coverage
(65395, 32030), -- Klaxxi'va Ik, Once in a Hundred Lifetimes
(65454, 31441), -- Hisek the Swarmkeeper, Corruption Runs Deep
(65558, 29780), -- Huojin Monk, Do No Evil
(65558, 29781), -- Huojin Monk, Monkey Advisory Warning
(65558, 29779), -- Huojin Monk, The Direct Solution
(65648, 31724), -- Old MacDonald, Old MacDonald
(65648, 31780), -- Old MacDonald, Old MacDonald
(65651, 31725), -- Lindsay, Lindsay
(65651, 31781), -- Lindsay, Lindsay
(65655, 31726), -- Eric Davidson, Eric Davidson
(65655, 31850), -- Eric Davidson, Eric Davidson
(65656, 31728), -- Bill Buckler, Bill Buckler
(65656, 31851), -- Bill Buckler, Bill Buckler
(65669, 31704), -- Your Hatchling, Pooped
(65669, 30150), -- Your Hatchling, Sweet as Honey
(65670, 31704), -- Your Hatchling, Pooped
(65670, 30150), -- Your Hatchling, Sweet as Honey
(65671, 31704), -- Your Hatchling, Pooped
(65671, 30150), -- Your Hatchling, Sweet as Honey
(65672, 31704), -- Your Cloud Serpent, Pooped
(65672, 31716), -- Your Cloud Serpent, Pooped
(65672, 31708), -- Your Cloud Serpent, Serpent's Scale
(65672, 30150), -- Your Cloud Serpent, Sweet as Honey
(65672, 31710), -- Your Cloud Serpent, Tiny Treats
(65673, 31704), -- Your Cloud Serpent, Pooped
(65673, 31716), -- Your Cloud Serpent, Pooped
(65673, 31708), -- Your Cloud Serpent, Serpent's Scale
(65673, 30150), -- Your Cloud Serpent, Sweet as Honey
(65673, 31710), -- Your Cloud Serpent, Tiny Treats
(65674, 31704), -- Your Cloud Serpent, Pooped
(65674, 31716), -- Your Cloud Serpent, Pooped
(65674, 31708), -- Your Cloud Serpent, Serpent's Scale
(65674, 30150), -- Your Cloud Serpent, Sweet as Honey
(65674, 31710), -- Your Cloud Serpent, Tiny Treats
(65679, 31716), -- Golden Hatchling, Pooped
(65679, 31708), -- Golden Hatchling, Serpent's Scale
(65723, 31716), -- Jade Hatchling, Pooped
(65723, 31708), -- Jade Hatchling, Serpent's Scale
(65724, 31716), -- Azure Hatchling, Pooped
(65724, 31708), -- Azure Hatchling, Serpent's Scale
(65724, 31710), -- Azure Hatchling, Tiny Treats
(65910, 31736), -- Sunke Khang, Envoy of the Alliance
(65910, 31740), -- Sunke Khang, Koukou's Rampage
(65910, 31738), -- Sunke Khang, Pillaging Peons
(65975, 31681), -- Zer'ik, Better With Age
(65975, 31680), -- Zer'ik, Crime and Punishment
(65998, 31778), -- Merchant Zin, Unreliable Allies
(65999, 31775), -- General Nazgrim, Assault on the Airstrip
(65999, 29804), -- General Nazgrim, Seein' Red
(65999, 31776), -- General Nazgrim, Strongarm Tactics
(66126, 31818), -- Zunta, Zunta
(66126, 31812), -- Zunta, Zunta, The Pet Tamer
(66135, 31813), -- Dagra the Fierce, Dagra the Fierce
(66135, 31819), -- Dagra the Fierce, Dagra the Fierce
(66136, 31814), -- Analynn, Analynn
(66136, 31854), -- Analynn, Analynn
(66137, 31815), -- Zonya the Sadist, Zonya the Sadist
(66137, 31862), -- Zonya the Sadist, Zonya the Sadist
(66190, 31766), -- General Nazgrim, Touching Ground
(66199, 31739), -- Lin Applebloom, Priorities!
(66260, 31834), -- Master Hight, Begin Your Training: Master Cheng
(66260, 31944), -- Master Hight, Complete Your Training: The Final Test
(66260, 31837), -- Master Hight, Continue Your Training: Master Cheng
(66260, 31839), -- Master Hight, Continue Your Training: Master Hsu
(66260, 31835), -- Master Hight, Continue Your Training: Master Kistane
(66260, 31838), -- Master Hight, Continue Your Training: Master Tsang
(66260, 31833), -- Master Hight, Continue Your Training: Master Woo
(66260, 31836), -- Master Hight, Continue Your Training: Master Yoon
(66260, 31840), -- Master Hight, Practice Makes Perfect: Master Cheng
(66260, 31844), -- Master Hight, Practice Makes Perfect: Master Cheng
(66260, 31846), -- Master Hight, Practice Makes Perfect: Master Hsu
(66260, 31842), -- Master Hight, Practice Makes Perfect: Master Kistane
(66260, 31845), -- Master Hight, Practice Makes Perfect: Master Tsang
(66260, 31841), -- Master Hight, Practice Makes Perfect: Master Woo
(66260, 31843), -- Master Hight, Practice Makes Perfect: Master Yoon
(66260, 31856), -- Master Hight, The Peak of Serenity - Begin Your Training
(66260, 31989), -- Master Hight, The Peak of Serenity - Complete Your Training
(66260, 31855), -- Master Hight, The Peak of Serenity - Continue Your Training
(66260, 31857), -- Master Hight, The Peak of Serenity - Continue Your Training
(66260, 31858), -- Master Hight, The Peak of Serenity - Continue Your Training
(66260, 31859), -- Master Hight, The Peak of Serenity - Continue Your Training
(66260, 31860), -- Master Hight, The Peak of Serenity - Continue Your Training
(66260, 31861), -- Master Hight, The Peak of Serenity - Continue Your Training
(66292, 31745), -- Sky Admiral Rogers, Onward and Inward
(66292, 29548), -- Sky Admiral Rogers, The Mission
(66292, 31732), -- Sky Admiral Rogers, Unleash Hell
(66352, 31871), -- Traitor Gluk, Traitor Gluk
(66372, 31817), -- Merda Stronghoof, Merda Stronghoof
(66372, 31872), -- Merda Stronghoof, Merda Stronghoof
(66412, 31908), -- Elena Flutterfly, Elena Flutterfly
(66422, 31870), -- Cassandra Kaboom, Cassandra Kaboom
(66422, 31904), -- Cassandra Kaboom, Cassandra Kaboom
(66436, 31905), -- Grazzle the Great, Grazzle the Great
(66442, 31907), -- Zoltan, Zoltan
(66452, 31906), -- Kela Grimtotem, Kela Grimtotem
(66466, 31897), -- Stone Cold Trixxy, Grand Master Trixxy
(66466, 31909), -- Stone Cold Trixxy, Grand Master Trixxy
(66478, 31910), -- David Kosse, David Kosse
(66512, 31911), -- Deiza Plaguehorn, Deiza Plaguehorn
(66515, 31912), -- Kortas Darkhammer, Kortas Darkhammer
(66518, 31913), -- Everessa, Everessa
(66520, 31914), -- Durin Darkhammer, Durin Darkhammer
(66522, 31915), -- Lydia Accoste, Grand Master Lydia Accoste
(66522, 31916), -- Lydia Accoste, Grand Master Lydia Accoste
(66550, 31922), -- Nicki Tinytech, Nicki Tinytech
(66551, 31923), -- Ras'an, Ras'an
(66552, 31924), -- Narrok, Narrok
(66553, 31925), -- Morulu The Elder, Morulu The Elder
(66557, 31920), -- Bloodknight Antari, Grand Master Antari
(66557, 31926), -- Bloodknight Antari, Grand Master Antari
(66581, 30070), -- Rell Nightwind, The Fall of Ga'trul
(66635, 31931), -- Beegle Blastfuse, Beegle Blastfuse
(66636, 31932), -- Nearly Headless Jacob, Nearly Headless Jacob
(66638, 31933), -- Okrut Dragonwaste, Okrut Dragonwaste
(66639, 31934), -- Gutretch, Gutretch
(66646, 31767), -- General Nazgrim, Finish Them!
(66646, 31768), -- General Nazgrim, Fire Is Always the Answer
(66656, 31769), -- General Nazgrim, The Final Blow!
(66667, 31765), -- Rivett Clutchpop, Paint it Red!
(66675, 31928), -- Major Payne, Grand Master Payne
(66675, 31935), -- Major Payne, Grand Master Payne
(66730, 31953), -- Hyuna of the Shrines, Grand Master Hyuna
(66733, 31954), -- Mo'ruk, Grand Master Mo'ruk
(66734, 31955), -- Farmer Nishi, Grand Master Nishi
(66738, 31956), -- Courageous Yon, Grand Master Yon
(66739, 31957), -- Wastewalker Shu, Grand Master Shu
(66741, 31951), -- Aki the Chosen, Grand Master Aki
(66741, 31958), -- Aki the Chosen, Grand Master Aki
(66815, 31973), -- Bordin Steadyfist, Bordin Steadyfist
(66819, 31972), -- Brok, Brok
(66822, 31974), -- Goz Banefury, Goz Banefury
(66824, 31970), -- Obalis, Grand Master Obalis
(66824, 31971), -- Obalis, Grand Master Obalis
(66845, 29694), -- Sergeant Gorrok, Regroup!
(66918, 31991), -- Seeker Zusshi, Grand Master Zusshi
(66949, 29885), -- Rell Nightwind, Road Rations
(66949, 29883), -- Rell Nightwind, The Pearlfin Situation
(66998, 32901), -- Jinho the Wind Breaker, Heroic Deeds
(67091, 31606), -- Rik'kal the Dissector, The Dissector Wakens
(67091, 31605), -- Rik'kal the Dissector, The Zan'thik Dig
(67138, 31077), -- Chen Stormstout, Evie Stormstout
(67153, 29765), -- Zin'Jun, Cryin' My Eyes Out
(67370, 32175), -- Jeremy Feasel, Darkmoon Pet Battle!
(67386, 32452), -- Sky Admiral Rogers, And Then There Were Goblins
(67386, 32146), -- Sky Admiral Rogers, Hammer to Fall
(67386, 32451), -- Sky Admiral Rogers, Send A Message
(67386, 32157), -- Sky Admiral Rogers, The Only Good Goblin...
(67386, 32142), -- Sky Admiral Rogers, We Will Rock You
(67402, 32130), -- Zazzix "Toasty" Sparkrocket, Good Luck, Have Fun
(67402, 32134), -- Zazzix "Toasty" Sparkrocket, Hard Counter
(67402, 32131), -- Zazzix "Toasty" Sparkrocket, We Require More Minerals!
(67444, 32156), -- Mishka, It's Only Right
(67444, 32144), -- Mishka, Under Pressure
(67533, 32238), -- Bixy Buzzsaw, Universal Remote-Explode
(67534, 32139), -- Zino "The Shredder" Quickchop, Stacked!
(67534, 32138), -- Zino "The Shredder" Quickchop, Work Order: Lumber
(67535, 32141), -- Boss-Lady Trixel, Power Metal
(67535, 32137), -- Boss-Lady Trixel, Runnin' On Empty
(67537, 32140), -- Daxil "The Gem" Oregrind, Work Order: Iron
(67542, 32136), -- Grizzle Gearslip, Work Order: Fuel
(67553, 32237), -- Bixy Buzzsaw, Precious Resource
(67554, 32236), -- Bixy Buzzsaw, Bug Off!
(67565, 32189), -- Barnaby Fletcher, A Shabby New Face
(67565, 32198), -- Barnaby Fletcher, One Magical, Flying Kingdom's Trash...
(67581, 32192), -- Lor'themar Theron, Bloodlines
(67581, 32190), -- Lor'themar Theron, To Mogujia
(67603, 32191), -- Fanlyr Silverthorn, Ancient Guardians
(67603, 32244), -- Fanlyr Silverthorn, The Korune
(67608, 32214), -- Rivett Clutchpop, Bilgewater Infiltrators
(67608, 32221), -- Rivett Clutchpop, Storming the Beach
(67618, 32123), -- Shokia, Death on Two Legs
(67628, 32135), -- Shademaster Kiryn, Hero Killer
(67628, 32133), -- Shademaster Kiryn, Sentry Wards
(67628, 32450), -- Shademaster Kiryn, The Time Is Now!
(67628, 32132), -- Shademaster Kiryn, Worker Harassment
(67630, 32149), -- Mishka, Resource Gathering
(67630, 32150), -- Mishka, Supply Block
(67631, 32148), -- Marshal Troteman, Attack! Move!
(67631, 32153), -- Marshal Troteman, Hero Killer
(67631, 32152), -- Marshal Troteman, Siege Damage
(67631, 32151), -- Marshal Troteman, Tower Defense
(67660, 32255), -- Archmage Aethas Sunreaver, De-Constructed
(67660, 32730), -- Archmage Aethas Sunreaver, Ihgaluk Crag
(67660, 32254), -- Archmage Aethas Sunreaver, Manipulating the Saurok
(67660, 32605), -- Archmage Aethas Sunreaver, Subtle Encouragement
(67660, 32204), -- Archmage Aethas Sunreaver, The Skumblade Threat
(67662, 32265), -- High Arcanist Savor, Charged Moganite
(67662, 32287), -- High Arcanist Savor, Enemies Beneath the Tower
(67662, 32303), -- High Arcanist Savor, Made for War
(67662, 32264), -- High Arcanist Savor, Spellbound
(67662, 32285), -- High Arcanist Savor, The Sleepless Legion
(67663, 32506), -- Magister Hathorel, A Wing to Fly On
(67663, 32288), -- Magister Hathorel, Bolstering the Defenses
(67663, 32262), -- Magister Hathorel, Captive Audience
(67663, 32300), -- Magister Hathorel, Disarming Irony
(67663, 32305), -- Magister Hathorel, Overpowered
(67673, 32269), -- Girana the Blooded, Breaking Down the Defenses
(67673, 32302), -- Girana the Blooded, Desconstruction
(67673, 32266), -- Girana the Blooded, Mana Manifestations
(67673, 32268), -- Girana the Blooded, Tactical Mana Bombs
(67673, 32228), -- Girana the Blooded, The Shuddering Moor
(67673, 32230), -- Girana the Blooded, The Zandalari Colossus
(67716, 32243), -- Hilda Hornswaggle, The Source of Korune Power
(67734, 32194), -- Sarannha Skyglaive, Bad Blood
(67734, 32393), -- Sarannha Skyglaive, The Ruins of Korune
(67767, 32127), -- Brolic, All Dead, All Dead
(67767, 32126), -- Brolic, Tear It Up
(67834, 32242), -- Fanlyr Silverthorn, Buried Secrets
(67834, 32257), -- Fanlyr Silverthorn, Voice of the Gods
(67840, 32352), -- Garrosh Hellscream, A Gathering Storm
(67840, 32256), -- Garrosh Hellscream, Rise Of An Empire
(67844, 32398), -- Malkorok, The Bell Speaks
(67847, 32449), -- Belloc Brightblade, The Ruins of Ogudei
(67866, 32318), -- Chen Stormstout, Regeneration Takes Time
(67866, 32284), -- Chen Stormstout, Someone You Should See
(67880, 32128), -- Blood Guard Gro'tash, Another One Bites the Dust
(67880, 32235), -- Blood Guard Gro'tash, Flash! Aaaaaahhhh!
(67880, 32222), -- Blood Guard Gro'tash, Wanted: Chief Engineer Cogwrench
(67880, 32223), -- Blood Guard Gro'tash, Wanted: Lieutenant Ethan Jacobson
(67939, 32413), -- General Nazgrim, A Return to Krasarang
(67939, 32328), -- General Nazgrim, Victorious Return
(67948, 32315), -- Anduin Wrynn, Anduin's Plea
(67976, 32145), -- Tinkmaster Overspark, Don't Lose Your Head
(67983, 32218), -- Captain Aerthas Firehawk, Ashes of the Enemy
(67984, 32227), -- Kethiel Sunlance, Preventing a Future Threat
(67984, 32216), -- Kethiel Sunlance, Pterrible Ptorment
(67985, 32282), -- Scout Captain Elsia, Compy Stomp
(67985, 32298), -- Scout Captain Elsia, Dino Might
(67985, 32563), -- Scout Captain Elsia, Encroaching Force
(67985, 32565), -- Scout Captain Elsia, Encroaching Force
(67985, 32294), -- Scout Captain Elsia, Raining Bones
(67985, 32523), -- Scout Captain Elsia, The Beast Pens
(67985, 32524), -- Scout Captain Elsia, The Beating of Troll Drums
(67985, 32206), -- Scout Captain Elsia, This Just Won't Do
(67985, 32233), -- Scout Captain Elsia, Very Disarming
(67985, 32232), -- Scout Captain Elsia, What's Inside Counts
(67985, 32564), -- Scout Captain Elsia, Zandalari on the Rise
(67986, 32297), -- Magister Edien Sunhollow, Direhorn or Devilsaur
(67986, 32234), -- Magister Edien Sunhollow, Knowledge Is Power
(67986, 32283), -- Magister Edien Sunhollow, Loa-saur
(67986, 32494), -- Magister Edien Sunhollow, Power Play
(67986, 32207), -- Magister Edien Sunhollow, Saur Loser
(67986, 32493), -- Magister Edien Sunhollow, They All Fall Down
(67989, 32201), -- Grand Magister Rommath, Grave Circumstances
(67989, 32220), -- Grand Magister Rommath, Soul Surrender
(67989, 32495), -- Grand Magister Rommath, The Bloodletter
(67989, 32225), -- Grand Magister Rommath, The Call of Thunder
(67989, 32728), -- Grand Magister Rommath, The Court of Bones
(67990, 32293), -- Lor'themar Theron, Among the Bones
(67990, 32520), -- Lor'themar Theron, Competing Magic
(67990, 32561), -- Lor'themar Theron, Competing Magic
(67990, 32278), -- Lor'themar Theron, Decisive Action
(67990, 32521), -- Lor'themar Theron, Encroaching Force
(67990, 32676), -- Lor'themar Theron, Extended Shore Leave
(67990, 32304), -- Lor'themar Theron, High Recognition
(67990, 32522), -- Lor'themar Theron, Imposing Threat
(67990, 32562), -- Lor'themar Theron, Imposing Threat
(67990, 32589), -- Lor'themar Theron, Life Blood
(67990, 32213), -- Lor'themar Theron, Old Enemies
(67990, 32677), -- Lor'themar Theron, Raiding the Vault
(67990, 32276), -- Lor'themar Theron, Tear Down This Wall!
(67990, 32212), -- Lor'themar Theron, The Assault on Zeb'tula
(67990, 32279), -- Lor'themar Theron, The Fall of Shan Bu
(67990, 32680), -- Lor'themar Theron, The Storm Gathers
(67990, 32277), -- Lor'themar Theron, To the Skies!
(67992, 32655), -- Lady Jaina Proudmoore, A Bold Idea
(67992, 32578), -- Lady Jaina Proudmoore, Among the Bones
(67992, 32485), -- Lady Jaina Proudmoore, Bolstering the Defenses
(67992, 32636), -- Lady Jaina Proudmoore, Captive Audience
(67992, 32576), -- Lady Jaina Proudmoore, Competing Magic
(67992, 32579), -- Lady Jaina Proudmoore, Competing Magic
(67992, 32580), -- Lady Jaina Proudmoore, Encroaching Force
(67992, 32635), -- Lady Jaina Proudmoore, Enough with the Bombs!
(67992, 32607), -- Lady Jaina Proudmoore, Extended Shore Leave
(67992, 32631), -- Lady Jaina Proudmoore, High Recognition
(67992, 32577), -- Lady Jaina Proudmoore, Imposing Threat
(67992, 32581), -- Lady Jaina Proudmoore, Imposing Threat
(67992, 32637), -- Lady Jaina Proudmoore, Overpowered
(67992, 32608), -- Lady Jaina Proudmoore, Raiding the Vault
(67992, 32599), -- Lady Jaina Proudmoore, Securing A Future
(67992, 32654), -- Lady Jaina Proudmoore, Tear Down This Wall!
(67992, 32644), -- Lady Jaina Proudmoore, The Assault on Shaol'mara
(67992, 32656), -- Lady Jaina Proudmoore, The Fall of Shan Bu
(67992, 32681), -- Lady Jaina Proudmoore, The Storm Gathers
(67992, 32652), -- Lady Jaina Proudmoore, To the Skies!
(67993, 32301), -- Vereesa Windrunner, Old Enemies
(67993, 32574), -- Vereesa Windrunner, The Shuddering Moor
(67993, 32575), -- Vereesa Windrunner, The Zandalari Colossus
(67994, 32571), -- Warmage Yurias, A Wing to Fly On
(67994, 32627), -- Warmage Yurias, Charged Moganite
(67994, 32632), -- Warmage Yurias, Made for War
(67994, 32633), -- Warmage Yurias, Spellbound
(67995, 32634), -- Captain Elleane Wavecrest, Breaking Down the Defenses
(67995, 32639), -- Captain Elleane Wavecrest, Deconstruction
(67995, 32573), -- Captain Elleane Wavecrest, Enemies Beneath the Tower
(67995, 32638), -- Captain Elleane Wavecrest, Mana Scavengers
(67995, 32628), -- Captain Elleane Wavecrest, Tactical Mana Bombs
(67995, 32572), -- Captain Elleane Wavecrest, The Sleepless Legion
(67996, 32537), -- Archmage Modera, De-Constructed
(67996, 32732), -- Archmage Modera, Ihgaluk Crag
(67996, 32536), -- Archmage Modera, Manipulating the Saurok
(67996, 32606), -- Archmage Modera, Subtle Encouragement
(67996, 32535), -- Archmage Modera, The Skumblade Threat
(67997, 32527), -- Narasi Snowdawn, Grave Circumstances
(67997, 32526), -- Narasi Snowdawn, Soul Surrender
(67997, 32731), -- Narasi Snowdawn, The Court of Bones
(67998, 32551), -- Scout Captain Daelin, Compy Stomp
(67998, 32554), -- Scout Captain Daelin, Dino Might
(67998, 32584), -- Scout Captain Daelin, Encroaching Force
(67998, 32585), -- Scout Captain Daelin, Encroaching Force
(67998, 32559), -- Scout Captain Daelin, Even Giants Fall
(67998, 32560), -- Scout Captain Daelin, Keep It Secret
(67998, 32568), -- Scout Captain Daelin, No Time To Rest
(67998, 32557), -- Scout Captain Daelin, Out of Enemy Hands
(67998, 32582), -- Scout Captain Daelin, Raining Bones
(67998, 32550), -- Scout Captain Daelin, Saur Loser
(67998, 32567), -- Scout Captain Daelin, The Beast Pens
(67998, 32583), -- Scout Captain Daelin, Zandalari on the Rise
(67999, 32558), -- Miura Brightweaver, All In the Family
(67999, 32555), -- Miura Brightweaver, Centuries in Sentries
(67999, 32553), -- Miura Brightweaver, Direhorn vs Devilsaur
(67999, 32552), -- Miura Brightweaver, Loa-saur
(67999, 32556), -- Miura Brightweaver, The More You Know
(68003, 32321), -- The Monkey King, The Monkey King
(68004, 32335), -- Anduin Wrynn, The Greatest Prank
(68004, 32355), -- Anduin Wrynn, The Harmonic Mallet
(68025, 32372), -- Thrall, De-Subjugation
(68025, 32319), -- Thrall, Find Thrall!
(68025, 32320), -- Thrall, The Horde Is Family
(68072, 32250), -- Kor'kron Bodyguard, The Might of the Warchief
(68077, 32326), -- Fanlyr Silverthorn, Insertion
(68077, 32327), -- Fanlyr Silverthorn, The Darnassus Mission
(68106, 32362), -- Anduin Wrynn, The Fate of Dalaran
(68106, 32331), -- Anduin Wrynn, The Kirin Tor
(68166, 32154), -- Sully "The Pickle" McLeary, Burn Out!
(68166, 32446), -- Sully "The Pickle" McLeary, Dis-Assembly Required
(68182, 32158), -- Seraphine of the Winter, Two Step Program
(68274, 32344), -- Kaelis Sunsoar, It Is A Mystery
(68274, 32348), -- Kaelis Sunsoar, Kick 'em While They're Down
(68274, 32120), -- Kaelis Sunsoar, Legacy of Ogudei
(68274, 32343), -- Kaelis Sunsoar, Ogudei's Lieutenants
(68274, 32118), -- Kaelis Sunsoar, Taking Advantage
(68274, 32342), -- Kaelis Sunsoar, The Spirit Trap
(68274, 32345), -- Kaelis Sunsoar, We're Not Monsters!
(68275, 32347), -- Hilda Hornswaggle, Eviction Notice
(68275, 32119), -- Hilda Hornswaggle, It Is A Mystery
(68275, 32122), -- Hilda Hornswaggle, Ogudei's Lieutenants
(68275, 32346), -- Hilda Hornswaggle, Oi Ain't Afraid o' No Ghosts!
(68275, 32116), -- Hilda Hornswaggle, Priorities, People!
(68275, 32115), -- Hilda Hornswaggle, Shackles of the Past
(68275, 32121), -- Hilda Hornswaggle, The Spirit Trap
(68287, 32351), -- Baine Bloodhoof, Echoes of Thunder
(68287, 32368), -- Baine Bloodhoof, Memory Wine
(68287, 32363), -- Baine Bloodhoof, The Kun-Lai Expedition
(68287, 32448), -- Baine Bloodhoof, Ties with the Past
(68337, 32392), -- Ishi, The Divine Bell
(68337, 32391), -- Ishi, The Ruins of Korune
(68370, 32378), -- Lor'themar Theron, Clearing a Path
(68370, 32379), -- Lor'themar Theron, Legacy of the Korune
(68370, 32376), -- Lor'themar Theron, To the Valley!
(68370, 32384), -- Lor'themar Theron, Trapping the Leader
(68375, 32377), -- Agent Connelly, A Kor'kron In Our Midst
(68375, 32371), -- Agent Connelly, Memory Wine
(68375, 32370), -- Agent Connelly, The Kun-Lai Expedition
(68399, 32247), -- 7th Legion Champion, A King Among Men
(68417, 32383), -- Cousin Goottooth, Bugging Out
(68417, 32397), -- Cousin Goottooth, He Won't Even Miss It
(68417, 32382), -- Cousin Goottooth, He's In Deep
(68462, 32439), -- Flowing Pandaren Spirit, Flowing Pandaren Spirit
(68463, 32434), -- Burning Pandaren Spirit, Burning Pandaren Spirit
(68464, 32440), -- Whispering Pandaren Spirit, Whispering Pandaren Spirit
(68465, 32441), -- Thundering Pandaren Spirit, Thundering Pandaren Spirit
(68526, 32380), -- Barkeep Townsley, The Best Around
(68526, 32381), -- Barkeep Townsley, To Catch A Spy
(68538, 32332), -- The Monkey King, The First Riddle: Mercy
(68538, 32336), -- The Monkey King, The Handle
(68538, 32338), -- The Monkey King, The Harmonic Ointment
(68538, 32337), -- The Monkey King, The Head
(68538, 32333), -- The Monkey King, The Second Riddle: Fellowship
(68538, 32334), -- The Monkey King, The Third Riddle: Strength
(68586, 32406), -- Grand Magister Rommath, A Tactical Assault
(68586, 32405), -- Grand Magister Rommath, Hand of the Silver Covenant
(68586, 32403), -- Grand Magister Rommath, It Starts in the Sewers
(68586, 32410), -- Grand Magister Rommath, Krasus' Landing
(68586, 32409), -- Grand Magister Rommath, The Kirin Tor's True Colors
(68586, 32411), -- Grand Magister Rommath, The Remaining Sunreavers
(68586, 32408), -- Grand Magister Rommath, The Silver Covenant's Stronghold
(68586, 32402), -- Grand Magister Rommath, The Situation In Dalaran
(68586, 32404), -- Grand Magister Rommath, Violence in the Arena
(68651, 32414), -- Lady Jaina Proudmoore, Darnassus Attacked?
(68651, 32460), -- Lady Jaina Proudmoore, Tracking the Thieves
(68687, 32420), -- Vereesa Windrunner, Cashing Out
(68687, 32416), -- Vereesa Windrunner, Jaina's Resolution
(68687, 32419), -- Vereesa Windrunner, Nowhere to Hide
(68687, 32421), -- Vereesa Windrunner, Nowhere to Run
(68687, 32417), -- Vereesa Windrunner, Sewer Cleaning
(68687, 32418), -- Vereesa Windrunner, Unfair Trade
(68939, 32400), -- Anduin Wrynn, The Bell Speaks
(68987, 32401), -- Anduin Wrynn, Breath of Darkest Shadow
(69371, 32299), -- Amalia Penshire, Just Some Light Clean-Up Work
(69371, 32491), -- Amalia Penshire, Left To Rot
(69371, 32489), -- Amalia Penshire, The Creeping Carpet of Ihgaluk
(69389, 32226), -- Ryshelle Brightlock, Into the Crypts
(69389, 32224), -- Ryshelle Brightlock, Rise No More!
(69389, 32219), -- Ryshelle Brightlock, Stone Cold
(69389, 32517), -- Ryshelle Brightlock, The Conquest of Stone
(69418, 32217), -- Elina Zaralae, Dark Offerings
(69418, 32215), -- Elina Zaralae, Heinous Sacrifice
(69425, 32274), -- Sunwalker Dezco, The Residents of Ihgaluk
(69551, 32509), -- Vale of Eternal Blossoms Flame Keeper, Honor the Flame
(69572, 32510), -- Vale of Eternal Blossoms Flame Warden, Honor the Flame
(69668, 32525), -- Danara Silverglass, Ashes of the Enemy
(69668, 32528), -- Danara Silverglass, Into the Crypts
(69668, 32532), -- Danara Silverglass, Rise No More!
(69668, 32533), -- Danara Silverglass, Stone Cold
(69670, 32530), -- Vylene Amaranth, The Bloodletter
(69670, 32529), -- Vylene Amaranth, The Call of Thunder
(69670, 32531), -- Vylene Amaranth, The Conquest of Stone
(69673, 32541), -- Ako, Preventing a Future Threat
(69673, 32544), -- Ako, Pterrible Ptorment
(69674, 32539), -- Dalvin Jaacor, Dark Offerings
(69674, 32538), -- Dalvin Jaacor, Heinous Sacrifice
(69675, 32545), -- Lyalia, The Residents of Ihgaluk
(69677, 32546), -- Sanitation Sorcerer Stephen Litmatch, Just Some Light Clean-Up Work
(69677, 32548), -- Sanitation Sorcerer Stephen Litmatch, Left To Rot
(69677, 32547), -- Sanitation Sorcerer Stephen Litmatch, The Creeping Carpet of Ihgaluk
(70022, 32616), -- Ku'ma, A Large Pile of Giant Dinosaur Bones
(70022, 32617), -- Ku'ma, A Mountain of Giant Dinosaur Bones
(70022, 32613), -- Ku'ma, Giant Dinosaur Bone
(70022, 32615), -- Ku'ma, Many More Giant Dinosaur Bones
(70022, 32614), -- Ku'ma, More Giant Dinosaur Bones
(70160, 32706), -- Taran Zhu, Allies in the Shadows
(70160, 32709), -- Taran Zhu, Allies in the Shadows
(70160, 32640), -- Taran Zhu, Champions of the Thunder King
(70160, 32641), -- Taran Zhu, Champions of the Thunder King
(70160, 32707), -- Taran Zhu, Secrets in the Isle of Thunder
(70160, 32708), -- Taran Zhu, Setting the Trap
(70316, 32296), -- Taoshi, Treasures of the Thunder King
(70358, 32678), -- Scout Captain Elsia, Thunder Calls
(70360, 32679), -- Vereesa Windrunner, Thunder Calls
(70398, 32685), -- Ben of the Booming Voice, No Fishing Pole Necessary!
(70398, 32684), -- Ben of the Booming Voice, You Want Fish?
(70517, 32543), -- Archmage Lan'dalock, Dangers of Za'Tual
(70517, 32540), -- Archmage Lan'dalock, Harbingers of the Loa
(70517, 32542), -- Archmage Lan'dalock, Surgical Strike
(70517, 32733), -- Archmage Lan'dalock, Za'Tual
(70520, 32200), -- Halduron Brightwing, Dangers of Za'Tual
(70520, 32252), -- Halduron Brightwing, Harbingers of the Loa
(70520, 32275), -- Halduron Brightwing, Surgical Death
(70520, 32729), -- Halduron Brightwing, Za'Tual
(70751, 32836), -- Card Trader Ami, A Knockoff Grumplefloot
(70751, 32838), -- Card Trader Ami, A Tale of Romance and Chivalry
(70751, 32851), -- Card Trader Ami, Blingtron 3000
(70751, 32840), -- Card Trader Ami, Boom Boom's Fuse
(70751, 32849), -- Card Trader Ami, Dippy and Doopy
(70751, 32848), -- Card Trader Ami, Frost-Tipped Eggshell
(70751, 32837), -- Card Trader Ami, Grandpa Grumplefloot
(70751, 32850), -- Card Trader Ami, Last Year's Model
(70751, 32841), -- Card Trader Ami, Master Boom Boom
(70751, 32847), -- Card Trader Ami, Mecha-Bruce
(70751, 32853), -- Card Trader Ami, Mingus Diggs
(70751, 32846), -- Card Trader Ami, Modified Chomping Apparatus
(70751, 32856), -- Card Trader Ami, Paper-Covered Rock
(70751, 32858), -- Card Trader Ami, Raptorhide Boxing Gloves
(70751, 32843), -- Card Trader Ami, Razorgrin
(70751, 32857), -- Card Trader Ami, Ro-Shambo
(70751, 32844), -- Card Trader Ami, Secret of the Ooze
(70751, 32845), -- Card Trader Ami, Splat
(70751, 32842), -- Card Trader Ami, Teeth Like Swords
(70751, 32839), -- Card Trader Ami, The Bear and the Lady Fair
(70751, 32855), -- Card Trader Ami, The Blind Hero
(70751, 32852), -- Card Trader Ami, The Digmaster's Earthblade
(70751, 32859), -- Card Trader Ami, Ty'thar
(70751, 32854), -- Card Trader Ami, Well-Worn Blindfold
(70752, 32836), -- Card Trader Leila, A Knockoff Grumplefloot
(70752, 32838), -- Card Trader Leila, A Tale of Romance and Chivalry
(70752, 32851), -- Card Trader Leila, Blingtron 3000
(70752, 32840), -- Card Trader Leila, Boom Boom's Fuse
(70752, 32849), -- Card Trader Leila, Dippy and Doopy
(70752, 32848), -- Card Trader Leila, Frost-Tipped Eggshell
(70752, 32837), -- Card Trader Leila, Grandpa Grumplefloot
(70752, 32850), -- Card Trader Leila, Last Year's Model
(70752, 32841), -- Card Trader Leila, Master Boom Boom
(70752, 32847), -- Card Trader Leila, Mecha-Bruce
(70752, 32853), -- Card Trader Leila, Mingus Diggs
(70752, 32846), -- Card Trader Leila, Modified Chomping Apparatus
(70752, 32856), -- Card Trader Leila, Paper-Covered Rock
(70752, 32858), -- Card Trader Leila, Raptorhide Boxing Gloves
(70752, 32843), -- Card Trader Leila, Razorgrin
(70752, 32857), -- Card Trader Leila, Ro-Shambo
(70752, 32844), -- Card Trader Leila, Secret of the Ooze
(70752, 32845), -- Card Trader Leila, Splat
(70752, 32842), -- Card Trader Leila, Teeth Like Swords
(70752, 32839), -- Card Trader Leila, The Bear and the Lady Fair
(70752, 32855), -- Card Trader Leila, The Blind Hero
(70752, 32852), -- Card Trader Leila, The Digmaster's Earthblade
(70752, 32859), -- Card Trader Leila, Ty'thar
(70752, 32854), -- Card Trader Leila, Well-Worn Blindfold
(70980, 32816), -- Seer Hao Pham Roo, Path of the Last Emperor
(72426, 33018), -- Lin Chao-Wei, Noodle Secrets Long Forgotten
(72751, 32974), -- Mound of Dirt, Rolo's Riddle
(72754, 32975), -- Mound of Dirt, Rolo's Riddle
(72870, 33161), -- Kairoz, A Timeless Tour
(72870, 33337), -- Kairoz, A Vision in Time
(72870, 33378), -- Kairoz, Courting Destiny
(72870, 33338), -- Kairoz, Empowering the Hourglass
(72870, 33377), -- Kairoz, Hidden Threads
(72870, 33332), -- Kairoz, Hints From The Past
(72870, 33379), -- Kairoz, One Final Turn
(72870, 33375), -- Kairoz, Refining The Vision
(72870, 33376), -- Kairoz, Seeking Fate
(72870, 33334), -- Kairoz, Strong Enough To Survive
(72870, 33336), -- Kairoz, The Essence of Time
(72870, 33228), -- Kairoz, Time In Your Hands
(72870, 33156), -- Kairoz, Time Keeper Kairoz
(72870, 33160), -- Kairoz, Time Keeper Kairoz
(72870, 33333), -- Kairoz, Timeless Treasures
(73082, 33137), -- Master Li, The Celestial Tournament
(73082, 33136), -- Master Li, The Rainy Day is Here
(73303, 33342), -- Emperor Shaohao, Drive Back The Flame
(73303, 33374), -- Emperor Shaohao, Path of the Mistwalker
(73303, 33343), -- Emperor Shaohao, The Archiereus Of Flame
(73303, 33335), -- Emperor Shaohao, The Last Emperor
(73303, 33340), -- Emperor Shaohao, Timeless Nutriment
(73303, 33341), -- Emperor Shaohao, Wayshrines Of The Celestials
(73318, 33147), -- Lorewalker Cho, The Last Gasp of Y'Shaarj
(73348, 33231), -- Watcher Lara, Journey to the Timeless Isle
(73353, 33232), -- Watcher Alundra, Journey to the Timeless Isle
(73570, 33211), -- Senior Historian Evelyna, A Timeless Question
(73626, 33222), -- Little Tommy Newcomer, Little Tommy Newcomer
(73657, 33235), -- Great Chef Woo, Great Turtle Meat
(73657, 33236), -- Great Chef Woo, Heavy Yak Flank
(73657, 33234), -- Great Chef Woo, Meaty Crane Leg
(73657, 33239), -- Great Chef Woo, Pristine Firestorm Egg
(73657, 33238), -- Great Chef Woo, Thick Tiger Haunch
(73691, 33229), -- Chromie, A Flash of Bronze...
(73691, 33230); -- Chromie, A Flash of Bronze...
