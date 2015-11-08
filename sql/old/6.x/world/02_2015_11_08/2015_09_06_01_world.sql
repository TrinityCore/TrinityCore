UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (70902, 71502, 71641, 72413, 72623, 72637, 73395, 73425, 73877, 74043, 74121, 74233, 74343, 74547, 74741, 74877, 75005, 75145, 75884, 76200, 76204, 76748, 77184, 77211, 77270, 77282, 77312, 77417, 77982, 78258, 79043, 79206, 79243);

DELETE FROM `creature_queststarter` WHERE `id` IN (70902, 71502, 71641, 72413, 72623, 72637, 73395, 73425, 73877, 74043, 74121, 74233, 74343, 74547, 74741, 74877, 75005, 75145, 75884, 76200, 76204, 76748, 77184, 77211, 77270, 77282, 77312, 77417, 77982, 78258, 79043, 79206, 79243, 79470, 79567, 79966, 80073, 80075, 80076, 80078, 80079, 80196, 80248, 80378, 80635, 80707, 80727, 80761, 80827, 80859, 80865, 81126, 81140, 81173, 81176, 81499, 81530, 82256, 82348, 82496, 82497, 82537, 83494, 84372, 84385, 84523, 84724, 84825, 84830, 84963, 84966, 84974, 87124, 88276, 88972, 89158, 93812, 93822, 95002);
DELETE FROM `creature_questender` WHERE `id` IN (70902, 71502, 71641, 72413, 72623, 72637, 73395, 73425, 73877, 74043, 74121, 74233, 74741, 74877, 75005, 75884, 76200, 76204, 76748, 77184, 77211, 77282, 77417, 77982, 78258, 79043, 79206, 79243, 79470, 79567, 79966, 80073, 80075, 80076, 80078, 80079, 80248, 80635, 80761, 80827, 80859, 80865, 81140, 81499, 81530, 82496, 82497, 82537, 84372, 84385, 84523, 84724, 84825, 84830, 84963, 84966, 84974, 87124, 88276, 88972, 93812, 93822, 95002);

