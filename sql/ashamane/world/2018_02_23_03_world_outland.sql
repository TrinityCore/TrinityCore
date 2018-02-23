DELETE FROM `gameobject_template_addon` WHERE `entry` IN (278457 /*Tableau de commandement du chef de guerre*/, 248956 /*Compendium d’armes anciennes, volume V*/, 278676 /*Tableau de l’aventurier*/, 269966 /*Grande caisse*/, 278575 /*Tableau de l’appel des héros*/, 278347 /*Tableau de commandement du chef de guerre*/, 278574 /*Tableau de l’appel des héros*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(278457, 29, 262144), -- Tableau de commandement du chef de guerre
(248956, 0, 4), -- Compendium d’armes anciennes, volume V
(278676, 35, 262144), -- Tableau de l’aventurier
(269966, 94, 0), -- Grande caisse
(278575, 12, 262144), -- Tableau de l’appel des héros
(278347, 29, 262144), -- Tableau de commandement du chef de guerre
(278574, 12, 262144); -- Tableau de l’appel des héros

UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=185877; -- Nethercite Deposit
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=185881; -- Netherdust Bush
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=216477; -- Boarded Gate
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185128; -- Lianthe's Strongbox
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184860; -- Fel Reaver Armor Plating
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=184827; -- Legion Display Device
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=184834; -- Infernal
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184859; -- Fel Reaver Power Core
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185220; -- Massive Treasure Chest
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry`=214507; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185225; -- Cabal Chest
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185224; -- Cabal Chest
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=183104; -- Terokkar Banner
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185226; -- Cabal Chest
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=29784; -- Basic Campfire
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=183294; -- The Shadow Labyrinth
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181557; -- Khorium Vein
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185201; -- Eye of Veil Shienor
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185200; -- Eye of Veil Reskk
UPDATE `gameobject_template_addon` SET `flags`=5 WHERE `entry`=182566; -- Western Altar
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181277; -- Terocone
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184466; -- Metal Coffer
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184115; -- Arelion's Knapsack
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry`=211498; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185302; -- Fei Fei's Cache
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=216327; -- Soulstone Fragment
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=184415; -- Portal Kaalez
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=176586; -- Mountain Silversage
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=2041; -- Liferoot
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry`=214500; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184310; -- Suspicious Outhouse
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=184255; -- Long Neck Spectrum Analyzer
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=259114; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181279; -- Netherbloom
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=188132; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184726; -- Thunderlord Clan Drum
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184728; -- Thunderlord Clan Tablet
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184727; -- Thunderlord Clan Arrow
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=185152; -- Grulloc's Sack
UPDATE `gameobject_template_addon` SET `faction`=14 WHERE `entry`=185922; -- Crystalforge controller
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181270; -- Felweed
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=184950; -- The First Prophecy
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=185234; -- Gorgrom's Altar
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181569; -- Rich Adamantite Deposit
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181281; -- Mana Thistle
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181280; -- Nightmare Vine
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=184744; -- T'chali's Hookah
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry`=214501; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry`=214503; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template_addon` SET `flags`=2097156 WHERE `entry`=182184; -- Daggerfen Poison Manual
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=176584; -- Dreamfoil
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183044; -- Felweed
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=176583; -- Golden Sansam
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183043; -- Ragveil
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183045; -- Dreaming Glory
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183046; -- Blindweed

DELETE FROM `creature_template_addon` WHERE `entry` IN (23269 /*23269 (Barash the Den Mother) - Battoir*/, 23209 /*23209 (Dragonmaw Peon Kill Credit)*/, 23267 /*23267 (Arvoar the Rapacious) - Battoir*/, 23305 /*23305 (Crazed Murkblood Foreman)*/, 23164 /*23164 (Toranaku)*/, 23324 /*23324 (Crazed Murkblood Miner)*/, 23264 /*23264 (Overmine Flayer) - Battoir*/, 23166 /*23166 (Ronag the Slave Driver)*/, 23285 /*23285 (Nethermine Burster) - Forage de tunnel Passif*/, 23149 /*23149 (Mistress of the Mines)*/, 23148 /*23148 (Forgus)*/, 23143 /*23143 (Horus)*/, 23150 /*23150 (Dragonmaw Pitfighter)*/, 23289 /*23289 (Mine Car) - Chariot de mine*/, 23140 /*23140 (Taskmaster Varkule Dragonbreath)*/, 23141 /*23141 (Yarzill the Merc)*/, 23142 /*23142 (Goblin Merc)*/, 23139 /*23139 (Overlord Mor'ghor)*/, 23145 /*23145 (Rumpus)*/, 23146 /*23146 (Dragonmaw Enforcer)*/, 23286 /*23286 (Black Blood of Draenor)*/, 23311 /*23311 (Disobedient Dragonmaw Peon) - Paresseux et bon à rien*/, 23169 /*23169 (Nethermine Flayer)*/, 23308 /*23308 (Dragonmaw Peon Work Node)*/, 23501 /*23501 (Netherwing Ray)*/, 23225 /*23225 (Netherwing Drake Escape Point)*/, 113941 /*113941 (Invisible Stalker)*/, 22860 /*22860 (Illidari Succubus)*/, 22858 /*22858 (Shadowhoof Assassin)*/, 22859 /*22859 (Shadowhoof Summoner) - Canalisation des Arcanes*/, 21166 /*21166 (Illidari Dreadlord)*/, 22934 /*22934 (Black Temple Battle Sensor) - Régulateur de flux des combats*/, 22857 /*22857 (Illidari Ravager)*/, 22862 /*22862 (Anchorite Caalen)*/, 22863 /*22863 (Seasoned Magister)*/, 22861 /*22861 (Lightsworn Vindicator)*/, 22864 /*22864 (Fyra Dawnstar)*/, 24925 /*24925 (Boss Portal: Purple (3.00))*/, 18528 /*18528 (Xi'ri)*/, 23496 /*23496 (Akama Event Trigger)*/, 21699 /*21699 (Maiev Shadowsong)*/, 21897 /*21897 (Felspine the Greater) - Aura de Gangrefeu*/, 23020 /*23020 (Shadow Serpent) - Forme d'Ombre*/, 23454 /*23454 (Dragonmaw Raid Credit Marker (Aldor))*/, 23452 /*23452 (Commander Arcus)*/, 21095 /*21095 (Credit Marker: Water)*/, 21709 /*21709 (Eykenen)*/, 23443 /*23443 (Dragonmaw Raid Credit Marker (Scryers))*/, 23434 /*23434 (Commander Hobb)*/, 24868 /*24868 (Niobe Whizzlespark)*/, 21287 /*21287 (Warbringer Razuun)*/, 19759 /*19759 (Newly Crafted Infernal) - Immoler*/, 19760 /*19760 (Cooling Infernal) - Feindre la mort permanent (Immobilisé)*/, 21211 /*21211 (Invis Deathforge Target)*/, 19757 /*19757 (Infernal Soul)*/, 17008 /*17008 (Gul'dan)*/, 21710 /*21710 (Uylaru)*/, 21703 /*21703 (Corrupt Fire Totem)*/, 21183 /*21183 (Oronok Torn-heart)*/, 21255 /*21255 (Umberhowl)*/, 21029 /*21029 (Captured Water Spirit) - Bulle d'eau*/, 20795 /*20795 (Keeper of the Cistern)*/, 21027 /*21027 (Earthmender Wilda) - Bulle d'eau*/, 21041 /*21041 (Earthmender Wilda Trigger)*/, 21196 /*21196 (Ravenous Flayer)*/, 62621 /*Gangreflamme*/, 19343 /*19343 (Trop Rendlimb)*/, 19345 /*19345 (Kalara)*/, 21359 /*21359 (Blood Guard Gulmok)*/, 22043 /*22043 (Sergeant Kargrul)*/, 21771 /*21771 (Warcaller Sardon Truslice)*/, 19319 /*19319 (Innkeeper Darg Bloodclaw)*/, 19317 /*19317 (Drek'Gol)*/, 19341 /*19341 (Grutah)*/, 19339 /*19339 (Korthul)*/, 19333 /*19333 (Grokom Deatheye)*/, 51910 /*51910 (Kor'kron Defender)*/, 21772 /*21772 (Chief Apothecary Hildagard)*/, 21770 /*21770 (Researcher Tiorus)*/, 19342 /*19342 (Krek Cragcrush)*/, 21769 /*21769 (Overlord Or'barokh)*/, 21340 /*21340 (Detrafila)*/, 21336 /*21336 (Gedrah)*/, 21938 /*21938 (Earthmender Splinthoof)*/, 25099 /*25099 (Jonathan Garrett)*/, 19348 /*19348 (Targrom)*/, 20494 /*20494 (Dama Wildmane)*/, 20500 /*20500 (Olrokk)*/, 21249 /*21249 (Wrathstalker)*/, 21501 /*21501 (Makazradon)*/, 66557 /*Chevalier de sang Antari*/, 66544 /*Jadefeu*/, 66545 /*Arcanus*/, 66543 /*Morsure-du-Néant*/, 21879 /*21879 (Vilewing Chimaera)*/, 62314 /*Cafard corrompu*/, 23363 /*23363 (Sahaak)*/, 21728 /*21728 (Skettis Surger)*/, 23029 /*23029 (Talonsworn Forest-Rager)*/, 21804 /*21804 (Skettis Kaliri)*/, 22986 /*22986 (Skettis - Invis Raven Stone)*/, 22991 /*22991 (Monstrous Kaliri Egg Trigger)*/, 22831 /*22831 (Outland Children's Week Auchindoun Trigger)*/, 24893 /*24893 (Auchindoun Daily Quest Trigger)*/, 22381 /*22381 (Hathyss the Wicked)*/, 18686 /*18686 (Doomsayer Jurim)*/, 61440 /*Scorpide à queue rayée*/, 21636 /*21636 (Vengeful Draenei) - Particules spirituelles, Particules spirituelles (grosses)*/, 18989 /*18989 (Stonebreaker Guard)*/, 24886 /*24886 (Exorcist Vaisha)*/, 18554 /*18554 (Sharth Voldoun)*/, 18648 /*18648 (Stonegazer)*/, 18438 /*18438 (Naphthal'ar) - Radiation bleue*/, 62583 /*Jeune traqueur dimensionnel*/, 24437 /*24437 (Consortium Assistant)*/, 24369 /*24369 (Wind Trader Zhareem)*/, 24370 /*24370 (Nether-Stalker Mah'duun)*/, 24412 /*24412 (Daily Dungeon Image Bunny)*/, 24411 /*24411 (Shattered Hand Centurion Image)*/, 22819 /*22819 (Orphan Matron Mercy)*/, 25992 /*25992 (Big Bruiser)*/, 23699 /*23699 (Kevin Browning)*/, 25136 /*25136 (Shattered Sun Trainee)*/, 35002 /*35002 (Asara Dawnblaze) - Armure de givre*/, 25135 /*25135 (Shattered Sun Trainee)*/, 25138 /*25138 (Captain Dranarus)*/, 25137 /*25137 (Shattered Sun Trainee)*/, 25134 /*25134 (Shattered Sun Trainee)*/, 35001 /*35001 (Saeld Brightflare) - Armure de givre*/, 52277 /*52277 (Droha)*/, 50136 /*50136 (Baelir)*/, 25885 /*25885 (Whirligig Wafflefry)*/, 50127 /*50127 (Windstalker Ifram) - Poison mortel*/, 50137 /*50137 (Muha)*/, 50130 /*50130 (Luknar)*/, 50128 /*50128 (Fel-Caller Guloto)*/, 52278 /*52278 (Linsa)*/, 52268 /*52268 (Riha)*/, 50140 /*50140 (Auctioneer Lyrsara)*/, 50139 /*50139 (Auctioneer Kalaren)*/, 25143 /*25143 (Shattered Sun Veteran)*/, 25167 /*25167 (General Tiras'alan)*/, 50012 /*50012 (Blood Knight Argaron) - Aura de vindicte*/, 50010 /*50010 (Alaressa)*/, 50007 /*50007 (Derithela)*/, 50013 /*50013 (Matron Ismara)*/, 50018 /*50018 (Tarlhir)*/, 50016 /*50016 (Pathstalker Arpalir) - Poison mortel*/, 50017 /*50017 (Summoner Durael)*/, 24938 /*24938 (Shattered Sun Marksman)*/, 25153 /*25153 (Shattered Sun Magi)*/, 25142 /*25142 (Shattered Sun Marksman)*/, 27667 /*27667 (Anwehu)*/, 25155 /*25155 (Shattered Sun Cleric)*/, 24932 /*24932 (Exarch Nasuun)*/, 27666 /*27666 (Ontuvo)*/, 24936 /*24936 (Sunwell Daily Bunny x 0.01)*/, 25195 /*25195 (Marksman Bova)*/, 33678 /*33678 (Jijia)*/, 33684 /*33684 (Weaver Aoa)*/, 33674 /*33674 (Alchemist Kanhu)*/, 23484 /*23484 (Haldor the Compulsive)*/, 23270 /*23270 (Vindicator Aeus)*/, 50143 /*50143 (Auctioneer Itoran)*/, 50145 /*50145 (Auctioneer Braku)*/, 23465 /*23465 (Zoya)*/, 23433 /*23433 (Barthamus)*/, 23466 /*23466 (Voranaku)*/, 24393 /*24393 (The Rokk)*/, 24416 /*24416 (Grisy Spicecrackle)*/, 18597 /*18597 (Sha'nir)*/, 62555 /*Jeune écorcheur*/, 24922 /*24922 (Razorthorn Ravager)*/, 24920 /*24920 (Razorthorn Flayer)*/, 17794 /*17794 (Alliance Tower Buffer)*/, 19028 /*19028 (The Overlook Capture Credit Marker)*/, 18677 /*18677 (Mekthorg the Wild)*/, 16857 /*16857 (Marauding Crust Burster) - Forage de tunnel Passif*/, 16977 /*16977 (Arch Mage Xintor) - Voile de la mort*/, 17060 /*17060 (Hellfire Combat Dummy Small)*/, 18678 /*18678 (Fulgorge) - Forage de tunnel Passif rouge*/, 35100 /*35100 (Hargen Bronzewing)*/, 30734 /*30734 (Jezebel Bican)*/, 30721 /*30721 (Michael Schwan)*/, 47574 /*47574 (Gerdra Fardelve)*/, 51799 /*51799 (Thrallmar Grunt)*/, 51800 /*51800 (Honor Hold Defender) - Détection de l'invisibilité et du camouflage*/, 18679 /*18679 (Vorakem Doomspeaker)*/, 22833 /*22833 (Outland Children's Week Dark Portal Trigger)*/, 18972 /*18972 (Orgrimmar Shaman) - Bouclier de foudre*/, 61325 /*Aspic*/, 21365 /*21365 (Floating Skull) - Particules spirituelles (rouges), Crâne flottant (DND)*/, 19443 /*19443 (Tagar Spinebreaker)*/, 49789 /*49789 (Allison)*/, 51903 /*51903 (Thrallmar Grunt) - Détection de l'invisibilité et du camouflage*/, 35099 /*35099 (Bana Wildmane)*/, 35093 /*35093 (Wind Rider Jahubo)*/, 18364 /*18364 (Blue Wind Rider)*/, 18365 /*18365 (Green Wind Rider)*/, 18363 /*18363 (Tawny Wind Rider)*/, 17004 /*17004 (Jir'see)*/, 17002 /*17002 (Angela "The Claw" Kestrel)*/, 30735 /*30735 (Kul Inkspiller)*/, 30722 /*30722 (Neferatti)*/, 47573 /*47573 (Sirabel)*/, 16844 /*16844 (Crust Burster) - Forage de tunnel Passif rouge*/, 18729 /*18729 (Infernal Rain (Hellfire))*/, 24959 /*24959 (Generic Quest Trigger - LAB)*/, 24933 /*24933 (Suspended Terrorguard) - Etat de bannissement vert*/, 24918 /*24918 (Felblood Initiate)*/, 20554 /*20554 (Arconus the Insatiable)*/, 22822 /*22822 (Ethereum Nullifier) - Annulateur de Pouvoir des Arcanes*/, 22821 /*22821 (Ethereum Avenger)*/, 20770 /*20770 (Warden Icoshock) - Naissance de traqueur sombre*/, 20780 /*20780 (Kaylaan)*/, 20922 /*20922 (Fallen Vindicator) - Feindre la mort permanent*/, 23491 /*23491 (Socrethar Event Trigger)*/, 20931 /*20931 (Tyrantus)*/, 20133 /*20133 (Image of Socrethar)*/, 22899 /*22899 (Protectorate Advisor Rahim)*/, 62627 /*Petite raie du Néant*/, 17408 /*17408 (Arcane Vortex)*/, 62625 /*Cafard du Néant*/, 29145 /*29145 (Pulik Swiftsnip)*/, 28343 /*28343 (Meeda)*/, 107619 /*107619 (Blaze Magmaburn)*/, 58152 /*58152 (Tini Smalls)*/, 23396 /*23396 (Krixel Pinchwhistle)*/, 107610 /*107610 (Kitzie Crankshot)*/, 54650 /*54650 (Kezzik the Striker)*/, 107599 /*107599 (Izzee the 'Clutch')*/, 54648 /*54648 (Leeni "Smiley" Smalls)*/, 54649 /*54649 (Big Zokk Torquewrench)*/, 40209 /*40209 (Grex Brainboiler)*/, 72823 /*72823 (Bill Porter)*/, 28344 /*28344 (Blazzle)*/, 20102 /*20102 (Goblin Commoner) - Gossip NPC Appearance - Default, Gossip NPC Periodic - Despawn, Gossip NPC Periodic - Fidget, Gossip NPC Periodic - Talk*/, 24974 /*24974 (Liza Cutlerflix)*/, 24977 /*24977 (Warpy)*/, 64374 /*Cafard du Néant*/, 62628 /*Jeune basilic brûlé*/, 51786 /*51786 (Mok'Nathal Hunter)*/, 51612 /*51612 (Death's Door Fel Cannon)*/, 115644 /*115644 (Scalewing Queen)*/, 21659 /*21659 (Floaty Flavor Eye)*/, 68841 /*Raptor lamerouage - Familier raptor*/, 23280 /*23280 (Agadai)*/, 10204 /*10204 (Misha)*/, 21294 /*21294 (Bloodmaul Goon)*/, 115598 /*115598 (Empowered Earth Elemental) - Durci*/, 115597 /*115597 (Geo-Lord Garug)*/, 21380 /*21380 (Greater Crust Burster) - Forage de tunnel Passif*/, 23217 /*23217 (Bladespire Agent)*/, 22941 /*22941 (Mog'dorg the Wizened)*/, 22995 /*22995 (Chort)*/, 22924 /*22924 (Arthorn Windsong)*/, 22922 /*22922 (Innkeeper Aelerya)*/, 20889 /*20889 (Ethereum Prisoner (Group Energy Ball)) - Etat Bannissement bleu/Forme d'Ombre, C_C_D*/, 22919 /*22919 (Image of Commander Ameer)*/, 23395 /*23395 (Bash'ir Landing Boss Bunny)*/, 23445 /*23445 (Ethereal Ring Target Bunny, Forge)*/, 23241 /*23241 (Skyguard Aether-Tech)*/, 23262 /*23262 (Ethereal Ring, Forge)*/, 23430 /*23430 (Skyguard Lieutenant)*/, 23242 /*23242 (Skyguard Ranger)*/, 23444 /*23444 (Ethereal Ring Target Bunny, Lightning)*/, 23424 /*23424 (Ethereal Ring Control Bunny)*/, 23246 /*23246 (Slavering Slave)*/, 23153 /*23153 (Bash'ir Surveyor) - Champ de stase*/, 23154 /*23154 (Mana-Debt Slave)*/, 18693 /*18693 (Speaker Mar'grom)*/, 23078 /*23078 (Fel Imp Defender)*/, 23212 /*23212 (Mo'arg Tormenter)*/, 23278 /*23278 (Portable Fel Cannon)*/, 23228 /*23228 (Eye of Shartuul)*/, 23173 /*23173 (Felhound Defender)*/, 23199 /*23199 (Gan'arg Underling)*/, 23120 /*23120 (Sky Sergeant Vanderlip)*/, 23208 /*23208 (Skyguard Pyrotechnician)*/, 23392 /*23392 (Skyguard Stable Master)*/, 23334 /*23334 (Sky Commander Keller)*/, 23413 /*23413 (Skyguard Handler Irena)*/, 23473 /*23473 (Aether-tech Apprentice)*/, 23500 /*23500 (Legion Ring Shield Zapper InvisMan) - Cosmétique - Anneau de la Légion Bouclier d'éclair*/, 23059 /*23059 (Legion Ring Event InvisMan)*/, 18692 /*18692 (Hemathion)*/, 23301 /*23301 (Dragon Bunny)*/, 23347 /*23347 (Tork)*/, 23110 /*23110 (Ogri'la Keg King) - Visuel d'Ivresse masse-sanglante*/, 22270 /*22270 (Ogri'la Merchant)*/, 22271 /*22271 (Ogri'la Trader)*/, 22266 /*22266 (Ogri'la Grubgiver)*/, 23233 /*23233 (Chu'a'lor)*/, 23316 /*23316 (Torkus)*/, 23428 /*23428 (Jho'nass)*/, 22264 /*22264 (Ogri'la Steelshaper)*/, 23256 /*23256 (Ogri'la Storyteller)*/, 23255 /*23255 (Kronk's Book Bunny) - Aura de Kronk*/, 23112 /*23112 (Mingo)*/, 23300 /*23300 (Gahk)*/, 23362 /*23362 (Torki)*/, 23115 /*23115 (Ogri'la Peacekeeper)*/, 62184 /*Vipère des rochers*/, 23382 /*23382 (Simon Game Summon Target)*/, 22923 /*22923 (Simon Game Bunny) - Détection de l'invisibilité et du camouflage*/, 23385 /*23385 (Simon Unit)*/, 61326 /*Scorpide*/, 23378 /*23378 (Simon Game Bunny Large) - Détection de l'invisibilité et du camouflage*/, 22304 /*22304 (Mo'arg Extractor)*/, 23174 /*23174 (Crystalfused Miner)*/, 23512 /*23512 (Crystalforge Bunny) - Fumée de cristalforge gangrenée*/, 23076 /*23076 (Legion Flak Cannon)*/, 19947 /*19947 (Darkcrest Sorceress)*/, 18281 /*18281 (Boglash) - Rosser, Nuage de Corruption*/, 22832 /*22832 (Morthis Whisperwing)*/, 22842 /*22842 (Corvax)*/, 22843 /*22843 (Rook)*/, 119287 /*119287 (Fenglow Stinger)*/, 20477 /*20477 (Terrorclaw) - Peur (effet aléatoire)*/, 66536 /*Lumiroir*/, 66534 /*Fongor*/, 66535 /*Tripatte*/, 66551 /*Ras’an*/, 22829 /*22829 (Outland Children's Week Sporeggar Trigger)*/, 22823 /*22823 (Hch'uu)*/, 62564 /*Pousse de sporelin*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(23269, 0, 0, 0, 1, 0, 0, 0, 0, '32732'), -- 23269 (Barash the Den Mother) - Battoir
(23209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23209 (Dragonmaw Peon Kill Credit)
(23267, 0, 0, 0, 1, 0, 0, 0, 0, '32732'), -- 23267 (Arvoar the Rapacious) - Battoir
(23305, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 23305 (Crazed Murkblood Foreman)
(23164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23164 (Toranaku)
(23324, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 23324 (Crazed Murkblood Miner)
(23264, 0, 0, 0, 1, 0, 0, 0, 0, '32732'), -- 23264 (Overmine Flayer) - Battoir
(23166, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 23166 (Ronag the Slave Driver)
(23285, 0, 0, 9, 1, 0, 0, 0, 0, '29147'), -- 23285 (Nethermine Burster) - Forage de tunnel Passif
(23149, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23149 (Mistress of the Mines)
(23148, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23148 (Forgus)
(23143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23143 (Horus)
(23150, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23150 (Dragonmaw Pitfighter)
(23289, 0, 0, 0, 0, 0, 0, 0, 0, '40684'), -- 23289 (Mine Car) - Chariot de mine
(23140, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23140 (Taskmaster Varkule Dragonbreath)
(23141, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23141 (Yarzill the Merc)
(23142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23142 (Goblin Merc)
(23139, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23139 (Overlord Mor'ghor)
(23145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23145 (Rumpus)
(23146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23146 (Dragonmaw Enforcer)
(23286, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23286 (Black Blood of Draenor)
(23311, 0, 0, 0, 1, 0, 0, 0, 0, '40732'), -- 23311 (Disobedient Dragonmaw Peon) - Paresseux et bon à rien
(23169, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23169 (Nethermine Flayer)
(23308, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23308 (Dragonmaw Peon Work Node)
(23501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23501 (Netherwing Ray)
(23225, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23225 (Netherwing Drake Escape Point)
(113941, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113941 (Invisible Stalker)
(22860, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22860 (Illidari Succubus)
(22858, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22858 (Shadowhoof Assassin)
(22859, 0, 0, 0, 1, 0, 0, 0, 0, '39550'), -- 22859 (Shadowhoof Summoner) - Canalisation des Arcanes
(21166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21166 (Illidari Dreadlord)
(22934, 0, 0, 0, 1, 0, 0, 0, 0, '39699'), -- 22934 (Black Temple Battle Sensor) - Régulateur de flux des combats
(22857, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22857 (Illidari Ravager)
(22862, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22862 (Anchorite Caalen)
(22863, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22863 (Seasoned Magister)
(22861, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22861 (Lightsworn Vindicator)
(22864, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22864 (Fyra Dawnstar)
(24925, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24925 (Boss Portal: Purple (3.00))
(18528, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18528 (Xi'ri)
(23496, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23496 (Akama Event Trigger)
(21699, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 21699 (Maiev Shadowsong)
(21897, 0, 0, 0, 1, 0, 0, 0, 0, '36006'), -- 21897 (Felspine the Greater) - Aura de Gangrefeu
(23020, 0, 0, 0, 1, 0, 0, 0, 0, '39579'), -- 23020 (Shadow Serpent) - Forme d'Ombre
(23454, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23454 (Dragonmaw Raid Credit Marker (Aldor))
(23452, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 23452 (Commander Arcus)
(21095, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21095 (Credit Marker: Water)
(21709, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21709 (Eykenen)
(23443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23443 (Dragonmaw Raid Credit Marker (Scryers))
(23434, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 23434 (Commander Hobb)
(24868, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24868 (Niobe Whizzlespark)
(21287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21287 (Warbringer Razuun)
(19759, 0, 0, 0, 1, 0, 0, 0, 0, '12743'), -- 19759 (Newly Crafted Infernal) - Immoler
(19760, 0, 0, 0, 1, 0, 0, 0, 0, '31261'), -- 19760 (Cooling Infernal) - Feindre la mort permanent (Immobilisé)
(21211, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21211 (Invis Deathforge Target)
(19757, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 19757 (Infernal Soul)
(17008, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 17008 (Gul'dan)
(21710, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21710 (Uylaru)
(21703, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21703 (Corrupt Fire Totem)
(21183, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21183 (Oronok Torn-heart)
(21255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21255 (Umberhowl)
(21029, 0, 0, 0, 1, 0, 0, 0, 0, '35929'), -- 21029 (Captured Water Spirit) - Bulle d'eau
(20795, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 20795 (Keeper of the Cistern)
(21027, 0, 0, 0, 257, 0, 0, 0, 0, '35921'), -- 21027 (Earthmender Wilda) - Bulle d'eau
(21041, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21041 (Earthmender Wilda Trigger)
(21196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21196 (Ravenous Flayer)
(62621, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gangreflamme
(19343, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19343 (Trop Rendlimb)
(19345, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19345 (Kalara)
(21359, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 21359 (Blood Guard Gulmok)
(22043, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22043 (Sergeant Kargrul)
(21771, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 21771 (Warcaller Sardon Truslice)
(19319, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19319 (Innkeeper Darg Bloodclaw)
(19317, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19317 (Drek'Gol)
(19341, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19341 (Grutah)
(19339, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19339 (Korthul)
(19333, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19333 (Grokom Deatheye)
(51910, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 51910 (Kor'kron Defender)
(21772, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 21772 (Chief Apothecary Hildagard)
(21770, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 21770 (Researcher Tiorus)
(19342, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19342 (Krek Cragcrush)
(21769, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 21769 (Overlord Or'barokh)
(21340, 0, 0, 3, 257, 0, 0, 0, 0, ''), -- 21340 (Detrafila)
(21336, 0, 0, 0, 258, 0, 0, 0, 0, ''), -- 21336 (Gedrah)
(21938, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21938 (Earthmender Splinthoof)
(25099, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25099 (Jonathan Garrett)
(19348, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 19348 (Targrom)
(20494, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 20494 (Dama Wildmane)
(20500, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 20500 (Olrokk)
(21249, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21249 (Wrathstalker)
(21501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21501 (Makazradon)
(66557, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chevalier de sang Antari
(66544, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jadefeu
(66545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcanus
(66543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Morsure-du-Néant
(21879, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21879 (Vilewing Chimaera)
(62314, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Cafard corrompu
(23363, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23363 (Sahaak)
(21728, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21728 (Skettis Surger)
(23029, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23029 (Talonsworn Forest-Rager)
(21804, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21804 (Skettis Kaliri)
(22986, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22986 (Skettis - Invis Raven Stone)
(22991, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22991 (Monstrous Kaliri Egg Trigger)
(22831, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22831 (Outland Children's Week Auchindoun Trigger)
(24893, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24893 (Auchindoun Daily Quest Trigger)
(22381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22381 (Hathyss the Wicked)
(18686, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18686 (Doomsayer Jurim)
(61440, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpide à queue rayée
(21636, 0, 0, 0, 1, 0, 0, 0, 0, '17327 31748'), -- 21636 (Vengeful Draenei) - Particules spirituelles, Particules spirituelles (grosses)
(18989, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 18989 (Stonebreaker Guard)
(24886, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 24886 (Exorcist Vaisha)
(18554, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 18554 (Sharth Voldoun)
(18648, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18648 (Stonegazer)
(18438, 0, 0, 0, 1, 0, 0, 0, 0, '32423'), -- 18438 (Naphthal'ar) - Radiation bleue
(62583, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jeune traqueur dimensionnel
(24437, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24437 (Consortium Assistant)
(24369, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24369 (Wind Trader Zhareem)
(24370, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24370 (Nether-Stalker Mah'duun)
(24412, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24412 (Daily Dungeon Image Bunny)
(24411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24411 (Shattered Hand Centurion Image)
(22819, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22819 (Orphan Matron Mercy)
(25992, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 25992 (Big Bruiser)
(23699, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23699 (Kevin Browning)
(25136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25136 (Shattered Sun Trainee)
(35002, 0, 0, 0, 1, 0, 0, 0, 0, '12544'), -- 35002 (Asara Dawnblaze) - Armure de givre
(25135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25135 (Shattered Sun Trainee)
(25138, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25138 (Captain Dranarus)
(25137, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25137 (Shattered Sun Trainee)
(25134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25134 (Shattered Sun Trainee)
(35001, 0, 0, 0, 1, 0, 0, 0, 0, '12544'), -- 35001 (Saeld Brightflare) - Armure de givre
(52277, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 52277 (Droha)
(50136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50136 (Baelir)
(25885, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 25885 (Whirligig Wafflefry)
(50127, 0, 0, 0, 1, 0, 0, 0, 0, '10022'), -- 50127 (Windstalker Ifram) - Poison mortel
(50137, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50137 (Muha)
(50130, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50130 (Luknar)
(50128, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50128 (Fel-Caller Guloto)
(52278, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 52278 (Linsa)
(52268, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 52268 (Riha)
(50140, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50140 (Auctioneer Lyrsara)
(50139, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50139 (Auctioneer Kalaren)
(25143, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 25143 (Shattered Sun Veteran)
(25167, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25167 (General Tiras'alan)
(50012, 0, 0, 0, 1, 0, 0, 0, 0, '79976'), -- 50012 (Blood Knight Argaron) - Aura de vindicte
(50010, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50010 (Alaressa)
(50007, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50007 (Derithela)
(50013, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50013 (Matron Ismara)
(50018, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50018 (Tarlhir)
(50016, 0, 0, 0, 1, 0, 0, 0, 0, '10022'), -- 50016 (Pathstalker Arpalir) - Poison mortel
(50017, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50017 (Summoner Durael)
(24938, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 24938 (Shattered Sun Marksman)
(25153, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25153 (Shattered Sun Magi)
(25142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25142 (Shattered Sun Marksman)
(27667, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 27667 (Anwehu)
(25155, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25155 (Shattered Sun Cleric)
(24932, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 24932 (Exarch Nasuun)
(27666, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 27666 (Ontuvo)
(24936, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24936 (Sunwell Daily Bunny x 0.01)
(25195, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 25195 (Marksman Bova)
(33678, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 33678 (Jijia)
(33684, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 33684 (Weaver Aoa)
(33674, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 33674 (Alchemist Kanhu)
(23484, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23484 (Haldor the Compulsive)
(23270, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23270 (Vindicator Aeus)
(50143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50143 (Auctioneer Itoran)
(50145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 50145 (Auctioneer Braku)
(23465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23465 (Zoya)
(23433, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23433 (Barthamus)
(23466, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23466 (Voranaku)
(24393, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24393 (The Rokk)
(24416, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24416 (Grisy Spicecrackle)
(18597, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18597 (Sha'nir)
(62555, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jeune écorcheur
(24922, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24922 (Razorthorn Ravager)
(24920, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24920 (Razorthorn Flayer)
(17794, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 17794 (Alliance Tower Buffer)
(19028, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 19028 (The Overlook Capture Credit Marker)
(18677, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18677 (Mekthorg the Wild)
(16857, 0, 0, 9, 1, 0, 0, 0, 0, '29147'), -- 16857 (Marauding Crust Burster) - Forage de tunnel Passif
(16977, 0, 0, 0, 1, 0, 0, 0, 0, '33900'), -- 16977 (Arch Mage Xintor) - Voile de la mort
(17060, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 17060 (Hellfire Combat Dummy Small)
(18678, 0, 0, 9, 1, 0, 0, 0, 0, '34038'), -- 18678 (Fulgorge) - Forage de tunnel Passif rouge
(35100, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 35100 (Hargen Bronzewing)
(30734, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 30734 (Jezebel Bican)
(30721, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 30721 (Michael Schwan)
(47574, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 47574 (Gerdra Fardelve)
(51799, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 51799 (Thrallmar Grunt)
(51800, 0, 0, 0, 257, 0, 0, 0, 0, '18950'), -- 51800 (Honor Hold Defender) - Détection de l'invisibilité et du camouflage
(18679, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18679 (Vorakem Doomspeaker)
(22833, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22833 (Outland Children's Week Dark Portal Trigger)
(18972, 0, 0, 0, 1, 0, 0, 0, 0, '20545'), -- 18972 (Orgrimmar Shaman) - Bouclier de foudre
(61325, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Aspic
(21365, 0, 0, 0, 257, 0, 0, 0, 0, '36725 36727'), -- 21365 (Floating Skull) - Particules spirituelles (rouges), Crâne flottant (DND)
(19443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 19443 (Tagar Spinebreaker)
(49789, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 49789 (Allison)
(51903, 0, 0, 0, 257, 0, 0, 0, 0, '18950'), -- 51903 (Thrallmar Grunt) - Détection de l'invisibilité et du camouflage
(35099, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 35099 (Bana Wildmane)
(35093, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 35093 (Wind Rider Jahubo)
(18364, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18364 (Blue Wind Rider)
(18365, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18365 (Green Wind Rider)
(18363, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18363 (Tawny Wind Rider)
(17004, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 17004 (Jir'see)
(17002, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 17002 (Angela "The Claw" Kestrel)
(30735, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 30735 (Kul Inkspiller)
(30722, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 30722 (Neferatti)
(47573, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 47573 (Sirabel)
(16844, 0, 0, 9, 1, 0, 0, 0, 0, '34038'), -- 16844 (Crust Burster) - Forage de tunnel Passif rouge
(18729, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18729 (Infernal Rain (Hellfire))
(24959, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24959 (Generic Quest Trigger - LAB)
(24933, 0, 0, 0, 1, 0, 0, 0, 0, '32567'), -- 24933 (Suspended Terrorguard) - Etat de bannissement vert
(24918, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 24918 (Felblood Initiate)
(20554, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 20554 (Arconus the Insatiable)
(22822, 0, 0, 0, 1, 0, 0, 0, 0, '39488'), -- 22822 (Ethereum Nullifier) - Annulateur de Pouvoir des Arcanes
(22821, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22821 (Ethereum Avenger)
(20770, 0, 0, 0, 1, 0, 0, 0, 0, '35242'), -- 20770 (Warden Icoshock) - Naissance de traqueur sombre
(20780, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 20780 (Kaylaan)
(20922, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 20922 (Fallen Vindicator) - Feindre la mort permanent
(23491, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23491 (Socrethar Event Trigger)
(20931, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 20931 (Tyrantus)
(20133, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 20133 (Image of Socrethar)
(22899, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22899 (Protectorate Advisor Rahim)
(62627, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Petite raie du Néant
(17408, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 17408 (Arcane Vortex)
(62625, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Cafard du Néant
(29145, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 29145 (Pulik Swiftsnip)
(28343, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 28343 (Meeda)
(107619, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107619 (Blaze Magmaburn)
(58152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 58152 (Tini Smalls)
(23396, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23396 (Krixel Pinchwhistle)
(107610, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 107610 (Kitzie Crankshot)
(54650, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 54650 (Kezzik the Striker)
(107599, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107599 (Izzee the 'Clutch')
(54648, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 54648 (Leeni "Smiley" Smalls)
(54649, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 54649 (Big Zokk Torquewrench)
(40209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 40209 (Grex Brainboiler)
(72823, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 72823 (Bill Porter)
(28344, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 28344 (Blazzle)
(20102, 0, 0, 0, 1, 0, 0, 0, 0, '65523 33209 33207 33208'), -- 20102 (Goblin Commoner) - Gossip NPC Appearance - Default, Gossip NPC Periodic - Despawn, Gossip NPC Periodic - Fidget, Gossip NPC Periodic - Talk
(24974, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 24974 (Liza Cutlerflix)
(24977, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24977 (Warpy)
(64374, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Cafard du Néant
(62628, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jeune basilic brûlé
(51786, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 51786 (Mok'Nathal Hunter)
(51612, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 51612 (Death's Door Fel Cannon)
(115644, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115644 (Scalewing Queen)
(21659, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21659 (Floaty Flavor Eye)
(68841, 0, 0, 0, 1, 0, 0, 0, 0, '67426'), -- Raptor lamerouage - Familier raptor
(23280, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23280 (Agadai)
(10204, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 10204 (Misha)
(21294, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 21294 (Bloodmaul Goon)
(115598, 0, 0, 33554432, 1, 0, 0, 0, 0, '82839'); -- 115598 (Empowered Earth Elemental) - Durci

INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(115597, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 115597 (Geo-Lord Garug)
(21380, 0, 0, 9, 1, 0, 0, 0, 0, '29147'), -- 21380 (Greater Crust Burster) - Forage de tunnel Passif
(23217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23217 (Bladespire Agent)
(22941, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22941 (Mog'dorg the Wizened)
(22995, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22995 (Chort)
(22924, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22924 (Arthorn Windsong)
(22922, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 22922 (Innkeeper Aelerya)
(20889, 0, 0, 0, 1, 0, 0, 0, 0, '39490 35465'), -- 20889 (Ethereum Prisoner (Group Energy Ball)) - Etat Bannissement bleu/Forme d'Ombre, C_C_D
(22919, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22919 (Image of Commander Ameer)
(23395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23395 (Bash'ir Landing Boss Bunny)
(23445, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23445 (Ethereal Ring Target Bunny, Forge)
(23241, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23241 (Skyguard Aether-Tech)
(23262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23262 (Ethereal Ring, Forge)
(23430, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23430 (Skyguard Lieutenant)
(23242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23242 (Skyguard Ranger)
(23444, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23444 (Ethereal Ring Target Bunny, Lightning)
(23424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23424 (Ethereal Ring Control Bunny)
(23246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23246 (Slavering Slave)
(23153, 0, 0, 0, 1, 0, 0, 0, 0, '40306'), -- 23153 (Bash'ir Surveyor) - Champ de stase
(23154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23154 (Mana-Debt Slave)
(18693, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18693 (Speaker Mar'grom)
(23078, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23078 (Fel Imp Defender)
(23212, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23212 (Mo'arg Tormenter)
(23278, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23278 (Portable Fel Cannon)
(23228, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23228 (Eye of Shartuul)
(23173, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23173 (Felhound Defender)
(23199, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23199 (Gan'arg Underling)
(23120, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 23120 (Sky Sergeant Vanderlip)
(23208, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23208 (Skyguard Pyrotechnician)
(23392, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 23392 (Skyguard Stable Master)
(23334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23334 (Sky Commander Keller)
(23413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23413 (Skyguard Handler Irena)
(23473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23473 (Aether-tech Apprentice)
(23500, 0, 0, 0, 1, 0, 0, 0, 0, '41916'), -- 23500 (Legion Ring Shield Zapper InvisMan) - Cosmétique - Anneau de la Légion Bouclier d'éclair
(23059, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23059 (Legion Ring Event InvisMan)
(18692, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18692 (Hemathion)
(23301, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23301 (Dragon Bunny)
(23347, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23347 (Tork)
(23110, 0, 0, 0, 1, 0, 0, 0, 0, '35777'), -- 23110 (Ogri'la Keg King) - Visuel d'Ivresse masse-sanglante
(22270, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22270 (Ogri'la Merchant)
(22271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22271 (Ogri'la Trader)
(22266, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22266 (Ogri'la Grubgiver)
(23233, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23233 (Chu'a'lor)
(23316, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23316 (Torkus)
(23428, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23428 (Jho'nass)
(22264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22264 (Ogri'la Steelshaper)
(23256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23256 (Ogri'la Storyteller)
(23255, 0, 0, 0, 1, 0, 0, 0, 0, '40570'), -- 23255 (Kronk's Book Bunny) - Aura de Kronk
(23112, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23112 (Mingo)
(23300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23300 (Gahk)
(23362, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23362 (Torki)
(23115, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 23115 (Ogri'la Peacekeeper)
(62184, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Vipère des rochers
(23382, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23382 (Simon Game Summon Target)
(22923, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 22923 (Simon Game Bunny) - Détection de l'invisibilité et du camouflage
(23385, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23385 (Simon Unit)
(61326, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpide
(23378, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 23378 (Simon Game Bunny Large) - Détection de l'invisibilité et du camouflage
(22304, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22304 (Mo'arg Extractor)
(23174, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23174 (Crystalfused Miner)
(23512, 0, 0, 0, 1, 0, 0, 0, 0, '35411'), -- 23512 (Crystalforge Bunny) - Fumée de cristalforge gangrenée
(23076, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 23076 (Legion Flak Cannon)
(19947, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 19947 (Darkcrest Sorceress)
(18281, 0, 0, 0, 1, 0, 0, 0, 0, '8876 33070'), -- 18281 (Boglash) - Rosser, Nuage de Corruption
(22832, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22832 (Morthis Whisperwing)
(22842, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22842 (Corvax)
(22843, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22843 (Rook)
(119287, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 119287 (Fenglow Stinger)
(20477, 0, 0, 0, 1, 0, 0, 0, 0, '35408'), -- 20477 (Terrorclaw) - Peur (effet aléatoire)
(66536, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lumiroir
(66534, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fongor
(66535, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tripatte
(66551, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Ras’an
(22829, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22829 (Outland Children's Week Sporeggar Trigger)
(22823, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22823 (Hch'uu)
(62564, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Pousse de sporelin

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22433; -- 22433 (Ja'y Nosliw)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=23144; -- 23144 (Gug)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22253; -- 22253 (Dragonmaw Ascendant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22274; -- 22274 (Dragonmaw Skybreaker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23326; -- 23326 (Nethermine Ravager)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23309; -- 23309 (Murkblood Overseer)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=22252; -- 22252 (Dragonmaw Peon)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=21720; -- 21720 (Dragonmaw Shaman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22317; -- 22317 (Netherwing Drake Escape Dummy)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36630' WHERE `entry`=21722; -- 21722 (Enslaved Netherwing Drake)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=21717; -- 21717 (Dragonmaw Wrangler)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='36630' WHERE `entry`=22112; -- 22112 (Karynaku)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21718; -- 21718 (Dragonmaw Subjugator)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36630' WHERE `entry`=21721; -- 21721 (Enslaved Netherwing Whelp)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21901; -- 21901 (Netherskate)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21719; -- 21719 (Dragonmaw Drake-Rider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21171; -- 21171 (Alandien)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21178; -- 21178 (Varedis)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21164; -- 21164 (Netharel)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='18950' WHERE `entry`=21179; -- 21179 (Demon Hunter Supplicant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21892; -- 21892 (Azaloth Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21908; -- 21908 (Spellbound Terrorguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21168; -- 21168 (Theras)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21180; -- 21180 (Demon Hunter Initiate)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21505; -- 21505 (Sunfury Summoner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21503; -- 21503 (Sunfury Warlock)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='18950' WHERE `entry`=22134; -- 22134 (Shadowmoon Eye of Kilrogg)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=22082; -- 22082 (Shadowmoon Slayer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21743; -- 21743 (Sunfury Blood Lord)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22966; -- 22966 (Lightsworn Elekk Rider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21742; -- 21742 (Sunfury Eradicator)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22230; -- 22230 (Shadowmoon Fel Orc Attack Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21826; -- 21826 (Sanoru)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21827; -- 21827 (Zandras)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21700; -- 21700 (Akama)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21102; -- 21102 (Uvuros)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21701; -- 21701 (Ashtongue Deathsworn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19744; -- 19744 (Dreadwarden)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21520; -- 21520 (Illidari Jailor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19801; -- 19801 (Illidari Agonizer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21802; -- 21802 (Elekk Demolisher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21803; -- 21803 (Ashtongue Handler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21808; -- 21808 (Illidari Overseer)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=21455; -- 21455 (Ashtongue Worker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21453; -- 21453 (Ashtongue Shaman)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19581; -- 19581 (Maddix)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19631; -- 19631 (Harram)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19629; -- 19629 (Denath)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19526; -- 19526 (Dunaman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22214; -- 22214 (Harbinger Saronen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19532; -- 19532 (Dearny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21402; -- 21402 (Anchorite Ceyla)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19528; -- 19528 (Nanomah)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21746; -- 21746 (Caretaker Aluuro)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19530; -- 19530 (Darmend)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21822; -- 21822 (Vindicator Aluumen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21860; -- 21860 (Exarch Onaala)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22079; -- 22079 (Air Force Guard Post (Aldor - Gryphon))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19649; -- 19649 (Dorni)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22080; -- 22080 (Air Force Trip Wire - Rooftop (Aldor))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21986; -- 21986 (Altar of Sha'tar Vindicator)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19648; -- 19648 (Maranem)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21454; -- 21454 (Ashtongue Warrior)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21704; -- 21704 (Corrupt Earth Totem)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21979; -- 21979 (Val'zareq the Conqueror)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19795; -- 19795 (Eclipsion Blood Knight)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19625; -- 19625 (Alorya)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19627; -- 19627 (Sulamin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19517; -- 19517 (Alorra)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19520; -- 19520 (Lelagar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21953; -- 21953 (Varen the Reclaimer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19518; -- 19518 (Feranin)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21766; -- 21766 (Alieshor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19521; -- 19521 (Arrond)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21954; -- 21954 (Larissa Sunstrike)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22211; -- 22211 (Battlemage Vyara)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21744; -- 21744 (Roldemar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21955; -- 21955 (Arcanist Thelis)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19504; -- 19504 (Scryer Guardian)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19628; -- 19628 (Furan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22070; -- 22070 (Air Force Trip Wire - Rooftop (Scryer))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19626; -- 19626 (Belanna)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22066; -- 22066 (Air Force Guard Post (Scryer - Dragonhawk))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22113; -- 22113 (Mordenai)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21477; -- 21477 (Rocknail Flayer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21478; -- 21478 (Rocknail Ripper)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36630' WHERE `entry`=21648; -- 21648 (Mature Netherwing Drake)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22395; -- 22395 ([PH]Altar of Shadows target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21872; -- 21872 (The Voice of Gorefiend)
UPDATE `creature_template_addon` SET `auras`='37509 37728' WHERE `entry`=21797; -- 21797 (Ancient Shadowmoon Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21711; -- 21711 (Haalum)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22417; -- 22417 ([PH]Altar of Shadows caster)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21705; -- 21705 (Corrupt Air Totem)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21060; -- 21060 (Enraged Air Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22073; -- 22073 (Marcus Auralion)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='37816' WHERE `entry`=22083; -- 22083 (Lord Illidan Stormrage)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='37119 37816' WHERE `entry`=22093; -- 22093 (Illidari Watcher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22012; -- 22012 (Chancellor Bloodleaf)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22011; -- 22011 (Corok the Mighty)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22016; -- 22016 (Eclipsion Soldier)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22017; -- 22017 (Eclipsion Spellbinder)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22018; -- 22018 (Eclipsion Cavalier)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19824; -- 19824 (Son of Corok)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22054; -- 22054 (Behemothon, King of the Colossi)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=20563; -- 20563 (Grand Commander Ruusk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21639; -- 21639 (Illidari Slayer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35190' WHERE `entry`=19796; -- 19796 (Eclipsion Archmage)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20431; -- 20431 (Eclipse Point - Bloodcrystal Spell Orgin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19806; -- 19806 (Eclipsion Bloodwarder)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=19792; -- 19792 (Eclipsion Centurion)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20502; -- 20502 (Eclipsion Dragonhawk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21293; -- 21293 (Borak, Son of Oronok)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=21384; -- 21384 (Dark Conclave Harbinger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22139; -- 22139 (Invis Arakkoa Target)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='38457' WHERE `entry`=22137; -- 22137 (Summoned Old God)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19825; -- 19825 (Dark Conclave Talonite)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22138; -- 22138 (Dark Conclave Ritualist)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=21385; -- 21385 (Dark Conclave Scorncrow)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22146; -- 22146 (Summoning Voidstorm)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19371; -- 19371 (Dalin Stouthammer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19369; -- 19369 (Celie Steelwing)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19352; -- 19352 (Dreg Cloudsweeper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22042; -- 22042 (Gryphonrider Kieran)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21775; -- 21775 (Warcaller Beersnout)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20506; -- 20506 (Swift Green Riding Gryphon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20505; -- 20505 (Snowy Gryphon Mount)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18939; -- 18939 (Brubeck Stormfoot)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19368; -- 19368 (Crinn Pathfinder)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20510; -- 20510 (Brunn Flamebeard)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20511; -- 20511 (Ilsa Blusterbrew)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20508; -- 20508 (Swift Red Riding Gryphon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20509; -- 20509 (Swift Blue Riding Gryphon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20507; -- 20507 (Swift Purple Riding Gryphon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20504; -- 20504 (Golden Gryphon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20503; -- 20503 (Ebon Gryphon)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19394; -- 19394 (Barimoke Wildbeard)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21774; -- 21774 (Zorus the Judicator)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19351; -- 19351 (Daggle Ironshaper)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19375; -- 19375 (Eli Thunderstrike)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19388; -- 19388 (Wildhammer Stronghold Target Dummy Right)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19379; -- 19379 (Sky'ree)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19395; -- 19395 (Bron Goldhammer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19373; -- 19373 (Mari Stonehand)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19370; -- 19370 (Ordinn Thunderfist)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19387; -- 19387 (Wildhammer Stronghold Target Dummy Left)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=21777; -- 21777 (Gnomus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19374; -- 19374 (Salle Sunforge)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19372; -- 19372 (Oran Blusterbrew)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21330; -- 21330 (Kurdran Wildhammer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21773; -- 21773 (Thane Yoregar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21937; -- 21937 (Earthmender Sophurus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19384; -- 19384 (Wildhammer Scout)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19382; -- 19382 (Wildhammer Gryphon Rider)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=21736; -- 21736 (Wildhammer Defender)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19756; -- 19756 (Deathforge Smith)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21476; -- 21476 (Mokthar Grimblade)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21475; -- 21475 (Scout Zagran)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20872; -- 20872 (Deathforge Summoner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19754; -- 19754 (Deathforge Tinkerer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20887; -- 20887 (Deathforge Imp)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21471; -- 21471 (Stormer Ewan Wildwing)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21472; -- 21472 (Gryphonrider Nordin)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19353; -- 19353 (Wildhammer Guard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20878; -- 20878 (Deathforge Guardian)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21026; -- 21026 (Earthmender Gorboto)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21024; -- 21024 (Earthmender Torlok)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21049; -- 21049 (Spirit of the Past)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21094; -- 21094 (Credit Marker: Fire)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21092; -- 21092 (Credit Marker: Earth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21108; -- 21108 (Spawn of Uvuros)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36006' WHERE `entry`=21050; -- 21050 (Enraged Earth Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36006' WHERE `entry`=21061; -- 21061 (Enraged Fire Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19788; -- 19788 (Coilskar Muckwatcher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19767; -- 19767 (Coilskar Sorceress)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21347; -- 21347 (Shadowmoon Valley Tuber Node)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19765; -- 19765 (Coilskar Myrmidon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21052; -- 21052 (Camera Shaker - Altar of Damnation)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21416; -- 21416 (Lakaan)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33908' WHERE `entry`=21195; -- 21195 (Domesticated Felboar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21420; -- 21420 (Corrupt Water Totem)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21462; -- 21462 (Greater Felfire Diemetradon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20684; -- 20684 (Lady Shav'rar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21295; -- 21295 (Coilskar Commander)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21291; -- 21291 (Grom'tor, Son of Oronok)
UPDATE `creature_template_addon` SET `bytes1`=7 WHERE `entry`=19784; -- 19784 (Coilskar Cobra)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20076; -- 20076 (Naga Distiller (Coilskar Point))
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36151' WHERE `entry`=21059; -- 21059 (Enraged Water Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19789; -- 19789 (Coilskar Waterkeeper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19769; -- 19769 (Coilskar Screamer)
UPDATE `creature_template_addon` SET `bytes1`=7 WHERE `entry`=19762; -- 19762 (Coilskar Defender)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=22025; -- 22025 (Asghar)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19827; -- 19827 (Dark Conclave Ravenguard)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=21386; -- 21386 (Dark Conclave Hawkeye)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19826; -- 19826 (Dark Conclave Shadowmancer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17407; -- 17407 (Felmist)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21450; -- 21450 (Skethyl Owl)
UPDATE `creature_template_addon` SET `mount`=14575, `bytes2`=257, `auras`='18950' WHERE `entry`=19364; -- 19364 (Kor'kron Rider)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19362; -- 19362 (Kor'kron Defender)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0, `auras`='18950' WHERE `entry`=19355; -- 19355 (Shadowmoon Peon)
UPDATE `creature_template_addon` SET `mount`=17721, `bytes2`=257 WHERE `entry`=21153; -- 21153 (Kor'kron Wyvern Rider)
UPDATE `creature_template_addon` SET `mount`=0, `bytes2`=1 WHERE `entry`=21245; -- 21245 (Bonechewer Marauder)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21499; -- 21499 (Overseer Ripsaw)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21403; -- 21403 (Invis Legion Hold Caster)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21512; -- 21512 (Invis Legion Hold Glyph)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21500; -- 21500 (Morgroron)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20683; -- 20683 (Prophetess Cavrylin)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='16245' WHERE `entry`=21316; -- 21316 (Deathforged Infernal)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21404; -- 21404 (Legion Hold Fel Reaver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21302; -- 21302 (Shadow Council Warlock)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21807; -- 21807 (Invis Legion Teleporter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19755; -- 19755 (Mo'arg Weaponsmith)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21314; -- 21314 (Terrormaster)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19740; -- 19740 (Wrathwalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21305; -- 21305 (Mutant Horror)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21419; -- 21419 (Infernal Attacker)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=21749; -- 21749 (Shadowmoon Scout)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21417; -- 21417 (Invis Infernal Caster)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21408; -- 21408 (Felfire Diemetradon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21348; -- 21348 (Shadowmoon Trigger)
UPDATE `creature_template_addon` SET `auras`='33908' WHERE `entry`=21878; -- 21878 (Felboar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21309; -- 21309 (Painmistress Gabrissa)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21928; -- 21928 (Lothros)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=10017; -- 10017 (Tainted Cockroach)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='' WHERE `entry`=21292; -- 21292 (Ar'tor, Son of Oronok)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21307; -- 21307 (Eva)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21310; -- 21310 (Shadowmoon Valley Invisible Trigger (Tiny))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21656; -- 21656 (Illidari Satyr)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20286; -- 20286 (Illadari Point - Succubi Spell Orgin 001)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20288; -- 20288 (Illadari Point - Succubi Caster Position 01)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20289; -- 20289 (Illadari Point - Succubi Caster Position 02)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19800; -- 19800 (Illidari Painlasher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19799; -- 19799 (Illidari Dreadbringer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21334; -- 21334 (Veneratus Spawn Node)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19802; -- 19802 (Illidari Shocktrooper)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='38303' WHERE `entry`=21855; -- 21855 (Skettis Arakkoa Spell Origin 02)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21856; -- 21856 (Skettis Kneel Target 04)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21649; -- 21649 (Skettis Windwalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21792; -- 21792 (Skettis Kneel Target 02)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21654; -- 21654 (Skettis Followers Spawner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21791; -- 21791 (Skettis Kneel Target 01)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21793; -- 21793 (Skettis Kneel Target 03)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21644; -- 21644 (Skettis Wing Guard)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34892' WHERE `entry`=21794; -- 21794 (Skettis Arakkoa Spell Origin 01)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21650; -- 21650 (Skettis Talonite)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21911; -- 21911 (Skettis Soulcaller)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32942' WHERE `entry`=23219; -- 23219 (Blackwind Warp Chaser)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22424; -- 22424 (Skywing)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32924' WHERE `entry`=18455; -- 18455 (Shalassi Oracle)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18454; -- 18454 (Shalassi Talonguard)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20986; -- 20986 (Dealer Tariq)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19718; -- 19718 (Provisioner Tsaalt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22371; -- 22371 (Terokkar Forest Ground Shaker Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21967; -- 21967 (Auchenai Death-Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22441; -- 22441 (Teribus the Cursed)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='8278 8279' WHERE `entry`=21941; -- 21941 (Accursed Apparition)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22045; -- 22045 (Vengeful Husk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22105; -- 22105 (Decrepit Clefthoof)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='13787' WHERE `entry`=21242; -- 21242 (Auchenai Death-Speaker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18460; -- 18460 (Lost Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21443; -- 21443 (Bone Wastes - Orb Waypoint 01)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21284; -- 21284 (Auchenai Initiate)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21852; -- 21852 (Auchenai Warrior)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16805; -- 16805 (Broken Skeleton)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21285; -- 21285 (Auchenai Doomsayer)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='31261' WHERE `entry`=21859; -- 21859 (Slain Sha'tar Vindicator)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='31261' WHERE `entry`=21846; -- 21846 (Slain Auchenai Warrior)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22364; -- 22364 (Scout Navrin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22458; -- 22458 (Chief Archaeologist Letoll)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22446; -- 22446 (Commander Ra'vaj)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22464; -- 22464 (Explorers' League Researcher)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22456; -- 22456 (Oakun)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=22476; -- 22476 (Aundro)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22481; -- 22481 (Dwarfowitz)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22453; -- 22453 (Injured Sha'tar Vindicator)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0, `auras`='18950' WHERE `entry`=22477; -- 22477 (Anchorite Ensham)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19659; -- 19659 (Great Elite Elekk)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32924' WHERE `entry`=22387; -- 22387 (Lithic Oracle)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22340; -- 22340 (Terokkar Arakkoa Fly Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22388; -- 22388 (Lithic Talonguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18843; -- 18843 (Bleeding Hollow Clan Ruins Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18273; -- 18273 (Kilrath)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18262; -- 18262 (Unkor the Ruthless)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18260; -- 18260 (Boulderfist Invader)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18588; -- 18588 (Floon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18707; -- 18707 (Torgos)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='17327 33900' WHERE `entry`=21200; -- 21200 (Screeching Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='17327 33900' WHERE `entry`=21198; -- 21198 (Deathtalon Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='17327 36978' WHERE `entry`=21324; -- 21324 (Spirit Raven)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22378; -- 22378 (Cabal Interrogator)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22377; -- 22377 (Akuno)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21661; -- 21661 (Cabal Skirmisher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21662; -- 21662 (Cabal Tomb-Raider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21660; -- 21660 (Cabal Abjurist)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22288; -- 22288 (Terokkar Quest Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18541; -- 18541 (Urdak)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22314; -- 22314 (Captive Child)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32912' WHERE `entry`=18453; -- 18453 (Skithian Windripper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18452; -- 18452 (Skithian Dreadhawk)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=18720; -- 18720 (Shadowmaster Grieve)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18719; -- 18719 (Shadowy Advisor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18718; -- 18718 (Shadowy Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='23017' WHERE `entry`=18716; -- 18716 (Shadowy Initiate)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18717; -- 18717 (Shadowy Laborer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16519; -- 16519 (Shadowy Executioner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17088; -- 17088 (Shadowy Summoner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18714; -- 18714 (Scout Neftis)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22365; -- 22365 (Ethan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20894; -- 20894 (Miihi)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20895; -- 20895 (Miiji)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=20890; -- 20890 (Siflaed Coldhammer)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=20891; -- 20891 (Skraa)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21313; -- 21313 (Dead Clefthoof)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20893; -- 20893 (Morula)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=20892; -- 20892 (Ruogo)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21317; -- 21317 (Aimi)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22272; -- 22272 (Kirrik the Awakened)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20874; -- 20874 (Skettis Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22370; -- 22370 (Mekeda)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=20877; -- 20877 (Shattrath Refugee)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18675; -- 18675 (Soolaveen)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=22278; -- 22278 (High Priest Orglum)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20876; -- 20876 (Human Refugee)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22407; -- 22407 (Caravan Defender)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21858; -- 21858 (Sha'tar Vindicator)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='37989' WHERE `entry`=21849; -- 21849 (Bone Crawler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21515; -- 21515 (Trachela)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22100; -- 22100 (Scorpid Bonecrawler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18470; -- 18470 (Bonelasher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22307; -- 22307 (Rotting Forest-Rager)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22095; -- 22095 (Infested Root-Walker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21368; -- 21368 (Ethereal Plunderer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32942' WHERE `entry`=18465; -- 18465 (Warp Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18467; -- 18467 (Dreadfang Widow)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19002; -- 19002 (Gardok Ripjaw)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=21194; -- 21194 (Ru'zah)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18960; -- 18960 (Rungor)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18383; -- 18383 (Kurgatok)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=18384; -- 18384 (Malukaz)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18676; -- 18676 (Keb'ezil)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19772; -- 19772 (Spirit Sage Gartok)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21188; -- 21188 (Thadok)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18962; -- 18962 (Bar Talet)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18957; -- 18957 (Innkeeper Grilka)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=18712; -- 18712 (Advisor Faila)
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=18705; -- 18705 (Mawg Grimshot)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=19606; -- 19606 (Grek)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19607; -- 19607 (Grek's Riding Wolf)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18386; -- 18386 (Rokag)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18807; -- 18807 (Kerna)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18447; -- 18447 (Tooki)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18984; -- 18984 (Trag)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18959; -- 18959 (Dod'ss)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18385; -- 18385 (Rakoria)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18249; -- 18249 (Mokasa)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21192; -- 21192 (Kugnar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21193; -- 21193 (Gralga)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0, `auras`='18950' WHERE `entry`=19048; -- 19048 (Stonebreaker Peon)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18973; -- 18973 (Stonebreaker Grunt)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=17467; -- 17467 (Skunk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18595; -- 18595 (Warped Peon)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18565; -- 18565 (Theloria Shadecloak)
UPDATE `creature_template_addon` SET `bytes2`=256, `emote`=0 WHERE `entry`=21006; -- 21006 (Lieutenant Meridian)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21039; -- 21039 (Mana Bomb Kill Credit Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20767; -- 20767 (Mana Bomb Explosion Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21898; -- 21898 (Mana Bomb Lightning Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20809; -- 20809 (Mana Bomb Channel Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21899; -- 21899 (Mana Bomb Lightning Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18760; -- 18760 (Isla Starmane)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16769; -- 16769 (Firewing Warlock)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32898' WHERE `entry`=1410; -- 1410 (Firewing Bloodwarder)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=5355; -- 5355 (Firewing Defender)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18463; -- 18463 (Dampscale Devourer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21816; -- 21816 (Ironspine Chomper)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32942' WHERE `entry`=18464; -- 18464 (Warp Stalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18477; -- 18477 (Timber Worg Alpha)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18469; -- 18469 (Royal Teromoth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16932; -- 16932 (Razorfang Hatchling)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18540; -- 18540 (Ayit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18457; -- 18457 (Tuurem Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17142; -- 17142 (Wrekt Warrior)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18456; -- 18456 (Tuurem Scavenger)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32924' WHERE `entry`=18539; -- 18539 (Ashkaz)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18451; -- 18451 (Shienor Wing Guard)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32924' WHERE `entry`=18450; -- 18450 (Shienor Sorcerer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18449; -- 18449 (Shienor Talonite)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18466; -- 18466 (Dreadfang Lurker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18468; -- 18468 (Teromoth)
UPDATE `creature_template_addon` SET `auras`='32423 29266 32900' WHERE `entry`=18480; -- 18480 (Broken Corpse)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18424; -- 18424 (Warden Treelos)
UPDATE `creature_template_addon` SET `auras`='32423 29266' WHERE `entry`=18490; -- 18490 (Fallen Druid)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18437; -- 18437 (Vicious Teromoth)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='19194' WHERE `entry`=18584; -- 18584 (Sal'salabim)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19077; -- 19077 (Dwarf Refugee)
UPDATE `creature_template_addon` SET `bytes1`=7, `bytes2`=1 WHERE `entry`=19289; -- 19289 (Vagabond)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19283; -- 19283 (Vagrant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19033; -- 19033 (Nicole Bartlett)
UPDATE `creature_template_addon` SET `bytes1`=3, `bytes2`=1, `emote`=0 WHERE `entry`=19170; -- 19170 (Peasant Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20125; -- 20125 (Zula Slagfury)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=20124; -- 20124 (Kradu Grimblade)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19150; -- 19150 (Orc Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23449; -- 23449 (Yuula)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18940; -- 18940 (Nutral)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19162; -- 19162 (Lost One Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20808; -- 20808 (Scribe Veredis)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23483; -- 23483 (Arcanist Xorith)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19331; -- 19331 (Quartermaster Enuril)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23273; -- 23273 (Arcanist Raestan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18166; -- 18166 (Archmage Khadgar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19246; -- 19246 (Berudan Keysworn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19715; -- 19715 (Ezekiel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19338; -- 19338 (L'lura Goldspun)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=19475; -- 19475 (Harbinger Haronem)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19680; -- 19680 (Aldor Spawn Controller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20791; -- 20791 (Iorioa)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22497; -- 22497 (V'eru)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=5202; -- 5202 (Archery Target)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35076' WHERE `entry`=18481; -- 18481 (A'dal)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=18893; -- 18893 (Spymistress Mehlisah Highcrown)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19120; -- 19120 (Broken Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18525; -- 18525 (G'eras)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21432; -- 21432 (Almaador)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=24928; -- 24928 (Sunwell Daily Bunny x 1.00)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=20331; -- 20331 (G'eras Vindicator)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=15892; -- 15892 (Lunar Festival Emissary)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19702; -- 19702 (Aldor Acolyte)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19726; -- 19726 ("Creepjack")
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19725; -- 19725 ("Epic" Malone)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19720; -- 19720 ("Dirty" Larry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19034; -- 19034 (Mendorn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19318; -- 19318 (Gromden)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19049; -- 19049 (Karokka)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19052; -- 19052 (Lorokeem)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19321; -- 19321 (Quartermaster Endarin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20807; -- 20807 (Scribe Saalyn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22429; -- 22429 (Vekax)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19074; -- 19074 (Skreah)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19051; -- 19051 (Araac)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22373; -- 22373 (Defender Grashna)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22292; -- 22292 (Rilak the Redeemed)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19047; -- 19047 (Lissaf)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19665; -- 19665 (Ewe)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18596; -- 18596 (Arcanist Adyria)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18622; -- 18622 (Iz'zard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19164; -- 19164 (Refugee Child)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22326; -- 22326 (Redeemed Avian)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20123; -- 20123 (Farmer Griffith)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19155; -- 19155 (Sporeling Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19075; -- 19075 (Skettis Outcast)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19045; -- 19045 (Oloraak)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=1 WHERE `entry`=19144; -- 19144 (Mag'har Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19163; -- 19163 (Refugee Kid)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=24436; -- 24436 (Gargoth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18652; -- 18652 (Zahlia)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18653; -- 18653 (Seth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19684; -- 19684 (Haggard War Veteran)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18600; -- 18600 (Injured Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19184; -- 19184 (Mildred Fletcher)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='5301' WHERE `entry`=19687; -- 19687 (Shattrath City Peacekeeper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21854; -- 21854 (Ironspine Petrifier)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18750; -- 18750 (Shimmerscale Eel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18461; -- 18461 (Dampscale Basilisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20678; -- 20678 (Akoru the Firecaller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19361; -- 19361 (Naladu)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16937; -- 16937 (Dreghood Geomancer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19354; -- 19354 (Arzeth the Merciless)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20677; -- 20677 (Morod the Windstirrer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20679; -- 20679 (Aylaan the Waterwaker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17058; -- 17058 (Illidari Taskmaster)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=16938; -- 16938 (Dreghood Brute)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34343' WHERE `entry`=19350; -- 19350 (Thornfang Venomspitter)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34343' WHERE `entry`=19349; -- 19349 (Thornfang Ravager)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20781; -- 20781 (Seed of Revitalization Target Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20617; -- 20617 (Red Crystal Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19188; -- 19188 (Raging Colossus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18990; -- 18990 (Burko)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17403; -- 17403 (Anchorite Alendar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16796; -- 16796 (Amaan the Wise)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18906; -- 18906 (Caregiver Ophera Windfury)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17006; -- 17006 (Elsaana)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19004; -- 19004 (Vodesiin)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=19001; -- 19001 (Talaara)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16799; -- 16799 (Ikan)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16836; -- 16836 (Escaped Dreghood)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16834; -- 16834 (Anchorite Obadei)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16833; -- 16833 (Makuru)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16797; -- 16797 (Scout Vanura)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=18758; -- 18758 (Telhamat Protector)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16798; -- 16798 (Provisioner Anir)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17402; -- 17402 (Yaluu)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18785; -- 18785 (Kuma)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16927; -- 16927 (Stonescythe Whelp)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16845; -- 16845 (Gorkan Bloodfist)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17123; -- 17123 (Earthcaller Ryga)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16848; -- 16848 (Provisioner Braknar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16912; -- 16912 (Mag'har Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16847; -- 16847 (Debilitated Mag'har Grunt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16846; -- 16846 (Mag'har Grunt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16973; -- 16973 (Bonestripper Vulture)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='29266' WHERE `entry`=17062; -- 17062 (Fel Orc Corpse)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=16911; -- 16911 (Mag'har Watcher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19191; -- 19191 (Arazzius the Cruel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19192; -- 19192 (Mistress of Doom)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='29266' WHERE `entry`=20158; -- 20158 (Slime-Covered Corpse)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16951; -- 16951 (Terrorfiend)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16901; -- 16901 (Blistering Rot)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16903; -- 16903 (Blistering Oozeling)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17795; -- 17795 (Horde Tower Buffer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19264; -- 19264 (Force-Commander Gorax)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19415; -- 19415 (Shattered Hand Acolyte)
UPDATE `creature_template_addon` SET `bytes1`=3, `bytes2`=1 WHERE `entry`=19413; -- 19413 (Shattered Hand Mage)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19295; -- 19295 (Shattered Hand Grenadier)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19414; -- 19414 (Shattered Hand Guard)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33908' WHERE `entry`=16880; -- 16880 (Hulking Helboar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19297; -- 19297 ([PH]Dynamite Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19263; -- 19263 (Warboss Nekrogg)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16878; -- 16878 (Shattered Hand Berserker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16974; -- 16974 (Rogue Voidwalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16975; -- 16975 (Uncontrolled Voidwalker)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='10848' WHERE `entry`=16978; -- 16978 (Lieutenant Commander Thalvos)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17059; -- 17059 (Hellfire Combat Dummy)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16976; -- 16976 (Ghostly Denizen)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16843; -- 16843 (Honor Hold Cavalryman)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16838; -- 16838 (Honor Hold Miner)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22431; -- 22431 (Anchorite Barada)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16884; -- 16884 (War Horse)
UPDATE `creature_template_addon` SET `mount`=17697, `bytes2`=257 WHERE `entry`=35101; -- 35101 (Grunda Bronzewing)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18974; -- 18974 (Z'kral)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16899; -- 16899 (Honor Hold Target Dummy Left)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16898; -- 16898 (Honor Hold Target Dummy Right)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16897; -- 16897 (Honor Hold Target Dummy Middle)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=16832; -- 16832 (Prospector Murantus)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='39283' WHERE `entry`=22432; -- 22432 (Colonel Jules)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18987; -- 18987 (Gaston)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16824; -- 16824 (Master Sergeant Lorin Thalmerok)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16822; -- 16822 (Flightmaster Krill Bitterhue)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16835; -- 16835 (Explorers' League Archaeologist)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16830; -- 16830 (Field Commander Romus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17657; -- 17657 (Logistics Officer Ulrike)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18266; -- 18266 (Warrant Officer Tracy Proudwell)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=20513; -- 20513 (Honor Hold Defender)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18777; -- 18777 (Jelena Nightsky)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19363; -- 19363 (Sergeant Dalton)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20206; -- 20206 (Fei Fei)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19393; -- 19393 (Fear Controller)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18779; -- 18779 (Hurnak Grimmord)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22467; -- 22467 (Fei Fei Stash Bunny)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=16823; -- 16823 (Humphry)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19308; -- 19308 (Marshal Isildor)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16886; -- 16886 (Arator the Redeemer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18771; -- 18771 (Brumman)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16828; -- 16828 (Honor Guard Greyn)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16825; -- 16825 (Father Malgor Devidicus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22430; -- 22430 (Assistant Klatu)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16826; -- 16826 (Sid Limbardi)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22227; -- 22227 (Markus Scylan)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18774; -- 18774 (Tatiana)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18772; -- 18772 (Hama)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18776; -- 18776 (Rorelien)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18773; -- 18773 (Johan Barnes)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16829; -- 16829 (Magus Zabraxis)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18802; -- 18802 (Alchemist Gribble)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=19392; -- 19392 (Watch Commander Leonus)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18775; -- 18775 (Lebowski)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16856; -- 16856 (Caretaker Dilandrus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16819; -- 16819 (Force Commander Danath Trollbane)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16821; -- 16821 (Magus Filinthus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16839; -- 16839 (Warp-Scryer Kryv)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16896; -- 16896 (Honor Hold Archer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16865; -- 16865 (Injured Stormwind Infantry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16887; -- 16887 (Eye of Honor Hold)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16972; -- 16972 (Bonestripper Buzzard)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=16905; -- 16905 (Unyielding Sorcerer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19937; -- 19937 (Commander Hogarth)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=16906; -- 16906 (Unyielding Knight)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=16904; -- 16904 (Unyielding Footman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21391; -- 21391 (Scarab Bunny)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16858; -- 16858 (Grelag)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19560; -- 19560 (Lukra)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19561; -- 19561 (Hagash the Blind)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21279; -- 21279 (Apothecary Albreck)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19736; -- 19736 (Althen the Historian)
UPDATE `creature_template_addon` SET `bytes2`=258, `auras`='18950' WHERE `entry`=19836; -- 19836 (Mixie Farshot)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22177; -- 22177 (Eye of Grillok Quest Credit Bunny)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22231; -- 22231 (Zezzak)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19682; -- 19682 (Emissary Mordiba)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22107; -- 22107 (Captain Darkhowl)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=19562; -- 19562 (Peon Bolgar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19558; -- 19558 (Amilya Airheart)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19559; -- 19559 (Mondul)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19332; -- 19332 (Stone Guard Ambelan)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19683; -- 19683 (Ogath the Mad)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21182; -- 21182 (Zeth'Gor Quest Credit Marker, They Must Burn, Tower South)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16964; -- 16964 (Warlord Morkh)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20813; -- 20813 (Zeth'Gor Quest Credit Marker, Barracks)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20816; -- 20816 (Zeth'Gor Quest Credit Marker, West Hovel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19423; -- 19423 (Bleeding Hollow Worg)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19458; -- 19458 (Ripp)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19442; -- 19442 (Worg Master Kruush)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20814; -- 20814 (Zeth'Gor Quest Credit Marker, Stable)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19459; -- 19459 (Feng)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19440; -- 19440 (Eye of Grillok)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22403; -- 22403 (Zeth'Gor Quest Credit Marker, They Must Burn, Tower Foothill)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=16873; -- 16873 (Bleeding Hollow Dark Shaman)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=19422; -- 19422 (Bleeding Hollow Necrolyte)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20815; -- 20815 (Zeth'Gor Quest Credit Marker, East Hovel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22402; -- 22402 (Zeth'Gor Quest Credit Marker, They Must Burn, Tower Forge)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22401; -- 22401 (Zeth'Gor Quest Credit Marker, They Must Burn, Tower North)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16907; -- 16907 (Bleeding Hollow Peon)
UPDATE `creature_template_addon` SET `mount`=9562, `bytes2`=1 WHERE `entry`=19424; -- 19424 (Bleeding Hollow Tormentor)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=16871; -- 16871 (Bleeding Hollow Grunt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21173; -- 21173 (Zeth'Gor Quest Credit Marker, They Must Burn)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19409; -- 19409 (Wing Commander Dabir'ee)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=21133; -- 21133 (Corporal Ironridge)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19310; -- 19310 (Forward Commander Kingston)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19316; -- 19316 (Field Marshal Rohamus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19314; -- 19314 (Supply Officer Shandria)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=16842; -- 16842 (Honor Hold Defender)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19434; -- 19434 (Dreadcaller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19136; -- 19136 (Flamewaker Imp)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18978; -- 18978 (Heckling Fel Sprite)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19326; -- 19326 (Legion Antenna: Oblivion)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19328; -- 19328 (Legion Antenna: Gehenna)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19335; -- 19335 (Subjugator Yalqiz)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19329; -- 19329 (Legion Antenna: Mageddon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19681; -- 19681 (Void Spawner L)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34524' WHERE `entry`=19527; -- 19527 (Vacillating Voidcaller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17014; -- 17014 (Collapsing Voidwalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21075; -- 21075 (Infernal Target (Hyjal))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19447; -- 19447 (Brother Daniels)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19455; -- 19455 (Nurse Judith)
UPDATE `creature_template_addon` SET `bytes1`=7, `bytes2`=1 WHERE `entry`=19624; -- 19624 (Wounded Stormwind Infantry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19007; -- 19007 (Gnomeregan Conjuror)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='18950' WHERE `entry`=19446; -- 19446 (Operations Officer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19452; -- 19452 (Quartermaster Drake)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19451; -- 19451 (Quartermaster Gorman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18931; -- 18931 (Amish Wildhammer)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18966; -- 18966 (Justinius the Harbinger)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='18950' WHERE `entry`=19444; -- 19444 (Peasant Worker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18949; -- 18949 (Stormwind Mage)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16831; -- 16831 (Nethergarde Infantry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18986; -- 18986 (Ironforge Paladin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16864; -- 16864 (Stormwind Infantry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18969; -- 18969 (Melgromm Highmountain)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18965; -- 18965 (Darnassian Archer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19005; -- 19005 (Wrath Master)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=19229; -- 19229 (Commander Duron)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18948; -- 18948 (Stormwind Soldier)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18970; -- 18970 (Darkspear Axe Thrower)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18950; -- 18950 (Orgrimmar Grunt)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32008' WHERE `entry`=18944; -- 18944 (Fel Soldier)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19179; -- 19179 (Formation Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18971; -- 18971 (Undercity Mage)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=19253; -- 19253 (Lieutenant General Orion)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=21252; -- 21252 (World Trigger (Not Immune PC))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19871; -- 19871 (World Trigger (Not Immune NPC))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19006; -- 19006 (Silvermoon Magister)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19436; -- 19436 (Supply Master Broog)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19435; -- 19435 (Dark Cleric Malod)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='18950' WHERE `entry`=19426; -- 19426 (Peon Overseer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18930; -- 18930 (Vlagga Freyfeather)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='18950' WHERE `entry`=19425; -- 19425 (Orgrimmar Peon)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='18950' WHERE `entry`=19432; -- 19432 (Injured Grunt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18945; -- 18945 (Pit Commander)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19215; -- 19215 (Infernal Relay (Hellfire))
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=20232; -- 20232 (Wing Commander Gryphongar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20231; -- 20231 (Supply Officer Pestle)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20251; -- 20251 (Honor Hold Scout Archery Target)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20234; -- 20234 (Runetog Wildhammer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20235; -- 20235 (Gryphoneer Windbellow)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20237; -- 20237 (Honor Hold Gryphon Rider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19279; -- 19279 (Legion Antenna: Fear)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19652; -- 19652 (Disrupt the Communications Quest Credit Marker North)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19282; -- 19282 (Subjugator Shi'aziv)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19278; -- 19278 (Legion Antenna: Hate)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19717; -- 19717 (Disrupt the Communications Quest Credit Marker South)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19277; -- 19277 (Legion Antenna: Rage)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18981; -- 18981 (Doomwhisperer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19276; -- 19276 (Legion Antenna: Spite)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16950; -- 16950 (Netherhound)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19190; -- 19190 (Fel Handler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18975; -- 18975 (Wrathguard)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21257; -- 21257 (Apothecary Zelana)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19401; -- 19401 (Wing Commander Brack)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19275; -- 19275 (Armored Wyvern Destroyer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19273; -- 19273 (Forward Commander To'arch)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19315; -- 19315 (Supply Officer Isabel)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16576; -- 16576 (Overlord Hun Maimfist)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16599; -- 16599 (Thrallmar Wolf Rider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18849; -- 18849 (Invis Alliance Siege Engine - East)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16870; -- 16870 (Shattered Hand Captain)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19410; -- 19410 (Shattered Hand Neophyte)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16867; -- 16867 (Shattered Hand Grunt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21237; -- 21237 (Invis Horde Siege Engine - East 02)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16925; -- 16925 (Bonechewer Raider)
UPDATE `creature_template_addon` SET `bytes1`=3, `bytes2`=1, `auras`='13787' WHERE `entry`=19411; -- 19411 (Shattered Hand Warlock)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18818; -- 18818 (Invis Horde Siege Engine - East)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16876; -- 16876 (Bonechewer Mutant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19701; -- 19701 (Bonechewer Evoker)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18952; -- 18952 (Bonechewer Scavenger)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19256; -- 19256 (Sergeant Shatterskull)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19257; -- 19257 (Arcanist Torseldori)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19258; -- 19258 (Bloodmage)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16587; -- 16587 (Barley)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16602; -- 16602 (Floyd Pinkus)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18751; -- 18751 (Kalaen)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22225; -- 22225 (Reagan Mancuso)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18749; -- 18749 (Dalinna)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18755; -- 18755 (Moorutu)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18267; -- 18267 (Battlecryer Blackeye)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18754; -- 18754 (Barim Spilthoof)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16586; -- 16586 (Huntsman Torf Angerhoof)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16585; -- 16585 (Cookie One-Eye)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16600; -- 16600 (Thrallmar Riding Wolf)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=16590; -- 16590 (Injured Thrallmar Grunt)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16589; -- 16589 (Guard Captain Cragtar)
UPDATE `creature_template_addon` SET `bytes2`=258, `emote`=0 WHERE `entry`=16582; -- 16582 (Thrallmar Marksman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=2615; -- 2615 (Air Force Alarm Bot (Horde))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16584; -- 16584 (Watch Commander Krunk)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19255; -- 19255 (General Krakork)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16579; -- 16579 (Falcon Watch Sentinel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18752; -- 18752 (Zebig)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18100' WHERE `entry`=16577; -- 16577 (Martik Tor'seldori)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16578; -- 16578 (Blood Elf Pilgrim)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17585; -- 17585 (Quartermaster Urgronn)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16574; -- 16574 (Far Seer Regulkut)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18747; -- 18747 (Krugosh)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16583; -- 16583 (Rohok)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0, `auras`='18950' WHERE `entry`=16591; -- 16591 (Thrallmar Peon)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21175; -- 21175 (Magister Bloodhawk)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=3230; -- 3230 (Nazgrel)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16575; -- 16575 (Shadow Hunter Ty'jin)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21256; -- 21256 (Vurtok Axebreaker)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16588; -- 16588 (Apothecary Antonivich)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18748; -- 18748 (Ruak Stronghorn)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18753; -- 18753 (Felannia)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=16580; -- 16580 (Thrallmar Grunt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16598; -- 16598 (Eye of Thrallmar)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=16915; -- 16915 (Foreman Razelcraz)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20195; -- 20195 (Dagz)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21847; -- 21847 (Fel Guard Hound)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16863; -- 16863 (Deranged Helboar)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32008' WHERE `entry`=19298; -- 19298 (Warbringer Arix'Amal)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19408; -- 19408 (Maiden of Pain)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18827; -- 18827 (Gan'arg Sapper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18976; -- 18976 (Urga'zz)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18828; -- 18828 (Camera Shaker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=15242; -- 15242 (Bat Rider Guard)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12743' WHERE `entry`=19261; -- 19261 (Infernal Warbringer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22461; -- 22461 (Fel Cannon MKI)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20798; -- 20798 (Razorsaw)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16946; -- 16946 (Mo'arg Forgefiend)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16960; -- 16960 (Sister of Grief)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16954; -- 16954 (Forge Camp Legionnaire)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=16947; -- 16947 (Gan'arg Servant)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33908' WHERE `entry`=16879; -- 16879 (Starving Helboar)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121541; -- Ban Lu
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20793; -- 20793 (Field Marshal Brock)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=257 WHERE `entry`=20238; -- 20238 (Honor Hold Scout)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19324; -- 19324 (Armored Gryphon Destroyer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20236; -- 20236 (Gryphoneer Leafbeard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19397; -- 19397 (Mo'arg Overseer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19400; -- 19400 (Fel Reaver Sentry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19399; -- 19399 (Fel Cannon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19398; -- 19398 (Gan'arg Peon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=24937; -- 24937 (Magistrix Seyla)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=24919; -- 24919 (Wrath Herald)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22323; -- 22323 (Incandescent Fel Spark)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='19818 34623' WHERE `entry`=18733; -- 18733 (Fel Reaver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20551; -- 20551 (Agent Araxes)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20858; -- 20858 (Arena Event Controller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20907; -- 20907 (Professor Dabiri)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20903; -- 20903 (Protectorate Nether Drake)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20451; -- 20451 (Subservient Flesh Beast)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20450; -- 20450 (Flesh Handler Viridius)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20092; -- 20092 (Dealer Hazzin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20449; -- 20449 (Researcher Navuud)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20071; -- 20071 (Wind Trader Marid)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20448; -- 20448 (Commander Ameer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20447; -- 20447 (Protectorate Vanguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20452; -- 20452 (Ethereum Assassin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20727; -- 20727 (Captain Zovax)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35504' WHERE `entry`=20456; -- 20456 (Ethereum Researcher)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35440' WHERE `entry`=20676; -- 20676 (Ethereum Sparring Dummy)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32566' WHERE `entry`=20755; -- 20755 (Ethereum Energy Cell)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=20453; -- 20453 (Ethereum Shocktrooper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19565; -- 19565 (Enormous Void Storm)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20899; -- 20899 (Void Conduit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19554; -- 19554 (Dimensius the All-Devouring)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36630' WHERE `entry`=18877; -- 18877 (Nether Drake)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20501; -- 20501 (Seeping Sludge)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19336; -- 19336 (Void Spawner XL)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18869; -- 18869 (Unstable Voidwraith)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34524' WHERE `entry`=18870; -- 18870 (Voidshrieker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20933; -- 20933 (Camera Shakers Manaforge Ultris)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20340; -- 20340 (Fleshfiend)
UPDATE `creature_template_addon` SET `auras`='31261' WHERE `entry`=20561; -- 20561 (Withered Corpse)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20607; -- 20607 (Craghide Basilisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19568; -- 19568 (Unending Voidwraith)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20459; -- 20459 (Ethereum Overlord)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20458; -- 20458 (Ethereum Archon)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32566 35465' WHERE `entry`=20520; -- 20520 (Ethereum Prisoner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20764; -- 20764 (Ethereum Target)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35242' WHERE `entry`=20778; -- 20778 (Void Waste)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32567 35465' WHERE `entry`=20825; -- 20825 (Ethereum Prisoner (Tyralius))
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35242 36515' WHERE `entry`=20474; -- 20474 (Ethereum Nexus-Stalker)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='37613' WHERE `entry`=20454; -- 20454 (Nexus-King Salhadaar)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32566' WHERE `entry`=20769; -- 20769 (Salaadin's Energy Ball)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20112; -- 20112 (Wind Trader Tuluman)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=20341; -- 20341 (Nether-Stalker Oazul)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18860; -- 18860 (Daughter of Destiny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20393; -- 20393 (Foreman Sundown)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20326; -- 20326 (Mo'arg Warp-Master)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20285; -- 20285 (Gan'arg Warp-Tinker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20804; -- 20804 (Netherstorm Moarg Work Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21089; -- 21089 (Sunfury Blood Knight)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20248; -- 20248 (Sunfury Nethermancer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20803; -- 20803 (Overmaster Grindgarr)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='37539' WHERE `entry`=20132; -- 20132 (Socrethar)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=20929; -- 20929 (Wrath Lord)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20930; -- 20930 (Hatecryer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20516; -- 20516 (Warp Monstrosity)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20913; -- 20913 (Tashar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20634; -- 20634 (Scythetooth Raptor)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='28126' WHERE `entry`=20138; -- 20138 (Culuthas)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `emote`=0, `auras`='29266' WHERE `entry`=20148; -- 20148 (Dead Doomguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20473; -- 20473 (Surveying Marker One)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21157; -- 21157 (Culuthas Scan Target Dummy)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20394; -- 20394 (Eye of Culuthas)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20141; -- 20141 (Hound of Culuthas)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20202; -- 20202 (Cragskaar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18886; -- 18886 (Farahlon Breaker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22351; -- 22351 (Eastern Gehenna Teleporter Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20928; -- 20928 (Ironspine Forgelord)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18859; -- 18859 (Wrath Priestess)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22348; -- 22348 (Western Gehenna Teleporter Credit)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=16943; -- 16943 (Cyber-Rage Forgelord)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18858; -- 18858 (Wrathbringer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18882; -- 18882 (Sundered Thunderer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20800; -- 20800 (Forgemaster Morug)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='38757' WHERE `entry`=22293; -- 22293 (Inactive Fel Reaver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22358; -- 22358 (Nether Gas Visual Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21923; -- 21923 (Terrorguard Protector)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='38966' WHERE `entry`=16949; -- 16949 (Gan'arg Mekgineer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20084; -- 20084 (Image of Nexus-Prince Haramad)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19583; -- 19583 (Grennik)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20470; -- 20470 (Zephyrion)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=20471; -- 20471 (Nether-Stalker Nauthis)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19540; -- 19540 (Asarnan)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19539; -- 19539 (Jazdalaad)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19538; -- 19538 (Dealer Senzik)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20775; -- 20775 (Markaru)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20068; -- 20068 (Zuben Eschamali)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20067; -- 20067 (Zuben Elgenubi)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19533; -- 19533 (Dealer Aljaan)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19537; -- 19537 (Dealer Malij)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20811; -- 20811 (Ghabar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20989; -- 20989 (Dealer Sadaqat)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20980; -- 20980 (Dealer Rashaad)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19534; -- 19534 (Dealer Digriz)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19535; -- 19535 (Dealer Zijaad)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19531; -- 19531 (Eyonix)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20242; -- 20242 (Karaaz)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20871; -- 20871 (Aurine Moonblaze)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20981; -- 20981 (Dealer Najeeb)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19536; -- 19536 (Dealer Jadyan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20204; -- 20204 (Action Jaxon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20205; -- 20205 (Audi the Needle)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22427; -- 22427 (Zarevhi)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22065; -- 22065 (Air Force Guard Post (Ethereal - Stormspire))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22068; -- 22068 (Air Force Trip Wire - Rooftop (Ethereal - Stormspire))
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=19529; -- 19529 (Stormspire Nexus-Guard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20610; -- 20610 (Talbuk Doe)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20777; -- 20777 (Talbuk Sire)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20774; -- 20774 (Farahlon Lasher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20810; -- 20810 (Mehrdad)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20066; -- 20066 (Gahruj)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20921; -- 20921 (Shauly Pore)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20194; -- 20194 (Dealer Dunar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19728; -- 19728 (Mama Wheeler)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34343' WHERE `entry`=20773; -- 20773 (Barbscale Crocolisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20611; -- 20611 (Shimmerwing Moth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20671; -- 20671 (Ripfang Lynx)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19738; -- 19738 (Doomclaw)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20281; -- 20281 (Drijya)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20296; -- 20296 (Teleporter Explosion Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20404; -- 20404 (Warp-Gate Engineer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16944; -- 16944 (Mo'arg Doomsmith)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=16948; -- 16948 (Gan'arg Engineer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19940; -- 19940 (Apex)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18883; -- 18883 (Mana Snapper)
UPDATE `creature_template_addon` SET `bytes2`=2, `emote`=0 WHERE `entry`=19705; -- 19705 (Master Daellis Dawnstrike)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35778 33918' WHERE `entry`=20139; -- 20139 (Sunfury Conjurer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19657; -- 19657 (Summoner Kanthin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19653; -- 19653 (Glacius)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20140; -- 20140 (Sunfury Centurion)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=20435; -- 20435 (Overseer Athanel)
UPDATE `creature_template_addon` SET `bytes2`=2, `emote`=0 WHERE `entry`=20207; -- 20207 (Sunfury Bowman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20673; -- 20673 (Swiftwing Shredder)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20515; -- 20515 (Harpax)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22491; -- 22491 (Kerpow Blastwrench)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22494; -- 22494 (Cosmowrench Bruiser)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=22479; -- 22479 (Sab'aoth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18884; -- 18884 (Warp Chaser)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20483; -- 20483 (Naberius)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=20415; -- 20415 (Bessy)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=20495; -- 20495 (Skeletal Stallion)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19544; -- 19544 (Conjurer Luminrath)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36635 33900' WHERE `entry`=20410; -- 20410 (Rhonsus)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='33900' WHERE `entry`=20409; -- 20409 (Kirin'Var Apprentice)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19866; -- 19866 (Invis East KV Rune)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19543; -- 19543 (Battle-Mage Dathric)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19545; -- 19545 (Cohlien Frostweaver)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900 12544' WHERE `entry`=19546; -- 19546 (Abjurist Belmara)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19494; -- 19494 (Ar'kelos)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19488; -- 19488 (Custodian Dieworth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19489; -- 19489 (Lieutenant-Sorcerer Morran)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20463; -- 20463 (Apprentice Andrethan)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=20934; -- 20934 (Severed Defender)
UPDATE `creature_template_addon` SET `auras`='10848' WHERE `entry`=6368; -- 6368 (Cat)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20464; -- 20464 (Thadell)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=20411; -- 20411 (Spectral Bovine)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1 WHERE `entry`=20512; -- 20512 (Tormented Soul)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21065; -- 21065 (Tormented Citizen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19867; -- 19867 (Invis NE KV Rune)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19926; -- 19926 (Spellreaver Marathelle)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20221; -- 20221 (Sunfury Flamekeeper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19723; -- 19723 (Invis BE Ballista)
UPDATE `creature_template_addon` SET `bytes2`=2, `emote`=0 WHERE `entry`=19707; -- 19707 (Sunfury Archer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19724; -- 19724 (Invis BE Tent)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19939; -- 19939 (Netherstorm Nether Beast Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19731; -- 19731 (Nether Beast)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19727; -- 19727 (Netherstorm Shoot Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19549; -- 19549 (Invis Weapon Rack)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=19881; -- 19881 (Severed Spirit)
UPDATE `creature_template_addon` SET `auras`='10848' WHERE `entry`=6271; -- 6271 (Mouse)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19548; -- 19548 (Invis Dresser)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19550; -- 19550 (Invis Footlocker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19547; -- 19547 (Invis Bookshelf)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18866; -- 18866 (Mageslayer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18867; -- 18867 (Mana Seeker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19868; -- 19868 (Invis West KV Rune)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35917' WHERE `entry`=19593; -- 19593 (Spellbinder Maryana)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19840; -- 19840 (Caledis Brightdawn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19839; -- 19839 (Lariel Sunrunner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19830; -- 19830 (Arcanist Ardonis)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19831; -- 19831 (Commander Dawnforge)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1, `emote`=0 WHERE `entry`=20136; -- 20136 (Sunfury Researcher)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35917' WHERE `entry`=20135; -- 20135 (Sunfury Arch Mage)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18850; -- 18850 (Sunfury Guardsman)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35778 33918' WHERE `entry`=20134; -- 20134 (Sunfury Arcanist)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19641; -- 19641 (Warp-Raider Nesaad)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19690; -- 19690 (N. D. Meancamp)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20243; -- 20243 (Scrapped Fel Reaver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20772; -- 20772 (Netherock)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20338; -- 20338 (Western Pipe Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18856; -- 18856 (Arcane Annihilator)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20337; -- 20337 (Southern Pipe Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20416; -- 20416 (Overseer Theredis)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19421; -- 19421 (Netherstorm Crystal Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19686; -- 19686 (Nether Anomaly)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19437; -- 19437 (Netherstorm Kneel Target)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35917' WHERE `entry`=19643; -- 19643 (Sunfury Astromancer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18855; -- 18855 (Sunfury Magister)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19453; -- 19453 (Sunfury Captain)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=1 WHERE `entry`=18853; -- 18853 (Sunfury Bloodwarder)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18857; -- 18857 (Sunfury Warp-Master)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20336; -- 20336 (Eastern Pipe Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19484; -- 19484 (Netherstorm Repair Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19483; -- 19483 (Netherstorm Use Standing Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19439; -- 19439 (Netherstorm Work Mining Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18852; -- 18852 (Sunfury Warp-Engineer)
UPDATE `creature_template_addon` SET `bytes2`=0, `emote`=0 WHERE `entry`=19779; -- 19779 (Sunfury Geologist)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18875; -- 18875 (Zaxxis Raider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19642; -- 19642 (Zaxxis Stalker)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36640' WHERE `entry`=18865; -- 18865 (Warp Aberration)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20215; -- 20215 (Pentatharon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19852; -- 19852 (Artifact Seeker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19853; -- 19853 (Felblade Doomguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18885; -- 18885 (Farahlon Giant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19849; -- 19849 (Scrap Reaver X6000)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19832; -- 19832 (Doctor Vomisa, Ph.T.)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19634; -- 19634 (Lead Sapper Blastfizzle)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21259; -- 21259 (Crash Bigbomb)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21262; -- 21262 (Goblin Equipment Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21261; -- 21261 (Big Wagon Full of Explosives Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21732; -- 21732 (Nandirx)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19776; -- 19776 (Experimental Pilot)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21734; -- 21734 (Zixxy)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21733; -- 21733 (Karzo)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19574; -- 19574 (Kizzie)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20389; -- 20389 (Lee Sparks)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19575; -- 19575 (Qiff)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19576; -- 19576 (Xyrol)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19709; -- 19709 (Chief Engineer Trep)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20162; -- 20162 (Veronia)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19655; -- 19655 (Area 52 Ethereal Technology Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19621; -- 19621 (Bill)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18938; -- 18938 (Krexcil)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19654; -- 19654 (Area 52 Analyzer Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21751; -- 21751 (Chubis)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19645; -- 19645 (Papa Wheeler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21493; -- 21493 (Kablamm Farflinger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19845; -- 19845 (Area 52 Fireworks Controller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19572; -- 19572 (Gant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19570; -- 19570 (Rocket-Chief Fuselage)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20484; -- 20484 (Area 52 Big Bruiser)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19880; -- 19880 (Nether-Stalker Khay'ji)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22280; -- 22280 (Soren)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22279; -- 22279 (Nadja)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19612; -- 19612 (Irradiated Manager)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19617; -- 19617 (Boots)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19217; -- 19217 (Ravandwyr)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19780; -- 19780 (Off-Duty Engineer)
UPDATE `creature_template_addon` SET `bytes1`=2, `bytes2`=1, `emote`=0 WHERE `entry`=19737; -- 19737 (Engineering Crewmember)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19482; -- 19482 (Sagan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19466; -- 19466 (Exarch Orelis)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19623; -- 19623 (Doc)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22063; -- 22063 (Air Force Trip Wire - Rooftop (Goblin - Area 52))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19468; -- 19468 (Spymaster Thalodien)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19469; -- 19469 (Magistrix Larynna)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19467; -- 19467 (Anchorite Karja)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19571; -- 19571 (Innkeeper Remi Dodoso)
UPDATE `creature_template_addon` SET `bytes1`=6, `bytes2`=1 WHERE `entry`=19651; -- 19651 (Seasoned Vindicator)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19610; -- 19610 (Irradiated Worker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17636; -- 17636 (Kalynna Lathred)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20485; -- 20485 (Area 52 Bruiser)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21997; -- 21997 (Air Force Guard Post (Goblin - Area 52 - Zeppelin))
UPDATE `creature_template_addon` SET `bytes1`=6, `bytes2`=1 WHERE `entry`=18593; -- 18593 (Scryer Retainer)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=19573; -- 19573 (Dash)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19541; -- 19541 (Netherstorm Agent)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20284; -- 20284 (Dr. Boom)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19692; -- 19692 (Boom Bot)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18881; -- 18881 (Sundered Rumbler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18864; -- 18864 (Mana Wraith)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=21058; -- 21058 (Disembodied Exarch)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=18873; -- 18873 (Disembodied Protector)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='33900' WHERE `entry`=18872; -- 18872 (Disembodied Vindicator)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18880; -- 18880 (Nether Ray)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36576' WHERE `entry`=20210; -- 20210 (Shaleskin Flayer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18879; -- 18879 (Phase Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19569; -- 19569 (Netherologist Coppernickels)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20203; -- 20203 (Nether Technician)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20514; -- 20514 (Searing Elemental)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20925; -- 20925 (Scalded Basilisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19961; -- 19961 (Doomforge Attendant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21233; -- 21233 (Legion Fel Cannon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22422; -- 22422 (Blade's Edge - Legion - Anger Camp - Invis Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19960; -- 19960 (Doomforge Engineer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16952; -- 16952 (Anger Guard)
UPDATE `creature_template_addon` SET `bytes1`=131072, `bytes2`=1, `auras`='22766' WHERE `entry`=20998; -- 20998 (Ridgespine Horror)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21124; -- 21124 (Felsworn Daggermaw)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21123; -- 21123 (Felsworn Scalewing)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21300; -- 21300 (Fel Corrupter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20635; -- 20635 (Razaani Light Orb)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21053; -- 21053 (Blade's Edge - Orb Trigger 03)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20856; -- 20856 (Blade's Edge - Deadsoul Orb Flight 05)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20666; -- 20666 (Blade's Edge - Orb Trigger 01)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20855; -- 20855 (Blade's Edge - Deadsoul Orb Flight 04)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20670; -- 20670 (Blade's Edge - Flesh Beast Zap Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20852; -- 20852 (Blade's Edge - Deadsoul Orb Flight 02)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20668; -- 20668 (Fiendling Flesh Beast)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20853; -- 20853 (Blade's Edge - Deadsoul Orb Flight 03)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20771; -- 20771 (Razaani Light Orb - Mini)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20609; -- 20609 (Razaani Nexus Stalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20601; -- 20601 (Razaani Raider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20614; -- 20614 (Razaani Spell-Thief)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20851; -- 20851 (Blade's Edge - Deadsoul Orb Flight 01)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22312; -- 22312 (Spiritcaller Dohgar)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=257, `emote`=0 WHERE `entry`=21103; -- 21103 (Spiritcaller Grakosh)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=257, `emote`=0 WHERE `entry`=21106; -- 21106 (Spiritcaller Skrash)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=257, `emote`=0 WHERE `entry`=21105; -- 21105 (Spiritcaller Roxnak)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22468; -- 22468 (Ogrin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22136; -- 22136 (Dubu)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21086; -- 21086 (Ruka)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21084; -- 21084 (Braagor)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21088; -- 21088 (Matron Varah)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22004; -- 22004 (Leoroxx)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22141; -- 22141 (Quilbeast)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22110; -- 22110 (Tethik)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21082; -- 21082 (Krugash)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21692; -- 21692 (Cansis)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21496; -- 21496 (Dertrok)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21896; -- 21896 (Silmara)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21895; -- 21895 (Taerek)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21083; -- 21083 (Erool)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=22142; -- 22142 (Zakk)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21087; -- 21087 (Grikka)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22135; -- 22135 (Tame Clefthoof)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21085; -- 21085 (Ragar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22455; -- 22455 (Sky-Master Maxxor)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21081; -- 21081 (Mok'Nathal Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20161; -- 20161 (Vekh'nir Matriarch)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19982; -- 19982 (Vekh'nir Keeneye)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21840; -- 21840 (Cosmetic Silkwing)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21839; -- 21839 (Mature Silkwing)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20747; -- 20747 (Silkwing Larva)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22472; -- 22472 (Death's Door South Warp-Gate)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22443; -- 22443 (Death's Door Fel Cannon)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=19978; -- 19978 (Deathforge Over-Smith)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22502; -- 22502 (Death's Door Warp-Gate Explosion Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22471; -- 22471 (Death's Door North Warp-Gate)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22500; -- 22500 (Void Hound)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22474; -- 22474 (Unstable Fel-Imp)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22495; -- 22495 (Death's Door Fel Cannon Target Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19980; -- 19980 (Void Terror)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19747; -- 19747 (Baelmon the Hound-Master)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20736; -- 20736 (Blade's Edge - Legion - Invis Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22305; -- 22305 (Vekh)
UPDATE `creature_template_addon` SET `bytes1`=2, `bytes2`=1 WHERE `entry`=19979; -- 19979 (Deathforge Technician)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20751; -- 20751 (Daggermaw Lashtail)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=19984; -- 19984 (Vekh'nir Dreadhawk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19983; -- 19983 (Vekh'nir Stormcaller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20749; -- 20749 (Scalewing Serpent)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='36661 36442' WHERE `entry`=21254; -- 21254 (Dullgrom Dredger)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36630' WHERE `entry`=21032; -- 21032 (Dreadwing)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36630' WHERE `entry`=21004; -- 21004 (Lesser Nether Drake)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21189; -- 21189 (Crystal Flayer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='42716' WHERE `entry`=21413; -- 21413 (Gnome Cannon Shooter #1)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='42716' WHERE `entry`=21935; -- 21935 (Gnome Cannon Shooter #Shattrath)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='42716' WHERE `entry`=21944; -- 21944 (Gnome Cannon Shooter #Ruuan)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21107; -- 21107 (Rip Pedalslam)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='42716' WHERE `entry`=21930; -- 21930 (Gnome Cannon Shooter #0)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21111; -- 21111 (Bembil Knockhammer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21112; -- 21112 (Bossi Pentapiston)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21113; -- 21113 (Sassa Weldwell)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21152; -- 21152 (Station Bot-Jock)
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=21691; -- 21691 (Toshley)
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=21824; -- 21824 (Dizzy Dina)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21393; -- 21393 (Cannon Channeler)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21110; -- 21110 (Fizit "Doc" Clocktock)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=21461; -- 21461 (Rally Zapnabber)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21755; -- 21755 (Nickwinkle the Metro-Gnome)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21494; -- 21494 (Smiles O'Byron)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21460; -- 21460 (Tally Zapnabber)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22090; -- 22090 (Air Force Guard Post (Toshley's Station - Flying Machine))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21422; -- 21422 (Blade's Edge - Toshley's - Invisible Stalker - Atk Target)
UPDATE `creature_template_addon` SET `path_id`=0, `bytes2`=257 WHERE `entry`=21118; -- 21118 (Razak Ironsides)
UPDATE `creature_template_addon` SET `bytes1`=131072, `bytes2`=1, `auras`='22766' WHERE `entry`=20714; -- 20714 (Ridgespine Stalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21447; -- 21447 (Blade's Edge - Toshley's - Def Gun Attack Origin)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=21114; -- 21114 (Station Technician)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='42716' WHERE `entry`=21942; -- 21942 (Gnome Cannon Shooter #Singing Ridge)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21819; -- 21819 (Blade's Edge - Toshley's - Invisible Stalker - Def Gun Target)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34343' WHERE `entry`=22123; -- 22123 (Rip-Blade Ravager)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21519; -- 21519 (Death's Might)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20765; -- 20765 (Bladespire Crusher)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=20766; -- 20766 (Bladespire Mystic)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20768; -- 20768 (Gnosh Brognat)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19476; -- 19476 (Lor)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19450; -- 19450 (Pol Snowhoof)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19471; -- 19471 (Old Orok)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19478; -- 19478 (Fera Palerunner)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18953; -- 18953 (Unoke Tenderhoof)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19470; -- 19470 (Gholah)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19473; -- 19473 (Raiza)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21311; -- 21311 (Rokgah Bloodgrip)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='12550 28892' WHERE `entry`=21117; -- 21117 (Gor'drek)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21147; -- 21147 (Tor'chunk Twoclaws)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19479; -- 19479 (Orgatha)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=18248; -- 18248 (Nekthar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19472; -- 19472 (Threlc)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19837; -- 19837 (Daga Ramba)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19474; -- 19474 (Karnaze)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21142; -- 21142 (Dire Timber Wolf Trigger)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19449; -- 19449 (Thunderlord Grunt)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21984; -- 21984 (Rexxar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21516; -- 21516 (Death's Watch)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21690; -- 21690 (R-3D0)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21956; -- 21956 (Rema)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21033; -- 21033 (Bladewing Bloodletter)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='37691' WHERE `entry`=20748; -- 20748 (Thunderlord Dire Wolf)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18937; -- 18937 (Amerun Leafshade)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19499; -- 19499 (Cahill)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19495; -- 19495 (Innkeeper Shaunessy)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19497; -- 19497 (Caoileann)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22469; -- 22469 (Fiskal Shadowsong)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=21197; -- 21197 (Bronwyn Stouthammer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21151; -- 21151 (Borgrim Stouthammer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21469; -- 21469 (Daranelle)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19498; -- 19498 (Tanaide)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21066; -- 21066 (Rina Moonspring)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=21158; -- 21158 (Commander Skyshadow)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20126; -- 20126 (Sylvanaar Ancient Protector)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=18098; -- 18098 (Kialon Nightblade)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19500; -- 19500 (Sylvanaar Sentinel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20095; -- 20095 (Grimnok Battleborn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21176; -- 21176 (Bloodmaul Dire Wolf Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21349; -- 21349 (T'chali the Witch Doctor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19952; -- 19952 (Bloodmaul Geomancer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=20726; -- 20726 (Mugdorg)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20730; -- 20730 (Glumdor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20723; -- 20723 (Korgaah)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21975; -- 21975 (Bladespire Sober Defender)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20230; -- 20230 (Blade's Edge - Bladespire Trigger 01)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20334; -- 20334 (Bladespire Cook)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21352; -- 21352 (Ogre Building Bunny Summoner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21277; -- 21277 (Vindicator Vuuleen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21296; -- 21296 (Bladespire Champion)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19995; -- 19995 (Bladespire Brute)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20728; -- 20728 (Bladespire Raptor)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=19998; -- 19998 (Bladespire Shaman)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20249; -- 20249 (Cymbre Starsong)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20915; -- 20915 (Noko Moonwhisper)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22216; -- 22216 (Fhyn Leafshadow)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=21983; -- 21983 (Samia Inkling)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20916; -- 20916 (Xerintha Ravenoak)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=22007; -- 22007 (Tree Warden Chawn)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22020; -- 22020 (O'Mally Zapnabber)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='36792' WHERE `entry`=22021; -- 22021 (O'Mally's Instrument Bunny)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22053; -- 22053 (Mosswood the Ancient)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21782; -- 21782 (Timeon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22465; -- 22465 (Natasha)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20250; -- 20250 (Rashere Pridehoof)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22127; -- 22127 (Wildlord Antelarion)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20917; -- 20917 (Zinyen Swiftstrider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22133; -- 22133 (Faradrella)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22151; -- 22151 (Ruuan Weald Sister)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22150; -- 22150 (Lieutenant Fairweather)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22149; -- 22149 (Commander Haephus Stonewall)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20211; -- 20211 (Ruuan'ok Matriarch)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20987; -- 20987 (Ruuan Weald Basilisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19987; -- 19987 (Ruuan'ok Ravenguard)
UPDATE `creature_template_addon` SET `bytes1`=2, `bytes2`=1 WHERE `entry`=19985; -- 19985 (Ruuan'ok Cloudgazer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19986; -- 19986 (Ruuan'ok Skyfury)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21981; -- 21981 (Overseer Nuaar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22241; -- 22241 (Bash'ir Raider)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='38857' WHERE `entry`=22242; -- 22242 (Bash'ir Spell-Thief)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22244; -- 22244 (Unbound Ethereal)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22243; -- 22243 (Bash'ir Arcanist)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='39991' WHERE `entry`=23261; -- 23261 (Furywing)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21021; -- 21021 (Scorch Imp)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='39991' WHERE `entry`=23281; -- 23281 (Insidion)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32942' WHERE `entry`=22255; -- 22255 (Daggertail Lizard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20757; -- 20757 (Fingrom)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20756; -- 20756 (Bladespire Chef)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19996; -- 19996 (Bladespire Battlemage)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22918; -- 22918 (Gronn Showdown Bunny)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22268; -- 22268 (Leokk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20729; -- 20729 (Bladespire Ravager)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19997; -- 19997 (Bladespire Enforcer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20753; -- 20753 (Dorgok)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22368; -- 22368 ([DND]Fermented Seed Beer Keg Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22356; -- 22356 ([DND]Green Spot Grog Keg Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22367; -- 22367 ([DND]Ripe Moonshine Keg Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22116; -- 22116 ([DND]Whisper Spying Credit Marker 1)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='13787' WHERE `entry`=22384; -- 22384 (Bloodmaul Soothsayer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22160; -- 22160 (Bloodmaul Taskmaster)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19993; -- 19993 (Bloodmaul Mauler)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=1, `auras`='13787' WHERE `entry`=19994; -- 19994 (Bloodmaul Warlock)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=20330; -- 20330 (Bloodmaul Battle Worg)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22052; -- 22052 (Daggermaw Blackhide)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21381; -- 21381 (Young Crust Burster)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22386; -- 22386 (Watcher Moonshade)
UPDATE `creature_template_addon` SET `bytes1`=131072, `bytes2`=257, `auras`='22766' WHERE `entry`=22206; -- 22206 (Expedition Druid)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=3681; -- 3681 (Wisp)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21809; -- 21809 (Wyrmcult Poacher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22308; -- 22308 (Wyrmcult Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22396; -- 22396 (Draaca Longtail)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22040; -- 22040 (Cave Bat)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21810; -- 21810 (Wyrmcult Hewer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22801; -- 22801 ([DND]Prophecy 4 Quest Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22799; -- 22799 ([DND]Prophecy 2 Quest Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20329; -- 20329 (Grishna Matriarch)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22800; -- 22800 ([DND]Prophecy 3 Quest Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20924; -- 20924 (Grishnath Basilisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22798; -- 22798 ([DND]Prophecy 1 Quest Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21851; -- 21851 (The Voice of the Raven God)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19988; -- 19988 (Grishna Falconwing)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19989; -- 19989 (Grishna Harbinger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19990; -- 19990 (Grishna Scorncrow)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22215; -- 22215 (Treebole)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21048; -- 21048 (Boulder'mok Chieftain)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21047; -- 21047 (Boulder'mok Shaman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21046; -- 21046 (Boulder'mok Brute)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21383; -- 21383 (Wyrmcult Acolyte)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21040; -- 21040 (Outraged Raven's Wood Sapling)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='37637' WHERE `entry`=21497; -- 21497 (Blackscale)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='37637' WHERE `entry`=21387; -- 21387 (Wyrmcult Blackwhelp)
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry`=21637; -- 21637 (Wyrmcult Scout)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21326; -- 21326 (Raven's Wood Leafbeard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21325; -- 21325 (Raven's Wood Stonebark)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21042; -- 21042 (Dire Raven)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21382; -- 21382 (Wyrmcult Zealot)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22019; -- 22019 (Kolphis Darkscale)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='8278 8279' WHERE `entry`=22282; -- 22282 (Witness of Doom)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22195; -- 22195 (Wrath Speaker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20557; -- 20557 (Wrath Hound)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22291; -- 22291 (Furnace Guard)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='19818 16245' WHERE `entry`=22196; -- 22196 (Wrath Reaver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22982; -- 22982 (Skyguard Navigator)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='40349' WHERE `entry`=22254; -- 22254 (Wrath Corruptor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23257; -- 23257 (Skyguard Windcharger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22987; -- 22987 (Skyguard Nether Ray)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21234; -- 21234 (Blade's Edge Invisible Stalker)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='40570' WHERE `entry`=23253; -- 23253 (Kronk)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='39991' WHERE `entry`=23282; -- 23282 (Obsidia)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `bytes2`=1, `auras`='39991' WHERE `entry`=23061; -- 23061 (Rivendark)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19656; -- 19656 (Invisible Location Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22175; -- 22175 (Apexis Flayer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21203; -- 21203 (Blade's Edge - Rock Flayer Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22181; -- 22181 (Aether Ray)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12743' WHERE `entry`=19973; -- 19973 (Abyssal Flamebringer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='40773' WHERE `entry`=22180; -- 22180 (Shard-Hide Boar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22298; -- 22298 (Vile Fire-Soul)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22204; -- 22204 (Fear Fiend)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20113; -- 20113 (Lashh'an Matriarch)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20003; -- 20003 (Blade's Edge Kneel Target 01)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19943; -- 19943 (Lashh'an Talonite)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20093; -- 20093 (Blade's Edge - Arakkoa Spell Origin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20024; -- 20024 (Blade's Edge Kneel Target 03)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20023; -- 20023 (Blade's Edge Kneel Target 02)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `emote`=0 WHERE `entry`=19944; -- 19944 (Lashh'an Wing Guard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20127; -- 20127 (Tame Kaliri)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19945; -- 19945 (Lashh'an Windwalker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21022; -- 21022 (Grovestalker Lynx)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21074; -- 21074 (Living Grove Defender Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20713; -- 20713 (Fey Drake)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=19992; -- 19992 (Bloodmaul Shaman)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=1 WHERE `entry`=19948; -- 19948 (Bloodmaul Skirmisher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19957; -- 19957 (Bloodmaul Brewmaster)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='18950' WHERE `entry`=20058; -- 20058 (Bloodmaul Dire Wolf)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19991; -- 19991 (Bloodmaul Brute)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21238; -- 21238 (Bloodmaul Drudger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22044; -- 22044 (Cavern Crawler)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22489; -- 22489 (Grunt Grahk)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='5301' WHERE `entry`=18922; -- 18922 (Telredor Guard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17998; -- 17998 (Umbrafen Steam Pump Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35319' WHERE `entry`=18138; -- 18138 (Umbrafen Eel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20079; -- 20079 (Darkcrest Sentry)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18122; -- 18122 (Dreghood Drudge)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19946; -- 19946 (Darkcrest Slaver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18137; -- 18137 (Marsh Dredger)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35360 35230' WHERE `entry`=18912; -- 18912 (Sporelok)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18136; -- 18136 (Marsh Lurker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18476; -- 18476 (Timber Worg)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=18586; -- 18586 (Coosh'coosh)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18080; -- 18080 (Kataru)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17969; -- 17969 (Kayra Longmane)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='34871' WHERE `entry`=20115; -- 20115 (Umbrafen Witchdoctor)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=18077; -- 18077 (Umbrafen Oracle)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18079; -- 18079 (Umbrafen Seer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17901; -- 17901 (Keleth)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18911; -- 18911 (Juno Dufrain)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18070; -- 18070 (Windcaller Blackhoof)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17858; -- 17858 (Warden Hamoot)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17900; -- 17900 (Ashyen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17956; -- 17956 (Ikeyen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18332; -- 18332 (Talut)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17896; -- 17896 (Kameel Longstride)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17909; -- 17909 (Lauranna Thar'well)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18907; -- 18907 (Innkeeper Coryth Stoktron)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18993; -- 18993 (Naka)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17904; -- 17904 (Fedryen Swiftspear)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17834; -- 17834 (Lethyn Moonfire)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21172; -- 21172 (Sarinei Whitestar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22125; -- 22125 (Air Force Guard Post (Cenarion - Stormcrow))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17841; -- 17841 (Ysiel Windsinger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22126; -- 22126 (Air Force Trip Wire - Rooftop (Cenarion Expedition))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17855; -- 17855 (Expedition Warden)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20762; -- 20762 (Gur'zil)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18243; -- 18243 (Lorti)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21993; -- 21993 (Air Force Guard Post (Horde - Bat Rider))
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='5301' WHERE `entry`=18910; -- 18910 (Swamprat Guard)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18011; -- 18011 (Zurai)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22002; -- 22002 (Air Force Trip Wire - Ground (Horde))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22001; -- 22001 (Air Force Trip Wire - Rooftop (Horde))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18012; -- 18012 (Reavij)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18016; -- 18016 (Magasha)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20283; -- 20283 (Marshrock Stomper)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='29266' WHERE `entry`=18035; -- 18035 (Scout Jyoba)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20324; -- 20324 (Parched Hydra)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18124; -- 18124 (Withered Giant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19706; -- 19706 (Marshrock Threshalisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19402; -- 19402 (Withered Bog Lord)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18130; -- 18130 (Marshfang Ripper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18132; -- 18132 (Umbraglow Stinger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20387; -- 20387 (Young Sporebat)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18044; -- 18044 (Rajis Fyashe)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18000; -- 18000 (Serpent Steam Pump Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20089; -- 20089 (Bloodscale Wavecaller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20088; -- 20088 (Bloodscale Overseer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20292; -- 20292 (Marsh Baron Brok)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='6871' WHERE `entry`=20291; -- 20291 (Lagoon Walker)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35319' WHERE `entry`=20290; -- 20290 (Lagoon Eel)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18213; -- 18213 (Mire Hydra)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=18197; -- 18197 (Elder Kuruti)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='12550' WHERE `entry`=18114; -- 18114 (Feralfen Mystic)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18113; -- 18113 (Feralfen Hunter)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20196; -- 20196 (Bloodthirsty Marshfang)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20270; -- 20270 (Feralfen Druid)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18128; -- 18128 (Sporebat)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='3417' WHERE `entry`=18134; -- 18134 (Fen Strider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18212; -- 18212 (Mudfin Frenzy)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='8876' WHERE `entry`=18214; -- 18214 (Fenclaw Thrasher)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18908; -- 18908 (Innkeeper Kerp)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20028; -- 20028 (Doba)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18010; -- 18010 (Maktu)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18008; -- 18008 (Ikuti)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22003; -- 22003 (Air Force Trip Wire - Ground (Alliance))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21996; -- 21996 (Air Force Guard Post (Alliance - Gryphon))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21999; -- 21999 (Air Force Trip Wire - Rooftop (Alliance))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19722; -- 19722 (Muheru the Weaver)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=22485; -- 22485 (Halu)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18009; -- 18009 (Puluu)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18019; -- 18019 (Timothy Daniels)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20197; -- 20197 (Bogflare Needler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18159; -- 18159 (Boss Grog'ak)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='5301' WHERE `entry`=18943; -- 18943 (Orebor Harborage Defender)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18118; -- 18118 (Ango'rosh Shaman)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18117; -- 18117 (Ango'rosh Ogre)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20442; -- 20442 (Captain Bo'kar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18115; -- 18115 (Daggerfen Muckdweller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19174; -- 19174 (Chieftain Mummaki)
UPDATE `creature_template_addon` SET `bytes1`=131072, `bytes2`=1, `auras`='22766' WHERE `entry`=18116; -- 18116 (Daggerfen Assassin)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18992; -- 18992 (Captain Krosh)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='13787' WHERE `entry`=19732; -- 19732 (Ango'rosh Warlock)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18119; -- 18119 (Ango'rosh Brute)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20443; -- 20443 (Ango'rosh Sentry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18002; -- 18002 (Marshlight Steam Pump Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='6961' WHERE `entry`=18340; -- 18340 (Steam Pump Overseer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20090; -- 20090 (Bloodscale Sentry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19733; -- 19733 (Daggerfen Servant)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18123; -- 18123 (Wrekt Slave)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18089; -- 18089 (Bloodscale Slavedriver)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='31261' WHERE `entry`=20294; -- 20294 (Bogstrok Razorclaw)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18088; -- 18088 (Bloodscale Enchantress)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20295; -- 20295 (Bogstrok Crusher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19730; -- 19730 (Ironspine Gazer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19729; -- 19729 (Ironspine Threshalisk)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='3417' WHERE `entry`=18680; -- 18680 (Marticar)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17925; -- 17925 (Gshaff)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=17866; -- 17866 (Khn'nix)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17856; -- 17856 (Gzhun'tt)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17924; -- 17924 (Msshi'fn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17877; -- 17877 (Fhwoor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18382; -- 18382 (Mycah)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18140; -- 18140 (Sporeggar Harvester)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18139; -- 18139 (Sporeggar Preserver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22087; -- 22087 (Air Force Guard Post (Sporeggar - Sporebat))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22088; -- 22088 (Air Force Trip Wire - Rooftop (Sporeggar))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17923; -- 17923 (Fahssn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20293; -- 20293 (Bogstrok Clacker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17378; -- 17378 (Swamp Gas)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20280; -- 20280 (Ragestone Trampler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20198; -- 20198 (Fenglow Stinger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20279; -- 20279 (Ragestone Threshalisk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18125; -- 18125 (Starving Fungal Giant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19519; -- 19519 (Starving Bog Lord)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='35360 35230' WHERE `entry`=18358; -- 18358 (Sporeggar Spawn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18133; -- 18133 (Marshlight Bleeder)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18129; -- 18129 (Greater Sporebat)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='8876' WHERE `entry`=18135; -- 18135 (Marsh Walker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18131; -- 18131 (Marshfang Slicer)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (16870, 20749, 23264, 16975, 22175, 20196, 22180, 16951, 18358, 23082, 17058, 22045, 19994, 21042, 16947, 21408, 16880, 22252, 23308, 21387, 21462, 22181, 16831, 21858, 18212, 16846, 19756, 21316, 19779, 22387, 20607, 21061, 20796, 21854, 20774, 16903, 18128, 23076, 19136, 22017, 5355, 18132, 20294, 19606, 18879, 21720, 19731, 16954, 18035, 23077, 23287, 18138, 18125, 19765, 18463, 19796, 1410, 18886, 21455, 24919, 20295, 19607, 19705, 19801, 21749, 21728, 22196, 18866, 18130, 18214, 18853, 20729, 20203, 21737, 21305, 22244, 22464, 20221, 20141, 20634, 19983, 16912, 20710, 18850, 21302, 19760, 20293, 20872, 18088, 21450, 20714, 21662, 21878, 12922, 21840, 18140, 21022, 18884, 19802, 17014, 18470, 18124, 18858, 20290, 19982, 18089, 16950, 20610, 19190, 21381, 21719, 19997, 20810, 22991, 20291, 19948, 22204, 22242, 21717, 19740, 18077, 19800, 21233, 20811, 18870, 19952, 18852, 21189, 21443, 21277, 20210, 21661, 22243, 22274, 18477, 19188, 23169, 18134, 21736, 18467, 19784, 21033, 20751, 21046, 18875, 19989, 22241, 20561, 23347, 16904, 20611, 20409, 18465, 16863, 18133, 21816, 16864, 20933, 21074, 19422, 20773, 16948, 22822, 16865, 18117, 20748, 21814, 21923, 19408, 20109, 21648, 21519, 16836, 21453, 21879, 21478, 21722, 19960, 22095, 22861, 19527, 16972, 22857, 20235, 20671, 21383, 18857, 22016, 20453, 23376, 19988, 18827, 18490, 21810, 19747, 22821, 20232, 17924, 21520, 20929, 20292, 21870, 16878, 20058, 22253, 20502, 23242, 23282, 16901, 18872, 21704, 21347, 17925, 19996, 18079, 21267, 21839, 16871, 18774, 18449, 21711, 18113, 19461, 19947, 20248, 18123, 20231, 18775, 17923, 19624, 20387, 23241, 23501, 19852, 21718, 19004, 20728, 21656, 16949, 18476, 18773, 16952, 18864, 20765, 18978, 19946, 20327, 21637, 18883, 20825, 19995, 19717, 21324, 19692, 22052, 20136, 21195, 22018, 24933, 18771, 21503, 21660, 18452, 21420, 21124, 20766, 21050, 20887, 22134, 20878, 18716, 19001, 20270, 20889, 23257, 21314, 19961, 18975, 20501, 21254, 21114, 20139, 22474, 20512, 18213, 16884, 16857, 16938, 19991, 22040, 20668, 19733, 23246, 16906, 16879, 16974, 22293, 22858, 17378, 18464, 22254, 21326, 18469, 22083, 22255, 23285, 20513, 20280, 16911, 21310, 21111, 20088, 18468, 22966, 21809, 21811, 20340, 23311, 18453, 18881, 22317, 21284, 20279, 16847, 18990, 24920, 23386, 21352, 21183, 19943, 16599, 19993, 19414, 22160, 21245, 22123, 23326, 21041, 21869, 24918, 19957, 18122, 20713, 19759, 20780, 21385, 21454, 18129, 18952, 22298, 19768, 19944, 21311, 19825, 16805, 21058, 23309, 21325, 18750, 21701, 19425, 21180, 19881, 18753, 19642, 21059, 19755, 22864, 20324, 20079, 20474, 22044, 19762, 22424, 20330, 20516, 16591, 20777, 21168, 20095, 20609, 16835, 19432, 21242, 20198, 20601, 19998, 22388, 21089, 21505, 21649, 16588, 19261, 19792, 21852, 18454, 18115, 16943, 21742, 16905, 18260, 16586, 18131, 21703, 35101, 18588, 16960, 20458, 21300, 19736, 19985, 17956, 21196, 21380, 19519, 20928, 35099, 16582, 22282, 16585, 21721, 20778, 16769, 18455, 18880, 20456, 19499, 20435, 20924, 20756, 21941, 19707, 20730, 16590, 18437, 22138, 20876, 19806, 21171, 18461, 19495, 20334, 16907, 21692, 19979, 19328, 19990, 23188, 23154, 21911, 20452, 22859, 21690, 20140, 21691, 18135, 16519, 16896, 19767, 21849, 20930, 20197, 16873, 19732, 21384, 21047, 22112, 19730, 20747, 16578, 18450, 23020, 20557, 21179, 20877, 19446, 19191, 16978, 19984, 21004, 18460, 19686, 19447, 19258, 18119, 18867, 22381, 23324, 18855, 21650, 20092, 20753, 16843, 21337, 19545, 18873, 18865, 22291, 20134, 18201, 16867, 18080, 20135, 18451, 20443, 21804, 19826, 21198, 19701, 20449, 20285, 19836, 19349, 23286, 19987, 16602, 18340, 17123, 21040, 16600, 21460, 21238, 19937, 21382, 19565, 16830, 22386, 19945, 22195, 18114, 21065, 20890, 19569, 21824, 16828, 21419, 20891, 19426, 18869, 20207, 22461, 22019, 16844, 21285, 17585, 16825, 23219, 19789, 20987, 18136, 20394, 19453, 22093, 22113, 19402, 21135, 18686, 35100, 20068, 22270, 17998, 21636, 22271, 22323, 21200, 20066, 21309, 20067, 20614, 19853, 22266, 18974, 19415, 22264, 21048, 23119, 17142, 19413, 21296, 16944, 17402, 19410, 35093, 18911, 18912, 16576, 18908, 22307, 19824, 19849, 18907, 22100, 20934, 21496, 18885, 21808, 19568, 18554, 21497, 21743, 49789, 18466, 20089, 19840, 16798, 16973, 16799, 20459, 19754, 16797, 21313, 24955, 21334, 21123, 19392, 18981, 20800, 19424, 20907, 18438, 19799, 18002, 19722, 21255, 18859, 20404, 21802, 22312, 19350, 21803, 20903, 21975, 20520, 20727, 20998, 19992, 20893, 17088, 21901, 21500, 19973, 21152, 22384, 21386, 21060, 22082, 18714, 21908, 22432, 22987, 18882, 22105, 22430, 19729, 22431, 18383, 18906, 16977, 21757, 18987, 16821, 21295, 21292, 19726, 21293, 18456, 21291, 18116, 19423, 19725, 20922, 20115, 22214, 16886, 21178, 20442, 19788, 20921, 23150, 21782, 18070, 22211, 20563, 18843, 19411, 22469, 22304, 18118, 20913, 23281, 22025, 19434, 23142, 21307, 20931, 21644, 21710, 22115, 18384, 18385, 20892, 20925, 22489, 20090, 19795, 19940, 21506, 3230, 22137, 16946, 21404, 22479, 21516, 16858, 21110, 16856, 19706, 20798, 19494, 20148, 18760, 16829, 19986, 16826, 20673, 18098, 20768, 18677, 16937, 16823, 20251, 16964, 20684, 19192, 20454, 19827, 16839, 21102, 21700, 20415, 18248, 20871, 24938, 18648, 21515, 16832, 20803, 16833, 19544, 22500, 19488, 19489, 16932, 18243, 20795, 21983, 22012, 21981, 19738, 20723, 22011, 19978, 20874, 24893, 20551, 20329, 19651, 17877, 20194, 22458, 23363, 19980, 18586, 20161, 23280, 18197, 19468, 19469, 19643, 18457, 19466, 22427, 19467, 21066, 18720, 21164, 16838, 20451, 21416, 20554, 16824, 20498, 20483, 16584, 22228, 20495, 19440, 19709, 23267, 19560, 20138, 19561, 22378, 20243, 23305, 22007, 16915, 20162, 21774, 21775, 21772, 21368, 21773, 18676, 21770, 21402, 22308, 21771, 51612, 21103, 20770, 21769, 22899, 23145, 23174, 21896, 20986, 21895, 66551, 18249, 19263, 21897, 18758, 19256, 21477, 21117, 29145, 19335, 20133, 18692, 19295, 17006, 21106, 30735, 17004, 21105, 17002, 22433, 115598, 22377, 21249, 16925, 18424, 19744, 18565, 19354, 30722, 23217, 21822, 23362, 18877, 19264, 22860, 19174, 22982, 20113, 47573, 19634, 21639, 18751, 19720, 18678, 18382, 23144, 18707, 20678, 20679, 23143, 20677, 19623, 21826, 23029, 19621, 20195, 20410, 19326, 18860, 22446, 18992, 23430, 18993, 115597, 20757, 22454, 21979, 21032, 16876, 18717, 18976, 21928, 21197, 22862, 17062, 21860, 21166, 21294, 22441, 19772, 22225, 21094, 18754, 18159, 21092, 21705, 18447, 20726, 21847, 22476, 19926, 21108, 20132, 19682, 19282, 16579, 18262, 16574, 17858, 18044, 21006, 16575, 19276, 17856, 18755, 19277, 22443, 23289, 20683, 21287, 20281, 23209, 21797, 20676, 19562, 19443, 16848, 22020, 20202, 18718, 22481, 19559, 23061, 19543, 18595, 16927, 17900, 18332, 17901, 20899, 20284, 17896, 21021, 20236, 19839, 22477, 21501, 18779, 20028, 16897, 18777, 19830, 18772, 19546, 19831, 22396, 23383, 19363, 22053, 19361, 19652, 18480, 21112, 17904, 20215, 21113, 115644, 21151, 21499, 30734, 21147, 21827, 21938, 20416, 23261, 18752, 20211, 18693, 19757, 30721, 19498, 19298, 19332, 21954, 19497, 21026, 21158, 21955, 21027, 21024, 21953, 19329, 24928, 19455, 18281, 47574, 18984, 19451, 20071, 18679, 18680, 17834, 18749, 21194, 20242, 21172, 21192, 20450, 21193, 19554, 20448, 21188, 19657, 19653, 22278, 23153, 22272, 22995, 20772, 16589, 17841, 18540, 19314, 23269, 19315, 21709, 19769, 18962, 16583, 20470, 20283, 18719, 16577, 20464, 20775, 19458, 20463, 18137, 19459, 22227, 22364, 20858, 18012, 18010, 21095, 17969, 18011, 24959, 18959, 18008, 18009, 22150, 18957, 22305, 21349, 18776, 19002, 19593, 18000, 22042, 22043, 19683, 21461, 20514, 19278, 20477, 19279, 18856, 21956, 18541, 22919, 19641, 18539, 18019, 18016, 18802, 17657, 18960, 22941, 22054, 18705, 21755, 19442, 20326);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(16870, 1, 25996),
(20749, 0, 25996),
(23264, 0, 25996),
(16975, 0, 25996),
(22175, 0, 25996),
(20196, -1, 25996),
(22180, 1, 25996),
(16951, 1, 25996),
(18358, 0, 25996),
(23082, -1, 25996),
(17058, 0, 25996),
(22045, -1, 25996),
(19994, 1, 25996),
(21042, -1, 25996),
(16947, 1, 25996),
(21408, 0, 25996),
(16880, 1, 25996),
(22252, 0, 25996),
(23308, 0, 25996),
(21387, 2, 25996),
(21462, 0, 25996),
(22181, 1, 25996),
(16831, 0, 25996),
(21858, 0, 25996),
(18212, 1, 25996),
(16846, 3, 25996),
(19756, 0, 25996),
(21316, 0, 25996),
(19779, 0, 25996),
(22387, 0, 25996),
(20607, 1, 25996),
(21061, 0, 25996),
(20796, 0, 25996),
(21854, 1, 25996),
(20774, -1, 25996),
(16903, 0, 25996),
(18128, 1, 25996),
(23076, 0, 25996),
(19136, 0, 25996),
(22017, -1, 25996),
(5355, -1, 25996),
(18132, -1, 25996),
(20294, -1, 25996),
(19606, 0, 25996),
(18879, 0, 25996),
(21720, 0, 25996),
(19731, 0, 25996),
(16954, 0, 25996),
(18035, 0, 25996),
(23077, 0, 25996),
(23287, 0, 25996),
(18138, -1, 25996),
(18125, 0, 25996),
(19765, 0, 25996),
(18463, -1, 25996),
(19796, 0, 25996),
(1410, -1, 25996),
(18886, 1, 25996),
(21455, 0, 25996),
(24919, -1, 25996),
(20295, 0, 25996),
(19607, 0, 25996),
(19705, 0, 25996),
(19801, 0, 25996),
(21749, 0, 25996),
(21728, -1, 25996),
(22196, 1, 25996),
(18866, 1, 25996),
(18130, 0, 25996),
(18214, -1, 25996),
(18853, 0, 25996),
(20729, 0, 25996),
(20203, 0, 25996),
(21737, 0, 25996),
(21305, 0, 25996),
(22244, 0, 25996),
(22464, 0, 25996),
(20221, 0, 25996),
(20141, -1, 25996),
(20634, -1, 25996),
(19983, 1, 25996),
(16912, 0, 25996),
(20710, 0, 25996),
(18850, 0, 25996),
(21302, 0, 25996),
(19760, 1, 25996),
(20293, 0, 25996),
(20872, 0, 25996),
(18088, -1, 25996),
(21450, -1, 25996),
(20714, 0, 25996),
(21662, 0, 25996),
(21878, 0, 25996),
(12922, 0, 25996),
(21840, 0, 25996),
(18140, 0, 25996),
(21022, 1, 25996),
(18884, -1, 25996),
(19802, 1, 25996),
(17014, 1, 25996),
(18470, 0, 25996),
(18124, 0, 25996),
(18858, 0, 25996),
(20290, 1, 25996),
(19982, 0, 25996),
(18089, 0, 25996),
(16950, 0, 25996),
(20610, -1, 25996),
(19190, 0, 25996),
(21381, 0, 25996),
(21719, 0, 25996),
(19997, 0, 25996),
(20810, 0, 25996),
(22991, 0, 25996),
(20291, -1, 25996),
(19948, -1, 25996),
(22204, 0, 25996),
(22242, 0, 25996),
(21717, -1, 25996),
(19740, 1, 25996),
(18077, -1, 25996),
(19800, 0, 25996),
(21233, 0, 25996),
(20811, 0, 25996),
(18870, 0, 25996),
(19952, 1, 25996),
(18852, 1, 25996),
(21189, 1, 25996),
(21443, 0, 25996),
(21277, 0, 25996),
(20210, -1, 25996),
(21661, 0, 25996),
(22243, 1, 25996),
(22274, 0, 25996),
(18477, -1, 25996),
(19188, 0, 25996),
(23169, -1, 25996),
(18134, 0, 25996),
(21736, 0, 25996),
(18467, 0, 25996),
(19784, 0, 25996),
(21033, 0, 25996),
(20751, 1, 25996),
(21046, 1, 25996),
(18875, 0, 25996),
(19989, 0, 25996),
(22241, -1, 25996),
(20561, 0, 25996),
(23347, 0, 25996),
(16904, 1, 25996),
(20611, 1, 25996),
(20409, 0, 25996),
(18465, -1, 25996),
(16863, 1, 25996),
(18133, 0, 25996),
(21816, 0, 25996),
(16864, 1, 25996),
(20933, 0, 25996),
(21074, -1, 25996),
(19422, 0, 25996),
(20773, 1, 25996),
(16948, -1, 25996),
(22822, -1, 25996),
(16865, 0, 25996),
(18117, 0, 25996),
(20748, 0, 25996),
(21814, 2, 25996),
(21923, 1, 25996),
(19408, 0, 25996),
(20109, -4, 25996),
(21648, 0, 25996),
(21519, 0, 25996),
(16836, 0, 25996),
(21453, 0, 25996),
(21879, 0, 25996),
(21478, 1, 25996),
(21722, 0, 25996),
(19960, 0, 25996),
(22095, 1, 25996),
(22861, 0, 25996),
(19527, 0, 25996),
(16972, -1, 25996),
(22857, 0, 25996),
(20235, 0, 25996),
(20671, 1, 25996),
(21383, 0, 25996),
(18857, 0, 25996),
(22016, -1, 25996),
(20453, 1, 25996),
(23376, 0, 25996),
(19988, 1, 25996),
(18827, 0, 25996),
(18490, 1, 25996),
(21810, -1, 25996),
(19747, 0, 25996),
(22821, 0, 25996),
(20232, 1, 25996),
(17924, 0, 25996),
(21520, 0, 25996),
(20929, 0, 25996),
(20292, 0, 25996),
(21870, 0, 25996),
(16878, 0, 25996),
(20058, 0, 25996),
(22253, 0, 25996),
(20502, 0, 25996),
(23242, 0, 25996),
(23282, 1, 25996),
(16901, 1, 25996),
(18872, 0, 25996),
(21704, 0, 25996),
(21347, 0, 25996),
(17925, 0, 25996),
(19996, 0, 25996),
(18079, 0, 25996),
(21267, 0, 25996),
(21839, 0, 25996),
(16871, 0, 25996),
(18774, 0, 25996),
(18449, 0, 25996),
(21711, 0, 25996),
(18113, -1, 25996),
(19461, 0, 25996),
(19947, -1, 25996),
(20248, 1, 25996),
(18123, 0, 25996),
(20231, 0, 25996),
(18775, 0, 25996),
(17923, 0, 25996),
(19624, 1, 25996),
(20387, 1, 25996),
(23241, 0, 25996),
(23501, 0, 25996),
(19852, 1, 25996),
(21718, 0, 25996),
(19004, 0, 25996),
(20728, 0, 25996),
(21656, 0, 25996),
(16949, 0, 25996),
(18476, 1, 25996),
(18773, 0, 25996),
(16952, 0, 25996),
(18864, -1, 25996),
(20765, 0, 25996),
(18978, 0, 25996),
(19946, -1, 25996),
(20327, -4, 25996),
(21637, 0, 25996),
(18883, 0, 25996),
(20825, 0, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(19995, -1, 25996),
(19717, 0, 25996),
(21324, -1, 25996),
(19692, -1, 25996),
(22052, 1, 25996),
(20136, -1, 25996),
(21195, 0, 25996),
(22018, 0, 25996),
(24933, 0, 25996),
(18771, 0, 25996),
(21503, 0, 25996),
(21660, 1, 25996),
(18452, 0, 25996),
(21420, 0, 25996),
(21124, -1, 25996),
(20766, 0, 25996),
(21050, -1, 25996),
(20887, 0, 25996),
(22134, 0, 25996),
(20878, 1, 25996),
(18716, 0, 25996),
(19001, 0, 25996),
(20270, 0, 25996),
(20889, 0, 25996),
(23257, -1, 25996),
(21314, 0, 25996),
(19961, 0, 25996),
(18975, -1, 25996),
(20501, 1, 25996),
(21254, -1, 25996),
(21114, 1, 25996),
(20139, 0, 25996),
(22474, 0, 25996),
(20512, 0, 25996),
(18213, 0, 25996),
(16884, 0, 25996),
(16857, -1, 25996),
(16938, 0, 25996),
(19991, 0, 25996),
(22040, 0, 25996),
(20668, 0, 25996),
(19733, 0, 25996),
(23246, 0, 25996),
(16906, 1, 25996),
(16879, -1, 25996),
(16974, 1, 25996),
(22293, 0, 25996),
(22858, 0, 25996),
(17378, 0, 25996),
(18464, 0, 25996),
(22254, -1, 25996),
(21326, 0, 25996),
(18469, 0, 25996),
(22083, 0, 25996),
(22255, -1, 25996),
(23285, 1, 25996),
(20513, 1, 25996),
(20280, 0, 25996),
(16911, 1, 25996),
(21310, 0, 25996),
(21111, 1, 25996),
(20088, 0, 25996),
(18468, -1, 25996),
(22966, 2, 25996),
(21809, -1, 25996),
(21811, -1, 25996),
(20340, 1, 25996),
(23311, -1, 25996),
(18453, 1, 25996),
(18881, 1, 25996),
(22317, 0, 25996),
(21284, 0, 25996),
(20279, 1, 25996),
(16847, 0, 25996),
(18990, 0, 25996),
(24920, 0, 25996),
(23386, 0, 25996),
(21352, 0, 25996),
(21183, 0, 25996),
(19943, 1, 25996),
(16599, 0, 25996),
(19993, 0, 25996),
(19414, -1, 25996),
(22160, 1, 25996),
(21245, 0, 25996),
(22123, 0, 25996),
(23326, 0, 25996),
(21041, 0, 25996),
(21869, 0, 25996),
(24918, 0, 25996),
(19957, 0, 25996),
(18122, 1, 25996),
(20713, -1, 25996),
(19759, 0, 25996),
(20780, 0, 25996),
(21385, 1, 25996),
(21454, 1, 25996),
(18129, 0, 25996),
(18952, 0, 25996),
(22298, 1, 25996),
(19768, 0, 25996),
(19944, 1, 25996),
(21311, 0, 25996),
(19825, 0, 25996),
(16805, 1, 25996),
(21058, 1, 25996),
(23309, 0, 25996),
(21325, 1, 25996),
(18750, 1, 25996),
(21701, 0, 25996),
(19425, 1, 25996),
(21180, 0, 25996),
(19881, 0, 25996),
(18753, 0, 25996),
(19642, 0, 25996),
(21059, 0, 25996),
(19755, 1, 25996),
(22864, 0, 25996),
(20324, 0, 25996),
(20079, 0, 25996),
(20474, 1, 25996),
(22044, 0, 25996),
(19762, 0, 25996),
(22424, 0, 25996),
(20330, 0, 25996),
(20516, -1, 25996),
(16591, 0, 25996),
(20777, 0, 25996),
(21168, 0, 25996),
(20095, 0, 25996),
(20609, 1, 25996),
(16835, 0, 25996),
(19432, 0, 25996),
(21242, 0, 25996),
(20198, 1, 25996),
(20601, 1, 25996),
(19998, 1, 25996),
(22388, 0, 25996),
(21089, 0, 25996),
(21505, 0, 25996),
(21649, 0, 25996),
(16588, 0, 25996),
(19261, 0, 25996),
(19792, 0, 25996),
(21852, 0, 25996),
(18454, 0, 25996),
(18115, 1, 25996),
(16943, -1, 25996),
(21742, 1, 25996),
(16905, -1, 25996),
(18260, 0, 25996),
(16586, 0, 25996),
(18131, 1, 25996),
(21703, 0, 25996),
(35101, 0, 25996),
(18588, 1, 25996),
(16960, 1, 25996),
(20458, 1, 25996),
(21300, -1, 25996),
(19736, 0, 25996),
(19985, 1, 25996),
(17956, 0, 25996),
(21196, -1, 25996),
(21380, 0, 25996),
(19519, 0, 25996),
(20928, 0, 25996),
(35099, 0, 25996),
(16582, 0, 25996),
(22282, 0, 25996),
(16585, 0, 25996),
(21721, 0, 25996),
(20778, 0, 25996),
(16769, 1, 25996),
(18455, -1, 25996),
(18880, 0, 25996),
(20456, 1, 25996),
(19499, 2, 25996),
(20435, 0, 25996),
(20924, 0, 25996),
(20756, 0, 25996),
(21941, 0, 25996),
(19707, -1, 25996),
(20730, 0, 25996),
(16590, -1, 25996),
(18437, 0, 25996),
(22138, 0, 25996),
(20876, 0, 25996),
(19806, 0, 25996),
(21171, 0, 25996),
(18461, 0, 25996),
(19495, 0, 25996),
(20334, 1, 25996),
(16907, 0, 25996),
(21692, 0, 25996),
(19979, -1, 25996),
(19328, 0, 25996),
(19990, -1, 25996),
(23188, 0, 25996),
(23154, 0, 25996),
(21911, -1, 25996),
(20452, 1, 25996),
(22859, 0, 25996),
(21690, 0, 25996),
(20140, -1, 25996),
(21691, 0, 25996),
(18135, 0, 25996),
(16519, -1, 25996),
(16896, 0, 25996),
(19767, 0, 25996),
(21849, 0, 25996),
(20930, 0, 25996),
(20197, 0, 25996),
(16873, 1, 25996),
(19732, 1, 25996),
(21384, 0, 25996),
(21047, 0, 25996),
(22112, 0, 25996),
(19730, -1, 25996),
(20747, -1, 25996),
(16578, 0, 25996),
(18450, 0, 25996),
(23020, 0, 25996),
(20557, -1, 25996),
(21179, 0, 25996),
(20877, 0, 25996),
(19446, 0, 25996),
(19191, 1, 25996),
(16978, 0, 25996),
(19984, 0, 25996),
(21004, 0, 25996),
(18460, 1, 25996),
(19686, 1, 25996),
(19447, 0, 25996),
(19258, 1, 25996),
(18119, 0, 25996),
(18867, 1, 25996),
(22381, 0, 25996),
(23324, 0, 25996),
(18855, 0, 25996),
(21650, 0, 25996),
(20092, 0, 25996),
(20753, 0, 25996),
(16843, 0, 25996),
(21337, 0, 25996),
(19545, 0, 25996),
(18873, 0, 25996),
(18865, 0, 25996),
(22291, 0, 25996),
(20134, 0, 25996),
(18201, -5, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(16867, 0, 25996),
(18080, 0, 25996),
(20135, 0, 25996),
(18451, 0, 25996),
(20443, -1, 25996),
(21804, 0, 25996),
(19826, -1, 25996),
(21198, 0, 25996),
(19701, 0, 25996),
(20449, 0, 25996),
(20285, -1, 25996),
(19836, 0, 25996),
(19349, 0, 25996),
(23286, 0, 25996),
(19987, 0, 25996),
(16602, 0, 25996),
(18340, 1, 25996),
(17123, 0, 25996),
(21040, 1, 25996),
(16600, 0, 25996),
(21460, 1, 25996),
(21238, 1, 25996),
(19937, 0, 25996),
(21382, 1, 25996),
(19565, 0, 25996),
(16830, 0, 25996),
(22386, 0, 25996),
(19945, 1, 25996),
(22195, 1, 25996),
(18114, 1, 25996),
(21065, 0, 25996),
(20890, 0, 25996),
(19569, 0, 25996),
(21824, 0, 25996),
(16828, 0, 25996),
(21419, 1, 25996),
(20891, 0, 25996),
(19426, 1, 25996),
(18869, -1, 25996),
(20207, 0, 25996),
(22461, 0, 25996),
(22019, 0, 25996),
(16844, 0, 25996),
(21285, 1, 25996),
(17585, 0, 25996),
(16825, 0, 25996),
(23219, -1, 25996),
(19789, 0, 25996),
(20987, 0, 25996),
(18136, 0, 25996),
(20394, 0, 25996),
(19453, 0, 25996),
(22093, 0, 25996),
(22113, 0, 25996),
(19402, 0, 25996),
(21135, 0, 25996),
(18686, 2, 25996),
(35100, 0, 25996),
(20068, 0, 25996),
(22270, 0, 25996),
(17998, 0, 25996),
(21636, 0, 25996),
(22271, 0, 25996),
(22323, 0, 25996),
(21200, 1, 25996),
(20066, 0, 25996),
(21309, 0, 25996),
(20067, 0, 25996),
(20614, 1, 25996),
(19853, 0, 25996),
(22266, 0, 25996),
(18974, 0, 25996),
(19415, 0, 25996),
(22264, -1, 25996),
(21048, 0, 25996),
(23119, 0, 25996),
(17142, -1, 25996),
(19413, 1, 25996),
(21296, 0, 25996),
(16944, 1, 25996),
(17402, 0, 25996),
(19410, 1, 25996),
(35093, 0, 25996),
(18911, 0, 25996),
(18912, 0, 25996),
(16576, 0, 25996),
(18908, 0, 25996),
(22307, 0, 25996),
(19824, 0, 25996),
(19849, 0, 25996),
(18907, 0, 25996),
(22100, 0, 25996),
(20934, 0, 25996),
(21496, 0, 25996),
(18885, 0, 25996),
(21808, 0, 25996),
(19568, 0, 25996),
(18554, 0, 25996),
(21497, 0, 25996),
(21743, 0, 25996),
(49789, 0, 25996),
(18466, 1, 25996),
(20089, 0, 25996),
(19840, 0, 25996),
(16798, 0, 25996),
(16973, -1, 25996),
(16799, 0, 25996),
(20459, 0, 25996),
(19754, 0, 25996),
(16797, 0, 25996),
(21313, 1, 25996),
(24955, 0, 25996),
(21334, 0, 25996),
(21123, 1, 25996),
(19392, 0, 25996),
(18981, 0, 25996),
(20800, 1, 25996),
(19424, -1, 25996),
(20907, 0, 25996),
(18438, 0, 25996),
(19799, 0, 25996),
(18002, 0, 25996),
(19722, 0, 25996),
(21255, 0, 25996),
(18859, 0, 25996),
(20404, 0, 25996),
(21802, 0, 25996),
(22312, 0, 25996),
(19350, -1, 25996),
(21803, 0, 25996),
(20903, 0, 25996),
(21975, 0, 25996),
(20520, 0, 25996),
(20727, 0, 25996),
(20998, 0, 25996),
(19992, 1, 25996),
(20893, 0, 25996),
(17088, 0, 25996),
(21901, -1, 25996),
(21500, 0, 25996),
(19973, 0, 25996),
(21152, 0, 25996),
(22384, 1, 25996),
(21386, 0, 25996),
(21060, -1, 25996),
(22082, 1, 25996),
(18714, 0, 25996),
(21908, 0, 25996),
(22432, 0, 25996),
(22987, 0, 25996),
(18882, 2, 25996),
(22105, 0, 25996),
(22430, 0, 25996),
(19729, -1, 25996),
(22431, 0, 25996),
(18383, 0, 25996),
(18906, 0, 25996),
(16977, 0, 25996),
(21757, 0, 25996),
(18987, 0, 25996),
(16821, 0, 25996),
(21295, 0, 25996),
(21292, 0, 25996),
(19726, 0, 25996),
(21293, 0, 25996),
(18456, 0, 25996),
(21291, 0, 25996),
(18116, 1, 25996),
(19423, 0, 25996),
(19725, 0, 25996),
(20922, 0, 25996),
(20115, 0, 25996),
(22214, 0, 25996),
(16886, 0, 25996),
(21178, 0, 25996),
(20442, 0, 25996),
(19788, 0, 25996),
(20921, 0, 25996),
(23150, 0, 25996),
(21782, 0, 25996),
(18070, -1, 25996),
(22211, 0, 25996),
(20563, 0, 25996),
(18843, 0, 25996),
(19411, -1, 25996),
(22469, 0, 25996),
(22304, 0, 25996),
(18118, 1, 25996),
(20913, 0, 25996),
(23281, 1, 25996),
(22025, 0, 25996),
(19434, 0, 25996),
(23142, 1, 25996),
(21307, 0, 25996),
(20931, 0, 25996),
(21644, 0, 25996),
(21710, 0, 25996),
(22115, 0, 25996),
(18384, -1, 25996),
(18385, 1, 25996),
(20892, 0, 25996),
(20925, 1, 25996),
(22489, 0, 25996),
(20090, 1, 25996),
(19795, 0, 25996),
(19940, 1, 25996),
(21506, 0, 25996),
(3230, 0, 25996),
(22137, 0, 25996),
(16946, 1, 25996),
(21404, 0, 25996),
(22479, 0, 25996),
(21516, 0, 25996),
(16858, 1, 25996),
(21110, 0, 25996),
(16856, 0, 25996),
(19706, 0, 25996),
(20798, 0, 25996),
(19494, 0, 25996),
(20148, 1, 25996),
(18760, 0, 25996),
(16829, 0, 25996),
(19986, 1, 25996),
(16826, 0, 25996),
(20673, 1, 25996),
(18098, 0, 25996),
(20768, 0, 25996),
(18677, 2, 25996),
(16937, 1, 25996),
(16823, 0, 25996),
(20251, 0, 25996),
(16964, 0, 25996),
(20684, 0, 25996),
(19192, 0, 25996),
(20454, 0, 25996),
(19827, 0, 25996),
(16839, 0, 25996),
(21102, 0, 25996),
(21700, 0, 25996),
(20415, 0, 25996),
(18248, 0, 25996),
(20871, 0, 25996),
(24938, 0, 25996),
(18648, 1, 25996),
(21515, 1, 25996),
(16832, 0, 25996),
(20803, 0, 25996),
(16833, 0, 25996),
(19544, 0, 25996),
(22500, 0, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(19488, 0, 25996),
(19489, 0, 25996),
(16932, -1, 25996),
(18243, 1, 25996),
(20795, 1, 25996),
(21983, 0, 25996),
(22012, 0, 25996),
(21981, 0, 25996),
(19738, 0, 25996),
(20723, 0, 25996),
(22011, 0, 25996),
(19978, 0, 25996),
(20874, 0, 25996),
(24893, 0, 25996),
(20551, 0, 25996),
(20329, 0, 25996),
(19651, 0, 25996),
(17877, 0, 25996),
(20194, 0, 25996),
(22458, 0, 25996),
(23363, 0, 25996),
(19980, 0, 25996),
(18586, 1, 25996),
(20161, 0, 25996),
(23280, 0, 25996),
(18197, 0, 25996),
(19468, 0, 25996),
(19469, 0, 25996),
(19643, 0, 25996),
(18457, 1, 25996),
(19466, 0, 25996),
(22427, 0, 25996),
(19467, 0, 25996),
(21066, 0, 25996),
(18720, 0, 25996),
(21164, 0, 25996),
(16838, 0, 25996),
(20451, 2, 25996),
(21416, 0, 25996),
(20554, 0, 25996),
(16824, 0, 25996),
(20498, 0, 25996),
(20483, 0, 25996),
(16584, 0, 25996),
(22228, 0, 25996),
(20495, 0, 25996),
(19440, 0, 25996),
(19709, 0, 25996),
(23267, 0, 25996),
(19560, 0, 25996),
(20138, 0, 25996),
(19561, 0, 25996),
(22378, 0, 25996),
(20243, 0, 25996),
(23305, 0, 25996),
(22007, 0, 25996),
(16915, 0, 25996),
(20162, 0, 25996),
(21774, 0, 25996),
(21775, 0, 25996),
(21772, 0, 25996),
(21368, 0, 25996),
(21773, 0, 25996),
(18676, 0, 25996),
(21770, 0, 25996),
(21402, 0, 25996),
(22308, 0, 25996),
(21771, 0, 25996),
(51612, 0, 25996),
(21103, 0, 25996),
(20770, 0, 25996),
(21769, 0, 25996),
(22899, 0, 25996),
(23145, 0, 25996),
(23174, 0, 25996),
(21896, 0, 25996),
(20986, 0, 25996),
(21895, 0, 25996),
(66551, 0, 25996),
(18249, -1, 25996),
(19263, 0, 25996),
(21897, 0, 25996),
(18758, 0, 25996),
(19256, 0, 25996),
(21477, 0, 25996),
(21117, 0, 25996),
(29145, 0, 25996),
(19335, 0, 25996),
(20133, 0, 25996),
(18692, 2, 25996),
(19295, 0, 25996),
(17006, 1, 25996),
(21106, 0, 25996),
(30735, 0, 25996),
(17004, 0, 25996),
(21105, 0, 25996),
(17002, 1, 25996),
(22433, 0, 25996),
(115598, 0, 25996),
(22377, 0, 25996),
(21249, 0, 25996),
(16925, 1, 25996),
(18424, 0, 25996),
(19744, 0, 25996),
(18565, 1, 25996),
(19354, 0, 25996),
(30722, 0, 25996),
(23217, 1, 25996),
(21822, 0, 25996),
(23362, 0, 25996),
(18877, 0, 25996),
(19264, 1, 25996),
(22860, 0, 25996),
(19174, 1, 25996),
(22982, 0, 25996),
(20113, 0, 25996),
(47573, 0, 25996),
(19634, 0, 25996),
(21639, 0, 25996),
(18751, 0, 25996),
(19720, 1, 25996),
(18678, 2, 25996),
(18382, 0, 25996),
(23144, 0, 25996),
(18707, 1, 25996),
(20678, 0, 25996),
(20679, 0, 25996),
(23143, 0, 25996),
(20677, 0, 25996),
(19623, 0, 25996),
(21826, 0, 25996),
(23029, 1, 25996),
(19621, 0, 25996),
(20195, 0, 25996),
(20410, 0, 25996),
(19326, 0, 25996),
(18860, 0, 25996),
(22446, 0, 25996),
(18992, 1, 25996),
(23430, 0, 25996),
(18993, 0, 25996),
(115597, 0, 25996),
(20757, 1, 25996),
(22454, 0, 25996),
(21979, 0, 25996),
(21032, 0, 25996),
(16876, -1, 25996),
(18717, 0, 25996),
(18976, 0, 25996),
(21928, 0, 25996),
(21197, 0, 25996),
(22862, 0, 25996),
(17062, 0, 25996),
(21860, 0, 25996),
(21166, 0, 25996),
(21294, 1, 25996),
(22441, 1, 25996),
(19772, 0, 25996),
(22225, 0, 25996),
(21094, 0, 25996),
(18754, 0, 25996),
(18159, 1, 25996),
(21092, 0, 25996),
(21705, 0, 25996),
(18447, 0, 25996),
(20726, 0, 25996),
(21847, 0, 25996),
(22476, 0, 25996),
(19926, 0, 25996),
(21108, 0, 25996),
(20132, 0, 25996),
(19682, 0, 25996),
(19282, 0, 25996),
(16579, 0, 25996),
(18262, 0, 25996),
(16574, 0, 25996),
(17858, 1, 25996),
(18044, 1, 25996),
(21006, 0, 25996),
(16575, 0, 25996),
(19276, 0, 25996),
(17856, 0, 25996),
(18755, 0, 25996),
(19277, 0, 25996),
(22443, 0, 25996),
(23289, 0, 25996),
(20683, 1, 25996),
(21287, 0, 25996),
(20281, 0, 25996),
(23209, 0, 25996),
(21797, 3, 25996),
(20676, 0, 25996),
(19562, 0, 25996),
(19443, 0, 25996),
(16848, 0, 25996),
(22020, 0, 25996),
(20202, 0, 25996),
(18718, 0, 25996),
(22481, 0, 25996),
(19559, 0, 25996),
(23061, 1, 25996),
(19543, 0, 25996),
(18595, -1, 25996),
(16927, -1, 25996),
(17900, 0, 25996),
(18332, 0, 25996),
(17901, 0, 25996),
(20899, 0, 25996),
(20284, 0, 25996),
(17896, -1, 25996),
(21021, -1, 25996),
(20236, 0, 25996),
(19839, 0, 25996),
(22477, 1, 25996),
(21501, 0, 25996),
(18779, 0, 25996),
(20028, 0, 25996),
(16897, 0, 25996),
(18777, 0, 25996),
(19830, 1, 25996),
(18772, 0, 25996),
(19546, 0, 25996),
(19831, 0, 25996),
(22396, 0, 25996),
(23383, 0, 25996),
(19363, 0, 25996),
(22053, 0, 25996),
(19361, 0, 25996),
(19652, 0, 25996),
(18480, 0, 25996),
(21112, 1, 25996),
(17904, 0, 25996),
(20215, 0, 25996),
(21113, 0, 25996),
(115644, 0, 25996),
(21151, 0, 25996),
(21499, 0, 25996),
(30734, 0, 25996),
(21147, 0, 25996),
(21827, 0, 25996),
(21938, 0, 25996),
(20416, 0, 25996),
(23261, 1, 25996),
(18752, 0, 25996),
(20211, 0, 25996),
(18693, 2, 25996),
(19757, 0, 25996),
(30721, 0, 25996),
(19498, 1, 25996),
(19298, 0, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(19332, 0, 25996),
(21954, 0, 25996),
(19497, 0, 25996),
(21026, 0, 25996),
(21158, 0, 25996),
(21955, 0, 25996),
(21027, 1, 25996),
(21024, 0, 25996),
(21953, 0, 25996),
(19329, 0, 25996),
(24928, 0, 25996),
(19455, 0, 25996),
(18281, 1, 25996),
(47574, 0, 25996),
(18984, 2, 25996),
(19451, 0, 25996),
(20071, 0, 25996),
(18679, 2, 25996),
(18680, 2, 25996),
(17834, 0, 25996),
(18749, 0, 25996),
(21194, 0, 25996),
(20242, 0, 25996),
(21172, 0, 25996),
(21192, 0, 25996),
(20450, 0, 25996),
(21193, 0, 25996),
(19554, 0, 25996),
(20448, 0, 25996),
(21188, 0, 25996),
(19657, 0, 25996),
(19653, 0, 25996),
(22278, 0, 25996),
(23153, 0, 25996),
(22272, 0, 25996),
(22995, 0, 25996),
(20772, 0, 25996),
(16589, 0, 25996),
(17841, 0, 25996),
(18540, 1, 25996),
(19314, 0, 25996),
(23269, 0, 25996),
(19315, 0, 25996),
(21709, 0, 25996),
(19769, 1, 25996),
(18962, 0, 25996),
(16583, 0, 25996),
(20470, 0, 25996),
(20283, 0, 25996),
(18719, 0, 25996),
(16577, 0, 25996),
(20464, 0, 25996),
(20775, 0, 25996),
(19458, 0, 25996),
(20463, 0, 25996),
(18137, -1, 25996),
(19459, 0, 25996),
(22227, 0, 25996),
(22364, 0, 25996),
(20858, 0, 25996),
(18012, 0, 25996),
(18010, 0, 25996),
(21095, 0, 25996),
(17969, 0, 25996),
(18011, 0, 25996),
(24959, 2, 25996),
(18959, -2, 25996),
(18008, 0, 25996),
(18009, 0, 25996),
(22150, 0, 25996),
(18957, 0, 25996),
(22305, 0, 25996),
(21349, 0, 25996),
(18776, 0, 25996),
(19002, 1, 25996),
(19593, 0, 25996),
(18000, 0, 25996),
(22042, 0, 25996),
(22043, 0, 25996),
(19683, 0, 25996),
(21461, 1, 25996),
(20514, 0, 25996),
(19278, 0, 25996),
(20477, 0, 25996),
(19279, 0, 25996),
(18856, 0, 25996),
(21956, 0, 25996),
(18541, 1, 25996),
(22919, 0, 25996),
(19641, 0, 25996),
(18539, 0, 25996),
(18019, 0, 25996),
(18016, 0, 25996),
(18802, 0, 25996),
(17657, 0, 25996),
(18960, 1, 25996),
(22941, 0, 25996),
(22054, 1, 25996),
(18705, 0, 25996),
(21755, 0, 25996),
(19442, 0, 25996),
(20326, 0, 25996);


DELETE FROM `creature_model_info` WHERE `DisplayID`=76348;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(76348, 0.31, 1, 0, 25996);

UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20239;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21394;
UPDATE `creature_model_info` SET `BoundingRadius`=1.450575, `VerifiedBuild`=25996 WHERE `DisplayID`=17756;
UPDATE `creature_model_info` SET `BoundingRadius`=9.73917, `VerifiedBuild`=25996 WHERE `DisplayID`=21446;
UPDATE `creature_model_info` SET `BoundingRadius`=2.451555, `VerifiedBuild`=25996 WHERE `DisplayID`=21392;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21299;
UPDATE `creature_model_info` SET `BoundingRadius`=1.8742, `VerifiedBuild`=25996 WHERE `DisplayID`=19975;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21285;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21286;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21283;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21278;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21284;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21403;
UPDATE `creature_model_info` SET `BoundingRadius`=1.229807, `VerifiedBuild`=25996 WHERE `DisplayID`=19885;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21441;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21290;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21002;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21275;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21276;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21277;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21274;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21280;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21279;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21375;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21281;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21438;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=13470;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=21422;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21421;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21426;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21424;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20892;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=13475;
UPDATE `creature_model_info` SET `BoundingRadius`=6.020489, `VerifiedBuild`=25996 WHERE `DisplayID`=20896;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18281;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18284;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18285;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20893;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18282;
UPDATE `creature_model_info` SET `BoundingRadius`=0.923969, `VerifiedBuild`=25996 WHERE `DisplayID`=20068;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21412;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20891;
UPDATE `creature_model_info` SET `BoundingRadius`=1.24335, `VerifiedBuild`=25996 WHERE `DisplayID`=17760;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20890;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19400;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20500;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20499;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21316;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20508;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20502;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20493;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20507;
UPDATE `creature_model_info` SET `BoundingRadius`=7.304378, `VerifiedBuild`=25996 WHERE `DisplayID`=20811;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18272;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20596;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20494;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20126;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20130;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20122;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20132;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20131;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20336;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17287;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20134;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20133;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20756;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20335;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20337;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20758;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20757;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20124;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20339;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20340;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20341;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20338;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20434;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20387;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20803;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20800;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20435;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19487;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21128;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17409;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18775;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21127;
UPDATE `creature_model_info` SET `BoundingRadius`=10.57423, `VerifiedBuild`=25996 WHERE `DisplayID`=22742;
UPDATE `creature_model_info` SET `BoundingRadius`=6.093203, `VerifiedBuild`=25996 WHERE `DisplayID`=20306;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=20523;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20524;
UPDATE `creature_model_info` SET `BoundingRadius`=1.086314, `VerifiedBuild`=25996 WHERE `DisplayID`=20681;
UPDATE `creature_model_info` SET `BoundingRadius`=1.225, `CombatReach`=14, `VerifiedBuild`=25996 WHERE `DisplayID`=20522;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=20422;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20628;
UPDATE `creature_model_info` SET `BoundingRadius`=2.108624, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=2879;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19892;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20592;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17679;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=20478;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=20312;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9117899, `VerifiedBuild`=25996 WHERE `DisplayID`=20334;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21193;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20972;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19080;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19057;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18965;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21519;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20867;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18963;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20270;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17905;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20437;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18964;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20558;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19082;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19081;
UPDATE `creature_model_info` SET `BoundingRadius`=1.07757, `VerifiedBuild`=25996 WHERE `DisplayID`=20333;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19073;
UPDATE `creature_model_info` SET `BoundingRadius`=1.07757, `VerifiedBuild`=25996 WHERE `DisplayID`=20439;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20676;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20677;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20674;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20678;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19053;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19055;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18948;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18950;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20631;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18949;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20455;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18952;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20632;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20866;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18941;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21505;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20436;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20633;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18943;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18940;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18942;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19056;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19054;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20813;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20555;
UPDATE `creature_model_info` SET `BoundingRadius`=1.442608, `VerifiedBuild`=25996 WHERE `DisplayID`=19867;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20475;
UPDATE `creature_model_info` SET `BoundingRadius`=1.07757, `VerifiedBuild`=25996 WHERE `DisplayID`=20440;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19071;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14515;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20777;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20792;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20702;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20701;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20714;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20712;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20715;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20719;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20717;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20721;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20718;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20720;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20723;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20716;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20713;
UPDATE `creature_model_info` SET `BoundingRadius`=3.609312, `VerifiedBuild`=25996 WHERE `DisplayID`=20750;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20577;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20360;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19683;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20361;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20381;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20354;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20356;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20352;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20362;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20355;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20357;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20353;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20350;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20363;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20351;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20263;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20198;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20271;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15786;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20278;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20274;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20841;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18779;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18778;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18748;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7009;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20463;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17703;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7250;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18777;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12055;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12054;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17717;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17697;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18814;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20462;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18747;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18784;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18788;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17718;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18815;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22699;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18781;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18787;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20464;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18782;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18780;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20225;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20461;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036125, `VerifiedBuild`=25996 WHERE `DisplayID`=20610;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18752;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18749;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18789;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18790;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18751;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17202;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20444;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20446;
UPDATE `creature_model_info` SET `BoundingRadius`=2.049679, `VerifiedBuild`=25996 WHERE `DisplayID`=20191;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20443;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20445;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=169;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7029;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20304;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20303;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20234;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18621;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16889;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20301;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20302;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18750;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20233;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036125, `VerifiedBuild`=25996 WHERE `DisplayID`=20005;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20004;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20020;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20022;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16642;
UPDATE `creature_model_info` SET `BoundingRadius`=1.07757, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=20441;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19074;
UPDATE `creature_model_info` SET `CombatReach`=6, `VerifiedBuild`=25996 WHERE `DisplayID`=20521;
UPDATE `creature_model_info` SET `BoundingRadius`=3.722398, `VerifiedBuild`=25996 WHERE `DisplayID`=20039;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14518;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20136;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20006;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=19361;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=19364;
UPDATE `creature_model_info` SET `BoundingRadius`=3.606521, `VerifiedBuild`=25996 WHERE `DisplayID`=20238;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18657;
UPDATE `creature_model_info` SET `BoundingRadius`=1.07757, `VerifiedBuild`=25996 WHERE `DisplayID`=20280;
UPDATE `creature_model_info` SET `BoundingRadius`=1.316267, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=20146;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19075;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20294;
UPDATE `creature_model_info` SET `BoundingRadius`=1.431885, `VerifiedBuild`=25996 WHERE `DisplayID`=19366;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=20199;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20196;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14559;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17423;
UPDATE `creature_model_info` SET `BoundingRadius`=2.084895, `VerifiedBuild`=25996 WHERE `DisplayID`=20076;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=19363;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=19362;
UPDATE `creature_model_info` SET `BoundingRadius`=1.217102, `VerifiedBuild`=25996 WHERE `DisplayID`=19365;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=19360;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20864;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45923;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20273;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20272;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20276;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17055;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20293;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1313;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4356;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20244;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20117;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20459;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18734;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18732;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3865;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1866;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3869;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20115;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20460;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20458;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3866;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20116;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20457;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17719;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=782;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20228;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20114;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20113;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20612;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22894;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6308;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7248;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17721;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17720;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4048;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20450;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20118;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18213;
UPDATE `creature_model_info` SET `BoundingRadius`=5.788603, `VerifiedBuild`=25996 WHERE `DisplayID`=20751;
UPDATE `creature_model_info` SET `BoundingRadius`=5.705576, `VerifiedBuild`=25996 WHERE `DisplayID`=20509;
UPDATE `creature_model_info` SET `BoundingRadius`=5.145425, `VerifiedBuild`=25996 WHERE `DisplayID`=19715;
UPDATE `creature_model_info` SET `BoundingRadius`=2.498933, `VerifiedBuild`=25996 WHERE `DisplayID`=20920;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12817;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20221;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20220;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18887;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17312;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20449;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20447;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35802;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=45238;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4058979, `CombatReach`=0.8, `VerifiedBuild`=25996 WHERE `DisplayID`=45623;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62384;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=13210;
UPDATE `creature_model_info` SET `BoundingRadius`=0.245, `CombatReach`=0.7, `VerifiedBuild`=25996 WHERE `DisplayID`=45622;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20571;
UPDATE `creature_model_info` SET `BoundingRadius`=1.645334, `VerifiedBuild`=25996 WHERE `DisplayID`=19249;
UPDATE `creature_model_info` SET `BoundingRadius`=3.122293, `VerifiedBuild`=25996 WHERE `DisplayID`=20385;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8611;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20197;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20213;
UPDATE `creature_model_info` SET `BoundingRadius`=1.581468, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=2687;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12334;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20214;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19991;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18654;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18634;
UPDATE `creature_model_info` SET `BoundingRadius`=2.084895, `VerifiedBuild`=25996 WHERE `DisplayID`=5564;
UPDATE `creature_model_info` SET `BoundingRadius`=7.891044, `VerifiedBuild`=25996 WHERE `DisplayID`=21213;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20602;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20738;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18628;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17864;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21396;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20998;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17809;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=20660;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7804;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21018;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4067;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14707;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4629;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5265;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37744;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18825;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17811;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18826;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20165;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20744;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20190;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18073;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20189;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20187;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20183;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20185;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20186;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18824;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20188;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20184;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20754;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21031;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16379;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21023;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21038;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17216;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21044;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17248;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17906;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17869;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21032;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17650;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11546;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11551;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18012;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37578;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20152;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20137;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=20537;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20562;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20394;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20223;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36617;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20695;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=20961;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20563;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20396;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20391;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17860;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=338;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=252;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17806;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17805;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18127;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18109;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17985;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18120;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18113;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18122;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18133;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18112;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17981;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18111;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18130;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18132;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20767;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18097;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7935;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19144;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1404;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20755;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16491;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19581;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17440;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18616;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17494;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21056;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19335;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18618;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=20962;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16921;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16492;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9117899, `VerifiedBuild`=25996 WHERE `DisplayID`=21039;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20752;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4616;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18559;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18619;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21057;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21054;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21053;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20753;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36616;
UPDATE `creature_model_info` SET `CombatReach`=3.825, `VerifiedBuild`=25996 WHERE `DisplayID`=20617;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20348;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20790;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1192;
UPDATE `creature_model_info` SET `BoundingRadius`=6.763752, `VerifiedBuild`=25996 WHERE `DisplayID`=12929;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20288;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6351;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20534;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19998;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9929;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12165;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18444;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20145;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18421;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22717;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17730;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17731;
UPDATE `creature_model_info` SET `BoundingRadius`=0.386562, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=62616;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19523;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20140;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4559;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5706;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18095;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18087;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19028;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19036;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17735;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2577;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17807;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18415;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3737;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17734;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17636;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18484;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20141;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20143;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18483;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18216;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18106;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19983;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18206;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17958;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18827;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18200;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18205;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18199;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18207;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18196;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18198;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18203;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18202;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18208;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16633;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18201;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18197;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18042;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17812;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20025;
UPDATE `creature_model_info` SET `BoundingRadius`=1.3, `CombatReach`=1.625, `VerifiedBuild`=25996 WHERE `DisplayID`=11417;
UPDATE `creature_model_info` SET `BoundingRadius`=0.923969, `VerifiedBuild`=25996 WHERE `DisplayID`=19844;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17808;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5709223, `VerifiedBuild`=25996 WHERE `DisplayID`=18427;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17974;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5709223, `VerifiedBuild`=25996 WHERE `DisplayID`=18428;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16875;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17005;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17006;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8271;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17574;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17833;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17849;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17847;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17848;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17783;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17798;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45998;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17795;
UPDATE `creature_model_info` SET `BoundingRadius`=1.239677, `VerifiedBuild`=25996 WHERE `DisplayID`=18405;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22387;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22386;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22425;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18707;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18530;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18706;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18523;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18703;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18704;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18702;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18472;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21100;
UPDATE `creature_model_info` SET `BoundingRadius`=0.439171, `VerifiedBuild`=25996 WHERE `DisplayID`=11650;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14589;
UPDATE `creature_model_info` SET `BoundingRadius`=0.146088, `VerifiedBuild`=25996 WHERE `DisplayID`=14616;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20167;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1942875, `VerifiedBuild`=25996 WHERE `DisplayID`=19314;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19926;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18617;
UPDATE `creature_model_info` SET `BoundingRadius`=0.151157, `VerifiedBuild`=25996 WHERE `DisplayID`=19315;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18529;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18558;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18543;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19355;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19356;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18557;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21697;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22943;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21514;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29519;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19128;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20969;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22934;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22937;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22928;
UPDATE `creature_model_info` SET `BoundingRadius`=0.439171, `VerifiedBuild`=25996 WHERE `DisplayID`=152;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22927;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22940;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22941;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22924;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29518;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19795;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21572;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18769;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17892;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=56765;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37818;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18766;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36967;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23467;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36964;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36968;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=36966;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=36965;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19153;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37819;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18767;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37817;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18914;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36971;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36972;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17082;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22931;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22968;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22753;
UPDATE `creature_model_info` SET `BoundingRadius`=2.437281, `VerifiedBuild`=25996 WHERE `DisplayID`=17072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3020;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22752;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18018;
UPDATE `creature_model_info` SET `BoundingRadius`=7.311843, `VerifiedBuild`=25996 WHERE `DisplayID`=18135;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22955;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22763;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22952;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36947;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36949;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36950;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36946;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36945;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36951;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22762;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22957;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20659;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18528;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18550;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22953;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22757;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24730;
UPDATE `creature_model_info` SET `BoundingRadius`=2.437281, `VerifiedBuild`=25996 WHERE `DisplayID`=17870;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20290;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19132;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22956;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22747;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19130;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15874;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24731;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15871;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20169;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15873;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15870;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15863;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18743;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15876;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15294;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28803;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28809;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28799;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18552;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15865;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15869;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19160;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19159;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19156;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18475;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18733;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17867;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21573;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18735;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19794;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20766;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18516;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36970;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36969;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18519;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1141;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1418;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20818;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=856;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21522;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17859;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=857;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19091;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18021;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17191;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11873;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15534;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18518;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19354;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18489;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21504;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21524;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18517;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18480;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19092;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18544;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7346;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22414;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18022;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18027;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18044;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=221;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19129;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20170;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18025;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18026;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18625;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20168;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16878;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31984;
UPDATE `creature_model_info` SET `BoundingRadius`=0.504913, `CombatReach`=0.35, `VerifiedBuild`=25996 WHERE `DisplayID`=42553;
UPDATE `creature_model_info` SET `BoundingRadius`=0.923969, `VerifiedBuild`=25996 WHERE `DisplayID`=16631;
UPDATE `creature_model_info` SET `BoundingRadius`=3.606521, `VerifiedBuild`=25996 WHERE `DisplayID`=22734;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=19720;
UPDATE `creature_model_info` SET `BoundingRadius`=7.358223, `VerifiedBuild`=25996 WHERE `DisplayID`=18753;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=19721;
UPDATE `creature_model_info` SET `BoundingRadius`=0.39, `CombatReach`=1.3, `VerifiedBuild`=25996 WHERE `DisplayID`=18311;
UPDATE `creature_model_info` SET `BoundingRadius`=1.20116, `VerifiedBuild`=25996 WHERE `DisplayID`=20063;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20308;
UPDATE `creature_model_info` SET `BoundingRadius`=5.806284, `VerifiedBuild`=25996 WHERE `DisplayID`=18275;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16727;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18305;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16636;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18445;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18442;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17818;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17823;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17824;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16728;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17766;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18149;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16726;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18150;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18441;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17001;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18246;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16742;
UPDATE `creature_model_info` SET `BoundingRadius`=1.442608, `VerifiedBuild`=25996 WHERE `DisplayID`=19850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16396;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18500;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16867;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19643;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18498;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16402;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18497;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16401;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17089;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16743;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19644;
UPDATE `creature_model_info` SET `BoundingRadius`=4.099358, `VerifiedBuild`=25996 WHERE `DisplayID`=18371;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19384;
UPDATE `creature_model_info` SET `BoundingRadius`=2.759334, `VerifiedBuild`=25996 WHERE `DisplayID`=18373;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1145;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10029;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18686;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20761;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18857;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18864;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18690;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18863;
UPDATE `creature_model_info` SET `BoundingRadius`=1.217547, `CombatReach`=1.85, `VerifiedBuild`=25996 WHERE `DisplayID`=16572;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18679;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18859;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17081;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16634;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16523;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16522;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16741;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16520;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16506;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16519;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16521;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16518;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17445;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16392;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4054662, `VerifiedBuild`=25996 WHERE `DisplayID`=341;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17021;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14338;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14337;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14583;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29610;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29609;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17696;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17694;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16381;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16378;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16382;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14533;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1715;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16367;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16365;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16380;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16373;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16451;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17160;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18488;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18185;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18755;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2034823, `VerifiedBuild`=25996 WHERE `DisplayID`=31174;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18182;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16366;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18715;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16624;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18177;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16371;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16368;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20328;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16369;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20876;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18173;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18171;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18184;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18179;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27299;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27284;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16372;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35699;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18204;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16375;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18175;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16409;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16374;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16362;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16364;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16384;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16450;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16428;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16880;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16507;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16503;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16504;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18088;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16502;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16505;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16411;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18993;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18994;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4110;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19207;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1394;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19790;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18995;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18991;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18992;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18738;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19789;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16484;
UPDATE `creature_model_info` SET `BoundingRadius`=1.3, `CombatReach`=1.625, `VerifiedBuild`=25996 WHERE `DisplayID`=9562;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37576;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19345;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2352;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18851;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17741;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18852;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18849;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18835;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18739;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16390;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18729;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16387;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16418;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16388;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8610;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18878;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16480;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16420;
UPDATE `creature_model_info` SET `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=20044;
UPDATE `creature_model_info` SET `BoundingRadius`=27.01446, `VerifiedBuild`=25996 WHERE `DisplayID`=18684;
UPDATE `creature_model_info` SET `BoundingRadius`=2.146957, `VerifiedBuild`=25996 WHERE `DisplayID`=19196;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18953;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18893;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20740;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20741;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15455;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20742;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10215;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18892;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18890;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3336;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3337;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3167;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18443;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18889;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16377;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18453;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16376;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18457;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16419;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14615;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14614;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18409;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15577;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15578;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2306;
UPDATE `creature_model_info` SET `CombatReach`=4.5, `VerifiedBuild`=25996 WHERE `DisplayID`=18531;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4601;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18668;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15579;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18408;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5446;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15574;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4260;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18345;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18455;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18669;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16298;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19792;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1377;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1602;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18665;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4602;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4259;
UPDATE `creature_model_info` SET `BoundingRadius`=15.43627, `VerifiedBuild`=25996 WHERE `DisplayID`=18622;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1987;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16389;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16370;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21064;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18666;
UPDATE `creature_model_info` SET `BoundingRadius`=1.8742, `VerifiedBuild`=25996 WHERE `DisplayID`=18419;
UPDATE `creature_model_info` SET `BoundingRadius`=1.401479, `VerifiedBuild`=25996 WHERE `DisplayID`=6172;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9129;
UPDATE `creature_model_info` SET `CombatReach`=2.25, `VerifiedBuild`=25996 WHERE `DisplayID`=20045;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21342;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1814;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18712;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18694;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18730;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16284;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16316;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16317;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18861;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18865;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18862;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16479;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21025;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18866;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18854;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19148;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18855;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18675;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18673;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18674;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18678;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18677;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16304;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16320;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36625;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18172;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20875;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18151;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18186;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18486;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18176;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16303;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29608;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16302;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29603;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=207;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2326;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17700;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17701;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17699;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1166;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16307;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16297;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16308;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16306;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16299;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16287;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16301;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18672;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16288;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7051;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16286;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16285;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16312;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16289;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17111;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16281;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18181;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16300;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16310;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20128;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1872;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16283;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16292;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16305;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6093389, `CombatReach`=0.75, `VerifiedBuild`=25996 WHERE `DisplayID`=850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4177;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18183;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16296;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18180;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16294;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27300;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27285;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35698;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16295;
UPDATE `creature_model_info` SET `BoundingRadius`=0.21, `CombatReach`=0.9, `VerifiedBuild`=25996 WHERE `DisplayID`=15227;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16468;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1913;
UPDATE `creature_model_info` SET `BoundingRadius`=1.08592, `VerifiedBuild`=25996 WHERE `DisplayID`=18701;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20047;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17457;
UPDATE `creature_model_info` SET `BoundingRadius`=2.050334, `VerifiedBuild`=25996 WHERE `DisplayID`=17210;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1986;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15303;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10906;
UPDATE `creature_model_info` SET `BoundingRadius`=6.846691, `VerifiedBuild`=25996 WHERE `DisplayID`=18816;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10070;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18832;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9872003, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=11410;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18731;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16449;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21065;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18817;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18819;
UPDATE `creature_model_info` SET `BoundingRadius`=10.20369, `CombatReach`=18, `VerifiedBuild`=25996 WHERE `DisplayID`=16630;
UPDATE `creature_model_info` SET `BoundingRadius`=3.345456, `VerifiedBuild`=25996 WHERE `DisplayID`=18820;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18818;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22843;
UPDATE `creature_model_info` SET `BoundingRadius`=5.518667, `VerifiedBuild`=25996 WHERE `DisplayID`=20919;
UPDATE `creature_model_info` SET `BoundingRadius`=1.048144, `VerifiedBuild`=25996 WHERE `DisplayID`=22979;
UPDATE `creature_model_info` SET `BoundingRadius`=1.522117, `VerifiedBuild`=25996 WHERE `DisplayID`=22748;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19675;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19896;
UPDATE `creature_model_info` SET `BoundingRadius`=2.974485, `VerifiedBuild`=25996 WHERE `DisplayID`=19891;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19648;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19629;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19628;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19653;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19631;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19739;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19635;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19632;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19681;
UPDATE `creature_model_info` SET `BoundingRadius`=148.8307, `VerifiedBuild`=25996 WHERE `DisplayID`=18997;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9832;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20011;
UPDATE `creature_model_info` SET `BoundingRadius`=4.13567, `VerifiedBuild`=25996 WHERE `DisplayID`=19272;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8834;
UPDATE `creature_model_info` SET `BoundingRadius`=37.20769, `VerifiedBuild`=25996 WHERE `DisplayID`=18685;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18050;
UPDATE `creature_model_info` SET `BoundingRadius`=2.86261, `VerifiedBuild`=25996 WHERE `DisplayID`=18990;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16946;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19540;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21103;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19695;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21102;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18998;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19638;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19637;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19774;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15380;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19657;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19633;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19782;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17903;
UPDATE `creature_model_info` SET `BoundingRadius`=1.249467, `VerifiedBuild`=25996 WHERE `DisplayID`=19586;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19513;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19578;
UPDATE `creature_model_info` SET `BoundingRadius`=3.075502, `VerifiedBuild`=25996 WHERE `DisplayID`=18646;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19512;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19511;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20060;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20061;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19514;
UPDATE `creature_model_info` SET `BoundingRadius`=3.679111, `VerifiedBuild`=25996 WHERE `DisplayID`=19200;
UPDATE `creature_model_info` SET `BoundingRadius`=5.7391, `VerifiedBuild`=25996 WHERE `DisplayID`=19358;
UPDATE `creature_model_info` SET `CombatReach`=3.75, `VerifiedBuild`=25996 WHERE `DisplayID`=18525;
UPDATE `creature_model_info` SET `BoundingRadius`=2.498933, `VerifiedBuild`=25996 WHERE `DisplayID`=19912;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19917;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19626;
UPDATE `creature_model_info` SET `BoundingRadius`=2.5, `CombatReach`=7.5, `VerifiedBuild`=25996 WHERE `DisplayID`=5238;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17446;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8198715, `VerifiedBuild`=25996 WHERE `DisplayID`=19359;
UPDATE `creature_model_info` SET `BoundingRadius`=2.988312, `VerifiedBuild`=25996 WHERE `DisplayID`=19579;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19293;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19414;
UPDATE `creature_model_info` SET `BoundingRadius`=7.846331, `VerifiedBuild`=25996 WHERE `DisplayID`=19458;
UPDATE `creature_model_info` SET `BoundingRadius`=2.498933, `VerifiedBuild`=25996 WHERE `DisplayID`=18699;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18448;
UPDATE `creature_model_info` SET `BoundingRadius`=4.652997, `VerifiedBuild`=25996 WHERE `DisplayID`=19456;
UPDATE `creature_model_info` SET `BoundingRadius`=9.128922, `VerifiedBuild`=25996 WHERE `DisplayID`=19899;
UPDATE `creature_model_info` SET `BoundingRadius`=3.679111, `VerifiedBuild`=25996 WHERE `DisplayID`=20606;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21132;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19654;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19776;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19655;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19957;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19955;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18660;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19881;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19956;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19417;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19421;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17647;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19960;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37779;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19779;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19775;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17689;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17685;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19904;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19161;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19771;
UPDATE `creature_model_info` SET `BoundingRadius`=6.003141, `VerifiedBuild`=25996 WHERE `DisplayID`=18370;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19593;
UPDATE `creature_model_info` SET `BoundingRadius`=4.564461, `VerifiedBuild`=25996 WHERE `DisplayID`=19035;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19189;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20101;
UPDATE `creature_model_info` SET `BoundingRadius`=2.003105, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=19690;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19150;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19446;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19464;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19463;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19465;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19084;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19459;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19460;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20095;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19444;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19445;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19443;
UPDATE `creature_model_info` SET `BoundingRadius`=0.65, `CombatReach`=1.3, `VerifiedBuild`=25996 WHERE `DisplayID`=19704;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21062;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21051;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21061;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21060;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21045;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19979;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7919;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19610;
UPDATE `creature_model_info` SET `BoundingRadius`=0.462922, `VerifiedBuild`=25996 WHERE `DisplayID`=5050;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18972;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19602;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19601;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5555;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18971;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18973;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5556;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20050;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18978;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5585;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19301;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19284;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18927;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18928;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19664;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19641;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19918;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19919;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5586;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19642;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19603;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20043;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19239;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17773;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17776;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19441;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19439;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19440;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19442;
UPDATE `creature_model_info` SET `BoundingRadius`=1.201863, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=19288;
UPDATE `creature_model_info` SET `BoundingRadius`=1.201863, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=19285;
UPDATE `creature_model_info` SET `BoundingRadius`=1.201863, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=18274;
UPDATE `creature_model_info` SET `BoundingRadius`=1.201863, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=19287;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19238;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4960;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19237;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19003;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19120;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19492;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19209;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19210;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19453;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19202;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19205;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19491;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19119;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19452;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19468;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19466;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19467;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19469;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18848;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19502;
UPDATE `creature_model_info` SET `BoundingRadius`=8.503078, `CombatReach`=15, `VerifiedBuild`=25996 WHERE `DisplayID`=19501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19461;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19201;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19490;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19123;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19488;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20096;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19115;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19118;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15438;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19116;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19462;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19117;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19450;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19489;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19451;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19449;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19125;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19126;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19122;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19493;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19496;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19495;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19124;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19121;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19494;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19650;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20985;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19916;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17054;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8612;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6173;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16269;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18700;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19357;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19203;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39831;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20171;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25624;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20428;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19197;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18967;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20430;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20429;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7098;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10746;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19580;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10742;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18174;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19151;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19660;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19046;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37716;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70200;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=13069;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20438;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40011;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21462;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70198;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27942;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70195;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19079;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23768;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29078;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20326;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10743;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19000;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=50854;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1122;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19645;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11375;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20906;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20905;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19038;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19076;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19043;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19340;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18661;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7341;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11376;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19198;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19343;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19167;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18920;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20518;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19047;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22780;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18906;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18905;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18903;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20622;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17907;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17904;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18966;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19077;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17138;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11377;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18017;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18016;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7099;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18968;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18969;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19524;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3027803, `VerifiedBuild`=25996 WHERE `DisplayID`=8189;
UPDATE `creature_model_info` SET `BoundingRadius`=2.791799, `VerifiedBuild`=25996 WHERE `DisplayID`=19662;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19672;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19099;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19102;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20035;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19107;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19103;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19106;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20031;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20034;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19101;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19100;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19104;
UPDATE `creature_model_info` SET `BoundingRadius`=0.42649, `VerifiedBuild`=25996 WHERE `DisplayID`=2177;
UPDATE `creature_model_info` SET `BoundingRadius`=0.45, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=19416;
UPDATE `creature_model_info` SET `BoundingRadius`=3.606521, `VerifiedBuild`=25996 WHERE `DisplayID`=17716;
UPDATE `creature_model_info` SET `BoundingRadius`=2.003105, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=19435;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18999;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19419;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19418;
UPDATE `creature_model_info` SET `BoundingRadius`=0.08000001, `CombatReach`=0.2, `VerifiedBuild`=25996 WHERE `DisplayID`=45953;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1204;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16877;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19961;
UPDATE `creature_model_info` SET `BoundingRadius`=3.931172, `VerifiedBuild`=25996 WHERE `DisplayID`=19486;
UPDATE `creature_model_info` SET `BoundingRadius`=1.936947, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=18193;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19730;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19742;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20094;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19634;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19772;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19692;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20987;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20926;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20074;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20073;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21033;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20827;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20056;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20058;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20928;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20829;
UPDATE `creature_model_info` SET `BoundingRadius`=1.311124, `VerifiedBuild`=25996 WHERE `DisplayID`=20808;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20054;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20825;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21059;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21055;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21052;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21058;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20055;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20053;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20830;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20059;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20824;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20057;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21035;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20052;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20051;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17834;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7898;
UPDATE `creature_model_info` SET `BoundingRadius`=4.002094, `VerifiedBuild`=25996 WHERE `DisplayID`=19168;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17188;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19368;
UPDATE `creature_model_info` SET `BoundingRadius`=2.676365, `VerifiedBuild`=25996 WHERE `DisplayID`=18505;
UPDATE `creature_model_info` SET `BoundingRadius`=4.919229, `VerifiedBuild`=25996 WHERE `DisplayID`=20533;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20842;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17876;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19190;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20838;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=73904;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17868;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20839;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2421;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20158;
UPDATE `creature_model_info` SET `BoundingRadius`=2.757113, `VerifiedBuild`=25996 WHERE `DisplayID`=19980;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20075;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20078;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20112;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20086;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20079;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20080;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20111;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20083;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20418;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20520;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20077;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20442;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20325;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20332;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20084;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20082;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20092;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20331;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19785;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17200;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20088;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `VerifiedBuild`=25996 WHERE `DisplayID`=15435;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20024;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47021;
UPDATE `creature_model_info` SET `BoundingRadius`=1.20116, `VerifiedBuild`=25996 WHERE `DisplayID`=17086;
UPDATE `creature_model_info` SET `BoundingRadius`=1.478351, `VerifiedBuild`=25996 WHERE `DisplayID`=20965;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20531;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18915;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18898;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18909;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18918;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20192;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18907;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18912;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20215;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21398;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20091;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20110;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18917;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9492;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17635;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20209;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18911;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19208;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18913;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20210;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20207;
UPDATE `creature_model_info` SET `BoundingRadius`=1.484768, `VerifiedBuild`=25996 WHERE `DisplayID`=20918;
UPDATE `creature_model_info` SET `BoundingRadius`=4.482468, `VerifiedBuild`=25996 WHERE `DisplayID`=20532;
UPDATE `creature_model_info` SET `BoundingRadius`=2.797071, `VerifiedBuild`=25996 WHERE `DisplayID`=20417;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20634;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17094;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9370;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20193;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1712;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10582;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2055;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21034;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20149;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20150;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=876;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4404;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4843;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20038;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20121;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4841;
UPDATE `creature_model_info` SET `BoundingRadius`=4.509168, `VerifiedBuild`=25996 WHERE `DisplayID`=2429;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17524;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4842;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4844;
UPDATE `creature_model_info` SET `BoundingRadius`=2.209087, `CombatReach`=3.3, `VerifiedBuild`=25996 WHERE `DisplayID`=73882;
UPDATE `creature_model_info` SET `BoundingRadius`=2.142013, `CombatReach`=3.75, `VerifiedBuild`=25996 WHERE `DisplayID`=73881;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20240;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11550;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20657;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20181;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19756;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19762;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19758;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15774;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19765;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12044;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2232;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20871;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20700;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2220;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20680;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20081;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `VerifiedBuild`=25996 WHERE `DisplayID`=16925;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4249;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=257;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7999;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21136;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5441;
UPDATE `creature_model_info` SET `BoundingRadius`=1.390289, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=2160;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8666;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=13672;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5814922, `VerifiedBuild`=25996 WHERE `DisplayID`=13673;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20840;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20836;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16876;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19606;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20679;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=347;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20898;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19661;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20895;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20894;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21494;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21493;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=21498;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21294;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21495;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4092, `CombatReach`=1.65, `VerifiedBuild`=25996 WHERE `DisplayID`=21295;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21487;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16890;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7816;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3264;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20901;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20989;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20486;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11544;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18070;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20762;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4585;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20093;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11583;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18358;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45899;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17782;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19755;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19531;
UPDATE `creature_model_info` SET `BoundingRadius`=0.525, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=19770;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20329;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20970;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9517255, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=29440;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10045;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20482;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2205, `CombatReach`=0.945, `VerifiedBuild`=25996 WHERE `DisplayID`=9535;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20481;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20485;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9532348, `VerifiedBuild`=25996 WHERE `DisplayID`=20483;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20487;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20484;
UPDATE `creature_model_info` SET `CombatReach`=1.95, `VerifiedBuild`=25996 WHERE `DisplayID`=20982;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2205, `CombatReach`=0.945, `VerifiedBuild`=25996 WHERE `DisplayID`=20843;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20480;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19604;
UPDATE `creature_model_info` SET `BoundingRadius`=20, `CombatReach`=20, `VerifiedBuild`=25996 WHERE `DisplayID`=12051;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20018;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20017;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4626;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20258;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20379;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20256;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=20254;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20257;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20252;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20604;
UPDATE `creature_model_info` SET `BoundingRadius`=1.043395, `VerifiedBuild`=25996 WHERE `DisplayID`=397;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20378;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2186544, `VerifiedBuild`=25996 WHERE `DisplayID`=134;
UPDATE `creature_model_info` SET `BoundingRadius`=4.509168, `VerifiedBuild`=25996 WHERE `DisplayID`=20249;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20250;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20013;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20251;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20711;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20204;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20202;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14430;
UPDATE `creature_model_info` SET `BoundingRadius`=3.7484, `VerifiedBuild`=25996 WHERE `DisplayID`=20855;
UPDATE `creature_model_info` SET `BoundingRadius`=0.875, `VerifiedBuild`=25996 WHERE `DisplayID`=20853;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21307;
UPDATE `creature_model_info` SET `BoundingRadius`=13.60493, `CombatReach`=24, `VerifiedBuild`=25996 WHERE `DisplayID`=18671;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20203;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21258;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21459;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21414;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21183;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21182;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21480;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21169;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21415;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=21499;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21194;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20206;
UPDATE `creature_model_info` SET `BoundingRadius`=2.260511, `VerifiedBuild`=25996 WHERE `DisplayID`=21156;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=21184;
UPDATE `creature_model_info` SET `BoundingRadius`=2.260511, `VerifiedBuild`=25996 WHERE `DisplayID`=21158;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19595;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8574;
UPDATE `creature_model_info` SET `BoundingRadius`=0.938, `CombatReach`=1.4, `VerifiedBuild`=25996 WHERE `DisplayID`=47206;
UPDATE `creature_model_info` SET `BoundingRadius`=1.809, `CombatReach`=2.7, `VerifiedBuild`=25996 WHERE `DisplayID`=47204;
UPDATE `creature_model_info` SET `BoundingRadius`=1.809, `CombatReach`=2.7, `VerifiedBuild`=25996 WHERE `DisplayID`=47205;
UPDATE `creature_model_info` SET `BoundingRadius`=1.809, `CombatReach`=2.7, `VerifiedBuild`=25996 WHERE `DisplayID`=47203;
UPDATE `creature_model_info` SET `BoundingRadius`=2.345, `CombatReach`=3.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47210;
UPDATE `creature_model_info` SET `BoundingRadius`=2.01, `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=47196;
UPDATE `creature_model_info` SET `BoundingRadius`=1.809, `CombatReach`=2.7, `VerifiedBuild`=25996 WHERE `DisplayID`=47209;
UPDATE `creature_model_info` SET `BoundingRadius`=1.809, `CombatReach`=2.7, `VerifiedBuild`=25996 WHERE `DisplayID`=47202;
UPDATE `creature_model_info` SET `BoundingRadius`=1.809, `CombatReach`=2.7, `VerifiedBuild`=25996 WHERE `DisplayID`=47195;
UPDATE `creature_model_info` SET `BoundingRadius`=2.01, `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=47194;
UPDATE `creature_model_info` SET `BoundingRadius`=1.809, `CombatReach`=2.7, `VerifiedBuild`=25996 WHERE `DisplayID`=47208;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21405;
UPDATE `creature_model_info` SET `BoundingRadius`=0.938, `CombatReach`=1.4, `VerifiedBuild`=25996 WHERE `DisplayID`=47207;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12869;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15470;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24139;
UPDATE `creature_model_info` SET `BoundingRadius`=2.298332, `VerifiedBuild`=25996 WHERE `DisplayID`=21234;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4268;
UPDATE `creature_model_info` SET `BoundingRadius`=4.100669, `VerifiedBuild`=25996 WHERE `DisplayID`=18368;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18288;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15469;
UPDATE `creature_model_info` SET `BoundingRadius`=0.45, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=21282;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15471;
UPDATE `creature_model_info` SET `BoundingRadius`=4.313914, `VerifiedBuild`=25996 WHERE `DisplayID`=18139;
UPDATE `creature_model_info` SET `BoundingRadius`=1.645334, `VerifiedBuild`=25996 WHERE `DisplayID`=20831;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12231;
UPDATE `creature_model_info` SET `BoundingRadius`=4.598889, `VerifiedBuild`=25996 WHERE `DisplayID`=17095;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21343;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18434;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18485;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15880;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17858;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20730;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19605;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `BoundingRadius`=1.311124, `VerifiedBuild`=25996 WHERE `DisplayID`=19705;
UPDATE `creature_model_info` SET `BoundingRadius`=2.891181, `VerifiedBuild`=25996 WHERE `DisplayID`=19728;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17835;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5905;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10708;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36544;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11549;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19347;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19905;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20208;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19476;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19477;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31771;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=17955;
UPDATE `creature_model_info` SET `BoundingRadius`=1.217102, `VerifiedBuild`=25996 WHERE `DisplayID`=17952;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=17951;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18312;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11419;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587565, `VerifiedBuild`=25996 WHERE `DisplayID`=10920;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5050466, `VerifiedBuild`=25996 WHERE `DisplayID`=18425;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16975;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18320;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17529;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17285;
UPDATE `creature_model_info` SET `BoundingRadius`=16, `CombatReach`=16, `VerifiedBuild`=25996 WHERE `DisplayID`=17310;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21106;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20621;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21119;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17767;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10916;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17319;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17313;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18306;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10564;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20618;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17320;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17274;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2200;
UPDATE `creature_model_info` SET `BoundingRadius`=0.124, `CombatReach`=0.4, `VerifiedBuild`=25996 WHERE `DisplayID`=75132;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17275;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20620;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20619;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10726;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18308;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17630;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18309;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17414;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17415;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17419;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17426;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19678;
UPDATE `creature_model_info` SET `BoundingRadius`=2.135722, `VerifiedBuild`=25996 WHERE `DisplayID`=19687;
UPDATE `creature_model_info` SET `BoundingRadius`=2.990011, `VerifiedBuild`=25996 WHERE `DisplayID`=18823;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=19404;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9288539, `VerifiedBuild`=25996 WHERE `DisplayID`=17753;
UPDATE `creature_model_info` SET `BoundingRadius`=1.217102, `VerifiedBuild`=25996 WHERE `DisplayID`=17582;
UPDATE `creature_model_info` SET `BoundingRadius`=3.613118, `VerifiedBuild`=25996 WHERE `DisplayID`=18313;
UPDATE `creature_model_info` SET `BoundingRadius`=1.708019, `VerifiedBuild`=25996 WHERE `DisplayID`=9011;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31773;
UPDATE `creature_model_info` SET `BoundingRadius`=0.439171, `VerifiedBuild`=25996 WHERE `DisplayID`=11653;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5050466, `VerifiedBuild`=25996 WHERE `DisplayID`=18423;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19405;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5050466, `VerifiedBuild`=25996 WHERE `DisplayID`=18424;
UPDATE `creature_model_info` SET `BoundingRadius`=1.496487, `VerifiedBuild`=25996 WHERE `DisplayID`=17751;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17781;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=705;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18314;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18307;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=19297;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17588;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17585;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19158;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17436;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17680;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17422;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18330;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18723;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11576;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18331;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11559;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5709223, `VerifiedBuild`=25996 WHERE `DisplayID`=18620;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19906;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20173;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11533;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17612;
UPDATE `creature_model_info` SET `BoundingRadius`=1.264376, `VerifiedBuild`=25996 WHERE `DisplayID`=11255;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7297132, `VerifiedBuild`=25996 WHERE `DisplayID`=4606;
UPDATE `creature_model_info` SET `BoundingRadius`=0.439171, `VerifiedBuild`=25996 WHERE `DisplayID`=18422;
UPDATE `creature_model_info` SET `BoundingRadius`=3.973071, `VerifiedBuild`=25996 WHERE `DisplayID`=19658;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9117899, `VerifiedBuild`=25996 WHERE `DisplayID`=17609;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=17954;
UPDATE `creature_model_info` SET `BoundingRadius`=1.986535, `VerifiedBuild`=25996 WHERE `DisplayID`=17106;
UPDATE `creature_model_info` SET `BoundingRadius`=1.217102, `VerifiedBuild`=25996 WHERE `DisplayID`=17953;
UPDATE `creature_model_info` SET `BoundingRadius`=1.986535, `VerifiedBuild`=25996 WHERE `DisplayID`=17107;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19163;
UPDATE `creature_model_info` SET `BoundingRadius`=1.05, `CombatReach`=9, `VerifiedBuild`=25996 WHERE `DisplayID`=45045;
UPDATE `creature_model_info` SET `BoundingRadius`=0.062, `CombatReach`=0.2, `VerifiedBuild`=25996 WHERE `DisplayID`=45616;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=0.5, `VerifiedBuild`=25996 WHERE `DisplayID`=45614;
UPDATE `creature_model_info` SET `BoundingRadius`=0.07, `CombatReach`=0.6, `VerifiedBuild`=25996 WHERE `DisplayID`=45615;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=45231;
UPDATE `creature_model_info` SET `BoundingRadius`=1.708578, `VerifiedBuild`=25996 WHERE `DisplayID`=18228;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17627;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18323;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2958;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4, `CombatReach`=0.4, `VerifiedBuild`=25996 WHERE `DisplayID`=42554;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=901;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6297;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17626;
UPDATE `creature_model_info` SET `BoundingRadius`=1.986535, `VerifiedBuild`=25996 WHERE `DisplayID`=17101;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18075;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6303;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19408;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16879;
UPDATE `creature_model_info` SET `BoundingRadius`=2.562867, `VerifiedBuild`=25996 WHERE `DisplayID`=18449;
UPDATE `creature_model_info` SET `BoundingRadius`=2.990011, `VerifiedBuild`=25996 WHERE `DisplayID`=19164;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17695;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1206;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19252;
UPDATE `creature_model_info` SET `BoundingRadius`=1.806105, `VerifiedBuild`=25996 WHERE `DisplayID`=17752;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6295;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2957;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18615;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1924;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19401;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=22253 AND `ID`=3) OR (`CreatureID`=22253 AND `ID`=2) OR (`CreatureID`=23146 AND `ID`=6) OR (`CreatureID`=23146 AND `ID`=5) OR (`CreatureID`=23146 AND `ID`=4) OR (`CreatureID`=23146 AND `ID`=3) OR (`CreatureID`=23146 AND `ID`=2) OR (`CreatureID`=21717 AND `ID`=7) OR (`CreatureID`=21717 AND `ID`=6) OR (`CreatureID`=21717 AND `ID`=5) OR (`CreatureID`=21717 AND `ID`=4) OR (`CreatureID`=21717 AND `ID`=3) OR (`CreatureID`=21717 AND `ID`=2) OR (`CreatureID`=21717 AND `ID`=1) OR (`CreatureID`=21742 AND `ID`=2) OR (`CreatureID`=22018 AND `ID`=5) OR (`CreatureID`=22018 AND `ID`=4) OR (`CreatureID`=22018 AND `ID`=3) OR (`CreatureID`=22016 AND `ID`=4) OR (`CreatureID`=22018 AND `ID`=2) OR (`CreatureID`=22016 AND `ID`=3) OR (`CreatureID`=22016 AND `ID`=2) OR (`CreatureID`=19806 AND `ID`=3) OR (`CreatureID`=19792 AND `ID`=8) OR (`CreatureID`=19792 AND `ID`=7) OR (`CreatureID`=19792 AND `ID`=6) OR (`CreatureID`=19806 AND `ID`=2) OR (`CreatureID`=19792 AND `ID`=5) OR (`CreatureID`=19792 AND `ID`=4) OR (`CreatureID`=19792 AND `ID`=3) OR (`CreatureID`=19792 AND `ID`=2) OR (`CreatureID`=19384 AND `ID`=2) OR (`CreatureID`=19765 AND `ID`=2) OR (`CreatureID`=19362 AND `ID`=4) OR (`CreatureID`=19362 AND `ID`=3) OR (`CreatureID`=19362 AND `ID`=2) OR (`CreatureID`=21911 AND `ID`=2) OR (`CreatureID`=18260 AND `ID`=5) OR (`CreatureID`=18260 AND `ID`=4) OR (`CreatureID`=18260 AND `ID`=3) OR (`CreatureID`=18260 AND `ID`=2) OR (`CreatureID`=18260 AND `ID`=1) OR (`CreatureID`=22407 AND `ID`=3) OR (`CreatureID`=22407 AND `ID`=2) OR (`CreatureID`=21368 AND `ID`=2) OR (`CreatureID`=19048 AND `ID`=2) OR (`CreatureID`=16976 AND `ID`=2) OR (`CreatureID`=16976 AND `ID`=1) OR (`CreatureID`=16831 AND `ID`=5) OR (`CreatureID`=16831 AND `ID`=4) OR (`CreatureID`=16831 AND `ID`=3) OR (`CreatureID`=16580 AND `ID`=5) OR (`CreatureID`=19836 AND `ID`=1) OR (`CreatureID`=16580 AND `ID`=4) OR (`CreatureID`=16842 AND `ID`=2) OR (`CreatureID`=16864 AND `ID`=2) OR (`CreatureID`=16831 AND `ID`=2) OR (`CreatureID`=16580 AND `ID`=3) OR (`CreatureID`=16582 AND `ID`=2) OR (`CreatureID`=20238 AND `ID`=2) OR (`CreatureID`=16580 AND `ID`=2) OR (`CreatureID`=16591 AND `ID`=2) OR (`CreatureID`=18857 AND `ID`=2) OR (`CreatureID`=19610 AND `ID`=3) OR (`CreatureID`=107619 AND `ID`=1) OR (`CreatureID`=107599 AND `ID`=1) OR (`CreatureID`=19737 AND `ID`=2) OR (`CreatureID`=19610 AND `ID`=2) OR (`CreatureID`=19737 AND `ID`=1) OR (`CreatureID`=19610 AND `ID`=1) OR (`CreatureID`=20203 AND `ID`=3) OR (`CreatureID`=20203 AND `ID`=2) OR (`CreatureID`=20203 AND `ID`=1) OR (`CreatureID`=21254 AND `ID`=1) OR (`CreatureID`=21114 AND `ID`=1) OR (`CreatureID`=20765 AND `ID`=2) OR (`CreatureID`=19952 AND `ID`=2) OR (`CreatureID`=115597 AND `ID`=1) OR (`CreatureID`=19995 AND `ID`=3) OR (`CreatureID`=19995 AND `ID`=2) OR (`CreatureID`=23385 AND `ID`=2) OR (`CreatureID`=21809 AND `ID`=2) OR (`CreatureID`=19997 AND `ID`=1) OR (`CreatureID`=19994 AND `ID`=2) OR (`CreatureID`=17855 AND `ID`=2) OR (`CreatureID`=19989 AND `ID`=2) OR (`CreatureID`=22982 AND `ID`=2) OR (`CreatureID`=23115 AND `ID`=2) OR (`CreatureID`=23385 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(22253, 3, 31600, 0, 0, 31466, 0, 0, 0, 0, 0), -- Dragonmaw Ascendant
(22253, 2, 31603, 0, 0, 31466, 0, 0, 0, 0, 0), -- Dragonmaw Ascendant
(23146, 6, 31604, 0, 0, 0, 0, 0, 0, 0, 0), -- Dragonmaw Enforcer
(23146, 5, 31601, 0, 0, 0, 0, 0, 0, 0, 0), -- Dragonmaw Enforcer
(23146, 4, 31600, 0, 0, 31466, 0, 0, 0, 0, 0), -- Dragonmaw Enforcer
(23146, 3, 31603, 0, 0, 0, 0, 0, 0, 0, 0), -- Dragonmaw Enforcer
(23146, 2, 31600, 0, 0, 0, 0, 0, 0, 0, 0), -- Dragonmaw Enforcer
(21717, 7, 31603, 0, 0, 31466, 0, 0, 0, 0, 0), -- Dragonmaw Wrangler
(21717, 6, 31601, 0, 0, 0, 0, 0, 0, 0, 0), -- Dragonmaw Wrangler
(21717, 5, 31604, 0, 0, 0, 0, 0, 0, 0, 0), -- Dragonmaw Wrangler
(21717, 4, 31600, 0, 0, 31600, 0, 0, 0, 0, 0), -- Dragonmaw Wrangler
(21717, 3, 5956, 0, 0, 0, 0, 0, 0, 0, 0), -- Dragonmaw Wrangler
(21717, 2, 31603, 0, 0, 31603, 0, 0, 0, 0, 0), -- Dragonmaw Wrangler
(21717, 1, 31600, 0, 0, 31466, 0, 0, 0, 0, 0), -- Dragonmaw Wrangler
(21742, 2, 5956, 0, 0, 24322, 0, 0, 0, 0, 0), -- Sunfury Eradicator
(22018, 5, 27405, 0, 0, 24328, 0, 0, 0, 0, 0), -- Eclipsion Cavalier
(22018, 4, 29417, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Cavalier
(22018, 3, 12403, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Cavalier
(22016, 4, 31207, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Soldier
(22018, 2, 25758, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Cavalier
(22016, 3, 31205, 0, 0, 31205, 0, 0, 0, 0, 0), -- Eclipsion Soldier
(22016, 2, 31206, 0, 0, 31466, 0, 0, 0, 0, 0), -- Eclipsion Soldier
(19806, 3, 29417, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Bloodwarder
(19792, 8, 30180, 0, 0, 21549, 0, 0, 0, 0, 0), -- Eclipsion Centurion
(19792, 7, 30179, 0, 0, 21549, 0, 0, 0, 0, 0), -- Eclipsion Centurion
(19792, 6, 2028, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Centurion
(19806, 2, 25758, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Bloodwarder
(19792, 5, 30636, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Centurion
(19792, 4, 27405, 0, 0, 24328, 0, 0, 0, 0, 0), -- Eclipsion Centurion
(19792, 3, 23225, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Centurion
(19792, 2, 29417, 0, 0, 0, 0, 0, 0, 0, 0), -- Eclipsion Centurion
(19384, 2, 2182, 0, 0, 0, 0, 0, 0, 0, 0), -- Wildhammer Scout
(19765, 2, 2028, 0, 0, 0, 0, 0, 0, 0, 0), -- Coilskar Myrmidon
(19362, 4, 30178, 0, 0, 0, 0, 0, 2507, 0, 0), -- Kor'kron Defender
(19362, 3, 30181, 0, 0, 21549, 0, 0, 2507, 0, 0), -- Kor'kron Defender
(19362, 2, 30180, 0, 0, 30180, 0, 0, 2507, 0, 0), -- Kor'kron Defender
(21911, 2, 1117, 0, 0, 12861, 0, 0, 0, 0, 0), -- Skettis Soulcaller
(18260, 5, 3326, 0, 0, 0, 0, 0, 0, 0, 0), -- Boulderfist Invader
(18260, 4, 5301, 0, 0, 0, 0, 0, 0, 0, 0), -- Boulderfist Invader
(18260, 3, 5491, 0, 0, 0, 0, 0, 0, 0, 0), -- Boulderfist Invader
(18260, 2, 17942, 0, 0, 0, 0, 0, 0, 0, 0), -- Boulderfist Invader
(18260, 1, 5300, 0, 0, 0, 0, 0, 0, 0, 0), -- Boulderfist Invader
(22407, 3, 3367, 0, 0, 13610, 0, 0, 2551, 0, 0), -- Caravan Defender
(22407, 2, 2695, 0, 0, 13610, 0, 0, 2551, 0, 0), -- Caravan Defender
(21368, 2, 29419, 0, 0, 29419, 0, 0, 0, 0, 0), -- Ethereal Plunderer
(19048, 2, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Stonebreaker Peon
(16976, 2, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- Ghostly Denizen
(16976, 1, 2813, 0, 0, 0, 0, 0, 0, 0, 0), -- Ghostly Denizen
(16831, 5, 2704, 0, 0, 13407, 0, 0, 0, 0, 0), -- Nethergarde Infantry
(16831, 4, 12858, 0, 0, 13606, 0, 0, 0, 0, 0), -- Nethergarde Infantry
(16831, 3, 12856, 0, 0, 12857, 0, 0, 0, 0, 0), -- Nethergarde Infantry
(16580, 5, 2184, 0, 0, 0, 0, 0, 5260, 0, 0), -- Thrallmar Grunt
(19836, 1, 0, 0, 0, 0, 0, 0, 12523, 0, 0), -- Mixie Farshot
(16580, 4, 3350, 0, 0, 0, 0, 0, 5260, 0, 0), -- Thrallmar Grunt
(16842, 2, 1903, 0, 0, 143, 0, 0, 0, 0, 0), -- Honor Hold Defender
(16864, 2, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Stormwind Infantry
(16831, 2, 1901, 0, 0, 0, 0, 0, 0, 0, 0), -- Nethergarde Infantry
(16580, 3, 17383, 0, 0, 12452, 0, 0, 5260, 0, 0), -- Thrallmar Grunt
(16582, 2, 14877, 0, 0, 0, 0, 0, 13924, 0, 0), -- Thrallmar Marksman
(20238, 2, 5305, 0, 0, 0, 0, 0, 5258, 0, 0), -- Honor Hold Scout
(16580, 2, 0, 0, 0, 0, 0, 0, 5260, 0, 0), -- Thrallmar Grunt
(16591, 2, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Thrallmar Peon
(18857, 2, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Sunfury Warp-Master
(19610, 3, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Irradiated Worker
(107619, 1, 137647, 0, 0, 0, 0, 0, 0, 0, 0), -- Blaze Magmaburn
(107599, 1, 137645, 0, 0, 0, 0, 0, 0, 0, 0), -- Izzee the 'Clutch'
(19737, 2, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Engineering Crewmember
(19610, 2, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- Irradiated Worker
(19737, 1, 4994, 0, 0, 0, 0, 0, 0, 0, 0), -- Engineering Crewmember
(19610, 1, 4994, 0, 0, 0, 0, 0, 0, 0, 0), -- Irradiated Worker
(20203, 3, 2704, 0, 0, 0, 0, 0, 0, 0, 0), -- Nether Technician
(20203, 2, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Nether Technician
(20203, 1, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Nether Technician
(21254, 1, 3350, 0, 0, 0, 0, 0, 0, 0, 0), -- Dullgrom Dredger
(21114, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Station Technician
(20765, 2, 2703, 0, 0, 13407, 0, 0, 5870, 0, 0), -- Bladespire Crusher
(19952, 2, 4090, 0, 0, 0, 0, 0, 0, 0, 0), -- Bloodmaul Geomancer
(115597, 1, 1907, 0, 0, 0, 0, 0, 0, 0, 0), -- Geo-Lord Garug
(19995, 3, 2703, 0, 0, 13407, 0, 0, 5870, 0, 0), -- Bladespire Brute
(19995, 2, 1903, 0, 0, 0, 0, 0, 5870, 0, 0), -- Bladespire Brute
(23385, 2, 29544, 0, 0, 0, 0, 0, 0, 0, 0), -- Simon Unit
(21809, 2, 5278, 0, 0, 0, 0, 0, 5260, 0, 0), -- Wyrmcult Poacher
(19997, 1, 2703, 0, 0, 13407, 0, 0, 0, 0, 0), -- Bladespire Enforcer
(19994, 2, 3361, 0, 0, 0, 0, 0, 0, 0, 0), -- Bloodmaul Warlock
(17855, 2, 1906, 0, 0, 0, 0, 0, 12523, 0, 0), -- Expedition Warden
(19989, 2, 6227, 0, 0, 0, 0, 0, 0, 0, 0), -- Grishna Harbinger
(22982, 2, 2705, 0, 0, 0, 0, 0, 0, 0, 0), -- Skyguard Navigator
(23115, 2, 0, 0, 0, 0, 0, 0, 5870, 0, 0), -- Ogri'la Peacekeeper
(23385, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0); -- Simon Unit

UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=23166 AND `ID`=1); -- Ronag the Slave Driver
UPDATE `creature_equip_template` SET `ItemID2`=31466 WHERE (`CreatureID`=23146 AND `ID`=1); -- Dragonmaw Enforcer
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=23188 AND `ID`=1); -- Dragonmaw Transporter
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=22211 AND `ID`=1); -- Battlemage Vyara
UPDATE `creature_equip_template` SET `ItemID1`=31208, `ItemID2`=0 WHERE (`CreatureID`=22016 AND `ID`=1); -- Eclipsion Soldier
UPDATE `creature_equip_template` SET `ItemID1`=30636 WHERE (`CreatureID`=22018 AND `ID`=1); -- Eclipsion Cavalier
UPDATE `creature_equip_template` SET `ItemID1`=30636 WHERE (`CreatureID`=19806 AND `ID`=1); -- Eclipsion Bloodwarder
UPDATE `creature_equip_template` SET `ItemID1`=25758 WHERE (`CreatureID`=19792 AND `ID`=1); -- Eclipsion Centurion
UPDATE `creature_equip_template` SET `ItemID1`=30179 WHERE (`CreatureID`=19362 AND `ID`=1); -- Kor'kron Defender
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=21650 AND `ID`=1); -- Skettis Talonite
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=22381 AND `ID`=1); -- Hathyss the Wicked
UPDATE `creature_equip_template` SET `ItemID1`=1910 WHERE (`CreatureID`=22407 AND `ID`=1); -- Caravan Defender
UPDATE `creature_equip_template` SET `ItemID1`=1910 WHERE (`CreatureID`=21368 AND `ID`=1); -- Ethereal Plunderer
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=35002 AND `ID`=1); -- Asara Dawnblaze
UPDATE `creature_equip_template` SET `ItemID1`=28067 WHERE (`CreatureID`=18166 AND `ID`=1); -- Archmage Khadgar
UPDATE `creature_equip_template` SET `ItemID1`=2901 WHERE (`CreatureID`=16938 AND `ID`=1); -- Dreghood Brute
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=19335 AND `ID`=1); -- Subjugator Yalqiz
UPDATE `creature_equip_template` SET `ItemID1`=5282, `ItemID2`=0 WHERE (`CreatureID`=16831 AND `ID`=1); -- Nethergarde Infantry
UPDATE `creature_equip_template` SET `ItemID1`=1899, `ItemID2`=0 WHERE (`CreatureID`=16864 AND `ID`=1); -- Stormwind Infantry
UPDATE `creature_equip_template` SET `ItemID1`=106044 WHERE (`CreatureID`=18970 AND `ID`=1); -- Darkspear Axe Thrower
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=19282 AND `ID`=1); -- Subjugator Shi'aziv
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=18981 AND `ID`=1); -- Doomwhisperer
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=16582 AND `ID`=1); -- Thrallmar Marksman
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=20930 AND `ID`=1); -- Hatecryer
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=19499 AND `ID`=1); -- Cahill
UPDATE `creature_equip_template` SET `ItemID1`=107415 WHERE (`CreatureID`=19995 AND `ID`=1); -- Bladespire Brute
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=22241 AND `ID`=1); -- Bash'ir Raider
UPDATE `creature_equip_template` SET `ItemID1`=4090 WHERE (`CreatureID`=19994 AND `ID`=1); -- Bloodmaul Warlock
UPDATE `creature_equip_template` SET `ItemID1`=1906 WHERE (`CreatureID`=21809 AND `ID`=1); -- Wyrmcult Poacher
UPDATE `creature_equip_template` SET `ItemID1`=1906 WHERE (`CreatureID`=22308 AND `ID`=1); -- Wyrmcult Hunter
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=19988 AND `ID`=1); -- Grishna Falconwing
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=19947 AND `ID`=1); -- Darkcrest Sorceress
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=18044 AND `ID`=1); -- Rajis Fyashe
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=20089 AND `ID`=1); -- Bloodscale Wavecaller
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=18115 AND `ID`=1); -- Daggerfen Muckdweller
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=20443 AND `ID`=1); -- Ango'rosh Sentry
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=18088 AND `ID`=1); -- Bloodscale Enchantress


UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=23269; -- Barash the Den Mother
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=23209; -- Dragonmaw Peon Kill Credit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=23267; -- Arvoar the Rapacious
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=23305; -- Crazed Murkblood Foreman
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23164; -- Toranaku
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=23324; -- Crazed Murkblood Miner
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=23264; -- Overmine Flayer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=33554432 WHERE `entry`=23285; -- Nethermine Burster
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23149; -- Mistress of the Mines
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=23143; -- Horus
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=23150; -- Dragonmaw Pitfighter
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23291; -- Chief Overseer Mudlump
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=23289; -- Mine Car
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=23427; -- Illidari Lord Balthas
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=23376; -- Dragonmaw Foreman
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=22433; -- Ja'y Nosliw
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23140; -- Taskmaster Varkule Dragonbreath
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23141; -- Yarzill the Merc
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=23142; -- Goblin Merc
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23139; -- Overlord Mor'ghor
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=23145; -- Rumpus
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=23144; -- Gug
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=23489; -- Drake Dealer Hurlunk
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23345; -- Wing Commander Ichman
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23342; -- Trope the Filth-Belcher
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23340; -- Murg "Oldie" Muckjaw
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23348; -- Captain Skyshatter
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23344; -- Corlok the Vet
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=23286; -- Black Blood of Draenor
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23346; -- Wing Commander Mulverick
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22253; -- Dragonmaw Ascendant
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=62 WHERE `entry`=23311; -- Disobedient Dragonmaw Peon
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=22274; -- Dragonmaw Skybreaker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=23287; -- Murkblood Miner
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=23326; -- Nethermine Ravager
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=23169; -- Nethermine Flayer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=23309; -- Murkblood Overseer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=23308; -- Dragonmaw Peon Work Node
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22252; -- Dragonmaw Peon
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0, `unit_flags2`=0 WHERE `entry`=23501; -- Netherwing Ray
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=23225; -- Netherwing Drake Escape Point
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21720; -- Dragonmaw Shaman
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=23188; -- Dragonmaw Transporter
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=22317; -- Netherwing Drake Escape Dummy
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `unit_flags`=32768 WHERE `entry`=21722; -- Enslaved Netherwing Drake
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21717; -- Dragonmaw Wrangler
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=22112; -- Karynaku
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21718; -- Dragonmaw Subjugator
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21721; -- Enslaved Netherwing Whelp
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0, `unit_flags2`=0 WHERE `entry`=21901; -- Netherskate
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21719; -- Dragonmaw Drake-Rider
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=21171; -- Alandien
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21178; -- Varedis
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=21164; -- Netharel
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=21506; -- Azaloth
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=1813 WHERE `entry`=21179; -- Demon Hunter Supplicant
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=21892; -- Azaloth Credit Marker
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21908; -- Spellbound Terrorguard
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21168; -- Theras
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21180; -- Demon Hunter Initiate
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21505; -- Sunfury Summoner
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21503; -- Sunfury Warlock
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=113941; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22860; -- Illidari Succubus
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=22858; -- Shadowhoof Assassin
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=22134; -- Shadowmoon Eye of Kilrogg
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=22859; -- Shadowhoof Summoner
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=21166; -- Illidari Dreadlord
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=22082; -- Shadowmoon Slayer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=22857; -- Illidari Ravager
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21743; -- Sunfury Blood Lord
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=33024 WHERE `entry`=22966; -- Lightsworn Elekk Rider
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=22515; -- World Trigger
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22862; -- Anchorite Caalen
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21742; -- Sunfury Eradicator
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22861; -- Lightsworn Vindicator
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22864; -- Fyra Dawnstar
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=22230; -- Shadowmoon Fel Orc Attack Trigger
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags2`=4196352 WHERE `entry`=24925; -- Boss Portal: Purple (3.00)
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857, `unit_flags2`=2099200 WHERE `entry`=18528; -- Xi'ri
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21826; -- Sanoru
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21827; -- Zandras
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21700; -- Akama
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21102; -- Uvuros
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21701; -- Ashtongue Deathsworn
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21699; -- Maiev Shadowsong
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19744; -- Dreadwarden
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21520; -- Illidari Jailor
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19801; -- Illidari Agonizer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21897; -- Felspine the Greater
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21802; -- Elekk Demolisher
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21803; -- Ashtongue Handler
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21808; -- Illidari Overseer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21455; -- Ashtongue Worker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21453; -- Ashtongue Shaman
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=23020; -- Shadow Serpent
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71 WHERE `entry`=23454; -- Dragonmaw Raid Credit Marker (Aldor)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=19581; -- Maddix
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=22214; -- Harbinger Saronen
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21402; -- Anchorite Ceyla
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21746; -- Caretaker Aluuro
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21822; -- Vindicator Aluumen
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21860; -- Exarch Onaala
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22079; -- Air Force Guard Post (Aldor - Gryphon)
UPDATE `creature_template` SET `npcflag`=640 WHERE `entry`=19649; -- Dorni
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22080; -- Air Force Trip Wire - Rooftop (Aldor)
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=21986; -- Altar of Sha'tar Vindicator
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21454; -- Ashtongue Warrior
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=21095; -- Credit Marker: Water
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21704; -- Corrupt Earth Totem
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21709; -- Eykenen
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21979; -- Val'zareq the Conqueror
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19795; -- Eclipsion Blood Knight
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21953; -- Varen the Reclaimer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=21766; -- Alieshor
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21954; -- Larissa Sunstrike
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71 WHERE `entry`=23443; -- Dragonmaw Raid Credit Marker (Scryers)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=22211; -- Battlemage Vyara
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21744; -- Roldemar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21955; -- Arcanist Thelis
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=19504; -- Scryer Guardian
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22070; -- Air Force Trip Wire - Rooftop (Scryer)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22066; -- Air Force Guard Post (Scryer - Dragonhawk)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `npcflag`=0 WHERE `entry`=22113; -- Mordenai
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=21477; -- Rocknail Flayer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=21478; -- Rocknail Ripper
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `unit_flags`=33344, `unit_flags2`=2099200 WHERE `entry`=21648; -- Mature Netherwing Drake
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1.142857 WHERE `entry`=21872; -- The Voice of Gorefiend
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21797; -- Ancient Shadowmoon Spirit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21711; -- Haalum
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21705; -- Corrupt Air Totem
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21060; -- Enraged Air Spirit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=22083; -- Lord Illidan Stormrage
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22093; -- Illidari Watcher
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22012; -- Chancellor Bloodleaf
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22011; -- Corok the Mighty
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `npcflag`=0 WHERE `entry`=22016; -- Eclipsion Soldier
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22017; -- Eclipsion Spellbinder
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22018; -- Eclipsion Cavalier
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=64 WHERE `entry`=19824; -- Son of Corok
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=22054; -- Behemothon, King of the Colossi
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20563; -- Grand Commander Ruusk
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21639; -- Illidari Slayer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19796; -- Eclipsion Archmage
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=20431; -- Eclipse Point - Bloodcrystal Spell Orgin
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19806; -- Eclipsion Bloodwarder
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19792; -- Eclipsion Centurion
UPDATE `creature_template` SET `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20502; -- Eclipsion Dragonhawk
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21293; -- Borak, Son of Oronok
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21384; -- Dark Conclave Harbinger
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22137; -- Summoned Old God
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19825; -- Dark Conclave Talonite
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=22138; -- Dark Conclave Ritualist
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21385; -- Dark Conclave Scorncrow
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=22146; -- Summoning Voidstorm
UPDATE `creature_template` SET `npcflag`=80 WHERE `entry`=19369; -- Celie Steelwing
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19352; -- Dreg Cloudsweeper
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22042; -- Gryphonrider Kieran
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21775; -- Warcaller Beersnout
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20505; -- Snowy Gryphon Mount
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18939; -- Brubeck Stormfoot
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19368; -- Crinn Pathfinder
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=20510; -- Brunn Flamebeard
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=20511; -- Ilsa Blusterbrew
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20504; -- Golden Gryphon
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21774; -- Zorus the Judicator
UPDATE `creature_template` SET `npcflag`=4224 WHERE `entry`=19351; -- Daggle Ironshaper
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19375; -- Eli Thunderstrike
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19388; -- Wildhammer Stronghold Target Dummy Right
UPDATE `creature_template` SET `npcflag`=16 WHERE `entry`=24868; -- Niobe Whizzlespark
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19370; -- Ordinn Thunderfist
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19387; -- Wildhammer Stronghold Target Dummy Left
UPDATE `creature_template` SET `npcflag`=640 WHERE `entry`=19374; -- Salle Sunforge
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21773; -- Thane Yoregar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21937; -- Earthmender Sophurus
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=19382; -- Wildhammer Gryphon Rider
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=21287; -- Warbringer Razuun
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21736; -- Wildhammer Defender
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19759; -- Newly Crafted Infernal
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=570425600, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=19760; -- Cooling Infernal
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=19756; -- Deathforge Smith
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20872; -- Deathforge Summoner
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19757; -- Infernal Soul
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19754; -- Deathforge Tinkerer
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=20887; -- Deathforge Imp
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20878; -- Deathforge Guardian
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21026; -- Earthmender Gorboto
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21024; -- Earthmender Torlok
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21049; -- Spirit of the Past
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=1 WHERE `entry`=17008; -- Gul'dan
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=21094; -- Credit Marker: Fire
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=21092; -- Credit Marker: Earth
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21710; -- Uylaru
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21703; -- Corrupt Fire Totem
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=21108; -- Spawn of Uvuros
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `unit_flags`=32768 WHERE `entry`=21050; -- Enraged Earth Spirit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21061; -- Enraged Fire Spirit
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21183; -- Oronok Torn-heart
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21255; -- Umberhowl
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20795; -- Keeper of the Cistern
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `npcflag`=0 WHERE `entry`=21027; -- Earthmender Wilda
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=21041; -- Earthmender Wilda Trigger
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19788; -- Coilskar Muckwatcher
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19767; -- Coilskar Sorceress
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21347; -- Shadowmoon Valley Tuber Node
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19765; -- Coilskar Myrmidon
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21196; -- Ravenous Flayer
UPDATE `creature_template` SET `maxlevel`=70, `unit_flags3`=1 WHERE `entry`=21052; -- Camera Shaker - Altar of Damnation
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21416; -- Lakaan
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=21195; -- Domesticated Felboar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21420; -- Corrupt Water Totem
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=21462; -- Greater Felfire Diemetradon
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20684; -- Lady Shav'rar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21295; -- Coilskar Commander
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21291; -- Grom'tor, Son of Oronok
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=33587968 WHERE `entry`=19784; -- Coilskar Cobra
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21059; -- Enraged Water Spirit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19789; -- Coilskar Waterkeeper
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19769; -- Coilskar Screamer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19768; -- Coilskar Siren
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=33587968 WHERE `entry`=19762; -- Coilskar Defender
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22025; -- Asghar
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62621; -- Gangreflamme
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19827; -- Dark Conclave Ravenguard
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21386; -- Dark Conclave Hawkeye
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19826; -- Dark Conclave Shadowmancer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21450; -- Skethyl Owl
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22043; -- Sergeant Kargrul
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21771; -- Warcaller Sardon Truslice
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19319; -- Innkeeper Darg Bloodclaw
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=19317; -- Drek'Gol
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=19341; -- Grutah
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19333; -- Grokom Deatheye
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=51910; -- Kor'kron Defender
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21772; -- Chief Apothecary Hildagard
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21770; -- Researcher Tiorus
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=21769; -- Overlord Or'barokh
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=4194433 WHERE `entry`=21336; -- Gedrah
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=19362; -- Kor'kron Defender
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21938; -- Earthmender Splinthoof
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=17 WHERE `entry`=25099; -- Jonathan Garrett
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=20494; -- Dama Wildmane
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=20500; -- Olrokk
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21153; -- Kor'kron Wyvern Rider
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=21245; -- Bonechewer Marauder
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21249; -- Wrathstalker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=21501; -- Makazradon
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=21499; -- Overseer Ripsaw
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=21500; -- Morgroron
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20683; -- Prophetess Cavrylin
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=33024, `unit_flags3`=1 WHERE `entry`=21316; -- Deathforged Infernal
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=21404; -- Legion Hold Fel Reaver
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21302; -- Shadow Council Warlock
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=61385; -- Vipère cendrée
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=19755; -- Mo'arg Weaponsmith
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21314; -- Terrormaster
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19740; -- Wrathwalker
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21305; -- Mutant Horror
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags2`=0 WHERE `entry`=21419; -- Infernal Attacker
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21749; -- Shadowmoon Scout
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=1500, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=66557; -- Chevalier de sang Antari
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=24, `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66544; -- Jadefeu
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=24, `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66545; -- Arcanus
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21408; -- Felfire Diemetradon
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=24, `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66543; -- Morsure-du-Néant
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=21879; -- Vilewing Chimaera
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=21348; -- Shadowmoon Trigger
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=21878; -- Felboar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21309; -- Painmistress Gabrissa
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21928; -- Lothros
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `unit_flags2`=0 WHERE `entry`=21292; -- Ar'tor, Son of Oronok
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=536870912, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=21307; -- Eva
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=21310; -- Shadowmoon Valley Invisible Trigger (Tiny)
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62314; -- Cafard corrompu
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21337; -- Illidari Shadowstalker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21656; -- Illidari Satyr
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=20286; -- Illadari Point - Succubi Spell Orgin 001
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=20288; -- Illadari Point - Succubi Caster Position 01
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=20289; -- Illadari Point - Succubi Caster Position 02
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19800; -- Illidari Painlasher
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19799; -- Illidari Dreadbringer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=21334; -- Veneratus Spawn Node
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19802; -- Illidari Shocktrooper
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80, `npcflag`=1 WHERE `entry`=23363; -- Sahaak
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21728; -- Skettis Surger
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_walk`=1, `unit_flags`=64 WHERE `entry`=23029; -- Talonsworn Forest-Rager
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21855; -- Skettis Arakkoa Spell Origin 02
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21856; -- Skettis Kneel Target 04
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21649; -- Skettis Windwalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21792; -- Skettis Kneel Target 02
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21804; -- Skettis Kaliri
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21791; -- Skettis Kneel Target 01
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21793; -- Skettis Kneel Target 03
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21644; -- Skettis Wing Guard
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=23383; -- Skyguard Prisoner
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21794; -- Skettis Arakkoa Spell Origin 01
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21650; -- Skettis Talonite
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21911; -- Skettis Soulcaller
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22991; -- Monstrous Kaliri Egg Trigger
UPDATE `creature_template` SET `speed_walk`=14, `speed_run`=1.714286, `unit_flags2`=2099200 WHERE `entry`=23051; -- Monstrous Kaliri
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=23219; -- Blackwind Warp Chaser
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22424; -- Skywing
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18455; -- Shalassi Oracle
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18454; -- Shalassi Talonguard
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=20986; -- Dealer Tariq
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `speed_run`=1.142857 WHERE `entry`=19718; -- Provisioner Tsaalt
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=33024, `unit_flags2`=4196352 WHERE `entry`=22441; -- Teribus the Cursed
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21941; -- Accursed Apparition
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22045; -- Vengeful Husk
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=22105; -- Decrepit Clefthoof
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=24893; -- Auchindoun Daily Quest Trigger
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21242; -- Auchenai Death-Speaker
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18460; -- Lost Spirit
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21443; -- Bone Wastes - Orb Waypoint 01
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21284; -- Auchenai Initiate
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21852; -- Auchenai Warrior
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=16805; -- Broken Skeleton
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21285; -- Auchenai Doomsayer
UPDATE `creature_template` SET `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=21859; -- Slain Sha'tar Vindicator
UPDATE `creature_template` SET `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=21846; -- Slain Auchenai Warrior
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=22364; -- Scout Navrin
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22458; -- Chief Archaeologist Letoll
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22446; -- Commander Ra'vaj
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22464; -- Explorers' League Researcher
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22476; -- Aundro
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22481; -- Dwarfowitz
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=22477; -- Anchorite Ensham
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=22387; -- Lithic Oracle
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22340; -- Terokkar Arakkoa Fly Target
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=22388; -- Lithic Talonguard
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18843; -- Bleeding Hollow Clan Ruins Credit Marker
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18262; -- Unkor the Ruthless
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18260; -- Boulderfist Invader
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18588; -- Floon
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=18707; -- Torgos
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21200; -- Screeching Spirit
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21198; -- Deathtalon Spirit
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21324; -- Spirit Raven
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22378; -- Cabal Interrogator
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=22377; -- Akuno
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21661; -- Cabal Skirmisher
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22381; -- Hathyss the Wicked
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21662; -- Cabal Tomb-Raider
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21660; -- Cabal Abjurist
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22288; -- Terokkar Quest Target
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18541; -- Urdak
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18453; -- Skithian Windripper
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18452; -- Skithian Dreadhawk
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18720; -- Shadowmaster Grieve
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18719; -- Shadowy Advisor
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18718; -- Shadowy Hunter
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=18716; -- Shadowy Initiate
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18717; -- Shadowy Laborer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=16519; -- Shadowy Executioner
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=17088; -- Shadowy Summoner
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18686; -- Doomsayer Jurim
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18714; -- Scout Neftis
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=20895; -- Miiji
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=20890; -- Siflaed Coldhammer
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=20891; -- Skraa
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=21313; -- Dead Clefthoof
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=20893; -- Morula
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=20892; -- Ruogo
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21317; -- Aimi
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22272; -- Kirrik the Awakened
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=20874; -- Skettis Refugee
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=22370; -- Mekeda
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=20877; -- Shattrath Refugee
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=18675; -- Soolaveen
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=22278; -- High Priest Orglum
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `npcflag`=0 WHERE `entry`=20876; -- Human Refugee
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=22407; -- Caravan Defender
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21858; -- Sha'tar Vindicator
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61440; -- Scorpide à queue rayée
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=33554432 WHERE `entry`=21849; -- Bone Crawler
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=21515; -- Trachela
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=22100; -- Scorpid Bonecrawler
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61366; -- Rat
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18470; -- Bonelasher
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=22307; -- Rotting Forest-Rager
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21636; -- Vengeful Draenei
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=22095; -- Infested Root-Walker
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21368; -- Ethereal Plunderer
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=18465; -- Warp Hunter
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18467; -- Dreadfang Widow
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=18989; -- Stonebreaker Guard
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=19002; -- Gardok Ripjaw
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21194; -- Ru'zah
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18960; -- Rungor
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18383; -- Kurgatok
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18384; -- Malukaz
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18676; -- Keb'ezil
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=19772; -- Spirit Sage Gartok
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21188; -- Thadok
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18962; -- Bar Talet
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18957; -- Innkeeper Grilka
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18712; -- Advisor Faila
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18705; -- Mawg Grimshot
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=19606; -- Grek
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19607; -- Grek's Riding Wolf
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18386; -- Rokag
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18807; -- Kerna
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18447; -- Tooki
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80, `npcflag`=4194433, `RangeAttackTime`=2000 WHERE `entry`=18984; -- Trag
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18959; -- Dod'ss
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18385; -- Rakoria
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18249; -- Mokasa
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21192; -- Kugnar
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=21193; -- Gralga
UPDATE `creature_template` SET `faction`=31 WHERE `entry`=17467; -- Skunk
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18595; -- Warped Peon
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18565; -- Theloria Shadecloak
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=21006; -- Lieutenant Meridian
UPDATE `creature_template` SET `faction`=35, `unit_flags`=33554432 WHERE `entry`=21039; -- Mana Bomb Kill Credit Trigger
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18554; -- Sharth Voldoun
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80 WHERE `entry`=18760; -- Isla Starmane
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `npcflag`=128, `RangeAttackTime`=2000 WHERE `entry`=16769; -- Firewing Warlock
UPDATE `creature_template` SET `faction`=31, `npcflag`=1073741824, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61255; -- Mouffette
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=1410; -- Firewing Bloodwarder
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=5355; -- Firewing Defender
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18648; -- Stonegazer
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18463; -- Dampscale Devourer
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21816; -- Ironspine Chomper
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=18464; -- Warp Stalker
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=18477; -- Timber Worg Alpha
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18469; -- Royal Teromoth
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=16932; -- Razorfang Hatchling
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18540; -- Ayit
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18457; -- Tuurem Hunter
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=17142; -- Wrekt Warrior
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18456; -- Tuurem Scavenger
UPDATE `creature_template` SET `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18539; -- Ashkaz
UPDATE `creature_template` SET `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18451; -- Shienor Wing Guard
UPDATE `creature_template` SET `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18450; -- Shienor Sorcerer
UPDATE `creature_template` SET `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18449; -- Shienor Talonite
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18466; -- Dreadfang Lurker
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18468; -- Teromoth
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=18480; -- Broken Corpse
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18424; -- Warden Treelos
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=18490; -- Fallen Druid
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18438; -- Naphthal'ar
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62583; -- Jeune traqueur dimensionnel
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18437; -- Vicious Teromoth
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=18584; -- Sal'salabim
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=24369; -- Wind Trader Zhareem
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=24370; -- Nether-Stalker Mah'duun
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=24412; -- Daily Dungeon Image Bunny
UPDATE `creature_template` SET `faction`=1720, `speed_run`=1.428571 WHERE `entry`=24411; -- Shattered Hand Centurion Image
UPDATE `creature_template` SET `gossip_menu_id`=0, `RangeAttackTime`=2000 WHERE `entry`=19033; -- Nicole Bartlett
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22819; -- Orphan Matron Mercy
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=20125; -- Zula Slagfury
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=20124; -- Kradu Grimblade
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23699; -- Kevin Browning
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry`=25136; -- Shattered Sun Trainee
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=35002; -- Asara Dawnblaze
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18940; -- Nutral
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=69 WHERE `entry`=25135; -- Shattered Sun Trainee
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=19162; -- Lost One Refugee
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry`=25134; -- Shattered Sun Trainee
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=35001; -- Saeld Brightflare
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=23483; -- Arcanist Xorith
UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=19331; -- Quartermaster Enuril
UPDATE `creature_template` SET `maxlevel`=60 WHERE `entry`=23273; -- Arcanist Raestan
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18166; -- Archmage Khadgar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=52277; -- Droha
UPDATE `creature_template` SET `npcflag`=131072 WHERE `entry`=19246; -- Berudan Keysworn
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=50136; -- Baelir
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `RangeAttackTime`=2000 WHERE `entry`=50127; -- Windstalker Ifram
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=50137; -- Muha
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `speed_run`=1.142857 WHERE `entry`=50130; -- Luknar
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=50128; -- Fel-Caller Guloto
UPDATE `creature_template` SET `gossip_menu_id`=0, `RangeAttackTime`=2000 WHERE `entry`=52278; -- Linsa
UPDATE `creature_template` SET `npcflag`=131072 WHERE `entry`=19338; -- L'lura Goldspun
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=19680; -- Aldor Spawn Controller
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=50140; -- Auctioneer Lyrsara
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=49 WHERE `entry`=20791; -- Iorioa
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=25167; -- General Tiras'alan
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=22497; -- V'eru
UPDATE `creature_template` SET `unit_flags`=33685760, `unit_flags3`=1 WHERE `entry`=5202; -- Archery Target
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=18481; -- A'dal
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `RangeAttackTime`=2000 WHERE `entry`=50012; -- Blood Knight Argaron
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `RangeAttackTime`=2000 WHERE `entry`=50010; -- Alaressa
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `RangeAttackTime`=2000 WHERE `entry`=50007; -- Derithela
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `RangeAttackTime`=2000 WHERE `entry`=50013; -- Matron Ismara
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=50018; -- Tarlhir
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `RangeAttackTime`=2000 WHERE `entry`=50016; -- Pathstalker Arpalir
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `RangeAttackTime`=2000 WHERE `entry`=50017; -- Summoner Durael
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=24938; -- Shattered Sun Marksman
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18893; -- Spymistress Mehlisah Highcrown
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=19120; -- Broken Refugee
UPDATE `creature_template` SET `minlevel`=69 WHERE `entry`=25153; -- Shattered Sun Magi
UPDATE `creature_template` SET `npcflag`=4224 WHERE `entry`=27667; -- Anwehu
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=18525; -- G'eras
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=24932; -- Exarch Nasuun
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=80 WHERE `entry`=24928; -- Sunwell Daily Bunny x 1.00
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=24936; -- Sunwell Daily Bunny x 0.01
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=15892; -- Lunar Festival Emissary
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=15891; -- Lunar Festival Herald
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=15897; -- Large Spotlight
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=145 WHERE `entry`=33678; -- Jijia
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=33684; -- Weaver Aoa
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3217 WHERE `entry`=33674; -- Alchemist Kanhu
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=15895; -- Lunar Festival Harbinger
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=19726; -- "Creepjack"
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=19725; -- "Epic" Malone
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=80, `unit_flags`=33536 WHERE `entry`=19720; -- "Dirty" Larry
UPDATE `creature_template` SET `npcflag`=131072 WHERE `entry`=19034; -- Mendorn
UPDATE `creature_template` SET `npcflag`=131072 WHERE `entry`=19318; -- Gromden
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=19 WHERE `entry`=19052; -- Lorokeem
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=23484; -- Haldor the Compulsive
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22429; -- Vekax
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19051; -- Araac
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=50145; -- Auctioneer Braku
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22292; -- Rilak the Redeemed
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23465; -- Zoya
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19047; -- Lissaf
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=19665; -- Ewe
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18596; -- Arcanist Adyria
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20123; -- Farmer Griffith
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=19155; -- Sporeling Refugee
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23466; -- Voranaku
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19045; -- Oloraak
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=19163; -- Refugee Kid
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=24393; -- The Rokk
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18597; -- Sha'nir
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18653; -- Seth
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19184; -- Mildred Fletcher
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19687; -- Shattrath City Peacekeeper
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21854; -- Ironspine Petrifier
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=18750; -- Shimmerscale Eel
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18461; -- Dampscale Basilisk
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62555; -- Jeune écorcheur
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=24922; -- Razorthorn Ravager
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=24920; -- Razorthorn Flayer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20678; -- Akoru the Firecaller
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19361; -- Naladu
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=16937; -- Dreghood Geomancer
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19354; -- Arzeth the Merciless
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=20677; -- Morod the Windstirrer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20679; -- Aylaan the Waterwaker
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=17058; -- Illidari Taskmaster
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16938; -- Dreghood Brute
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=19350; -- Thornfang Venomspitter
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=19349; -- Thornfang Ravager
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19188; -- Raging Colossus
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=18990; -- Burko
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=16796; -- Amaan the Wise
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18906; -- Caregiver Ophera Windfury
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=17006; -- Elsaana
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=19004; -- Vodesiin
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=19001; -- Talaara
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=16799; -- Ikan
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=16836; -- Escaped Dreghood
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=16834; -- Anchorite Obadei
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=16833; -- Makuru
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16797; -- Scout Vanura
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=18758; -- Telhamat Protector
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16798; -- Provisioner Anir
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=17402; -- Yaluu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18785; -- Kuma
UPDATE `creature_template` SET `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=16852; -- Sedai's Corpse
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `faction`=31, `speed_walk`=0.8, `speed_run`=0.7142857 WHERE `entry`=16927; -- Stonescythe Whelp
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=16845; -- Gorkan Bloodfist
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=17123; -- Earthcaller Ryga
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16848; -- Provisioner Braknar
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16912; -- Mag'har Hunter
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=16847; -- Debilitated Mag'har Grunt
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16846; -- Mag'har Grunt
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=16973; -- Bonestripper Vulture
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=17062; -- Fel Orc Corpse
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16911; -- Mag'har Watcher
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=19191; -- Arazzius the Cruel
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19192; -- Mistress of Doom
UPDATE `creature_template` SET `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=20158; -- Slime-Covered Corpse
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=16951; -- Terrorfiend
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16901; -- Blistering Rot
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16903; -- Blistering Oozeling
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=17795; -- Horde Tower Buffer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=17794; -- Alliance Tower Buffer
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19264; -- Force-Commander Gorax
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `faction`=1662, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=18677; -- Mekthorg the Wild
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16857; -- Marauding Crust Burster
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19415; -- Shattered Hand Acolyte
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19413; -- Shattered Hand Mage
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19295; -- Shattered Hand Grenadier
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19414; -- Shattered Hand Guard
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=16880; -- Hulking Helboar
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19297; -- [PH]Dynamite Target
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19263; -- Warboss Nekrogg
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16878; -- Shattered Hand Berserker
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16974; -- Rogue Voidwalker
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16975; -- Uncontrolled Voidwalker
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16978; -- Lieutenant Commander Thalvos
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16977; -- Arch Mage Xintor
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=17060; -- Hellfire Combat Dummy Small
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=17059; -- Hellfire Combat Dummy
UPDATE `creature_template` SET `minlevel`=16 WHERE `entry`=16976; -- Ghostly Denizen
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=33587264 WHERE `entry`=18678; -- Fulgorge
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16843; -- Honor Hold Cavalryman
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=16838; -- Honor Hold Miner
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `unit_flags2`=0, `unit_flags3`=1 WHERE `entry`=22431; -- Anchorite Barada
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16884; -- War Horse
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=35101; -- Grunda Bronzewing
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=35100; -- Hargen Bronzewing
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000 WHERE `entry`=18974; -- Z'kral
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `unit_flags3`=1 WHERE `entry`=16899; -- Honor Hold Target Dummy Left
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `unit_flags3`=1 WHERE `entry`=16898; -- Honor Hold Target Dummy Right
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=16897; -- Honor Hold Target Dummy Middle
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16832; -- Prospector Murantus
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=22432; -- Colonel Jules
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=18987; -- Gaston
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=16824; -- Master Sergeant Lorin Thalmerok
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=16822; -- Flightmaster Krill Bitterhue
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16835; -- Explorers' League Archaeologist
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16830; -- Field Commander Romus
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=17657; -- Logistics Officer Ulrike
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18266; -- Warrant Officer Tracy Proudwell
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=20513; -- Honor Hold Defender
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=17 WHERE `entry`=18777; -- Jelena Nightsky
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19363; -- Sergeant Dalton
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19393; -- Fear Controller
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=17 WHERE `entry`=18779; -- Hurnak Grimmord
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=4241 WHERE `entry`=16823; -- Humphry
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16886; -- Arator the Redeemer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=145 WHERE `entry`=18771; -- Brumman
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16828; -- Honor Guard Greyn
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16825; -- Father Malgor Devidicus
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=22430; -- Assistant Klatu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=66179 WHERE `entry`=16826; -- Sid Limbardi
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=22227; -- Markus Scylan
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=145 WHERE `entry`=18774; -- Tatiana
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18772; -- Hama
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=17 WHERE `entry`=18776; -- Rorelien
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18773; -- Johan Barnes
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `npcflag`=128 WHERE `entry`=30734; -- Jezebel Bican
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `npcflag`=16 WHERE `entry`=30721; -- Michael Schwan
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16829; -- Magus Zabraxis
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=47574; -- Gerdra Fardelve
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=3219 WHERE `entry`=18802; -- Alchemist Gribble
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19392; -- Watch Commander Leonus
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=129 WHERE `entry`=18775; -- Lebowski
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16856; -- Caretaker Dilandrus
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=16819; -- Force Commander Danath Trollbane
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16821; -- Magus Filinthus
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16839; -- Warp-Scryer Kryv
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16896; -- Honor Hold Archer
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16865; -- Injured Stormwind Infantry
UPDATE `creature_template` SET `maxlevel`=48, `unit_flags2`=2099200 WHERE `entry`=16887; -- Eye of Honor Hold
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=16972; -- Bonestripper Buzzard
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16905; -- Unyielding Sorcerer
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19937; -- Commander Hogarth
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16906; -- Unyielding Knight
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16904; -- Unyielding Footman
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=51799; -- Thrallmar Grunt
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21391; -- Scarab Bunny
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16858; -- Grelag
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `npcflag`=640, `RangeAttackTime`=2000 WHERE `entry`=19560; -- Lukra
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `npcflag`=4224, `RangeAttackTime`=2000 WHERE `entry`=19561; -- Hagash the Blind
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21279; -- Apothecary Albreck
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19736; -- Althen the Historian
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `npcflag`=128 WHERE `entry`=19836; -- Mixie Farshot
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22231; -- Zezzak
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19682; -- Emissary Mordiba
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22107; -- Captain Darkhowl
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19562; -- Peon Bolgar
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=19558; -- Amilya Airheart
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=19559; -- Mondul
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=19332; -- Stone Guard Ambelan
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19683; -- Ogath the Mad
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21182; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower South
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16964; -- Warlord Morkh
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=20813; -- Zeth'Gor Quest Credit Marker, Barracks
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=20816; -- Zeth'Gor Quest Credit Marker, West Hovel
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=19423; -- Bleeding Hollow Worg
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=19458; -- Ripp
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19442; -- Worg Master Kruush
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=20814; -- Zeth'Gor Quest Credit Marker, Stable
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=19459; -- Feng
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=19440; -- Eye of Grillok
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=22403; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower Foothill
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16873; -- Bleeding Hollow Dark Shaman
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19422; -- Bleeding Hollow Necrolyte
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=20815; -- Zeth'Gor Quest Credit Marker, East Hovel
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=22402; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower Forge
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=22401; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower North
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16907; -- Bleeding Hollow Peon
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19424; -- Bleeding Hollow Tormentor
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16871; -- Bleeding Hollow Grunt
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21173; -- Zeth'Gor Quest Credit Marker, They Must Burn
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19409; -- Wing Commander Dabir'ee
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21133; -- Corporal Ironridge
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19310; -- Forward Commander Kingston
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1666, `unit_flags`=32768 WHERE `entry`=51800; -- Honor Hold Defender
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=4737 WHERE `entry`=19314; -- Supply Officer Shandria
UPDATE `creature_template` SET `faction`=1666, `npcflag`=0, `unit_flags`=32768 WHERE `entry`=16842; -- Honor Hold Defender
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19434; -- Dreadcaller
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19136; -- Flamewaker Imp
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=18978; -- Heckling Fel Sprite
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19326; -- Legion Antenna: Oblivion
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19328; -- Legion Antenna: Gehenna
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=18679; -- Vorakem Doomspeaker
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19335; -- Subjugator Yalqiz
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19329; -- Legion Antenna: Mageddon
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=19681; -- Void Spawner L
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19527; -- Vacillating Voidcaller
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=17014; -- Collapsing Voidwalker
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21075; -- Infernal Target (Hyjal)
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=19447; -- Brother Daniels
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19455; -- Nurse Judith
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19624; -- Wounded Stormwind Infantry
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19446; -- Operations Officer
UPDATE `creature_template` SET `npcflag`=4736 WHERE `entry`=19452; -- Quartermaster Drake
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19451; -- Quartermaster Gorman
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18931; -- Amish Wildhammer
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18966; -- Justinius the Harbinger
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=19444; -- Peasant Worker
UPDATE `creature_template` SET `maxlevel`=68 WHERE `entry`=18949; -- Stormwind Mage
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16831; -- Nethergarde Infantry
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=67, `unit_flags`=33024 WHERE `entry`=18986; -- Ironforge Paladin
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16864; -- Stormwind Infantry
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18969; -- Melgromm Highmountain
UPDATE `creature_template` SET `faction`=1754, `unit_flags`=0 WHERE `entry`=19005; -- Wrath Master
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68 WHERE `entry`=18972; -- Orgrimmar Shaman
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18948; -- Stormwind Soldier
UPDATE `creature_template` SET `maxlevel`=68, `unit_flags`=33024 WHERE `entry`=18970; -- Darkspear Axe Thrower
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18950; -- Orgrimmar Grunt
UPDATE `creature_template` SET `minlevel`=70, `faction`=1754, `npcflag`=0, `unit_flags`=32768 WHERE `entry`=18944; -- Fel Soldier
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=19179; -- Formation Marker
UPDATE `creature_template` SET `maxlevel`=68 WHERE `entry`=18971; -- Undercity Mage
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19253; -- Lieutenant General Orion
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21252; -- World Trigger (Not Immune PC)
UPDATE `creature_template` SET `npcflag`=4736 WHERE `entry`=19436; -- Supply Master Broog
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19426; -- Peon Overseer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18930; -- Vlagga Freyfeather
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19425; -- Orgrimmar Peon
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19432; -- Injured Grunt
UPDATE `creature_template` SET `minlevel`=72, `speed_walk`=1, `unit_flags2`=2099200 WHERE `entry`=18945; -- Pit Commander
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=19215; -- Infernal Relay (Hellfire)
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=61325; -- Aspic
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=20232; -- Wing Commander Gryphongar
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=20231; -- Supply Officer Pestle
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20251; -- Honor Hold Scout Archery Target
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=20234; -- Runetog Wildhammer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=20235; -- Gryphoneer Windbellow
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19279; -- Legion Antenna: Fear
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19652; -- Disrupt the Communications Quest Credit Marker North
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19282; -- Subjugator Shi'aziv
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19278; -- Legion Antenna: Hate
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19717; -- Disrupt the Communications Quest Credit Marker South
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19277; -- Legion Antenna: Rage
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=18981; -- Doomwhisperer
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19276; -- Legion Antenna: Spite
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=16950; -- Netherhound
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19190; -- Fel Handler
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18975; -- Wrathguard
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21257; -- Apothecary Zelana
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19401; -- Wing Commander Brack
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19273; -- Forward Commander To'arch
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=19315; -- Supply Officer Isabel
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16576; -- Overlord Hun Maimfist
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16599; -- Thrallmar Wolf Rider
UPDATE `creature_template` SET `faction`=190, `unit_flags`=33555200 WHERE `entry`=18849; -- Invis Alliance Siege Engine - East
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16870; -- Shattered Hand Captain
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19410; -- Shattered Hand Neophyte
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16867; -- Shattered Hand Grunt
UPDATE `creature_template` SET `faction`=190, `unit_flags`=33555200 WHERE `entry`=21237; -- Invis Horde Siege Engine - East 02
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=16925; -- Bonechewer Raider
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19443; -- Tagar Spinebreaker
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19411; -- Shattered Hand Warlock
UPDATE `creature_template` SET `faction`=190, `unit_flags`=33555200 WHERE `entry`=18818; -- Invis Horde Siege Engine - East
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=16876; -- Bonechewer Mutant
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19701; -- Bonechewer Evoker
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=18952; -- Bonechewer Scavenger
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19256; -- Sergeant Shatterskull
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=19257; -- Arcanist Torseldori
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19258; -- Bloodmage
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=16587; -- Barley
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=66177 WHERE `entry`=16602; -- Floyd Pinkus
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=49789; -- Allison
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=145, `RangeAttackTime`=2000 WHERE `entry`=18751; -- Kalaen
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=22225; -- Reagan Mancuso
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18749; -- Dalinna
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=17 WHERE `entry`=18755; -- Moorutu
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18267; -- Battlecryer Blackeye
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=145 WHERE `entry`=18754; -- Barim Spilthoof
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `unit_flags`=32768 WHERE `entry`=51903; -- Thrallmar Grunt
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16586; -- Huntsman Torf Angerhoof
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=35099; -- Bana Wildmane
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=16585; -- Cookie One-Eye
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=35093; -- Wind Rider Jahubo
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16600; -- Thrallmar Riding Wolf
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=16590; -- Injured Thrallmar Grunt
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16589; -- Guard Captain Cragtar
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `faction`=1668, `unit_flags`=0 WHERE `entry`=16582; -- Thrallmar Marksman
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=2615; -- Air Force Alarm Bot (Horde)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16584; -- Watch Commander Krunk
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19255; -- General Krakork
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16579; -- Falcon Watch Sentinel
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `npcflag`=129 WHERE `entry`=18752; -- Zebig
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21283; -- Megzeg Nukklebust
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16577; -- Martik Tor'seldori
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16578; -- Blood Elf Pilgrim
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=17585; -- Quartermaster Urgronn
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16574; -- Far Seer Regulkut
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=17 WHERE `entry`=18747; -- Krugosh
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=4227 WHERE `entry`=16583; -- Rohok
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16591; -- Thrallmar Peon
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=3230; -- Nazgrel
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16575; -- Shadow Hunter Ty'jin
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `npcflag`=3219 WHERE `entry`=16588; -- Apothecary Antonivich
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=17004; -- Jir'see
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=17002; -- Angela "The Claw" Kestrel
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=17 WHERE `entry`=18748; -- Ruak Stronghorn
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18753; -- Felannia
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=30735; -- Kul Inkspiller
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `npcflag`=16 WHERE `entry`=30722; -- Neferatti
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=47573; -- Sirabel
UPDATE `creature_template` SET `faction`=1668, `unit_flags`=32768 WHERE `entry`=16580; -- Thrallmar Grunt
UPDATE `creature_template` SET `minlevel`=48, `unit_flags2`=2099200 WHERE `entry`=16598; -- Eye of Thrallmar
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=16915; -- Foreman Razelcraz
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16844; -- Crust Burster
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=20195; -- Dagz
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=768 WHERE `entry`=21847; -- Fel Guard Hound
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=16863; -- Deranged Helboar
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19298; -- Warbringer Arix'Amal
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=19408; -- Maiden of Pain
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=18827; -- Gan'arg Sapper
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000 WHERE `entry`=18976; -- Urga'zz
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=18828; -- Camera Shaker
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=3300; -- Adder
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=15242; -- Bat Rider Guard
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19261; -- Infernal Warbringer
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=18729; -- Infernal Rain (Hellfire)
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=22461; -- Fel Cannon MKI
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=20798; -- Razorsaw
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=16946; -- Mo'arg Forgefiend
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=16960; -- Sister of Grief
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=16954; -- Forge Camp Legionnaire
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=16947; -- Gan'arg Servant
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=16879; -- Starving Helboar
UPDATE `creature_template` SET `faction`=1737, `speed_walk`=1 WHERE `entry`=19324; -- Armored Gryphon Destroyer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=58, `maxlevel`=80 WHERE `entry`=20236; -- Gryphoneer Leafbeard
UPDATE `creature_template` SET `minlevel`=70, `speed_walk`=1, `speed_run`=1.142857, `unit_flags2`=2097152 WHERE `entry`=19397; -- Mo'arg Overseer
UPDATE `creature_template` SET `unit_flags2`=2097152 WHERE `entry`=19400; -- Fel Reaver Sentry
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags2`=2097152 WHERE `entry`=19399; -- Fel Cannon
UPDATE `creature_template` SET `unit_flags2`=2097152 WHERE `entry`=19398; -- Gan'arg Peon
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=24937; -- Magistrix Seyla
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=24959; -- Generic Quest Trigger - LAB
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=24933; -- Suspended Terrorguard
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=24918; -- Felblood Initiate
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=24919; -- Wrath Herald
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80 WHERE `entry`=22323; -- Incandescent Fel Spark
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags2`=1073743872 WHERE `entry`=18733; -- Fel Reaver
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20551; -- Agent Araxes
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=20858; -- Arena Event Controller
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20907; -- Professor Dabiri
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=20903; -- Protectorate Nether Drake
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_class`=2 WHERE `entry`=20451; -- Subservient Flesh Beast
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20450; -- Flesh Handler Viridius
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20092; -- Dealer Hazzin
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20449; -- Researcher Navuud
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80, `faction`=1731, `unit_flags`=768 WHERE `entry`=20071; -- Wind Trader Marid
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20448; -- Commander Ameer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=20447; -- Protectorate Vanguard
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20452; -- Ethereum Assassin
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20727; -- Captain Zovax
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20456; -- Ethereum Researcher
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=20676; -- Ethereum Sparring Dummy
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20453; -- Ethereum Shocktrooper
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20554; -- Arconus the Insatiable
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `unit_flags2`=2099200 WHERE `entry`=19565; -- Enormous Void Storm
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags2`=2097152 WHERE `entry`=20899; -- Void Conduit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=33555264, `unit_flags2`=2099200 WHERE `entry`=19554; -- Dimensius the All-Devouring
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18877; -- Nether Drake
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20501; -- Seeping Sludge
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags2`=2099200 WHERE `entry`=19336; -- Void Spawner XL
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18869; -- Unstable Voidwraith
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18870; -- Voidshrieker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags3`=1 WHERE `entry`=20933; -- Camera Shakers Manaforge Ultris
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20340; -- Fleshfiend
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=536903680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=20561; -- Withered Corpse
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22822; -- Ethereum Nullifier
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20607; -- Craghide Basilisk
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=22821; -- Ethereum Avenger
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `unit_flags2`=2099200 WHERE `entry`=19568; -- Unending Voidwraith
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20459; -- Ethereum Overlord
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20458; -- Ethereum Archon
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20520; -- Ethereum Prisoner
UPDATE `creature_template` SET `faction`=35 WHERE `entry`=20764; -- Ethereum Target
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20770; -- Warden Icoshock
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20778; -- Void Waste
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20825; -- Ethereum Prisoner (Tyralius)
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20474; -- Ethereum Nexus-Stalker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=20454; -- Nexus-King Salhadaar
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20769; -- Salaadin's Energy Ball
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20780; -- Kaylaan
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=20922; -- Fallen Vindicator
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=20112; -- Wind Trader Tuluman
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=18860; -- Daughter of Destiny
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=20393; -- Foreman Sundown
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=20326; -- Mo'arg Warp-Master
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=20285; -- Gan'arg Warp-Tinker
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=20804; -- Netherstorm Moarg Work Target
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21089; -- Sunfury Blood Knight
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=20248; -- Sunfury Nethermancer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20803; -- Overmaster Grindgarr
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=33554688 WHERE `entry`=23491; -- Socrethar Event Trigger
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=1786, `speed_walk`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33344, `unit_flags2`=2099200 WHERE `entry`=20132; -- Socrethar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=90, `speed_walk`=1.6 WHERE `entry`=20929; -- Wrath Lord
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=90, `speed_walk`=1.6 WHERE `entry`=20930; -- Hatecryer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20516; -- Warp Monstrosity
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20913; -- Tashar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20931; -- Tyrantus
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20634; -- Scythetooth Raptor
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=90, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=20138; -- Culuthas
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=90, `speed_walk`=1, `speed_run`=1.142857, `unit_flags`=33555200, `unit_flags3`=1 WHERE `entry`=20133; -- Image of Socrethar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_class`=1, `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=20148; -- Dead Doomguard
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `unit_flags`=33555200 WHERE `entry`=20473; -- Surveying Marker One
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=69, `unit_flags3`=1 WHERE `entry`=21157; -- Culuthas Scan Target Dummy
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=90, `speed_run`=1.142857 WHERE `entry`=20394; -- Eye of Culuthas
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=90 WHERE `entry`=20141; -- Hound of Culuthas
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=20202; -- Cragskaar
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=778, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=18886; -- Farahlon Breaker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=22351; -- Eastern Gehenna Teleporter Credit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=20928; -- Ironspine Forgelord
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=18859; -- Wrath Priestess
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=22348; -- Western Gehenna Teleporter Credit
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=16943; -- Cyber-Rage Forgelord
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=18858; -- Wrathbringer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18882; -- Sundered Thunderer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=20800; -- Forgemaster Morug
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `faction`=35, `unit_flags`=262912, `unit_flags2`=2099200 WHERE `entry`=22293; -- Inactive Fel Reaver
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=22358; -- Nether Gas Visual Trigger
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21923; -- Terrorguard Protector
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=16949; -- Gan'arg Mekgineer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=22899; -- Protectorate Advisor Rahim
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags3`=1 WHERE `entry`=20084; -- Image of Nexus-Prince Haramad
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=19583; -- Grennik
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20470; -- Zephyrion
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=20471; -- Nether-Stalker Nauthis
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19540; -- Asarnan
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=145 WHERE `entry`=19539; -- Jazdalaad
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20775; -- Markaru
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20068; -- Zuben Eschamali
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20067; -- Zuben Elgenubi
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20811; -- Ghabar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19531; -- Eyonix
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20242; -- Karaaz
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20871; -- Aurine Moonblaze
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=22427; -- Zarevhi
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22065; -- Air Force Guard Post (Ethereal - Stormspire)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22068; -- Air Force Trip Wire - Rooftop (Ethereal - Stormspire)
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=19529; -- Stormspire Nexus-Guard
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20610; -- Talbuk Doe
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20777; -- Talbuk Sire
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20774; -- Farahlon Lasher
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20810; -- Mehrdad
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20066; -- Gahruj
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20921; -- Shauly Pore
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=20194; -- Dealer Dunar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19728; -- Mama Wheeler
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=20773; -- Barbscale Crocolisk
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=33555200 WHERE `entry`=20611; -- Shimmerwing Moth
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=20671; -- Ripfang Lynx
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=19738; -- Doomclaw
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20281; -- Drijya
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20296; -- Teleporter Explosion Trigger
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20404; -- Warp-Gate Engineer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=16944; -- Mo'arg Doomsmith
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=16948; -- Gan'arg Engineer
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19940; -- Apex
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18883; -- Mana Snapper
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19705; -- Master Daellis Dawnstrike
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20139; -- Sunfury Conjurer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19657; -- Summoner Kanthin
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=19653; -- Glacius
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20140; -- Sunfury Centurion
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `npcflag`=0 WHERE `entry`=20435; -- Overseer Athanel
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20207; -- Sunfury Bowman
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_walk`=1.6, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=20673; -- Swiftwing Shredder
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=20515; -- Harpax
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=0 WHERE `entry`=22494; -- Cosmowrench Bruiser
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=22479; -- Sab'aoth
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=18884; -- Warp Chaser
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20483; -- Naberius
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20415; -- Bessy
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20495; -- Skeletal Stallion
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19544; -- Conjurer Luminrath
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20410; -- Rhonsus
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20409; -- Kirin'Var Apprentice
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19543; -- Battle-Mage Dathric
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19545; -- Cohlien Frostweaver
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19546; -- Abjurist Belmara
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19494; -- Ar'kelos
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=19481; -- Archmage Vargoth
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19488; -- Custodian Dieworth
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=19489; -- Lieutenant-Sorcerer Morran
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20463; -- Apprentice Andrethan
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20934; -- Severed Defender
UPDATE `creature_template` SET `faction`=190, `unit_flags`=33554432 WHERE `entry`=6368; -- Cat
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20464; -- Thadell
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20512; -- Tormented Soul
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21065; -- Tormented Citizen
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19926; -- Spellreaver Marathelle
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20221; -- Sunfury Flamekeeper
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19707; -- Sunfury Archer
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19939; -- Netherstorm Nether Beast Target
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19731; -- Nether Beast
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19727; -- Netherstorm Shoot Target
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19881; -- Severed Spirit
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=6271; -- Mouse
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=19547; -- Invis Bookshelf
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=18866; -- Mageslayer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=18867; -- Mana Seeker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19593; -- Spellbinder Maryana
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19840; -- Caledis Brightdawn
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19839; -- Lariel Sunrunner
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19830; -- Arcanist Ardonis
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19831; -- Commander Dawnforge
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=20136; -- Sunfury Researcher
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20135; -- Sunfury Arch Mage
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18850; -- Sunfury Guardsman
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=20134; -- Sunfury Arcanist
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19641; -- Warp-Raider Nesaad
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19690; -- N. D. Meancamp
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=768, `unit_flags2`=2097152 WHERE `entry`=20243; -- Scrapped Fel Reaver
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags`=32832 WHERE `entry`=20772; -- Netherock
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20338; -- Western Pipe Credit Marker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=18856; -- Arcane Annihilator
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20337; -- Southern Pipe Credit Marker
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20416; -- Overseer Theredis
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19421; -- Netherstorm Crystal Target
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19686; -- Nether Anomaly
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62627; -- Petite raie du Néant
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19437; -- Netherstorm Kneel Target
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19643; -- Sunfury Astromancer
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18855; -- Sunfury Magister
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19453; -- Sunfury Captain
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18853; -- Sunfury Bloodwarder
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=18857; -- Sunfury Warp-Master
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19484; -- Netherstorm Repair Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19483; -- Netherstorm Use Standing Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=19439; -- Netherstorm Work Mining Target
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18852; -- Sunfury Warp-Engineer
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19779; -- Sunfury Geologist
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18875; -- Zaxxis Raider
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19642; -- Zaxxis Stalker
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18865; -- Warp Aberration
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62625; -- Cafard du Néant
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20215; -- Pentatharon
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=19852; -- Artifact Seeker
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19853; -- Felblade Doomguard
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18885; -- Farahlon Giant
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19849; -- Scrap Reaver X6000
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19832; -- Doctor Vomisa, Ph.T.
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19634; -- Lead Sapper Blastfizzle
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=21262; -- Goblin Equipment Trigger
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=21261; -- Big Wagon Full of Explosives Trigger
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=29145; -- Pulik Swiftsnip
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=65 WHERE `entry`=21732; -- Nandirx
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=19776; -- Experimental Pilot
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=67 WHERE `entry`=21733; -- Karzo
UPDATE `creature_template` SET `minlevel`=66, `maxlevel`=66 WHERE `entry`=28343; -- Meeda
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=20389; -- Lee Sparks
UPDATE `creature_template` SET `minlevel`=67 WHERE `entry`=19575; -- Qiff
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=19576; -- Xyrol
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19709; -- Chief Engineer Trep
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=20162; -- Veronia
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=19655; -- Area 52 Ethereal Technology Bunny
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19621; -- Bill
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18938; -- Krexcil
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=107619; -- Blaze Magmaburn
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=19654; -- Area 52 Analyzer Bunny
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=58152; -- Tini Smalls
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23396; -- Krixel Pinchwhistle
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=107610; -- Kitzie Crankshot
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=107599; -- Izzee the 'Clutch'
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19645; -- Papa Wheeler
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=54648; -- Leeni "Smiley" Smalls
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21493; -- Kablamm Farflinger
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=1 WHERE `entry`=19845; -- Area 52 Fireworks Controller
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19570; -- Rocket-Chief Fuselage
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=72823; -- Bill Porter
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19880; -- Nether-Stalker Khay'ji
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22280; -- Soren
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22279; -- Nadja
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=67 WHERE `entry`=19612; -- Irradiated Manager
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19617; -- Boots
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19217; -- Ravandwyr
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=1, `maxlevel`=1, `npcflag`=1, `unit_flags`=32768 WHERE `entry`=20102; -- Goblin Commoner
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=19737; -- Engineering Crewmember
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19466; -- Exarch Orelis
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19623; -- Doc
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=63, `maxlevel`=63, `npcflag`=4194433 WHERE `entry`=24974; -- Liza Cutlerflix
UPDATE `creature_template` SET `minlevel`=19, `maxlevel`=19 WHERE `entry`=24977; -- Warpy
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22063; -- Air Force Trip Wire - Rooftop (Goblin - Area 52)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19468; -- Spymaster Thalodien
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19469; -- Magistrix Larynna
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19467; -- Anchorite Karja
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19571; -- Innkeeper Remi Dodoso
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=19651; -- Seasoned Vindicator
UPDATE `creature_template` SET `maxlevel`=55 WHERE `entry`=17636; -- Kalynna Lathred
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=21997; -- Air Force Guard Post (Goblin - Area 52 - Zeppelin)
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=65 WHERE `entry`=19573; -- Dash
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=0 WHERE `entry`=19541; -- Netherstorm Agent
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80, `unit_flags2`=0 WHERE `entry`=20284; -- Dr. Boom
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19692; -- Boom Bot
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18881; -- Sundered Rumbler
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18864; -- Mana Wraith
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=21058; -- Disembodied Exarch
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18873; -- Disembodied Protector
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18872; -- Disembodied Vindicator
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.8571429, `unit_flags2`=2048 WHERE `entry`=64374; -- Cafard du Néant
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768, `unit_flags2`=0 WHERE `entry`=18880; -- Nether Ray
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20210; -- Shaleskin Flayer
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18879; -- Phase Hunter
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=19569; -- Netherologist Coppernickels
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=20203; -- Nether Technician
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62628; -- Jeune basilic brûlé
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20514; -- Searing Elemental
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20925; -- Scalded Basilisk
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19961; -- Doomforge Attendant
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21233; -- Legion Fel Cannon
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=22422; -- Blade's Edge - Legion - Anger Camp - Invis Bunny
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=19960; -- Doomforge Engineer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=16952; -- Anger Guard
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=20998; -- Ridgespine Horror
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=21124; -- Felsworn Daggermaw
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=21123; -- Felsworn Scalewing
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21300; -- Fel Corrupter
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=21053; -- Blade's Edge - Orb Trigger 03
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20856; -- Blade's Edge - Deadsoul Orb Flight 05
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20666; -- Blade's Edge - Orb Trigger 01
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20855; -- Blade's Edge - Deadsoul Orb Flight 04
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20670; -- Blade's Edge - Flesh Beast Zap Trigger
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20852; -- Blade's Edge - Deadsoul Orb Flight 02
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20668; -- Fiendling Flesh Beast
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20853; -- Blade's Edge - Deadsoul Orb Flight 03
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20609; -- Razaani Nexus Stalker
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20601; -- Razaani Raider
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20614; -- Razaani Spell-Thief
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20851; -- Blade's Edge - Deadsoul Orb Flight 01
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=51786; -- Mok'Nathal Hunter
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22312; -- Spiritcaller Dohgar
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21103; -- Spiritcaller Grakosh
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21106; -- Spiritcaller Skrash
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=21105; -- Spiritcaller Roxnak
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22468; -- Ogrin
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21088; -- Matron Varah
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22004; -- Leoroxx
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=22110; -- Tethik
UPDATE `creature_template` SET `npcflag`=640 WHERE `entry`=21082; -- Krugash
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21692; -- Cansis
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21496; -- Dertrok
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21896; -- Silmara
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21895; -- Taerek
UPDATE `creature_template` SET `npcflag`=16 WHERE `entry`=21087; -- Grikka
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=22455; -- Sky-Master Maxxor
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20161; -- Vekh'nir Matriarch
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19982; -- Vekh'nir Keeneye
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21840; -- Cosmetic Silkwing
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=21839; -- Mature Silkwing
UPDATE `creature_template` SET `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=20747; -- Silkwing Larva
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857, `unit_flags`=33554432 WHERE `entry`=22472; -- Death's Door South Warp-Gate
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `faction`=954, `speed_run`=1.142857, `unit_flags2`=0 WHERE `entry`=22443; -- Death's Door Fel Cannon
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=19978; -- Deathforge Over-Smith
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=22502; -- Death's Door Warp-Gate Explosion Bunny
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22500; -- Void Hound
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22474; -- Unstable Fel-Imp
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19980; -- Void Terror
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857, `unit_flags2`=0 WHERE `entry`=51612; -- Death's Door Fel Cannon
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=19747; -- Baelmon the Hound-Master
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=0 WHERE `entry`=22423; -- Evergrove Druid
UPDATE `creature_template` SET `unit_flags`=33554688, `unit_flags3`=1 WHERE `entry`=20736; -- Blade's Edge - Legion - Invis Bunny
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22305; -- Vekh
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19979; -- Deathforge Technician
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=20751; -- Daggermaw Lashtail
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19984; -- Vekh'nir Dreadhawk
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=110, `faction`=14, `speed_walk`=1.6, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115644; -- Scalewing Queen
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19983; -- Vekh'nir Stormcaller
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=20749; -- Scalewing Serpent
UPDATE `creature_template` SET `maxlevel`=80, `BaseAttackTime`=2857 WHERE `entry`=21254; -- Dullgrom Dredger
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21032; -- Dreadwing
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=1, `unit_flags`=0 WHERE `entry`=21004; -- Lesser Nether Drake
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21189; -- Crystal Flayer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21413; -- Gnome Cannon Shooter #1
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21935; -- Gnome Cannon Shooter #Shattrath
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21944; -- Gnome Cannon Shooter #Ruuan
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=21107; -- Rip Pedalslam
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21930; -- Gnome Cannon Shooter #0
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21111; -- Bembil Knockhammer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21112; -- Bossi Pentapiston
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21113; -- Sassa Weldwell
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21152; -- Station Bot-Jock
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21691; -- Toshley
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21824; -- Dizzy Dina
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21393; -- Cannon Channeler
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21110; -- Fizit "Doc" Clocktock
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21461; -- Rally Zapnabber
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21755; -- Nickwinkle the Metro-Gnome
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21494; -- Smiles O'Byron
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21460; -- Tally Zapnabber
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22090; -- Air Force Guard Post (Toshley's Station - Flying Machine)
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=21118; -- Razak Ironsides
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=0.5, `speed_run`=0.7142857, `unit_flags`=32768 WHERE `entry`=20714; -- Ridgespine Stalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21447; -- Blade's Edge - Toshley's - Def Gun Attack Origin
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21114; -- Station Technician
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=21942; -- Gnome Cannon Shooter #Singing Ridge
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=68841; -- Raptor lamerouage
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=22123; -- Rip-Blade Ravager
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21519; -- Death's Might
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20765; -- Bladespire Crusher
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20766; -- Bladespire Mystic
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20768; -- Gnosh Brognat
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19476; -- Lor
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19471; -- Old Orok
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19478; -- Fera Palerunner
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18953; -- Unoke Tenderhoof
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19470; -- Gholah
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21311; -- Rokgah Bloodgrip
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=23280; -- Agadai
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21117; -- Gor'drek
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21147; -- Tor'chunk Twoclaws
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=18248; -- Nekthar
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=113, `maxlevel`=113, `unit_flags2`=2099200 WHERE `entry`=21984; -- Rexxar
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21516; -- Death's Watch
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857, `unit_flags2`=2099200 WHERE `entry`=21690; -- R-3D0
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=21956; -- Rema
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=21033; -- Bladewing Bloodletter
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=20748; -- Thunderlord Dire Wolf
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18937; -- Amerun Leafshade
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19499; -- Cahill
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=19495; -- Innkeeper Shaunessy
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19497; -- Caoileann
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80, `npcflag`=4194433 WHERE `entry`=22469; -- Fiskal Shadowsong
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21197; -- Bronwyn Stouthammer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21151; -- Borgrim Stouthammer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19498; -- Tanaide
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21066; -- Rina Moonspring
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21158; -- Commander Skyshadow
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=20126; -- Sylvanaar Ancient Protector
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=18098; -- Kialon Nightblade
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20095; -- Grimnok Battleborn
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1.6, `unit_flags`=32768 WHERE `entry`=21294; -- Bloodmaul Goon
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=110, `faction`=1781, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115598; -- Empowered Earth Elemental
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=110, `faction`=1781, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115597; -- Geo-Lord Garug
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21349; -- T'chali the Witch Doctor
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19952; -- Bloodmaul Geomancer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20726; -- Mugdorg
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20730; -- Glumdor
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20723; -- Korgaah
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21975; -- Bladespire Sober Defender
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20230; -- Blade's Edge - Bladespire Trigger 01
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=20334; -- Bladespire Cook
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21352; -- Ogre Building Bunny Summoner
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21277; -- Vindicator Vuuleen
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21296; -- Bladespire Champion
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19995; -- Bladespire Brute
UPDATE `creature_template` SET `maxlevel`=80, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20728; -- Bladespire Raptor
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19998; -- Bladespire Shaman
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21380; -- Greater Crust Burster
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=23217; -- Bladespire Agent
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22941; -- Mog'dorg the Wizened
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22995; -- Chort
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=22216; -- Fhyn Leafshadow
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21983; -- Samia Inkling
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22007; -- Tree Warden Chawn
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22020; -- O'Mally Zapnabber
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `speed_run`=1.142857 WHERE `entry`=22021; -- O'Mally's Instrument Bunny
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=22053; -- Mosswood the Ancient
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21782; -- Timeon
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22465; -- Natasha
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22924; -- Arthorn Windsong
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22922; -- Innkeeper Aelerya
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22127; -- Wildlord Antelarion
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22150; -- Lieutenant Fairweather
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22149; -- Commander Haephus Stonewall
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20211; -- Ruuan'ok Matriarch
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20987; -- Ruuan Weald Basilisk
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19987; -- Ruuan'ok Ravenguard
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19985; -- Ruuan'ok Cloudgazer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19986; -- Ruuan'ok Skyfury
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=21981; -- Overseer Nuaar
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `unit_flags`=0 WHERE `entry`=883; -- Deer
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=80 WHERE `entry`=20889; -- Ethereum Prisoner (Group Energy Ball)
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22241; -- Bash'ir Raider
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=67, `maxlevel`=80 WHERE `entry`=22919; -- Image of Commander Ameer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=23395; -- Bash'ir Landing Boss Bunny
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22242; -- Bash'ir Spell-Thief
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22244; -- Unbound Ethereal
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags2`=0, `unit_flags3`=1 WHERE `entry`=23241; -- Skyguard Aether-Tech
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `faction`=250, `unit_flags`=32768, `unit_flags2`=0 WHERE `entry`=23430; -- Skyguard Lieutenant
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `faction`=250, `unit_flags`=32768, `unit_flags2`=0 WHERE `entry`=23242; -- Skyguard Ranger
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22243; -- Bash'ir Arcanist
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=23246; -- Slavering Slave
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23261; -- Furywing
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21021; -- Scorch Imp
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=23153; -- Bash'ir Surveyor
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23281; -- Insidion
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=23154; -- Mana-Debt Slave
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=22255; -- Daggertail Lizard
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20757; -- Fingrom
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20756; -- Bladespire Chef
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19996; -- Bladespire Battlemage
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=1.6, `speed_run`=1.428571, `unit_flags`=32832 WHERE `entry`=18693; -- Speaker Mar'grom
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=22918; -- Gronn Showdown Bunny
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=22268; -- Leokk
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20729; -- Bladespire Ravager
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19997; -- Bladespire Enforcer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20753; -- Dorgok
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=22480; -- Brown Marmot
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22384; -- Bloodmaul Soothsayer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22160; -- Bloodmaul Taskmaster
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19993; -- Bloodmaul Mauler
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19994; -- Bloodmaul Warlock
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20330; -- Bloodmaul Battle Worg
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=22052; -- Daggermaw Blackhide
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21381; -- Young Crust Burster
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22386; -- Watcher Moonshade
UPDATE `creature_template` SET `speed_run`=0.5714286, `RangeAttackTime`=2000 WHERE `entry`=22206; -- Expedition Druid
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=3681; -- Wisp
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=21809; -- Wyrmcult Poacher
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=22308; -- Wyrmcult Hunter
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22396; -- Draaca Longtail
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22040; -- Cave Bat
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21810; -- Wyrmcult Hewer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20329; -- Grishna Matriarch
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20924; -- Grishnath Basilisk
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19988; -- Grishna Falconwing
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19989; -- Grishna Harbinger
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19990; -- Grishna Scorncrow
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22215; -- Treebole
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21048; -- Boulder'mok Chieftain
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21047; -- Boulder'mok Shaman
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21046; -- Boulder'mok Brute
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21383; -- Wyrmcult Acolyte
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21040; -- Outraged Raven's Wood Sapling
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=21497; -- Blackscale
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=1, `unit_flags`=0 WHERE `entry`=21387; -- Wyrmcult Blackwhelp
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21637; -- Wyrmcult Scout
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=21326; -- Raven's Wood Leafbeard
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21325; -- Raven's Wood Stonebark
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21042; -- Dire Raven
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=21382; -- Wyrmcult Zealot
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22019; -- Kolphis Darkscale
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=22282; -- Witness of Doom
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22195; -- Wrath Speaker
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20557; -- Wrath Hound
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22291; -- Furnace Guard
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=22196; -- Wrath Reaver
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23120; -- Sky Sergeant Vanderlip
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23208; -- Skyguard Pyrotechnician
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=4194433 WHERE `entry`=23392; -- Skyguard Stable Master
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23334; -- Sky Commander Keller
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23413; -- Skyguard Handler Irena
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22982; -- Skyguard Navigator
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23335; -- Skyguard Khatie
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=23473; -- Aether-tech Apprentice
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22254; -- Wrath Corruptor
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=23257; -- Skyguard Windcharger
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=80 WHERE `entry`=22987; -- Skyguard Nether Ray
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags2`=2099200 WHERE `entry`=23500; -- Legion Ring Shield Zapper InvisMan
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags2`=2099200 WHERE `entry`=23059; -- Legion Ring Event InvisMan
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=18692; -- Hemathion
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=23301; -- Dragon Bunny
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=23347; -- Tork
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=71 WHERE `entry`=23110; -- Ogri'la Keg King
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22270; -- Ogri'la Merchant
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22271; -- Ogri'la Trader
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22266; -- Ogri'la Grubgiver
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23233; -- Chu'a'lor
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23316; -- Torkus
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23428; -- Jho'nass
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=65, `maxlevel`=80 WHERE `entry`=22264; -- Ogri'la Steelshaper
UPDATE `creature_template` SET `maxlevel`=71 WHERE `entry`=23256; -- Ogri'la Storyteller
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=23255; -- Kronk's Book Bunny
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=23253; -- Kronk
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=73 WHERE `entry`=23112; -- Mingo
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=70, `maxlevel`=70 WHERE `entry`=23300; -- Gahk
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=23362; -- Torki
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=23115; -- Ogri'la Peacekeeper
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=2147483648, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=23282; -- Obsidia
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=62184; -- Vipère des rochers
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags2`=2099200, `unit_flags3`=1, `HoverHeight`=10 WHERE `entry`=23061; -- Rivendark
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22923; -- Simon Game Bunny
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `faction`=90, `unit_flags`=32768 WHERE `entry`=23385; -- Simon Unit
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61326; -- Scorpide
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=19656; -- Invisible Location Trigger
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=22175; -- Apexis Flayer
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=23378; -- Simon Game Bunny Large
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=22304; -- Mo'arg Extractor
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21203; -- Blade's Edge - Rock Flayer Target
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=23174; -- Crystalfused Miner
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=22181; -- Aether Ray
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19973; -- Abyssal Flamebringer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=22180; -- Shard-Hide Boar
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags2`=2099200 WHERE `entry`=23512; -- Crystalforge Bunny
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22298; -- Vile Fire-Soul
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=22204; -- Fear Fiend
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `speed_run`=1.142857, `unit_flags2`=2097152 WHERE `entry`=23076; -- Legion Flak Cannon
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=20113; -- Lashh'an Matriarch
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `unit_flags3`=1 WHERE `entry`=20003; -- Blade's Edge Kneel Target 01
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19943; -- Lashh'an Talonite
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=20093; -- Blade's Edge - Arakkoa Spell Origin
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `unit_flags3`=1 WHERE `entry`=20024; -- Blade's Edge Kneel Target 03
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `unit_flags3`=1 WHERE `entry`=20023; -- Blade's Edge Kneel Target 02
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19944; -- Lashh'an Wing Guard
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=61 WHERE `entry`=20127; -- Tame Kaliri
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=19945; -- Lashh'an Windwalker
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=21022; -- Grovestalker Lynx
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21074; -- Living Grove Defender Trigger
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=20713; -- Fey Drake
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19992; -- Bloodmaul Shaman
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=15476; -- Scorpid
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19948; -- Bloodmaul Skirmisher
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19957; -- Bloodmaul Brewmaster
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80, `faction`=1781, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=20058; -- Bloodmaul Dire Wolf
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=19991; -- Bloodmaul Brute
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=80 WHERE `entry`=21238; -- Bloodmaul Drudger
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=22044; -- Cavern Crawler
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=22489; -- Grunt Grahk
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=17998; -- Umbrafen Steam Pump Credit Marker
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18138; -- Umbrafen Eel
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20079; -- Darkcrest Sentry
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18122; -- Dreghood Drudge
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19947; -- Darkcrest Sorceress
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=19946; -- Darkcrest Slaver
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18137; -- Marsh Dredger
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18912; -- Sporelok
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18136; -- Marsh Lurker
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18476; -- Timber Worg
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18586; -- Coosh'coosh
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18080; -- Kataru
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=17969; -- Kayra Longmane
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1 WHERE `entry`=20115; -- Umbrafen Witchdoctor
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18077; -- Umbrafen Oracle
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1, `unit_flags`=0 WHERE `entry`=18079; -- Umbrafen Seer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=18281; -- Boglash
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=17901; -- Keleth
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=18911; -- Juno Dufrain
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=18070; -- Windcaller Blackhoof
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=17858; -- Warden Hamoot
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=17900; -- Ashyen
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=70, `maxlevel`=70 WHERE `entry`=22832; -- Morthis Whisperwing
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=17956; -- Ikeyen
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18332; -- Talut
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `npcflag`=4194433 WHERE `entry`=17896; -- Kameel Longstride
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=17909; -- Lauranna Thar'well
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `npcflag`=66177 WHERE `entry`=18907; -- Innkeeper Coryth Stoktron
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=18993; -- Naka
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=17904; -- Fedryen Swiftspear
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=17834; -- Lethyn Moonfire
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80, `npcflag`=641 WHERE `entry`=21172; -- Sarinei Whitestar
UPDATE `creature_template` SET `faction`=2000, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=119287; -- Fenglow Stinger
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=17841; -- Ysiel Windsinger
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=0 WHERE `entry`=17855; -- Expedition Warden
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=20762; -- Gur'zil
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18243; -- Lorti
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=21993; -- Air Force Guard Post (Horde - Bat Rider)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `npcflag`=4739 WHERE `entry`=18011; -- Zurai
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22002; -- Air Force Trip Wire - Ground (Horde)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22001; -- Air Force Trip Wire - Rooftop (Horde)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=18012; -- Reavij
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=18016; -- Magasha
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=20283; -- Marshrock Stomper
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=18035; -- Scout Jyoba
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=20324; -- Parched Hydra
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18124; -- Withered Giant
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=19706; -- Marshrock Threshalisk
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19402; -- Withered Bog Lord
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0, `unit_flags2`=0 WHERE `entry`=18130; -- Marshfang Ripper
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=18132; -- Umbraglow Stinger
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=20387; -- Young Sporebat
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18044; -- Rajis Fyashe
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18000; -- Serpent Steam Pump Credit Marker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20089; -- Bloodscale Wavecaller
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=20088; -- Bloodscale Overseer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=20292; -- Marsh Baron Brok
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=20291; -- Lagoon Walker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=20290; -- Lagoon Eel
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=18213; -- Mire Hydra
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18197; -- Elder Kuruti
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18114; -- Feralfen Mystic
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1, `unit_flags`=0 WHERE `entry`=18113; -- Feralfen Hunter
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=0, `unit_flags2`=0 WHERE `entry`=20196; -- Bloodthirsty Marshfang
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=20270; -- Feralfen Druid
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=18128; -- Sporebat
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18134; -- Fen Strider
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18212; -- Mudfin Frenzy
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18214; -- Fenclaw Thrasher
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=18908; -- Innkeeper Kerp
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=20028; -- Doba
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18010; -- Maktu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18008; -- Ikuti
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22003; -- Air Force Trip Wire - Ground (Alliance)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=21999; -- Air Force Trip Wire - Rooftop (Alliance)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=19722; -- Muheru the Weaver
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=22485; -- Halu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18009; -- Puluu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80 WHERE `entry`=18019; -- Timothy Daniels
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=20197; -- Bogflare Needler
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18159; -- Boss Grog'ak
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18118; -- Ango'rosh Shaman
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18117; -- Ango'rosh Ogre
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=20442; -- Captain Bo'kar
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=18115; -- Daggerfen Muckdweller
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=19174; -- Chieftain Mummaki
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=0.5 WHERE `entry`=18116; -- Daggerfen Assassin
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18992; -- Captain Krosh
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=19732; -- Ango'rosh Warlock
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18119; -- Ango'rosh Brute
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=20443; -- Ango'rosh Sentry
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18002; -- Marshlight Steam Pump Credit Marker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18340; -- Steam Pump Overseer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20090; -- Bloodscale Sentry
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1, `unit_flags3`=1 WHERE `entry`=19733; -- Daggerfen Servant
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20477; -- Terrorclaw
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=33587200, `unit_flags3`=1 WHERE `entry`=18123; -- Wrekt Slave
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=18089; -- Bloodscale Slavedriver
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=20294; -- Bogstrok Razorclaw
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18088; -- Bloodscale Enchantress
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=20295; -- Bogstrok Crusher
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=19730; -- Ironspine Gazer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=19729; -- Ironspine Threshalisk
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857, `RangeAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=18680; -- Marticar
UPDATE `creature_template` SET `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66536; -- Lumiroir
UPDATE `creature_template` SET `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66534; -- Fongor
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=17925; -- Gshaff
UPDATE `creature_template` SET `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66535; -- Tripatte
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=1500, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=66551; -- Ras’an
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=17866; -- Khn'nix
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `faction`=35, `speed_run`=1.142857 WHERE `entry`=17856; -- Gzhun'tt
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=17924; -- Msshi'fn
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=17877; -- Fhwoor
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22829; -- Outland Children's Week Sporeggar Trigger
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=22823; -- Hch'uu
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `faction`=35, `speed_run`=1.142857 WHERE `entry`=18382; -- Mycah
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18140; -- Sporeggar Harvester
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.142857 WHERE `entry`=18139; -- Sporeggar Preserver
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22087; -- Air Force Guard Post (Sporeggar - Sporebat)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22088; -- Air Force Trip Wire - Rooftop (Sporeggar)
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62564; -- Pousse de sporelin
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61071; -- Petite grenouille
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=17923; -- Fahssn
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20293; -- Bogstrok Clacker
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=17378; -- Swamp Gas
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=20280; -- Ragestone Trampler
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=20198; -- Fenglow Stinger
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80 WHERE `entry`=20279; -- Ragestone Threshalisk
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18125; -- Starving Fungal Giant
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=19519; -- Starving Bog Lord
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=18358; -- Sporeggar Spawn
UPDATE `creature_template` SET `faction`=31, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=61142; -- Serpent
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=0 WHERE `entry`=18133; -- Marshlight Bleeder
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=18129; -- Greater Sporebat
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=2914; -- Snake
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18135; -- Marsh Walker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=80, `unit_flags`=0, `unit_flags2`=0 WHERE `entry`=18131; -- Marshfang Slicer


UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=23269; -- Barash the Den Mother
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23209; -- Dragonmaw Peon Kill Credit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23267; -- Arvoar the Rapacious
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=23305; -- Crazed Murkblood Foreman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23164; -- Toranaku
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23324; -- Crazed Murkblood Miner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23264; -- Overmine Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23166; -- Ronag the Slave Driver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23285; -- Nethermine Burster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23149; -- Mistress of the Mines
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23291; -- Chief Overseer Mudlump
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23150; -- Dragonmaw Pitfighter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23148; -- Forgus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23143; -- Horus
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23289; -- Mine Car
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23376; -- Dragonmaw Foreman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22433; -- Ja'y Nosliw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23140; -- Taskmaster Varkule Dragonbreath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23141; -- Yarzill the Merc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23427; -- Illidari Lord Balthas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23142; -- Goblin Merc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23139; -- Overlord Mor'ghor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23144; -- Gug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23145; -- Rumpus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23489; -- Drake Dealer Hurlunk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23146; -- Dragonmaw Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23370; -- Dragonmaw Tower Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23345; -- Wing Commander Ichman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23348; -- Captain Skyshatter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23344; -- Corlok the Vet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23342; -- Trope the Filth-Belcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23340; -- Murg "Oldie" Muckjaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23346; -- Wing Commander Mulverick
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=23286; -- Black Blood of Draenor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22253; -- Dragonmaw Ascendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23311; -- Disobedient Dragonmaw Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22274; -- Dragonmaw Skybreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23326; -- Nethermine Ravager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23287; -- Murkblood Miner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23169; -- Nethermine Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23309; -- Murkblood Overseer
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23308; -- Dragonmaw Peon Work Node
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22252; -- Dragonmaw Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23501; -- Netherwing Ray
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23225; -- Netherwing Drake Escape Point
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23188; -- Dragonmaw Transporter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21720; -- Dragonmaw Shaman
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22317; -- Netherwing Drake Escape Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21722; -- Enslaved Netherwing Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21717; -- Dragonmaw Wrangler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22112; -- Karynaku
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21721; -- Enslaved Netherwing Whelp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21718; -- Dragonmaw Subjugator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21901; -- Netherskate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21719; -- Dragonmaw Drake-Rider
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=21171; -- Alandien
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=21178; -- Varedis
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=21164; -- Netharel
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21892; -- Azaloth Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21506; -- Azaloth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21179; -- Demon Hunter Supplicant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21908; -- Spellbound Terrorguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21505; -- Sunfury Summoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21180; -- Demon Hunter Initiate
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=21168; -- Theras
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21503; -- Sunfury Warlock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113941; -- Invisible Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22860; -- Illidari Succubus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22858; -- Shadowhoof Assassin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22859; -- Shadowhoof Summoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21166; -- Illidari Dreadlord
UPDATE `creature_template` SET `type`=3, `VerifiedBuild`=25996 WHERE `entry`=22134; -- Shadowmoon Eye of Kilrogg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22082; -- Shadowmoon Slayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22934; -- Black Temple Battle Sensor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22966; -- Lightsworn Elekk Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22857; -- Illidari Ravager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21743; -- Sunfury Blood Lord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22515; -- World Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22861; -- Lightsworn Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21742; -- Sunfury Eradicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22863; -- Seasoned Magister
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=22862; -- Anchorite Caalen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22864; -- Fyra Dawnstar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23033; -- Invisible Stalker (Floating)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24925; -- Boss Portal: Purple (3.00)
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22230; -- Shadowmoon Fel Orc Attack Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18528; -- Xi'ri
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21826; -- Sanoru
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23496; -- Akama Event Trigger
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=21827; -- Zandras
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21700; -- Akama
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21102; -- Uvuros
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21701; -- Ashtongue Deathsworn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19744; -- Dreadwarden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21699; -- Maiev Shadowsong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21520; -- Illidari Jailor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19801; -- Illidari Agonizer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21897; -- Felspine the Greater
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21803; -- Ashtongue Handler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21802; -- Elekk Demolisher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21808; -- Illidari Overseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21455; -- Ashtongue Worker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21453; -- Ashtongue Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23020; -- Shadow Serpent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23454; -- Dragonmaw Raid Credit Marker (Aldor)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19631; -- Harram
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19629; -- Denath
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=19581; -- Maddix
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19526; -- Dunaman
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=22214; -- Harbinger Saronen
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19532; -- Dearny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23452; -- Commander Arcus
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=21402; -- Anchorite Ceyla
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19528; -- Nanomah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22080; -- Air Force Trip Wire - Rooftop (Aldor)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22079; -- Air Force Guard Post (Aldor - Gryphon)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22078; -- Air Force Alarm Bot (Aldor)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21860; -- Exarch Onaala
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=21822; -- Vindicator Aluumen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21746; -- Caretaker Aluuro
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19649; -- Dorni
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19648; -- Maranem
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19530; -- Darmend
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=21986; -- Altar of Sha'tar Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21454; -- Ashtongue Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21095; -- Credit Marker: Water
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21709; -- Eykenen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21704; -- Corrupt Earth Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21979; -- Val'zareq the Conqueror
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19795; -- Eclipsion Blood Knight
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=21953; -- Varen the Reclaimer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19627; -- Sulamin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19625; -- Alorya
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19520; -- Lelagar
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19517; -- Alorra
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=21954; -- Larissa Sunstrike
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=21766; -- Alieshor
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19521; -- Arrond
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19518; -- Feranin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23443; -- Dragonmaw Raid Credit Marker (Scryers)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23434; -- Commander Hobb
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=22211; -- Battlemage Vyara
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=21955; -- Arcanist Thelis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21744; -- Roldemar
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=19504; -- Scryer Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22071; -- Air Force Alarm Bot (Scryer)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22070; -- Air Force Trip Wire - Rooftop (Scryer)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19628; -- Furan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19626; -- Belanna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22066; -- Air Force Guard Post (Scryer - Dragonhawk)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22113; -- Mordenai
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21477; -- Rocknail Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21478; -- Rocknail Ripper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21648; -- Mature Netherwing Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22395; -- [PH]Altar of Shadows target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21872; -- The Voice of Gorefiend
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21797; -- Ancient Shadowmoon Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21711; -- Haalum
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22417; -- [PH]Altar of Shadows caster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21705; -- Corrupt Air Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21060; -- Enraged Air Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22083; -- Lord Illidan Stormrage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22073; -- Marcus Auralion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22093; -- Illidari Watcher
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=22012; -- Chancellor Bloodleaf
UPDATE `creature_template` SET `type_flags`=2147484160, `VerifiedBuild`=25996 WHERE `entry`=22011; -- Corok the Mighty
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22018; -- Eclipsion Cavalier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22017; -- Eclipsion Spellbinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22016; -- Eclipsion Soldier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19824; -- Son of Corok
UPDATE `creature_template` SET `type`=5, `VerifiedBuild`=25996 WHERE `entry`=22054; -- Behemothon, King of the Colossi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20563; -- Grand Commander Ruusk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21639; -- Illidari Slayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20431; -- Eclipse Point - Bloodcrystal Spell Orgin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19796; -- Eclipsion Archmage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19806; -- Eclipsion Bloodwarder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19792; -- Eclipsion Centurion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20502; -- Eclipsion Dragonhawk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21293; -- Borak, Son of Oronok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22115; -- Enraged Earth Shard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21384; -- Dark Conclave Harbinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22139; -- Invis Arakkoa Target
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=22137; -- Summoned Old God
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21385; -- Dark Conclave Scorncrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19825; -- Dark Conclave Talonite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22138; -- Dark Conclave Ritualist
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22146; -- Summoning Voidstorm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19371; -- Dalin Stouthammer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19369; -- Celie Steelwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19352; -- Dreg Cloudsweeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22042; -- Gryphonrider Kieran
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=20506; -- Swift Green Riding Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21775; -- Warcaller Beersnout
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=20505; -- Snowy Gryphon Mount
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18939; -- Brubeck Stormfoot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20511; -- Ilsa Blusterbrew
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20510; -- Brunn Flamebeard
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=20509; -- Swift Blue Riding Gryphon
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=20508; -- Swift Red Riding Gryphon
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=20507; -- Swift Purple Riding Gryphon
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=20504; -- Golden Gryphon
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=20503; -- Ebon Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19394; -- Barimoke Wildbeard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19368; -- Crinn Pathfinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21774; -- Zorus the Judicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19388; -- Wildhammer Stronghold Target Dummy Right
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=19379; -- Sky'ree
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19375; -- Eli Thunderstrike
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19351; -- Daggle Ironshaper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19395; -- Bron Goldhammer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24868; -- Niobe Whizzlespark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19387; -- Wildhammer Stronghold Target Dummy Left
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19373; -- Mari Stonehand
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19370; -- Ordinn Thunderfist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21777; -- Gnomus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19374; -- Salle Sunforge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19372; -- Oran Blusterbrew
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21937; -- Earthmender Sophurus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21330; -- Kurdran Wildhammer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21773; -- Thane Yoregar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19384; -- Wildhammer Scout
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19382; -- Wildhammer Gryphon Rider
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=21287; -- Warbringer Razuun
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21736; -- Wildhammer Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19759; -- Newly Crafted Infernal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19760; -- Cooling Infernal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19756; -- Deathforge Smith
UPDATE `creature_template` SET `modelid1`=47950, `VerifiedBuild`=25996 WHERE `entry`=21211; -- Invis Deathforge Target
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21210; -- Invis Deathforge Caster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21476; -- Mokthar Grimblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21475; -- Scout Zagran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20872; -- Deathforge Summoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19754; -- Deathforge Tinkerer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19757; -- Infernal Soul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20887; -- Deathforge Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21471; -- Stormer Ewan Wildwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21472; -- Gryphonrider Nordin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19353; -- Wildhammer Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20878; -- Deathforge Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21026; -- Earthmender Gorboto
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21024; -- Earthmender Torlok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21049; -- Spirit of the Past
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17008; -- Gul'dan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21094; -- Credit Marker: Fire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21092; -- Credit Marker: Earth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21710; -- Uylaru
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21703; -- Corrupt Fire Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21108; -- Spawn of Uvuros
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21050; -- Enraged Earth Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21061; -- Enraged Fire Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21183; -- Oronok Torn-heart
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21255; -- Umberhowl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21029; -- Captured Water Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21027; -- Earthmender Wilda
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20795; -- Keeper of the Cistern
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21041; -- Earthmender Wilda Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19788; -- Coilskar Muckwatcher
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21347; -- Shadowmoon Valley Tuber Node
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21196; -- Ravenous Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19767; -- Coilskar Sorceress
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19765; -- Coilskar Myrmidon
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21052; -- Camera Shaker - Altar of Damnation
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21420; -- Corrupt Water Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21416; -- Lakaan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21195; -- Domesticated Felboar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21462; -- Greater Felfire Diemetradon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20684; -- Lady Shav'rar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21295; -- Coilskar Commander
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21291; -- Grom'tor, Son of Oronok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19784; -- Coilskar Cobra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20076; -- Naga Distiller (Coilskar Point)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19769; -- Coilskar Screamer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21059; -- Enraged Water Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19789; -- Coilskar Waterkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19762; -- Coilskar Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19768; -- Coilskar Siren
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22025; -- Asghar
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62621; -- Gangreflamme
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19827; -- Dark Conclave Ravenguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21386; -- Dark Conclave Hawkeye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19826; -- Dark Conclave Shadowmancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21450; -- Skethyl Owl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17407; -- Felmist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19345; -- Kalara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19343; -- Trop Rendlimb
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19364; -- Kor'kron Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21359; -- Blood Guard Gulmok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22043; -- Sergeant Kargrul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19319; -- Innkeeper Darg Bloodclaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21771; -- Warcaller Sardon Truslice
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19341; -- Grutah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19339; -- Korthul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19333; -- Grokom Deatheye
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=19317; -- Drek'Gol
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=51910; -- Kor'kron Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21772; -- Chief Apothecary Hildagard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21770; -- Researcher Tiorus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19342; -- Krek Cragcrush
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21769; -- Overlord Or'barokh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19348; -- Targrom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21938; -- Earthmender Splinthoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25099; -- Jonathan Garrett
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21340; -- Detrafila
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21336; -- Gedrah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20500; -- Olrokk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20494; -- Dama Wildmane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20492; -- Swift Yellow Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20491; -- Swift Red Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20490; -- Swift Purple Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20489; -- Swift Green Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19362; -- Kor'kron Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20493; -- Green Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20488; -- Tawny Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20486; -- Blue Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19355; -- Shadowmoon Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21153; -- Kor'kron Wyvern Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22228; -- Flame Wave II
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21249; -- Wrathstalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21245; -- Bonechewer Marauder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21501; -- Makazradon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21499; -- Overseer Ripsaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21403; -- Invis Legion Hold Caster
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21512; -- Invis Legion Hold Glyph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21500; -- Morgroron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20683; -- Prophetess Cavrylin
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=21316; -- Deathforged Infernal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21404; -- Legion Hold Fel Reaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21302; -- Shadow Council Warlock
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61385; -- Vipère cendrée
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21807; -- Invis Legion Teleporter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19755; -- Mo'arg Weaponsmith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21314; -- Terrormaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19740; -- Wrathwalker
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=21305; -- Mutant Horror
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21749; -- Shadowmoon Scout
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21419; -- Infernal Attacker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21417; -- Invis Infernal Caster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=49568; -- Ash Viper
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=66557; -- Chevalier de sang Antari
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66545; -- Arcanus
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66544; -- Jadefeu
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66543; -- Morsure-du-Néant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21408; -- Felfire Diemetradon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21879; -- Vilewing Chimaera
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21348; -- Shadowmoon Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21309; -- Painmistress Gabrissa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21878; -- Felboar
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=21928; -- Lothros
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=10017; -- Tainted Cockroach
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21307; -- Eva
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21292; -- Ar'tor, Son of Oronok
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21310; -- Shadowmoon Valley Invisible Trigger (Tiny)
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62314; -- Cafard corrompu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21337; -- Illidari Shadowstalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20289; -- Illadari Point - Succubi Caster Position 02
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21656; -- Illidari Satyr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20288; -- Illadari Point - Succubi Caster Position 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20286; -- Illadari Point - Succubi Spell Orgin 001
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19800; -- Illidari Painlasher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19799; -- Illidari Dreadbringer
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21334; -- Veneratus Spawn Node
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19802; -- Illidari Shocktrooper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23363; -- Sahaak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21728; -- Skettis Surger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23029; -- Talonsworn Forest-Rager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21856; -- Skettis Kneel Target 04
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21855; -- Skettis Arakkoa Spell Origin 02
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21649; -- Skettis Windwalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23383; -- Skyguard Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21794; -- Skettis Arakkoa Spell Origin 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21793; -- Skettis Kneel Target 03
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21792; -- Skettis Kneel Target 02
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21654; -- Skettis Followers Spawner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21804; -- Skettis Kaliri
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21791; -- Skettis Kneel Target 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21644; -- Skettis Wing Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21650; -- Skettis Talonite
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22986; -- Skettis - Invis Raven Stone
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22991; -- Monstrous Kaliri Egg Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21911; -- Skettis Soulcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23051; -- Monstrous Kaliri
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23219; -- Blackwind Warp Chaser
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22424; -- Skywing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18455; -- Shalassi Oracle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18454; -- Shalassi Talonguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20986; -- Dealer Tariq
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19718; -- Provisioner Tsaalt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22831; -- Outland Children's Week Auchindoun Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22371; -- Terokkar Forest Ground Shaker Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21967; -- Auchenai Death-Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22441; -- Teribus the Cursed
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22045; -- Vengeful Husk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21941; -- Accursed Apparition
UPDATE `creature_template` SET `family`=43, `type_flags`=65537, `VerifiedBuild`=25996 WHERE `entry`=22105; -- Decrepit Clefthoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24893; -- Auchindoun Daily Quest Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21242; -- Auchenai Death-Speaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21870; -- Unliving Initiate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18460; -- Lost Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21284; -- Auchenai Initiate
UPDATE `creature_template` SET `modelid1`=47950, `VerifiedBuild`=25996 WHERE `entry`=21443; -- Bone Wastes - Orb Waypoint 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16805; -- Broken Skeleton
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21869; -- Unliving Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21852; -- Auchenai Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21846; -- Slain Auchenai Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21285; -- Auchenai Doomsayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21859; -- Slain Sha'tar Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22364; -- Scout Navrin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22458; -- Chief Archaeologist Letoll
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22446; -- Commander Ra'vaj
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22481; -- Dwarfowitz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22477; -- Anchorite Ensham
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22476; -- Aundro
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22464; -- Explorers' League Researcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22456; -- Oakun
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=22453; -- Injured Sha'tar Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19659; -- Great Elite Elekk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22387; -- Lithic Oracle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22340; -- Terokkar Arakkoa Fly Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22388; -- Lithic Talonguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18273; -- Kilrath
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=18843; -- Bleeding Hollow Clan Ruins Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18262; -- Unkor the Ruthless
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18260; -- Boulderfist Invader
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18588; -- Floon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18707; -- Torgos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21200; -- Screeching Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21198; -- Deathtalon Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21324; -- Spirit Raven
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22378; -- Cabal Interrogator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22377; -- Akuno
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21661; -- Cabal Skirmisher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22381; -- Hathyss the Wicked
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21662; -- Cabal Tomb-Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21660; -- Cabal Abjurist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22288; -- Terokkar Quest Target
UPDATE `creature_template` SET `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18541; -- Urdak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22314; -- Captive Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18452; -- Skithian Dreadhawk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18453; -- Skithian Windripper
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18720; -- Shadowmaster Grieve
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18719; -- Shadowy Advisor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18718; -- Shadowy Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18717; -- Shadowy Laborer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18716; -- Shadowy Initiate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16519; -- Shadowy Executioner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17088; -- Shadowy Summoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18686; -- Doomsayer Jurim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18714; -- Scout Neftis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22365; -- Ethan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20895; -- Miiji
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20894; -- Miihi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20890; -- Siflaed Coldhammer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20893; -- Morula
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20892; -- Ruogo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20891; -- Skraa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21317; -- Aimi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22272; -- Kirrik the Awakened
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20874; -- Skettis Refugee
UPDATE `creature_template` SET `family`=43, `VerifiedBuild`=25996 WHERE `entry`=21313; -- Dead Clefthoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18675; -- Soolaveen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22370; -- Mekeda
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22278; -- High Priest Orglum
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20877; -- Shattrath Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21858; -- Sha'tar Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20876; -- Human Refugee
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=22407; -- Caravan Defender
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61440; -- Scorpide à queue rayée
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=49833; -- Stripe-Tailed Scorpid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21849; -- Bone Crawler
UPDATE `creature_template` SET `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=21515; -- Trachela
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22100; -- Scorpid Bonecrawler
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61366; -- Rat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18470; -- Bonelasher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22307; -- Rotting Forest-Rager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22095; -- Infested Root-Walker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21636; -- Vengeful Draenei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21368; -- Ethereal Plunderer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18465; -- Warp Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18467; -- Dreadfang Widow
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18989; -- Stonebreaker Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19002; -- Gardok Ripjaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21194; -- Ru'zah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18960; -- Rungor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18962; -- Bar Talet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18957; -- Innkeeper Grilka
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18712; -- Advisor Faila
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18705; -- Mawg Grimshot
UPDATE `creature_template` SET `modelid1`=62616, `VerifiedBuild`=25996 WHERE `entry`=18676; -- Keb'ezil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18383; -- Kurgatok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21188; -- Thadok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24886; -- Exorcist Vaisha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19772; -- Spirit Sage Gartok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18384; -- Malukaz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18984; -- Trag
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18807; -- Kerna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18386; -- Rokag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19607; -- Grek's Riding Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19606; -- Grek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18959; -- Dod'ss
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18447; -- Tooki
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21193; -- Gralga
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21192; -- Kugnar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19048; -- Stonebreaker Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18385; -- Rakoria
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18249; -- Mokasa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18973; -- Stonebreaker Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18595; -- Warped Peon
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=17467; -- Skunk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18565; -- Theloria Shadecloak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21006; -- Lieutenant Meridian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21899; -- Mana Bomb Lightning Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21898; -- Mana Bomb Lightning Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21039; -- Mana Bomb Kill Credit Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20809; -- Mana Bomb Channel Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20767; -- Mana Bomb Explosion Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18760; -- Isla Starmane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18554; -- Sharth Voldoun
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61255; -- Mouffette
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16769; -- Firewing Warlock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=1410; -- Firewing Bloodwarder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5355; -- Firewing Defender
UPDATE `creature_template` SET `family`=130, `type_flags`=2147483649, `VerifiedBuild`=25996 WHERE `entry`=18648; -- Stonegazer
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=18463; -- Dampscale Devourer
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=21816; -- Ironspine Chomper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18477; -- Timber Worg Alpha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18464; -- Warp Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18469; -- Royal Teromoth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16932; -- Razorfang Hatchling
UPDATE `creature_template` SET `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18540; -- Ayit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18457; -- Tuurem Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17142; -- Wrekt Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18456; -- Tuurem Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=131072; -- Traqueur du Vide
UPDATE `creature_template` SET `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18539; -- Ashkaz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18451; -- Shienor Wing Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18450; -- Shienor Sorcerer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18449; -- Shienor Talonite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18466; -- Dreadfang Lurker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18468; -- Teromoth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18480; -- Broken Corpse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18424; -- Warden Treelos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18490; -- Fallen Druid
UPDATE `creature_template` SET `family`=37, `type_flags`=2147483649, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18438; -- Naphthal'ar
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62583; -- Jeune traqueur dimensionnel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18437; -- Vicious Teromoth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24437; -- Consortium Assistant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23852; -- [DND] L70ETC Mai'Kyl Controller
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=18584; -- Sal'salabim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24369; -- Wind Trader Zhareem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24412; -- Daily Dungeon Image Bunny
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=24429; -- Rift Lord Image
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24370; -- Nether-Stalker Mah'duun
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19289; -- Vagabond
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19077; -- Dwarf Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19283; -- Vagrant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25992; -- Big Bruiser
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19033; -- Nicole Bartlett
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22819; -- Orphan Matron Mercy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19170; -- Peasant Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20125; -- Zula Slagfury
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20124; -- Kradu Grimblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23699; -- Kevin Browning
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19150; -- Orc Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25138; -- Captain Dranarus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25136; -- Shattered Sun Trainee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25135; -- Shattered Sun Trainee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23449; -- Yuula
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18940; -- Nutral
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=35002; -- Asara Dawnblaze
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19162; -- Lost One Refugee
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=15214; -- Invisible Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25137; -- Shattered Sun Trainee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25134; -- Shattered Sun Trainee
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=35001; -- Saeld Brightflare
UPDATE `creature_template` SET `modelid1`=56765, `type_flags`=4, `VerifiedBuild`=25996 WHERE `entry`=18166; -- Archmage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19331; -- Quartermaster Enuril
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23273; -- Arcanist Raestan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20808; -- Scribe Veredis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23483; -- Arcanist Xorith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=52277; -- Droha
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50127; -- Windstalker Ifram
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=52268; -- Riha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=52278; -- Linsa
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50136; -- Baelir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19715; -- Ezekiel
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50137; -- Muha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19246; -- Berudan Keysworn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19338; -- L'lura Goldspun
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50130; -- Luknar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25885; -- Whirligig Wafflefry
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50128; -- Fel-Caller Guloto
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19680; -- Aldor Spawn Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19475; -- Harbinger Haronem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20791; -- Iorioa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=50140; -- Auctioneer Lyrsara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=50139; -- Auctioneer Kalaren
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25167; -- General Tiras'alan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18481; -- A'dal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22497; -- V'eru
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25143; -- Shattered Sun Veteran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5202; -- Archery Target
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50018; -- Tarlhir
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50017; -- Summoner Durael
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50016; -- Pathstalker Arpalir
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50013; -- Matron Ismara
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50012; -- Blood Knight Argaron
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50010; -- Alaressa
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50007; -- Derithela
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24938; -- Shattered Sun Marksman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19120; -- Broken Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18893; -- Spymistress Mehlisah Highcrown
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25142; -- Shattered Sun Marksman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25153; -- Shattered Sun Magi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21432; -- Almaador
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18525; -- G'eras
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25155; -- Shattered Sun Cleric
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=27667; -- Anwehu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24932; -- Exarch Nasuun
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20331; -- G'eras Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24928; -- Sunwell Daily Bunny x 1.00
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24936; -- Sunwell Daily Bunny x 0.01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=27666; -- Ontuvo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15892; -- Lunar Festival Emissary
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=33684; -- Weaver Aoa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25195; -- Marksman Bova
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=33678; -- Jijia
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=33674; -- Alchemist Kanhu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15897; -- Large Spotlight
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15893; -- Lunar Firework Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15894; -- Lunar Cluster Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15891; -- Lunar Festival Herald
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19702; -- Aldor Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15895; -- Lunar Festival Harbinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15898; -- Lunar Festival Vendor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19726; -- "Creepjack"
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19725; -- "Epic" Malone
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19720; -- "Dirty" Larry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19318; -- Gromden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19034; -- Mendorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23484; -- Haldor the Compulsive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23270; -- Vindicator Aeus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22429; -- Vekax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20807; -- Scribe Saalyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19321; -- Quartermaster Endarin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19074; -- Skreah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19052; -- Lorokeem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19049; -- Karokka
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=50143; -- Auctioneer Itoran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19051; -- Araac
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=50145; -- Auctioneer Braku
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=4075; -- Rat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22373; -- Defender Grashna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22292; -- Rilak the Redeemed
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22326; -- Redeemed Avian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20123; -- Farmer Griffith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19665; -- Ewe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19164; -- Refugee Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19047; -- Lissaf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18622; -- Iz'zard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18596; -- Arcanist Adyria
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23465; -- Zoya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19155; -- Sporeling Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19075; -- Skettis Outcast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23466; -- Voranaku
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23433; -- Barthamus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19045; -- Oloraak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24436; -- Gargoth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19144; -- Mag'har Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24416; -- Grisy Spicecrackle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24393; -- The Rokk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19163; -- Refugee Kid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18653; -- Seth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18652; -- Zahlia
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18597; -- Sha'nir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19684; -- Haggard War Veteran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19184; -- Mildred Fletcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18600; -- Injured Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19687; -- Shattrath City Peacekeeper
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=21854; -- Ironspine Petrifier
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=18750; -- Shimmerscale Eel
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=18461; -- Dampscale Basilisk
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62555; -- Jeune écorcheur
UPDATE `creature_template` SET `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=24922; -- Razorthorn Ravager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24920; -- Razorthorn Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20678; -- Akoru the Firecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19361; -- Naladu
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=16937; -- Dreghood Geomancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20677; -- Morod the Windstirrer
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=19354; -- Arzeth the Merciless
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20679; -- Aylaan the Waterwaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17058; -- Illidari Taskmaster
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=16938; -- Dreghood Brute
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19349; -- Thornfang Ravager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19350; -- Thornfang Venomspitter
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20781; -- Seed of Revitalization Target Trigger
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20617; -- Red Crystal Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19188; -- Raging Colossus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18906; -- Caregiver Ophera Windfury
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17403; -- Anchorite Alendar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17006; -- Elsaana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16796; -- Amaan the Wise
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18990; -- Burko
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19004; -- Vodesiin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19001; -- Talaara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16836; -- Escaped Dreghood
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16834; -- Anchorite Obadei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16833; -- Makuru
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16799; -- Ikan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18758; -- Telhamat Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16797; -- Scout Vanura
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16798; -- Provisioner Anir
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18785; -- Kuma
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17402; -- Yaluu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16852; -- Sedai's Corpse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16927; -- Stonescythe Whelp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16845; -- Gorkan Bloodfist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17123; -- Earthcaller Ryga
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16848; -- Provisioner Braknar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16912; -- Mag'har Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19461; -- Tamed Ravager
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=16846; -- Mag'har Grunt
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=16847; -- Debilitated Mag'har Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16973; -- Bonestripper Vulture
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17062; -- Fel Orc Corpse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16911; -- Mag'har Watcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19191; -- Arazzius the Cruel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19192; -- Mistress of Doom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20158; -- Slime-Covered Corpse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16951; -- Terrorfiend
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=16903; -- Blistering Oozeling
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=16901; -- Blistering Rot
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=19028; -- The Overlook Capture Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17795; -- Horde Tower Buffer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17794; -- Alliance Tower Buffer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19264; -- Force-Commander Gorax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18677; -- Mekthorg the Wild
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16857; -- Marauding Crust Burster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19415; -- Shattered Hand Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19413; -- Shattered Hand Mage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19295; -- Shattered Hand Grenadier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19414; -- Shattered Hand Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16880; -- Hulking Helboar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19297; -- [PH]Dynamite Target
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22444; -- Anchorite Relic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22454; -- Fel Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19263; -- Warboss Nekrogg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16878; -- Shattered Hand Berserker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16974; -- Rogue Voidwalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16975; -- Uncontrolled Voidwalker
UPDATE `creature_template` SET `type_flags2`=8192, `VerifiedBuild`=25996 WHERE `entry`=17060; -- Hellfire Combat Dummy Small
UPDATE `creature_template` SET `type_flags2`=8192, `VerifiedBuild`=25996 WHERE `entry`=17059; -- Hellfire Combat Dummy
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=16977; -- Arch Mage Xintor
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=16978; -- Lieutenant Commander Thalvos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16976; -- Ghostly Denizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18678; -- Fulgorge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16843; -- Honor Hold Cavalryman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16838; -- Honor Hold Miner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22431; -- Anchorite Barada
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16884; -- War Horse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=35101; -- Grunda Bronzewing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=35100; -- Hargen Bronzewing
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18974; -- Z'kral
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16899; -- Honor Hold Target Dummy Left
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16897; -- Honor Hold Target Dummy Middle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16898; -- Honor Hold Target Dummy Right
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16832; -- Prospector Murantus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22432; -- Colonel Jules
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=16822; -- Flightmaster Krill Bitterhue
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16835; -- Explorers' League Archaeologist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16824; -- Master Sergeant Lorin Thalmerok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18987; -- Gaston
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16830; -- Field Commander Romus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17657; -- Logistics Officer Ulrike
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18777; -- Jelena Nightsky
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20513; -- Honor Hold Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19363; -- Sergeant Dalton
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18266; -- Warrant Officer Tracy Proudwell
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20206; -- Fei Fei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18779; -- Hurnak Grimmord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22467; -- Fei Fei Stash Bunny
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19393; -- Fear Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19308; -- Marshal Isildor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16823; -- Humphry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16886; -- Arator the Redeemer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16826; -- Sid Limbardi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16828; -- Honor Guard Greyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16825; -- Father Malgor Devidicus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22430; -- Assistant Klatu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22227; -- Markus Scylan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18771; -- Brumman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18774; -- Tatiana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18772; -- Hama
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18776; -- Rorelien
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18773; -- Johan Barnes
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=30734; -- Jezebel Bican
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=30721; -- Michael Schwan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47574; -- Gerdra Fardelve
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18802; -- Alchemist Gribble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16829; -- Magus Zabraxis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19392; -- Watch Commander Leonus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16856; -- Caretaker Dilandrus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18775; -- Lebowski
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16821; -- Magus Filinthus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16839; -- Warp-Scryer Kryv
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16896; -- Honor Hold Archer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16819; -- Force Commander Danath Trollbane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16865; -- Injured Stormwind Infantry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16887; -- Eye of Honor Hold
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16972; -- Bonestripper Buzzard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16905; -- Unyielding Sorcerer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19937; -- Commander Hogarth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16906; -- Unyielding Knight
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16904; -- Unyielding Footman
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=51799; -- Thrallmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19561; -- Hagash the Blind
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16858; -- Grelag
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21391; -- Scarab Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21279; -- Apothecary Albreck
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19560; -- Lukra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22107; -- Captain Darkhowl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19836; -- Mixie Farshot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19683; -- Ogath the Mad
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19682; -- Emissary Mordiba
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19559; -- Mondul
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=19558; -- Amilya Airheart
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19332; -- Stone Guard Ambelan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22231; -- Zezzak
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22177; -- Eye of Grillok Quest Credit Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19736; -- Althen the Historian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19562; -- Peon Bolgar
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21182; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower South
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=16964; -- Warlord Morkh
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20813; -- Zeth'Gor Quest Credit Marker, Barracks
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20816; -- Zeth'Gor Quest Credit Marker, West Hovel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19423; -- Bleeding Hollow Worg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19458; -- Ripp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19442; -- Worg Master Kruush
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20814; -- Zeth'Gor Quest Credit Marker, Stable
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19459; -- Feng
UPDATE `creature_template` SET `type`=3, `VerifiedBuild`=25996 WHERE `entry`=19440; -- Eye of Grillok
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22403; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower Foothill
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20815; -- Zeth'Gor Quest Credit Marker, East Hovel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19422; -- Bleeding Hollow Necrolyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16873; -- Bleeding Hollow Dark Shaman
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22401; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower North
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22402; -- Zeth'Gor Quest Credit Marker, They Must Burn, Tower Forge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16907; -- Bleeding Hollow Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19424; -- Bleeding Hollow Tormentor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16871; -- Bleeding Hollow Grunt
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21173; -- Zeth'Gor Quest Credit Marker, They Must Burn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21133; -- Corporal Ironridge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19316; -- Field Marshal Rohamus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19314; -- Supply Officer Shandria
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=51800; -- Honor Hold Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19409; -- Wing Commander Dabir'ee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19310; -- Forward Commander Kingston
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16842; -- Honor Hold Defender
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=19434; -- Dreadcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19136; -- Flamewaker Imp
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=18978; -- Heckling Fel Sprite
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19326; -- Legion Antenna: Oblivion
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19328; -- Legion Antenna: Gehenna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18679; -- Vorakem Doomspeaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19335; -- Subjugator Yalqiz
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19329; -- Legion Antenna: Mageddon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19681; -- Void Spawner L
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19527; -- Vacillating Voidcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17014; -- Collapsing Voidwalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21075; -- Infernal Target (Hyjal)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19624; -- Wounded Stormwind Infantry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19455; -- Nurse Judith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19447; -- Brother Daniels
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19452; -- Quartermaster Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19451; -- Quartermaster Gorman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19446; -- Operations Officer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19007; -- Gnomeregan Conjuror
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18931; -- Amish Wildhammer
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19444; -- Peasant Worker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18986; -- Ironforge Paladin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18949; -- Stormwind Mage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22833; -- Outland Children's Week Dark Portal Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16864; -- Stormwind Infantry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19225; -- Strength of the Storm Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16831; -- Nethergarde Infantry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18965; -- Darnassian Archer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19229; -- Commander Duron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18969; -- Melgromm Highmountain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18972; -- Orgrimmar Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18950; -- Orgrimmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18970; -- Darkspear Axe Thrower
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19005; -- Wrath Master
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18944; -- Fel Soldier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19179; -- Formation Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21252; -- World Trigger (Not Immune PC)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19253; -- Lieutenant General Orion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18971; -- Undercity Mage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19871; -- World Trigger (Not Immune NPC)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19006; -- Silvermoon Magister
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19436; -- Supply Master Broog
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19435; -- Dark Cleric Malod
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19426; -- Peon Overseer
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18930; -- Vlagga Freyfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19425; -- Orgrimmar Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18948; -- Stormwind Soldier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18966; -- Justinius the Harbinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18945; -- Pit Commander
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18946; -- Infernal Siegebreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19432; -- Injured Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19215; -- Infernal Relay (Hellfire)
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61325; -- Aspic
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20232; -- Wing Commander Gryphongar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20251; -- Honor Hold Scout Archery Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20231; -- Supply Officer Pestle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20237; -- Honor Hold Gryphon Rider
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20235; -- Gryphoneer Windbellow
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=20234; -- Runetog Wildhammer
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19279; -- Legion Antenna: Fear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19652; -- Disrupt the Communications Quest Credit Marker North
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19282; -- Subjugator Shi'aziv
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19278; -- Legion Antenna: Hate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19717; -- Disrupt the Communications Quest Credit Marker South
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19277; -- Legion Antenna: Rage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18981; -- Doomwhisperer
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19276; -- Legion Antenna: Spite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16950; -- Netherhound
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19190; -- Fel Handler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18975; -- Wrathguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21365; -- Floating Skull
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21257; -- Apothecary Zelana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19401; -- Wing Commander Brack
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=19275; -- Armored Wyvern Destroyer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19315; -- Supply Officer Isabel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19273; -- Forward Commander To'arch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16599; -- Thrallmar Wolf Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16576; -- Overlord Hun Maimfist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18849; -- Invis Alliance Siege Engine - East
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19410; -- Shattered Hand Neophyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16870; -- Shattered Hand Captain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16867; -- Shattered Hand Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19443; -- Tagar Spinebreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16925; -- Bonechewer Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21237; -- Invis Horde Siege Engine - East 02
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19411; -- Shattered Hand Warlock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18818; -- Invis Horde Siege Engine - East
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16876; -- Bonechewer Mutant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19701; -- Bonechewer Evoker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18952; -- Bonechewer Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19258; -- Bloodmage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19257; -- Arcanist Torseldori
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19256; -- Sergeant Shatterskull
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=16587; -- Barley
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=49789; -- Allison
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18749; -- Dalinna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22225; -- Reagan Mancuso
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16602; -- Floyd Pinkus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18751; -- Kalaen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18755; -- Moorutu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18754; -- Barim Spilthoof
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=51903; -- Thrallmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18267; -- Battlecryer Blackeye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=35099; -- Bana Wildmane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=35093; -- Wind Rider Jahubo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18365; -- Green Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18364; -- Blue Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18363; -- Tawny Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16600; -- Thrallmar Riding Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16586; -- Huntsman Torf Angerhoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16585; -- Cookie One-Eye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16590; -- Injured Thrallmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16589; -- Guard Captain Cragtar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16582; -- Thrallmar Marksman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16577; -- Martik Tor'seldori
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16579; -- Falcon Watch Sentinel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16578; -- Blood Elf Pilgrim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16584; -- Watch Commander Krunk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21283; -- Megzeg Nukklebust
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19255; -- General Krakork
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18752; -- Zebig
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16583; -- Rohok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18747; -- Krugosh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16591; -- Thrallmar Peon
UPDATE `creature_template` SET `type`=5, `VerifiedBuild`=25996 WHERE `entry`=17585; -- Quartermaster Urgronn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16574; -- Far Seer Regulkut
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21256; -- Vurtok Axebreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21175; -- Magister Bloodhawk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16575; -- Shadow Hunter Ty'jin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3230; -- Nazgrel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18748; -- Ruak Stronghorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17004; -- Jir'see
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17002; -- Angela "The Claw" Kestrel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16588; -- Apothecary Antonivich
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47573; -- Sirabel
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=30735; -- Kul Inkspiller
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=30722; -- Neferatti
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18753; -- Felannia
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16580; -- Thrallmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16598; -- Eye of Thrallmar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16915; -- Foreman Razelcraz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16844; -- Crust Burster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21847; -- Fel Guard Hound
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20195; -- Dagz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16863; -- Deranged Helboar
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=19298; -- Warbringer Arix'Amal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19408; -- Maiden of Pain
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18976; -- Urga'zz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18828; -- Camera Shaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18827; -- Gan'arg Sapper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15242; -- Bat Rider Guard
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=18729; -- Infernal Rain (Hellfire)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19261; -- Infernal Warbringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22461; -- Fel Cannon MKI
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20798; -- Razorsaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16960; -- Sister of Grief
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16946; -- Mo'arg Forgefiend
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16954; -- Forge Camp Legionnaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16947; -- Gan'arg Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16879; -- Starving Helboar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121541; -- Ban Lu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20793; -- Field Marshal Brock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20238; -- Honor Hold Scout
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20236; -- Gryphoneer Leafbeard
UPDATE `creature_template` SET `modelid1`=76348, `family`=160, `VerifiedBuild`=25996 WHERE `entry`=19324; -- Armored Gryphon Destroyer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19397; -- Mo'arg Overseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19400; -- Fel Reaver Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19399; -- Fel Cannon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19398; -- Gan'arg Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24937; -- Magistrix Seyla
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=24959; -- Generic Quest Trigger - LAB
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24955; -- Emaciated Felblood
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24933; -- Suspended Terrorguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24918; -- Felblood Initiate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24921; -- Cosmetic Trigger - LAB
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24919; -- Wrath Herald
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22323; -- Incandescent Fel Spark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18733; -- Fel Reaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20551; -- Agent Araxes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20858; -- Arena Event Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20907; -- Professor Dabiri
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20903; -- Protectorate Nether Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20450; -- Flesh Handler Viridius
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=20451; -- Subservient Flesh Beast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20092; -- Dealer Hazzin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20071; -- Wind Trader Marid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20449; -- Researcher Navuud
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20448; -- Commander Ameer
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=20447; -- Protectorate Vanguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20452; -- Ethereum Assassin
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20727; -- Captain Zovax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20676; -- Ethereum Sparring Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20456; -- Ethereum Researcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20755; -- Ethereum Energy Cell
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20453; -- Ethereum Shocktrooper
UPDATE `creature_template` SET `type`=3, `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20554; -- Arconus the Insatiable
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=20899; -- Void Conduit
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=4, `VerifiedBuild`=25996 WHERE `entry`=19565; -- Enormous Void Storm
UPDATE `creature_template` SET `KillCredit2`=0, `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=19554; -- Dimensius the All-Devouring
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18877; -- Nether Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19336; -- Void Spawner XL
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=20501; -- Seeping Sludge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18869; -- Unstable Voidwraith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18870; -- Voidshrieker
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=20933; -- Camera Shakers Manaforge Ultris
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=20340; -- Fleshfiend
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20561; -- Withered Corpse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22822; -- Ethereum Nullifier
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20607; -- Craghide Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22821; -- Ethereum Avenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19568; -- Unending Voidwraith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20459; -- Ethereum Overlord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20458; -- Ethereum Archon
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=20770; -- Warden Icoshock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20520; -- Ethereum Prisoner
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=20778; -- Void Waste
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20764; -- Ethereum Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20825; -- Ethereum Prisoner (Tyralius)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20474; -- Ethereum Nexus-Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20454; -- Nexus-King Salhadaar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20769; -- Salaadin's Energy Ball
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20922; -- Fallen Vindicator
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=20780; -- Kaylaan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20341; -- Nether-Stalker Oazul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20112; -- Wind Trader Tuluman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18860; -- Daughter of Destiny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20393; -- Foreman Sundown
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20326; -- Mo'arg Warp-Master
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20804; -- Netherstorm Moarg Work Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20285; -- Gan'arg Warp-Tinker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21089; -- Sunfury Blood Knight
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21267; -- Mana Beast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20248; -- Sunfury Nethermancer
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20803; -- Overmaster Grindgarr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23491; -- Socrethar Event Trigger
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=20132; -- Socrethar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20929; -- Wrath Lord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20930; -- Hatecryer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20516; -- Warp Monstrosity
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20913; -- Tashar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20931; -- Tyrantus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20634; -- Scythetooth Raptor
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20133; -- Image of Socrethar
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20148; -- Dead Doomguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20138; -- Culuthas
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=20473; -- Surveying Marker One
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21157; -- Culuthas Scan Target Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20394; -- Eye of Culuthas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20141; -- Hound of Culuthas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20202; -- Cragskaar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18886; -- Farahlon Breaker
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22351; -- Eastern Gehenna Teleporter Credit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20928; -- Ironspine Forgelord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18859; -- Wrath Priestess
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22348; -- Western Gehenna Teleporter Credit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21135; -- Fel Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16943; -- Cyber-Rage Forgelord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18858; -- Wrathbringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18882; -- Sundered Thunderer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20800; -- Forgemaster Morug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22293; -- Inactive Fel Reaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22358; -- Nether Gas Visual Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16949; -- Gan'arg Mekgineer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21923; -- Terrorguard Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22899; -- Protectorate Advisor Rahim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20084; -- Image of Nexus-Prince Haramad
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=19583; -- Grennik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20471; -- Nether-Stalker Nauthis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20470; -- Zephyrion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19540; -- Asarnan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19539; -- Jazdalaad
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19538; -- Dealer Senzik
UPDATE `creature_template` SET `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20775; -- Markaru
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19537; -- Dealer Malij
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19533; -- Dealer Aljaan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20068; -- Zuben Eschamali
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20067; -- Zuben Elgenubi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19535; -- Dealer Zijaad
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20242; -- Karaaz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19531; -- Eyonix
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20811; -- Ghabar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20980; -- Dealer Rashaad
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19534; -- Dealer Digriz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20989; -- Dealer Sadaqat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2334; -- Event Generator 001
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20871; -- Aurine Moonblaze
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22427; -- Zarevhi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20981; -- Dealer Najeeb
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20205; -- Audi the Needle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20204; -- Action Jaxon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19536; -- Dealer Jadyan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22065; -- Air Force Guard Post (Ethereal - Stormspire)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22069; -- Air Force Alarm Bot (Stormspire)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22068; -- Air Force Trip Wire - Rooftop (Ethereal - Stormspire)
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=19529; -- Stormspire Nexus-Guard
UPDATE `creature_template` SET `KillCredit2`=0, `family`=151, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20610; -- Talbuk Doe
UPDATE `creature_template` SET `family`=151, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20777; -- Talbuk Sire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20774; -- Farahlon Lasher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20921; -- Shauly Pore
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20810; -- Mehrdad
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20194; -- Dealer Dunar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20066; -- Gahruj
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19728; -- Mama Wheeler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20773; -- Barbscale Crocolisk
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20611; -- Shimmerwing Moth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20671; -- Ripfang Lynx
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19738; -- Doomclaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20281; -- Drijya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20296; -- Teleporter Explosion Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20404; -- Warp-Gate Engineer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16948; -- Gan'arg Engineer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16944; -- Mo'arg Doomsmith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19940; -- Apex
UPDATE `creature_template` SET `family`=35, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=18883; -- Mana Snapper
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=19705; -- Master Daellis Dawnstrike
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20139; -- Sunfury Conjurer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19657; -- Summoner Kanthin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19653; -- Glacius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20140; -- Sunfury Centurion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20435; -- Overseer Athanel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20207; -- Sunfury Bowman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20673; -- Swiftwing Shredder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20796; -- Netherstorm Target
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=20515; -- Harpax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22491; -- Kerpow Blastwrench
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=22494; -- Cosmowrench Bruiser
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22479; -- Sab'aoth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18884; -- Warp Chaser
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=20483; -- Naberius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20415; -- Bessy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20495; -- Skeletal Stallion
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20410; -- Rhonsus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19544; -- Conjurer Luminrath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20409; -- Kirin'Var Apprentice
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19866; -- Invis East KV Rune
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19543; -- Battle-Mage Dathric
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19545; -- Cohlien Frostweaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19546; -- Abjurist Belmara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19481; -- Archmage Vargoth
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=19494; -- Ar'kelos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19489; -- Lieutenant-Sorcerer Morran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19488; -- Custodian Dieworth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20463; -- Apprentice Andrethan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20934; -- Severed Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20464; -- Thadell
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=6368; -- Cat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20411; -- Spectral Bovine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21065; -- Tormented Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20512; -- Tormented Soul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19867; -- Invis NE KV Rune
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19926; -- Spellreaver Marathelle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20221; -- Sunfury Flamekeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19939; -- Netherstorm Nether Beast Target
UPDATE `creature_template` SET `modelid1`=62616, `VerifiedBuild`=25996 WHERE `entry`=19724; -- Invis BE Tent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19723; -- Invis BE Ballista
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19707; -- Sunfury Archer
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=19727; -- Netherstorm Shoot Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19731; -- Nether Beast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19549; -- Invis Weapon Rack
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19881; -- Severed Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=6271; -- Mouse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19548; -- Invis Dresser
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19550; -- Invis Footlocker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18866; -- Mageslayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19547; -- Invis Bookshelf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18867; -- Mana Seeker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19868; -- Invis West KV Rune
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19593; -- Spellbinder Maryana
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19840; -- Caledis Brightdawn
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19839; -- Lariel Sunrunner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19831; -- Commander Dawnforge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19830; -- Arcanist Ardonis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20136; -- Sunfury Researcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20135; -- Sunfury Arch Mage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18850; -- Sunfury Guardsman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20134; -- Sunfury Arcanist
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=19641; -- Warp-Raider Nesaad
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19690; -- N. D. Meancamp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20243; -- Scrapped Fel Reaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20498; -- Sundered Shard
UPDATE `creature_template` SET `type_flags`=2147484160, `VerifiedBuild`=25996 WHERE `entry`=20772; -- Netherock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20338; -- Western Pipe Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18856; -- Arcane Annihilator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20337; -- Southern Pipe Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20416; -- Overseer Theredis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19421; -- Netherstorm Crystal Target
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62627; -- Petite raie du Néant
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=19686; -- Nether Anomaly
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19643; -- Sunfury Astromancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18855; -- Sunfury Magister
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19437; -- Netherstorm Kneel Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19453; -- Sunfury Captain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18853; -- Sunfury Bloodwarder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18857; -- Sunfury Warp-Master
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=20336; -- Eastern Pipe Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19779; -- Sunfury Geologist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19483; -- Netherstorm Use Standing Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19439; -- Netherstorm Work Mining Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18852; -- Sunfury Warp-Engineer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19484; -- Netherstorm Repair Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19642; -- Zaxxis Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18875; -- Zaxxis Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18865; -- Warp Aberration
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17408; -- Arcane Vortex
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62625; -- Cafard du Néant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20215; -- Pentatharon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19852; -- Artifact Seeker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19853; -- Felblade Doomguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18885; -- Farahlon Giant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19849; -- Scrap Reaver X6000
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19832; -- Doctor Vomisa, Ph.T.
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19634; -- Lead Sapper Blastfizzle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21262; -- Goblin Equipment Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21261; -- Big Wagon Full of Explosives Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21259; -- Crash Bigbomb
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=29145; -- Pulik Swiftsnip
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19776; -- Experimental Pilot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21734; -- Zixxy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21733; -- Karzo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21732; -- Nandirx
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=28343; -- Meeda
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19574; -- Kizzie
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18938; -- Krexcil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97511; -- Aquamouche chatoyante
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20389; -- Lee Sparks
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19709; -- Chief Engineer Trep
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19655; -- Area 52 Ethereal Technology Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19621; -- Bill
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19576; -- Xyrol
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19575; -- Qiff
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=20162; -- Veronia
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19654; -- Area 52 Analyzer Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21751; -- Chubis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107619; -- Blaze Magmaburn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107610; -- Kitzie Crankshot
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=54649; -- Big Zokk Torquewrench
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107599; -- Izzee the 'Clutch'
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=54650; -- Kezzik the Striker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23396; -- Krixel Pinchwhistle
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=40209; -- Grex Brainboiler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19645; -- Papa Wheeler
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=54648; -- Leeni "Smiley" Smalls
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=58152; -- Tini Smalls
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21493; -- Kablamm Farflinger
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20484; -- Area 52 Big Bruiser
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=72823; -- Bill Porter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19572; -- Gant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19570; -- Rocket-Chief Fuselage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19845; -- Area 52 Fireworks Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19737; -- Engineering Crewmember
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19217; -- Ravandwyr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19612; -- Irradiated Manager
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22280; -- Soren
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22279; -- Nadja
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19880; -- Nether-Stalker Khay'ji
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20102; -- Goblin Commoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=28344; -- Blazzle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19780; -- Off-Duty Engineer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19617; -- Boots
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19623; -- Doc
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=19482; -- Sagan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24974; -- Liza Cutlerflix
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19466; -- Exarch Orelis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21974; -- Air Force Alarm Bot (Area 52)
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19467; -- Anchorite Karja
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19469; -- Magistrix Larynna
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=19468; -- Spymaster Thalodien
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19571; -- Innkeeper Remi Dodoso
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19651; -- Seasoned Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22063; -- Air Force Trip Wire - Rooftop (Goblin - Area 52)
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=24977; -- Warpy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19610; -- Irradiated Worker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21997; -- Air Force Guard Post (Goblin - Area 52 - Zeppelin)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20485; -- Area 52 Bruiser
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18593; -- Scryer Retainer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17636; -- Kalynna Lathred
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19573; -- Dash
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=19541; -- Netherstorm Agent
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20392; -- Boom Bot Target
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=20284; -- Dr. Boom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19692; -- Boom Bot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18881; -- Sundered Rumbler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18864; -- Mana Wraith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21058; -- Disembodied Exarch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18873; -- Disembodied Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18872; -- Disembodied Vindicator
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `HealthModifier`=0.2, `VerifiedBuild`=25996 WHERE `entry`=64374; -- Cafard du Néant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18880; -- Nether Ray
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20210; -- Shaleskin Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18879; -- Phase Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19569; -- Netherologist Coppernickels
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20203; -- Nether Technician
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62628; -- Jeune basilic brûlé
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20514; -- Searing Elemental
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20925; -- Scalded Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22422; -- Blade's Edge - Legion - Anger Camp - Invis Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21233; -- Legion Fel Cannon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19961; -- Doomforge Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19960; -- Doomforge Engineer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16952; -- Anger Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20998; -- Ridgespine Horror
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21123; -- Felsworn Scalewing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21124; -- Felsworn Daggermaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21300; -- Fel Corrupter
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20635; -- Razaani Light Orb
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21053; -- Blade's Edge - Orb Trigger 03
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20856; -- Blade's Edge - Deadsoul Orb Flight 05
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20666; -- Blade's Edge - Orb Trigger 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20855; -- Blade's Edge - Deadsoul Orb Flight 04
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20853; -- Blade's Edge - Deadsoul Orb Flight 03
UPDATE `creature_template` SET `modelid1`=65891, `VerifiedBuild`=25996 WHERE `entry`=20852; -- Blade's Edge - Deadsoul Orb Flight 02
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=20670; -- Blade's Edge - Flesh Beast Zap Trigger
UPDATE `creature_template` SET `type`=15, `VerifiedBuild`=25996 WHERE `entry`=20668; -- Fiendling Flesh Beast
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20771; -- Razaani Light Orb - Mini
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20609; -- Razaani Nexus Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20851; -- Blade's Edge - Deadsoul Orb Flight 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20601; -- Razaani Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20614; -- Razaani Spell-Thief
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=51786; -- Mok'Nathal Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22468; -- Ogrin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22312; -- Spiritcaller Dohgar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22136; -- Dubu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21106; -- Spiritcaller Skrash
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21105; -- Spiritcaller Roxnak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21103; -- Spiritcaller Grakosh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21088; -- Matron Varah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21086; -- Ruka
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21084; -- Braagor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21082; -- Krugash
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22141; -- Quilbeast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22004; -- Leoroxx
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22110; -- Tethik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21896; -- Silmara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21895; -- Taerek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21692; -- Cansis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21496; -- Dertrok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21083; -- Erool
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22142; -- Zakk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22135; -- Tame Clefthoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21087; -- Grikka
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=22455; -- Sky-Master Maxxor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21085; -- Ragar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21081; -- Mok'Nathal Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20161; -- Vekh'nir Matriarch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19982; -- Vekh'nir Keeneye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21840; -- Cosmetic Silkwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20747; -- Silkwing Larva
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21839; -- Mature Silkwing
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22443; -- Death's Door Fel Cannon
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=25996 WHERE `entry`=22472; -- Death's Door South Warp-Gate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19978; -- Deathforge Over-Smith
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22502; -- Death's Door Warp-Gate Explosion Bunny
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=25996 WHERE `entry`=22471; -- Death's Door North Warp-Gate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22500; -- Void Hound
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22495; -- Death's Door Fel Cannon Target Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22474; -- Unstable Fel-Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19980; -- Void Terror
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=51612; -- Death's Door Fel Cannon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20736; -- Blade's Edge - Legion - Invis Bunny
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=19747; -- Baelmon the Hound-Master
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22423; -- Evergrove Druid
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=22305; -- Vekh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19979; -- Deathforge Technician
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20751; -- Daggermaw Lashtail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19984; -- Vekh'nir Dreadhawk
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=1, `type_flags`=2147483648, `HealthModifier`=3, `movementId`=150, `VerifiedBuild`=25996 WHERE `entry`=115644; -- Scalewing Queen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19983; -- Vekh'nir Stormcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21254; -- Dullgrom Dredger
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=20749; -- Scalewing Serpent
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21659; -- Floaty Flavor Eye
UPDATE `creature_template` SET `type_flags`=2147483656, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=21032; -- Dreadwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21004; -- Lesser Nether Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21814; -- Nether Drake Egg Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21189; -- Crystal Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21413; -- Gnome Cannon Shooter #1
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21944; -- Gnome Cannon Shooter #Ruuan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21935; -- Gnome Cannon Shooter #Shattrath
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=21107; -- Rip Pedalslam
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21930; -- Gnome Cannon Shooter #0
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21111; -- Bembil Knockhammer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21113; -- Sassa Weldwell
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21112; -- Bossi Pentapiston
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21152; -- Station Bot-Jock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21691; -- Toshley
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21755; -- Nickwinkle the Metro-Gnome
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21824; -- Dizzy Dina
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21461; -- Rally Zapnabber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21110; -- Fizit "Doc" Clocktock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21393; -- Cannon Channeler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21494; -- Smiles O'Byron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22090; -- Air Force Guard Post (Toshley's Station - Flying Machine)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21757; -- Big Electromental Flavor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21460; -- Tally Zapnabber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21422; -- Blade's Edge - Toshley's - Invisible Stalker - Atk Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20714; -- Ridgespine Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21447; -- Blade's Edge - Toshley's - Def Gun Attack Origin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21118; -- Razak Ironsides
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21115; -- Station Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21114; -- Station Technician
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21942; -- Gnome Cannon Shooter #Singing Ridge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21819; -- Blade's Edge - Toshley's - Invisible Stalker - Def Gun Target
UPDATE `creature_template` SET `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=68841; -- Raptor lamerouage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22123; -- Rip-Blade Ravager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21519; -- Death's Might
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20766; -- Bladespire Mystic
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20765; -- Bladespire Crusher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21737; -- Mini-Electromental Flavor
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20768; -- Gnosh Brognat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19476; -- Lor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19450; -- Pol Snowhoof
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18953; -- Unoke Tenderhoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19478; -- Fera Palerunner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19471; -- Old Orok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19470; -- Gholah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19473; -- Raiza
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21311; -- Rokgah Bloodgrip
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23280; -- Agadai
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21147; -- Tor'chunk Twoclaws
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21117; -- Gor'drek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19479; -- Orgatha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19472; -- Threlc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18248; -- Nekthar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=10204; -- Misha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19837; -- Daga Ramba
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19474; -- Karnaze
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21142; -- Dire Timber Wolf Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19449; -- Thunderlord Grunt
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=21984; -- Rexxar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21516; -- Death's Watch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21690; -- R-3D0
UPDATE `creature_template` SET `type_flags`=2147483649, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=21956; -- Rema
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20748; -- Thunderlord Dire Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21033; -- Bladewing Bloodletter
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18937; -- Amerun Leafshade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19495; -- Innkeeper Shaunessy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19499; -- Cahill
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19497; -- Caoileann
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22469; -- Fiskal Shadowsong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21197; -- Bronwyn Stouthammer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21151; -- Borgrim Stouthammer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21469; -- Daranelle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19498; -- Tanaide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21158; -- Commander Skyshadow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21066; -- Rina Moonspring
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20126; -- Sylvanaar Ancient Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19500; -- Sylvanaar Sentinel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18098; -- Kialon Nightblade
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20095; -- Grimnok Battleborn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21176; -- Bloodmaul Dire Wolf Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21294; -- Bloodmaul Goon
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=4, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=115598; -- Empowered Earth Elemental
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=115597; -- Geo-Lord Garug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21349; -- T'chali the Witch Doctor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19952; -- Bloodmaul Geomancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20726; -- Mugdorg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20730; -- Glumdor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21975; -- Bladespire Sober Defender
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20723; -- Korgaah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20230; -- Blade's Edge - Bladespire Trigger 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20334; -- Bladespire Cook
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21352; -- Ogre Building Bunny Summoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21277; -- Vindicator Vuuleen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21296; -- Bladespire Champion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19995; -- Bladespire Brute
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20728; -- Bladespire Raptor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19998; -- Bladespire Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21380; -- Greater Crust Burster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23217; -- Bladespire Agent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22941; -- Mog'dorg the Wizened
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22995; -- Chort
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20249; -- Cymbre Starsong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20915; -- Noko Moonwhisper
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=22216; -- Fhyn Leafshadow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22053; -- Mosswood the Ancient
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22007; -- Tree Warden Chawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21983; -- Samia Inkling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22021; -- O'Mally's Instrument Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22020; -- O'Mally Zapnabber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20916; -- Xerintha Ravenoak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21782; -- Timeon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22924; -- Arthorn Windsong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22465; -- Natasha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20250; -- Rashere Pridehoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22150; -- Lieutenant Fairweather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22149; -- Commander Haephus Stonewall
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22127; -- Wildlord Antelarion
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=20917; -- Zinyen Swiftstrider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22922; -- Innkeeper Aelerya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22151; -- Ruuan Weald Sister
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22133; -- Faradrella
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20214; -- Arakkoa Egg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20211; -- Ruuan'ok Matriarch
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20987; -- Ruuan Weald Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19987; -- Ruuan'ok Ravenguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19985; -- Ruuan'ok Cloudgazer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19986; -- Ruuan'ok Skyfury
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21981; -- Overseer Nuaar
UPDATE `creature_template` SET `family`=151, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=883; -- Deer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20889; -- Ethereum Prisoner (Group Energy Ball)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22241; -- Bash'ir Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22919; -- Image of Commander Ameer
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23395; -- Bash'ir Landing Boss Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22242; -- Bash'ir Spell-Thief
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22244; -- Unbound Ethereal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23445; -- Ethereal Ring Target Bunny, Forge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23241; -- Skyguard Aether-Tech
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23262; -- Ethereal Ring, Forge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23430; -- Skyguard Lieutenant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23242; -- Skyguard Ranger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23444; -- Ethereal Ring Target Bunny, Lightning
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23424; -- Ethereal Ring Control Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23246; -- Slavering Slave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23261; -- Furywing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21021; -- Scorch Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23281; -- Insidion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23154; -- Mana-Debt Slave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23153; -- Bash'ir Surveyor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22255; -- Daggertail Lizard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22243; -- Bash'ir Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20757; -- Fingrom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20756; -- Bladespire Chef
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19996; -- Bladespire Battlemage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22918; -- Gronn Showdown Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18693; -- Speaker Mar'grom
UPDATE `creature_template` SET `modelid1`=4585, `family`=160, `VerifiedBuild`=25996 WHERE `entry`=22268; -- Leokk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19997; -- Bladespire Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20729; -- Bladespire Ravager
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20753; -- Dorgok
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22368; -- [DND]Fermented Seed Beer Keg Credit
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22356; -- [DND]Green Spot Grog Keg Credit
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22367; -- [DND]Ripe Moonshine Keg Credit
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22480; -- Brown Marmot
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22116; -- [DND]Whisper Spying Credit Marker 1
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22384; -- Bloodmaul Soothsayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22160; -- Bloodmaul Taskmaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19993; -- Bloodmaul Mauler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19994; -- Bloodmaul Warlock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20330; -- Bloodmaul Battle Worg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22052; -- Daggermaw Blackhide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21381; -- Young Crust Burster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22386; -- Watcher Moonshade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22206; -- Expedition Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3681; -- Wisp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22308; -- Wyrmcult Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21809; -- Wyrmcult Poacher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21811; -- Wyrmcult Broodling
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=22396; -- Draaca Longtail
UPDATE `creature_template` SET `family`=24, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=22040; -- Cave Bat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21810; -- Wyrmcult Hewer
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22801; -- [DND]Prophecy 4 Quest Credit
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22799; -- [DND]Prophecy 2 Quest Credit
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22800; -- [DND]Prophecy 3 Quest Credit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20329; -- Grishna Matriarch
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20924; -- Grishnath Basilisk
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22798; -- [DND]Prophecy 1 Quest Credit
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=21851; -- The Voice of the Raven God
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19988; -- Grishna Falconwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20327; -- Grishna Raven
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19989; -- Grishna Harbinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19990; -- Grishna Scorncrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22215; -- Treebole
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21048; -- Boulder'mok Chieftain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21047; -- Boulder'mok Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21046; -- Boulder'mok Brute
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21040; -- Outraged Raven's Wood Sapling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21383; -- Wyrmcult Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21497; -- Blackscale
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21387; -- Wyrmcult Blackwhelp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21637; -- Wyrmcult Scout
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21326; -- Raven's Wood Leafbeard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21325; -- Raven's Wood Stonebark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21042; -- Dire Raven
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21382; -- Wyrmcult Zealot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22019; -- Kolphis Darkscale
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20557; -- Wrath Hound
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22195; -- Wrath Speaker
UPDATE `creature_template` SET `type`=3, `VerifiedBuild`=25996 WHERE `entry`=22282; -- Witness of Doom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22291; -- Furnace Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22196; -- Wrath Reaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23278; -- Portable Fel Cannon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23228; -- Eye of Shartuul
UPDATE `creature_template` SET `modelid1`=47950, `VerifiedBuild`=25996 WHERE `entry`=23212; -- Mo'arg Tormenter
UPDATE `creature_template` SET `modelid1`=47950, `VerifiedBuild`=25996 WHERE `entry`=23173; -- Felhound Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23078; -- Fel Imp Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23199; -- Gan'arg Underling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23392; -- Skyguard Stable Master
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23334; -- Sky Commander Keller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23208; -- Skyguard Pyrotechnician
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23120; -- Sky Sergeant Vanderlip
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23335; -- Skyguard Khatie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23473; -- Aether-tech Apprentice
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23413; -- Skyguard Handler Irena
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22982; -- Skyguard Navigator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23257; -- Skyguard Windcharger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22987; -- Skyguard Nether Ray
UPDATE `creature_template` SET `modelid1`=47950, `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23500; -- Legion Ring Shield Zapper InvisMan
UPDATE `creature_template` SET `modelid1`=47950, `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23059; -- Legion Ring Event InvisMan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22254; -- Wrath Corruptor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18692; -- Hemathion
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23301; -- Dragon Bunny
UPDATE `creature_template` SET `modelid1`=47206, `VerifiedBuild`=25996 WHERE `entry`=23347; -- Tork
UPDATE `creature_template` SET `modelid1`=47208, `VerifiedBuild`=25996 WHERE `entry`=23110; -- Ogri'la Keg King
UPDATE `creature_template` SET `modelid1`=47204, `VerifiedBuild`=25996 WHERE `entry`=22270; -- Ogri'la Merchant
UPDATE `creature_template` SET `modelid1`=47203, `VerifiedBuild`=25996 WHERE `entry`=22266; -- Ogri'la Grubgiver
UPDATE `creature_template` SET `modelid1`=47209, `VerifiedBuild`=25996 WHERE `entry`=23428; -- Jho'nass
UPDATE `creature_template` SET `modelid1`=47196, `VerifiedBuild`=25996 WHERE `entry`=23316; -- Torkus
UPDATE `creature_template` SET `modelid1`=47210, `VerifiedBuild`=25996 WHERE `entry`=23233; -- Chu'a'lor
UPDATE `creature_template` SET `modelid1`=47205, `VerifiedBuild`=25996 WHERE `entry`=22271; -- Ogri'la Trader
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21234; -- Blade's Edge Invisible Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23300; -- Gahk
UPDATE `creature_template` SET `modelid1`=47195, `VerifiedBuild`=25996 WHERE `entry`=23256; -- Ogri'la Storyteller
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23255; -- Kronk's Book Bunny
UPDATE `creature_template` SET `modelid1`=47194, `VerifiedBuild`=25996 WHERE `entry`=23253; -- Kronk
UPDATE `creature_template` SET `modelid1`=47208, `VerifiedBuild`=25996 WHERE `entry`=23112; -- Mingo
UPDATE `creature_template` SET `modelid1`=47202, `VerifiedBuild`=25996 WHERE `entry`=22264; -- Ogri'la Steelshaper
UPDATE `creature_template` SET `modelid1`=47207, `VerifiedBuild`=25996 WHERE `entry`=23362; -- Torki
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=23115; -- Ogri'la Peacekeeper
UPDATE `creature_template` SET `type_flags`=2147483688, `VerifiedBuild`=25996 WHERE `entry`=23282; -- Obsidia
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62184; -- Vipère des rochers
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23061; -- Rivendark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23382; -- Simon Game Summon Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22923; -- Simon Game Bunny
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=23386; -- Gan'arg Analyzer
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61326; -- Scorpide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22175; -- Apexis Flayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19656; -- Invisible Location Trigger
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=23378; -- Simon Game Bunny Large
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22304; -- Mo'arg Extractor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23174; -- Crystalfused Miner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21203; -- Blade's Edge - Rock Flayer Target
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=22181; -- Aether Ray
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19973; -- Abyssal Flamebringer
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=23082; -- Legion Flak Cannon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23512; -- Crystalforge Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22180; -- Shard-Hide Boar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22298; -- Vile Fire-Soul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23077; -- [PH]Knockdown Fel Cannon Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22204; -- Fear Fiend
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23119; -- Bombing Run Explosion Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23076; -- Legion Flak Cannon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20113; -- Lashh'an Matriarch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20093; -- Blade's Edge - Arakkoa Spell Origin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20024; -- Blade's Edge Kneel Target 03
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20023; -- Blade's Edge Kneel Target 02
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20003; -- Blade's Edge Kneel Target 01
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19943; -- Lashh'an Talonite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20109; -- Lashh'an Kaliri
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19944; -- Lashh'an Wing Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20127; -- Tame Kaliri
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19945; -- Lashh'an Windwalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=61080; -- Lapin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21022; -- Grovestalker Lynx
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21074; -- Living Grove Defender Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20713; -- Fey Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19992; -- Bloodmaul Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15476; -- Scorpid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19948; -- Bloodmaul Skirmisher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=50481; -- Rock Viper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19957; -- Bloodmaul Brewmaster
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=20058; -- Bloodmaul Dire Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19991; -- Bloodmaul Brute
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21238; -- Bloodmaul Drudger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22044; -- Cavern Crawler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22489; -- Grunt Grahk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18922; -- Telredor Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17998; -- Umbrafen Steam Pump Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18138; -- Umbrafen Eel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20079; -- Darkcrest Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19947; -- Darkcrest Sorceress
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18122; -- Dreghood Drudge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19946; -- Darkcrest Slaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18137; -- Marsh Dredger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18912; -- Sporelok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18136; -- Marsh Lurker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18476; -- Timber Worg
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=18586; -- Coosh'coosh
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18080; -- Kataru
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17969; -- Kayra Longmane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20115; -- Umbrafen Witchdoctor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18077; -- Umbrafen Oracle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18079; -- Umbrafen Seer
UPDATE `creature_template` SET `modelid1`=45045, `family`=126, `type_flags`=2147549185, `VerifiedBuild`=25996 WHERE `entry`=18281; -- Boglash
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17901; -- Keleth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17858; -- Warden Hamoot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18911; -- Juno Dufrain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22832; -- Morthis Whisperwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18070; -- Windcaller Blackhoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17900; -- Ashyen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22843; -- Rook
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22842; -- Corvax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18332; -- Talut
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17896; -- Kameel Longstride
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17956; -- Ikeyen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17909; -- Lauranna Thar'well
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21172; -- Sarinei Whitestar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18993; -- Naka
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18907; -- Innkeeper Coryth Stoktron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17904; -- Fedryen Swiftspear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17834; -- Lethyn Moonfire
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `family`=44, `type`=1, `type_flags`=1611661329, `type_flags2`=6, `HealthModifier`=0.1, `VerifiedBuild`=25996 WHERE `entry`=119287; -- Fenglow Stinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17841; -- Ysiel Windsinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22126; -- Air Force Trip Wire - Rooftop (Cenarion Expedition)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22125; -- Air Force Guard Post (Cenarion - Stormcrow)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22124; -- Air Force Alarm Bot (Cenarion)
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=17855; -- Expedition Warden
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=20762; -- Gur'zil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21993; -- Air Force Guard Post (Horde - Bat Rider)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18910; -- Swamprat Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18243; -- Lorti
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18011; -- Zurai
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22002; -- Air Force Trip Wire - Ground (Horde)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22001; -- Air Force Trip Wire - Rooftop (Horde)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18016; -- Magasha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18012; -- Reavij
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2615; -- Air Force Alarm Bot (Horde)
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20283; -- Marshrock Stomper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18035; -- Scout Jyoba
UPDATE `creature_template` SET `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20324; -- Parched Hydra
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=19706; -- Marshrock Threshalisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18124; -- Withered Giant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19402; -- Withered Bog Lord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18130; -- Marshfang Ripper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18132; -- Umbraglow Stinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20387; -- Young Sporebat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18044; -- Rajis Fyashe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18000; -- Serpent Steam Pump Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20089; -- Bloodscale Wavecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20088; -- Bloodscale Overseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20292; -- Marsh Baron Brok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20291; -- Lagoon Walker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20290; -- Lagoon Eel
UPDATE `creature_template` SET `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=18213; -- Mire Hydra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18197; -- Elder Kuruti
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18114; -- Feralfen Mystic
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18113; -- Feralfen Hunter
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=18201; -- Tamed Sporebat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20196; -- Bloodthirsty Marshfang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20270; -- Feralfen Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18128; -- Sporebat
UPDATE `creature_template` SET `family`=126, `type_flags`=65537, `VerifiedBuild`=25996 WHERE `entry`=18134; -- Fen Strider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15384; -- OLDWorld Trigger (DO NOT DELETE)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18212; -- Mudfin Frenzy
UPDATE `creature_template` SET `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=18214; -- Fenclaw Thrasher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18908; -- Innkeeper Kerp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20028; -- Doba
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18010; -- Maktu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18008; -- Ikuti
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22003; -- Air Force Trip Wire - Ground (Alliance)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21996; -- Air Force Guard Post (Alliance - Gryphon)
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=22485; -- Halu
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21999; -- Air Force Trip Wire - Rooftop (Alliance)
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19722; -- Muheru the Weaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18019; -- Timothy Daniels
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18009; -- Puluu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2614; -- Air Force Alarm Bot (Alliance)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20197; -- Bogflare Needler
UPDATE `creature_template` SET `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18159; -- Boss Grog'ak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18943; -- Orebor Harborage Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18118; -- Ango'rosh Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18117; -- Ango'rosh Ogre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20442; -- Captain Bo'kar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19174; -- Chieftain Mummaki
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18115; -- Daggerfen Muckdweller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18116; -- Daggerfen Assassin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18992; -- Captain Krosh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19732; -- Ango'rosh Warlock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18119; -- Ango'rosh Brute
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20443; -- Ango'rosh Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18340; -- Steam Pump Overseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18002; -- Marshlight Steam Pump Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20090; -- Bloodscale Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19733; -- Daggerfen Servant
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=20477; -- Terrorclaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18123; -- Wrekt Slave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20294; -- Bogstrok Razorclaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18089; -- Bloodscale Slavedriver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18088; -- Bloodscale Enchantress
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20295; -- Bogstrok Crusher
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=19730; -- Ironspine Gazer
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=19729; -- Ironspine Threshalisk
UPDATE `creature_template` SET `modelid1`=45045, `family`=126, `type_flags`=65537, `VerifiedBuild`=25996 WHERE `entry`=18680; -- Marticar
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66536; -- Lumiroir
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66534; -- Fongor
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=66551; -- Ras’an
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66535; -- Tripatte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17925; -- Gshaff
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17866; -- Khn'nix
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17856; -- Gzhun'tt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22829; -- Outland Children's Week Sporeggar Trigger
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22823; -- Hch'uu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17924; -- Msshi'fn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17877; -- Fhwoor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18382; -- Mycah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18140; -- Sporeggar Harvester
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18139; -- Sporeggar Preserver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22087; -- Air Force Guard Post (Sporeggar - Sporebat)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22088; -- Air Force Trip Wire - Rooftop (Sporeggar)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22086; -- Air Force Alarm Bot (Sporeggar)
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62564; -- Pousse de sporelin
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=61071; -- Petite grenouille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17923; -- Fahssn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20710; -- Bogstrok Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20293; -- Bogstrok Clacker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17378; -- Swamp Gas
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20280; -- Ragestone Trampler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20198; -- Fenglow Stinger
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=20279; -- Ragestone Threshalisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18125; -- Starving Fungal Giant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19519; -- Starving Bog Lord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18358; -- Sporeggar Spawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18133; -- Marshlight Bleeder
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61142; -- Serpent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18129; -- Greater Sporebat

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=115644 AND `Idx`=1) OR (`CreatureEntry`=115644 AND `Idx`=0) OR (`CreatureEntry`=115597 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(115644, 1, 35229, 25996), -- Scalewing Queen
(115644, 0, 142270, 25996), -- Scalewing Queen
(115597, 0, 142268, 25996); -- Geo-Lord Garug

UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23269 AND `Idx`=0); -- Barash the Den Mother
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23267 AND `Idx`=0); -- Arvoar the Rapacious
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23264 AND `Idx`=0); -- Overmine Flayer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23285 AND `Idx`=0); -- Nethermine Burster
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23326 AND `Idx`=0); -- Nethermine Ravager
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23169 AND `Idx`=0); -- Nethermine Flayer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23501 AND `Idx`=0); -- Netherwing Ray
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21722 AND `Idx`=0); -- Enslaved Netherwing Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21721 AND `Idx`=0); -- Enslaved Netherwing Whelp
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21901 AND `Idx`=0); -- Netherskate
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21102 AND `Idx`=0); -- Uvuros
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21897 AND `Idx`=0); -- Felspine the Greater
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21802 AND `Idx`=0); -- Elekk Demolisher
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23020 AND `Idx`=0); -- Shadow Serpent
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21648 AND `Idx`=0); -- Mature Netherwing Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20502 AND `Idx`=0); -- Eclipsion Dragonhawk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21108 AND `Idx`=0); -- Spawn of Uvuros
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21462 AND `Idx`=0); -- Greater Felfire Diemetradon
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19784 AND `Idx`=0); -- Coilskar Cobra
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21408 AND `Idx`=0); -- Felfire Diemetradon
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21879 AND `Idx`=0); -- Vilewing Chimaera
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21878 AND `Idx`=0); -- Felboar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23219 AND `Idx`=0); -- Blackwind Warp Chaser
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=22105 AND `Idx`=0); -- Decrepit Clefthoof
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18588 AND `Idx`=0); -- Floon
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21515 AND `Idx`=0); -- Trachela
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=22100 AND `Idx`=0); -- Scorpid Bonecrawler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18465 AND `Idx`=0); -- Warp Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18648 AND `Idx`=0); -- Stonegazer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18463 AND `Idx`=0); -- Dampscale Devourer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21816 AND `Idx`=0); -- Ironspine Chomper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18477 AND `Idx`=0); -- Timber Worg Alpha
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18464 AND `Idx`=0); -- Warp Stalker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=16932 AND `Idx`=0); -- Razorfang Hatchling
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21854 AND `Idx`=0); -- Ironspine Petrifier
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18461 AND `Idx`=0); -- Dampscale Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=24922 AND `Idx`=0); -- Razorthorn Ravager
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19349 AND `Idx`=0); -- Thornfang Ravager
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19350 AND `Idx`=0); -- Thornfang Venomspitter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=16880 AND `Idx`=0); -- Hulking Helboar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18678 AND `Idx`=0); -- Fulgorge
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19423 AND `Idx`=0); -- Bleeding Hollow Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19458 AND `Idx`=0); -- Ripp
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19459 AND `Idx`=0); -- Feng
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=16950 AND `Idx`=0); -- Netherhound
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=16863 AND `Idx`=0); -- Deranged Helboar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=16879 AND `Idx`=0); -- Starving Helboar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18877 AND `Idx`=0); -- Nether Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20607 AND `Idx`=0); -- Craghide Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20931 AND `Idx`=0); -- Tyrantus
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20634 AND `Idx`=0); -- Scythetooth Raptor
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20775 AND `Idx`=0); -- Markaru
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20610 AND `Idx`=0); -- Talbuk Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20777 AND `Idx`=0); -- Talbuk Sire
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20773 AND `Idx`=0); -- Barbscale Crocolisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20671 AND `Idx`=0); -- Ripfang Lynx
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20673 AND `Idx`=0); -- Swiftwing Shredder
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18884 AND `Idx`=0); -- Warp Chaser
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20243 AND `Idx`=0); -- Scrapped Fel Reaver
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19852 AND `Idx`=0); -- Artifact Seeker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21058 AND `Idx`=0); -- Disembodied Exarch
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18880 AND `Idx`=0); -- Nether Ray
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20925 AND `Idx`=0); -- Scalded Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21123 AND `Idx`=0); -- Felsworn Scalewing
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21124 AND `Idx`=0); -- Felsworn Daggermaw
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21839 AND `Idx`=0); -- Mature Silkwing
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19980 AND `Idx`=0); -- Void Terror
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20751 AND `Idx`=0); -- Daggermaw Lashtail
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20749 AND `Idx`=0); -- Scalewing Serpent
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21032 AND `Idx`=0); -- Dreadwing
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21004 AND `Idx`=0); -- Lesser Nether Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=22123 AND `Idx`=0); -- Rip-Blade Ravager
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21956 AND `Idx`=0); -- Rema
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20748 AND `Idx`=0); -- Thunderlord Dire Wolf
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21033 AND `Idx`=0); -- Bladewing Bloodletter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20728 AND `Idx`=0); -- Bladespire Raptor
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20987 AND `Idx`=0); -- Ruuan Weald Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23261 AND `Idx`=1); -- Furywing
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23261 AND `Idx`=0); -- Furywing
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23281 AND `Idx`=1); -- Insidion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23281 AND `Idx`=0); -- Insidion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=22255 AND `Idx`=0); -- Daggertail Lizard
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20729 AND `Idx`=0); -- Bladespire Ravager
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20330 AND `Idx`=0); -- Bloodmaul Battle Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=22052 AND `Idx`=0); -- Daggermaw Blackhide
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20924 AND `Idx`=0); -- Grishnath Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21387 AND `Idx`=0); -- Wyrmcult Blackwhelp
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20557 AND `Idx`=0); -- Wrath Hound
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18692 AND `Idx`=0); -- Hemathion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23282 AND `Idx`=1); -- Obsidia
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23282 AND `Idx`=0); -- Obsidia
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23061 AND `Idx`=1); -- Rivendark
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=23061 AND `Idx`=0); -- Rivendark
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=22181 AND `Idx`=0); -- Aether Ray
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=22180 AND `Idx`=0); -- Shard-Hide Boar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=21022 AND `Idx`=0); -- Grovestalker Lynx
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20713 AND `Idx`=0); -- Fey Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20058 AND `Idx`=0); -- Bloodmaul Dire Wolf
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18476 AND `Idx`=0); -- Timber Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18586 AND `Idx`=0); -- Coosh'coosh
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20283 AND `Idx`=0); -- Marshrock Stomper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20324 AND `Idx`=0); -- Parched Hydra
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19706 AND `Idx`=0); -- Marshrock Threshalisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18130 AND `Idx`=0); -- Marshfang Ripper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20387 AND `Idx`=0); -- Young Sporebat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18213 AND `Idx`=0); -- Mire Hydra
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18201 AND `Idx`=0); -- Tamed Sporebat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20196 AND `Idx`=0); -- Bloodthirsty Marshfang
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18128 AND `Idx`=0); -- Sporebat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18214 AND `Idx`=0); -- Fenclaw Thrasher
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19730 AND `Idx`=0); -- Ironspine Gazer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=19729 AND `Idx`=0); -- Ironspine Threshalisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20280 AND `Idx`=0); -- Ragestone Trampler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=20279 AND `Idx`=0); -- Ragestone Threshalisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18129 AND `Idx`=0); -- Greater Sporebat

DELETE FROM `gameobject_template` WHERE `entry` IN (278457 /*Tableau de commandement du chef de guerre*/, 278676 /*Tableau de l’aventurier*/, 269966 /*Grande caisse*/, 278575 /*Tableau de l’appel des héros*/, 278347 /*Tableau de commandement du chef de guerre*/, 278574 /*Tableau de l’appel des héros*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(278457, 10, 47197, 'Warchief''s Command Board', '', '', '', 1, 2824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 261655, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 25996), -- Tableau de commandement du chef de guerre
(278676, 10, 47198, 'Command Board', '', '', '', 1, 2824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256856, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 25996), -- Tableau de l’aventurier
(269966, 5, 31, 'Big Crate', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Grande caisse
(278575, 10, 47195, 'Hero''s Call Board', '', '', '', 1, 2824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 261654, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 25996), -- Tableau de l’appel des héros
(278347, 10, 47199, 'Warchief''s Command Board', '', '', '', 1, 2824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 261655, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 25996), -- Tableau de commandement du chef de guerre
(278574, 10, 47194, 'Hero''s Call Board', '', '', '', 1, 2824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 261654, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 25996); -- Tableau de l’appel des héros

UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=185182; -- Nethervine Crystal
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=185939; -- Nethermine Cargo
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180035; -- Fence
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3946; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3951; -- Mighty Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3950; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3948; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3947; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3945; -- Mighty Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3949; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3944; -- Fierce Blaze
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=185915; -- Netherwing Egg
UPDATE `gameobject_template` SET `type`=50, `Data3`=0, `Data4`=0, `Data5`=0, `Data6`=30, `Data7`=0, `Data18`=10, `Data20`=185878, `VerifiedBuild`=25996 WHERE `entry`=185877; -- Nethercite Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185600; -- Netherwing Egg Trap (Gas)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185156; -- Zuluhed's Chains
UPDATE `gameobject_template` SET `type`=50, `Data3`=0, `Data4`=0, `Data5`=0, `Data6`=30, `Data7`=0, `Data18`=10, `Data20`=185878, `VerifiedBuild`=25996 WHERE `entry`=185881; -- Netherdust Bush
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185878; -- Nethercite Smoke Effect
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185132; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185138; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185137; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185131; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184416; -- 184416
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=216477; -- Boarded Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184114; -- 184114
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184331; -- 184331
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184294; -- 184294
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185550; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184870; -- Baa'ri Tablet Fragment
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184869; -- Baa'ri Tablet Fragment
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184868; -- Baa'ri Tablet Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184490; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185102; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184738; -- Altar of Shadows
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185126; -- Crystal Prison
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185128; -- Lianthe's Strongbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184797; -- Rotten Arakkoa Egg
UPDATE `gameobject_template` SET `Data3`=1, `Data8`=10547, `VerifiedBuild`=25996 WHERE `entry`=184796; -- Rotten Arakkoa Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185130; -- Sketh'lon Feather
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184801; -- Rotten Arakkoa Egg Dummy
UPDATE `gameobject_template` SET `Data3`=1, `Data8`=10547, `VerifiedBuild`=25996 WHERE `entry`=184795; -- Rotten Arakkoa Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183034; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183010; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183033; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183035; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183006; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183028; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183029; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183007; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183030; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183026; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183032; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183027; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183008; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183025; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183024; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183023; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183022; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183031; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183009; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184946; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184652; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183005; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184286; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184285; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182994; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182873; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182872; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182871; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182891; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182874; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182901; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182875; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182865; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182866; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182890; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182863; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182864; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182895; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182894; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182862; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182893; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182892; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182897; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182884; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182896; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182900; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182869; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182883; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182868; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182882; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182899; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182898; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182881; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182928; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182929; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182870; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182878; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182877; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182923; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182922; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182919; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182921; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182902; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182904; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182918; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182920; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182867; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182903; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182876; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182924; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182889; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182888; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182926; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182927; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182925; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182912; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182911; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182910; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182909; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182908; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182907; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182906; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182905; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182887; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182886; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182885; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182880; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182879; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182917; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182916; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182915; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182914; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182913; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183344; -- Fel Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184683; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184701; -- Shadowmoon Tuber Mound
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184714; -- Ball and Chain
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184716; -- Coilskar Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184945; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182946; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184871; -- Fel Reaver Parts Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184860; -- Fel Reaver Armor Plating
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184827; -- Legion Display Device
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184835; -- Infernal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184834; -- Infernal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184833; -- Legion Communication Device
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184872; -- Fel Reaver Parts Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184859; -- Fel Reaver Power Core
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=184948; -- Ever-burning Ash
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184731; -- Demonic Crystal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183402; -- Portcullis
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183401; -- Portcullis
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185123; -- Lever
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184246; -- Heavy Iron Portcullis
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=149046; -- Scaffold Cars
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=149045; -- Scaffold Cars
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184995; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184996; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184994; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184991; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184990; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184986; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184989; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184988; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185928; -- Ancient Skull Pile
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184987; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184909; -- Dave's Glowy Gem Thing
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184908; -- Dave's Circle
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182957; -- Highland Mixed School
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184983; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185952; -- Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185913; -- Skull Pile
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184982; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185549; -- Monstrous Kaliri Egg
UPDATE `gameobject_template` SET `castBarCaption`='Extinguishing', `VerifiedBuild`=25996 WHERE `entry`=185218; -- Violet Signal Fire
UPDATE `gameobject_template` SET `castBarCaption`='Extinguishing', `VerifiedBuild`=25996 WHERE `entry`=185219; -- Bloodstone Signal Fire
UPDATE `gameobject_template` SET `castBarCaption`='Extinguishing', `VerifiedBuild`=25996 WHERE `entry`=185217; -- Emerald Signal Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184458; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185220; -- Massive Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183413; -- Terokkar Banner
UPDATE `gameobject_template` SET `Data8`=1, `VerifiedBuild`=25996 WHERE `entry`=214507; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183414; -- Terokkar Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185184; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185183; -- Bonfire
UPDATE `gameobject_template` SET `castBarCaption`='Breaking', `VerifiedBuild`=25996 WHERE `entry`=185211; -- Cursed Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185208; -- [PH] Arakkoa Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185212; -- [PH] Arakkoa Egg
UPDATE `gameobject_template` SET `castBarCaption`='Breaking', `VerifiedBuild`=25996 WHERE `entry`=185210; -- Cursed Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184843; -- Torgos's Bane
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184842; -- Torgos's Bane
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185225; -- Cabal Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185112; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185110; -- Ancient Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185113; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185111; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185109; -- Ancient Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185108; -- Ancient Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185224; -- Cabal Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183104; -- Terokkar Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185226; -- Cabal Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183829; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183827; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183826; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185191; -- Darkstone of Terokk
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183825; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183828; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183824; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183823; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183830; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182591; -- G_RuneBlue01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184743; -- Consuming Flames
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184730; -- Clefthoof Carrion Flies
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=29784; -- Basic Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=182584; -- Restless Bones
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184800; -- Casket Lid
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184799; -- Ancient Casket
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184807; -- Ethereal Particles
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183411; -- Terokkar Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183412; -- Terokkar Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183922; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183166; -- Smoker
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182118; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182117; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183167; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182588; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183895; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183168; -- Smoker
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183294; -- The Shadow Labyrinth
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182956; -- School of Darter
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184495; -- Campfire
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182546; -- Orb of Translocation
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184232; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184231; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184234; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184237; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184239; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184238; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184236; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184235; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184233; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184229; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184230; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184725; -- Mana Bomb
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182794; -- Cage
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182543; -- Orb of Translocation
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182547; -- Orb of Translocation
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182548; -- Orb of Translocation
UPDATE `gameobject_template` SET `type`=50, `Data0`=38, `Data3`=0, `Data4`=400, `Data5`=450, `Data6`=30, `Data12`=75, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181557; -- Khorium Vein
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183139; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181385; -- Ravager Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183136; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185201; -- Eye of Veil Shienor
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183140; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183135; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183134; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183138; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183137; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182581; -- Draenei Vessel
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182583; -- Draenei Vessel
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182582; -- Draenei Vessel
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182565; -- Eastern Altar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183131; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185200; -- Eye of Veil Reskk
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183128; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182563; -- Northern Altar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182566; -- Western Altar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183129; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183127; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183130; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183789; -- Strange Object
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182524; -- Arcane Aura
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=350, `Data5`=400, `Data6`=30, `Data12`=60, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181277; -- Terocone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180339; -- Candle 02
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180338; -- Candle 01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186041; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186040; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186039; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186027; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186026; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186731; -- Doodad_ET_Holographic_Stand02
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186129; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183432; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186011; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186010; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186025; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186024; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186023; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185506; -- Baby_Gn
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186114; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185510; -- Baby_Ta
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185509; -- Baby_Or
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185511; -- Baby_Tr
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185508; -- Baby_Ne
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185507; -- Baby_Hu
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185459; -- ElfWallHanging09
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185505; -- Baby_dw
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186115; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184139; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183433; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184559; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184558; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184554; -- Molten metal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186013; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186012; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186014; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186009; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186018; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186016; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184136; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184135; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186015; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186019; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186020; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184555; -- Scryer Bank
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185983; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185977; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=188127; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186017; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185978; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183435; -- Marksman Regiment's Cooking Pot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185984; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185970; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183325; -- Shattrath Portal to Stormwind
UPDATE `gameobject_template` SET `Data0`=17609, `VerifiedBuild`=25996 WHERE `entry`=183323; -- Shattrath Portal to Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187345; -- Sunwell Plateau
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185170; -- The Mark of Kael'Thas
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185989; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185993; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185990; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185992; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185972; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185991; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185986; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185985; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185971; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185967; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186144; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186145; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186099; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186096; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185969; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185979; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185997; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187356; -- Shattered Sun Banner (Draenei - Pole)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185988; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185980; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185976; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185987; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187357; -- Shattered Sun Banner (Blood Elf - Pole)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187056; -- Shattrath Portal to Isle of Quel'Danas
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183318; -- Draenei HoloRunes
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180777; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187057; -- Mana Cell 3x3
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187058; -- Mana Cell
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=180871; -- Firecrackers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185975; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185994; -- Brazier
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=180873; -- Firecrackers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185998; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180766; -- Lantern
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180879; -- ElvenWoodenTable
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180778; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=194466; -- Alchemy Lab
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180869; -- Cluster Launcher
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=180764; -- Firecrackers
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=180763; -- Firecrackers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180868; -- Firework Launcher
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185995; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180768; -- Lantern
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=180872; -- Firecrackers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180888; -- OrcTable01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180881; -- AmmoBoxBlueBlock
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180882; -- AmmoBoxRed
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180883; -- AmmoBoxRedBlock
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180880; -- AmmoBoxBlue
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180878; -- GunShopFireworksBarrel
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185996; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185325; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=188126; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183849; -- Alchemy Lab
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183848; -- Alchemy Lab
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186022; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184556; -- Bank of the Aldor
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184137; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186021; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184138; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186001; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186035; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186004; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186003; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186006; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186130; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186125; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186005; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187370; -- Cooking Pot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186126; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186007; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186148; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184557; -- Shattrath Infirmary
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186147; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183286; -- Doodad_PVP_Orc_Door_Front01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186146; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186124; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186008; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183287; -- Doodad_PVP_Orc_Door_Interior01
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182349; -- Corki's Prison
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183289; -- Doodad_PVP_Orc_Door_Interior01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183288; -- Doodad_PVP_Orc_Door_Front01
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=182601; -- Olemba Root
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182541; -- Olemba Cone
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185204; -- Veil Skith Cage
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185202; -- Veil Skith Cage
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185205; -- Veil Skith Cage
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185203; -- Veil Skith Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187073; -- Razorthorn Dirt Mound
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183203; -- Doodad_AncDrae_elevatorPiece02
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183169; -- Doodad_AncDrae_elevatorPiece01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183202; -- Doodad_AncDrae_elevatorPiece03
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184466; -- Metal Coffer
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181637; -- Sha'naar Relic
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184454; -- Earthbinder's Rune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185528; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183038; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182861; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182860; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183436; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184655; -- Sedai's Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183161; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183160; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183159; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184016; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183368; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184028; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184027; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184029; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184026; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183380; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183369; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183383; -- Fire Pit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183379; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183378; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183376; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183374; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183373; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183372; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183371; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183382; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183381; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183370; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183377; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183375; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184030; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184144; -- Arelion's Knapsack Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184115; -- Arelion's Knapsack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181449; -- Altar of Aggonar
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=183515; -- Tower Banners, W
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182173; -- Hellfire Banner, W
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184011; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183839; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183833; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183838; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184455; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184439; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184437; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184436; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183836; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183832; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184497; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184438; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183517; -- Lever
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184498; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184496; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183837; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183844; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183843; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184499; -- Brazier
UPDATE `gameobject_template` SET `Data8`=1, `VerifiedBuild`=25996 WHERE `entry`=211498; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184456; -- Meeting Stone
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182525; -- Tower Banners, N
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182174; -- Hellfire Banner, N
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184032; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183340; -- Imarion's Shield
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183338; -- Imarion's Sword
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=183514; -- Tower Banners, S
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182175; -- Hellfire Banner, S
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184034; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184033; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184035; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185298; -- Anchorite Relic
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184036; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184037; -- Brazier
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=181664; -- Arakkoa Cage
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=183410; -- Explosive Charge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22887; -- Cozy Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22885; -- Cozy Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183504; -- 183504
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183500; -- 183500
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183502; -- 183502
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183503; -- 183503
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183501; -- 183501
UPDATE `gameobject_template` SET `castBarCaption`='Searching', `VerifiedBuild`=25996 WHERE `entry`=185302; -- Fei Fei's Cache
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180575; -- Keg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22902; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22914; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22894; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147282; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147283; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147285; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=146441; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147284; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181475; -- Monument of Remembrance
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=149051; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22929; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22928; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175002; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175003; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22912; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22913; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175014; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175010; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181380; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22911; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=38148; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175013; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175020; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175019; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22882; -- Cozy Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22886; -- Cozy Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175021; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22884; -- Cozy Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148735; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=22883; -- Cozy Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175007; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175025; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175006; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175028; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148757; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148746; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175017; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148756; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148747; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175018; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175008; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175009; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148760; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175015; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175016; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175027; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175024; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175030; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148759; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175001; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148753; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175011; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148763; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175012; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175023; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175005; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175026; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175022; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175029; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=148750; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152328; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175004; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152327; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152325; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37031; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37025; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3772; -- Potbelly Stove
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152329; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37027; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37028; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181066; -- Flowers for Tony
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181064; -- Flowers for Tony
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181369; -- Decorated Gravestone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152332; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181063; -- Flowers for Tony
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152326; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37035; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37026; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37033; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181065; -- Flowers for Tony
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152331; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37032; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181067; -- Flowers for Tony
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37030; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37034; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37029; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152330; -- Fiery Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37036; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37037; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=37038; -- High Back Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183396; -- Zeppelin Debris
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183395; -- Zeppelin Debris
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185167; -- Troll Skull Pile
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185166; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184448; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=2551; -- Boiled Skull
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185180; -- Mordiba's Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183397; -- Zeppelin Debris
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183394; -- Zeppelin Debris
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184005; -- Unyielding Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184852; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182800; -- Bleeding Hollow Supplies
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=51705; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=51704; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=50984; -- Heated Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184657; -- Ironridge Table
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183996; -- Amadi Scroll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181595; -- Campfire
UPDATE `gameobject_template` SET `Data17`=20234, `VerifiedBuild`=25996 WHERE `entry`=216327; -- Soulstone Fragment
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=181372; -- Hellfire Spineleaf
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184415; -- Portal Kaalez
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=195139; -- Portal to Stormwind
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184564; -- 184564
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184565; -- 184565
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183333; -- Vanguard of the Alliance
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184563; -- 184563
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=195140; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183791; -- Might of the Horde
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184289; -- Portal Kruul
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184414; -- Portal Grimh
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184694; -- Zelana's Alchemy Set
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184290; -- Portal Xilus
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182798; -- Salvageable Metal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182799; -- Salvageable Wood
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182797; -- Salvageable Metal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184024; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184023; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183920; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182789; -- Trampled Skeleton
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183916; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183919; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183918; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183917; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183499; -- 183499
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182938; -- Salvageable Metal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182937; -- Salvageable Metal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=106336; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=106327; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=106326; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=106325; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=149038; -- Table Cooker
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=106335; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181381; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183910; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182936; -- Salvageable Wood
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183911; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183912; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183908; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183907; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183909; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183905; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184640; -- Magtheridon's Head
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183906; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=51702; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183904; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=50983; -- Heated Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183347; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=51703; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183348; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183903; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181310; -- Outland Map
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=174859; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3851; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3850; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3849; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3848; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3847; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182147; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182154; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182152; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182151; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182150; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182149; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182148; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183900; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147753; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183902; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182153; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183899; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147762; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183901; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183898; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147749; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147757; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183897; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147758; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147759; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147748; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147756; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147751; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147750; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147744; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147742; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147754; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147752; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147746; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183896; -- Fierce Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147747; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147745; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147766; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182935; -- Rune of Spite
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147767; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185190; -- Hellfire Quest - Rune of Spite Closed 2
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184656; -- Hellfire Quest - Rune of Spite Closed - 3.0
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147768; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147761; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147769; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147765; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147764; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147763; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147760; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147743; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147770; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147755; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=147771; -- Crude Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182945; -- Legion Stone Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182934; -- Glyph Inscribed Obelisk
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=305, `Data5`=355, `Data6`=30, `Data12`=56, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=176586; -- Mountain Silversage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184912; -- The Shattered Halls
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184670; -- CookPot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184311; -- Duro Control Console
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184667; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184434; -- Portable Transponder
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184582; -- 184582
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184447; -- Protectorate Tracer
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184383; -- Ethereum Transponder Zeta
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184581; -- 184581
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184580; -- 184580
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184678; -- Campfire
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184579; -- 184579
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184507; -- 184507
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184510; -- 184510
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184509; -- 184509
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184508; -- 184508
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184677; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184682; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207479; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184583; -- 184583
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184513; -- 184513
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184512; -- 184512
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184511; -- 184511
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184585; -- 184585
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=25996 WHERE `entry`=184516; -- 184516
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184998; -- Ethereum Prison Base (Global)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184298; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184297; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184296; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184295; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183098; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183096; -- Cookpot
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=184615; -- Crystal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184608; -- Raptor Nest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184607; -- Dome Generator Segment
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184092; -- Legion Communicator Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184072; -- Legion Communicator
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184612; -- Surveying Marker Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184071; -- Haramad's Holographic Stand
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184070; -- Nexus-Prince Haramad's Teleporter
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183047; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183048; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186139; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186140; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184590; -- Diagnostic Frame
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184589; -- Diagnostic Equipment
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=175, `Data5`=225, `Data6`=30, `Data12`=30, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=2041; -- Liferoot
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=186729; -- Mana Berry Bush
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184443; -- Ivory Bell
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184613; -- Doomclaw's Brazier
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=183935; -- Fel Reaver Part
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=184031; -- Box of Surveying Equipment
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182559; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186138; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186137; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184734; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184735; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184732; -- Chair
UPDATE `gameobject_template` SET `Data8`=1, `VerifiedBuild`=25996 WHERE `entry`=214500; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=160868; -- Pew
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=160867; -- Pew
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=160866; -- Pew
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=160869; -- Pew
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=160871; -- Pew
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=160870; -- Pew
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184300; -- Necromantic Focus
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184310; -- Suspicious Outhouse
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182421; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182420; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182429; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182436; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182425; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182435; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182426; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182446; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182450; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184123; -- Krasus's Compendium - Chapter 3
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182434; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182433; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182432; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182415; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182414; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184121; -- Krasus's Compendium - Chapter 1
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182422; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182431; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182445; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182447; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182449; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182430; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182423; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183507; -- Archmage Vargoth's Orb
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182424; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182444; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182448; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182428; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182437; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182443; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182427; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182419; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182452; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182418; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182442; -- Chair
UPDATE `gameobject_template` SET `type`=2, `displayId`=1128, `castBarCaption`='Recuperation', `Data0`=1690, `Data2`=1, `Data6`=23645, `VerifiedBuild`=25996 WHERE `entry`=248956; -- Compendium d’armes anciennes, volume V
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182451; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182441; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182440; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182439; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182438; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182417; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182416; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182413; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184254; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184253; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184252; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181915; -- Blaze
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183269; -- Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184124; -- Krasus's Compendium Aura
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184122; -- Krasus's Compendium - Chapter 2
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183267; -- Dresser
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184433; -- Mana Bomb Fragment
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184056; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183266; -- Footlocker
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183268; -- Bookshelf
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183947; -- Kirin'Var Rune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184055; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184320; -- The Arcatraz
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182810; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184666; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184669; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184054; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183945; -- Energy Isolation Cube
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184152; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184675; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184665; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184668; -- Arcane Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184674; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184673; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184672; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184671; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184053; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184051; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184052; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184050; -- Burning Brazier
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=183813; -- Ethereal Technology
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=183814; -- Ethereal Technology
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183808; -- Big Wagon Full of Explosives
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183805; -- Hyper Rotational Dig-A-Matic
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182809; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183807; -- Multi-Spectrum Terrain Analyzer
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183806; -- Servo-Pneumatic Dredging Claw
UPDATE `gameobject_template` SET `Data2`=7810, `VerifiedBuild`=25996 WHERE `entry`=191817; -- Barber Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187299; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184255; -- Long Neck Spectrum Analyzer
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259114; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183987; -- Rocket Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186142; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186141; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184085; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183306; -- Stove
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183811; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183297; -- Doodad_InnBench02
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180037; -- Haybail 01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183298; -- Doodad_InnBench01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183300; -- Doodad_InnBench03
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=179975; -- Water Trough Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183299; -- Doodad_InnBench04
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184488; -- Salvaged Ethereum Prison
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=375, `Data5`=425, `Data6`=30, `Data7`=0, `Data12`=70, `Data13`=1, `Data14`=28702, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181279; -- Netherbloom
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182811; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182788; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182605; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183771; -- Draenei Machine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183768; -- Etherlithium Matrix Crystal
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=183767; -- Etherlithium Matrix Crystal
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184422; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184418; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184431; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184423; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184421; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184420; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184419; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184430; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184429; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184428; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184427; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184426; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184425; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184424; -- Ethereum Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184588; -- Captain Tyralius's Prison
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184330; -- Doodad_AncDrae_elevatorPiece_netherstorm01
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=25996 WHERE `entry`=185197; -- Legion Obelisk
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=25996 WHERE `entry`=185198; -- Legion Obelisk
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=25996 WHERE `entry`=185193; -- Legion Obelisk
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=25996 WHERE `entry`=185195; -- Legion Obelisk
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185194; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185192; -- Brazier
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185165; -- Legion Communicator
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=188132; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185236; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185235; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185243; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185242; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185241; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185239; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185238; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185237; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185240; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183393; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184867; -- Nether Drake Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184944; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185290; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185288; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185289; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185287; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185283; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185286; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184906; -- Power Converter
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183465; -- Smoked Meat Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184467; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185269; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185270; -- Smoked Meat Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183467; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184148; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184660; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185268; -- Smoked Meat Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185267; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183484; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183483; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=177280; -- Moonwell
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184147; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185035; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185164; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185163; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184361; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183927; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184360; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184362; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183931; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183428; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185162; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185161; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184713; -- Bladespire Clan Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184351; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184745; -- T'chali's Skull
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184742; -- T'chali's Grave
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184350; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183430; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184399; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183926; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183427; -- Bonfire
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=184726; -- Thunderlord Clan Drum
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184348; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184346; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184347; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183925; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184397; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183424; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184345; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184398; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183924; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184400; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184736; -- Thunderlord Clan Tablet
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=184728; -- Thunderlord Clan Tablet
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184339; -- Bonfire
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=184727; -- Thunderlord Clan Arrow
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182585; -- Restless Bones
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183923; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184344; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183422; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184313; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183408; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183423; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184702; -- Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183425; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185159; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185160; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185158; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185157; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184341; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185154; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185153; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184342; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184349; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184343; -- Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=185152; -- Grulloc's Sack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185024; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185023; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185025; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185026; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185027; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185120; -- O'Mally's Instrument
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185477; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185028; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185029; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185274; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185281; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185280; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207480; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185282; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185273; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185279; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185278; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185277; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185272; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185271; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185276; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185275; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185031; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185030; -- Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185964; -- Proton Accelerator Controller
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185460; -- Ethereum Prison Base Group (Global)
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185963; -- Proton Accelerator Controller
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185959; -- Proton Accelerator Controller
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185962; -- Proton Accelerator Controller
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185921; -- Bash'ir Crystalforge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185922; -- Crystalforge controller
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183356; -- Theatric Lightning
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185615; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185614; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185613; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185612; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185611; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185610; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185609; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185608; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185619; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185605; -- Large Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185623; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185616; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185620; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185622; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185618; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185607; -- Large Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185621; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185617; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185624; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185627; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185631; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185630; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185628; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185629; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185625; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185626; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185606; -- Large Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185604; -- Large Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185855; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185854; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185853; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185852; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185635; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185634; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185633; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185632; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=185938; -- Insidion's Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185638; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185639; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185677; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185676; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185678; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185679; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185637; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185636; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185650; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185642; -- Large Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185651; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185649; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185686; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185684; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185685; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185687; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185648; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185641; -- Large Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185640; -- Large Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185645; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185646; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185680; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185683; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185681; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185682; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185647; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185644; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185643; -- Large Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185691; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185690; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185689; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185688; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185655; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185654; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185653; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185652; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185673; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185674; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185704; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185707; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185705; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185706; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185672; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185665; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185675; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185666; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185664; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185699; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185696; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185697; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185698; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185667; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185660; -- Large Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185662; -- Large Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185663; -- Large Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185661; -- Large Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185659; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185669; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185656; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185695; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185694; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185692; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185693; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185670; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185657; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185703; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185700; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185701; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185702; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185668; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185658; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185671; -- Green Cluster
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=185937; -- Furywing's Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184366; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184462; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184377; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184376; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184375; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184374; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184370; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184372; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184371; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183420; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184373; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185309; -- Altar of Goc
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184369; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184367; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184368; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185530; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185538; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185537; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185534; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185301; -- [DND]Cage Base
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185296; -- Battered Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185529; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185536; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185533; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185532; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185531; -- Brazier
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=185214; -- Fermented Seed Beer Keg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184364; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185539; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185535; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184356; -- Campfire
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=185206; -- Green Spot Grog Keg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184357; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183419; -- Bonfire
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=325, `Data5`=375, `Data6`=30, `Data12`=62, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181270; -- Felweed
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=185213; -- Ripe Moonshine Keg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184358; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184470; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184471; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184472; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184473; -- Cook Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184474; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184354; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184355; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184475; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185266; -- Brazier
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=184969; -- The Fourth Prophecy
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185262; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185261; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185259; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185263; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185260; -- Brazier
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=184967; -- The Second Prophecy
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185258; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185257; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185256; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184003; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185255; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185254; -- Brazier
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=184968; -- The Third Prophecy
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185253; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185252; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185251; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185250; -- Brazier
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=184950; -- The First Prophecy
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185265; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185264; -- Brazier
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data0`=1690, `Data3`=1, `VerifiedBuild`=25996 WHERE `entry`=182941; -- Grishnath Orb
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183944; -- Ogre Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183943; -- Ogre Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183942; -- Ogre Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184004; -- Anvil
UPDATE `gameobject_template` SET `castBarCaption`='Using', `Data20`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=185234; -- Gorgrom's Altar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184724; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183984; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184840; -- Wyrmcult Egg
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185919; -- Fel Crystalforge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185923; -- Crystalforge controller
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185512; -- Stasis Chamber Alpha
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185465; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185461; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=184595; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185769; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185775; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185770; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185713; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185712; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185714; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185715; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185768; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185774; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185722; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185721; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185720; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185723; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185772; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185771; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185773; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185779; -- Large Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185776; -- Large Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185777; -- Large Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185778; -- Large Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185783; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185780; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185709; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185711; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185710; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185708; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185781; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185782; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185787; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185784; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185717; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185718; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185716; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185719; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185786; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185785; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185965; -- Mailbox
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185466; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185467; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185803; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185790; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185796; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185789; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185799; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185801; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185802; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185800; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185725; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185724; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185727; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185726; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185798; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185791; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185797; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185788; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185792; -- Large Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185793; -- Large Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185795; -- Large Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185811; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185810; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185809; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185808; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185794; -- Large Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185735; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185734; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185733; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185732; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185935; -- Dragon Egg Aura
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=185932; -- Obsidia's Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185931; -- Dragonkin Nest 03
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185930; -- Dragonkin Nest 02
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185929; -- Dragonkin Nest 01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185807; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185806; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185805; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185804; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185731; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185730; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185729; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185728; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185464; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185463; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=185462; -- Ethereum Stasis Chamber
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183930; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183421; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185906; -- Kronk's Book
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185602; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184146; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185831; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185830; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185829; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185828; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185820; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185747; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185746; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185745; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185744; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185823; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185750; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185751; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185749; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185748; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185821; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185816; -- Large Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185822; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185817; -- Large Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185819; -- Large Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185824; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185742; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185743; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185741; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185740; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185825; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185818; -- Large Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185812; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185815; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185738; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185739; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185737; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185736; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185813; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185814; -- Green Cluster
UPDATE `gameobject_template` SET `type`=50, `Data0`=38, `Data3`=0, `Data4`=375, `Data5`=425, `Data6`=30, `Data12`=70, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181569; -- Rich Adamantite Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185827; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185826; -- Green Cluster
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=185911; -- Apexis Shard Formation
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185835; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185834; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185833; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185832; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185767; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185766; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185765; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185764; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185837; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185847; -- Large Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185838; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185846; -- Large Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185755; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185752; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185754; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185753; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185836; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185839; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185842; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185841; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185945; -- Apexis Decharger
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185763; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185762; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185760; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185761; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185843; -- Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185840; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185844; -- Large Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185845; -- Large Red Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185849; -- Yellow Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185850; -- Green Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185756; -- Simon Game Base Blue Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185759; -- Simon Game Base Yellow Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185757; -- Simon Game Base Red Small
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185758; -- Simon Game Base Green Smalll
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185894; -- Relic Decharger
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185890; -- Apexis Relic
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185848; -- Blue Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185851; -- Red Cluster
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=400, `Data5`=450, `Data6`=30, `Data7`=0, `Data12`=75, `Data13`=1, `Data14`=28718, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181281; -- Mana Thistle
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185924; -- Crystalforge controller
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185920; -- Fel Crystalforge
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=380, `Data5`=430, `Data6`=30, `Data7`=0, `Data12`=70, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181280; -- Nightmare Vine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185944; -- Apexis Monument
UPDATE `gameobject_template` SET `castBarCaption`='Using', `VerifiedBuild`=25996 WHERE `entry`=185927; -- Fel Crystal Prism
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185861; -- Fel Cannonball Stack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185244; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185247; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185246; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185245; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185249; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183949; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185248; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183950; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184825; -- Lashh'an Tome
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=182606; -- Dragonspine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184631; -- Grove Seedling
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183290; -- Doodad_PVP_Ogre_Door_Front01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183291; -- Team 2 Inside
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184504; -- Bloodmaul Brew Keg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183429; -- Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=184744; -- T'chali's Hookah
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=184689; -- Draenethyst Mine Crystal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183293; -- Team 1 Inside
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183292; -- Doodad_PVP_Ogre_Door_Front03
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182343; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182209; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182400; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182401; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182402; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183418; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182115; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182271; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182066; -- Lauranna's Guide to Zangarmarsh Plants
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182065; -- A Field Guide to Seeds
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182062; -- Insect Species of Outland
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183039; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182270; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182269; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182944; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181873; -- Steam Pump Part
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181875; -- Steam Pump Part
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181872; -- Steam Pump Part
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182119; -- Dead Mire Soil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181874; -- Steam Pump Part
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181871; -- Steam Pump Part
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183986; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182378; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=152614; -- Elevator
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182377; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182206; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182376; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182205; -- Campfire
UPDATE `gameobject_template` SET `Data0`=43, `Data23`=1, `Data24`=1, `VerifiedBuild`=25996 WHERE `entry`=182116; -- Fulgor Spore
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183894; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184740; -- Wicker Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182139; -- Feralfen Idol
UPDATE `gameobject_template` SET `Data3`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182529; -- Zangarmarsh Banner
UPDATE `gameobject_template` SET `Data8`=1, `VerifiedBuild`=25996 WHERE `entry`=214501; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182954; -- Brackish Mixed School
UPDATE `gameobject_template` SET `Data8`=1, `VerifiedBuild`=25996 WHERE `entry`=214503; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183177; -- Doodad_mushroombase_elevator01
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183040; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183284; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182571; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182185; -- Daggerfen Poison Vial
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207478; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182575; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183415; -- Ogre Firepit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182573; -- Ogre Firepit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182574; -- Ogre Firepit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182184; -- Daggerfen Poison Manual
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182166; -- Ango'rosh Attack Plans
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184396; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184395; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182576; -- Ogre Firepit
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=295, `Data5`=345, `Data6`=30, `Data12`=54, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=176584; -- Dreamfoil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182578; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182577; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182579; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182082; -- The Ark of Ssslith
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182107; -- (NEEDS GRAPHICS)Steam Pump Controls
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182538; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182535; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182536; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182095; -- Burstcap Mushroom
UPDATE `gameobject_template` SET `type`=50, `Data3`=0, `Data4`=325, `Data5`=375, `Data6`=30, `Data12`=62, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=183044; -- Felweed
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184212; -- Coilfang Resevoir Waterfall
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182537; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182953; -- Sporefish School
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182952; -- Steam Pump Flotsam
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182534; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184836; -- Campfire
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=285, `Data5`=335, `Data6`=30, `Data12`=52, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=176583; -- Golden Sansam
UPDATE `gameobject_template` SET `type`=50, `Data3`=0, `Data4`=350, `Data5`=400, `Data6`=30, `Data12`=65, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=183043; -- Ragveil
UPDATE `gameobject_template` SET `type`=50, `Data3`=0, `Data4`=260, `Data5`=310, `Data6`=30, `Data12`=47, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=183046; -- Blindweed
UPDATE `gameobject_template` SET `type`=50, `Data3`=0, `Data4`=340, `Data5`=390, `Data6`=30, `Data7`=0, `Data12`=60, `Data13`=1, `Data14`=28694, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=183045; -- Dreaming Glory
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182069; -- Mature Spore Sac
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=182053; -- Glowcap


UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185182 AND `Idx`=0); -- Nethervine Crystal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185939 AND `Idx`=0); -- Nethermine Cargo
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184870 AND `Idx`=0); -- Baa'ri Tablet Fragment
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184869 AND `Idx`=0); -- Baa'ri Tablet Fragment
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185128 AND `Idx`=0); -- Lianthe's Strongbox
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185130 AND `Idx`=0); -- Sketh'lon Feather
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184795 AND `Idx`=0); -- Rotten Arakkoa Egg
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184860 AND `Idx`=0); -- Fel Reaver Armor Plating
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184859 AND `Idx`=0); -- Fel Reaver Power Core
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184948 AND `Idx`=0); -- Ever-burning Ash
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185220 AND `Idx`=0); -- Massive Treasure Chest
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185225 AND `Idx`=0); -- Cabal Chest
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185224 AND `Idx`=0); -- Cabal Chest
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185226 AND `Idx`=0); -- Cabal Chest
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182584 AND `Idx`=0); -- Restless Bones
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181385 AND `Idx`=0); -- Ravager Egg
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185201 AND `Idx`=0); -- Eye of Veil Shienor
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182581 AND `Idx`=0); -- Draenei Vessel
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185200 AND `Idx`=0); -- Eye of Veil Reskk
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182601 AND `Idx`=0); -- Olemba Root
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182541 AND `Idx`=0); -- Olemba Cone
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184466 AND `Idx`=0); -- Metal Coffer
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181637 AND `Idx`=0); -- Sha'naar Relic
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184115 AND `Idx`=0); -- Arelion's Knapsack
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185302 AND `Idx`=0); -- Fei Fei's Cache
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183396 AND `Idx`=0); -- Zeppelin Debris
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183395 AND `Idx`=0); -- Zeppelin Debris
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183397 AND `Idx`=0); -- Zeppelin Debris
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183394 AND `Idx`=0); -- Zeppelin Debris
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=216327 AND `Idx`=0); -- Soulstone Fragment
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181372 AND `Idx`=0); -- Hellfire Spineleaf
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182798 AND `Idx`=0); -- Salvageable Metal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182799 AND `Idx`=0); -- Salvageable Wood
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182797 AND `Idx`=0); -- Salvageable Metal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182938 AND `Idx`=0); -- Salvageable Metal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182937 AND `Idx`=0); -- Salvageable Metal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182936 AND `Idx`=0); -- Salvageable Wood
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184607 AND `Idx`=0); -- Dome Generator Segment
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184589 AND `Idx`=0); -- Diagnostic Equipment
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=186729 AND `Idx`=0); -- Mana Berry Bush
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184443 AND `Idx`=0); -- Ivory Bell
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183935 AND `Idx`=0); -- Fel Reaver Part
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184031 AND `Idx`=0); -- Box of Surveying Equipment
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184310 AND `Idx`=0); -- Suspicious Outhouse
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184123 AND `Idx`=0); -- Krasus's Compendium - Chapter 3
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184121 AND `Idx`=0); -- Krasus's Compendium - Chapter 1
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184122 AND `Idx`=0); -- Krasus's Compendium - Chapter 2
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184433 AND `Idx`=0); -- Mana Bomb Fragment
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183945 AND `Idx`=0); -- Energy Isolation Cube
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183813 AND `Idx`=0); -- Ethereal Technology
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183814 AND `Idx`=0); -- Ethereal Technology
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=183767 AND `Idx`=0); -- Etherlithium Matrix Crystal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184726 AND `Idx`=0); -- Thunderlord Clan Drum
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184728 AND `Idx`=0); -- Thunderlord Clan Tablet
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184727 AND `Idx`=0); -- Thunderlord Clan Arrow
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=185152 AND `Idx`=0); -- Grulloc's Sack
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182606 AND `Idx`=0); -- Dragonspine
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184744 AND `Idx`=0); -- T'chali's Hookah
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=184689 AND `Idx`=0); -- Draenethyst Mine Crystal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181873 AND `Idx`=0); -- Steam Pump Part
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181875 AND `Idx`=0); -- Steam Pump Part
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181872 AND `Idx`=0); -- Steam Pump Part
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182119 AND `Idx`=0); -- Dead Mire Soil
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181874 AND `Idx`=0); -- Steam Pump Part
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=181871 AND `Idx`=0); -- Steam Pump Part
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182116 AND `Idx`=0); -- Fulgor Spore
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182139 AND `Idx`=0); -- Feralfen Idol
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182185 AND `Idx`=0); -- Daggerfen Poison Vial
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182184 AND `Idx`=0); -- Daggerfen Poison Manual
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182166 AND `Idx`=0); -- Ango'rosh Attack Plans
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182095 AND `Idx`=0); -- Burstcap Mushroom

