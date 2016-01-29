UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (72822, 76508, 79188, 79201, 79263, 79281, 79282, 79310, 79312, 79576, 79674, 79722, 79743, 79954, 80001, 80003, 80083, 80140, 80161, 80184, 80319, 80429, 80434, 80451, 80593, 80595, 80597, 80624, 80864, 80866, 81039, 81097, 81134, 81144, 81186, 81189, 81194, 81195, 81319, 81335, 81361, 81790, 81953, 81955, 82078, 82080, 82092, 82094, 82138, 82179, 82181, 82658, 82688, 82727, 82746, 83051, 83052, 83053, 83054, 83606, 83686, 83734, 83888, 84459, 84632, 84637, 84702, 84720, 84783, 84784, 84861, 87110, 87311, 87393, 87706, 88240, 88500);

DELETE FROM `creature_queststarter` WHERE `id` IN (72822, 76508, 79188, 79201, 79263, 79281, 79282, 79310, 79312, 79576, 79674, 79722, 79743, 79954, 80001, 80003, 80083, 80140, 80161, 80184, 80319, 80429, 80434, 80451, 80593, 80595, 80597, 80624, 80864, 80866, 81039, 81097, 81134, 81144, 81186, 81189, 81194, 81195, 81319, 81335, 81361, 81790, 81953, 81955, 82078, 82080, 82092, 82094, 82138, 82179, 82181, 82658, 82688, 82727, 82746, 83051, 83052, 83053, 83054, 83606, 83686, 83734, 83888, 84459, 84632, 84637, 84702, 84720, 84783, 84784, 84861, 87110, 87311, 87393, 87706, 88240, 88500);
DELETE FROM `creature_questender` WHERE `id` IN (72822, 76508, 79188, 79201, 79263, 79281, 79282, 79310, 79312, 79576, 79674, 79722, 79743, 79954, 80001, 80003, 80083, 80140, 80161, 80319, 80429, 80434, 80593, 80595, 80597, 80864, 80866, 81039, 81144, 81186, 81335, 81361, 81790, 81953, 81955, 82078, 82080, 82092, 82094, 82138, 82179, 82181, 82658, 82688, 82727, 82746, 83051, 83052, 83053, 83054, 83686, 83734, 83888, 84459, 84632, 84637, 84702, 84720, 84783, 84784, 84861, 87110, 87311, 87393, 87706, 88240);