INSERT INTO `creature_queststarter` VALUES
(70902, 33419), -- Roona, A Matter of Life and Death
(71502, 33813), -- Ariaana, In Need of a Hero
(71641, 33077), -- Old Loola, A Grandmother's Remedy
(71641, 34876), -- Old Loola, Loola's Lost Love
(72413, 33256), -- Exarch Akama, The Defense of Karabor
(72623, 33120), -- Delas Moonfang, A Curse Upon the Woods
(72623, 33113), -- Delas Moonfang, Shadowmoonwell
(72637, 33269), -- Cordana Felsong, Cleaning Up Gul'var
(73395, 33533), -- Yrel, The Secrets of Gorgrond
(73425, 33080), -- Rangari Veka, Going Undercover
(73877, 33271), -- Jarrod Hamby, Game of Thorns
(74043, 33072), -- Prophet Velen, Into Twilight
(74043, 34019), -- Prophet Velen, Shadows Awaken
(74121, 33078), -- Loreseeker Heidii, The Dark that Blinds Us
(74233, 33084), -- Traevar Gunnermark, The Big Haul
(74343, 33905), -- Vindicator Tenuum, Closing the Door
(74547, 34806), -- Ryan Metcalf, Prune the Podlings
(74741, 35614), -- Romuul, Artificer Romuul
(74877, 33081), -- Yrel, Escape From Shaz'gul
(75005, 33765), -- Samaara, Dark Enemies
(75145, 33255), -- Vindicator Maraad, The Righteous March
(75884, 33082), -- Rulkan, Ancestor's Memory
(75884, 34043), -- Rulkan, Darkest Night
(75884, 35631), -- Rulkan, Rulkan
(76200, 33786), -- Prelate Reenu, Crippled Caravan
(76204, 33788), -- Fiona, Cooking With Unstable Herbs
(76204, 35617), -- Fiona, Fiona
(76204, 33787), -- Fiona, Fiona's Solution
(76204, 35006), -- Fiona, Poison Paralysis
(76204, 33808), -- Fiona, Swamplighter Queen
(76748, 35625), -- Shelly Hamby, Shelly Hamby
(77184, 33062), -- Archmage Khadgar, Catching His Eye
(77184, 33112), -- Archmage Khadgar, Ominous Portents
(77184, 33115), -- Archmage Khadgar, Shrouding Stones
(77184, 33066), -- Archmage Khadgar, Soul Shards of Summoning
(77211, 34847), -- Dulga, Forbidden Love
(77270, 33331), -- Captured Critter, Captured Critters
(77282, 33837), -- Prophet Velen, Darkness Falls
(77282, 35032), -- Prophet Velen, Into Anguish
(77282, 34054), -- Prophet Velen, The Dark Side of the Moon
(77282, 35093), -- Prophet Velen, The Dark Side of the Moon
(77312, 33255), -- Vindicator Maraad, The Righteous March
(77417, 33135), -- Image of Archmage Khadgar, Cleaning Up Gul'var
(77417, 33114), -- Image of Archmage Khadgar, Forging the Soul Trap
(77417, 33168), -- Image of Archmage Khadgar, Heart On Fire
(77417, 33116), -- Image of Archmage Khadgar, To Catch a Shadow
(77982, 34355), -- Rexxar, Dirty Rats
(77982, 34353), -- Rexxar, Shredder Suppressor
(78258, 34397), -- Rexxar, Downsizing the Darktide
(78258, 34365), -- Rexxar, Releasing Rylak
(78258, 34450), -- Rexxar, Rylak Rescue
(79043, 33586), -- Prophet Velen, Chasing Shadows
(79043, 33076), -- Prophet Velen, The Clarity Elixir
(79043, 33059), -- Prophet Velen, The Fate of Karabor
(79206, 34582), -- Prophet Velen, Finding a Foothold
(79243, 34586), -- Baros Alexston, Establish Your Garrison
(79243, 34584), -- Baros Alexston, Looking for Lumber
(79243, 34616), -- Baros Alexston, Ravenous Ravens
(79470, 34583), -- Vindicator Maraad, For the Alliance!
(79567, 34585), -- Yrel, Quakefist
(79966, 33461), -- Lost Packmule, Gloomshade Game Hunter
(79966, 33263), -- Lost Packmule, Gloomshade Grove
(80073, 34789), -- Exarch Maladaar, Speaker for the Dead
(80073, 36168), -- Exarch Maladaar, The Trial of Faith
(80073, 35552), -- Exarch Maladaar, Trust No One
(80075, 34780), -- Exarch Hataaru, Invisible Ramparts
(80075, 35070), -- Exarch Hataaru, Shut 'er Down
(80076, 34785), -- Exarch Othaar, Hataaru, the Artificer
(80076, 34783), -- Exarch Othaar, Naielle, The Rangari
(80078, 34787), -- Exarch Akama, Exarch Maladaar
(80078, 36164), -- Exarch Akama, The Trial of Courage
(80079, 34788), -- Exarch Naielle, Friend of the Exarchs
(80079, 34784), -- Exarch Naielle, Fun with Fungus
(80079, 35905), -- Exarch Naielle, Supply Drop
(80079, 36167), -- Exarch Naielle, The Trial of Heart
(80196, 33070), -- Efee, Think of the Children!
(80248, 34836), -- Zukaza, Lunarblossom
(80378, 34897), -- Rangari Navra, Rangari Roundup
(80635, 35015), -- Rangari Arepheon, Gestating Genesaur
(80707, 34997), -- Sleepy Rangari, Slumberbloom
(80727, 35014), -- Rangari Arepheon, Blademoon Bloom
(80761, 34994), -- Beezil Linkspanner, Forever Young
(80827, 36311), -- Haephest, Father and Son
(80859, 34996), -- Rangari Duula, Rotting Riverbeasts
(80865, 34995), -- Tarenar Sunstrike, Botani Beatdown
(81126, 35450), -- Prelate Luari, The Southern Wilds
(81140, 34786), -- Apprentice Artificer Andren, Engorged Goren
(81173, 33795), -- Illuminate Praavi, Across the Stars
(81176, 33793), -- Rangari Saa'to, Harbingers of the Void
(81176, 33083), -- Rangari Saa'to, On the Offensive
(81176, 33794), -- Rangari Saa'to, The Great Salvation
(81499, 35190), -- Soulbinder Zamaya, An Ancient Threat
(81499, 35188), -- Soulbinder Zamaya, Pesky Podlings
(81530, 35194), -- Anchorite Laanda, Facing Demons
(81530, 35196), -- Anchorite Laanda, Forging Ahead
(81530, 35197), -- Anchorite Laanda, Forging Ahead
(81530, 35191), -- Anchorite Laanda, Shattering the Enemy
(81530, 35189), -- Anchorite Laanda, The Word of Socrethar
(82256, 35444), -- Farmer Gehaar, The Southern Wilds
(82348, 34782), -- Vindicator Maraad, The Exarch Council
(82496, 35345), -- Telos, Shocking Assistance
(82497, 35344), -- Abatha, The Missing Father
(82537, 34790), -- Rangari Chel, The Sting
(83494, 34352), -- Darktide Pilferer, Darktide Defender
(84372, 36202), -- Madari, Anglin' In Our Garrison
(84372, 36199), -- Madari, Moonshell Claws
(84372, 36201), -- Madari, Proving Your Worth
(84385, 36185), -- Fanara, Fair Trade
(84385, 36177), -- Fanara, Friendly Competition
(84523, 36269), -- Ameeka, Hexcloth
(84523, 36266), -- Ameeka, The Clothes on Their Backs
(84724, 36240), -- Sha'la, Slow and Steady
(84724, 36241), -- Sha'la, The Power of Preservation
(84825, 36287), -- Goggles, Snatch 'n' Grab
(84830, 36409), -- Artificer Baleera, Restoration
(84963, 36315), -- Deema, Oru'kai's Staff
(84966, 36313), -- Arcanist Delath, Failed Apprentice
(84974, 36169), -- Exarch Maladaar, The Trial of Champions
(87124, 37203), -- Ashlei, Ashlei
(88276, 35187), -- Archmage Modera, Infiltrating the Sargerei
(88972, 34792), -- Exarch Maladaar, The Traitor's True Name
(89158, 34455), -- Goblin Mind Control Device, Free their Minds
(93812, 39665), -- Salty Jorren, A True Naval Commander
(93822, 39404), -- Merreck Vonder, Destroying the Competition
(93822, 39666), -- Merreck Vonder, Equipping Our Fleet
(93822, 39601), -- Merreck Vonder, I Sunk Your Battleship
(93822, 39655), -- Merreck Vonder, If At First You Fail, Try Again!
(93822, 39082), -- Merreck Vonder, Let's Get To Work
(93822, 39056), -- Merreck Vonder, Naval Commander
(93822, 39068), -- Merreck Vonder, Naval Domination
(93822, 39067), -- Merreck Vonder, Upgrading The Fleet
(95002, 39055), -- Yanas Seastrike, Ship Shape
(95002, 38435); -- Yanas Seastrike, The Invasion of Tanaan

