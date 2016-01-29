UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (74125, 74593, 74594, 74606, 74611, 75008, 75127, 75136, 75146, 75593, 75710, 75878, 76688, 77014, 78187, 78251, 79320, 79322, 79331, 80757, 80762, 80856, 80921, 80978, 81076, 81202, 81218, 81241, 81588, 81589, 81590, 81601, 81731, 81751, 82222, 82225, 82228, 82233, 82254, 82274, 82334, 82337, 82476, 82477, 82569, 82574, 82575, 82610, 82732, 82832, 83837, 84131, 84176, 84185, 84743, 85077, 85089, 85119, 85147, 85426, 85431, 85432, 85436, 85601, 88530, 89179, 89937, 90177, 90180, 92401, 76987, 80874, 80922, 81185, 82499, 83569, 84748, 86088, 78030, 81772, 82338, 85278, 85980);

DELETE FROM `creature_queststarter` WHERE `id` IN (74125, 74593, 74594, 74606, 74611, 75008, 75127, 75136, 75146, 75593, 75710, 75878, 76688, 77014, 78187, 78251, 79320, 79322, 79331, 80757, 80762, 80856, 80921, 80978, 81076, 81202, 81218, 81241, 81588, 81589, 81590, 81601, 81731, 81751, 82222, 82225, 82228, 82233, 82254, 82274, 82334, 82337, 82476, 82477, 82569, 82574, 82575, 82610, 82732, 82832, 83837, 84131, 84176, 84185, 84743, 85077, 85089, 85119, 85147, 85426, 85431, 85432, 85436, 85601, 88530, 89179, 89937, 90177, 90180, 92401, 76987, 80874, 80922, 81185, 82499, 83569, 84748, 86088, 78030, 81772, 82338, 85278, 85980);
DELETE FROM `creature_questender` WHERE `id` IN (74125, 74593, 74594, 74606, 74611, 75008, 75127, 75136, 75146, 75593, 75710, 75878, 76688, 77014, 78187, 78251, 79320, 79322, 79331, 80757, 80762, 80856, 80921, 80978, 81076, 81202, 81218, 81241, 81588, 81589, 81590, 81601, 81731, 81751, 82222, 82225, 82228, 82233, 82254, 82274, 82334, 82337, 82476, 82477, 82569, 82574, 82575, 82610, 82732, 82832, 83837, 84131, 84176, 84185, 84743, 85077, 85089, 85119, 85147, 85426, 85431, 85432, 85436, 85601, 88530, 89179, 89937, 90177, 90180, 92401, 78030, 81772, 82338, 85278, 85980);