INSERT INTO `creature_queststarter` VALUES
(72822, 35167), -- Mankrik, Lost in Nagrand
(76508, 35973), -- Dizzy Sparkshift, Brokyo Beatdown
(76508, 37516), -- Dizzy Sparkshift, News for Nixxie
(76508, 37517), -- Dizzy Sparkshift, News for Nixxie
(79188, 34665), -- Dexyl Deadblade, Ring of Trials: Captain Boomspark
(79188, 34662), -- Dexyl Deadblade, Ring of Trials: Crushmaul
(79188, 34664), -- Dexyl Deadblade, Ring of Trials: Hol'yelaa
(79188, 34663), -- Dexyl Deadblade, Ring of Trials: Raketalon
(79188, 34666), -- Dexyl Deadblade, Ring of Trials: Roakk the Zealot
(79201, 35632), -- Gazmolf Futzwangler, A Lesson in Archaeology
(79201, 34809), -- Gazmolf Futzwangler, A Lesson in Mineralogy
(79201, 35663), -- Gazmolf Futzwangler, A Lesson in Teamwork
(79263, 34675), -- Lieutenant Balfor, The Might of the Warsong
(79281, 35155), -- Akrosh, Obliterating Ogres
(79281, 35157), -- Akrosh, Obtaining Ogre Offensive Orders
(79282, 34572), -- Rangari Eleena, Obliterating Ogres
(79282, 34593), -- Rangari Eleena, Obtaining Ogre Offensive Orders
(79310, 34512), -- Pyxni Pennypocket, Declawing The Competition
(79310, 34598), -- Pyxni Pennypocket, The Missing Caravan
(79312, 34515), -- Greezlex Fizzpinch, Gobnapped
(79312, 34514), -- Greezlex Fizzpinch, They've Got The Goods!
(79576, 35059), -- Rangari D'kaan, Along the Riverside
(79576, 35169), -- Rangari D'kaan, And Justice for Thrall
(79576, 35332), -- Rangari D'kaan, Nobundo Sends Word
(79576, 34720), -- Rangari D'kaan, Operation: Just Arrowhead
(79576, 34678), -- Rangari D'kaan, Up and Running
(79674, 34769), -- Thaelin Darkanvil, A Choice to Make
(79674, 34682), -- Thaelin Darkanvil, Operation: Surprise Party
(79722, 34716), -- Rangari Ogir, Mo'mor Might Know
(79722, 34717), -- Rangari Ogir, Operation: Just Arrowhead
(79743, 34719), -- Vindicator Mo'mor, ... and My Hammer
(79743, 34746), -- Vindicator Mo'mor, Shields Down!
(79743, 34718), -- Vindicator Mo'mor, The Others
(79954, 34952), -- Hansel Heavyhands, The Friend o' My Enemy
(79954, 35148), -- Hansel Heavyhands, Trouble at the Overwatch
(80001, 34795), -- Stone Guard Brox, The Might of the Warsong
(80003, 35095), -- Thrall, Along the Riverside
(80003, 35171), -- Thrall, And Justice for Thrall
(80003, 34808), -- Thrall, More Lazy Peons
(80003, 34964), -- Thrall, The Farseer Awaits
(80003, 34826), -- Thrall, The Friend of My Enemy
(80083, 35596), -- Goldmane the Skinner, Feline Friends Forever
(80140, 34899), -- Foreman Thazz'ril, A Choice to Make
(80140, 34818), -- Foreman Thazz'ril, They Call Him Lantresor of the Blade
(80161, 34953), -- Lantresor of the Blade, Blood of the Burning Blade
(80161, 35143), -- Lantresor of the Blade, Blood of the Burning Blade
(80161, 34866), -- Lantresor of the Blade, Meet Me in the Cavern
(80161, 34956), -- Lantresor of the Blade, Meet Me in the Cavern
(80161, 34850), -- Lantresor of the Blade, Not Without My Honor
(80161, 34955), -- Lantresor of the Blade, Not Without My Honor
(80161, 34849), -- Lantresor of the Blade, The Blade Itself
(80161, 34954), -- Lantresor of the Blade, The Blade Itself
(80184, 34810), -- Gabby Goldsnap, Gazmolf Futzwangler and the Highmaul Crusade
(80319, 34868), -- Lantresor of the Blade, Challenge of the Masters
(80319, 34957), -- Lantresor of the Blade, Challenge of the Masters
(80429, 34915), -- Shadow Hunter Kajassa, I Help Ya Kill Dem
(80429, 34918), -- Shadow Hunter Kajassa, Shields Down!
(80429, 34916), -- Shadow Hunter Kajassa, The Blessing of Samedi
(80434, 34894), -- Gar'rok, A Rare Bloom
(80434, 34932), -- Gar'rok, Guise of the Deceiver
(80434, 34941), -- Gar'rok, The Debt We Share
(80451, 34917), -- Rangari Keilnei, Shields Up!
(80593, 34881), -- Incineratus, Earth, Wind and Fire...and Water
(80593, 34893), -- Incineratus, Guardians of the Plateau
(80595, 34943), -- Kalandrios, An Old Friend
(80597, 34965), -- Farseer Drek'Thar, Called to the Throne
(80597, 34891), -- Farseer Drek'Thar, Elemental Attunement
(80597, 35232), -- Farseer Drek'Thar, The Call of Oshu'gun
(80597, 35265), -- Farseer Drek'Thar, The Ritual of Binding
(80624, 34951), -- Vindicator Mo'mor, They Call Him Lantresor of the Blade
(80864, 35024), -- Gar'rok, Golmash Hellscream
(80864, 35022), -- Gar'rok, Lighting The Darkness
(80866, 35023), -- Dahaka, Echoes of the Past
(81039, 35141), -- Vindicator Yrel, Carrier Has Arrived
(81039, 35062), -- Vindicator Yrel, Lok-rath is Secured
(81039, 35060), -- Vindicator Yrel, Terms of Surrender
(81039, 35140), -- Vindicator Yrel, THAELIN!
(81097, 35068), -- Lieutenant K. K. Lee, If They Won't Surrender...
(81097, 35067), -- Lieutenant K. K. Lee, Silence the War Machines
(81134, 35069), -- Fallen Alliance Soldier, Terror of Nagrand
(81144, 34596), -- Rangari Mirana, Reglakk's Research
(81144, 34877), -- Rangari Mirana, Removing the Reinforcements
(81186, 35098), -- Durotan, Lok-rath is Secured
(81186, 35096), -- Durotan, Terms of Surrender
(81189, 34914), -- Aggra, Target of Opportunity: Telaar
(81194, 35100), -- Senior Sergeant Igerdes, If They Won't Surrender...
(81194, 35099), -- Senior Sergeant Igerdes, Silence the War Machines
(81195, 35101), -- Fallen Horde Soldier, Terror of Nagrand
(81319, 35150), -- Draka, Trouble at the Overwatch
(81335, 35144), -- Farseer Drek'Thar, Dark Binding
(81335, 35231), -- Farseer Drek'Thar, Spiritual Matters
(81335, 35145), -- Farseer Drek'Thar, The Pale Threat
(81361, 35158), -- Dalgorsh, Reglakk's Research
(81361, 35159), -- Dalgorsh, Removing the Reinforcements
(81790, 34747), -- Lantresor of the Blade, The Honor of a Blademaster
(81790, 34770), -- Lantresor of the Blade, The Honor of a Blademaster
(81953, 35317), -- Farseer Drek'Thar, The Dark Heart of Oshu'gun
(81953, 34271), -- Farseer Drek'Thar, The Fate of Gordawg
(81955, 34819), -- Digrem Orebar, Fruitful Ventures
(81955, 34900), -- Digrem Orebar, New Babies
(81955, 34869), -- Digrem Orebar, Tastes Like Chicken
(82078, 35375), -- Shadow Hunter Taz, Queen of the Clefthoof
(82078, 35374), -- Shadow Hunter Taz, That Pounding Sound
(82080, 35378), -- Stalker Ogka, King of the Breezestriders
(82080, 35376), -- Stalker Ogka, Shooting the Breeze
(82092, 35350), -- Kia Herman, Queen of the Clefthoof
(82092, 35337), -- Kia Herman, That Pounding Sound
(82094, 35357), -- Rangari Laara, King of the Breezestriders
(82094, 35338), -- Rangari Laara, Shooting the Breeze
(82138, 35331), -- Vindicator Nobundo, Called to the Throne
(82138, 35333), -- Vindicator Nobundo, Elemental Attunement
(82138, 35372), -- Vindicator Nobundo, The Call of Oshu'gun
(82138, 35330), -- Vindicator Nobundo, The Ritual of Binding
(82179, 35398), -- Vindicator Nobundo, Dark Binding
(82179, 35393), -- Vindicator Nobundo, Spiritual Matters
(82179, 35397), -- Vindicator Nobundo, The Pale Threat
(82181, 35396), -- Vindicator Nobundo, The Dark Heart of Oshu'gun
(82181, 35395), -- Vindicator Nobundo, The Fate of Gordawg
(82658, 34811), -- Trixi Leroux, Good Help is Hard to Find
(82688, 35170), -- Olgra, Consumed by Vengeance
(82727, 35928), -- Meatgut, Meatgut Needs Bones
(82746, 36711), -- Abu'gar, Abu'gar
(83051, 35838), -- Jeanine Amrell, The Warlord's Council
(83052, 35844), -- Shadow Hunter Zasta, The Warlord's Council
(83053, 35840), -- Flint Shadowmore, Intercepting the Orders
(83053, 35839), -- Flint Shadowmore, Plans of War
(83053, 35841), -- Flint Shadowmore, Putting Down the Packleader
(83054, 35846), -- Shadow Hunter Kajassa, Intercepting the Orders
(83054, 35845), -- Shadow Hunter Kajassa, Plans of War
(83054, 35842), -- Shadow Hunter Kajassa, Putting Down the Packleader
(83606, 35921), -- Lucy Brokerblast, Bread and Circuses
(83606, 35922), -- Lucy Brokerblast, Bread and Circuses
(83686, 35945), -- Greblin Fastfizzle, Greblin Fastfizzle
(83734, 37511), -- Greblin Fastfizzle, Dizzy Sparkshift
(83734, 35972), -- Greblin Fastfizzle, Ogre Onslaught
(83734, 35970), -- Greblin Fastfizzle, Preservation Capitalization
(83888, 39299), -- Mister Knuckles, Black Marketeering
(84459, 36193), -- Rangari Saardar, An Act of Kindness
(84632, 35146), -- Marybelle Walsh, The Good Doctor
(84632, 36273), -- Marybelle Walsh, Whacking Weeds
(84637, 36220), -- Gurgthock, How Tough Are You?
(84702, 36004), -- Archmage Khadgar, Power Unleashed
(84702, 35995), -- Archmage Khadgar, Tarnished Bronze
(84702, 36206), -- Archmage Khadgar, The Dragon's Tale
(84720, 36221), -- Kroggol the Wall, Entry Fee
(84783, 36705), -- Gurgthock, The Ring of Blood: Mogor!
(84783, 36670), -- Gurgthock, The Ring of Blood: Skull Chewer!
(84784, 36289), -- Wodin the Troll-Servant, Out of the Shadows
(84784, 36290), -- Wodin the Troll-Servant, Out of the Shadows
(84784, 36222), -- Wodin the Troll-Servant, The Champion of Blood
(84861, 36284), -- Dr. Hadley Ricard, A Fascinating Fungus
(84861, 36285), -- Dr. Hadley Ricard, Dirgemire
(84861, 36275), -- Dr. Hadley Ricard, The Search For Research
(87110, 37206), -- Tarr the Terrible, Tarr the Terrible
(87311, 37083), -- Kharg, Fight, Kill, Salute!
(87311, 37286), -- Kharg, The Bloodshed Never Ends
(87393, 37125), -- Sallee Silverclamp, A Rare Find
(87393, 35147), -- Sallee Silverclamp, Fragments of the Past
(87706, 37210), -- Gazmolf Futzwangler, Aogexon's Fang
(87706, 37211), -- Gazmolf Futzwangler, Bergruu's Horn
(87706, 37221), -- Gazmolf Futzwangler, Dekorhan's Tusk
(87706, 37222), -- Gazmolf Futzwangler, Direhoof's Hide
(87706, 37223), -- Gazmolf Futzwangler, Gagrog's Skull
(87706, 37224), -- Gazmolf Futzwangler, Mu'gra's Head
(87706, 37225), -- Gazmolf Futzwangler, Thek'talon's Talon
(87706, 37520), -- Gazmolf Futzwangler, Vileclaw's Claw
(87706, 37226), -- Gazmolf Futzwangler, Xelganak's Stinger
(88240, 37293), -- Shadow Hunter Mok'e, Clearing the Mist
(88500, 37318); -- Murgok, The Dead Do Not Forget...