INSERT INTO `creature_questender` VALUES
(70902, 33419), -- Roona, A Matter of Life and Death
(71502, 33813), -- Ariaana, In Need of a Hero
(71641, 33077), -- Old Loola, A Grandmother's Remedy
(71641, 34876), -- Old Loola, Loola's Lost Love
(72413, 33255), -- Exarch Akama, The Righteous March
(72623, 33120), -- Delas Moonfang, A Curse Upon the Woods
(72623, 33113), -- Delas Moonfang, Shadowmoonwell
(72637, 33135), -- Cordana Felsong, Cleaning Up Gul'var
(72637, 33269), -- Cordana Felsong, Cleaning Up Gul'var
(73395, 33837), -- Yrel, Darkness Falls
(73395, 36163), -- Yrel, Garrison Campaign: The Exarch's Call
(73395, 34054), -- Yrel, The Dark Side of the Moon
(73395, 35093), -- Yrel, The Dark Side of the Moon
(73395, 33256), -- Yrel, The Defense of Karabor
(73395, 33794), -- Yrel, The Great Salvation
(73425, 34897), -- Rangari Veka, Rangari Roundup
(73877, 33263), -- Jarrod Hamby, Gloomshade Grove
(74043, 33905), -- Prophet Velen, Closing the Door
(74043, 33765), -- Prophet Velen, Dark Enemies
(74043, 34019), -- Prophet Velen, Shadows Awaken
(74043, 33070), -- Prophet Velen, Think of the Children!
(74121, 33078), -- Loreseeker Heidii, The Dark that Blinds Us
(74233, 33084), -- Traevar Gunnermark, The Big Haul
(74741, 35614), -- Romuul, Artificer Romuul
(74877, 33080), -- Yrel, Going Undercover
(75005, 33075), -- Samaara, A Hero's Welcome
(75884, 33082), -- Rulkan, Ancestor's Memory
(75884, 33586), -- Rulkan, Chasing Shadows
(75884, 35631), -- Rulkan, Rulkan
(76200, 35444), -- Prelate Reenu, The Southern Wilds
(76200, 35450), -- Prelate Reenu, The Southern Wilds
(76200, 35459), -- Prelate Reenu, The Southern Wilds
(76204, 33788), -- Fiona, Cooking With Unstable Herbs
(76204, 33786), -- Fiona, Crippled Caravan
(76204, 35617), -- Fiona, Fiona
(76204, 33787), -- Fiona, Fiona's Solution
(76204, 35006), -- Fiona, Poison Paralysis
(76204, 33808), -- Fiona, Swamplighter Queen
(76748, 33271), -- Shelly Hamby, Game of Thorns
(76748, 35625), -- Shelly Hamby, Shelly Hamby
(77184, 33062), -- Archmage Khadgar, Catching His Eye
(77184, 33359), -- Archmage Khadgar, Meet Us at Starfall Outpost
(77184, 33112), -- Archmage Khadgar, Ominous Portents
(77184, 33115), -- Archmage Khadgar, Shrouding Stones
(77184, 33116), -- Archmage Khadgar, To Catch a Shadow
(77211, 34847), -- Dulga, Forbidden Love
(77282, 33795), -- Prophet Velen, Across the Stars
(77282, 34043), -- Prophet Velen, Darkest Night
(77282, 33793), -- Prophet Velen, Harbingers of the Void
(77282, 35032), -- Prophet Velen, Into Anguish
(77282, 33083), -- Prophet Velen, On the Offensive
(77417, 33114), -- Image of Archmage Khadgar, Forging the Soul Trap
(77417, 33168), -- Image of Archmage Khadgar, Heart On Fire
(77417, 33066), -- Image of Archmage Khadgar, Soul Shards of Summoning
(77982, 34354), -- Rexxar, A Good Death
(77982, 35861), -- Rexxar, Garrison Campaign: Darktide Roost
(77982, 35876), -- Rexxar, Garrison Campaign: Darktide Roost
(77982, 34353), -- Rexxar, Shredder Suppressor
(78258, 34355), -- Rexxar, Dirty Rats
(78258, 34397), -- Rexxar, Downsizing the Darktide
(78258, 34365), -- Rexxar, Releasing Rylak
(79043, 33072), -- Prophet Velen, Into Twilight
(79043, 33076), -- Prophet Velen, The Clarity Elixir
(79043, 33059), -- Prophet Velen, The Fate of Karabor
(79206, 34575), -- Prophet Velen, Step Three: Prophet!
(79243, 34583), -- Baros Alexston, For the Alliance!
(79243, 34584), -- Baros Alexston, Looking for Lumber
(79243, 34616), -- Baros Alexston, Ravenous Ravens
(79470, 34582), -- Vindicator Maraad, Finding a Foothold
(79567, 34585), -- Yrel, Quakefist
(79966, 34820), -- Lost Packmule, Lost Lumberjacks
(80073, 34787), -- Exarch Maladaar, Exarch Maladaar
(80073, 34789), -- Exarch Maladaar, Speaker for the Dead
(80073, 34792), -- Exarch Maladaar, The Traitor's True Name
(80073, 34791), -- Exarch Maladaar, Warning the Exarchs
(80075, 34785), -- Exarch Hataaru, Hataaru, the Artificer
(80075, 35070), -- Exarch Hataaru, Shut 'er Down
(80076, 34782), -- Exarch Othaar, The Exarch Council
(80078, 34779), -- Exarch Akama, Circle the Wagon
(80079, 34788), -- Exarch Naielle, Friend of the Exarchs
(80079, 34784), -- Exarch Naielle, Fun with Fungus
(80079, 34783), -- Exarch Naielle, Naielle, The Rangari
(80248, 34836), -- Zukaza, Lunarblossom
(80635, 35014), -- Rangari Arepheon, Blademoon Bloom
(80635, 35015), -- Rangari Arepheon, Gestating Genesaur
(80761, 34994), -- Beezil Linkspanner, Forever Young
(80827, 36311), -- Haephest, Father and Son
(80827, 36309), -- Haephest, The Strength of Iron
(80859, 34996), -- Rangari Duula, Rotting Riverbeasts
(80865, 34995), -- Tarenar Sunstrike, Botani Beatdown
(81140, 34786), -- Apprentice Artificer Andren, Engorged Goren
(81499, 35190), -- Soulbinder Zamaya, An Ancient Threat
(81499, 35188), -- Soulbinder Zamaya, Pesky Podlings
(81530, 35187), -- Anchorite Laanda, Infiltrating the Sargerei
(81530, 35191), -- Anchorite Laanda, Shattering the Enemy
(81530, 35195), -- Anchorite Laanda, Socrethar's Fury
(81530, 35189), -- Anchorite Laanda, The Word of Socrethar
(82496, 35344), -- Telos, The Missing Father
(82497, 35345), -- Abatha, Shocking Assistance
(82497, 35343), -- Abatha, The Young Alchemist
(82537, 34790), -- Rangari Chel, The Sting
(84372, 34194), -- Madari, Looking For Help
(84372, 36199), -- Madari, Moonshell Claws
(84372, 36201), -- Madari, Proving Your Worth
(84385, 36176), -- Fanara, A Call for Huntsman
(84385, 36177), -- Fanara, Friendly Competition
(84523, 36262), -- Ameeka, Ameeka, Master Tailor
(84523, 36269), -- Ameeka, Hexcloth
(84523, 36266), -- Ameeka, The Clothes on Their Backs
(84724, 36239), -- Sha'la, A Mysterious Satchel
(84724, 36240), -- Sha'la, Slow and Steady
(84825, 36287), -- Goggles, Snatch 'n' Grab
(84825, 36286), -- Goggles, Transponder 047-B
(84830, 36408), -- Artificer Baleera, A Power Lost
(84830, 36409), -- Artificer Baleera, Restoration
(84963, 36313), -- Deema, Failed Apprentice
(84966, 36315), -- Arcanist Delath, Oru'kai's Staff
(84966, 36310), -- Arcanist Delath, The Arakkoan Enchanter
(84974, 36169), -- Exarch Maladaar, The Trial of Champions
(84974, 36168), -- Exarch Maladaar, The Trial of Faith
(87124, 37203), -- Ashlei, Ashlei
(88276, 35185), -- Archmage Modera, Garrison Campaign: The Sargerei
(88276, 35186), -- Archmage Modera, Garrison Campaign: The Sargerei
(88972, 34789), -- Exarch Maladaar, Speaker for the Dead
(93812, 38932), -- Salty Jorren, Equipment Blueprint: Bilge Pump
(93812, 39368), -- Salty Jorren, Equipment Blueprint: Blast Furnace
(93812, 39366), -- Salty Jorren, Equipment Blueprint: Felsmoke Launchers
(93812, 39365), -- Salty Jorren, Equipment Blueprint: Ghostly Spyglass
(93812, 39364), -- Salty Jorren, Equipment Blueprint: Gyroscopic Internal Stabilizer
(93812, 39356), -- Salty Jorren, Equipment Blueprint: High Intensity Fog Lights
(93812, 39363), -- Salty Jorren, Equipment Blueprint: Ice Cutter
(93812, 39355), -- Salty Jorren, Equipment Blueprint: Trained Shark Tank
(93812, 39360), -- Salty Jorren, Equipment Blueprint: True Iron Rudder
(93812, 39359), -- Salty Jorren, Equipment Blueprint: Tuskarr Fishing Net
(93812, 39358), -- Salty Jorren, Equipment Blueprint: Unsinkable
(93812, 39666), -- Salty Jorren, Equipping Our Fleet
(93822, 39665), -- Merreck Vonder, A True Naval Commander
(93822, 39404), -- Merreck Vonder, Destroying the Competition
(93822, 39655), -- Merreck Vonder, If At First You Fail, Try Again!
(93822, 39056), -- Merreck Vonder, Naval Commander
(93822, 39068), -- Merreck Vonder, Naval Domination
(93822, 39422), -- Merreck Vonder, Shipyard Report
(93822, 39067), -- Merreck Vonder, Upgrading The Fleet
(95002, 39055), -- Yanas Seastrike, Ship Shape
(95002, 39276); -- Yanas Seastrike, Strange Tools
