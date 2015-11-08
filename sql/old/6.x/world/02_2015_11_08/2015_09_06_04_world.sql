UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (79519, 79539, 79748, 79890, 80153, 80155, 80157, 80232, 80233, 80469, 80481, 80508, 80639, 80648, 80740, 80758, 80834, 80860, 80863, 81109, 81128, 81443, 81514, 81770, 81773, 81784, 81890, 81891, 81920, 81929, 81949, 81959, 81960, 81961, 81972, 81978, 82100, 82101, 82124, 82126, 82194, 82212, 82278, 82293, 82402, 82403, 82468, 82621, 82691, 82709, 82713, 82759, 82786, 82788, 82813, 83463, 83529, 83549, 83608, 83609, 83772, 83773, 83903, 83904, 83959, 84122, 84262, 84276, 84291, 84292, 85062, 85080, 85320, 85425, 85550, 85566, 85598, 86355, 86381, 86475, 86597, 87123, 87561, 88179, 88195);

DELETE FROM `creature_queststarter` WHERE `id` IN (79519, 79539, 79748, 79890, 80153, 80155, 80157, 80232, 80233, 80469, 80481, 80508, 80639, 80648, 80740, 80758, 80834, 80860, 80863, 81109, 81128, 81443, 81514, 81770, 81773, 81784, 81890, 81891, 81920, 81929, 81949, 81959, 81960, 81961, 81972, 81978, 82100, 82101, 82124, 82126, 82194, 82212, 82278, 82293, 82402, 82403, 82468, 82621, 82691, 82709, 82713, 82759, 82786, 82788, 82813, 83463, 83529, 83549, 83608, 83609, 83772, 83773, 83903, 83904, 83959, 84122, 84262, 84276, 84291, 84292, 85062, 85080, 85320, 85425, 85550, 85566, 85598, 86355, 86381, 86475, 86597, 87123, 87561, 88179, 88195);
DELETE FROM `creature_questender` WHERE `id` IN (79519, 79539, 79890, 80153, 80155, 80157, 80232, 80469, 80481, 80508, 80639, 80648, 80740, 80758, 80834, 81109, 81128, 81443, 81514, 81770, 81773, 81784, 81890, 81891, 81920, 81929, 81960, 81961, 81972, 81978, 82100, 82124, 82126, 82194, 82212, 82468, 82621, 82713, 82759, 82786, 82788, 82813, 83463, 83608, 83609, 83772, 83773, 83903, 83904, 83959, 84122, 84262, 84291, 84292, 85080, 85320, 86355, 86475, 86597, 87123, 87561, 88179, 88195);