INSERT INTO `creature_queststarter` VALUES
(74125, 34340), -- Aren Mistshade, Heating Up
(74593, 35432), -- Draka, Bushwhacker
(74593, 35400), -- Draka, The Infested
(74594, 33593), -- Durotan, A Flare for the Dramatic
(74594, 36494), -- Durotan, News from Talador
(74594, 36434), -- Durotan, Penny From Heaven
(74594, 35880), -- Durotan, Rage and Wisdom
(74594, 36574), -- Durotan, Strike While the Iron is Hot
(74594, 36573), -- Durotan, Strike While the Iron is Hot
(74594, 33543), -- Durotan, The Laughing Skull
(74594, 36474), -- Durotan, The Razorbloom
(74594, 35151), -- Durotan, Your Base, Your Choice
(74606, 35430), -- Kaz the Shrieker, Cutter
(74606, 35399), -- Kaz the Shrieker, Mossy Fate
(74606, 35429), -- Kaz the Shrieker, Pollen Power
(74606, 35402), -- Kaz the Shrieker, The Voice of Iyu
(74611, 33563), -- Limbflayer, Eye Candy
(75008, 34012), -- Prowler Sasha, Need More Teeth
(75127, 36495), -- Vindicator Maraad, News from Talador
(75127, 35686), -- Vindicator Maraad, Rage and Wisdom
(75127, 36575), -- Vindicator Maraad, Strike While the Iron is Hot
(75127, 36576), -- Vindicator Maraad, Strike While the Iron is Hot
(75136, 35212), -- Thaelin Darkanvil, Deeproot
(75136, 35055), -- Thaelin Darkanvil, Lost Mole Machines
(75136, 35063), -- Thaelin Darkanvil, We Need An Outpost
(75146, 36595), -- Rangari D'kaan, He Drew Aggro...culture
(75146, 35666), -- Rangari D'kaan, Rangari in the Red
(75146, 35050), -- Rangari D'kaan, Rescue Rangari
(75146, 36432), -- Rangari D'kaan, Seeking the Scout
(75593, 33633), -- Rooter, Rooter the Ravenous
(75710, 35229), -- Hansel Heavyhands, Down the Goren Hole
(75710, 35233), -- Hansel Heavyhands, Just In Case
(75710, 35234), -- Hansel Heavyhands, Will of the Genesaur
(75878, 35255), -- Yrel, Power of the Genesaur
(76688, 34697), -- Limbflayer, A Rediscovered Legend
(76688, 36108), -- Limbflayer, Trophy Hunter of Gorgrond
(77014, 34703), -- Bruto, The Axe of Kor'gall
(78187, 34336), -- Thisalee Crow, Ambushing the Enemy
(78187, 34337), -- Thisalee Crow, The Giant Cauldron
(78251, 34341), -- Thisalee Crow, The Beating Heart
(78251, 34410), -- Thisalee Crow, The Beating Heart
(78251, 34338), -- Thisalee Crow, The Descent
(79320, 34700), -- Kash'drakor, Nazgrel
(79320, 34698), -- Kash'drakor, Slave Hunters
(79320, 35152), -- Kash'drakor, The Sparring Arena
(79322, 34699), -- Gladiator Akaani, Getting Gladiators
(79322, 35137), -- Gladiator Akaani, The Sparring Arena
(79331, 34702), -- Beatface, Krav'ogra
(80757, 35030), -- Grulkor, A Grim Harvest
(80757, 35031), -- Grulkor, A Heartfelt Search
(80757, 35027), -- Grulkor, Clearing the Way
(80757, 35029), -- Grulkor, The Secret of the Fungus
(80762, 35633), -- Khaano, Scout Forensics
(80856, 35037), -- Rexxar, Bad at Breaking
(80856, 35128), -- Rexxar, Fair Warning
(80856, 35218), -- Rexxar, Iron Horde Orders
(80856, 35129), -- Rexxar, Leave Every Soldier Behind
(80856, 35934), -- Rexxar, Nisha's Vengeance
(80921, 35065), -- Rangari D'kaan, A Harvester Has Come
(80978, 35033), -- Yrel, Welcome to Gorgrond
(81076, 34704), -- Rangari Jonaa, A Rediscovered Legend
(81076, 36107), -- Rangari Jonaa, Trophy Hunter of Gorgrond
(81202, 35248), -- Bony Xuk, A Harsh Reminder
(81202, 35035), -- Bony Xuk, Seedbearers of Bad News
(81202, 35025), -- Bony Xuk, We Have Company
(81218, 35016), -- Grulkor, Basic Skulltaking
(81241, 35040), -- Grulkor, Heart of the Fen
(81588, 35225), -- Thaelin Darkanvil, A Heavy Helping Hand
(81588, 35208), -- Thaelin Darkanvil, Dark Iron Down
(81588, 35213), -- Thaelin Darkanvil, The Razorbloom
(81589, 35204), -- Rangari Kaalya, Pollen Power
(81589, 35214), -- Rangari Kaalya, The Infested
(81590, 35206), -- Yrel, Bushwhacker
(81601, 36523), -- Burrian Coalpart, A Green Ogron?
(81601, 35205), -- Burrian Coalpart, Burn the Bodies
(81601, 35207), -- Burrian Coalpart, Coalpart's Revenge
(81601, 35209), -- Burrian Coalpart, The Life Spring
(81731, 33685), -- Rakthoth, Ambassador to the Ancient
(81731, 33689), -- Rakthoth, Plant Pruning
(81751, 35235), -- Hansel Heavyhands, Iyu
(82222, 33661), -- Rakthoth, Steamscar "Reagents"
(82225, 33695), -- Rakthoth, Taking the Death Bloom
(82228, 35434), -- Kaz the Shrieker, The Life Spring
(82228, 36488), -- Kaz the Shrieker, Thieving Dwarves
(82233, 35433), -- Draka, Cut Them Down
(82254, 36482), -- Cutter, A Green Ogron?
(82274, 36482), -- Cutter, A Green Ogron?
(82274, 35536), -- Cutter, Secrets of the Botani
(82274, 35487), -- Cutter, We Burn the Dead
(82334, 35510), -- Cutter, Iyu
(82337, 35416), -- Draka, Power of the Genesaur
(82476, 35647), -- Khaano, A Grim Harvest
(82476, 35656), -- Khaano, A Heartfelt Search
(82476, 35644), -- Khaano, Mercy for the Living
(82476, 35645), -- Khaano, The Secret of the Fungus
(82477, 35659), -- Khaano, Heart of the Fen
(82569, 35508), -- Frenna, Chapter I: Plant Food
(82569, 35654), -- Frenna, Chapter I: Plant Food
(82569, 35527), -- Frenna, Chapter II: The Harvest
(82569, 35651), -- Frenna, Chapter II: The Harvest
(82569, 35524), -- Frenna, Chapter III: Ritual of the Charred
(82569, 35650), -- Frenna, Chapter III: Ritual of the Charred
(82574, 35506), -- Penny Clobberbottom, Growing Wood
(82575, 35652), -- Glirin, Growing Wood
(82575, 36368), -- Glirin, Lost Lumberjack
(82610, 35693), -- Rangari Erdanii, A Harsh Reminder
(82610, 36210), -- Rangari Erdanii, Hard Shell
(82610, 36223), -- Rangari Erdanii, Leave Every Soldier Behind
(82610, 35664), -- Rangari Erdanii, Seedbearers of Bad News
(82610, 36208), -- Rangari Erdanii, The Crystal Shard
(82610, 35665), -- Rangari Erdanii, We Have Company
(82610, 36209), -- Rangari Erdanii, What's Under There?
(82732, 33694), -- Marrow, Reagents from Rakthoth
(82732, 35667), -- Marrow, Skulltakers in Crimson Fen
(82832, 35870), -- Rexxar, Basilisk Butcher
(82832, 35730), -- Rexxar, Cauterizing Wounds
(82832, 35026), -- Rexxar, On the Mend
(83837, 37201), -- Cymre Brightblade, Cymre Brightblade
(84131, 35136), -- Rexxar, Chains of Iron
(84131, 35702), -- Rexxar, Chains of Iron
(84131, 35139), -- Rexxar, Eye in the Sky
(84176, 33544), -- Ripfist, Goren, Goren, Gone!
(84185, 36341), -- Thisalee Crow, Primal Fury
(84743, 35038), -- Bony Xuk, What the Bony Xuk?
(84743, 35041), -- Bony Xuk, Xuk It!
(84743, 35202), -- Bony Xuk, Xuk Me, Right?
(85077, 36812), -- Penny Clobberbottom, Penny For Your Thoughts
(85077, 35707), -- Penny Clobberbottom, Tangleheart
(85089, 33662), -- Rakthoth, Beatface vs. Boulder
(85089, 33663), -- Rakthoth, Shredder vs. Saberon
(85119, 36828), -- Glirin, Lumber, I Hardly Knew 'Er
(85119, 35708), -- Glirin, Tangleheart
(85147, 36460), -- Penny Clobberbottom, Just Another Stick in the Wall
(85426, 36437), -- Altauur, Ambassador to the Ancient
(85426, 36436), -- Altauur, Plant Pruning
(85431, 36440), -- Altauur, Saberon Population Reduction
(85432, 36438), -- Altauur, Beatface vs. Boulder
(85432, 36439), -- Altauur, Shredder vs. Saberon
(85436, 36442), -- Altauur, Taking the Death Bloom
(85601, 35507), -- Cutter, Down the Goren Hole
(85601, 35509), -- Cutter, Will of the Genesaur
(88530, 36342), -- Choluna, Primal Fury
(89179, 34339), -- Choluna, A Goren's Feast
(89937, 38570), -- Sammy Fivefingers, Derailment
(90177, 38255), -- Exarch Yrel, The Train Gang
(90180, 38254), -- Exarch Naielle, Derailment
(92401, 38571), -- Durotan, The Train Gang
(76987, 33548), -- Kaz the Shrieker, We Die Laughing!
(80874, 35828), -- Thaelin Darkanvil, I Drew Aggro...culture
(80922, 35834), -- Rangari Kaalya, Wake of the Genesaur
(81185, 35017), -- Dying Skulltaker, Skulltaker's Revenge
(82499, 35640), -- Dying Rangari, Vengeance for the Fallen
(83569, 35036), -- Rexxar, Is This One of Yours?
(83569, 36508), -- Rexxar, Is This One of Yours?
(84748, 35247), -- Bony Xuk, Zero Xuks Given
(86088, 36632), -- Rangari Kolaan, The Secrets of Gorgrond
(78030, 34279), -- Blook, I Am Blook
(81772, 35262), -- Rangari Kaalya, Service of Rangari Kaalya
(82338, 35511), -- Kaz the Shrieker, Kaz the Shrieker
(85278, 36833), -- Rangari Erdanii, May I Be of Service?
(85980, 36832); -- Spirit of Bony Xuk, Get the Xuk Outta Here!