INSERT INTO `creature_questender` VALUES
(72822, 35170), -- Mankrik, Consumed by Vengeance
(76508, 35973), -- Dizzy Sparkshift, Brokyo Beatdown
(76508, 37511), -- Dizzy Sparkshift, Dizzy Sparkshift
(79188, 35921), -- Dexyl Deadblade, Bread and Circuses
(79188, 35922), -- Dexyl Deadblade, Bread and Circuses
(79188, 34665), -- Dexyl Deadblade, Ring of Trials: Captain Boomspark
(79188, 34662), -- Dexyl Deadblade, Ring of Trials: Crushmaul
(79188, 34664), -- Dexyl Deadblade, Ring of Trials: Hol'yelaa
(79188, 34663), -- Dexyl Deadblade, Ring of Trials: Raketalon
(79188, 34666), -- Dexyl Deadblade, Ring of Trials: Roakk the Zealot
(79201, 35632), -- Gazmolf Futzwangler, A Lesson in Archaeology
(79201, 35663), -- Gazmolf Futzwangler, A Lesson in Teamwork
(79201, 34810), -- Gazmolf Futzwangler, Gazmolf Futzwangler and the Highmaul Crusade
(79263, 34674), -- Lieutenant Balfor, Taking the Fight to Nagrand
(79263, 37184), -- Lieutenant Balfor, Taking the Fight to Nagrand
(79281, 35150), -- Akrosh, Trouble at the Overwatch
(79282, 35148), -- Rangari Eleena, Trouble at the Overwatch
(79310, 34512), -- Pyxni Pennypocket, Declawing The Competition
(79310, 34515), -- Pyxni Pennypocket, Gobnapped
(79310, 34514), -- Pyxni Pennypocket, They've Got The Goods!
(79310, 34513), -- Pyxni Pennypocket, WANTED: Razorpaw!
(79312, 34598), -- Greezlex Fizzpinch, The Missing Caravan
(79576, 34769), -- Rangari D'kaan, A Choice to Make
(79576, 34957), -- Rangari D'kaan, Challenge of the Masters
(79576, 35062), -- Rangari D'kaan, Lok-rath is Secured
(79576, 34717), -- Rangari D'kaan, Operation: Just Arrowhead
(79576, 34720), -- Rangari D'kaan, Operation: Just Arrowhead
(79576, 34596), -- Rangari D'kaan, Reglakk's Research
(79576, 34877), -- Rangari D'kaan, Removing the Reinforcements
(79576, 34675), -- Rangari D'kaan, The Might of the Warsong
(79674, 35141), -- Thaelin Darkanvil, Carrier Has Arrived
(79674, 34877), -- Thaelin Darkanvil, Removing the Reinforcements
(79674, 34746), -- Thaelin Darkanvil, Shields Down!
(79674, 34678), -- Thaelin Darkanvil, Up and Running
(79722, 34682), -- Rangari Ogir, Operation: Surprise Party
(79743, 34719), -- Vindicator Mo'mor, ... and My Hammer
(79743, 34716), -- Vindicator Mo'mor, Mo'mor Might Know
(79743, 34718), -- Vindicator Mo'mor, The Others
(79954, 34953), -- Hansel Heavyhands, Blood of the Burning Blade
(79954, 34952), -- Hansel Heavyhands, The Friend o' My Enemy
(80001, 34794), -- Stone Guard Brox, Taking the Fight to Nagrand
(80001, 36952), -- Stone Guard Brox, Taking the Fight to Nagrand
(80003, 34899), -- Thrall, A Choice to Make
(80003, 35143), -- Thrall, Blood of the Burning Blade
(80003, 35098), -- Thrall, Lok-rath is Secured
(80003, 35158), -- Thrall, Reglakk's Research
(80003, 35159), -- Thrall, Removing the Reinforcements
(80003, 34918), -- Thrall, Shields Down!
(80003, 34826), -- Thrall, The Friend of My Enemy
(80003, 34795), -- Thrall, The Might of the Warsong
(80083, 35596), -- Goldmane the Skinner, Feline Friends Forever
(80140, 34868), -- Foreman Thazz'ril, Challenge of the Masters
(80140, 34808), -- Foreman Thazz'ril, More Lazy Peons
(80140, 35159), -- Foreman Thazz'ril, Removing the Reinforcements
(80161, 34850), -- Lantresor of the Blade, Not Without My Honor
(80161, 34955), -- Lantresor of the Blade, Not Without My Honor
(80161, 34849), -- Lantresor of the Blade, The Blade Itself
(80161, 34954), -- Lantresor of the Blade, The Blade Itself
(80161, 34818), -- Lantresor of the Blade, They Call Him Lantresor of the Blade
(80161, 34951), -- Lantresor of the Blade, They Call Him Lantresor of the Blade
(80319, 34866), -- Lantresor of the Blade, Meet Me in the Cavern
(80319, 34956), -- Lantresor of the Blade, Meet Me in the Cavern
(80429, 34915), -- Shadow Hunter Kajassa, I Help Ya Kill Dem
(80429, 34917), -- Shadow Hunter Kajassa, Shields Up!
(80429, 34914), -- Shadow Hunter Kajassa, Target of Opportunity: Telaar
(80429, 34916), -- Shadow Hunter Kajassa, The Blessing of Samedi
(80434, 34894), -- Gar'rok, A Rare Bloom
(80434, 34943), -- Gar'rok, An Old Friend
(80434, 34932), -- Gar'rok, Guise of the Deceiver
(80593, 33928), -- Incineratus, A Wrong of Earth and Fire
(80593, 34881), -- Incineratus, Earth, Wind and Fire...and Water
(80593, 34893), -- Incineratus, Guardians of the Plateau
(80595, 34941), -- Kalandrios, The Debt We Share
(80595, 34271), -- Kalandrios, The Fate of Gordawg
(80595, 35395), -- Kalandrios, The Fate of Gordawg
(80597, 34965), -- Farseer Drek'Thar, Called to the Throne
(80597, 34891), -- Farseer Drek'Thar, Elemental Attunement
(80597, 34964), -- Farseer Drek'Thar, The Farseer Awaits
(80597, 35265), -- Farseer Drek'Thar, The Ritual of Binding
(80864, 35024), -- Gar'rok, Golmash Hellscream
(80864, 35022), -- Gar'rok, Lighting The Darkness
(80864, 35231), -- Gar'rok, Spiritual Matters
(80864, 35393), -- Gar'rok, Spiritual Matters
(80866, 35023), -- Dahaka, Echoes of the Past
(81039, 35059), -- Vindicator Yrel, Along the Riverside
(81039, 35140), -- Vindicator Yrel, THAELIN!
(81039, 35061), -- Vindicator Yrel, The Pride of Lok-rath
(81144, 34572), -- Rangari Mirana, Obliterating Ogres
(81144, 34593), -- Rangari Mirana, Obtaining Ogre Offensive Orders
(81144, 34597), -- Rangari Mirana, Removing the Paper Trail
(81186, 35095), -- Durotan, Along the Riverside
(81186, 35097), -- Durotan, The Pride of Lok-rath
(81335, 35232), -- Farseer Drek'Thar, The Call of Oshu'gun
(81361, 35155), -- Dalgorsh, Obliterating Ogres
(81361, 35157), -- Dalgorsh, Obtaining Ogre Offensive Orders
(81361, 35156), -- Dalgorsh, Removing the Paper Trail
(81790, 34747), -- Lantresor of the Blade, The Honor of a Blademaster
(81790, 34770), -- Lantresor of the Blade, The Honor of a Blademaster
(81953, 35144), -- Farseer Drek'Thar, Dark Binding
(81953, 35145), -- Farseer Drek'Thar, The Pale Threat
(81955, 34819), -- Digrem Orebar, Fruitful Ventures
(81955, 34900), -- Digrem Orebar, New Babies
(81955, 34869), -- Digrem Orebar, Tastes Like Chicken
(82078, 35375), -- Shadow Hunter Taz, Queen of the Clefthoof
(82078, 35374), -- Shadow Hunter Taz, That Pounding Sound
(82080, 35378), -- Stalker Ogka, King of the Breezestriders
(82080, 35376), -- Stalker Ogka, Shooting the Breeze
(82080, 35377), -- Stalker Ogka, Someone's Missing Axe
(82092, 35350), -- Kia Herman, Queen of the Clefthoof
(82092, 35337), -- Kia Herman, That Pounding Sound
(82094, 35357), -- Rangari Laara, King of the Breezestriders
(82094, 35338), -- Rangari Laara, Shooting the Breeze
(82094, 35356), -- Rangari Laara, Someone's Missing Arrow
(82138, 35331), -- Vindicator Nobundo, Called to the Throne
(82138, 35333), -- Vindicator Nobundo, Elemental Attunement
(82138, 35332), -- Vindicator Nobundo, Nobundo Sends Word
(82138, 35330), -- Vindicator Nobundo, The Ritual of Binding
(82179, 35372), -- Vindicator Nobundo, The Call of Oshu'gun
(82181, 35398), -- Vindicator Nobundo, Dark Binding
(82181, 35397), -- Vindicator Nobundo, The Pale Threat
(82658, 34811), -- Trixi Leroux, Good Help is Hard to Find
(82688, 35167), -- Olgra, Lost in Nagrand
(82727, 35928), -- Meatgut, Meatgut Needs Bones
(82746, 36711), -- Abu'gar, Abu'gar
(83051, 35837), -- Jeanine Amrell, Garrison Campaign: Deep Recon
(83052, 35843), -- Shadow Hunter Zasta, Garrison Campaign: Deep Recon
(83053, 35838), -- Flint Shadowmore, The Warlord's Council
(83054, 35844), -- Shadow Hunter Kajassa, The Warlord's Council
(83686, 35985), -- Greblin Fastfizzle, Garrison Campaign: The Broken Precipice
(83686, 36117), -- Greblin Fastfizzle, Garrison Campaign: The Broken Precipice
(83734, 35945), -- Greblin Fastfizzle, Greblin Fastfizzle
(83734, 35972), -- Greblin Fastfizzle, Ogre Onslaught
(83734, 35970), -- Greblin Fastfizzle, Preservation Capitalization
(83888, 39278), -- Mister Knuckles, The Missing Manifest
(84459, 36193), -- Rangari Saardar, An Act of Kindness
(84632, 36273), -- Marybelle Walsh, Whacking Weeds
(84637, 36219), -- Gurgthock, Garrison Campaign: The Ring of Blood
(84637, 36280), -- Gurgthock, Garrison Campaign: The Ring of Blood
(84637, 36281), -- Gurgthock, Garrison Campaign: The Ring of Blood
(84637, 36282), -- Gurgthock, Garrison Campaign: The Ring of Blood
(84702, 36000), -- Archmage Khadgar, Fugitive Dragon
(84702, 35995), -- Archmage Khadgar, Tarnished Bronze
(84702, 36206), -- Archmage Khadgar, The Dragon's Tale
(84720, 36220), -- Kroggol the Wall, How Tough Are You?
(84783, 36705), -- Gurgthock, The Ring of Blood: Mogor!
(84783, 36670), -- Gurgthock, The Ring of Blood: Skull Chewer!
(84783, 37981), -- Gurgthock, The World Famous Ring of Blood!
(84784, 36221), -- Wodin the Troll-Servant, Entry Fee
(84784, 36222), -- Wodin the Troll-Servant, The Champion of Blood
(84861, 36284), -- Dr. Hadley Ricard, A Fascinating Fungus
(84861, 36285), -- Dr. Hadley Ricard, Dirgemire
(84861, 35146), -- Dr. Hadley Ricard, The Good Doctor
(84861, 36275), -- Dr. Hadley Ricard, The Search For Research
(87110, 37206), -- Tarr the Terrible, Tarr the Terrible
(87311, 37082), -- Kharg, Call of the Gladiator
(87311, 37083), -- Kharg, Fight, Kill, Salute!
(87311, 37286), -- Kharg, The Bloodshed Never Ends
(87393, 37125), -- Sallee Silverclamp, A Rare Find
(87393, 35147), -- Sallee Silverclamp, Fragments of the Past
(87706, 37210), -- Gazmolf Futzwangler, Aogexon's Fang
(87706, 37211), -- Gazmolf Futzwangler, Bergruu's Horn
(87706, 37221), -- Gazmolf Futzwangler, Dekorhan's Tusk
(87706, 37222), -- Gazmolf Futzwangler, Direhoof's Hide
(87706, 37223), -- Gazmolf Futzwangler, Gagrog's Skull
(87706, 37224), -- Gazmolf Futzwangler, Mu'gra's Head
(87706, 37225), -- Gazmolf Futzwangler, Thek'talon's Talon
(87706, 37520), -- Gazmolf Futzwangler, Vileclaw's Claw
(87706, 37226), -- Gazmolf Futzwangler, Xelganak's Stinger
(88240, 37293); -- Shadow Hunter Mok'e, Clearing the Mist