INSERT INTO `creature_queststarter` VALUES
(79519, 34657), -- Reshad, Adherents of the Sun God
(79519, 34805), -- Reshad, Echo Hunters
(79519, 34656), -- Reshad, Hidden in Plain Sight
(79519, 34658), -- Reshad, Orders From On High
(79519, 34659), -- Reshad, The Crone
(79539, 34655), -- Azik, The Shadows of Skettis
(79748, 35611), -- Percy, Return to Veil Terokk
(79890, 34756), -- Ornekka, A Charming Deception
(79890, 35636), -- Ornekka, All Due Respect
(80153, 36059), -- Shadow-Sage Iskar, A Worthy Vessel
(80153, 34827), -- Shadow-Sage Iskar, Last of the Talonpriests
(80153, 36601), -- Shadow-Sage Iskar, News from Nagrand
(80153, 36602), -- Shadow-Sage Iskar, News from Nagrand
(80155, 35259), -- Kura the Blind, Sol Sisters
(80157, 35634), -- Darkscryer Raastok, Control is King
(80157, 35260), -- Darkscryer Raastok, Hardly Working
(80157, 35258), -- Darkscryer Raastok, Legacy of the Apexis
(80232, 34830), -- Talonpriest Ishaal, Behind the Veil
(80232, 34828), -- Talonpriest Ishaal, Ishaal's Orb
(80232, 34829), -- Talonpriest Ishaal, New Neighbors
(80233, 34885), -- Skizzik, Mother of Thorns
(80469, 34886), -- Ikky, Baby Bird
(80481, 35009), -- High Ravenspeaker Krikka, Call of the Raven Mother
(80481, 35007), -- High Ravenspeaker Krikka, Rendezvous with the Ritualists
(80508, 34883), -- Talonpriest Zellek, A Feast of Shadows
(80508, 34942), -- Talonpriest Zellek, Back from Beyond
(80508, 34882), -- Talonpriest Zellek, Blades in the Dark
(80639, 35010), -- Iktis of the Flock, The High Ravenspeaker
(80639, 34991), -- Iktis of the Flock, To the... Rescue?
(80648, 34921), -- Anzu, Cult of the Ravenspeakers
(80648, 35003), -- Anzu, Ritual Severance
(80648, 35004), -- Anzu, Servants of a Dead God
(80740, 34938), -- Ravenspeaker Sekara, Ralshiara's Demise
(80740, 34923), -- Ravenspeaker Sekara, The Bloodmane
(80740, 34922), -- Ravenspeaker Sekara, Words of the Raven Mother
(80758, 35000), -- Talon Guard Kurekk, Banished From the Sky
(80758, 35001), -- Talon Guard Kurekk, Gaze of the Raven God
(80758, 35002), -- Talon Guard Kurekk, Sons of Sethe
(80758, 37144), -- Talon Guard Kurekk, Talon Guard Kurekk
(80834, 35245), -- Memory of Lithic, A Sentimental Relic
(80860, 34939), -- High Ravenspeaker Krikka, Declawing The Bloodmane
(80863, 34924), -- Vakora of the Flock, The Egg Thieves
(81109, 35077), -- Kimzee Pinchwhistle, Defungination
(81109, 35080), -- Kimzee Pinchwhistle, The Mother Lode
(81128, 35079), -- Engineer Gazwitz, Spore-be-Gone
(81443, 36428), -- Krixel Pinchwhistle, Curing With Force
(81443, 36384), -- Krixel Pinchwhistle, Field Trial
(81443, 35298), -- Krixel Pinchwhistle, Flame On
(81443, 35211), -- Krixel Pinchwhistle, Preventing the Worst
(81514, 34999), -- Kazu, Hatred Undying
(81770, 35671), -- Reshad, A Gathering of Shadows
(81770, 35733), -- Reshad, Rites of the Talonpriests
(81770, 34998), -- Reshad, Talon Watch
(81770, 34884), -- Reshad, The Kaliri Whisperer
(81770, 35897), -- Reshad, The Missing Piece
(81770, 36316), -- Reshad, Victory is Within Reach
(81773, 35082), -- Kimzee Pinchwhistle, Getting the Crew Back Together
(81784, 35081), -- Engineer Gazwitz, Clearing Out Before Cleaning Up
(81784, 35285), -- Engineer Gazwitz, Follow that Hotrod!
(81890, 35275), -- Shadow Hunter Ukambe, Inspecting the Troops
(81890, 35272), -- Shadow Hunter Ukambe, One of Our Own
(81891, 35276), -- Jasper Fel, Inspecting the Troops
(81891, 35274), -- Jasper Fel, One of Our Own
(81920, 37326), -- Taskmaster Gornek, Befriending the Locals
(81920, 36607), -- Taskmaster Gornek, News from Nagrand
(81920, 35277), -- Taskmaster Gornek, Orders, Commander?
(81929, 37327), -- Lieutenant Willem, Befriending the Locals
(81929, 36606), -- Lieutenant Willem, News from Nagrand
(81929, 35286), -- Lieutenant Willem, Orders, Commander?
(81949, 35293), -- Jasper Fel, Old Friends
(81959, 35295), -- Shadow Hunter Ukambe, What's Theirs is Ours
(81960, 35329), -- Jasper Fel, I See Dead People
(81961, 35322), -- Shadow Hunter Ukambe, I See Dead People
(81972, 35089), -- Kimzee Pinchwhistle, Skimming Off the Top
(81972, 35090), -- Kimzee Pinchwhistle, The Right Parts for the Job
(81978, 35091), -- Kimzee Pinchwhistle, Sporicide
(82100, 35339), -- Bryan Finn, A Parting Favor
(82101, 35339), -- Bryan Finn, A Parting Favor
(82124, 35353), -- Alice Finn, A Piece of the Puzzle
(82126, 35380), -- Alice Finn, Second in Command
(82194, 35407), -- Sir Edward, Punishable by Death
(82212, 35408), -- Lady Claudia, Prime the Cannons
(82278, 35482), -- Lady Claudia, Admiral Taylor
(82278, 36183), -- Lady Claudia, Admiral Taylor
(82293, 35482), -- Lady Claudia, Admiral Taylor
(82293, 36183), -- Lady Claudia, Admiral Taylor
(82402, 35550), -- Shadow Hunter Ukambe, Surviving in a Savage Land
(82403, 35549), -- Jasper Fel, Honoring a Hero
(82468, 36062), -- Kimzee Pinchwhistle, Kimzee Pinchwhistle
(82621, 35668), -- Reshad, Syth's Secret
(82691, 35705), -- Provisioner Galgar, Best Deals Anywhere
(82691, 35697), -- Provisioner Galgar, Peace Offering
(82709, 35699), -- Milly Osworth, Peace Offering
(82709, 35713), -- Milly Osworth, The Tinkertoss Twins
(82713, 35718), -- Mixxy Weldblast, Back on Track
(82713, 35879), -- Mixxy Weldblast, Safety Measures
(82713, 35706), -- Mixxy Weldblast, Sticky Situation
(82759, 35719), -- Filbert Tinkertoss, Back on Track
(82759, 35878), -- Filbert Tinkertoss, Safety Measures
(82759, 35716), -- Filbert Tinkertoss, Sticky Situation
(82786, 35738), -- Trixxy Weldblast, All Natural
(82786, 35766), -- Trixxy Weldblast, I See Dead Arakkoa
(82786, 35797), -- Trixxy Weldblast, The Ebon Hunter
(82788, 35739), -- Dilbert Tinkertoss, All Natural
(82788, 35782), -- Dilbert Tinkertoss, I See Dead Arakkoa
(82788, 35835), -- Dilbert Tinkertoss, The Ebon Hunter
(82813, 35895), -- Effigy of Terokk, Terokk's Fall
(82813, 35734), -- Effigy of Terokk, The Talon King
(83463, 37296), -- Dusk-Seer Irizzar, A Lack of Wasps
(83463, 37328), -- Dusk-Seer Irizzar, Not Here, Not Now
(83463, 37329), -- Dusk-Seer Irizzar, Not Here, Not Now
(83463, 37330), -- Dusk-Seer Irizzar, Not Here, Not Now
(83463, 37331), -- Dusk-Seer Irizzar, Not Here, Not Now
(83529, 35907), -- Dark Ranger Velonara, Attempted Murder
(83549, 35915), -- Hulda Shadowblade, Attempted Murder
(83608, 35924), -- Dark Ranger Velonara, Assassin's Mark
(83609, 35926), -- Hulda Shadowblade, Assassin's Mark
(83772, 36022), -- Dark Ranger Velonara, Extrinsic Motivation
(83772, 36028), -- Dark Ranger Velonara, Gardul Venomshiv
(83772, 35947), -- Dark Ranger Velonara, The Power of Poison
(83773, 36023), -- Hulda Shadowblade, Extrinsic Motivation
(83773, 36029), -- Hulda Shadowblade, Gardul Venomshiv
(83773, 35959), -- Hulda Shadowblade, The Power of Poison
(83903, 36166), -- Dark Ranger Velonara, No Time to Waste
(83904, 36165), -- Hulda Shadowblade, No Time to Waste
(83959, 37141), -- Talonpriest Ishaal, Talonpriest Ishaal
(84122, 35896), -- Shade of Terokk, The Avatar of Terokk
(84262, 35704), -- Reshad, When All Is Aligned
(84276, 36085), -- Reshad, On Ebon Wings
(84291, 37287), -- Kolrigg Stoktron, Cleaning House
(84292, 37292), -- Lunzul, Not In Your Army
(85062, 36179), -- Exterminator Lemmy, Unwanted Pests
(85080, 36353), -- Admiral Taylor, For Old Times' Sake
(85320, 34898), -- Ikky, Ikky
(85425, 36425), -- Ravager Egg, Egg Punt
(85550, 35619), -- Watchman Kovak, Pinchwhistle Gearworks
(85566, 35620), -- Scout Cel, Pinchwhistle Gearworks
(85598, 35257), -- Darkscryer Raastok, Power Unearthed
(86355, 35012), -- Anzu, Sethe, the Dead God
(86381, 36790), -- Mortally Wounded Initiate, The Initiate's Revenge
(86475, 35013), -- Talon Guard Kurekk, Lithic's Gift
(86475, 35011), -- Talon Guard Kurekk, The False Talon King
(86597, 36864), -- Benjamin Gibb, Three Feet Under
(87123, 37207), -- Vesharr, Vesharr
(87561, 37168), -- Leorajh, Leorajh, the Enlightened
(88179, 37276), -- Dark Ranger Velonara, Standing United
(88195, 37281); -- Hulda Shadowblade, Standing United