INSERT INTO `creature_questender` VALUES
(74125, 34340), -- Aren Mistshade, Heating Up
(74593, 35400), -- Draka, The Infested
(74593, 36474), -- Draka, The Razorbloom
(74594, 33593), -- Durotan, A Flare for the Dramatic
(74594, 35136), -- Durotan, Chains of Iron
(74594, 36460), -- Durotan, Just Another Stick in the Wall
(74594, 35416), -- Durotan, Power of the Genesaur
(74594, 36574), -- Durotan, Strike While the Iron is Hot
(74594, 36573), -- Durotan, Strike While the Iron is Hot
(74594, 34867), -- Durotan, The Secrets of Gorgrond
(74594, 35557), -- Durotan, The Secrets of Gorgrond
(74594, 36503), -- Durotan, Trophy of Glory: Biolante
(74594, 35815), -- Durotan, Trophy of Glory: Charl Doomwing
(74594, 35811), -- Durotan, Trophy of Glory: Crater Lord Igneous
(74594, 35810), -- Durotan, Trophy of Glory: Dessicus
(74594, 35807), -- Durotan, Trophy of Glory: Erosian
(74594, 35814), -- Durotan, Trophy of Glory: Fungal Praetorian
(74594, 35819), -- Durotan, Trophy of Glory: Khargax the Devourer
(74594, 35818), -- Durotan, Trophy of Glory: Roardan the Sky Terror
(74594, 35151), -- Durotan, Your Base, Your Choice
(74606, 35511), -- Kaz the Shrieker, Kaz the Shrieker
(74606, 35399), -- Kaz the Shrieker, Mossy Fate
(74606, 35406), -- Kaz the Shrieker, Super Seeds
(74606, 35402), -- Kaz the Shrieker, The Voice of Iyu
(74606, 33548), -- Kaz the Shrieker, We Die Laughing!
(74611, 33563), -- Limbflayer, Eye Candy
(75008, 34012), -- Prowler Sasha, Need More Teeth
(75127, 35702), -- Vindicator Maraad, Chains of Iron
(75127, 35255), -- Vindicator Maraad, Power of the Genesaur
(75127, 36575), -- Vindicator Maraad, Strike While the Iron is Hot
(75127, 36576), -- Vindicator Maraad, Strike While the Iron is Hot
(75127, 36502), -- Vindicator Maraad, Trophy of Glory: Biolante
(75127, 35816), -- Vindicator Maraad, Trophy of Glory: Charl Doomwing
(75127, 35812), -- Vindicator Maraad, Trophy of Glory: Crater Lord Igneous
(75127, 35809), -- Vindicator Maraad, Trophy of Glory: Dessicus
(75127, 35808), -- Vindicator Maraad, Trophy of Glory: Erosian
(75127, 35813), -- Vindicator Maraad, Trophy of Glory: Fungal Praetorian
(75127, 35820), -- Vindicator Maraad, Trophy of Glory: Khargax the Devourer
(75127, 35817), -- Vindicator Maraad, Trophy of Glory: Roardan the Sky Terror
(75136, 36595), -- Thaelin Darkanvil, He Drew Aggro...culture
(75136, 35828), -- Thaelin Darkanvil, I Drew Aggro...culture
(75136, 35055), -- Thaelin Darkanvil, Lost Mole Machines
(75136, 35063), -- Thaelin Darkanvil, We Need An Outpost
(75146, 35065), -- Rangari D'kaan, A Harvester Has Come
(75146, 35659), -- Rangari D'kaan, Heart of the Fen
(75146, 35050), -- Rangari D'kaan, Rescue Rangari
(75593, 33633), -- Rooter, Rooter the Ravenous
(75710, 35225), -- Hansel Heavyhands, A Heavy Helping Hand
(75710, 35229), -- Hansel Heavyhands, Down the Goren Hole
(75710, 35233), -- Hansel Heavyhands, Just In Case
(75878, 35235), -- Yrel, Iyu
(76688, 36094), -- Limbflayer, Proof of Strength: Ancient Branch
(76688, 36104), -- Limbflayer, Proof of Strength: Basilisk Scale
(76688, 36086), -- Limbflayer, Proof of Strength: Botani Bloom
(76688, 36106), -- Limbflayer, Proof of Strength: Elemental Crystal
(76688, 35948), -- Limbflayer, Proof of Strength: Goren Tooth
(76688, 36083), -- Limbflayer, Proof of Strength: Gronn Eye
(76688, 36080), -- Limbflayer, Proof of Strength: Gronnling Scale
(76688, 36076), -- Limbflayer, Proof of Strength: Ogron Horn
(76688, 36091), -- Limbflayer, Proof of Strength: Orc Thorn
(76688, 36097), -- Limbflayer, Proof of Strength: Ravager Claw
(76688, 36101), -- Limbflayer, Proof of Strength: Wasp Stinger
(76688, 35152), -- Limbflayer, The Sparring Arena
(76688, 36108), -- Limbflayer, Trophy Hunter of Gorgrond
(77014, 34699), -- Bruto, Getting Gladiators
(77014, 35882), -- Bruto, The Interest of Bruto
(78187, 34336), -- Thisalee Crow, Ambushing the Enemy
(78187, 34347), -- Thisalee Crow, Bladefury's Orders
(78187, 34335), -- Thisalee Crow, Garrison Campaign: Crows In The Field
(78187, 34409), -- Thisalee Crow, Garrison Campaign: Crows In The Field
(78251, 34338), -- Thisalee Crow, The Descent
(78251, 34337), -- Thisalee Crow, The Giant Cauldron
(79320, 34697), -- Kash'drakor, A Rediscovered Legend
(79320, 34700), -- Kash'drakor, Nazgrel
(79320, 34698), -- Kash'drakor, Slave Hunters
(79322, 34704), -- Gladiator Akaani, A Rediscovered Legend
(79322, 34703), -- Gladiator Akaani, The Axe of Kor'gall
(79331, 34702), -- Beatface, Krav'ogra
(80757, 35016), -- Grulkor, Basic Skulltaking
(80757, 35027), -- Grulkor, Clearing the Way
(80757, 35021), -- Grulkor, Mysterious Pod
(80757, 35017), -- Grulkor, Skulltaker's Revenge
(80757, 35029), -- Grulkor, The Secret of the Fungus
(80762, 35666), -- Khaano, Rangari in the Red
(80856, 35037), -- Rexxar, Bad at Breaking
(80856, 35934), -- Rexxar, Nisha's Vengeance
(80856, 35925), -- Rexxar, The Gronn Strategy
(80856, 35041), -- Rexxar, Xuk It!
(80921, 35033), -- Rangari D'kaan, Welcome to Gorgrond
(80978, 33533), -- Yrel, The Secrets of Gorgrond
(80978, 35556), -- Yrel, The Secrets of Gorgrond
(80978, 36632), -- Yrel, The Secrets of Gorgrond
(81076, 36092), -- Rangari Jonaa, Proof of Strength: Ancient Branch
(81076, 36103), -- Rangari Jonaa, Proof of Strength: Basilisk Scale
(81076, 36084), -- Rangari Jonaa, Proof of Strength: Botani Bloom
(81076, 36105), -- Rangari Jonaa, Proof of Strength: Elemental Crystal
(81076, 35944), -- Rangari Jonaa, Proof of Strength: Goren Tooth
(81076, 36081), -- Rangari Jonaa, Proof of Strength: Gronn Eye
(81076, 36078), -- Rangari Jonaa, Proof of Strength: Gronnling Scale
(81076, 36075), -- Rangari Jonaa, Proof of Strength: Ogron Horn
(81076, 36090), -- Rangari Jonaa, Proof of Strength: Orc Thorn
(81076, 36096), -- Rangari Jonaa, Proof of Strength: Ravager Claw
(81076, 36098), -- Rangari Jonaa, Proof of Strength: Wasp Stinger
(81076, 35137), -- Rangari Jonaa, The Sparring Arena
(81076, 36107), -- Rangari Jonaa, Trophy Hunter of Gorgrond
(81202, 35248), -- Bony Xuk, A Harsh Reminder
(81202, 35880), -- Bony Xuk, Rage and Wisdom
(81202, 35035), -- Bony Xuk, Seedbearers of Bad News
(81218, 35667), -- Grulkor, Skulltakers in Crimson Fen
(81241, 35030), -- Grulkor, A Grim Harvest
(81241, 35031), -- Grulkor, A Heartfelt Search
(81588, 35212), -- Thaelin Darkanvil, Deeproot
(81588, 35216), -- Thaelin Darkanvil, Super Seeds
(81588, 35213), -- Thaelin Darkanvil, The Razorbloom
(81588, 35215), -- Thaelin Darkanvil, The Voice of Iyu
(81589, 35204), -- Rangari Kaalya, Pollen Power
(81589, 35214), -- Rangari Kaalya, The Infested
(81590, 35206), -- Yrel, Bushwhacker
(81590, 35209), -- Yrel, The Life Spring
(81601, 36523), -- Burrian Coalpart, A Green Ogron?
(81601, 35205), -- Burrian Coalpart, Burn the Bodies
(81601, 35207), -- Burrian Coalpart, Coalpart's Revenge
(81731, 33694), -- Rakthoth, Reagents from Rakthoth
(81751, 35229), -- Hansel Heavyhands, Down the Goren Hole
(81751, 35233), -- Hansel Heavyhands, Just In Case
(81751, 35234), -- Hansel Heavyhands, Will of the Genesaur
(82222, 33662), -- Rakthoth, Beatface vs. Boulder
(82222, 33663), -- Rakthoth, Shredder vs. Saberon
(82222, 33660), -- Rakthoth, The Sacking of the Saberon
(82225, 33661), -- Rakthoth, Steamscar "Reagents"
(82225, 33660), -- Rakthoth, The Sacking of the Saberon
(82228, 35429), -- Kaz the Shrieker, Pollen Power
(82228, 35536), -- Kaz the Shrieker, Secrets of the Botani
(82228, 35434), -- Kaz the Shrieker, The Life Spring
(82233, 35432), -- Draka, Bushwhacker
(82233, 35433), -- Draka, Cut Them Down
(82254, 35430), -- Cutter, Cutter
(82274, 36482), -- Cutter, A Green Ogron?
(82274, 35487), -- Cutter, We Burn the Dead
(82334, 35507), -- Cutter, Down the Goren Hole
(82334, 35509), -- Cutter, Will of the Genesaur
(82337, 35510), -- Draka, Iyu
(82476, 35647), -- Khaano, A Grim Harvest
(82476, 35644), -- Khaano, Mercy for the Living
(82476, 35642), -- Khaano, Mysterious Pod
(82476, 35633), -- Khaano, Scout Forensics
(82476, 35645), -- Khaano, The Secret of the Fungus
(82476, 35640), -- Khaano, Vengeance for the Fallen
(82477, 35647), -- Khaano, A Grim Harvest
(82477, 35656), -- Khaano, A Heartfelt Search
(82569, 35505), -- Frenna, Lost Lumberjack
(82569, 36368), -- Frenna, Lost Lumberjack
(82574, 35508), -- Penny Clobberbottom, Chapter I: Plant Food
(82574, 35527), -- Penny Clobberbottom, Chapter II: The Harvest
(82574, 35524), -- Penny Clobberbottom, Chapter III: Ritual of the Charred
(82574, 35506), -- Penny Clobberbottom, Growing Wood
(82574, 35707), -- Penny Clobberbottom, Tangleheart
(82575, 35708), -- Glirin, Tangleheart
(82610, 35693), -- Rangari Erdanii, A Harsh Reminder
(82610, 36210), -- Rangari Erdanii, Hard Shell
(82610, 36508), -- Rangari Erdanii, Is This One of Yours?
(82610, 35686), -- Rangari Erdanii, Rage and Wisdom
(82610, 35664), -- Rangari Erdanii, Seedbearers of Bad News
(82610, 36208), -- Rangari Erdanii, The Crystal Shard
(82610, 36209), -- Rangari Erdanii, What's Under There?
(82732, 35040), -- Marrow, Heart of the Fen
(82832, 35730), -- Rexxar, Cauterizing Wounds
(82832, 35025), -- Rexxar, We Have Company
(82832, 35665), -- Rexxar, We Have Company
(83837, 37201), -- Cymre Brightblade, Cymre Brightblade
(84131, 35210), -- Rexxar, A Great Escape
(84131, 35139), -- Rexxar, Eye in the Sky
(84131, 35128), -- Rexxar, Fair Warning
(84131, 35129), -- Rexxar, Leave Every Soldier Behind
(84131, 36223), -- Rexxar, Leave Every Soldier Behind
(84176, 33544), -- Ripfist, Goren, Goren, Gone!
(84176, 33543), -- Ripfist, The Laughing Skull
(84185, 36134), -- Thisalee Crow, Garrison Campaign: Awakening
(84743, 35036), -- Bony Xuk, Is This One of Yours?
(84743, 35038), -- Bony Xuk, What the Bony Xuk?
(84743, 35202), -- Bony Xuk, Xuk Me, Right?
(85077, 36812), -- Penny Clobberbottom, Penny For Your Thoughts
(85089, 33685), -- Rakthoth, Ambassador to the Ancient
(85089, 33689), -- Rakthoth, Plant Pruning
(85119, 36828), -- Glirin, Lumber, I Hardly Knew 'Er
(85147, 36434), -- Penny Clobberbottom, Penny From Heaven
(85426, 36432), -- Altauur, Seeking the Scout
(85431, 36438), -- Altauur, Beatface vs. Boulder
(85431, 36441), -- Altauur, Reclaiming Property
(85431, 36439), -- Altauur, Shredder vs. Saberon
(85432, 36437), -- Altauur, Ambassador to the Ancient
(85432, 36436), -- Altauur, Plant Pruning
(85436, 36441), -- Altauur, Reclaiming Property
(85436, 36440), -- Altauur, Saberon Population Reduction
(85601, 35507), -- Cutter, Down the Goren Hole
(85601, 36488), -- Cutter, Thieving Dwarves
(88530, 36136), -- Choluna, Garrison Campaign: Awakening
(89179, 34339), -- Choluna, A Goren's Feast
(89937, 38568), -- Sammy Fivefingers, We Need a Shipwright
(90177, 38254), -- Exarch Yrel, Derailment
(90180, 38257), -- Exarch Naielle, We Need a Shipwright
(92401, 38570), -- Durotan, Derailment
(78030, 34279), -- Blook, I Am Blook
(81772, 35262), -- Rangari Kaalya, Service of Rangari Kaalya
(82338, 35511), -- Kaz the Shrieker, Kaz the Shrieker
(85278, 36833), -- Rangari Erdanii, May I Be of Service?
(85980, 36832), -- Spirit of Bony Xuk, Get the Xuk Outta Here!
(85980, 35247); -- Spirit of Bony Xuk, Zero Xuks Given