INSERT INTO `creature_questender` VALUES
(79519, 34657), -- Reshad, Adherents of the Sun God
(79519, 34656), -- Reshad, Hidden in Plain Sight
(79519, 34658), -- Reshad, Orders From On High
(79519, 34655), -- Reshad, The Shadows of Skettis
(79539, 34653), -- Azik, Arakkoa Exodus
(79539, 36951), -- Azik, Arakkoa Exodus
(79890, 34659), -- Ornekka, The Crone
(80153, 35671), -- Shadow-Sage Iskar, A Gathering of Shadows
(80153, 34942), -- Shadow-Sage Iskar, Back from Beyond
(80155, 35273), -- Kura the Blind, Hot Seat
(80157, 35260), -- Darkscryer Raastok, Hardly Working
(80157, 35258), -- Darkscryer Raastok, Legacy of the Apexis
(80157, 35257), -- Darkscryer Raastok, Power Unearthed
(80232, 34828), -- Talonpriest Ishaal, Ishaal's Orb
(80232, 34827), -- Talonpriest Ishaal, Last of the Talonpriests
(80232, 34829), -- Talonpriest Ishaal, New Neighbors
(80469, 34886), -- Ikky, Baby Bird
(80469, 34838), -- Ikky, Ikky's Egg
(80481, 34939), -- High Ravenspeaker Krikka, Declawing The Bloodmane
(80481, 34938), -- High Ravenspeaker Krikka, Ralshiara's Demise
(80481, 35010), -- High Ravenspeaker Krikka, The High Ravenspeaker
(80508, 34883), -- Talonpriest Zellek, A Feast of Shadows
(80508, 34830), -- Talonpriest Zellek, Behind the Veil
(80508, 34882), -- Talonpriest Zellek, Blades in the Dark
(80639, 34921), -- Iktis of the Flock, Cult of the Ravenspeakers
(80639, 34991), -- Iktis of the Flock, To the... Rescue?
(80648, 35012), -- Anzu, Sethe, the Dead God
(80740, 35007), -- Ravenspeaker Sekara, Rendezvous with the Ritualists
(80740, 34923), -- Ravenspeaker Sekara, The Bloodmane
(80740, 34922), -- Ravenspeaker Sekara, Words of the Raven Mother
(80758, 35000), -- Talon Guard Kurekk, Banished From the Sky
(80758, 37144), -- Talon Guard Kurekk, Talon Guard Kurekk
(80758, 34998), -- Talon Guard Kurekk, Talon Watch
(80834, 35013), -- Memory of Lithic, Lithic's Gift
(81109, 35077), -- Kimzee Pinchwhistle, Defungination
(81109, 35619), -- Kimzee Pinchwhistle, Pinchwhistle Gearworks
(81109, 35620), -- Kimzee Pinchwhistle, Pinchwhistle Gearworks
(81109, 36861), -- Kimzee Pinchwhistle, Pinchwhistle Gearworks
(81109, 36862), -- Kimzee Pinchwhistle, Pinchwhistle Gearworks
(81128, 35079), -- Engineer Gazwitz, Spore-be-Gone
(81128, 36179), -- Engineer Gazwitz, Unwanted Pests
(81443, 36428), -- Krixel Pinchwhistle, Curing With Force
(81443, 36384), -- Krixel Pinchwhistle, Field Trial
(81443, 35211), -- Krixel Pinchwhistle, Preventing the Worst
(81514, 34999), -- Kazu, Hatred Undying
(81770, 34756), -- Reshad, A Charming Deception
(81770, 35245), -- Reshad, A Sentimental Relic
(81770, 34805), -- Reshad, Echo Hunters
(81770, 34885), -- Reshad, Mother of Thorns
(81770, 35611), -- Reshad, Return to Veil Terokk
(81770, 35668), -- Reshad, Syth's Secret
(81770, 35895), -- Reshad, Terokk's Fall
(81770, 35896), -- Reshad, The Avatar of Terokk
(81770, 34884), -- Reshad, The Kaliri Whisperer
(81770, 35734), -- Reshad, The Talon King
(81770, 36316), -- Reshad, Victory is Within Reach
(81770, 35704), -- Reshad, When All Is Aligned
(81773, 35082), -- Kimzee Pinchwhistle, Getting the Crew Back Together
(81773, 35080), -- Kimzee Pinchwhistle, The Mother Lode
(81784, 35081), -- Engineer Gazwitz, Clearing Out Before Cleaning Up
(81890, 35272), -- Shadow Hunter Ukambe, One of Our Own
(81891, 35274), -- Jasper Fel, One of Our Own
(81920, 37328), -- Taskmaster Gornek, Not Here, Not Now
(81920, 37330), -- Taskmaster Gornek, Not Here, Not Now
(81920, 35277), -- Taskmaster Gornek, Orders, Commander?
(81920, 35550), -- Taskmaster Gornek, Surviving in a Savage Land
(81920, 35669), -- Taskmaster Gornek, Wanted: Keeho's Severed Paw
(81929, 35549), -- Lieutenant Willem, Honoring a Hero
(81929, 37329), -- Lieutenant Willem, Not Here, Not Now
(81929, 37331), -- Lieutenant Willem, Not Here, Not Now
(81929, 35286), -- Lieutenant Willem, Orders, Commander?
(81929, 35674), -- Lieutenant Willem, Wanted: Keeho's Severed Paw
(81960, 35293), -- Jasper Fel, Old Friends
(81961, 35295), -- Shadow Hunter Ukambe, What's Theirs is Ours
(81972, 35285), -- Kimzee Pinchwhistle, Follow that Hotrod!
(81978, 35089), -- Kimzee Pinchwhistle, Skimming Off the Top
(81978, 35091), -- Kimzee Pinchwhistle, Sporicide
(81978, 35090), -- Kimzee Pinchwhistle, The Right Parts for the Job
(82100, 35322), -- Bryan Finn, I See Dead People
(82100, 35329), -- Bryan Finn, I See Dead People
(82124, 35339), -- Alice Finn, A Parting Favor
(82126, 35353), -- Alice Finn, A Piece of the Puzzle
(82194, 35407), -- Sir Edward, Punishable by Death
(82194, 35380), -- Sir Edward, Second in Command
(82212, 35408), -- Lady Claudia, Prime the Cannons
(82468, 35298), -- Kimzee Pinchwhistle, Flame On
(82468, 36062), -- Kimzee Pinchwhistle, Kimzee Pinchwhistle
(82621, 35636), -- Reshad, All Due Respect
(82713, 35705), -- Mixxy Weldblast, Best Deals Anywhere
(82713, 35879), -- Mixxy Weldblast, Safety Measures
(82713, 35706), -- Mixxy Weldblast, Sticky Situation
(82759, 35878), -- Filbert Tinkertoss, Safety Measures
(82759, 35716), -- Filbert Tinkertoss, Sticky Situation
(82759, 35713), -- Filbert Tinkertoss, The Tinkertoss Twins
(82786, 35738), -- Trixxy Weldblast, All Natural
(82786, 35718), -- Trixxy Weldblast, Back on Track
(82786, 35766), -- Trixxy Weldblast, I See Dead Arakkoa
(82786, 35797), -- Trixxy Weldblast, The Ebon Hunter
(82788, 35739), -- Dilbert Tinkertoss, All Natural
(82788, 35719), -- Dilbert Tinkertoss, Back on Track
(82788, 35782), -- Dilbert Tinkertoss, I See Dead Arakkoa
(82788, 35835), -- Dilbert Tinkertoss, The Ebon Hunter
(82813, 35733), -- Effigy of Terokk, Rites of the Talonpriests
(82813, 35897), -- Effigy of Terokk, The Missing Piece
(83463, 37296), -- Dusk-Seer Irizzar, A Lack of Wasps
(83463, 37326), -- Dusk-Seer Irizzar, Befriending the Locals
(83463, 37327), -- Dusk-Seer Irizzar, Befriending the Locals
(83463, 35697), -- Dusk-Seer Irizzar, Peace Offering
(83463, 35699), -- Dusk-Seer Irizzar, Peace Offering
(83608, 35907), -- Dark Ranger Velonara, Attempted Murder
(83609, 35915), -- Hulda Shadowblade, Attempted Murder
(83772, 35924), -- Dark Ranger Velonara, Assassin's Mark
(83772, 36022), -- Dark Ranger Velonara, Extrinsic Motivation
(83772, 35947), -- Dark Ranger Velonara, The Power of Poison
(83773, 35926), -- Hulda Shadowblade, Assassin's Mark
(83773, 36023), -- Hulda Shadowblade, Extrinsic Motivation
(83773, 35959), -- Hulda Shadowblade, The Power of Poison
(83903, 36047), -- Dark Ranger Velonara, We Have Him Now
(83904, 36029), -- Hulda Shadowblade, Gardul Venomshiv
(83904, 36048), -- Hulda Shadowblade, We Have Him Now
(83959, 37141), -- Talonpriest Ishaal, Talonpriest Ishaal
(84122, 36059), -- Shade of Terokk, A Worthy Vessel
(84122, 37177), -- Shade of Terokk, Call of the Talon King
(84262, 36085), -- Reshad, On Ebon Wings
(84291, 37287), -- Kolrigg Stoktron, Cleaning House
(84292, 37292), -- Lunzul, Not In Your Army
(85080, 36353), -- Admiral Taylor, For Old Times' Sake
(85320, 34898), -- Ikky, Ikky
(86355, 35003), -- Anzu, Ritual Severance
(86355, 35004), -- Anzu, Servants of a Dead God
(86475, 35011), -- Talon Guard Kurekk, The False Talon King
(86597, 36864), -- Benjamin Gibb, Three Feet Under
(87123, 37207), -- Vesharr, Vesharr
(87561, 37168), -- Leorajh, Leorajh, the Enlightened
(88179, 37276), -- Dark Ranger Velonara, Standing United
(88195, 37281); -- Hulda Shadowblade, Standing United
