DELETE FROM `gameobject_template_addon` WHERE `entry` IN (288154 /*Idol of Binding*/, 289733 /*Gong of Zem'lan*/, 272622 /*Cursed Treasure*/, 287490 /*Cursed Treasure*/, 287493 /*Cursed Treasure*/, 289734 /*Cursed Altar of Zem'lan*/, 287314 /*Disturbed Sand*/, 277530 /*Captain Gulnaku's Treasure*/, 277527 /*Freshly Dug Sand*/, 277356 /*Zandalari Cauldron*/, 287495 /*Pirate Hat*/, 280613 /*Zandalari Cooking Pit*/, 289728 /*Captain Gulnaku's Treasure Map*/, 275099 /*Saurolisk Egg*/, 282636 /*Sezahjin's Meat Pies*/, 282633 /*Alpaca Butter*/, 282635 /*Alpaca Hides*/, 287398 /*Wanted: Za'roco*/, 282634 /*Hyena Jerky*/, 292784 /*Zandalari Dunemelons*/, 282632 /*Fresh Water*/, 282631 /*Medicinal Herbs*/, 290712 /*Sandworn Blade*/, 279646 /*Bloodguard Chronicles*/, 287440 /*Wanted: Taz'raka*/, 287498 /*Zem'lan Blackeye Brew*/, 271662 /*Hissing Crate*/, 284418 /*Treasure Chest*/, 287496 /*Treasure Map*/, 296574 /*Ian's Empty Bottle*/, 276242 /*Anchor Weed*/, 281872 /*Sea Stalks*/, 297494 /*Tales of de Loa: Kimbul*/, 284417 /*Treasure Chest*/, 282498 /*Desert Flute*/, 289364 /*Sethrak Cage*/, 277876 /*Sethrak Cage*/, 277899 /*Sethrak War Banner*/, 287441 /*Wanted: Sandscout Vesarik*/, 277911 /*Sethrak Spire*/, 296580 /*Ofer's Bound Journal*/, 296581 /*Skye's Pet Rock*/, 273837 /*Supply Pouch*/, 273836 /*Backpack*/, 282740 /*Mysterious Trashpile*/, 276394 /*Stolen Relics*/, 276393 /*Stolen Relics*/, 276392 /*Stolen Relics*/, 281583 /*Ancient Reliquary*/, 281558 /*Glittering Sapphire*/, 281639 /*Crumbling Statue*/, 281634 /*Cracked Stone Tablet*/, 281229 /*Magic Barrier*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(288154, 0, 262144), -- Idol of Binding
(289733, 0, 262144), -- Gong of Zem'lan
(272622, 0, 2113540), -- Cursed Treasure
(287490, 0, 2113540), -- Cursed Treasure
(287493, 0, 2113540), -- Cursed Treasure
(289734, 0, 262144), -- Cursed Altar of Zem'lan
(287314, 0, 262144), -- Disturbed Sand
(277530, 0, 4), -- Captain Gulnaku's Treasure
(277527, 0, 2113536), -- Freshly Dug Sand
(277356, 114, 0), -- Zandalari Cauldron
(287495, 0, 262144), -- Pirate Hat
(280613, 114, 0), -- Zandalari Cooking Pit
(289728, 0, 4), -- Captain Gulnaku's Treasure Map
(275099, 0, 2113540), -- Saurolisk Egg
(282636, 0, 2113540), -- Sezahjin's Meat Pies
(282633, 0, 2113540), -- Alpaca Butter
(282635, 0, 2113540), -- Alpaca Hides
(287398, 0, 4), -- Wanted: Za'roco
(282634, 0, 2113540), -- Hyena Jerky
(292784, 0, 2113540), -- Zandalari Dunemelons
(282632, 0, 2113540), -- Fresh Water
(282631, 0, 2113540), -- Medicinal Herbs
(290712, 0, 2113540), -- Sandworn Blade
(279646, 0, 4), -- Bloodguard Chronicles
(287440, 0, 4), -- Wanted: Taz'raka
(287498, 0, 262144), -- Zem'lan Blackeye Brew
(271662, 0, 262144), -- Hissing Crate
(284418, 0, 278528), -- Treasure Chest
(287496, 0, 262144), -- Treasure Map
(296574, 0, 2113568), -- Ian's Empty Bottle
(276242, 0, 278528), -- Anchor Weed
(281872, 0, 278528), -- Sea Stalks
(297494, 0, 262144), -- Tales of de Loa: Kimbul
(284417, 0, 278528), -- Treasure Chest
(282498, 0, 4), -- Desert Flute
(289364, 0, 262148), -- Sethrak Cage
(277876, 0, 262144), -- Sethrak Cage
(277899, 0, 262144), -- Sethrak War Banner
(287441, 0, 4), -- Wanted: Sandscout Vesarik
(277911, 0, 262144), -- Sethrak Spire
(296580, 0, 2113568), -- Ofer's Bound Journal
(296581, 0, 2113568), -- Skye's Pet Rock
(273837, 0, 2113540), -- Supply Pouch
(273836, 0, 2113540), -- Backpack
(282740, 0, 262144), -- Mysterious Trashpile
(276394, 0, 8192), -- Stolen Relics
(276393, 0, 8192), -- Stolen Relics
(276392, 0, 8192), -- Stolen Relics
(281583, 0, 4), -- Ancient Reliquary
(281558, 0, 2113540), -- Glittering Sapphire
(281639, 0, 4), -- Crumbling Statue
(281634, 0, 262144), -- Cracked Stone Tablet
(281229, 0, 32); -- Magic Barrier

UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=218384; -- Zandalari Crate 03

DELETE FROM `scene_template` WHERE (`SceneId`=2140 AND `ScriptPackageID`=2348);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(2140, 27, 2348);


DELETE FROM `quest_offer_reward` WHERE `ID` IN (51062 /*-Unknown-*/, 48326 /*-Unknown-*/, 51061 /*-Unknown-*/, 51060 /*-Unknown-*/, 51059 /*-Unknown-*/, 49138 /*-Unknown-*/, 51057 /*-Unknown-*/, 47499 /*-Unknown-*/, 51056 /*-Unknown-*/, 51055 /*-Unknown-*/, 51054 /*-Unknown-*/, 51053 /*-Unknown-*/, 48324 /*-Unknown-*/, 48657 /*-Unknown-*/, 48656 /*-Unknown-*/, 48655 /*-Unknown-*/, 48533 /*-Unknown-*/, 48531 /*-Unknown-*/, 48585 /*-Unknown-*/, 48532 /*-Unknown-*/, 51162 /*-Unknown-*/, 48530 /*-Unknown-*/, 48529 /*-Unknown-*/, 51573 /*-Unknown-*/, 50794 /*-Unknown-*/, 50812 /*-Unknown-*/, 50775 /*-Unknown-*/, 50771 /*-Unknown-*/, 51991 /*-Unknown-*/, 52129 /*-Unknown-*/, 50834 /*-Unknown-*/, 50980 /*-Unknown-*/, 50817 /*-Unknown-*/, 50979 /*-Unknown-*/, 50818 /*-Unknown-*/, 49340 /*-Unknown-*/, 49334 /*-Unknown-*/, 49327 /*-Unknown-*/, 50641 /*-Unknown-*/, 47324 /*-Unknown-*/, 50561 /*-Unknown-*/, 48315 /*-Unknown-*/, 50539 /*-Unknown-*/, 50770 /*-Unknown-*/, 48313 /*-Unknown-*/, 48314 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(51062, 1, 0, 0, 0, 0, 0, 0, 0, 'What have you gotten us into, $p? We asked you to find our friend, not bring monsters into our camp.', 27843), -- -Unknown-
(48326, 1, 0, 0, 0, 0, 0, 0, 0, 'Yarr! Vengeance and treasure!', 27843), -- -Unknown-
(51061, 1, 0, 0, 0, 0, 0, 0, 0, 'I guess de idols can\'t be destroyed... even by a mortal. Curses be fickle things.$B$BI was de first Zem\'lan cursed, and I did nothin\' to stop him from cursin\' de rest of de crew.$B$BI regret it every day...$B$BBut enough livin\' in de past. It\'s time to be free.', 27843), -- -Unknown-
(51060, 1, 0, 0, 0, 0, 0, 0, 0, 'I suppose dis little amount of gold won\'t be cursin\' ya for too long. I\'ll carry de rest.', 27843), -- -Unknown-
(51059, 396, 0, 0, 0, 0, 0, 0, 0, 'Here we are. De Golden Isle. It\'s beautiful, ain\'t it?$B$BA pirate\'s paradise.', 27843), -- -Unknown-
(49138, 0, 0, 0, 0, 0, 0, 0, 0, '<The chest is filled with shiny treasure.>', 27843), -- -Unknown-
(51057, 1, 0, 0, 0, 0, 0, 0, 0, 'Good. We be ready to sail.', 27843), -- -Unknown-
(47499, 1, 0, 0, 0, 0, 0, 0, 0, 'Dese be cursed and evil things.', 27843), -- -Unknown-
(51056, 1, 0, 0, 0, 0, 0, 0, 0, 'Now you know how desperate we were on dat day, $p.$B$BI don\'t be making excuses, but you should understand why we did what we did.', 27843), -- -Unknown-
(51055, 1, 0, 0, 0, 0, 0, 0, 0, 'It looks like we all be of one accord. It be mutiny!', 27843), -- -Unknown-
(51054, 1, 0, 0, 0, 0, 0, 0, 0, 'Dis won\'t be easy, $p. But it be worth it.', 27843), -- -Unknown-
(51053, 1, 0, 0, 0, 0, 0, 0, 0, 'Dat was where it all began. I could\'ve stopped Zem\'lan right dere... I could\'ve prevented dis fate for de crew.\n\nInstead, I led dem straight into it.', 27843), -- -Unknown-
(48324, 1, 0, 0, 0, 0, 0, 0, 0, '<Meeki has been stabbed multiple times. He is clearly dead.>', 27843), -- -Unknown-
(48657, 1, 0, 0, 0, 0, 0, 0, 0, 'You have de eggs! Be careful not to break dem... just roll dem under da box... gently... gently now...', 27843), -- -Unknown-
(48656, 6, 0, 0, 0, 0, 0, 0, 0, 'De saurolisks are all gone and it\'s safe to come out? Thank you so much! I never thought I\'d make it out of here alive!', 27843), -- -Unknown-
(48655, 1, 0, 0, 0, 0, 0, 0, 0, 'You can\'t fool me, saurolisk! I know you\'re out dere waiting to eat me! Oh wait... you\'re a grown up! Please, get me out of here! Help!', 27843), -- -Unknown-
(48533, 1, 0, 0, 0, 0, 0, 0, 0, 'It may not be chicken, but it\'s food! With enough seasoning nobody will know de difference.$b$bEverything tastes like chicken, right?', 27843), -- -Unknown-
(48531, 1, 0, 0, 0, 0, 0, 0, 0, 'Just look at all dese juicy intestines! We\'ll have enough pies to feed de entire camp!', 27843), -- -Unknown-
(48585, 1, 0, 0, 0, 0, 0, 0, 0, 'I see you made a scavenging run and came back alive!$b$bWe will put these supplies to good use among the tribe. You have my thanks.', 27843), -- -Unknown-
(48532, 1, 0, 0, 0, 0, 0, 0, 0, 'Looks like you recovered most of de herd. Good work... even though Mojambo and his henchmons will probably murder us in our sleep and take de alpacas for demselves...', 27843), -- -Unknown-
(51162, 1, 0, 0, 0, 0, 0, 0, 0, 'A bounty worth paying. Thank you, $p.', 27843), -- -Unknown-
(48530, 6, 1, 0, 0, 0, 3000, 0, 0, 'Razgaji sent you? I\'m not sure why he cares so much. When Mojambo and his gang come back, we\'ll all be dead anyway...', 27843), -- -Unknown-
(48529, 6, 1, 0, 0, 0, 3000, 0, 0, 'A newcomer, eh? You picked a bad time to join our tribe. You\'d find better luck wandering de wastes in search of mirages.', 27843), -- -Unknown-
(51573, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojambo will come back with all his minions. And when he does... dere will be blood.', 27843), -- -Unknown-
(50794, 1, 0, 0, 0, 0, 0, 0, 0, 'Yes, Julwaba told me to expect you.', 27843), -- -Unknown-
(50812, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s better. Not sure how we were going to turn a profit if we had to keep replacing workers.', 27843), -- -Unknown-
(50775, 1, 0, 0, 0, 0, 0, 0, 0, 'That should fill us up a few more bags. If they run out again, I\'ll make \'em break out the pickaxes.$b$bI bet then a little self-fueling won\'t sound so bad!$b$bUngrateful sons of bellybutton lint...', 27843), -- -Unknown-
(50771, 1, 0, 0, 0, 0, 0, 0, 0, 'Not bad, chief! The crew should be wrapping it up soon.', 27843), -- -Unknown-
(51991, 5, 0, 0, 0, 0, 0, 0, 0, 'Hey! Not bad for your first time! They\'re so ugly they\'re cute, aren\'t they?', 27843), -- -Unknown-
(52129, 1, 0, 0, 0, 0, 0, 0, 0, 'If Merd wants you to help, I\'ve got just the thing!', 27843), -- -Unknown-
(50834, 5, 0, 0, 0, 0, 0, 0, 0, 'Dangerous? Violence incoming? Tell us somethin\' we don\'t know!$b$bWe ain\'t goin\' nowhere until we get what we came for!', 27843), -- -Unknown-
(50980, 4, 0, 0, 0, 0, 0, 0, 0, 'It seems he found you indigestible. Excellent work!$b$bWe all thank you!', 27843), -- -Unknown-
(50817, 1, 0, 0, 0, 0, 0, 0, 0, 'Yes! Thanks, $n! They are so much happier now!', 27843), -- -Unknown-
(50979, 1, 0, 0, 0, 0, 0, 0, 0, 'Thanks, $n! That should do the trick!$b$bAt least it will tide me over until they realize we\'re on the same side.', 27843), -- -Unknown-
(50818, 5, 0, 0, 0, 0, 0, 0, 0, 'My flute! I\'ve been looking everywhere!$b$bWell, sort of...', 27843), -- -Unknown-
(49340, 1, 0, 0, 0, 0, 0, 0, 0, 'Thanks to you, we now have two of the keys. Korthek still holds the third.$B$BIf we can get our hands on that key, then Mythrax will remain sealed in his tomb forever.', 27843), -- -Unknown-
(49334, 1, 0, 0, 0, 0, 0, 0, 0, 'I owe you my life, $n.', 27843), -- -Unknown-
(49327, 1, 0, 0, 0, 0, 0, 0, 0, 'The faithless will never stop their siege, but your efforts have bought us time.', 27843), -- -Unknown-
(50641, 1, 0, 0, 0, 0, 0, 0, 0, 'Our temple will not fall at the hands of the faithless!', 27843), -- -Unknown-
(47324, 1, 0, 0, 0, 0, 0, 0, 0, 'We cannot let the Faithless take this temple!', 27843), -- -Unknown-
(50561, 1, 0, 0, 0, 0, 0, 0, 0, 'This stone... I\'ve seen one like it before.', 27843), -- -Unknown-
(48315, 0, 0, 0, 0, 0, 0, 0, 0, '<The gems slot perfectly into place.>', 27843), -- -Unknown-
(50539, 1, 0, 0, 0, 0, 0, 0, 0, '<The ancient stones hum with magic.>', 27843), -- -Unknown-
(50770, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you for saving my life. I\'m afraid we don\'t have time for formal introductions.', 27843), -- -Unknown-
(48313, 1, 0, 0, 0, 0, 0, 0, 0, 'These cactus roots will do nicely.', 27843), -- -Unknown-
(48314, 1, 0, 0, 0, 0, 0, 0, 0, 'Be gentle with the scorpashi stingers, it will only complicate matters worse if one of us become poisoned. The venom of the scorpashi is highly toxic.', 27843); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=48327 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48327 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51062 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51062 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51062 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48326 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48326 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48326 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48326 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51061 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51061 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51061 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51061 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51060 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51060 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51060 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51059 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51059 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51059 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49138 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=49138 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=49138 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49138 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49138 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49138 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51057 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51057 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51057 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=51057 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47499 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=47499 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=47499 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47499 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47499 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47499 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51056 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51056 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51056 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51056 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51055 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=51055 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51055 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51055 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51055 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47647 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=47647 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=47647 AND `BlobIndex`=2 AND `Idx1`=5) OR (`QuestID`=47647 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=47647 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47647 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47647 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47647 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51054 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51054 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51054 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51053 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51053 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51053 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48657 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48657 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48657 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48656 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48656 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48656 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48655 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48655 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48585 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48585 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48585 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48532 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48532 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48532 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48533 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48533 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48533 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48531 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48531 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48531 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48530 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48530 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48529 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48529 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51573 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51573 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51573 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51162 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51162 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51162 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48324 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48324 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50812 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=50812 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50812 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50812 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51991 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51991 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51991 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51991 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=52129 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=52129 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50775 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50775 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50775 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50771 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50771 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50771 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50834 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50834 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50980 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50980 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50980 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50817 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50817 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50817 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50979 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50979 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50979 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49662 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49662 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49340 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49340 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49340 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50818 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50818 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51165 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51165 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51165 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49327 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=49327 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49327 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49327 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49327 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50641 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50641 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50641 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49334 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49334 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49334 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47324 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47324 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47324 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47324 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50794 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50794 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50561 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50561 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48315 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48315 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48315 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50539 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50539 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50770 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50770 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50770 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48313 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48313 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48313 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48314 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48314 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48314 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(48327, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1385844, 0, 27843), -- -Unknown-
(48327, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1463715, 0, 27843), -- -Unknown-
(51062, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(51062, 0, 1, 0, 335175, 136953, 1642, 864, 0, 0, 0, 0, 1490652, 0, 27843), -- -Unknown-
(51062, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1385844, 0, 27843), -- -Unknown-
(48326, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(48326, 0, 2, 1, 294184, 127025, 1642, 864, 0, 0, 0, 0, 1374436, 0, 27843), -- -Unknown-
(48326, 0, 1, 0, 294183, 136921, 1642, 864, 0, 0, 0, 0, 1374436, 0, 27843), -- -Unknown-
(48326, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(51061, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(51061, 0, 2, 1, 336029, 136792, 1642, 864, 0, 0, 0, 0, 1374436, 0, 27843), -- -Unknown-
(51061, 0, 1, 0, 335119, 137869, 1642, 864, 0, 0, 0, 0, 1509160, 0, 27843), -- -Unknown-
(51061, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(51060, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(51060, 0, 1, 0, 335037, 152659, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51060, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(51059, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1488804, 0, 27843), -- -Unknown-
(51059, 0, 1, 0, 335115, 136775, 1642, 864, 0, 0, 0, 0, 1397333, 0, 27843), -- -Unknown-
(51059, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1494261, 0, 27843), -- -Unknown-
(49138, 0, 5, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1509134, 0, 27843), -- -Unknown-
(49138, 0, 4, 4, 294188, 153419, 1642, 864, 0, 0, 0, 0, 1397598, 0, 27843), -- -Unknown-
(49138, 0, 3, 3, 294027, 128502, 1642, 864, 0, 0, 0, 0, 1399081, 0, 27843), -- -Unknown-
(49138, 0, 2, 2, 294026, 128501, 1642, 864, 0, 0, 0, 0, 1399074, 0, 27843), -- -Unknown-
(49138, 0, 1, 1, 294025, 128500, 1642, 864, 0, 0, 0, 0, 1399076, 0, 27843), -- -Unknown-
(49138, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1399081, 0, 27843), -- -Unknown-
(51057, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1488803, 0, 27843), -- -Unknown-
(51057, 0, 2, 0, 335071, 136744, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51057, 1, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 63850, 1488803, 0, 27843), -- -Unknown-
(51057, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 63851, 1488804, 0, 27843), -- -Unknown-
(47499, 0, 5, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1488803, 0, 27843), -- -Unknown-
(47499, 0, 4, 2, 293982, 153352, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(47499, 0, 3, 1, 293981, 151021, 1642, 864, 0, 0, 0, 0, 1398778, 0, 27843), -- -Unknown-
(47499, 0, 2, 0, 293879, 153351, 1642, 864, 0, 0, 0, 0, 1397874, 0, 27843), -- -Unknown-
(47499, 0, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 63851, 1488804, 0, 27843), -- -Unknown-
(47499, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 63850, 1488803, 0, 27843), -- -Unknown-
(51056, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1488803, 0, 27843), -- -Unknown-
(51056, 0, 2, 1, 334887, 136610, 1642, 864, 0, 0, 0, 0, 1492349, 0, 27843), -- -Unknown-
(51056, 0, 1, 0, 334886, 136609, 1642, 864, 0, 0, 0, 0, 1492260, 0, 27843), -- -Unknown-
(51056, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1488803, 0, 27843), -- -Unknown-
(51055, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1488803, 0, 27843), -- -Unknown-
(51055, 0, 3, 2, 334871, 136605, 1642, 864, 0, 0, 0, 0, 1490459, 0, 27843), -- -Unknown-
(51055, 0, 2, 1, 334870, 136604, 1642, 864, 0, 0, 0, 0, 1490457, 0, 27843), -- -Unknown-
(51055, 0, 1, 0, 334869, 136603, 1642, 864, 0, 0, 0, 0, 1490450, 0, 27843), -- -Unknown-
(51055, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1488803, 0, 27843), -- -Unknown-
(47647, 0, 7, 32, 0, 0, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(47647, 0, 6, 5, 294518, 128369, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(47647, 2, 5, 4, 293949, 129435, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(47647, 1, 4, 4, 293949, 129435, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(47647, 0, 3, 4, 293949, 129435, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(47647, 0, 2, 3, 293948, 128380, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(47647, 0, 1, 2, 293947, 128315, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(47647, 0, 0, 1, 293943, 128379, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(51054, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1488799, 0, 27843), -- -Unknown-
(51054, 0, 1, 0, 334846, 136571, 1642, 864, 0, 0, 0, 0, 1491441, 0, 27843), -- -Unknown-
(51054, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1488803, 0, 27843), -- -Unknown-
(51053, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1488799, 0, 27843), -- -Unknown-
(51053, 0, 1, 0, 334825, 136503, 1642, 864, 0, 0, 0, 0, 1491094, 0, 27843), -- -Unknown-
(51053, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1488799, 0, 27843), -- -Unknown-
(48657, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1385129, 0, 27843), -- -Unknown-
(48657, 0, 1, 0, 292725, 152647, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48657, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1385129, 0, 27843), -- -Unknown-
(48656, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1385129, 0, 27843), -- -Unknown-
(48656, 0, 1, 0, 292723, 126984, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48656, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1385129, 0, 27843), -- -Unknown-
(48655, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1362097, 0, 27843), -- -Unknown-
(48655, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1385129, 0, 27843), -- -Unknown-
(48585, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1372288, 0, 27843), -- -Unknown-
(48585, 0, 1, 0, 292585, 152601, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48585, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1375238, 0, 27843), -- -Unknown-
(48532, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1362099, 0, 27843), -- -Unknown-
(48532, 0, 1, 0, 292462, 126610, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48532, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1362099, 0, 27843), -- -Unknown-
(48533, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1362097, 0, 27843), -- -Unknown-
(48533, 0, 1, 0, 292464, 152571, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48533, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1362097, 0, 27843), -- -Unknown-
(48531, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1362097, 0, 27843), -- -Unknown-
(48531, 0, 1, 0, 292456, 152566, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48531, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1362097, 0, 27843), -- -Unknown-
(48530, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1375238, 0, 27843), -- -Unknown-
(48530, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1362099, 0, 27843), -- -Unknown-
(48529, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1375238, 0, 27843), -- -Unknown-
(48529, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1362097, 0, 27843), -- -Unknown-
(51573, 0, 2, 1, 336318, 138147, 1642, 0, 0, 0, 0, 0, 1511959, 0, 27843), -- -Unknown-
(51573, 0, 1, 0, 336317, 138146, 1642, 0, 0, 0, 0, 0, 1375238, 0, 27843), -- -Unknown-
(51573, 0, 0, -1, 0, 0, 1642, 0, 0, 0, 0, 0, 1375238, 0, 27843), -- -Unknown-
(51162, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1492182, 0, 27843), -- -Unknown-
(51162, 0, 1, 0, 334932, 136595, 1642, 864, 0, 0, 0, 0, 1491752, 0, 27843), -- -Unknown-
(51162, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1385844, 0, 27843), -- -Unknown-
(48324, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1385844, 0, 27843), -- -Unknown-
(48324, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1488672, 0, 27843), -- -Unknown-
(50812, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478717, 0, 27843), -- -Unknown-
(50812, 0, 2, 1, 334036, 135349, 1642, 864, 0, 0, 0, 0, 1479419, 0, 27843), -- -Unknown-
(50812, 0, 1, 0, 333883, 135436, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(50812, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1478717, 0, 27843), -- -Unknown-
(51991, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1539106, 0, 27843), -- -Unknown-
(51991, 0, 2, 2, 338000, 139492, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(51991, 0, 1, 0, 337998, 143377, 1642, 864, 0, 0, 0, 0, 1538454, 0, 27843), -- -Unknown-
(51991, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1539106, 0, 27843), -- -Unknown-
(52129, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478716, 0, 27843), -- -Unknown-
(52129, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1539106, 0, 27843), -- -Unknown-
(50775, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478716, 0, 27843), -- -Unknown-
(50775, 0, 1, 0, 333780, 158707, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50775, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1478716, 0, 27843), -- -Unknown-
(50771, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478716, 0, 27843), -- -Unknown-
(50771, 0, 1, 0, 333767, 135080, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50771, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1478716, 0, 27843), -- -Unknown-
(50834, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(50834, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1478716, 0, 27843), -- -Unknown-
(50980, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(50980, 0, 1, 0, 334496, 140050, 1642, 864, 0, 0, 0, 0, 1487843, 0, 27843), -- -Unknown-
(50980, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(50817, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(50817, 0, 1, 0, 333913, 135084, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50817, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(50979, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(50979, 0, 1, 0, 334494, 159675, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50979, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(49662, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1406135, 0, 27843), -- -Unknown-
(49662, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1510401, 0, 27843), -- -Unknown-
(49340, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1406075, 0, 27843), -- -Unknown-
(49340, 0, 1, 0, 333256, 129519, 1642, 864, 0, 0, 0, 0, 1406075, 0, 27843), -- -Unknown-
(49340, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1406135, 0, 27843), -- -Unknown-
(50818, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479876, 0, 27843), -- -Unknown-
(50818, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479881, 0, 27843), -- -Unknown-
(51165, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1492253, 0, 27843), -- -Unknown-
(51165, 0, 1, 0, 334934, 136596, 1642, 864, 0, 0, 0, 0, 1491756, 0, 27843), -- -Unknown-
(51165, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1405006, 0, 27843), -- -Unknown-
(49327, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1401587, 0, 27843), -- -Unknown-
(49327, 0, 3, 2, 294294, 277911, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49327, 0, 2, 1, 294259, 129076, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49327, 0, 1, 0, 294258, 277899, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49327, 0, 0, -1, 0, 0, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(50641, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1401587, 0, 27843), -- -Unknown-
(50641, 0, 1, 0, 333429, 128664, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(50641, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1401587, 0, 27843), -- -Unknown-
(49334, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1406082, 0, 27843), -- -Unknown-
(49334, 0, 1, 0, 294338, 128962, 1642, 864, 0, 0, 0, 0, 1403013, 0, 27843), -- -Unknown-
(49334, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1406075, 0, 27843), -- -Unknown-
(47324, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1391282, 0, 27843), -- -Unknown-
(47324, 0, 2, 1, 333414, 134545, 1642, 864, 0, 0, 0, 0, 1391282, 0, 27843), -- -Unknown-
(47324, 0, 1, 0, 333413, 134544, 1642, 864, 0, 0, 0, 0, 1470318, 0, 27843), -- -Unknown-
(47324, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1406082, 0, 27843), -- -Unknown-
(50794, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1470295, 0, 27843), -- -Unknown-
(50794, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1522638, 0, 27843), -- -Unknown-
(50561, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1466660, 0, 27843), -- -Unknown-
(50561, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1391282, 0, 27843), -- -Unknown-
(48315, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1466990, 0, 27843), -- -Unknown-
(48315, 0, 1, 0, 333102, 157864, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(48315, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1466990, 0, 27843), -- -Unknown-
(50539, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1391282, 0, 27843), -- -Unknown-
(50539, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1466990, 0, 27843), -- -Unknown-
(50770, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1477492, 0, 27843), -- -Unknown-
(50770, 0, 1, 0, 333765, 134532, 1642, 864, 0, 0, 0, 0, 1360411, 0, 27843), -- -Unknown-
(50770, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1391282, 0, 27843), -- -Unknown-
(48313, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1477492, 0, 27843), -- -Unknown-
(48313, 0, 1, 0, 291919, 152393, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48313, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477492, 0, 27843), -- -Unknown-
(48314, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1477492, 0, 27843), -- -Unknown-
(48314, 0, 1, 0, 291925, 152397, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(48314, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477492, 0, 27843); -- -Unknown-

UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=42422 AND `BlobIndex`=0 AND `Idx1`=0); -- The Wardens
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=42422 AND `BlobIndex`=0 AND `Idx1`=0); -- The Wardens

DELETE FROM `quest_poi_points` WHERE (`QuestID`=48327 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48327 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51062 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51062 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51062 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48326 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48326 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48326 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48326 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51061 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51061 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51061 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51061 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51060 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51060 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=51060 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=51060 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51060 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51060 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51060 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51060 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51060 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51059 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51059 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51059 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49138 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=49138 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=49138 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49138 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49138 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49138 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51057 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51057 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=51057 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=51057 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=51057 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=51057 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=51057 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=51057 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51057 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51057 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47499 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=47499 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=47499 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47499 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47499 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47499 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51056 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51056 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51056 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51056 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51055 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=51055 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51055 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51055 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51055 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=7) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=6) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=5) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=4) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=3) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=2) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=1) OR (`QuestID`=47647 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=47647 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=47647 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=47647 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=47647 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=47647 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=47647 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=47647 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=47647 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=47647 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=47647 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=47647 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=47647 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47647 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=47647 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=47647 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=47647 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51054 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51054 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51054 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51053 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51053 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51053 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48657 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48657 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48657 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48657 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48657 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48657 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48657 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48657 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48657 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48656 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48656 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48656 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48655 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48655 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48585 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48585 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48585 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48532 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48532 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48532 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48533 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48533 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48533 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48533 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48533 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48533 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48533 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48533 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48533 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48531 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48531 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48531 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48531 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48531 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48531 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48531 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48531 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48530 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48530 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48529 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48529 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51573 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51573 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51573 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51162 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51162 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51162 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48324 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48324 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50812 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=50812 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50812 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50812 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51991 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51991 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=51991 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=51991 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=51991 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=51991 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51991 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51991 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=52129 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=52129 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50775 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50775 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50775 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50775 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50775 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50775 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50775 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50775 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50775 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50771 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50771 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50771 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50771 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50771 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50771 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50771 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50834 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50834 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50980 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50980 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50980 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50817 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50817 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50817 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50979 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50979 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50979 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49662 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49662 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49340 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49340 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49340 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50818 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50818 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51165 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51165 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51165 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49327 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=49327 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=49327 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=49327 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=49327 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49327 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=49327 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=49327 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=49327 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49327 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=49327 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=49327 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=49327 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49327 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50641 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50641 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50641 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49334 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49334 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49334 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47324 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47324 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47324 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47324 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50794 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50794 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50561 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50561 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48315 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48315 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48315 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50539 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50539 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50770 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50770 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50770 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48313 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48313 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48313 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48314 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48314 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48314 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(48327, 1, 0, 826, 4041, 27843), -- -Unknown-
(48327, 0, 0, 1595, 3723, 27843), -- -Unknown-
(51062, 2, 0, 408, 4629, 27843), -- -Unknown-
(51062, 1, 0, 417, 4627, 27843), -- -Unknown-
(51062, 0, 0, 826, 4041, 27843), -- -Unknown-
(48326, 3, 0, 408, 4629, 27843), -- -Unknown-
(48326, 2, 0, 311, 4735, 27843), -- -Unknown-
(48326, 1, 0, 311, 4735, 27843), -- -Unknown-
(48326, 0, 0, 408, 4629, 27843), -- -Unknown-
(51061, 3, 0, 408, 4629, 27843), -- -Unknown-
(51061, 2, 0, 344, 4659, 27843), -- -Unknown-
(51061, 1, 0, 343, 4660, 27843), -- -Unknown-
(51061, 0, 0, 408, 4629, 27843), -- -Unknown-
(51060, 2, 0, 408, 4629, 27843), -- -Unknown-
(51060, 1, 6, 285, 4721, 27843), -- -Unknown-
(51060, 1, 5, 310, 4733, 27843), -- -Unknown-
(51060, 1, 4, 449, 4726, 27843), -- -Unknown-
(51060, 1, 3, 451, 4721, 27843), -- -Unknown-
(51060, 1, 2, 450, 4673, 27843), -- -Unknown-
(51060, 1, 1, 367, 4594, 27843), -- -Unknown-
(51060, 1, 0, 302, 4582, 27843), -- -Unknown-
(51060, 0, 0, 408, 4629, 27843), -- -Unknown-
(51059, 2, 0, 624, 4422, 27843), -- -Unknown-
(51059, 1, 0, 620, 4425, 27843), -- -Unknown-
(51059, 0, 0, 408, 4629, 27843), -- -Unknown-
(49138, 5, 0, 686, 4302, 27843), -- -Unknown-
(49138, 4, 0, 738, 4527, 27843), -- -Unknown-
(49138, 3, 0, 736, 4525, 27843), -- -Unknown-
(49138, 2, 0, 863, 4338, 27843), -- -Unknown-
(49138, 1, 0, 626, 4299, 27843), -- -Unknown-
(49138, 0, 0, 736, 4525, 27843), -- -Unknown-
(51057, 3, 0, 559, 4284, 27843), -- -Unknown-
(51057, 2, 6, 572, 4330, 27843), -- -Unknown-
(51057, 2, 5, 586, 4385, 27843), -- -Unknown-
(51057, 2, 4, 686, 4520, 27843), -- -Unknown-
(51057, 2, 3, 751, 4540, 27843), -- -Unknown-
(51057, 2, 2, 765, 4421, 27843), -- -Unknown-
(51057, 2, 1, 636, 4271, 27843), -- -Unknown-
(51057, 2, 0, 605, 4266, 27843), -- -Unknown-
(51057, 1, 0, 559, 4284, 27843), -- -Unknown-
(51057, 0, 0, 624, 4422, 27843), -- -Unknown-
(47499, 5, 0, 559, 4284, 27843), -- -Unknown-
(47499, 4, 11, 750, 4440, 27843), -- -Unknown-
(47499, 4, 10, 731, 4459, 27843), -- -Unknown-
(47499, 4, 9, 722, 4469, 27843), -- -Unknown-
(47499, 4, 8, 722, 4483, 27843), -- -Unknown-
(47499, 4, 7, 722, 4502, 27843), -- -Unknown-
(47499, 4, 6, 731, 4507, 27843), -- -Unknown-
(47499, 4, 5, 750, 4507, 27843), -- -Unknown-
(47499, 4, 4, 793, 4459, 27843), -- -Unknown-
(47499, 4, 3, 826, 4421, 27843), -- -Unknown-
(47499, 4, 2, 819, 4399, 27843), -- -Unknown-
(47499, 4, 1, 797, 4397, 27843), -- -Unknown-
(47499, 4, 0, 765, 4426, 27843), -- -Unknown-
(47499, 3, 0, 814, 4349, 27843), -- -Unknown-
(47499, 2, 0, 647, 4382, 27843), -- -Unknown-
(47499, 1, 0, 624, 4422, 27843), -- -Unknown-
(47499, 0, 0, 559, 4284, 27843), -- -Unknown-
(51056, 3, 0, 559, 4284, 27843), -- -Unknown-
(51056, 2, 0, 917, 4248, 27843), -- -Unknown-
(51056, 1, 0, 795, 4233, 27843), -- -Unknown-
(51056, 0, 0, 559, 4284, 27843), -- -Unknown-
(51055, 4, 0, 559, 4284, 27843), -- -Unknown-
(51055, 3, 0, 834, 4330, 27843), -- -Unknown-
(51055, 2, 0, 797, 4295, 27843), -- -Unknown-
(51055, 1, 0, 792, 4174, 27843), -- -Unknown-
(51055, 0, 0, 559, 4284, 27843), -- -Unknown-
(47647, 7, 0, 777, 4280, 27843), -- -Unknown-
(47647, 6, 7, 701, 4165, 27843), -- -Unknown-
(47647, 6, 6, 690, 4175, 27843), -- -Unknown-
(47647, 6, 5, 643, 4340, 27843), -- -Unknown-
(47647, 6, 4, 672, 4348, 27843), -- -Unknown-
(47647, 6, 3, 778, 4362, 27843), -- -Unknown-
(47647, 6, 2, 886, 4302, 27843), -- -Unknown-
(47647, 6, 1, 864, 4254, 27843), -- -Unknown-
(47647, 6, 0, 788, 4159, 27843), -- -Unknown-
(47647, 5, 7, 708, 4160, 27843), -- -Unknown-
(47647, 5, 6, 704, 4163, 27843), -- -Unknown-
(47647, 5, 5, 696, 4169, 27843), -- -Unknown-
(47647, 5, 4, 725, 4219, 27843), -- -Unknown-
(47647, 5, 3, 772, 4227, 27843), -- -Unknown-
(47647, 5, 2, 776, 4221, 27843), -- -Unknown-
(47647, 5, 1, 790, 4160, 27843), -- -Unknown-
(47647, 5, 0, 785, 4157, 27843), -- -Unknown-
(47647, 4, 2, 830, 4327, 27843), -- -Unknown-
(47647, 4, 1, 884, 4303, 27843), -- -Unknown-
(47647, 4, 0, 856, 4251, 27843), -- -Unknown-
(47647, 3, 5, 642, 4343, 27843), -- -Unknown-
(47647, 3, 4, 628, 4384, 27843), -- -Unknown-
(47647, 3, 3, 777, 4405, 27843), -- -Unknown-
(47647, 3, 2, 799, 4381, 27843), -- -Unknown-
(47647, 3, 1, 734, 4303, 27843), -- -Unknown-
(47647, 3, 0, 708, 4291, 27843), -- -Unknown-
(47647, 2, 3, 832, 4241, 27843), -- -Unknown-
(47647, 2, 2, 854, 4244, 27843), -- -Unknown-
(47647, 2, 1, 864, 4240, 27843), -- -Unknown-
(47647, 2, 0, 843, 4239, 27843), -- -Unknown-
(47647, 1, 11, 579, 4183, 27843), -- -Unknown-
(47647, 1, 10, 558, 4303, 27843), -- -Unknown-
(47647, 1, 9, 536, 4480, 27843), -- -Unknown-
(47647, 1, 8, 553, 4506, 27843), -- -Unknown-
(47647, 1, 7, 700, 4585, 27843), -- -Unknown-
(47647, 1, 6, 777, 4536, 27843), -- -Unknown-
(47647, 1, 5, 867, 4428, 27843), -- -Unknown-
(47647, 1, 4, 956, 4234, 27843), -- -Unknown-
(47647, 1, 3, 951, 4174, 27843), -- -Unknown-
(47647, 1, 2, 918, 4130, 27843), -- -Unknown-
(47647, 1, 1, 824, 4105, 27843), -- -Unknown-
(47647, 1, 0, 736, 4097, 27843), -- -Unknown-
(47647, 0, 3, 814, 4349, 27843), -- -Unknown-
(47647, 0, 2, 738, 4527, 27843), -- -Unknown-
(47647, 0, 1, 813, 4422, 27843), -- -Unknown-
(47647, 0, 0, 837, 4325, 27843), -- -Unknown-
(51054, 2, 0, 531, 4275, 27843), -- -Unknown-
(51054, 1, 0, 531, 4275, 27843), -- -Unknown-
(51054, 0, 0, 559, 4284, 27843), -- -Unknown-
(51053, 2, 0, 531, 4275, 27843), -- -Unknown-
(51053, 1, 0, 456, 4365, 27843), -- -Unknown-
(51053, 0, 0, 531, 4275, 27843), -- -Unknown-
(48657, 2, 0, 766, 3733, 27843), -- -Unknown-
(48657, 1, 6, 623, 3657, 27843), -- -Unknown-
(48657, 1, 5, 610, 3806, 27843), -- -Unknown-
(48657, 1, 4, 613, 3829, 27843), -- -Unknown-
(48657, 1, 3, 614, 3829, 27843), -- -Unknown-
(48657, 1, 2, 706, 3655, 27843), -- -Unknown-
(48657, 1, 1, 665, 3639, 27843), -- -Unknown-
(48657, 1, 0, 664, 3639, 27843), -- -Unknown-
(48657, 0, 0, 766, 3733, 27843), -- -Unknown-
(48656, 2, 0, 766, 3733, 27843), -- -Unknown-
(48656, 1, 7, 627, 3683, 27843), -- -Unknown-
(48656, 1, 6, 573, 3843, 27843), -- -Unknown-
(48656, 1, 5, 630, 3868, 27843), -- -Unknown-
(48656, 1, 4, 700, 3823, 27843), -- -Unknown-
(48656, 1, 3, 758, 3754, 27843), -- -Unknown-
(48656, 1, 2, 764, 3731, 27843), -- -Unknown-
(48656, 1, 1, 695, 3655, 27843), -- -Unknown-
(48656, 1, 0, 656, 3653, 27843), -- -Unknown-
(48656, 0, 0, 766, 3733, 27843), -- -Unknown-
(48655, 1, 0, 858, 3723, 27843), -- -Unknown-
(48655, 0, 0, 766, 3733, 27843), -- -Unknown-
(48585, 2, 0, 993, 3935, 27843), -- -Unknown-
(48585, 1, 7, 936, 3942, 27843), -- -Unknown-
(48585, 1, 6, 922, 4032, 27843), -- -Unknown-
(48585, 1, 5, 949, 4103, 27843), -- -Unknown-
(48585, 1, 4, 1003, 4147, 27843), -- -Unknown-
(48585, 1, 3, 1126, 4119, 27843), -- -Unknown-
(48585, 1, 2, 1175, 4059, 27843), -- -Unknown-
(48585, 1, 1, 1150, 3900, 27843), -- -Unknown-
(48585, 1, 0, 1120, 3805, 27843), -- -Unknown-
(48585, 0, 0, 911, 3732, 27843), -- -Unknown-
(48532, 2, 0, 877, 3820, 27843), -- -Unknown-
(48532, 1, 7, 968, 3921, 27843), -- -Unknown-
(48532, 1, 6, 883, 3934, 27843), -- -Unknown-
(48532, 1, 5, 1007, 4104, 27843), -- -Unknown-
(48532, 1, 4, 1115, 4124, 27843), -- -Unknown-
(48532, 1, 3, 1308, 4133, 27843), -- -Unknown-
(48532, 1, 2, 1299, 4039, 27843), -- -Unknown-
(48532, 1, 1, 1272, 3903, 27843), -- -Unknown-
(48532, 1, 0, 1204, 3892, 27843), -- -Unknown-
(48532, 0, 0, 877, 3820, 27843), -- -Unknown-
(48533, 2, 0, 858, 3724, 27843), -- -Unknown-
(48533, 1, 6, 898, 3664, 27843), -- -Unknown-
(48533, 1, 5, 897, 3802, 27843), -- -Unknown-
(48533, 1, 4, 961, 3813, 27843), -- -Unknown-
(48533, 1, 3, 1016, 3806, 27843), -- -Unknown-
(48533, 1, 2, 1031, 3804, 27843), -- -Unknown-
(48533, 1, 1, 1057, 3795, 27843), -- -Unknown-
(48533, 1, 0, 1065, 3660, 27843), -- -Unknown-
(48533, 0, 0, 858, 3724, 27843), -- -Unknown-
(48531, 2, 0, 850, 3712, 27843), -- -Unknown-
(48531, 1, 5, 864, 3882, 27843), -- -Unknown-
(48531, 1, 4, 903, 4013, 27843), -- -Unknown-
(48531, 1, 3, 1048, 4149, 27843), -- -Unknown-
(48531, 1, 2, 1178, 4133, 27843), -- -Unknown-
(48531, 1, 1, 1246, 4094, 27843), -- -Unknown-
(48531, 1, 0, 1179, 3805, 27843), -- -Unknown-
(48531, 0, 0, 850, 3712, 27843), -- -Unknown-
(48530, 1, 0, 911, 3732, 27843), -- -Unknown-
(48530, 0, 0, 877, 3820, 27843), -- -Unknown-
(48529, 1, 0, 910, 3732, 27843), -- -Unknown-
(48529, 0, 0, 858, 3724, 27843), -- -Unknown-
(51573, 2, 0, 982, 3735, 27843), -- -Unknown-
(51573, 1, 0, 911, 3732, 27843), -- -Unknown-
(51573, 0, 0, 911, 3732, 27843), -- -Unknown-
(51162, 2, 0, 842, 4042, 27843), -- -Unknown-
(51162, 1, 0, 1123, 4271, 27843), -- -Unknown-
(51162, 0, 0, 826, 4041, 27843), -- -Unknown-
(48324, 1, 0, 828, 4039, 27843), -- -Unknown-
(48324, 0, 0, 537, 4282, 27843), -- -Unknown-
(50812, 3, 0, 931, 4966, 27843), -- -Unknown-
(50812, 2, 0, 1392, 4932, 27843), -- -Unknown-
(50812, 1, 11, 1324, 4873, 27843), -- -Unknown-
(50812, 1, 10, 1318, 4901, 27843), -- -Unknown-
(50812, 1, 9, 1318, 4919, 27843), -- -Unknown-
(50812, 1, 8, 1318, 4955, 27843), -- -Unknown-
(50812, 1, 7, 1333, 4978, 27843), -- -Unknown-
(50812, 1, 6, 1370, 4992, 27843), -- -Unknown-
(50812, 1, 5, 1406, 4973, 27843), -- -Unknown-
(50812, 1, 4, 1420, 4951, 27843), -- -Unknown-
(50812, 1, 3, 1434, 4923, 27843), -- -Unknown-
(50812, 1, 2, 1438, 4905, 27843), -- -Unknown-
(50812, 1, 1, 1429, 4882, 27843), -- -Unknown-
(50812, 1, 0, 1397, 4855, 27843), -- -Unknown-
(50812, 0, 0, 931, 4966, 27843), -- -Unknown-
(51991, 3, 0, 1217, 4756, 27843), -- -Unknown-
(51991, 2, 4, 1168, 4678, 27843), -- -Unknown-
(51991, 2, 3, 1269, 4737, 27843), -- -Unknown-
(51991, 2, 2, 1351, 4669, 27843), -- -Unknown-
(51991, 2, 1, 1371, 4630, 27843), -- -Unknown-
(51991, 2, 0, 1218, 4607, 27843), -- -Unknown-
(51991, 1, 0, 1217, 4737, 27843), -- -Unknown-
(51991, 0, 0, 1217, 4756, 27843), -- -Unknown-
(52129, 1, 0, 993, 4905, 27843), -- -Unknown-
(52129, 0, 0, 1217, 4756, 27843), -- -Unknown-
(50775, 2, 0, 993, 4905, 27843), -- -Unknown-
(50775, 1, 6, 906, 4769, 27843), -- -Unknown-
(50775, 1, 5, 1049, 4954, 27843), -- -Unknown-
(50775, 1, 4, 1301, 5024, 27843), -- -Unknown-
(50775, 1, 3, 1358, 5031, 27843), -- -Unknown-
(50775, 1, 2, 1386, 5018, 27843), -- -Unknown-
(50775, 1, 1, 1503, 4944, 27843), -- -Unknown-
(50775, 1, 0, 1418, 4656, 27843), -- -Unknown-
(50775, 0, 0, 993, 4905, 27843), -- -Unknown-
(50771, 2, 0, 993, 4905, 27843), -- -Unknown-
(50771, 1, 4, 1153, 4974, 27843), -- -Unknown-
(50771, 1, 3, 1331, 5038, 27843), -- -Unknown-
(50771, 1, 2, 1342, 4914, 27843), -- -Unknown-
(50771, 1, 1, 1316, 4810, 27843), -- -Unknown-
(50771, 1, 0, 944, 4798, 27843), -- -Unknown-
(50771, 0, 0, 993, 4905, 27843), -- -Unknown-
(50834, 1, 0, 1642, 4679, 27843), -- -Unknown-
(50834, 0, 0, 993, 4905, 27843), -- -Unknown-
(50980, 2, 0, 1642, 4679, 27843), -- -Unknown-
(50980, 1, 0, 1558, 4788, 27843), -- -Unknown-
(50980, 0, 0, 1642, 4679, 27843), -- -Unknown-
(50817, 2, 0, 1642, 4679, 27843), -- -Unknown-
(50817, 1, 10, 1559, 4528, 27843), -- -Unknown-
(50817, 1, 9, 1412, 4646, 27843), -- -Unknown-
(50817, 1, 8, 1418, 4713, 27843), -- -Unknown-
(50817, 1, 7, 1437, 4824, 27843), -- -Unknown-
(50817, 1, 6, 1455, 4859, 27843), -- -Unknown-
(50817, 1, 5, 1462, 4865, 27843), -- -Unknown-
(50817, 1, 4, 1549, 4900, 27843), -- -Unknown-
(50817, 1, 3, 1623, 4902, 27843), -- -Unknown-
(50817, 1, 2, 1639, 4847, 27843), -- -Unknown-
(50817, 1, 1, 1608, 4649, 27843), -- -Unknown-
(50817, 1, 0, 1566, 4526, 27843), -- -Unknown-
(50817, 0, 0, 1642, 4679, 27843), -- -Unknown-
(50979, 2, 0, 1642, 4679, 27843), -- -Unknown-
(50979, 1, 11, 1450, 4671, 27843); -- -Unknown-

INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(50979, 1, 10, 1426, 4726, 27843), -- -Unknown-
(50979, 1, 9, 1420, 4781, 27843), -- -Unknown-
(50979, 1, 8, 1422, 4785, 27843), -- -Unknown-
(50979, 1, 7, 1478, 4857, 27843), -- -Unknown-
(50979, 1, 6, 1511, 4882, 27843), -- -Unknown-
(50979, 1, 5, 1590, 4899, 27843), -- -Unknown-
(50979, 1, 4, 1632, 4891, 27843), -- -Unknown-
(50979, 1, 3, 1637, 4889, 27843), -- -Unknown-
(50979, 1, 2, 1723, 4709, 27843), -- -Unknown-
(50979, 1, 1, 1636, 4558, 27843), -- -Unknown-
(50979, 1, 0, 1569, 4535, 27843), -- -Unknown-
(50979, 0, 0, 1642, 4679, 27843), -- -Unknown-
(49662, 1, 0, 1950, 4842, 27843), -- -Unknown-
(49662, 0, 0, 2715, 3766, 27843), -- -Unknown-
(49340, 2, 0, 1950, 4808, 27843), -- -Unknown-
(49340, 1, 0, 1950, 4808, 27843), -- -Unknown-
(49340, 0, 0, 1950, 4842, 27843), -- -Unknown-
(50818, 1, 0, 1396, 4613, 27843), -- -Unknown-
(50818, 0, 0, 1642, 4679, 27843), -- -Unknown-
(51165, 2, 0, 1917, 4825, 27843), -- -Unknown-
(51165, 1, 0, 2242, 3803, 27843), -- -Unknown-
(51165, 0, 0, 1920, 4806, 27843), -- -Unknown-
(49327, 4, 0, 1890, 4836, 27843), -- -Unknown-
(49327, 3, 3, 1842, 4711, 27843), -- -Unknown-
(49327, 3, 2, 2001, 4725, 27843), -- -Unknown-
(49327, 3, 1, 2065, 4722, 27843), -- -Unknown-
(49327, 3, 0, 1841, 4622, 27843), -- -Unknown-
(49327, 2, 3, 1890, 4679, 27843), -- -Unknown-
(49327, 2, 2, 2007, 4677, 27843), -- -Unknown-
(49327, 2, 1, 1997, 4668, 27843), -- -Unknown-
(49327, 2, 0, 1860, 4602, 27843), -- -Unknown-
(49327, 1, 3, 1884, 4687, 27843), -- -Unknown-
(49327, 1, 2, 2012, 4687, 27843), -- -Unknown-
(49327, 1, 1, 1971, 4663, 27843), -- -Unknown-
(49327, 1, 0, 1862, 4640, 27843), -- -Unknown-
(49327, 0, 0, 1872, 4868, 27843), -- -Unknown-
(50641, 2, 0, 1891, 4836, 27843), -- -Unknown-
(50641, 1, 11, 1839, 4572, 27843), -- -Unknown-
(50641, 1, 10, 1815, 4617, 27843), -- -Unknown-
(50641, 1, 9, 1815, 4693, 27843), -- -Unknown-
(50641, 1, 8, 1833, 4739, 27843), -- -Unknown-
(50641, 1, 7, 1880, 4769, 27843), -- -Unknown-
(50641, 1, 6, 1941, 4774, 27843), -- -Unknown-
(50641, 1, 5, 2011, 4759, 27843), -- -Unknown-
(50641, 1, 4, 2068, 4729, 27843), -- -Unknown-
(50641, 1, 3, 2078, 4663, 27843), -- -Unknown-
(50641, 1, 2, 2047, 4607, 27843), -- -Unknown-
(50641, 1, 1, 1986, 4572, 27843), -- -Unknown-
(50641, 1, 0, 1901, 4557, 27843), -- -Unknown-
(50641, 0, 0, 1890, 4836, 27843), -- -Unknown-
(49334, 2, 0, 1888, 4835, 27843), -- -Unknown-
(49334, 1, 0, 1975, 4644, 27843), -- -Unknown-
(49334, 0, 0, 1950, 4808, 27843), -- -Unknown-
(47324, 3, 0, 898, 3483, 27843), -- -Unknown-
(47324, 2, 0, 884, 3483, 27843), -- -Unknown-
(47324, 1, 0, 911, 3501, 27843), -- -Unknown-
(47324, 0, 0, 1888, 4835, 27843), -- -Unknown-
(50794, 1, 0, 901, 3483, 27843), -- -Unknown-
(50794, 0, 0, 915, 3733, 27843), -- -Unknown-
(50561, 1, 0, 965, 3358, 27843), -- -Unknown-
(50561, 0, 0, 898, 3483, 27843), -- -Unknown-
(48315, 2, 0, 950, 3358, 27843), -- -Unknown-
(48315, 1, 11, 1003, 3209, 27843), -- -Unknown-
(48315, 1, 10, 979, 3259, 27843), -- -Unknown-
(48315, 1, 9, 974, 3295, 27843), -- -Unknown-
(48315, 1, 8, 999, 3331, 27843), -- -Unknown-
(48315, 1, 7, 1040, 3326, 27843), -- -Unknown-
(48315, 1, 6, 1070, 3300, 27843), -- -Unknown-
(48315, 1, 5, 1090, 3265, 27843), -- -Unknown-
(48315, 1, 4, 1100, 3234, 27843), -- -Unknown-
(48315, 1, 3, 1100, 3203, 27843), -- -Unknown-
(48315, 1, 2, 1095, 3179, 27843), -- -Unknown-
(48315, 1, 1, 1075, 3169, 27843), -- -Unknown-
(48315, 1, 0, 1040, 3169, 27843), -- -Unknown-
(48315, 0, 0, 950, 3358, 27843), -- -Unknown-
(50539, 1, 0, 898, 3483, 27843), -- -Unknown-
(50539, 0, 0, 952, 3358, 27843), -- -Unknown-
(50770, 2, 0, 904, 3483, 27843), -- -Unknown-
(50770, 1, 0, 898, 3483, 27843), -- -Unknown-
(50770, 0, 0, 898, 3483, 27843), -- -Unknown-
(48313, 2, 0, 904, 3483, 27843), -- -Unknown-
(48313, 1, 9, 875, 3538, 27843), -- -Unknown-
(48313, 1, 8, 843, 3582, 27843), -- -Unknown-
(48313, 1, 7, 888, 3632, 27843), -- -Unknown-
(48313, 1, 6, 977, 3612, 27843), -- -Unknown-
(48313, 1, 5, 1016, 3607, 27843), -- -Unknown-
(48313, 1, 4, 1087, 3605, 27843), -- -Unknown-
(48313, 1, 3, 1153, 3531, 27843), -- -Unknown-
(48313, 1, 2, 1162, 3517, 27843), -- -Unknown-
(48313, 1, 1, 1184, 3440, 27843), -- -Unknown-
(48313, 1, 0, 1105, 3412, 27843), -- -Unknown-
(48313, 0, 0, 904, 3483, 27843), -- -Unknown-
(48314, 2, 0, 910, 3470, 27843), -- -Unknown-
(48314, 1, 11, 1252, 3260, 27843), -- -Unknown-
(48314, 1, 10, 1109, 3254, 27843), -- -Unknown-
(48314, 1, 9, 1088, 3488, 27843), -- -Unknown-
(48314, 1, 8, 888, 3513, 27843), -- -Unknown-
(48314, 1, 7, 847, 3544, 27843), -- -Unknown-
(48314, 1, 6, 832, 3594, 27843), -- -Unknown-
(48314, 1, 5, 862, 3639, 27843), -- -Unknown-
(48314, 1, 4, 1070, 3635, 27843), -- -Unknown-
(48314, 1, 3, 1196, 3619, 27843), -- -Unknown-
(48314, 1, 2, 1242, 3579, 27843), -- -Unknown-
(48314, 1, 1, 1242, 3518, 27843), -- -Unknown-
(48314, 1, 0, 1221, 3435, 27843), -- -Unknown-
(48314, 0, 0, 904, 3483, 27843); -- -Unknown-

DELETE FROM `quest_greeting` WHERE (`ID`=126576 AND `Type`=0) OR (`ID`=135179 AND `Type`=0) OR (`ID`=128696 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(126576, 0, 1, 0, '', 27843), -- 126576
(135179, 0, 1, 0, 'How you doin\'? Seems you have good timing today.', 27843), -- 135179
(128696, 0, 1, 0, 'The temple is our last refuge.', 27843); -- 128696


DELETE FROM `quest_details` WHERE `ID` IN (48327 /*-Unknown-*/, 51062 /*-Unknown-*/, 48326 /*-Unknown-*/, 51061 /*-Unknown-*/, 51060 /*-Unknown-*/, 51059 /*-Unknown-*/, 49138 /*-Unknown-*/, 51057 /*-Unknown-*/, 47499 /*-Unknown-*/, 51056 /*-Unknown-*/, 51055 /*-Unknown-*/, 51054 /*-Unknown-*/, 51053 /*-Unknown-*/, 48657 /*-Unknown-*/, 48656 /*-Unknown-*/, 48655 /*-Unknown-*/, 48585 /*-Unknown-*/, 48532 /*-Unknown-*/, 48533 /*-Unknown-*/, 48531 /*-Unknown-*/, 48530 /*-Unknown-*/, 48529 /*-Unknown-*/, 51573 /*-Unknown-*/, 51162 /*-Unknown-*/, 48324 /*-Unknown-*/, 50812 /*-Unknown-*/, 51991 /*-Unknown-*/, 52129 /*-Unknown-*/, 50775 /*-Unknown-*/, 50771 /*-Unknown-*/, 50834 /*-Unknown-*/, 50980 /*-Unknown-*/, 50817 /*-Unknown-*/, 50979 /*-Unknown-*/, 49662 /*-Unknown-*/, 49340 /*-Unknown-*/, 50818 /*-Unknown-*/, 51165 /*-Unknown-*/, 49327 /*-Unknown-*/, 50641 /*-Unknown-*/, 49334 /*-Unknown-*/, 47324 /*-Unknown-*/, 50794 /*-Unknown-*/, 50561 /*-Unknown-*/, 48315 /*-Unknown-*/, 50539 /*-Unknown-*/, 50770 /*-Unknown-*/, 48313 /*-Unknown-*/, 48314 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48327, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51062, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48326, 1, 1, 0, 0, 0, 2000, 0, 0, 27843), -- -Unknown-
(51061, 669, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51060, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51059, 669, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49138, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51057, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47499, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51056, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51055, 1, 25, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(51054, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51053, 1, 1, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(48657, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48656, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48655, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48585, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48532, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48533, 6, 1, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(48531, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48530, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48529, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51573, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51162, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48324, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50812, 1, 25, 0, 0, 0, 20, 0, 0, 27843), -- -Unknown-
(51991, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(52129, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50775, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50771, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50834, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50980, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50817, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50979, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49662, 669, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49340, 1, 6, 0, 0, 0, 2000, 0, 0, 27843), -- -Unknown-
(50818, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51165, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49327, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50641, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49334, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47324, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50794, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50561, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48315, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50539, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50770, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48313, 1, 6, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(48314, 1, 0, 0, 0, 0, 0, 0, 0, 27843); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (51060 /*-Unknown-*/, 49138 /*-Unknown-*/, 47499 /*-Unknown-*/, 48657 /*-Unknown-*/, 48533 /*-Unknown-*/, 48531 /*-Unknown-*/, 48585 /*-Unknown-*/, 50775 /*-Unknown-*/, 51991 /*-Unknown-*/, 50979 /*-Unknown-*/, 50561 /*-Unknown-*/, 48315 /*-Unknown-*/, 48313 /*-Unknown-*/, 48314 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(51060, 1, 0, 0, 0, 'More treasure!', 27843), -- -Unknown-
(49138, 1, 0, 0, 0, '<It\'s firmly locked. You\'ll need the captain\'s key to open this.>', 27843), -- -Unknown-
(47499, 1, 0, 0, 0, 'I\'d hoped I\'d never have to see those idols again.', 27843), -- -Unknown-
(48657, 6, 0, 0, 0, 'Do you have de saurolisk eggs?', 27843), -- -Unknown-
(48533, 6, 0, 0, 0, 'Do you have de buzzard meat?', 27843), -- -Unknown-
(48531, 6, 0, 0, 0, 'Do you have de \"mystery ingredient\" for de mystery meat pie?', 27843), -- -Unknown-
(48585, 6, 0, 0, 0, 'What do you have for me?', 27843), -- -Unknown-
(50775, 0, 0, 0, 0, 'Ya get us the dirt yet?', 27843), -- -Unknown-
(51991, 1, 0, 0, 0, 'All juiced up?', 27843), -- -Unknown-
(50979, 0, 0, 0, 0, 'How goes the juicing?', 27843), -- -Unknown-
(50561, 6, 0, 0, 0, 'What have you found?', 27843), -- -Unknown-
(48315, 0, 0, 0, 0, '<Carved into the ancient statue are two eye sockets that look like they once held gems.>', 27843), -- -Unknown-
(48313, 6, 0, 0, 0, 'Do you have the prickly plum for the salve?', 27843), -- -Unknown-
(48314, 6, 0, 0, 0, 'Do you have the scorpashi stingers?', 27843); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`ID`=274224 AND `EffectIndex`=1) OR (`ID`=274187 AND `EffectIndex`=0) OR (`ID`=274238 AND `EffectIndex`=0) OR (`ID`=280463 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(274224, 1, 1642, 1220.91, 4746.58, 72.45, 27843), -- Spell: Ranishu Exit Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(274187, 0, 1642, 1258.05, 4672.46, 84.53, 27843), -- Spell: Back to Start Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(274238, 0, 1642, 1222.76, 4739.57, 75.45, 27843), -- Spell: Ride the Ranishu Efffect: 28 (SPELL_EFFECT_SUMMON)
(280463, 0, 1642, 1950.1, 4850.02, 101.76, 27843); -- Spell: Teleport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (130999, 136778, 127025, 128633, 128646, 128640, 128641, 128642, 128643, 128644, 128645, 136951, 136472, 136487, 136466, 136954, 130997, 128843, 128300, 136785, 136781, 136783, 136779, 135449, 128557, 128497, 128840, 136689, 128845, 128299, 128793, 128827, 128749, 128791, 128800, 136673, 136446, 136680, 128859, 128833, 128839, 128826, 128588, 128828, 128825, 128834, 128831, 128829, 136773, 128878, 136310, 136780, 136782, 136784, 136774, 123481, 128794, 128346, 128853, 128851, 128748, 128548, 128572, 128573, 128569, 128570, 128571, 128575, 136629, 128823, 128830, 136679, 125299, 128822, 136678, 128802, 128857, 128824, 128856, 128860, 128858, 136622, 128862, 128454, 128855, 136441, 128747, 128758, 128744, 136621, 128745, 128871, 136434, 136435, 128846, 128861, 128847, 128789, 128869, 128841, 128743, 128741, 128738, 128739, 128732, 128736, 128765, 128733, 128297, 128854, 128820, 136691, 136693, 128469, 128755, 128757, 128766, 128368, 128844, 136309, 136583, 136543, 128525, 128527, 128520, 128516, 128517, 128518, 128519, 128515, 128528, 128530, 128750, 128832, 128523, 128522, 136695, 128835, 128788, 123489, 130996, 129283, 136287, 128261, 125082, 128724, 128723, 128762, 128786, 144462, 141780, 128787, 124567, 135483, 126643, 127776, 136354, 124591, 136595, 142648, 138124, 138126, 138127, 126108, 126984, 138910, 135655, 136389, 125862, 127578, 126085, 138395, 135326, 135333, 135338, 135339, 135311, 128763, 128764, 128760, 128237, 131378, 123811, 125904, 127053, 128716, 128711, 128753, 128717, 128714, 128253, 128715, 128251, 128252, 128866, 128868, 128453, 128850, 128351, 128864, 128865, 128873, 128872, 128801, 125310, 128870, 128348, 124560, 128796, 128564, 128197, 128565, 124811, 128795, 122790, 128404, 139773, 142895, 139775, 139492, 135349, 136338, 139772, 140046, 139982, 139989, 139569, 139929, 140567, 140888, 140530, 144610, 144611, 135179, 135180, 135269, 144245, 135286, 139114, 140051, 140050, 136225, 141755, 135006, 143213, 143212, 141720, 135084, 139071, 128694, 134595, 129519, 129518, 130023, 130022, 128660, 128664, 128661, 134638, 128961, 128662, 129076, 129202, 144353, 139827, 128695, 129224, 124832, 128687, 128697, 128693, 129011, 128688, 128696, 134613, 129216, 129521, 129014, 128692, 128689, 142313, 125098, 143454, 135400, 124716, 124522, 124718, 136144, 136109, 129004, 130042, 134321, 134320, 128665, 139072, 129008, 129007, 136548, 136545, 141597, 136546, 137556, 123473, 133888, 126627, 126645, 126576, 135654, 134292, 134121, 134090, 134067, 136340, 134533, 126712, 137332, 124810, 134164, 134245, 134314, 134148, 139082, 139083);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(130999, 110, 120, 0, 0, 27843),
(136778, 110, 120, 0, 0, 27843),
(127025, 110, 120, 0, 0, 27843),
(128633, 110, 120, 0, 0, 27843),
(128646, 110, 120, 0, 0, 27843),
(128640, 110, 120, 0, 0, 27843),
(128641, 110, 120, 0, 0, 27843),
(128642, 110, 120, 0, 0, 27843),
(128643, 110, 120, 0, 0, 27843),
(128644, 110, 120, 0, 0, 27843),
(128645, 110, 120, 0, 0, 27843),
(136951, 110, 120, 0, 0, 27843),
(136472, 110, 120, 0, 0, 27843),
(136487, 110, 120, 0, 0, 27843),
(136466, 110, 120, 0, 0, 27843),
(136954, 110, 120, 0, 0, 27843),
(130997, 110, 120, 0, 0, 27843),
(128843, 110, 120, 0, 0, 27843),
(128300, 110, 120, 0, 0, 27843),
(136785, 110, 120, 0, 0, 27843),
(136781, 110, 120, 0, 0, 27843),
(136783, 110, 120, 0, 0, 27843),
(136779, 110, 120, 0, 0, 27843),
(135449, 110, 120, 0, 0, 27843),
(128557, 110, 120, 0, 0, 27843),
(128497, 110, 120, 0, 0, 27843),
(128840, 110, 120, 0, 0, 27843),
(136689, 110, 120, 0, 0, 27843),
(128845, 110, 120, 0, 0, 27843),
(128299, 110, 120, 0, 0, 27843),
(128793, 110, 120, 0, 0, 27843),
(128827, 110, 120, 0, 0, 27843),
(128749, 110, 120, 0, 0, 27843),
(128791, 110, 120, 0, 0, 27843),
(128800, 110, 120, 0, 0, 27843),
(136673, 110, 120, 0, 0, 27843),
(136446, 110, 120, 0, 0, 27843),
(136680, 110, 120, 0, 0, 27843),
(128859, 110, 120, 0, 0, 27843),
(128833, 110, 120, 0, 0, 27843),
(128839, 110, 120, 0, 0, 27843),
(128826, 110, 120, 0, 0, 27843),
(128588, 110, 120, 0, 0, 27843),
(128828, 110, 120, 0, 0, 27843),
(128825, 110, 120, 0, 0, 27843),
(128834, 110, 120, 0, 0, 27843),
(128831, 110, 120, 0, 0, 27843),
(128829, 110, 120, 0, 0, 27843),
(136773, 110, 120, 0, 0, 27843),
(128878, 110, 120, 0, 0, 27843),
(136310, 110, 120, 0, 0, 27843),
(136780, 110, 120, 0, 0, 27843),
(136782, 110, 120, 0, 0, 27843),
(136784, 110, 120, 0, 0, 27843),
(136774, 110, 120, 0, 0, 27843),
(123481, 110, 120, 0, 0, 27843),
(128794, 110, 120, 0, 0, 27843),
(128346, 110, 120, 0, 0, 27843),
(128853, 110, 120, 0, 0, 27843),
(128851, 110, 120, 0, 0, 27843),
(128748, 110, 120, 0, 0, 27843),
(128548, 110, 120, 0, 0, 27843),
(128572, 110, 120, 0, 0, 27843),
(128573, 110, 120, 0, 0, 27843),
(128569, 110, 120, 0, 0, 27843),
(128570, 110, 120, 0, 0, 27843),
(128571, 110, 120, 0, 0, 27843),
(128575, 110, 120, 0, 0, 27843),
(136629, 110, 120, 0, 0, 27843),
(128823, 110, 120, 0, 0, 27843),
(128830, 110, 120, 0, 0, 27843),
(136679, 110, 120, 0, 0, 27843),
(125299, 110, 120, 0, 0, 27843),
(128822, 110, 120, 0, 0, 27843),
(136678, 110, 120, 0, 0, 27843),
(128802, 110, 120, 0, 0, 27843),
(128857, 110, 120, 0, 0, 27843),
(128824, 110, 120, 0, 0, 27843),
(128856, 110, 120, 0, 0, 27843),
(128860, 110, 120, 0, 0, 27843),
(128858, 110, 120, 0, 0, 27843),
(136622, 110, 120, 0, 0, 27843),
(128862, 110, 120, 0, 0, 27843),
(128454, 110, 120, 0, 0, 27843),
(128855, 110, 120, 0, 0, 27843),
(136441, 110, 120, 0, 0, 27843),
(128747, 110, 120, 0, 0, 27843),
(128758, 110, 120, 0, 0, 27843),
(128744, 110, 120, 0, 0, 27843),
(136621, 110, 120, 0, 0, 27843),
(128745, 110, 120, 0, 0, 27843),
(128871, 110, 120, 0, 0, 27843),
(136434, 110, 120, 0, 0, 27843),
(136435, 110, 120, 0, 0, 27843),
(128846, 110, 120, 0, 0, 27843),
(128861, 110, 120, 0, 0, 27843),
(128847, 110, 120, 0, 0, 27843),
(128789, 110, 120, 0, 0, 27843),
(128869, 110, 120, 0, 0, 27843),
(128841, 110, 120, 0, 0, 27843),
(128743, 110, 120, 0, 0, 27843),
(128741, 110, 120, 0, 0, 27843),
(128738, 110, 120, 0, 0, 27843),
(128739, 110, 120, 0, 0, 27843),
(128732, 110, 120, 0, 0, 27843),
(128736, 110, 120, 0, 0, 27843),
(128765, 110, 120, 0, 0, 27843),
(128733, 110, 120, 0, 0, 27843),
(128297, 110, 120, 0, 0, 27843),
(128854, 110, 120, 0, 0, 27843),
(128820, 110, 120, 0, 0, 27843),
(136691, 110, 120, 0, 0, 27843),
(136693, 110, 120, 0, 0, 27843),
(128469, 110, 120, 0, 0, 27843),
(128755, 110, 120, 0, 0, 27843),
(128757, 110, 120, 0, 0, 27843),
(128766, 110, 120, 0, 0, 27843),
(128368, 110, 120, 0, 0, 27843),
(128844, 110, 120, 0, 0, 27843),
(136309, 110, 120, 0, 0, 27843),
(136583, 110, 120, 0, 0, 27843),
(136543, 110, 120, 0, 0, 27843),
(128525, 110, 120, 0, 0, 27843),
(128527, 110, 120, 0, 0, 27843),
(128520, 110, 120, 0, 0, 27843),
(128516, 110, 120, 0, 0, 27843),
(128517, 110, 120, 0, 0, 27843),
(128518, 110, 120, 0, 0, 27843),
(128519, 110, 120, 0, 0, 27843),
(128515, 110, 120, 0, 0, 27843),
(128528, 110, 120, 0, 0, 27843),
(128530, 110, 120, 0, 0, 27843),
(128750, 110, 120, 0, 0, 27843),
(128832, 110, 120, 0, 0, 27843),
(128523, 110, 120, 0, 0, 27843),
(128522, 110, 120, 0, 0, 27843),
(136695, 110, 120, 0, 0, 27843),
(128835, 110, 120, 0, 0, 27843),
(128788, 110, 120, 0, 0, 27843),
(123489, 110, 120, 0, 0, 27843),
(130996, 110, 120, 0, 0, 27843),
(129283, 110, 120, 0, 0, 27843),
(136287, 110, 120, 0, 0, 27843),
(128261, 110, 120, 0, 0, 27843),
(125082, 110, 120, 0, 0, 27843),
(128724, 110, 120, 0, 0, 27843),
(128723, 110, 120, 0, 0, 27843),
(128762, 110, 120, 0, 0, 27843),
(128786, 110, 120, 0, 0, 27843),
(144462, 110, 120, 0, 0, 27843),
(141780, 120, 120, 0, 0, 27843),
(128787, 110, 120, 0, 0, 27843),
(124567, 110, 120, 0, 0, 27843),
(135483, 110, 120, 0, 0, 27843),
(126643, 110, 120, 0, 0, 27843),
(127776, 110, 120, 0, 0, 27843),
(136354, 110, 120, 0, 0, 27843),
(124591, 110, 120, 0, 0, 27843),
(136595, 110, 120, 0, 0, 27843),
(142648, 110, 120, 0, 0, 27843),
(138124, 110, 120, 0, 0, 27843),
(138126, 110, 120, 0, 0, 27843),
(138127, 110, 120, 0, 0, 27843),
(126108, 110, 120, 0, 0, 27843),
(126984, 110, 120, 0, 0, 27843),
(138910, 110, 120, 0, 0, 27843),
(135655, 110, 120, 0, 0, 27843),
(136389, 110, 120, 0, 0, 27843),
(125862, 110, 120, 0, 0, 27843),
(127578, 110, 120, 0, 0, 27843),
(126085, 110, 120, 0, 0, 27843),
(138395, 110, 120, 0, 0, 27843),
(135326, 110, 120, 0, 0, 27843),
(135333, 110, 120, 0, 0, 27843),
(135338, 110, 120, 0, 0, 27843),
(135339, 110, 120, 0, 0, 27843),
(135311, 110, 120, 0, 0, 27843),
(128763, 110, 120, 0, 0, 27843),
(128764, 110, 120, 0, 0, 27843),
(128760, 110, 120, 0, 0, 27843),
(128237, 110, 120, 0, 0, 27843),
(131378, 110, 120, 0, 0, 27843),
(123811, 110, 120, 0, 0, 27843),
(125904, 110, 120, 0, 0, 27843),
(127053, 110, 120, 0, 0, 27843),
(128716, 110, 120, 0, 0, 27843),
(128711, 110, 120, 0, 0, 27843),
(128753, 110, 120, 0, 0, 27843),
(128717, 110, 120, 0, 0, 27843),
(128714, 110, 120, 0, 0, 27843),
(128253, 110, 120, 0, 0, 27843),
(128715, 110, 120, 0, 0, 27843),
(128251, 110, 120, 0, 0, 27843),
(128252, 110, 120, 0, 0, 27843),
(128866, 110, 120, 0, 0, 27843),
(128868, 110, 120, 0, 0, 27843),
(128453, 110, 120, 0, 0, 27843),
(128850, 110, 120, 0, 0, 27843),
(128351, 110, 120, 0, 0, 27843),
(128864, 110, 120, 0, 0, 27843),
(128865, 110, 120, 0, 0, 27843),
(128873, 110, 120, 0, 0, 27843),
(128872, 110, 120, 0, 0, 27843),
(128801, 110, 120, 0, 0, 27843),
(125310, 110, 120, 0, 0, 27843),
(128870, 110, 120, 0, 0, 27843),
(128348, 110, 120, 0, 0, 27843),
(124560, 110, 120, 0, 0, 27843),
(128796, 110, 120, 0, 0, 27843),
(128564, 110, 120, 0, 0, 27843),
(128197, 110, 120, 0, 0, 27843),
(128565, 110, 120, 0, 0, 27843),
(124811, 110, 120, 0, 0, 27843),
(128795, 110, 120, 0, 0, 27843),
(122790, 110, 120, 0, 0, 27843),
(128404, 110, 120, 0, 0, 27843),
(139773, 110, 120, 0, 0, 27843),
(142895, 110, 120, 0, 0, 27843),
(139775, 110, 120, 0, 0, 27843),
(139492, 110, 120, 0, 0, 27843),
(135349, 110, 120, 0, 0, 27843),
(136338, 110, 120, 0, 0, 27843),
(139772, 110, 120, 0, 0, 27843),
(140046, 110, 120, 0, 0, 27843),
(139982, 110, 120, 0, 0, 27843),
(139989, 110, 120, 0, 0, 27843),
(139569, 110, 120, 0, 0, 27843),
(139929, 110, 120, 0, 0, 27843),
(140567, 120, 120, 0, 0, 27843),
(140888, 110, 120, 0, 0, 27843),
(140530, 120, 120, 0, 0, 27843),
(144610, 110, 120, 0, 0, 27843),
(144611, 110, 120, 0, 0, 27843),
(135179, 110, 120, 0, 0, 27843),
(135180, 110, 120, 0, 0, 27843),
(135269, 110, 120, 0, 0, 27843),
(144245, 110, 120, 0, 0, 27843),
(135286, 110, 120, 0, 0, 27843),
(139114, 110, 120, 0, 0, 27843),
(140051, 110, 120, 0, 0, 27843),
(140050, 110, 120, 0, 0, 27843),
(136225, 110, 120, 0, 0, 27843),
(141755, 110, 120, 0, 0, 27843),
(135006, 110, 120, 0, 0, 27843),
(143213, 110, 120, 0, 0, 27843),
(143212, 110, 120, 0, 0, 27843),
(141720, 110, 120, 0, 0, 27843),
(135084, 110, 120, 0, 0, 27843),
(139071, 110, 120, 0, 0, 27843),
(128694, 110, 120, 0, 0, 27843);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(134595, 110, 120, 0, 0, 27843),
(129519, 110, 120, 0, 0, 27843),
(129518, 110, 120, 0, 0, 27843),
(130023, 110, 120, 0, 0, 27843),
(130022, 110, 120, 0, 0, 27843),
(128660, 110, 120, 0, 0, 27843),
(128664, 110, 120, 0, 0, 27843),
(128661, 110, 120, 0, 0, 27843),
(134638, 110, 120, 0, 0, 27843),
(128961, 110, 120, 0, 0, 27843),
(128662, 110, 120, 0, 0, 27843),
(129076, 110, 120, 0, 0, 27843),
(129202, 110, 120, 0, 0, 27843),
(144353, 110, 120, 0, 0, 27843),
(139827, 110, 120, 0, 0, 27843),
(128695, 110, 120, 0, 0, 27843),
(129224, 110, 120, 0, 0, 27843),
(124832, 110, 120, 0, 0, 27843),
(128687, 110, 120, 0, 0, 27843),
(128697, 110, 120, 0, 0, 27843),
(128693, 110, 120, 0, 0, 27843),
(129011, 110, 120, 0, 0, 27843),
(128688, 110, 120, 0, 0, 27843),
(128696, 110, 120, 0, 0, 27843),
(134613, 110, 120, 0, 0, 27843),
(129216, 110, 120, 0, 0, 27843),
(129521, 110, 120, 0, 0, 27843),
(129014, 110, 120, 0, 0, 27843),
(128692, 110, 120, 0, 0, 27843),
(128689, 110, 120, 0, 0, 27843),
(142313, 110, 120, 0, 0, 27843),
(125098, 110, 120, 0, 0, 27843),
(143454, 110, 120, 0, 0, 27843),
(135400, 110, 120, 0, 0, 27843),
(124716, 110, 120, 0, 0, 27843),
(124522, 110, 120, 0, 0, 27843),
(124718, 110, 120, 0, 0, 27843),
(136144, 110, 120, 0, 0, 27843),
(136109, 110, 120, 0, 0, 27843),
(129004, 110, 120, 0, 0, 27843),
(130042, 110, 120, 0, 0, 27843),
(134321, 110, 120, 0, 0, 27843),
(134320, 110, 120, 0, 0, 27843),
(128665, 110, 120, 0, 0, 27843),
(139072, 110, 120, 0, 0, 27843),
(129008, 110, 120, 0, 0, 27843),
(129007, 110, 120, 0, 0, 27843),
(136548, 110, 120, 0, 0, 27843),
(136545, 110, 120, 0, 0, 27843),
(141597, 110, 120, 0, 0, 27843),
(136546, 110, 120, 0, 0, 27843),
(137556, 110, 120, 0, 0, 27843),
(123473, 110, 120, 0, 0, 27843),
(133888, 110, 120, 0, 0, 27843),
(126627, 110, 120, 0, 0, 27843),
(126645, 110, 120, 0, 0, 27843),
(126576, 110, 120, 0, 0, 27843),
(135654, 110, 120, 0, 0, 27843),
(134292, 110, 120, 0, 0, 27843),
(134121, 110, 120, 0, 0, 27843),
(134090, 110, 120, 0, 0, 27843),
(134067, 110, 120, 0, 0, 27843),
(136340, 110, 120, 0, 0, 27843),
(134533, 110, 120, 0, 0, 27843),
(126712, 110, 120, 0, 0, 27843),
(137332, 110, 120, 0, 0, 27843),
(124810, 110, 120, 0, 0, 27843),
(134164, 110, 120, 0, 0, 27843),
(134245, 110, 120, 0, 0, 27843),
(134314, 110, 120, 0, 0, 27843),
(134148, 110, 120, 0, 0, 27843),
(139082, 110, 120, 0, 0, 27843),
(139083, 110, 120, 0, 0, 27843);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (80056, 80041, 84782, 84783, 84787, 84780, 84781, 80208, 77630, 80789, 84260, 80176, 80206, 84892, 80210, 80119, 80168, 80196, 84191, 80166, 80173, 84874, 84778, 84880, 80223, 80202, 80205, 80195, 80197, 80194, 80203, 80200, 80198, 84719, 84925, 77469, 80169, 80111, 80215, 80214, 80133, 80005, 80004, 80576, 80000, 80001, 80002, 80575, 80192, 80199, 84877, 78248, 80191, 84876, 80175, 80221, 80193, 80220, 80224, 80222, 80226, 79412, 80217, 84776, 80132, 80138, 80128, 80131, 80235, 84775, 84774, 80211, 80225, 80212, 80165, 80233, 80207, 80125, 80124, 80121, 80122, 80116, 80117, 85303, 85304, 80146, 80115, 79660, 80216, 85305, 80190, 84894, 84895, 80145, 80136, 80137, 80147, 85302, 80209, 79991, 79965, 79966, 79964, 79960, 79961, 79962, 79963, 79959, 79968, 79972, 80134, 80201, 84896, 80204, 80164, 77584, 78326, 80500, 79469, 80060, 80110, 80109, 80141, 80162, 80163, 77188, 79365, 78107, 82992, 84838, 77391, 80495, 85734, 78735, 79267, 78736, 84759, 78616, 78894, 79006, 79005, 78713, 79007, 84203, 79004, 85849, 85851, 87962, 85848, 85850, 80142, 80143, 80140, 81795, 79476, 79464, 79466, 80104, 80100, 80135, 80105, 78402, 80101, 80103, 80230, 80232, 80113, 80213, 79574, 80228, 79573, 80229, 80237, 79572, 80236, 79472, 80174, 79218, 80234, 79570, 79473, 79095, 80171, 79830, 79215, 79217, 79831, 78205, 80170, 76977, 87770, 80463, 86556, 76384, 76382, 76383, 86766, 84179, 84180, 84122, 84123, 84094, 86492, 86137, 81654, 81655, 87762, 86670, 84081, 86116, 80093, 82697, 80640, 80643, 84483, 84491, 80681, 80334, 79953, 87364, 80668, 80630, 86117, 80632, 80631, 80633, 80627, 83784, 80628, 80629, 80635, 80634, 84472, 77903, 84659, 80264, 79014, 85309, 80466, 80636, 75372, 85308, 80648, 80571, 80572, 83717, 85321, 80676, 80677, 83682, 84603, 80570, 77495, 87963, 87966, 87967, 84161, 78988, 78742, 83534, 83354, 83321, 87845, 84727, 84744, 80625, 78206, 83368, 83519, 84726, 83358, 84729);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(80056, 0.9458658, 2.4, 0, 27843),
(80041, 15.80507, 1.5, 0, 27843),
(84782, 0.5911661, 1.5, 0, 27843),
(84783, 0.5911661, 1.5, 0, 27843),
(84787, 2.181009, 1.5, 0, 27843),
(84780, 0.5911661, 1.5, 0, 27843),
(84781, 0.5911661, 1.5, 0, 27843),
(80208, 0.5911661, 1.5, 0, 27843),
(77630, 2.502509, 4.8, 0, 27843),
(80789, 1, 1.5, 0, 27843),
(84260, 0.8073308, 1, 0, 27843),
(80176, 0.7389576, 1.875, 0, 27843),
(80206, 0.5911661, 1.5, 0, 27843),
(84892, 0.5911661, 1.5, 0, 27843),
(80210, 0.5911661, 1.5, 0, 27843),
(80119, 0.7093994, 1.8, 0, 27843),
(80168, 0.5911661, 1.5, 0, 27843),
(80196, 0.5911661, 1.5, 0, 27843),
(84191, 0.9344095, 1.5, 0, 27843),
(80166, 0.5911661, 1.5, 0, 27843),
(80173, 0.5911661, 1.5, 0, 27843),
(84874, 0.5911661, 1.5, 0, 27843),
(84778, 0.7389576, 1.875, 0, 27843),
(84880, 0.5911661, 1.5, 0, 27843),
(80223, 0.5911661, 1.5, 0, 27843),
(80202, 0.5911661, 1.5, 0, 27843),
(80205, 0.5911661, 1.5, 0, 27843),
(80195, 0.5911661, 1.5, 0, 27843),
(80197, 0.5911661, 1.5, 0, 27843),
(80194, 0.5911661, 1.5, 0, 27843),
(80203, 0.5911661, 1.5, 0, 27843),
(80200, 0.5911661, 1.5, 0, 27843),
(80198, 0.5911661, 1.5, 0, 27843),
(84719, 1.433767, 1.5, 0, 27843),
(84925, 0.5911661, 1.5, 0, 27843),
(77469, 3.128136, 6, 0, 27843),
(80169, 0.5911661, 1.5, 0, 27843),
(80111, 0.7389576, 1.875, 0, 27843),
(80215, 0.5911661, 1.5, 0, 27843),
(80214, 0.5911661, 1.5, 0, 27843),
(80005, 0.347222, 1.5, 0, 27843),
(80004, 0.347222, 1.5, 0, 27843),
(80576, 0.9344095, 1.5, 0, 27843),
(80000, 0.347222, 1.5, 0, 27843),
(80001, 0.347222, 1.5, 0, 27843),
(80002, 0.347222, 1.5, 0, 27843),
(80575, 0.9344095, 1.5, 0, 27843),
(80192, 0.5911661, 1.5, 0, 27843),
(80199, 0.5911661, 1.5, 0, 27843),
(84877, 0.5911661, 1.5, 0, 27843),
(78248, 1, 1.25, 0, 27843),
(80191, 0.5911661, 1.5, 0, 27843),
(84876, 0.5911661, 1.5, 0, 27843),
(80175, 0.5911661, 1.5, 0, 27843),
(80221, 0.5911661, 1.5, 0, 27843),
(80193, 0.5911661, 1.5, 0, 27843),
(80220, 0.5911661, 1.5, 0, 27843),
(80224, 0.5911661, 1.5, 0, 27843),
(80222, 0.5911661, 1.5, 0, 27843),
(80226, 0.5911661, 1.5, 0, 27843),
(79412, 2.586958, 2.25, 0, 27843),
(80217, 0.5911661, 1.5, 0, 27843),
(84776, 0.5911661, 1.5, 0, 27843),
(80132, 0.5911661, 1.5, 0, 27843),
(80138, 0.5911661, 1.5, 0, 27843),
(80128, 0.5911661, 1.5, 0, 27843),
(80131, 0.5911661, 1.5, 0, 27843),
(80235, 0.5911661, 1.5, 0, 27843),
(84775, 0.5911661, 1.5, 0, 27843),
(84774, 0.5911661, 1.5, 0, 27843),
(80211, 0.5911661, 1.5, 0, 27843),
(80225, 0.5911661, 1.5, 0, 27843),
(80212, 0.5911661, 1.5, 0, 27843),
(80165, 0.5911661, 1.5, 0, 27843),
(80233, 0.5911661, 1.5, 0, 27843),
(80207, 0.5911661, 1.5, 0, 27843),
(80125, 0.5911661, 1.5, 0, 27843),
(80124, 0.5911661, 1.5, 0, 27843),
(80121, 0.5911661, 1.5, 0, 27843),
(80122, 0.5911661, 1.5, 0, 27843),
(80116, 0.5911661, 1.5, 0, 27843),
(80117, 0.5911661, 1.5, 0, 27843),
(85303, 0.306, 1.5, 0, 27843),
(85304, 0.306, 1.5, 0, 27843),
(80146, 0.5911661, 1.5, 0, 27843),
(80115, 0.5911661, 1.5, 0, 27843),
(79660, 0.8745, 1.65, 0, 27843),
(80216, 0.5911661, 1.5, 0, 27843),
(85305, 0.306, 1.5, 0, 27843),
(80190, 0.5911661, 1.5, 0, 27843),
(84894, 0.5911661, 1.5, 0, 27843),
(84895, 0.5911661, 1.5, 0, 27843),
(80145, 0.5911661, 1.5, 0, 27843),
(80136, 0.5911661, 1.5, 0, 27843),
(80137, 0.5911661, 1.5, 0, 27843),
(80147, 0.5911661, 1.5, 0, 27843),
(85302, 0.306, 1.5, 0, 27843),
(80209, 0.5911661, 1.5, 0, 27843),
(79991, 0.347222, 1.5, 0, 27843),
(79965, 0.347222, 1.5, 0, 27843),
(79966, 0.347222, 1.5, 0, 27843),
(79964, 0.347222, 1.5, 0, 27843),
(79960, 0.347222, 1.5, 0, 27843),
(79961, 0.347222, 1.5, 0, 27843),
(79962, 0.347222, 1.5, 0, 27843),
(79963, 0.347222, 1.5, 0, 27843),
(79959, 0.347222, 1.5, 0, 27843),
(79968, 0.347222, 1.5, 0, 27843),
(79972, 0.4340275, 1.875, 0, 27843),
(80134, 0.5911661, 1.5, 0, 27843),
(80201, 0.5911661, 1.5, 0, 27843),
(84896, 0.5911661, 1.5, 0, 27843),
(80204, 0.5911661, 1.5, 0, 27843),
(80164, 0.5911661, 1.5, 0, 27843),
(77584, 2.502509, 4.8, 0, 27843),
(78326, 0.2625, 0.6, 0, 27843),
(80500, 2.156971, 2.8125, 0, 27843),
(79469, 0.306, 1.5, 0, 27843),
(80060, 0.7093994, 1.8, 0, 27843),
(80110, 0.5911661, 1.5, 0, 27843),
(80109, 0.5911661, 1.5, 0, 27843),
(80141, 0.5911661, 1.5, 0, 27843),
(80162, 0.5911661, 1.5, 0, 27843),
(80163, 0.5911661, 1.5, 0, 27843),
(77188, 0.17565, 1, 0, 27843),
(79365, 2.988973, 3.3, 0, 27843),
(78107, 0.347222, 1.5, 0, 27843),
(82992, 0.347222, 1.5, 0, 27843),
(84838, 0.8867492, 2.25, 0, 27843),
(77391, 0.3466739, 1.5, 0, 27843),
(80495, 0.347222, 1.5, 0, 27843),
(85734, 0.3819442, 1.65, 0, 27843),
(78735, 0.347222, 1.5, 0, 27843),
(79267, 1.992649, 2.2, 0, 27843),
(78736, 0.347222, 1.5, 0, 27843),
(84759, 0.347222, 1.5, 0, 27843),
(78616, 0.347222, 1.5, 0, 27843),
(78894, 0.347222, 1.5, 0, 27843),
(79006, 0.347222, 1.5, 0, 27843),
(79005, 0.347222, 1.5, 0, 27843),
(78713, 0.347222, 1.5, 0, 27843),
(79007, 0.347222, 1.5, 0, 27843),
(84203, 0.347222, 1.5, 0, 27843),
(79004, 0.347222, 1.5, 0, 27843),
(85849, 0.347222, 1.5, 0, 27843),
(85851, 0.347222, 1.5, 0, 27843),
(87962, 0.5695243, 1.5, 0, 27843),
(85848, 0.347222, 1.5, 0, 27843),
(85850, 0.347222, 1.5, 0, 27843),
(80142, 0.5911661, 1.5, 0, 27843),
(80143, 0.5911661, 1.5, 0, 27843),
(80140, 0.5911661, 1.5, 0, 27843),
(81795, 0.306, 1.5, 0, 27843),
(79476, 0.306, 1.5, 0, 27843),
(79466, 0.306, 1.5, 0, 27843),
(80104, 0.5911661, 1.5, 0, 27843),
(80100, 0.5911661, 1.5, 0, 27843),
(80135, 0.5911661, 1.5, 0, 27843),
(80105, 0.5911661, 1.5, 0, 27843),
(78402, 0.306, 1.5, 0, 27843),
(80101, 0.5911661, 1.5, 0, 27843),
(80103, 0.5911661, 1.5, 0, 27843),
(80230, 0.5911661, 1.5, 0, 27843),
(80232, 0.5911661, 1.5, 0, 27843),
(80113, 0.7389576, 1.875, 0, 27843),
(80213, 0.5911661, 1.5, 0, 27843),
(79574, 1.018043, 1.5, 0, 27843),
(80228, 0.5911661, 1.5, 0, 27843),
(79573, 1.018043, 1.5, 0, 27843),
(80229, 0.5911661, 1.5, 0, 27843),
(80237, 0.5911661, 1.5, 0, 27843),
(79572, 1.018043, 1.5, 0, 27843),
(80236, 0.5911661, 1.5, 0, 27843),
(79472, 0.306, 1.5, 0, 27843),
(80174, 0.5911661, 1.5, 0, 27843),
(79218, 0.9344095, 1.5, 0, 27843),
(80234, 0.5911661, 1.5, 0, 27843),
(79570, 1.018043, 1.5, 0, 27843),
(79473, 0.306, 1.5, 0, 27843),
(79095, 0.9344095, 1.5, 0, 27843),
(80171, 0.5911661, 1.5, 0, 27843),
(79830, 0.347222, 1.5, 0, 27843),
(79215, 0.9344095, 1.5, 0, 27843),
(79217, 0.9344095, 1.5, 0, 27843),
(79831, 0.347222, 1.5, 0, 27843),
(78205, 1.5, 3, 0, 27843),
(80170, 0.5911661, 1.5, 0, 27843),
(76977, 0.3, 1.5, 0, 27843),
(87770, 5, 1.5, 0, 27843),
(80463, 0.245, 0.7, 0, 27843),
(86556, 0.306, 1.5, 0, 27843),
(76384, 0.6319579, 0.6, 0, 27843),
(76382, 0.7899474, 0.75, 0, 27843),
(76383, 0.5266316, 0.5, 0, 27843),
(86766, 0.51705, 2.025, 0, 27843),
(84179, 0.306, 1.5, 0, 27843),
(84180, 0.306, 1.5, 0, 27843),
(84122, 0.306, 1.5, 0, 27843),
(84123, 0.383, 1.5, 0, 27843),
(84094, 2.85421, 2.5, 0, 27843),
(86492, 0.347222, 1.5, 0, 27843),
(86137, 8.277778, 5, 0, 27843),
(81654, 1.863049, 1.2, 0, 27843),
(81655, 1.31966, 0.85, 0, 27843),
(87762, 0.3366, 1.65, 0, 27843),
(86670, 1.970095, 1.725, 0, 27843),
(84081, 0.8, 1, 0, 27843),
(86116, 1.5, 1.5, 0, 27843),
(80093, 2.502509, 4.8, 0, 27843),
(82697, 2.502509, 4.8, 0, 27843),
(80640, 0.8073308, 1, 0, 27843),
(80643, 1.009162, 1.5, 0, 27843),
(84483, 1.009162, 1.5, 0, 27843),
(84491, 0.8073308, 1, 0, 27843),
(80681, 1.401614, 1.5, 0, 27843),
(80334, 0.8719173, 1.08, 0, 27843),
(79953, 1.944477, 5, 0, 27843),
(87364, 1.368729, 1.8, 0, 27843),
(80668, 0.9344095, 1.5, 0, 27843),
(80630, 0.9344095, 1.5, 0, 27843),
(86117, 1.5, 1.5, 0, 27843),
(80632, 0.9344095, 1.5, 0, 27843),
(80631, 0.8073308, 1, 0, 27843),
(80633, 0.8073308, 1, 0, 27843),
(80627, 0.8073308, 1, 0, 27843),
(83784, 0.9344095, 1.5, 0, 27843),
(80628, 0.8073308, 1, 0, 27843),
(80629, 0.9344095, 1.5, 0, 27843),
(80635, 0.9344095, 1.5, 0, 27843),
(80634, 0.8073308, 1, 0, 27843),
(84472, 0.9811299, 1.5, 0, 27843),
(77903, 1.866102, 1.5, 0, 27843),
(84659, 0.306, 1.5, 0, 27843),
(80264, 0.4879304, 0.625, 0, 27843),
(79014, 0.2927582, 0.375, 0, 27843),
(85309, 0.35, 0.35, 0, 27843),
(80466, 0.35, 1, 0, 27843),
(80636, 0.9811299, 1.5, 0, 27843),
(75372, 1.342116, 1.75, 0, 27843),
(85308, 0.35, 0.35, 0, 27843),
(80648, 1.009162, 1.5, 0, 27843),
(80571, 0.9344095, 1.5, 0, 27843),
(80572, 0.9344095, 1.5, 0, 27843),
(83717, 0.9344095, 1.5, 0, 27843),
(85321, 0.306, 1.5, 0, 27843),
(80676, 0.8073308, 1, 0, 27843),
(80677, 0.8073308, 1, 0, 27843),
(83682, 0.306, 1.5, 0, 27843);

INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(84603, 0.306, 1.5, 0, 27843),
(80570, 0.9344095, 1.5, 0, 27843),
(77495, 1.992649, 2.2, 0, 27843),
(87963, 0.5695243, 1.5, 0, 27843),
(87966, 0.5695243, 1.5, 0, 27843),
(87967, 0.5695243, 1.5, 0, 27843),
(84161, 1.284845, 1.125, 0, 27843),
(78988, 0.3819442, 1.65, 0, 27843),
(78742, 0.347222, 1.5, 0, 27843),
(83534, 0.8880639, 1.1, 0, 27843),
(83354, 1.121291, 1.5, 0, 27843),
(83321, 3.229323, 4, 0, 27843),
(87845, 3.229323, 4, 0, 27843),
(84727, 0.306, 1.5, 0, 27843),
(84744, 1.457679, 1.5, 0, 27843),
(80625, 0.9811299, 1.5, 0, 27843),
(78206, 0.5, 1, 0, 27843),
(83368, 0.3672, 1.8, 0, 27843),
(83519, 0.2372223, 1.5, 0, 27843),
(84726, 0.306, 1.5, 0, 27843),
(83358, 0.306, 1.5, 0, 27843),
(84729, 0.306, 1.5, 0, 27843);

UPDATE `creature_model_info` SET `BoundingRadius`=3.978021, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=2851;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199188, `CombatReach`=1.05, `VerifiedBuild`=27843 WHERE `DisplayID`=15339;
UPDATE `creature_model_info` SET `BoundingRadius`=0.105, `CombatReach`=0.24, `VerifiedBuild`=27843 WHERE `DisplayID`=43295;
UPDATE `creature_model_info` SET `BoundingRadius`=1.342116, `CombatReach`=1.75, `VerifiedBuild`=27843 WHERE `DisplayID`=999;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5669019, `CombatReach`=1.35, `VerifiedBuild`=27843 WHERE `DisplayID`=1535;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199188, `CombatReach`=1.05, `VerifiedBuild`=27843 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `BoundingRadius`=1.575, `CombatReach`=4.5 WHERE `DisplayID`=80467;
UPDATE `creature_model_info` SET `BoundingRadius`=0.0875, `CombatReach`=0.25, `VerifiedBuild`=27843 WHERE `DisplayID`=30137;
UPDATE `creature_model_info` SET `BoundingRadius`=1.516783, `CombatReach`=1, `VerifiedBuild`=27843 WHERE `DisplayID`=72015;
UPDATE `creature_model_info` SET `BoundingRadius`=2.771951, `VerifiedBuild`=27843 WHERE `DisplayID`=32405;
UPDATE `creature_model_info` SET `BoundingRadius`=2.771951, `VerifiedBuild`=27843 WHERE `DisplayID`=32408;
UPDATE `creature_model_info` SET `BoundingRadius`=1.516783, `CombatReach`=1, `VerifiedBuild`=27843 WHERE `DisplayID`=72013;
UPDATE `creature_model_info` SET `BoundingRadius`=1.516783, `CombatReach`=1, `VerifiedBuild`=27843 WHERE `DisplayID`=72016;
UPDATE `creature_model_info` SET `BoundingRadius`=7.905617, `CombatReach`=18, `VerifiedBuild`=27843 WHERE `DisplayID`=55786;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199188, `CombatReach`=1.05, `VerifiedBuild`=27843 WHERE `DisplayID`=11108;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `CombatReach`=0.75, `VerifiedBuild`=27843 WHERE `DisplayID`=61527;
UPDATE `creature_model_info` SET `BoundingRadius`=1.371799, `VerifiedBuild`=27843 WHERE `DisplayID`=19480;
UPDATE `creature_model_info` SET `BoundingRadius`=1.713126, `VerifiedBuild`=27843 WHERE `DisplayID`=15464;
UPDATE `creature_model_info` SET `BoundingRadius`=0.09586539, `CombatReach`=0.125, `VerifiedBuild`=27843 WHERE `DisplayID`=5557;
UPDATE `creature_model_info` SET `BoundingRadius`=0.09586539, `CombatReach`=0.125, `VerifiedBuild`=27843 WHERE `DisplayID`=5560;
UPDATE `creature_model_info` SET `BoundingRadius`=0.0875, `CombatReach`=0.25, `VerifiedBuild`=27843 WHERE `DisplayID`=40999;
UPDATE `creature_model_info` SET `BoundingRadius`=2.52932, `CombatReach`=4.2 WHERE `DisplayID`=80970;

DELETE FROM `trainer` WHERE `Id`=858;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(858, 2, 'Can I teach you how to turn the meat you find on beasts into a feast?', 27843);


DELETE FROM `trainer_spell` WHERE (`TrainerId`=858 AND `SpellId`=259446) OR (`TrainerId`=858 AND `SpellId`=259415) OR (`TrainerId`=858 AND `SpellId`=259436) OR (`TrainerId`=858 AND `SpellId`=259414) OR (`TrainerId`=858 AND `SpellId`=259440) OR (`TrainerId`=858 AND `SpellId`=259443) OR (`TrainerId`=858 AND `SpellId`=259412) OR (`TrainerId`=858 AND `SpellId`=259437) OR (`TrainerId`=858 AND `SpellId`=259419) OR (`TrainerId`=858 AND `SpellId`=259445) OR (`TrainerId`=858 AND `SpellId`=259434) OR (`TrainerId`=858 AND `SpellId`=259439) OR (`TrainerId`=858 AND `SpellId`=259424) OR (`TrainerId`=858 AND `SpellId`=259431) OR (`TrainerId`=858 AND `SpellId`=259418) OR (`TrainerId`=858 AND `SpellId`=259421) OR (`TrainerId`=858 AND `SpellId`=259428) OR (`TrainerId`=858 AND `SpellId`=259427) OR (`TrainerId`=858 AND `SpellId`=259433) OR (`TrainerId`=858 AND `SpellId`=259411) OR (`TrainerId`=858 AND `SpellId`=259425) OR (`TrainerId`=858 AND `SpellId`=264633) OR (`TrainerId`=858 AND `SpellId`=265818);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(858, 259446, 450000, 2541, 75, 259445, 0, 0, 0, 27843),
(858, 259415, 450000, 2541, 75, 259414, 0, 0, 0, 27843),
(858, 259436, 250000, 2541, 10, 0, 0, 0, 0, 27843),
(858, 259414, 375000, 2541, 50, 0, 0, 0, 0, 27843),
(858, 259440, 450000, 2541, 75, 259439, 0, 0, 0, 27843),
(858, 259443, 350000, 2541, 35, 259442, 0, 0, 0, 27843),
(858, 259412, 350000, 2541, 35, 259411, 0, 0, 0, 27843),
(858, 259437, 350000, 2541, 35, 259436, 0, 0, 0, 27843),
(858, 259419, 450000, 2541, 75, 259418, 0, 0, 0, 27843),
(858, 259445, 375000, 2541, 50, 0, 0, 0, 0, 27843),
(858, 259434, 450000, 2541, 75, 259433, 0, 0, 0, 27843),
(858, 259439, 375000, 2541, 50, 0, 0, 0, 0, 27843),
(858, 259424, 250000, 2541, 10, 0, 0, 0, 0, 27843),
(858, 259431, 300000, 2541, 15, 259430, 0, 0, 0, 27843),
(858, 259418, 375000, 2541, 50, 0, 0, 0, 0, 27843),
(858, 259421, 600000, 2541, 110, 0, 0, 0, 0, 27843),
(858, 259428, 450000, 2541, 75, 259427, 0, 0, 0, 27843),
(858, 259427, 375000, 2541, 50, 0, 0, 0, 0, 27843),
(858, 259433, 375000, 2541, 50, 0, 0, 0, 0, 27843),
(858, 259411, 250000, 2541, 10, 0, 0, 0, 0, 27843),
(858, 259425, 350000, 2541, 35, 259424, 0, 0, 0, 27843),
(858, 264633, 10, 0, 0, 0, 0, 0, 5, 27843),
(858, 265818, 500000, 185, 1, 0, 0, 0, 110, 27843);


DELETE FROM `npc_vendor` WHERE (`entry`=136389 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=136389 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=136389 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127578 AND `item`=162570 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127578 AND `item`=162569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127578 AND `item`=162566 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=117445 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=115351 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135655 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135400 AND `item`=159753 AND `ExtendedCost`=6422 AND `type`=1) OR (`entry`=135400 AND `item`=163514 AND `ExtendedCost`=6440 AND `type`=1) OR (`entry`=135400 AND `item`=163512 AND `ExtendedCost`=6431 AND `type`=1) OR (`entry`=135400 AND `item`=163511 AND `ExtendedCost`=6431 AND `type`=1) OR (`entry`=135400 AND `item`=163509 AND `ExtendedCost`=6428 AND `type`=1) OR (`entry`=139827 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=128697 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128697 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128693 AND `item`=162570 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128693 AND `item`=162569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128693 AND `item`=162566 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(136389, 10, 163203, 0, 6426, 1, 0, 0, 27843), -- Hypersensitive Azeritometer Sensor
(136389, 9, 3857, 0, 0, 1, 0, 0, 27843), -- Coal
(136389, 8, 18567, 0, 0, 1, 0, 0, 27843), -- Elemental Flux
(136389, 7, 160298, 0, 0, 1, 0, 0, 27843), -- Durable Flux
(136389, 6, 3466, 0, 0, 1, 0, 0, 27843), -- Strong Flux
(136389, 5, 2880, 0, 0, 1, 0, 0, 27843), -- Weak Flux
(136389, 4, 5956, 0, 0, 1, 0, 0, 27843), -- Blacksmith Hammer
(136389, 3, 2901, 0, 0, 1, 0, 0, 27843), -- Mining Pick
(136389, 2, 160502, 0, 0, 1, 0, 0, 27843), -- Chemical Blasting Cap
(136389, 1, 163569, 0, 0, 1, 0, 0, 27843), -- Insulated Wiring
(127578, 7, 162570, 0, 0, 1, 0, 0, 27843), -- Pricklevine Juice
(127578, 6, 162569, 0, 0, 1, 0, 0, 27843), -- Sun-Parched Waterskin
(127578, 2, 162566, 0, 0, 1, 0, 0, 27843), -- Sun-Turned Curds
(135655, 17, 64670, 0, 0, 1, 0, 0, 27843), -- Vanishing Powder
(135655, 16, 39505, 0, 0, 1, 0, 0, 27843), -- Virtuoso Inking Set
(135655, 15, 20815, 0, 0, 1, 0, 0, 27843), -- Jeweler's Kit
(135655, 14, 5956, 0, 0, 1, 0, 0, 27843), -- Blacksmith Hammer
(135655, 13, 6217, 0, 0, 1, 0, 0, 27843), -- Copper Rod
(135655, 12, 6256, 0, 0, 1, 0, 0, 27843), -- Fishing Pole
(135655, 11, 85663, 0, 0, 1, 0, 0, 27843), -- Herbalist's Spade
(135655, 10, 7005, 0, 0, 1, 0, 0, 27843), -- Skinning Knife
(135655, 9, 2901, 0, 0, 1, 0, 0, 27843), -- Mining Pick
(135655, 8, 117445, 0, 0, 1, 0, 0, 27843), -- Clefthoof Hide Satchel
(135655, 7, 90146, 0, 0, 1, 0, 0, 27843), -- Tinker's Kit
(135655, 6, 4470, 0, 0, 1, 0, 0, 27843), -- Simple Wood
(135655, 5, 38682, 0, 0, 1, 0, 0, 27843), -- Enchanting Vellum
(135655, 4, 3371, 0, 0, 1, 0, 0, 27843), -- Crystal Vial
(135655, 3, 39354, 0, 0, 1, 0, 0, 27843), -- Light Parchment
(135655, 2, 115351, 0, 0, 1, 0, 0, 27843), -- "Rylak Claws"
(135655, 1, 117452, 0, 0, 1, 0, 0, 27843), -- Gorgrond Mineral Water
(135400, 6, 159753, 0, 6422, 1, 0, 0, 27843), -- Desert Flute
(135400, 4, 163514, 0, 6440, 1, 0, 0, 27843), -- Violent Looking Flower Pot
(135400, 3, 163512, 0, 6431, 1, 0, 0, 27843), -- Sandstinger Wasp
(135400, 2, 163511, 0, 6431, 1, 0, 0, 27843), -- Barnacled Hermit Crab
(135400, 1, 163509, 0, 6428, 1, 0, 0, 27843), -- Freshwater Pincher
(139827, 1, 37460, 0, 0, 1, 0, 0, 27843), -- Rope Pet Leash
(128697, 10, 163203, 0, 6426, 1, 0, 0, 27843), -- Hypersensitive Azeritometer Sensor
(128697, 9, 3857, 0, 0, 1, 0, 0, 27843), -- Coal
(128697, 8, 18567, 0, 0, 1, 0, 0, 27843), -- Elemental Flux
(128697, 7, 160298, 0, 0, 1, 0, 0, 27843), -- Durable Flux
(128697, 6, 3466, 0, 0, 1, 0, 0, 27843), -- Strong Flux
(128697, 5, 2880, 0, 0, 1, 0, 0, 27843), -- Weak Flux
(128697, 4, 5956, 0, 0, 1, 0, 0, 27843), -- Blacksmith Hammer
(128697, 3, 2901, 0, 0, 1, 0, 0, 27843), -- Mining Pick
(128697, 2, 160502, 0, 0, 1, 0, 0, 27843), -- Chemical Blasting Cap
(128697, 1, 163569, 0, 0, 1, 0, 0, 27843), -- Insulated Wiring
(128693, 6, 162570, 0, 0, 1, 0, 0, 27843), -- Pricklevine Juice
(128693, 5, 162569, 0, 0, 1, 0, 0, 27843), -- Sun-Parched Waterskin
(128693, 1, 162566, 0, 0, 1, 0, 0, 27843); -- Sun-Turned Curds


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=127025 AND `ID`=1) OR (`CreatureID`=128646 AND `ID`=1) OR (`CreatureID`=128640 AND `ID`=1) OR (`CreatureID`=128641 AND `ID`=1) OR (`CreatureID`=128642 AND `ID`=1) OR (`CreatureID`=128643 AND `ID`=1) OR (`CreatureID`=128644 AND `ID`=1) OR (`CreatureID`=136785 AND `ID`=2) OR (`CreatureID`=136466 AND `ID`=1) OR (`CreatureID`=128843 AND `ID`=1) OR (`CreatureID`=136785 AND `ID`=1) OR (`CreatureID`=136781 AND `ID`=1) OR (`CreatureID`=136783 AND `ID`=1) OR (`CreatureID`=136779 AND `ID`=1) OR (`CreatureID`=128557 AND `ID`=1) OR (`CreatureID`=128840 AND `ID`=1) OR (`CreatureID`=136689 AND `ID`=1) OR (`CreatureID`=128845 AND `ID`=1) OR (`CreatureID`=128299 AND `ID`=1) OR (`CreatureID`=128793 AND `ID`=1) OR (`CreatureID`=128827 AND `ID`=1) OR (`CreatureID`=128749 AND `ID`=1) OR (`CreatureID`=128791 AND `ID`=1) OR (`CreatureID`=128800 AND `ID`=1) OR (`CreatureID`=136673 AND `ID`=1) OR (`CreatureID`=136446 AND `ID`=1) OR (`CreatureID`=136680 AND `ID`=1) OR (`CreatureID`=128859 AND `ID`=1) OR (`CreatureID`=128833 AND `ID`=1) OR (`CreatureID`=128839 AND `ID`=1) OR (`CreatureID`=128826 AND `ID`=1) OR (`CreatureID`=128828 AND `ID`=1) OR (`CreatureID`=128825 AND `ID`=1) OR (`CreatureID`=128834 AND `ID`=1) OR (`CreatureID`=128831 AND `ID`=1) OR (`CreatureID`=128829 AND `ID`=1) OR (`CreatureID`=128878 AND `ID`=1) OR (`CreatureID`=136310 AND `ID`=1) OR (`CreatureID`=136780 AND `ID`=1) OR (`CreatureID`=136782 AND `ID`=1) OR (`CreatureID`=136784 AND `ID`=1) OR (`CreatureID`=128794 AND `ID`=1) OR (`CreatureID`=128346 AND `ID`=1) OR (`CreatureID`=128853 AND `ID`=1) OR (`CreatureID`=128851 AND `ID`=1) OR (`CreatureID`=128748 AND `ID`=1) OR (`CreatureID`=128572 AND `ID`=1) OR (`CreatureID`=128573 AND `ID`=1) OR (`CreatureID`=128569 AND `ID`=1) OR (`CreatureID`=128570 AND `ID`=1) OR (`CreatureID`=128571 AND `ID`=1) OR (`CreatureID`=128575 AND `ID`=2) OR (`CreatureID`=128575 AND `ID`=1) OR (`CreatureID`=136629 AND `ID`=1) OR (`CreatureID`=128823 AND `ID`=1) OR (`CreatureID`=128830 AND `ID`=1) OR (`CreatureID`=136679 AND `ID`=1) OR (`CreatureID`=128822 AND `ID`=1) OR (`CreatureID`=136678 AND `ID`=1) OR (`CreatureID`=128802 AND `ID`=1) OR (`CreatureID`=128857 AND `ID`=1) OR (`CreatureID`=128824 AND `ID`=1) OR (`CreatureID`=128856 AND `ID`=1) OR (`CreatureID`=128860 AND `ID`=1) OR (`CreatureID`=128858 AND `ID`=1) OR (`CreatureID`=136622 AND `ID`=1) OR (`CreatureID`=128862 AND `ID`=1) OR (`CreatureID`=128855 AND `ID`=1) OR (`CreatureID`=128747 AND `ID`=1) OR (`CreatureID`=128758 AND `ID`=1) OR (`CreatureID`=128744 AND `ID`=1) OR (`CreatureID`=136621 AND `ID`=1) OR (`CreatureID`=128745 AND `ID`=1) OR (`CreatureID`=128871 AND `ID`=1) OR (`CreatureID`=128846 AND `ID`=1) OR (`CreatureID`=128861 AND `ID`=1) OR (`CreatureID`=128847 AND `ID`=1) OR (`CreatureID`=128789 AND `ID`=1) OR (`CreatureID`=128869 AND `ID`=1) OR (`CreatureID`=128841 AND `ID`=1) OR (`CreatureID`=128743 AND `ID`=1) OR (`CreatureID`=128741 AND `ID`=1) OR (`CreatureID`=128738 AND `ID`=1) OR (`CreatureID`=128739 AND `ID`=1) OR (`CreatureID`=128732 AND `ID`=1) OR (`CreatureID`=128736 AND `ID`=1) OR (`CreatureID`=128765 AND `ID`=1) OR (`CreatureID`=128733 AND `ID`=1) OR (`CreatureID`=128854 AND `ID`=1) OR (`CreatureID`=128820 AND `ID`=1) OR (`CreatureID`=136691 AND `ID`=1) OR (`CreatureID`=136693 AND `ID`=1) OR (`CreatureID`=128469 AND `ID`=1) OR (`CreatureID`=128755 AND `ID`=1) OR (`CreatureID`=128757 AND `ID`=1) OR (`CreatureID`=128766 AND `ID`=1) OR (`CreatureID`=128844 AND `ID`=1) OR (`CreatureID`=136309 AND `ID`=1) OR (`CreatureID`=128525 AND `ID`=1) OR (`CreatureID`=128527 AND `ID`=1) OR (`CreatureID`=128528 AND `ID`=1) OR (`CreatureID`=128530 AND `ID`=1) OR (`CreatureID`=128750 AND `ID`=1) OR (`CreatureID`=128832 AND `ID`=1) OR (`CreatureID`=136695 AND `ID`=1) OR (`CreatureID`=128835 AND `ID`=1) OR (`CreatureID`=128788 AND `ID`=1) OR (`CreatureID`=128724 AND `ID`=1) OR (`CreatureID`=128723 AND `ID`=1) OR (`CreatureID`=128762 AND `ID`=1) OR (`CreatureID`=128786 AND `ID`=1) OR (`CreatureID`=141780 AND `ID`=1) OR (`CreatureID`=128787 AND `ID`=1) OR (`CreatureID`=136595 AND `ID`=1) OR (`CreatureID`=142648 AND `ID`=1) OR (`CreatureID`=138124 AND `ID`=1) OR (`CreatureID`=138126 AND `ID`=1) OR (`CreatureID`=138127 AND `ID`=1) OR (`CreatureID`=138395 AND `ID`=1) OR (`CreatureID`=135326 AND `ID`=1) OR (`CreatureID`=135311 AND `ID`=1) OR (`CreatureID`=128763 AND `ID`=1) OR (`CreatureID`=128764 AND `ID`=1) OR (`CreatureID`=128760 AND `ID`=1) OR (`CreatureID`=131378 AND `ID`=1) OR (`CreatureID`=125904 AND `ID`=1) OR (`CreatureID`=128716 AND `ID`=1) OR (`CreatureID`=128753 AND `ID`=1) OR (`CreatureID`=128717 AND `ID`=1) OR (`CreatureID`=128714 AND `ID`=1) OR (`CreatureID`=128715 AND `ID`=1) OR (`CreatureID`=128866 AND `ID`=1) OR (`CreatureID`=128868 AND `ID`=1) OR (`CreatureID`=128453 AND `ID`=1) OR (`CreatureID`=128850 AND `ID`=1) OR (`CreatureID`=128864 AND `ID`=1) OR (`CreatureID`=128865 AND `ID`=1) OR (`CreatureID`=128873 AND `ID`=1) OR (`CreatureID`=128872 AND `ID`=1) OR (`CreatureID`=128801 AND `ID`=1) OR (`CreatureID`=128870 AND `ID`=1) OR (`CreatureID`=128796 AND `ID`=1) OR (`CreatureID`=128795 AND `ID`=1) OR (`CreatureID`=140567 AND `ID`=1) OR (`CreatureID`=140888 AND `ID`=1) OR (`CreatureID`=135286 AND `ID`=1) OR (`CreatureID`=128660 AND `ID`=1) OR (`CreatureID`=128664 AND `ID`=1) OR (`CreatureID`=128661 AND `ID`=1) OR (`CreatureID`=134638 AND `ID`=1) OR (`CreatureID`=128662 AND `ID`=1) OR (`CreatureID`=129202 AND `ID`=1) OR (`CreatureID`=129224 AND `ID`=1) OR (`CreatureID`=124832 AND `ID`=1) OR (`CreatureID`=129011 AND `ID`=1) OR (`CreatureID`=129014 AND `ID`=1) OR (`CreatureID`=142313 AND `ID`=1) OR (`CreatureID`=129004 AND `ID`=1) OR (`CreatureID`=134321 AND `ID`=1) OR (`CreatureID`=134320 AND `ID`=1) OR (`CreatureID`=128665 AND `ID`=1) OR (`CreatureID`=129008 AND `ID`=1) OR (`CreatureID`=129007 AND `ID`=1) OR (`CreatureID`=136545 AND `ID`=1) OR (`CreatureID`=141597 AND `ID`=1) OR (`CreatureID`=136546 AND `ID`=1) OR (`CreatureID`=134121 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(127025, 1, 110032, 0, 0, 110032, 0, 0, 0, 0, 0), -- Pirate-King Zem'lan
(128646, 1, 94104, 0, 0, 0, 0, 0, 0, 0, 0), -- Vision of Ugly Zul
(128640, 1, 94215, 0, 0, 94192, 0, 0, 0, 0, 0), -- Vision of Basher Hak'anjin
(128641, 1, 94215, 0, 0, 94215, 0, 0, 0, 0, 0), -- Vision of Bos'n Sno
(128642, 1, 0, 0, 0, 0, 0, 0, 94101, 0, 0), -- Vision of Hula'mon
(128643, 1, 94215, 0, 0, 0, 0, 0, 0, 0, 0), -- Vision of Quartermaster Gran
(128644, 1, 94104, 0, 0, 0, 0, 0, 0, 0, 0), -- Vision of Sezza
(136785, 2, 155295, 0, 0, 0, 0, 0, 0, 0, 0), -- Quartermaster Tulmac
(136466, 1, 153290, 0, 0, 0, 0, 0, 0, 0, 0), -- Goldslave
(128843, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Zulashi
(136785, 1, 2705, 0, 0, 0, 0, 0, 0, 0, 0), -- Quartermaster Tulmac
(136781, 1, 0, 0, 0, 0, 0, 0, 94101, 0, 0), -- Gunner Bosanya
(136783, 1, 155277, 0, 0, 155277, 0, 0, 0, 0, 0), -- Jukanga the Snitch
(136779, 1, 116454, 0, 0, 0, 0, 0, 0, 0, 0), -- First Mate Jamboya
(128557, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Stormbringer
(128840, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Lookout Gronula
(136689, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Gunner Khudal
(128845, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Gunner Zol'jabu
(128299, 1, 144164, 0, 0, 0, 0, 0, 0, 0, 0), -- Captain Gulnaku
(128793, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Tamer Zalo'bin
(128827, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Lookout Kuzu'juzu
(128749, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Warguard
(128791, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Basher Hak'anjin
(128800, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Tamer Gonja
(136673, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Tamer Dukazi
(136446, 1, 116573, 0, 0, 0, 0, 0, 127533, 0, 0), -- Master Gunner Torwec
(136680, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Gunner Sumanko
(128859, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Master Bos'n Maalzahn
(128833, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Shiny Benyani
(128839, 1, 155295, 0, 0, 155295, 0, 0, 0, 0, 0), -- Khulena the Mute
(128826, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Blindeye Gwanma
(128828, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Kuzzambi of the Deep
(128825, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Rigger Balajai
(128834, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Tonga the Frisk
(128831, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Seshu the Slave
(128829, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Kwanuhna the Scavenger
(128878, 1, 144164, 0, 0, 0, 0, 0, 0, 0, 0), -- Zenanju
(136310, 1, 116454, 0, 0, 0, 0, 0, 0, 0, 0), -- First Mate Jamboya
(136780, 1, 0, 0, 0, 0, 0, 0, 94101, 0, 0), -- Gunner Bosanya
(136782, 1, 155277, 0, 0, 155277, 0, 0, 0, 0, 0), -- Jukanga the Snitch
(136784, 1, 155295, 0, 0, 0, 0, 0, 0, 0, 0), -- Quartermaster Tulmac
(128794, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Lookout Jumgan
(128346, 1, 84788, 0, 0, 0, 0, 0, 0, 0, 0), -- Quartermaster Boonzali
(128853, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Vujaca the Greaser
(128851, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Captain Ghun'tha
(128748, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Quartermaster Gran
(128572, 1, 94215, 0, 0, 94215, 0, 0, 0, 0, 0), -- Vision of Druga
(128573, 1, 94104, 0, 0, 0, 0, 0, 0, 0, 0), -- Vision of Witchdoctor Unnraz
(128569, 1, 94215, 0, 0, 94192, 0, 0, 0, 0, 0), -- Vision of Basher Nujia
(128570, 1, 94215, 0, 0, 0, 0, 0, 0, 0, 0), -- Vision of Tayusha
(128571, 1, 94104, 0, 0, 0, 0, 0, 0, 0, 0), -- Vision of Witchdoctor Zuwei
(128575, 2, 156877, 0, 0, 151334, 0, 0, 0, 0, 0), -- Vision of Faithless Invader
(128575, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Vision of Faithless Invader
(136629, 1, 155277, 0, 0, 155277, 0, 0, 0, 0, 0), -- Jukanga the Snitch
(128823, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Jublaya Four-Fingers
(128830, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Mugambi
(136679, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Gunner Navo
(128822, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Rigger Unjaazi
(136678, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Gunner Rawalu
(128802, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Tamer Sejuuma
(128857, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Xu'nanji
(128824, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Zalnon'mak
(128856, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Hagglin' Senjilak
(128860, 1, 87562, 0, 0, 0, 0, 0, 0, 0, 0), -- Master Bos'n Segazea
(128858, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- Lazy Tzushu
(136622, 1, 0, 0, 0, 0, 0, 0, 94101, 0, 0), -- Gunner Bosanya
(128862, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Smuggler Hemalu
(128855, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Zununbar
(128747, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Patches
(128758, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Lookout Ungalra
(128744, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Jammo
(136621, 1, 155295, 0, 0, 0, 0, 0, 0, 0, 0), -- Quartermaster Tulmac
(128745, 1, 155295, 0, 0, 155295, 0, 0, 0, 0, 0), -- Oggo the Peddler
(128871, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Master Gunner Nahkek
(128846, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Quartermaster Anji'zari
(128861, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Navigator Roka'kan
(128847, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Quartermaster Tasunya
(128789, 1, 2703, 0, 0, 116573, 0, 0, 0, 0, 0), -- Zulazi
(128869, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Coxswain Growna
(128841, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Navigator Haantha
(128743, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Sek'thun
(128741, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Blackeye Gunt
(128738, 1, 155295, 0, 0, 155295, 0, 0, 0, 0, 0), -- Useless Krak
(128739, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Vinchanta the Unsteady
(128732, 1, 94740, 0, 0, 0, 0, 0, 0, 0, 0), -- Innkeeper Rakakan
(128736, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Navigator Rama'xu
(128765, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Hana'shi
(128733, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Kana
(128854, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Yahlwei
(128820, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Inspector Gan'wam
(136691, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Toe-Taker Jakko
(136693, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Sacker Bhatgo
(128469, 1, 94121, 0, 0, 0, 0, 0, 0, 0, 0), -- First Mate Drakul
(128755, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Lookout Ronaku
(128757, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Lookout Sezza
(128766, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Nim'ra the Facestomper
(128844, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Lookout Gol'thuwa
(136309, 1, 116454, 0, 0, 0, 0, 0, 0, 0, 0), -- First Mate Jamboya
(128525, 1, 0, 0, 0, 0, 0, 0, 94101, 0, 0), -- Vision of Shredder Ungalra
(128527, 1, 94215, 0, 0, 94192, 0, 0, 0, 0, 0), -- Vision of Vor'sul
(128528, 1, 94215, 0, 0, 94215, 0, 0, 0, 0, 0), -- Vision of Ronaku
(128530, 1, 94720, 0, 0, 0, 0, 0, 0, 0, 0), -- Vision of Pirate-King Zem'lan
(128750, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Lookout Rakana
(128832, 1, 118027, 0, 0, 0, 0, 0, 0, 0, 0), -- Shaky Ragnan
(136695, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Navigator Vocawa
(128835, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Bos'n Tayadur
(128788, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Zuk'su
(128724, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Thunka
(128723, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Grunka
(128762, 1, 87562, 0, 0, 0, 0, 0, 0, 0, 0), -- Bonebender Shu'mu
(128786, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Robba Klobba
(141780, 1, 2178, 0, 0, 143, 0, 0, 0, 0, 0), -- 7th Legion Guardsman
(128787, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Umbo the Sneak
(136595, 1, 110049, 0, 0, 110049, 0, 0, 0, 0, 0), -- Taz'raka the Traitor
(142648, 1, 160451, 0, 0, 0, 0, 0, 0, 0, 0), -- Zandalari Exile
(138124, 1, 52528, 0, 0, 52528, 0, 0, 0, 0, 0), -- Mojambo
(138126, 1, 52528, 0, 0, 52528, 0, 0, 0, 0, 0), -- Zandalari Exile
(138127, 1, 107963, 0, 0, 0, 0, 0, 0, 0, 0), -- Zandalari Exile
(138395, 1, 2064, 0, 0, 0, 0, 0, 0, 0, 0), -- Scorched Sands Outcast
(135326, 1, 52528, 0, 0, 52528, 0, 0, 0, 0, 0), -- Tongo
(135311, 1, 107963, 0, 0, 0, 0, 0, 0, 0, 0), -- Zandalari Exile
(128763, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Bos'n Sno
(128764, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Ugly Zul
(128760, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Lookout Vor'sul
(131378, 1, 88553, 0, 0, 0, 0, 0, 0, 0, 0), -- Romu
(125904, 1, 102240, 0, 0, 102240, 0, 0, 0, 0, 0), -- Norah
(128716, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Lazy Ranson
(128753, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Kulaka the Sharp
(128717, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Xon'ke the Scavenger
(128714, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Kuntho
(128715, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Ninsan
(128866, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Cutthroat Dubsun
(128868, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Bun'zia the Hacker
(128453, 1, 94740, 0, 0, 0, 0, 0, 0, 0, 0), -- Witchdoctor Yoksa
(128850, 1, 94740, 0, 0, 0, 0, 0, 0, 0, 0), -- Apprentice Valin'ini
(128864, 1, 87562, 0, 0, 0, 0, 0, 0, 0, 0), -- Bonebender Sun'la
(128865, 1, 87562, 0, 0, 0, 0, 0, 0, 0, 0), -- Bonebender Wonashi
(128873, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- First Mate Kiffa
(128872, 1, 155277, 0, 0, 0, 0, 0, 39487, 0, 0), -- Captain Zhonga
(128801, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Tamer Khuwaza
(128870, 1, 155277, 0, 0, 0, 0, 0, 155275, 0, 0), -- Master Gunner Garna
(128796, 1, 116573, 0, 0, 116573, 0, 0, 0, 0, 0), -- Hula'mon
(128795, 1, 93648, 0, 0, 93648, 0, 0, 0, 0, 0), -- Cook Shak'mak
(140567, 1, 0, 0, 0, 12743, 0, 0, 0, 0, 0), -- Arlethal Sunwatcher
(140888, 1, 160846, 0, 0, 0, 0, 0, 0, 0, 0), -- Reconfigulator Repair-Goblin
(135286, 1, 160846, 0, 0, 0, 0, 0, 0, 0, 0), -- Bilgewater Miner
(128660, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Aggressor
(128664, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Sentry
(128661, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Ravager
(134638, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Warlord Zothix
(128662, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Warden
(129202, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Temple Defender
(129224, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(124832, 1, 95790, 0, 0, 94194, 0, 0, 0, 0, 0), -- Warguard Rakera
(129011, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Temple Defender
(129014, 1, 2827, 0, 0, 0, 0, 0, 0, 0, 0), -- Hessir
(142313, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Temple Defender
(129004, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Temple Defender
(134321, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Aggressor
(134320, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Ravager
(128665, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Skycaller
(129008, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Faithless Sandscout
(129007, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Sentry
(136545, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Ravager
(141597, 1, 160451, 0, 0, 0, 0, 0, 0, 0, 0), -- Zandalari Exile
(136546, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Warden
(134121, 1, 157852, 0, 0, 157852, 0, 0, 0, 0, 0); -- Overseer Nerzet


DELETE FROM `gossip_menu` WHERE (`MenuId`=21389 AND `TextId`=32766) OR (`MenuId`=21390 AND `TextId`=32767) OR (`MenuId`=22536 AND `TextId`=34672) OR (`MenuId`=22534 AND `TextId`=34539) OR (`MenuId`=22487 AND `TextId`=34671) OR (`MenuId`=22488 AND `TextId`=34538) OR (`MenuId`=21497 AND `TextId`=32760) OR (`MenuId`=21496 AND `TextId`=32759) OR (`MenuId`=21470 AND `TextId`=32704) OR (`MenuId`=21469 AND `TextId`=32703) OR (`MenuId`=21520 AND `TextId`=32799) OR (`MenuId`=21521 AND `TextId`=32800) OR (`MenuId`=21468 AND `TextId`=32702) OR (`MenuId`=21946 AND `TextId`=33574) OR (`MenuId`=23188 AND `TextId`=35871) OR (`MenuId`=22707 AND `TextId`=35099) OR (`MenuId`=23275 AND `TextId`=36069) OR (`MenuId`=21306 AND `TextId`=33314) OR (`MenuId`=21094 AND `TextId`=33303) OR (`MenuId`=21797 AND `TextId`=33309) OR (`MenuId`=21725 AND `TextId`=33099) OR (`MenuId`=22325 AND `TextId`=34263) OR (`MenuId`=22324 AND `TextId`=34262) OR (`MenuId`=22322 AND `TextId`=34261) OR (`MenuId`=22323 AND `TextId`=34260) OR (`MenuId`=22315 AND `TextId`=33320) OR (`MenuId`=21724 AND `TextId`=33098) OR (`MenuId`=21763 AND `TextId`=33232) OR (`MenuId`=21754 AND `TextId`=33191) OR (`MenuId`=21385 AND `TextId`=32578) OR (`MenuId`=21437 AND `TextId`=32860) OR (`MenuId`=22683 AND `TextId`=35030) OR (`MenuId`=21306 AND `TextId`=32362);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(21389, 32766, 27843), -- 123811 (Vigori)
(21390, 32767, 27843), -- 125904 (Norah)
(22536, 34672, 27843), -- 136317 (Cursed Skeleton)
(22534, 34539, 27843), -- 136779 (First Mate Jamboya)
(22487, 34671, 27843), -- 136310 (First Mate Jamboya)
(22488, 34538, 27843), -- 136309 (First Mate Jamboya)
(21497, 32760, 27843), -- 127032 (Junji)
(21496, 32759, 27843), -- 276187
(21470, 32704, 27843), -- 126108 (Sezahjin)
(21469, 32703, 27843), -- 126085 (Mugjabu)
(21520, 32799, 27843), -- 126085 (Mugjabu)
(21521, 32800, 27843), -- 126108 (Sezahjin)
(21468, 32702, 27843), -- 126576 (Razgaji)
(21946, 33574, 27843), -- 131378 (Romu)
(23188, 35871, 27843), -- 139792 (Ta'mil Nadu)
(22707, 35099, 27843), -- 135180 (Nerin Solvis)
(23275, 36069, 27843), -- 135400 (Jenoh)
(21306, 33314, 27843), -- 129260
(21094, 33303, 27843), -- Bladeguard Kaja
(21797, 33309, 27843), -- Vorrik
(21725, 33099, 27843), -- 128697 (Zeriph)
(22325, 34263, 27843), -- 128688 (Sorin)
(22324, 34262, 27843), -- 128688 (Sorin)
(22322, 34261, 27843), -- 128688 (Sorin)
(22323, 34260, 27843), -- 128688 (Sorin)
(22315, 33320, 27843), -- 128688 (Sorin)
(21724, 33098, 27843), -- 128693 (Issik)
(21763, 33232, 27843), -- 129521 (Hezzil)
(21754, 33191, 27843), -- 129014 (Hessir)
(21385, 32578, 27843), -- 134162
(21437, 32860, 27843), -- 128807
(22683, 35030, 27843), -- 135154
(21306, 32362, 27843); -- 129260

UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=11919 AND `TextId`=16734); -- 0
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=21470 AND `OptionIndex`=1) OR (`MenuId`=21470 AND `OptionIndex`=0) OR (`MenuId`=21469 AND `OptionIndex`=0) OR (`MenuId`=21468 AND `OptionIndex`=0) OR (`MenuId`=23275 AND `OptionIndex`=1) OR (`MenuId`=21797 AND `OptionIndex`=1) OR (`MenuId`=21725 AND `OptionIndex`=0) OR (`MenuId`=22325 AND `OptionIndex`=0) OR (`MenuId`=22324 AND `OptionIndex`=1) OR (`MenuId`=22324 AND `OptionIndex`=0) OR (`MenuId`=22322 AND `OptionIndex`=1) OR (`MenuId`=22322 AND `OptionIndex`=0) OR (`MenuId`=22323 AND `OptionIndex`=1) OR (`MenuId`=22323 AND `OptionIndex`=0) OR (`MenuId`=22315 AND `OptionIndex`=0) OR (`MenuId`=21724 AND `OptionIndex`=1) OR (`MenuId`=21724 AND `OptionIndex`=0) OR (`MenuId`=21754 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(21470, 1, 1, 'I wish to buy from you.', 25568, 27843),
(21470, 0, 0, 'How did you end up in Vol\'dun?', 136903, 27843),
(21469, 0, 0, 'How did you end up in Vol\'dun?', 136905, 27843),
(21468, 0, 0, 'I\'m ready. Let\'s go.', 155198, 27843),
(23275, 1, 1, 'I wish to buy from you.', 14979, 27843),
(21797, 1, 0, '<Give Vorrik Sulthis\' Stone.>', 148354, 27843),
(21725, 0, 1, 'Can you repair equipment?', 143334, 27843),
(22325, 0, 0, 'What else can you tell me?', 140441, 27843),
(22324, 1, 0, 'What else can you tell me?', 140441, 27843),
(22324, 0, 0, 'Who are the Keepers?', 140743, 27843),
(22322, 1, 0, 'What else can you tell me?', 140441, 27843),
(22322, 0, 0, 'Who is Korthek?', 140738, 27843),
(22323, 1, 0, 'What else can you tell me?', 140441, 27843),
(22323, 0, 0, 'Who are the Faithless?', 140439, 27843),
(22315, 0, 0, 'Who is Sethraliss?', 140740, 27843),
(21724, 1, 1, 'Let me browse your goods.', 8097, 27843),
(21724, 0, 5, 'Make this inn your home.', 162070, 27843),
(21754, 0, 3, 'Train me.', 3266, 27843);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=21469 AND `OptionIndex`=0) OR (`MenuId`=21470 AND `OptionIndex`=0) OR (`MenuId`=22324 AND `OptionIndex`=0) OR (`MenuId`=22322 AND `OptionIndex`=0) OR (`MenuId`=22323 AND `OptionIndex`=0) OR (`MenuId`=22315 AND `OptionIndex`=0) OR (`MenuId`=22323 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(21469, 0, 21520, 0),
(21470, 0, 21521, 0),
(22324, 0, 22325, 0),
(22322, 0, 22324, 1),
(22323, 0, 22322, 1),
(22315, 0, 22323, 0),
(22323, 1, 22315, 1);


DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=21754 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(21754, 0, 858);



UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130999; -- Voracious Hammerhead
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67143680 WHERE `entry`=136778; -- Jamboya's Boat
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=127025; -- Pirate-King Zem'lan
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `speed_run`=5.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048, `VehicleId`=5628 WHERE `entry`=128613; -- Zem'lan's Boat
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=5629 WHERE `entry`=128615; -- Zem'lan's Boat Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128633; -- Vision of First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128646; -- Vision of Ugly Zul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128640; -- Vision of Basher Hak'anjin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128641; -- Vision of Bos'n Sno
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128642; -- Vision of Hula'mon
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128643; -- Vision of Quartermaster Gran
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128644; -- Vision of Sezza
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128645; -- Vision of Sulazi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67143680 WHERE `entry`=136951; -- Jamboya's Boat
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=123183; -- (Bunny)
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=136472; -- Animated Treasure
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=31, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136487; -- Goldeater
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136466; -- Goldslave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_walk`=1.2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=34816, `VehicleId`=6300 WHERE `entry`=136954; -- Jamboya's Boat Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130997; -- Sandshell Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128843; -- Zulashi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128300; -- Lifeboat
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=136785; -- Quartermaster Tulmac
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136781; -- Gunner Bosanya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=136783; -- Jukanga the Snitch
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=136779; -- First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=119, `maxlevel`=119, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=18432, `dynamicflags`=128 WHERE `entry`=135449; -- Sethrak War Banner
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128557; -- Sethrak Stormbringer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128497; -- Bajiani the Slick
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128840; -- Lookout Gronula
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136689; -- Gunner Khudal
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128845; -- Gunner Zol'jabu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16448, `unit_flags2`=2048 WHERE `entry`=128299; -- Captain Gulnaku
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=128793; -- Tamer Zalo'bin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128827; -- Lookout Kuzu'juzu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128749; -- Sethrak Warguard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128791; -- Basher Hak'anjin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128800; -- Tamer Gonja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136673; -- Tamer Dukazi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=136446; -- Master Gunner Torwec
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136680; -- Gunner Sumanko
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128859; -- Master Bos'n Maalzahn
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128833; -- Shiny Benyani
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128839; -- Khulena the Mute
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128826; -- Blindeye Gwanma
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=128588; -- Stoneshell Sea Turtle
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128828; -- Kuzzambi of the Deep
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128825; -- Rigger Balajai
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128834; -- Tonga the Frisk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128831; -- Seshu the Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128829; -- Kwanuhna the Scavenger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67143680 WHERE `entry`=136773; -- Jamboya's Boat
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=128878; -- Zenanju
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=136310; -- First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136780; -- Gunner Bosanya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=136782; -- Jukanga the Snitch
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=136784; -- Quartermaster Tulmac
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=136320; -- (Bunny) Pillaging Canoe
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_walk`=1.2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=34816, `VehicleId`=5935 WHERE `entry`=136774; -- Jamboya's Boat Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=123481; -- Riverbeast Guardian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128794; -- Lookout Jumgan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128346; -- Quartermaster Boonzali
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128853; -- Vujaca the Greaser
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128851; -- Captain Ghun'tha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128748; -- Quartermaster Gran
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128548; -- Vision of First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128572; -- Vision of Druga
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128573; -- Vision of Witchdoctor Unnraz
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128569; -- Vision of Basher Nujia
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128570; -- Vision of Tayusha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128571; -- Vision of Witchdoctor Zuwei
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128575; -- Vision of Faithless Invader
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=136629; -- Jukanga the Snitch
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=136648; -- (Bunny) Battlefield Flashback
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128823; -- Jublaya Four-Fingers
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128830; -- Mugambi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136679; -- Gunner Navo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125299; -- Soultainted Cobra
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128822; -- Rigger Unjaazi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136678; -- Gunner Rawalu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128802; -- Tamer Sejuuma
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128857; -- Xu'nanji
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128824; -- Zalnon'mak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128856; -- Hagglin' Senjilak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128860; -- Master Bos'n Segazea
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128858; -- Lazy Tzushu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136622; -- Gunner Bosanya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128862; -- Smuggler Hemalu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128454; -- Da Cabin Boy
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128855; -- Zununbar
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=136441; -- Jukanga the Snitch
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128747; -- Patches
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128758; -- Lookout Ungalra
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128744; -- Jammo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=136621; -- Quartermaster Tulmac
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128745; -- Oggo the Peddler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128871; -- Master Gunner Nahkek
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136434; -- Quartermaster Tulmac
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136435; -- Gunner Bosanya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128846; -- Quartermaster Anji'zari
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128861; -- Navigator Roka'kan
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=136642; -- (Bunny) Throne Room Flashback
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128847; -- Quartermaster Tasunya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128789; -- Zulazi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128869; -- Coxswain Growna
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128841; -- Navigator Haantha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128743; -- Sek'thun
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128741; -- Blackeye Gunt
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128738; -- Useless Krak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128739; -- Vinchanta the Unsteady
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128732; -- Innkeeper Rakakan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128736; -- Navigator Rama'xu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128765; -- Hana'shi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128733; -- Kana
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128297; -- Zul the Cuddly
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128854; -- Yahlwei
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128820; -- Inspector Gan'wam
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136691; -- Toe-Taker Jakko
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136693; -- Sacker Bhatgo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128469; -- First Mate Drakul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128755; -- Lookout Ronaku
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128757; -- Lookout Sezza
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128766; -- Nim'ra the Facestomper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128368; -- Captured Vulpera
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128844; -- Lookout Gol'thuwa
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=136309; -- First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136583; -- First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=136543; -- Vision of First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128525; -- Vision of Shredder Ungalra
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128527; -- Vision of Vor'sul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128520; -- Vision of Kejina
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128516; -- Vision of Jumash
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128517; -- Vision of Jumju
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128518; -- Vision of Taiani
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128519; -- Vision of Vulnullu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128515; -- Vision of Muzingi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128528; -- Vision of Ronaku
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128530; -- Vision of Pirate-King Zem'lan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128750; -- Lookout Rakana
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128832; -- Shaky Ragnan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2753, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=128523; -- Souldrained Refugee
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2753, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=128522; -- Souldrained Refugee
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136695; -- Navigator Vocawa
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=128835; -- Bos'n Tayadur
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128788; -- Zuk'su
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=123489; -- Riverbeast Calf
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130996; -- Sandshell Sea Turtle
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129283; -- Jumbo Sandsnapper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=136287; -- Meeki
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600 WHERE `entry`=128261; -- First Mate Jamboya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2832, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125082; -- Frenzied Thresher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128724; -- Thunka
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128723; -- Grunka
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128762; -- Bonebender Shu'mu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128786; -- Robba Klobba
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=144462; -- Spikeshell Scuttler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2774, `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=141780; -- 7th Legion Guardsman
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128787; -- Umbo the Sneak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=16779264 WHERE `entry`=124567; -- Sand Scuttler
UPDATE `creature_template` SET `gossip_menu_id`=21497, `minlevel`=5, `maxlevel`=5, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=127032; -- Junji
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=135483; -- Alpaca
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126643; -- Snarlfang Hyena
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=127776; -- Scaleclaw Broodmother
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=136354; -- Alpaca
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=124591; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=136595; -- Taz'raka the Traitor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=7, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=18432 WHERE `entry`=123535; -- Rickety Plank
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=142648; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `VehicleId`=6235 WHERE `entry`=142647; -- Vehicle Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=2048 WHERE `entry`=138124; -- Mojambo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=2048 WHERE `entry`=138126; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=138127; -- Zandalari Exile
UPDATE `creature_template` SET `gossip_menu_id`=21470, `minlevel`=110, `maxlevel`=110, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=126108; -- Sezahjin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126984; -- Scaleclaw Saurolisk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=32768 WHERE `entry`=138910; -- Julwaba
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=121541; -- Ban-Lu
UPDATE `creature_template` SET `gossip_menu_id`=11919, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=65665, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135655; -- Mozesha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=136389; -- Xombo
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=125862; -- Zauljin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=127578; -- Taz'jin
UPDATE `creature_template` SET `gossip_menu_id`=21469, `minlevel`=116, `maxlevel`=116, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=126085; -- Mugjabu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=138395; -- Scorched Sands Outcast
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=135326; -- Tongo
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=135333; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135338; -- Gnarl
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135339; -- Snarl
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555264, `unit_flags2`=67110912, `VehicleId`=5879 WHERE `entry`=97052; -- Elothir
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135311; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128763; -- Bos'n Sno
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128764; -- Ugly Zul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128760; -- Lookout Vor'sul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=128237; -- Souldrained Refugee
UPDATE `creature_template` SET `gossip_menu_id`=21946, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=131378; -- Romu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=123811; -- Vigori
UPDATE `creature_template` SET `gossip_menu_id`=21390, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=125904; -- Norah
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=127053; -- Ahna
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128716; -- Lazy Ranson
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128711; -- Gentle Guntha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128753; -- Kulaka the Sharp
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128717; -- Xon'ke the Scavenger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128714; -- Kuntho
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128253; -- Captured Tiger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128715; -- Ninsan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128251; -- Sedated Saurolisk Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=31, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128252; -- Captured Beetle
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128866; -- Cutthroat Dubsun
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128868; -- Bun'zia the Hacker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128453; -- Witchdoctor Yoksa
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128850; -- Apprentice Valin'ini
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=294912, `unit_flags2`=2048 WHERE `entry`=128351; -- Subdued Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128864; -- Bonebender Sun'la
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128865; -- Bonebender Wonashi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128873; -- First Mate Kiffa
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128872; -- Captain Zhonga
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128801; -- Tamer Khuwaza
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=131072, `unit_flags3`=17 WHERE `entry`=128287; -- Tiki Target
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2753, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=125310; -- Souldrained Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128870; -- Master Gunner Garna
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128348; -- Mindless Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=124560; -- Slaughtered Vulpera
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128796; -- Hula'mon
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2753, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=128564; -- Souldrained Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2753, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=128197; -- Souldrained Invader
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2753, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=128565; -- Souldrained Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=124811; -- Scorpashi Bladetail
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128795; -- Cook Shak'mak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122790; -- Bonebeak Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=31, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128404; -- Shackled Beetle
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2164736, `VehicleId`=6066 WHERE `entry`=139773; -- Big Mama
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=142895; -- Golden Lash
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=139775; -- Sand Funnel
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=69240832 WHERE `entry`=139492; -- Caromzar Cactus
UPDATE `creature_template` SET `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=143377; -- Lectric Frequency Modulator
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=135349; -- Enraged Azermental
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=136338; -- Sirokar
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=18433, `unit_flags3`=8192 WHERE `entry`=139772; -- Ridge Lasher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=714, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=140046; -- Rozzy
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537166080, `unit_flags2`=67110913, `unit_flags3`=8192 WHERE `entry`=139982; -- Ridge Lashlet
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67141632, `unit_flags3`=1 WHERE `entry`=139989; -- Charging Circuit
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=139569; -- Captive Ranishu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=139929; -- Cracked Pricklevine
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=106, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=140567; -- Arlethal Sunwatcher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=106, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=140888; -- Reconfigulator Repair-Goblin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=106, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=140530; -- Abrasive Reconfigulator 8000
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=7, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=2 WHERE `entry`=144610; -- Silverskin Remora
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=144611; -- Coralback Scuttler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=714, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135179; -- Merd Archfeld
UPDATE `creature_template` SET `gossip_menu_id`=22707, `minlevel`=120, `maxlevel`=120, `faction`=714, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135180; -- Nerin Solvis
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1933, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=135269; -- Abrasive Reconfigulator 8000
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2136, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=144245; -- South Sea Glider
UPDATE `creature_template` SET `gossip_menu_id`=23188, `minlevel`=120, `maxlevel`=120, `faction`=2028, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=139792; -- Ta'mil Nadu
UPDATE `creature_template` SET `faction`=31, `npcflag`=1073741824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=143056; -- Hermit Crab
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135286; -- Bilgewater Miner
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `dynamicflags`=128 WHERE `entry`=139114; -- Dense Stone
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67141632, `unit_flags3`=1 WHERE `entry`=135232; -- Cleaner Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=140051; -- Strand Cobra Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=140050; -- Territorial Hydra
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136225; -- Sirocite
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=141755; -- Ridge Skimmer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=69238784, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=135080; -- Target
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135006; -- Siroccan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_walk`=3.6, `speed_run`=2.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143213; -- Ridge Runner
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_walk`=3.6, `speed_run`=2.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143212; -- Wiley
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=25, `faction`=188, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141969; -- Spineleaf
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=141720; -- Ridge Crawler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135084; -- Strand Cobra Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139071; -- Bonebeak Buzzard
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=129257; -- Sulthis' Keystone
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128694; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=134595; -- Zissiah
UPDATE `creature_template` SET `gossip_menu_id`=21797, `minlevel`=108, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129519; -- Vorrik
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129518; -- Serrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130023; -- Saltscale Calf
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130022; -- Saltscale Riverbeast
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128660; -- Faithless Aggressor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128664; -- Faithless Sentry
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128661; -- Faithless Ravager
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=134638; -- Warlord Zothix
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128961; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128662; -- Faithless Warden
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2628, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=51200, `unit_flags3`=1 WHERE `entry`=129076; -- Sethrak Cannon
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2299, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=129202; -- Temple Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2968, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=144353; -- Collector Kojo
UPDATE `creature_template` SET `gossip_menu_id`=9821, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=129, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139827; -- Vithur
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=8192, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128695; -- Vethiss
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=139075; -- Vorrik's Keystone
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129224; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=120, `faction`=2361, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=124832; -- Warguard Rakera
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128687; -- Serrik
UPDATE `creature_template` SET `gossip_menu_id`=21725, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=4225, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128697; -- Zeriph
UPDATE `creature_template` SET `gossip_menu_id`=21724, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=65665, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128693; -- Issik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33554432 WHERE `entry`=129011; -- Temple Defender
UPDATE `creature_template` SET `gossip_menu_id`=22325, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128688; -- Sorin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128696; -- Zissiah
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=134613; -- Zareen
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=129216; -- Faithless Warbringer
UPDATE `creature_template` SET `gossip_menu_id`=21763, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129521; -- Hezzil
UPDATE `creature_template` SET `gossip_menu_id`=21754, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=81, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129014; -- Hessir
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128692; -- Ikoriss
UPDATE `creature_template` SET `gossip_menu_id`=21763, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128689; -- Sissok
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141945; -- Sizzik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2299, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=142313; -- Temple Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=125098; -- Cove Seagull
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=143454; -- Taz
UPDATE `creature_template` SET `gossip_menu_id`=23275, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=131, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135400; -- Jenoh
UPDATE `creature_template` SET `faction`=31, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=130077; -- Hermit Crab
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124716; -- Alpaca Alpha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124522; -- Alpaca
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=31, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124718; -- Alpaca Calf
UPDATE `creature_template` SET `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=137402; -- Pygmy Crab
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136144; -- Atrivax Lashlet
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136109; -- Atrivax Lasher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2299, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=129004; -- Temple Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130042; -- Stoneclaw Crab
UPDATE `creature_template` SET `faction`=2575, `speed_walk`=0.28, `speed_run`=0.1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136986; -- Sandshell Turtle
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134321; -- Faithless Aggressor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134320; -- Faithless Ravager
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128665; -- Faithless Skycaller
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139072; -- Bonebeak Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129008; -- Faithless Sandscout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129007; -- Faithless Sentry
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136548; -- War Krolusk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136545; -- Sethrak Ravager
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=141597; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136546; -- Sethrak Warden
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137556; -- Vulpera Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=123473; -- Faithless Trapper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133888; -- Whistlebloom Hunter
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126627; -- Lost Alpaca
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126645; -- Vol'duni Dunecrawler
UPDATE `creature_template` SET `gossip_menu_id`=21468, `minlevel`=117, `maxlevel`=117, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=126576; -- Razgaji
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=2980, `npcflag`=8192, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135654; -- Makaanji
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048 WHERE `entry`=134292; -- Sulthis
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=126817; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=127152; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=134121; -- Overseer Nerzet
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67684352, `unit_flags3`=128 WHERE `entry`=134090; -- Keeper Sulthis
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67667968, `unit_flags3`=128 WHERE `entry`=134067; -- Keeper Vorrik
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=136340; -- Relic Hunter Hazaak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2028, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=32768 WHERE `entry`=134533; -- Serrik
UPDATE `creature_template` SET `gossip_menu_id`=21437 WHERE `entry`=128807; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=131072, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=126712; -- Training Dummy
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2952, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137332; -- Scorpashi Duneclaw
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124810; -- Scorpid Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=134164; -- Amre
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67160064, `dynamicflags`=128 WHERE `entry`=134245; -- Scepter of Prescience
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67141632, `unit_flags3`=1 WHERE `entry`=134314; -- Ring Creature
UPDATE `creature_template` SET `minlevel`=119, `maxlevel`=119 WHERE `entry`=134532; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=22683 WHERE `entry`=135154; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21306 WHERE `entry`=129260; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21094 WHERE `entry`=128316; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=134148; -- Maaz
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=139082; -- Raze
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=139083; -- Nephy
UPDATE `creature_template` SET `faction`=2832 WHERE `entry`=125882; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=126893; -- -Unknown-

DELETE FROM `quest_template` WHERE `ID` IN (48327 /*-Unknown-*/, 51062 /*-Unknown-*/, 48326 /*-Unknown-*/, 51061 /*-Unknown-*/, 51060 /*-Unknown-*/, 51059 /*-Unknown-*/, 49138 /*-Unknown-*/, 51057 /*-Unknown-*/, 47499 /*-Unknown-*/, 51056 /*-Unknown-*/, 51055 /*-Unknown-*/, 47647 /*-Unknown-*/, 51054 /*-Unknown-*/, 51053 /*-Unknown-*/, 48657 /*-Unknown-*/, 48656 /*-Unknown-*/, 48655 /*-Unknown-*/, 48585 /*-Unknown-*/, 48532 /*-Unknown-*/, 48533 /*-Unknown-*/, 48531 /*-Unknown-*/, 48530 /*-Unknown-*/, 48529 /*-Unknown-*/, 51573 /*-Unknown-*/, 51162 /*-Unknown-*/, 48324 /*-Unknown-*/, 50812 /*-Unknown-*/, 51991 /*-Unknown-*/, 52129 /*-Unknown-*/, 50775 /*-Unknown-*/, 50771 /*-Unknown-*/, 50847 /*-Unknown-*/, 50834 /*-Unknown-*/, 50980 /*-Unknown-*/, 50979 /*-Unknown-*/, 50817 /*-Unknown-*/, 49662 /*-Unknown-*/, 49340 /*-Unknown-*/, 50818 /*-Unknown-*/, 51165 /*-Unknown-*/, 49327 /*-Unknown-*/, 50641 /*-Unknown-*/, 49334 /*-Unknown-*/, 50794 /*-Unknown-*/, 47324 /*-Unknown-*/, 50561 /*-Unknown-*/, 48315 /*-Unknown-*/, 50539 /*-Unknown-*/, 50770 /*-Unknown-*/, 48313 /*-Unknown-*/, 48314 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `ScalingFactionGroup`, `MaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(48327, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 47497, 1, 1, 20200, 1, 1, 8200, 0, 0, 0, 0, 0, 0, 159677, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 159677, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'A Strange Delivery', 'Deliver the pineapple to Rhan\'ka in the Whistlebloom Oasis.', 'The last time our caravan rolled through the Whistlebloom Oasis, we found an odd Zandalari living in a cave. We traded a few things and he paid me upfront to bring him a pineapple. I don\'t know why.\n\nIt took me a long time to find one, but a vulpera holds up her end of the trade.\n\nI was planning to stop by and drop it off after we finished here. But, thanks to your help, we\'ve got a lot more treasure hunting to do here at the port.\n\nIf you have time, would you deliver it for me?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51062, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 101000, 3, 1, 41150, 0, 0, 0, 268997, 0, 0, 0, 0, 1, 0, 36700168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Escaping Zem\'lan', 'Ride Jamboya\'s boat to the shore and lead the pirates to Camp Lastwind.', 'Pirate-King Zem\'lan was right about one thing: he won\'t stay dead for long.\n\nWe gotta take our treasure and get out of here while we got de chance.\n\nWe can take de boat, but we\'ll need a place to hide out for awhile. Are your vulpera friends open to housin\' a few stowaways?\n\n<First Mate Jamboya motions to the piles of treasure in his boat.>\n\nClearly, we can pay dem for their trouble.', '', 'Lead the pirates to Norah at Camp Lastwind outside the Port of Zem\'lan.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48326, 2, -1, 5, 120, 18779, 110, 8501, 0, 0, 51062, 7, 1, 606000, 7, 1, 123400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 173015048, 0, 0, 0, 0, 80056, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'This Be Mutiny', 'Ring the Gong of Zem\'lan and kill Pirate-King Zem\'lan.', 'It be time to face Pirate-King Zem\'lan and bring dis mutiny to bear, $p.\n\nZem\'lan keeps a gong at de top of his treasure isle dat any crew member can ring to challenge him to a fight. I only ever seen one lass brave enough to ring it, and it didn\'t end well for her.\n\nBut you and me, we be de scourge of de seven seas, aye? Even mighty Zem\'lan be no match for de two of us together.\n\nRing de gong, and let\'s make Zem\'lan pay for cursin\' his crew and treatin\' us like dogs.\n\nMutiny or de yard arm!', '', 'Meet First Mate Jamboya at his boat on the Golden Isle.', 0, 0, 0, 0, 0, 0, 0, 0, 'Cruel captain of the undead pirate crew.', 'Pirate-King Zem\'lan', '', '', 890, 878, 27843), -- -Unknown-
(51061, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 48326, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4194312, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The First Time I Died', 'Place the idols on the altar and try to destroy them.', 'Dis be it. Where Zem\'lan cursed us all.\n\nIt began with me death. De first of countless deaths I\'ve had since. Each of dem spent fighting and dying for Pirate-King Zem\'lan and his selfish treasure hoard.\n\nI don\'t know if de idols he used to curse us can even be destroyed, but we gotta try. Let\'s take dem to de altar where de ritual occurred and try to smash one.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51060, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 48326, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Our Share of the Plunder', 'Collect $1oa Cursed Treasures of Zem\'lan.', 'Dis treasure belongs to de crew! We\'ve fought every battle for Zem\'lan, but he hoards all de booty for himself.\n\nAnd if ya try to take some for yourself, he turns ya into one of his goldslaves. Those be de mindless drones ya see tendin\' to de treasure out here.\n\nWe ain\'t leavin\' here empty-handed after de mutiny. Collect all de treasure ya can!\n\nBeware de cursed bits. It don\'t hurt us, but I\'m guessin\' it\'ll hurt you.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51059, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 101000, 3, 1, 41150, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Golden Isle', 'Ride in Jamboya\'s boat out to the Golden Isle.', 'Pirate-King Zem\'lan don\'t stay in de port with de rest of us. Too good to crack a jug with his crew no more.\n\nWe gotta sail out to de Golden Isle to find him. That be de forbidden island where Zem\'lan hoards all of de treasure we\'ve pillaged and plundered, so only he can enjoy dem.\n\nHop in my boat and we\'ll row out dere together.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49138, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 163633, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Captain Gulnaku\'s Treasure', 'Search for Captain Gulnaku\'s treasure chest.', '<This map is poorly drawn and covered in stains, but appears to identify three possible locations where a pirate captain may have buried treasure around the Port of Zem\'lan. The treasure could be at any of the three locations.\n\nAt the bottom of the map, someone scrawled an order: Set traps!>', '', 'Open Captain Gulnaku\'s treasure chest.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51057, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 51059, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 159774, 0, 1, 0, 38928392, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 159774, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Maroon \'em with Fire', 'Use the Undying Torch to burn $1oa Pillaging Canoes.', 'We gonna have to sail out to de Golden Isle to face Pirate-King Zem\'lan.\n\nLet\'s make sure de rest of de crew can\'t follow us once we go. Burn their boats in de harbor.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47499, 2, -1, 5, 120, 18857, 110, 8501, 0, 0, 51059, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Grinning Idols', 'Collect the Idol of Binding, Idol of Immortality, and Idol of Sacrifice.', 'Before de curse, we were a loyal crew to a good captain. But de curse corrupted Pirate-King Zem\'lan, made him cruel and controlling.\n\nNow, he treats us more like slaves than crewmates. Forced to fight and die for his gain, no treasure for ourselves. No speakin\' up without punishment.\n\nWell, us four, we ain\'t gonna be his slaves no more.\n\nA few of de crew hold onto de idols dat Zem\'lan used to curse us. Kill dem and take de idols. I wanna see if we can break dem. Just for fun.', '', 'Meet First Mate Jamboya near his boat.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51056, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 159757, 0, 1, 0, 37879816, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 159757, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'My Last Day Alive', 'Use First Mate Jamboya\'s Medallion to witness visions of his past.', 'De curse came one fateful day, in ages past, when de sethrak attacked. Dere was no end to dem.\n\nIn our desperation, I helped Pirate-King Zem\'lan do de unthinkable.\n\nWe became monsters. Even worse, we became eternal slaves to Zem\'lan.\n\nDe curse weighs heavy on me, but my guilt is heavier. I led me crew into dis.\n\nBefore we confront de Pirate-King himself, you need to understand what we be up against.\n\nYou need to see what happened de day dat de Port of Zem\'lan fell.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51055, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Yard Arm of the Law', 'Free Quartermaster Tulmac, Gunner Bosanya, and Jukanga the Snitch.', 'I\'m not de only pirate Zem\'lan has had strung up around de port. Hangin\' on de yard arm is his favorite form of punishment for de crew.\n\nWe can\'t feel pain and don\'t stay dead, so his options are limited.\n\nLook for more crewmates hangin\' around town. Tell dem to meet me here after you free dem.\n\nAfter weeks of hanging helplessly while being mocked and abused by de rest of de crew, I bet dey be willin\' to discuss mutiny.', '', '', 1553, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47647, 3, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 2, 396000, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41484544, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 5381, 0, 12261800583900083122, 0, 7, 'Monsters of Zem\'lan', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51054, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Overdue Mutiny', 'Free First Mate Jamboya.', 'I used to be a Zandalari, $p.\n\nLong ago, before dis curse. We were all Zandalari pirates, proudly sailing under de black flag of our captain, Zem\'lan.\n\nNow look at us... undead monsters, forced to serve our eternal captain like slaves.\n\nWell, I be done with dis. De curse can\'t be broken, but we can still mutiny!\n\nWhat say you? It gonna be tough, but I promise treasure and a chance to kill de notorious Pirate-King Zem\'lan who murdered your vulpera friend.\n\nHelp me down, and we be gettin\' started.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51053, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 51054, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 159747, 0, 1, 0, 37879816, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 159747, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Day the Port Fell', 'Use First Mate Jamboya\'s Medallion to view a vision of his past.', 'Dis be a cursed land, $pr. Feel it in your bones: de cold chill of death... and undeath.\n\nDe Pirate-King Zem\'lan rules dis port, with his crew of de eternal damned.\n\nIf you be lookin\' for honor or noble adventure, you won\'t find it here. But if you can settle for vengeance and treasure, I got an offer for you.\n\nBut you should know who you be allying with. My hands are not clean in dis.\n\nTake de medallion from my cloak and use it to reveal a vision of my past at de end of de dock.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48657, 2, -1, 5, 120, 18786, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 252254, 0, 0, 0, 0, 1, 0, 36700168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'They Might Be Delicious', 'Gather $1oa saurolisk eggs from the Arid Basin.', 'Saurolisk eggs are de most delicious eggs in de desert!\n\nI mean, I\'ve never tried dem myself... but look at de size of them! Dey\'re huge! Bigger is better, right?\n\nIf I go back to camp empty handed, Sezahjin is going to kill me! We have to get some of those eggs!\n\nYou sound a lot older and stronger than I am. Gather up de eggs so we can take dem back for everyone to eat.\n\nDon\'t worry about me, I\'ll wait for you here. It\'s not like I\'m going anywhere...', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48656, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 252254, 0, 0, 0, 0, 1, 0, 36700168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Savage Saurolisks', 'Slay $1oa Scaleclaw Saurolisks in the Arid Basin.', 'Please, help me! I\'m trapped in dis box and I can\'t make it out alone!\n\nI came here to collect eggs. I knew it was a bad idea, but I thought I could sneak around and grab de eggs before de saurolisks noticed.\n\nI was wrong...\n\nI hid underneath dis crate to avoid being eaten!\n\nCan you clear out de saurolisks and tell me when it\'s safe to come out?\n\nPlease, don\'t leave me here!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48655, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Chef\'s Apprentice', 'Locate Junji.', '<Sezahjin rummages through his cooking ingredients in frustration.>\n\nWhere is Junji? I sent him to scavenge for vulture eggs, but he hasn\'t returned.\n\n<Sezahjin pauses for a moment.>\n\nHe was just going on about de size of saurolisk eggs, but those oversized lizards are far too dangerous for a boy! He can\'t possibly be so foolish...\n\nIf he has gone to de saurolisk breeding grounds... he may already be dead. Please find him before it\'s too late!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48585, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Wasteland Survivor', 'Collect $1oa Scavenged Supplies.', '<The leather has become dry and cracked in the sun, but the supplies inside are mostly intact.\n\nIt\'s unknown what gruesome death befell the backpack\'s former owner, but supplies like these are in high demand among the outcasts.\n\nThe desert has claimed many lives... perhaps there are more supplies to be found among the dunes. >', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48532, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 253653, 0, 0, 152570, 0, 1, 0, 36700168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152570, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Alpacas Gone Wild', 'Round up $1oa Alpacas.', 'Our herd of alpacas escaped dis morning. Dey\'re out dere wandering de dunes as we speak.\n\nProbably for de best, if you ask me. We\'ll all be dead soon once Mojambo comes back.\n\nSince you seem to care so much, take dis alpaca whistle and use it to round dem up. I blow de whistle every day at feeding time, so de alpacas should come running home when dey hear de sound.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48533, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 253655, 0, 0, 152572, 0, 1, 0, 36700168, 0, 0, 0, 0, 0, 0, 0, 163208, 0, 0, 0, 2, 0, 0, 0, 152572, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Vol\'duni Fried Chicken', 'Collect $1oa Roasted Buzzard.', 'Have you ever tried my delicious Vol\'duni fried chicken?\n\nMe neither! Probably because dere aren\'t any chickens in Vol\'dun.\n\nDere are plenty of vultures, though. Why don\'t you see if you can find some tasty vulture meat?\n\nDe secret to delicious fried chicken is to roast de meat before you fry it, but it only works if de meat is fresh.\n\nI\'ve soaked dese arrows in alpaca fat. If you ignite de arrows and shoot down de birds, dey\'ll start cooking before dey\'re even dead!', '', '', 1553, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48531, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 253655, 0, 0, 0, 0, 1, 0, 36700168, 0, 0, 0, 0, 0, 0, 0, 163841, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Mystery Meat', 'Collect $1oa Dung Beetle Innards.', 'Mojambo\'s gang may be coming to kill us, but we\'ve still got to eat. And when you live in a harsh wasteland, you make do with what you\'ve got.\n\nSometimes fresh meat is hard to find.\n\nDat\'s how I came up with de idea for my famous mystery meat pie.\n\nDe secret ingredient is dung beetle, but with enough seasoning you can\'t even tell!\n\nOur food supplies are dangerously low right now. I need someone to go beetle hunting as soon as possible!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48530, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 253651, 0, 0, 0, 0, 1, 0, 35651592, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'I Heard You Lost the Herd', 'Speak with Mugjabu.', 'Our herd of alpacas went missing dis morning.\n\nIt may seem like we have more pressing matters to worry about, but de meat and milk de alpacas provide are essential to our survival.\n\nThose alpacas won\'t survive long on de dunes. Speak with Mugjabu and help him find de alpacas before it\'s too late!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48529, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 253645, 0, 0, 0, 0, 1, 0, 35651592, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Hungry Mouths To Feed', 'Speak with Sezahjin.', 'We don\'t have much in de way of supplies right now.\n\nMojambo and his gang will be back to finish us off, of dat I\'m sure. But without food and supplies, dere will be none of us alive for dem to kill.\n\nOur cook is looking for someone to help gather supplies so we can feed de camp.\n\nSpeak with him and see if you can find what he\'s looking for.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51573, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 253632, 0, 0, 0, 0, 1, 0, 40894472, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'I\'ve Got Your Back', 'Guard Razgaji while he meets with Mojambo.', 'It\'s good to see a new face around here. I\'ve got a problem and you look like you can handle a fight.\n\nDat group of murderous thugs over dere are looking for trouble and I need someone to back me up.\n\nDe truth is dat I used to be one of dem myself, but I left for a second chance at an honest life.\n\nI need to convince Mojambo and his henchmons to leave before dey start causing trouble for de rest of de outcasts here.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51162, 2, -1, 5, 120, 0, 110, 8501, 1, 3, 0, 7, 1, 594000, 7, 1, 61200, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 167772168, 0, 0, 0, 0, 84838, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'WANTED: Taz\'raka the Traitor', 'Find and kill Taz\'raka the Traitor.', 'To all caravans and travelers:\n\nBeware Taz\'raka the Traitor, a skeleton ambushing travelers on the road near Port of Zem\'lan. If you must travel on that road, move quickly, and avoid entering any of the ruins.\n\nSeveral caravans have combined resources to offer a reward for Taz\'raka\'s death.\n\nTo collect, speak with Norah in Camp Lastwind.', '', '', 1553, 0, 0, 0, 115, 0, 0, 0, 'Known criminal.', 'Taz\'raka the Traitor', '', '', 890, 878, 27843), -- -Unknown-
(48324, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Lost in Zem\'lan', 'Find Meeki.', 'Legends say that a mountain of treasure sits deep inside the Port of Zem\'lan, pillaged from every corner of Azeroth. But it\'s guarded by unkillable, eternal monsters.\n\nNo vulpera or exile has ever stolen treasure from the Port of Zem\'lan and made it out alive.\n\nMy caravan was going to be the first. Our scout, Meeki snuck in to figure out a route, but he never came back.\n\nIt would be wisest for you to leave here and never return. But, if you go into the port, please find Meeki.', '', 'Find Meeki in the Port of Zem\'lan.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50812, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 396000, 6, 1, 51000, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Awakened Elements', 'Investigate the disturbance.', 'It seems that all of this infernal blasting and hammering has stirred up... something.\n\nI heard some screaming from over in that direction.\n\n<He gestures vaguely to the North.>\n\nIf you could go take care of the situation, that would be most appreciated.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51991, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 81040, 0, 0, 0, 0, 1, 0, 35651584, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Charging the Batteries', 'Fill that ranishu\'s belly.', 'These little fellas are ravenous whirlwinds of devouring destruction. When they get going, they consume anything in their path, without even stopping! When sated, they discharge power from them little \'lectric zingers on their heads! \n\nThen they nap.\n\nLucky for us, we found just the right frequency to control their tiny bug brains. Hit that device, and you can take your own little zapper out for a spin... literally!\n\nMake sure ya bring it back full, so we can keep our rigs charged!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(52129, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 51991, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Power Problems', 'Check in with Rozzy.', 'Rozzy, part of the extraction crew, headed out with some gear to work on a plan to keep these reconfigulators all charged up.\n\nGo see see if she could use some help!', '', 'Check in with Rozzy', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50775, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Get Us Some Beach', 'Collect $1oa piles of sand.', 'These guys are running out of \"ammo\" faster than we can replace it! \n\nI tells \'em, we\'re on a beach, you\'re in a sandblaster, suck it up!\n\nThey says it\'s against the cleaner driver rules for their local chapter.\n\nI\'m not buyin\' it.\n\nGrab us some more sand. Them sand monsters have gotta be full of the stuff!\n\nWe\'ll make it worth your time.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50771, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 158725, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158725, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Calldown: Cleaner', 'Identify and mark $1oa Azerite deposits for the extraction team.', 'With these dust blowin\' siro-ma-whosits all over this beach front, it\'s a pain to get our cleaners out onto the nodes.\n\nSome of the crew wanted to check somewhere else, but no way we\'re leaving without those rocks for Gallywix. \n\nBetween you and me, $c, we\'re gonna be gettin\' some serious hazard pay for this gig.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50847, 3, -1, 0, 120, 0, 120, 8499, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 270259, 0, 0, 0, 0, 0, 0, 37290048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2159, 2103, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7500, 7500, 0, 0, 0, 0, 0, 0, 18446744073709551615, 916, 7, 'Twisted Child of Rezan', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50834, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Keep It Down!', 'Warn the goblins of danger.', 'There is a lot of noise and light coming from those filthy mechs down by the shore. No wonder my  little hatchlings get so cranky!\n\nThey are shaking up a coast that is already unstable. You never know what one might wake up that way! \n\nLet them know they should be careful.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50980, 2, -1, 5, 120, 18791, 110, 8501, 0, 0, 0, 6, 1, 0, 6, 1, 0, 0, 0, 0, 81040, 0, 0, 0, 0, 1, 0, 169869832, 0, 0, 0, 0, 55786, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'My Hungry Neighbor', 'Kill the Territorial Hydra.', 'There is an angry hydra that has decided to make a nearby ridge his home.\n\nHe keeps getting bigger, and meaner, and hungrier!\n\nMy cobras are terrified. \n\nPlease, $n, take care of him before he comes after us!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'He\'s feeling hangry.', 'Territorial Hydra', '', '', 890, 878, 27843), -- -Unknown-
(50979, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Just a Nip', 'Get $1oa samples of Atrivax Gel.', 'My tough-guys-in-training are quick learners! \n\nThey do seem to get a bit... bitey... when they\'re grouchy, though. Too many, and I start to get a little light-headed.\n\nThe nearby atrivax plants have a medicinal gel. It is great to treat fresh wounds and nullify venom.\n\nThey don\'t like sharing it. Could you harvest a bit for me?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50817, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 158883, 0, 1, 0, 33685512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158883, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'A Charming Tail', 'Send $1oa cobras to Jenoh.', 'I think they would make great guardians, when they get older... with the proper training.\n\nHowever, it seems some of my trainees have wandered off. There are so many things nearby that could harm them!\n\nBetween the walking sandstorms and angry plants... it\'s been safer to hide out here and look at night.\n\nI\'m so exhausted! \n\nCould you take this flute with you and play them a little tune? It will remind them to come back to me.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49662, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 50745, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5242888, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Missing Key', 'Meet Vorrik at Bwoljin\'s Fall.', 'Korthek has grown spiteful and arrogant over the years, but I realize now that he has grown mad as well.\n\nMythrax will kill all of us if he is released.\n\nFor too long, I\'ve held out hope that I could convince Korthek peacefully to abandon his heresy. I was wrong.\n\nAll of Zandalar is at risk while Korthek and his allies hold even one key to Mythrax\'s prison.\n\nMeet me outside his fortress in the north. We will confront my old friend \"Emperor\" Korthek and end this together.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49340, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Keepers\' Keys', 'Speak to Vorrik and uncover the significance of Sulthis\' Stone.', 'Serrik mentioned you might have uncovered something of significance at Zul\'Ahjin?\n\nWe don\'t have much time, I\'m afraid.\n\nWhat is it you have found?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50818, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 50817, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 0, 0, 0, 158882, 0, 1, 0, 34603016, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158882, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'A Lost Flute', 'Find the owner of the Desert Flute.', '<This little flute, while dusty, appears to be well cared for.\n\nIts owner can\'t be too far away.>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51165, 2, -1, 5, 120, 0, 110, 8501, 1, 5, 0, 7, 1, 594000, 7, 1, 61200, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 167772232, 0, 0, 0, 0, 84839, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 2159, 0, 0, 0, 5, 5, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 7, 'WANTED: Sandscout Vesarik', 'Find and kill Sandscout Vesarik.', 'To any and all who wish to see the Faithless empire fall: \n\nSandscout Vesarik was spotted patrolling the dunes to the east. Gather a formidable force and strike him down!\n\nThose who succeed will be granted a fitting reward.', '', '', 1553, 0, 0, 0, 115, 0, 0, 0, 'Experienced in combat. Approach with extreme caution.', 'Sandscout Vesarik', '', '', 890, 878, 27843), -- -Unknown-
(49327, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 264413, 0, 0, 0, 0, 1, 0, 39845896, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Push Them Back!', 'Disrupt the Faithless assault on the Sanctuary of the Devoted.', 'The faithless are laying siege to our home. \n\nThis isn\'t the first time they\'ve attacked, nor will it be the last, but we must protect the temple!\n\nDo whatever you can to disrupt their siege and push them back.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50641, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 264413, 0, 0, 0, 0, 1, 0, 39845896, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Break Their Ranks', 'Kill $1oa Faithless attackers within the Temple Grounds.', 'This temple is our last bastion against the Faithless. We need every able fighter to defend its walls. \n\nIf you\'re offering to help, we won\'t turn you away. \n\nHead into battle and do what you can to break their ranks!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49334, 2, -1, 5, 120, 18781, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'A Powerful Prisoner', 'Find Vorrik and free him from his captors.', 'It appears the Faithless broke through our defenses while I was away. \n\nThey must be after Vorrik\'s key. It\'s the only reason they would have taken him alive. \n\nPlease, $n. You must secure our leader\'s safe return.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50794, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 198000, 5, 1, 4100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 50331656, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Seeking Shelter', 'Find Razgaji at the Scorched Sands Outpost.', 'I must head back to de arena. Razgaji will want to know what happened here. \n\nIf you seek shelter, you will find it at de outpost not too far from here.\n  \nI will let our leader know you\'re coming.\n\nBe safe, $n.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47324, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Unlikely Allies', 'Fly to the Sanctuary of the Devoted.', 'I believe this is one of the Keepers\' keys! Only Vorrik would know for sure. \n\nWe need to head to the temple at once. \n\nMy pterrordax can take us there when you\'re ready, but we need to hurry.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50561, 2, -1, 5, 120, 18793, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 157865, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Sulthis\' Stone', 'Deliver Sulthis\' Stone to Serrik within Zul\'Ahjin.', '<The ancient reliquary contains a single stone, humming with magic. Perhaps Serrik will know what it is?>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48315, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Hollow, Empty Eyes', 'Find the statue\'s missing gems.', '<Carved into the ancient statue are two eye sockets that look like they once held gems. \n\nPerhaps the missing gems can be found within the ruins?>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50539, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Secrets of Zul\'Ahjin', 'Investigate the statue.', 'You\'re not the only one who came to Zul\'Ahjin looking for answers. The place is crawling with looters and assassins, all searching for something... \n\nSo far, they\'ve come up empty handed, but that\'s because they don\'t know where to look.\n\nI do. \n\nInvestigate the statue at the center of the ruins. It is the key to uncovering the city\'s ancient secrets.', '', '', 1553, 0, 0, 0, 100, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50770, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 158678, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158678, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Effective Antivenom', 'Administer the Antivenom to Serrik.', 'The salve is ready. \n\nI work fast. Hopefully faster than the scorpid poison. \n\nTake this antivenom to your friend and see that he swallows every last drop. \n\nYou should know within moments if it\'s been effective.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48313, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 4194304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Nature\'s Remedy', 'Harvest $1oa Prickly Plum in Zul\'Ahjin.', 'Your friend doesn\'t have much time left. The scorpid venom is likely rotting his veins right now. \n\nHe will certainly meet death without a cure.\n\nI will help. \n\nThe first ingredient I\'ll need is the root of the prickly plum cactus. Its natural healing properties will make a suitable base for the salve.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48314, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 4194304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Creeping Death', 'Collect $1oa Scorpashi Stingers in Zul\'Ahjin.', 'Scorposhi venom usually induces a slow, creeping death.\n\nIt\'s remarkable that your friend has survived this long.\n\nAs with most antivenoms, the thing that kills is also the thing that heals. \n\nI\'ll need to extract the venom from several scorpashi stingers to craft the cure.\n\nWhen the extracted poison is mixed with cactus root salve, we will have the antivenom we need to treat his wounds.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843); -- -Unknown-

UPDATE `quest_template` SET `MaxScalingLevel`=110, `VerifiedBuild`=27843 WHERE `ID`=46261; -- The Taste of Corruption
UPDATE `quest_template` SET `FlagsEx2`=2, `VerifiedBuild`=27843 WHERE `ID`=42240; -- Halls of Valor: Ponderous Poaching
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=41701; -- Gettin' Tuffer
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=43617; -- WANTED: Devouring Darkness
UPDATE `quest_template` SET `MaxScalingLevel`=110, `VerifiedBuild`=27843 WHERE `ID`=45924; -- Abyssal Monstrosity
UPDATE `quest_template` SET `MaxScalingLevel`=110, `VerifiedBuild`=27843 WHERE `ID`=46265; -- The Fel and the Fawns
UPDATE `quest_template` SET `MaxScalingLevel`=110, `VerifiedBuild`=27843 WHERE `ID`=44730; -- Ravaged Dreams
UPDATE `quest_template` SET `AllowableRaces`=12261800583900083122, `VerifiedBuild`=27843 WHERE `ID`=43752; -- Oh, Ship!
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=43622; -- WANTED: Glimar Ironfist
UPDATE `quest_template` SET `MaxScalingLevel`=110, `VerifiedBuild`=27843 WHERE `ID`=46766; -- Ulgthax
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=43476; -- Experimental Potion: Test Subjects Needed
UPDATE `quest_template` SET `MaxScalingLevel`=110, `VerifiedBuild`=27843 WHERE `ID`=45923; -- Gloth
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=41948; -- All Pets Go to Heaven
UPDATE `quest_template` SET `RewardItem2`=0, `RewardAmount2`=0, `VerifiedBuild`=27843 WHERE `ID`=42422; -- The Wardens
UPDATE `quest_template` SET `MaxScalingLevel`=110, `MinLevel`=98, `RewardMoney`=146000, `RewardBonusMoney`=1700, `VerifiedBuild`=27843 WHERE `ID`=45812; -- Assault on Val'sharah

DELETE FROM `quest_objectives` WHERE `ID` IN (335175 /*335175*/, 335167 /*335167*/, 294184 /*294184*/, 294183 /*294183*/, 336029 /*336029*/, 335119 /*335119*/, 335037 /*335037*/, 335115 /*335115*/, 294188 /*294188*/, 294027 /*294027*/, 294026 /*294026*/, 294025 /*294025*/, 293887 /*293887*/, 335071 /*335071*/, 293982 /*293982*/, 293981 /*293981*/, 293879 /*293879*/, 334887 /*334887*/, 334886 /*334886*/, 334871 /*334871*/, 334870 /*334870*/, 334869 /*334869*/, 294518 /*294518*/, 293949 /*293949*/, 293948 /*293948*/, 293947 /*293947*/, 293943 /*293943*/, 293942 /*293942*/, 334846 /*334846*/, 334825 /*334825*/, 292725 /*292725*/, 292723 /*292723*/, 292585 /*292585*/, 341639 /*341639*/, 292462 /*292462*/, 341637 /*341637*/, 292464 /*292464*/, 292456 /*292456*/, 336318 /*336318*/, 336317 /*336317*/, 334932 /*334932*/, 334036 /*334036*/, 333883 /*333883*/, 340972 /*340972*/, 339805 /*339805*/, 338001 /*338001*/, 338000 /*338000*/, 337999 /*337999*/, 337998 /*337998*/, 333780 /*333780*/, 333767 /*333767*/, 334088 /*334088*/, 334496 /*334496*/, 334494 /*334494*/, 333913 /*333913*/, 333256 /*333256*/, 334934 /*334934*/, 294294 /*294294*/, 294259 /*294259*/, 294258 /*294258*/, 333429 /*333429*/, 294338 /*294338*/, 333414 /*333414*/, 333413 /*333413*/, 333104 /*333104*/, 333102 /*333102*/, 333765 /*333765*/, 291919 /*291919*/, 291925 /*291925*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(335175, 51062, 0, 0, 0, 136953, 1, 0, 0, 0, 'Jamboya\'s boat ridden', 27843), -- 335175
(335167, 48326, 0, 2, 2, 136946, 1, 28, 0, 0, '', 27843), -- 335167
(294184, 48326, 0, 1, 1, 127025, 1, 3, 0, 0, '', 27843), -- 294184
(294183, 48326, 0, 0, 0, 136921, 1, 0, 0, 0, 'Ring the Gong of Zem\'lan', 27843), -- 294183
(336029, 51061, 0, 1, 0, 136792, 1, 2, 0, 0, 'Idol of Binding attacked', 27843), -- 336029
(335119, 51061, 0, 0, 1, 137869, 1, 0, 0, 0, 'Idols placed on altar', 27843), -- 335119
(335037, 51060, 1, 0, 0, 152659, 12, 0, 1, 0, '', 27843), -- 335037
(335115, 51059, 0, 0, 0, 136775, 1, 0, 0, 0, 'Jamboya\'s boat ridden', 27843), -- 335115
(294188, 49138, 1, 4, 4, 153419, 1, 3, 1, 0, '', 27843), -- 294188
(294027, 49138, 0, 3, 2, 128502, 1, 12, 0, 0, 'Dock searched', 27843), -- 294027
(294026, 49138, 0, 2, 5, 128501, 1, 12, 0, 0, 'Alleyway searched', 27843), -- 294026
(294025, 49138, 0, 1, 1, 128500, 1, 12, 0, 0, 'Beach searched', 27843), -- 294025
(293887, 49138, 0, 0, 0, 128499, 1, 0, 0, 0, 'Buried treasure found', 27843), -- 293887
(335071, 51057, 0, 0, 0, 136744, 8, 0, 0, 0, 'Pillaging canoes burned', 27843), -- 335071
(293982, 47499, 1, 2, 2, 153352, 1, 1, 1, 0, '', 27843), -- 293982
(293981, 47499, 1, 1, 1, 151021, 1, 1, 1, 0, '', 27843), -- 293981
(293879, 47499, 1, 0, 0, 153351, 1, 1, 1, 0, '', 27843), -- 293879
(334887, 51056, 0, 1, 1, 136610, 1, 0, 0, 0, 'Battlefield memory witnessed', 27843), -- 334887
(334886, 51056, 0, 0, 0, 136609, 1, 0, 0, 0, 'Throne room memory witnessed', 27843), -- 334886
(334871, 51055, 0, 2, 2, 136605, 1, 0, 0, 0, 'Jukanga the Snitch freed', 27843), -- 334871
(334870, 51055, 0, 1, 1, 136604, 1, 0, 0, 0, 'Gunner Bosanya freed', 27843), -- 334870
(334869, 51055, 0, 0, 0, 136603, 1, 0, 0, 0, 'Quartermaster Tulmac freed', 27843), -- 334869
(294518, 47647, 0, 5, 0, 128369, 50, 92, 0, 2, '', 27843), -- 294518
(293949, 47647, 0, 4, 4, 129435, 50, 92, 0, 2, '', 27843), -- 293949
(293948, 47647, 0, 3, 3, 128380, 200, 92, 0, 0.5, '', 27843), -- 293948
(293947, 47647, 0, 2, 2, 128315, 50, 92, 0, 2, '', 27843), -- 293947
(293943, 47647, 0, 1, 1, 128379, 34, 92, 0, 3, '', 27843), -- 293943
(293942, 47647, 15, 0, -1, 0, 1, 0, 0, 0, 'Assault the Port of Zem\'lan', 27843), -- 293942
(334846, 51054, 0, 0, 0, 136571, 1, 0, 0, 0, 'First Mate Jamboya freed', 27843), -- 334846
(334825, 51053, 0, 0, 0, 136503, 1, 0, 0, 0, 'Jamboya\'s memory witnessed', 27843), -- 334825
(292725, 48657, 1, 0, 0, 152647, 10, 0, 1, 0, '', 27843), -- 292725
(292723, 48656, 0, 0, 0, 126984, 8, 0, 0, 0, '', 27843), -- 292723
(292585, 48585, 1, 0, 1, 152601, 10, 0, 1, 0, '', 27843), -- 292585
(341639, 48532, 0, 1, 1, 126627, 1000, 28, 0, 0, '', 27843), -- 341639
(292462, 48532, 0, 0, 0, 126610, 6, 0, 0, 0, 'Alpacas herded', 27843), -- 292462
(341637, 48533, 0, 1, 1, 126502, 100, 28, 0, 0, '', 27843), -- 341637
(292464, 48533, 1, 0, 0, 152571, 8, 0, 1, 0, '', 27843), -- 292464
(292456, 48531, 1, 0, 0, 152566, 8, 0, 1, 0, '', 27843), -- 292456
(336318, 51573, 0, 1, 1, 138147, 1, 2, 0, 0, 'Razgaji escorted', 27843), -- 336318
(336317, 51573, 0, 0, 0, 138146, 1, 0, 0, 0, 'Speak with Razgaji', 27843), -- 336317
(334932, 51162, 0, 0, 0, 136595, 1, 1, 0, 0, '', 27843), -- 334932
(334036, 50812, 0, 1, 0, 135349, 1, 2, 0, 0, '', 27843), -- 334036
(333883, 50812, 0, 0, 1, 135436, 1, 0, 0, 0, 'Disturbance to the north investigated', 27843), -- 333883
(340972, 51991, 0, 5, 4, 142895, 3, 92, 0, 42, '', 27843), -- 340972
(339805, 51991, 0, 4, 2, 139929, 20, 92, 0, 5, '', 27843), -- 339805
(338001, 51991, 0, 3, 1, 139772, 34, 92, 0, 3, '', 27843), -- 338001
(338000, 51991, 0, 2, 0, 139492, 100, 92, 0, 1, '', 27843), -- 338000
(337999, 51991, 15, 1, -1, 0, 1, 2, 0, 0, 'Feed lashers to the ranishu', 27843), -- 337999
(337998, 51991, 0, 0, 3, 143377, 1, 0, 0, 0, 'Use the Lectric Frequency Modulator', 27843), -- 337998
(333780, 50775, 1, 0, 0, 158707, 20, 0, 1, 0, '', 27843), -- 333780
(333767, 50771, 0, 0, 0, 135080, 5, 0, 0, 0, 'Target identified', 27843), -- 333767
(334088, 50847, 0, 0, 0, 130643, 1, 0, 0, 0, '', 27843), -- 334088
(334496, 50980, 0, 0, 0, 140050, 1, 1, 0, 0, '', 27843), -- 334496
(334494, 50979, 1, 0, 0, 159675, 10, 0, 1, 0, '', 27843), -- 334494
(333913, 50817, 0, 0, 0, 135084, 15, 0, 0, 0, 'Strand Cobra sent home', 27843), -- 333913
(333256, 49340, 0, 0, 0, 129519, 1, 1, 0, 0, 'Speak to Vorrik', 27843), -- 333256
(334934, 51165, 0, 0, 0, 136596, 1, 1, 0, 0, '', 27843), -- 334934
(294294, 49327, 2, 2, 4, 277911, 2, 0, 0, 0, 'Spires shattered', 27843), -- 294294
(294259, 49327, 0, 1, 5, 129076, 2, 0, 0, 0, 'Cannons crushed', 27843), -- 294259
(294258, 49327, 2, 0, 3, 277899, 4, 0, 0, 0, 'Banners burned', 27843), -- 294258
(333429, 50641, 0, 0, 1, 128664, 10, 0, 0, 0, 'Faithless slain', 27843), -- 333429
(294338, 49334, 0, 0, 0, 128962, 1, 0, 0, 0, 'Vorrik rescued', 27843), -- 294338
(333414, 47324, 0, 1, 1, 134545, 1, 2, 0, 0, 'Fly to the Sanctuary of the Devoted', 27843), -- 333414
(333413, 47324, 0, 0, 0, 134544, 1, 1, 0, 0, 'Pterrordax mounted', 27843), -- 333413
(333104, 50561, 1, 0, 0, 157865, 1, 0, 1, 0, '', 27843), -- 333104
(333102, 48315, 1, 0, 0, 157864, 2, 0, 1, 0, '', 27843), -- 333102
(333765, 50770, 0, 0, 0, 134532, 1, 1, 0, 0, 'Restorative Balm applied', 27843), -- 333765
(291919, 48313, 1, 0, 0, 152393, 6, 0, 1, 0, '', 27843), -- 291919
(291925, 48314, 1, 0, 0, 152397, 7, 0, 1, 0, '', 27843); -- 291925


UPDATE `quest_objectives` SET `Order`=2, `VerifiedBuild`=27843 WHERE `ID`=282698; -- 282698
UPDATE `quest_objectives` SET `Order`=1, `VerifiedBuild`=27843 WHERE `ID`=282699; -- 282699
UPDATE `quest_objectives` SET `Description`='King\'s Fang boarded', `VerifiedBuild`=27843 WHERE `ID`=285801; -- 285801

DELETE FROM `quest_visual_effect` WHERE (`ID`=335175 AND `Index`=0) OR (`ID`=294184 AND `Index`=0) OR (`ID`=294183 AND `Index`=0) OR (`ID`=336029 AND `Index`=0) OR (`ID`=335119 AND `Index`=0) OR (`ID`=335037 AND `Index`=2) OR (`ID`=335037 AND `Index`=1) OR (`ID`=335037 AND `Index`=0) OR (`ID`=335115 AND `Index`=0) OR (`ID`=294188 AND `Index`=0) OR (`ID`=294027 AND `Index`=0) OR (`ID`=294026 AND `Index`=0) OR (`ID`=294025 AND `Index`=0) OR (`ID`=335071 AND `Index`=1) OR (`ID`=335071 AND `Index`=0) OR (`ID`=293982 AND `Index`=0) OR (`ID`=293981 AND `Index`=0) OR (`ID`=293879 AND `Index`=0) OR (`ID`=334887 AND `Index`=0) OR (`ID`=334886 AND `Index`=0) OR (`ID`=334871 AND `Index`=0) OR (`ID`=334870 AND `Index`=0) OR (`ID`=334869 AND `Index`=0) OR (`ID`=294518 AND `Index`=0) OR (`ID`=293949 AND `Index`=2) OR (`ID`=293949 AND `Index`=1) OR (`ID`=293949 AND `Index`=0) OR (`ID`=334846 AND `Index`=0) OR (`ID`=334825 AND `Index`=0) OR (`ID`=292723 AND `Index`=0) OR (`ID`=292462 AND `Index`=0) OR (`ID`=292464 AND `Index`=0) OR (`ID`=336317 AND `Index`=0) OR (`ID`=334932 AND `Index`=0) OR (`ID`=334036 AND `Index`=0) OR (`ID`=337998 AND `Index`=0) OR (`ID`=333767 AND `Index`=0) OR (`ID`=334088 AND `Index`=0) OR (`ID`=334496 AND `Index`=0) OR (`ID`=333913 AND `Index`=0) OR (`ID`=333256 AND `Index`=0) OR (`ID`=334934 AND `Index`=0) OR (`ID`=294259 AND `Index`=0) OR (`ID`=294338 AND `Index`=0) OR (`ID`=333413 AND `Index`=0) OR (`ID`=333765 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(335175, 0, 9312, 27843),
(294184, 0, 8273, 27843),
(294183, 0, 9310, 27843),
(336029, 0, 9418, 27843),
(335119, 0, 9419, 27843),
(335037, 2, 9286, 27843),
(335037, 1, 9285, 27843),
(335037, 0, 9284, 27843),
(335115, 0, 9306, 27843),
(294188, 0, 8267, 27843),
(294027, 0, 8265, 27843),
(294026, 0, 8263, 27843),
(294025, 0, 8262, 27843),
(335071, 1, 10220, 27843),
(335071, 0, 9297, 27843),
(293982, 0, 9326, 27843),
(293981, 0, 9327, 27843),
(293879, 0, 9328, 27843),
(334887, 0, 9258, 27843),
(334886, 0, 9257, 27843),
(334871, 0, 9255, 27843),
(334870, 0, 9254, 27843),
(334869, 0, 9253, 27843),
(294518, 0, 9296, 27843),
(293949, 2, 9295, 27843),
(293949, 1, 9294, 27843),
(293949, 0, 9293, 27843),
(334846, 0, 9249, 27843),
(334825, 0, 9244, 27843),
(292723, 0, 9227, 27843),
(292462, 0, 9233, 27843),
(292464, 0, 9080, 27843),
(336317, 0, 9454, 27843),
(334932, 0, 2101, 27843),
(334036, 0, 2101, 27843),
(337998, 0, 10154, 27843),
(333767, 0, 9617, 27843),
(334088, 0, 2101, 27843),
(334496, 0, 2101, 27843),
(333913, 0, 2100, 27843),
(333256, 0, 2099, 27843),
(334934, 0, 2101, 27843),
(294259, 0, 2100, 27843),
(294338, 0, 10177, 27843),
(333413, 0, 2099, 27843),
(333765, 0, 2099, 27843);

UPDATE `creature_template_model` SET `Probability`=99, `VerifiedBuild`=27843 WHERE (`CreatureID`=62005 AND `CreatureDisplayID`=28647); -- Beast
UPDATE `creature_template_model` SET `Probability`=99, `VerifiedBuild`=27843 WHERE (`CreatureID`=62005 AND `CreatureDisplayID`=42373); -- Beast
UPDATE `creature_template_model` SET `Probability`=99, `VerifiedBuild`=27843 WHERE (`CreatureID`=62005 AND `CreatureDisplayID`=42372); -- Beast

DELETE FROM `gameobject_template` WHERE `entry` IN (287326 /*Zem'lan's Buried Treasure*/, 275082 /*Idol of Sacrifice*/, 288155 /*Idol of Immortality*/, 288154 /*Idol of Binding*/, 289733 /*Gong of Zem'lan*/, 272622 /*Cursed Treasure*/, 287493 /*Cursed Treasure*/, 287490 /*Cursed Treasure*/, 276191 /*Zem'lan's Bloody Notes*/, 289734 /*Cursed Altar of Zem'lan*/, 287314 /*Disturbed Sand*/, 277530 /*Captain Gulnaku's Treasure*/, 277527 /*Freshly Dug Sand*/, 277526 /*Freshly Dug Sand*/, 277356 /*Zandalari Cauldron*/, 287495 /*Pirate Hat*/, 280613 /*Zandalari Cooking Pit*/, 279690 /*Rug*/, 289728 /*Captain Gulnaku's Treasure Map*/, 287488 /*Blood Troll Canoe*/, 289632 /*Pillaging Canoe*/, 276194 /*Crate*/, 273821 /*Campfire*/, 289709 /*Cave Rock*/, 275099 /*Saurolisk Egg*/, 276187 /*Junji*/, 289779 /*Zandalari Skull (Mouth Closed)*/, 281394 /*Zandalari Skeleton (Sitting Up)*/, 281392 /*Zandalari Skeleton (Head Left)*/, 273854 /*Backpack*/, 282636 /*Sezahjin's Meat Pies*/, 282635 /*Alpaca Hides*/, 282633 /*Alpaca Butter*/, 282630 /*Table*/, 289438 /*Campfire*/, 287398 /*Wanted: Za'roco*/, 292747 /*Mailbox*/, 289446 /*Forge*/, 289443 /*Anvil*/, 289445 /*Chair*/, 289444 /*Chair*/, 289442 /*Chair*/, 289441 /*Chair*/, 289440 /*Chair*/, 289439 /*Chair*/, 282634 /*Hyena Jerky*/, 282466 /*Tongo's Chair*/, 292784 /*Zandalari Dunemelons*/, 282632 /*Fresh Water*/, 282631 /*Medicinal Herbs*/, 282467 /*Blood Drip*/, 282474 /*Stake*/, 290712 /*Sandworn Blade*/, 279646 /*Bloodguard Chronicles*/, 273824 /*Bench*/, 273822 /*Campfire*/, 287440 /*Wanted: Taz'raka*/, 273825 /*Stool*/, 273823 /*Stool*/, 287498 /*Zem'lan Blackeye Brew*/, 284471 /*Guntha's Peace Offering*/, 287418 /*The End of Every Mutineer*/, 287417 /*Zandalari Wall Torch (Dirt)*/, 271662 /*Hissing Crate*/, 284418 /*Treasure Chest*/, 271165 /*Skeleton*/, 287496 /*Treasure Map*/, 296574 /*Ian's Empty Bottle*/, 276242 /*Anchor Weed*/, 282332 /*Azerite*/, 287211 /*Caromzar Cactus*/, 282445 /*Azerite*/, 282418 /*Azerite*/, 282449 /*Cleaner Repair Kit*/, 282444 /*Sand Bags*/, 278401 /*Sand Shifter School*/, 281872 /*Sea Stalks*/, 296258 /*Campfire*/, 294330 /*Campfire*/, 297494 /*Tales of de Loa: Kimbul*/, 284417 /*Treasure Chest*/, 282498 /*Desert Flute*/, 289364 /*Sethrak Cage*/, 277876 /*Sethrak Cage*/, 277899 /*Sethrak War Banner*/, 296256 /*Anvil*/, 296255 /*Anvil*/, 296254 /*Forge*/, 296554 /*Mailbox*/, 296257 /*Grill*/, 287441 /*Wanted: Sandscout Vesarik*/, 277911 /*Sethrak Spire*/, 278403 /*Slimy Mackerel School*/, 296580 /*Ofer's Bound Journal*/, 296581 /*Skye's Pet Rock*/, 273837 /*Supply Pouch*/, 273834 /*Troll Bones - Arm*/, 273836 /*Backpack*/, 273835 /*Troll Bones - Skeleton*/, 282740 /*Mysterious Trashpile*/, 276394 /*Stolen Relics*/, 276393 /*Stolen Relics*/, 276392 /*Stolen Relics*/, 281583 /*Ancient Reliquary*/, 281552 /*Polished Onyx*/, 281558 /*Glittering Sapphire*/, 281639 /*Crumbling Statue*/, 281634 /*Cracked Stone Tablet*/, 291085 /*Sand Base*/, 281229 /*Magic Barrier*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `RequiredLevel`, `VerifiedBuild`) VALUES
(287326, 3, 48259, 'Zem\'lan\'s Buried Treasure', '', 'Opening', '', 1, 57, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 705, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2905, 87635, 0, 0, 0, 108, 27843), -- Zem'lan's Buried Treasure
(275082, 5, 13556, 'Idol of Sacrifice', '', '', '', 0.2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Idol of Sacrifice
(288155, 5, 13556, 'Idol of Immortality', '', '', '', 0.2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Idol of Immortality
(288154, 10, 13572, 'Idol of Binding', 'questinteract', 'Breaking', '', 0.2, 2741, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 271251, 0, 0, 0, 20138, 0, 0, 0, 0, 0, 1, 0, 58110, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Idol of Binding
(289733, 10, 43901, 'Gong of Zem\'lan', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 271264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 63622, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Gong of Zem'lan
(272622, 3, 29551, 'Cursed Treasure', 'questinteract', 'Collecting', '', 0.7, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245147, 0, 0, 0, 87710, 1, 0, 0, 0, 27843), -- Cursed Treasure
(287493, 3, 30844, 'Cursed Treasure', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245147, 0, 0, 0, 87709, 1, 0, 0, 0, 27843), -- Cursed Treasure
(287490, 3, 29552, 'Cursed Treasure', 'questinteract', 'Collecting', '', 0.7, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245147, 0, 0, 0, 87710, 1, 0, 0, 0, 27843), -- Cursed Treasure
(276191, 9, 11456, 'Zem\'lan\'s Bloody Notes', 'interact', '', '', 1, 7314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zem'lan's Bloody Notes
(289734, 10, 48853, 'Cursed Altar of Zem\'lan', 'questinteract', 'Placing', '', 1.81, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 271252, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 58111, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Cursed Altar of Zem'lan
(287314, 10, 9533, 'Disturbed Sand', 'questinteract', 'Digging', '', 0.8, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 268225, 0, 0, 0, 152300, 0, 0, 0, 0, 0, 1, 0, 56876, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Disturbed Sand
(277530, 2, 13635, 'Captain Gulnaku\'s Treasure', 'questturnin', '', '', 1.5, 0, 21501, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Captain Gulnaku's Treasure
(277527, 3, 20, 'Freshly Dug Sand', 'questinteract', 'Digging', '', 1, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35059, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254983, 0, 0, 0, 76966, 1, 0, 0, 0, 27843), -- Freshly Dug Sand
(277526, 10, 20, 'Freshly Dug Sand', 'questinteract', 'Digging', '', 1, 43, 0, 63628, 3000, 0, 0, 0, 0, 0, 0, 254982, 0, 0, 0, 35059, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Freshly Dug Sand
(277356, 5, 13622, 'Zandalari Cauldron', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Cauldron
(287495, 10, 43470, 'Pirate Hat', 'questinteract', 'Collecting', '', 1.5, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 268462, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Pirate Hat
(280613, 5, 46749, 'Zandalari Cooking Pit', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Cooking Pit
(279690, 5, 45693, 'Rug', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Rug
(289728, 2, 222, 'Captain Gulnaku\'s Treasure Map', 'quest', '', '', 1, 0, 22133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Captain Gulnaku's Treasure Map
(287488, 5, 48953, 'Blood Troll Canoe', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Blood Troll Canoe
(289632, 5, 48953, 'Pillaging Canoe', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Pillaging Canoe
(276194, 5, 41702, 'Crate', '', '', '', 1.5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Crate
(273821, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(289709, 5, 29478, 'Cave Rock', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Cave Rock
(275099, 3, 13575, 'Saurolisk Egg', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76034, 0, 0, 0, 0, 27843), -- Saurolisk Egg
(276187, 2, 41702, 'Junji', '', '', '', 1.5, 0, 21386, 1, 21496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Junji
(289779, 5, 48715, 'Zandalari Skull (Mouth Closed)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Skull (Mouth Closed)
(281394, 5, 43302, 'Zandalari Skeleton (Sitting Up)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Skeleton (Sitting Up)
(281392, 5, 44344, 'Zandalari Skeleton (Head Left)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Skeleton (Head Left)
(273854, 2, 14316, 'Backpack', '', '', '', 1, 0, 21373, 1, 21488, 0, 0, 0, 0, 0, 0, 51854, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Backpack
(282636, 3, 41702, 'Sezahjin\'s Meat Pies', 'questinteract', 'Opening', '', 0.6, 1691, 0, 1, 0, 0, 0, 0, 0, 48790, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87409, 0, 0, 0, 0, 27843), -- Sezahjin's Meat Pies
(282635, 3, 48521, 'Alpaca Hides', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 48790, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87410, 0, 0, 0, 0, 27843), -- Alpaca Hides
(282633, 3, 34273, 'Alpaca Butter', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 48790, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87412, 0, 0, 0, 0, 27843), -- Alpaca Butter
(282630, 5, 14839, 'Table', '', '', '', 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Table
(289438, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(287398, 2, 45786, 'Wanted: Za\'roco', '', '', '', 1, 0, 22051, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Wanted: Za'roco
(292747, 19, 50361, 'Mailbox', '', '', '', 1, 923, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mailbox
(289446, 8, 12595, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(289443, 8, 48031, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(289445, 7, 49215, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(289444, 7, 49215, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(289442, 7, 49215, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(289441, 7, 49215, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(289440, 7, 49215, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(289439, 7, 49215, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(282634, 3, 48520, 'Hyena Jerky', 'questinteract', 'Opening', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 48790, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87411, 0, 0, 0, 0, 27843), -- Hyena Jerky
(282466, 5, 91, 'Tongo\'s Chair', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Tongo's Chair
(292784, 3, 50359, 'Zandalari Dunemelons', 'questinteract', 'Collecting', '', 0.7, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88701, 1, 0, 0, 0, 27843), -- Zandalari Dunemelons
(282632, 3, 33132, 'Fresh Water', 'questinteract', 'Collecting', '', 2.25, 1691, 0, 1, 0, 0, 0, 0, 0, 48790, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87413, 0, 0, 0, 0, 27843), -- Fresh Water
(282631, 3, 7678, 'Medicinal Herbs', 'questinteract', 'Collecting', '', 0.6, 1691, 0, 1, 0, 0, 0, 0, 0, 48790, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87414, 0, 0, 0, 0, 27843), -- Medicinal Herbs
(282467, 5, 14012, 'Blood Drip', '', '', '', 0.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Blood Drip
(282474, 5, 15993, 'Stake', '', '', '', 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stake
(290712, 3, 26047, 'Sandworn Blade', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88148, 0, 0, 0, 0, 27843), -- Sandworn Blade
(279646, 2, 28058, 'Bloodguard Chronicles', '', '', '', 0.75, 0, 21725, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bloodguard Chronicles
(273824, 7, 44319, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bench
(273822, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(287440, 2, 45786, 'Wanted: Taz\'raka', '', '', '', 1, 0, 22053, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Wanted: Taz'raka
(273825, 7, 44320, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(273823, 7, 44318, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(287498, 10, 46058, 'Zem\'lan Blackeye Brew', 'questinteract', 'Drinking', '', 1, 2873, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 268468, 0, 0, 0, 21295, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zem'lan Blackeye Brew
(284471, 22, 46057, 'Guntha\'s Peace Offering', '', '', '', 1, 167152, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Guntha's Peace Offering
(287418, 5, 11581, 'The End of Every Mutineer', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- The End of Every Mutineer
(287417, 5, 48912, 'Zandalari Wall Torch (Dirt)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Wall Torch (Dirt)
(271662, 10, 13558, 'Hissing Crate', 'questinteract', 'Breaking', '', 1, 99, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 245654, 0, 0, 0, 20138, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Hissing Crate
(284418, 50, 46516, 'Treasure Chest', '', '', '', 0.5, 1690, 87484, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2822, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(271165, 5, 19810, 'Skeleton', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skeleton
(287496, 10, 13650, 'Treasure Map', 'questinteract', 'Collecting', '', 0.8, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 268464, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Treasure Map
(296574, 3, 11284, 'Ian\'s Empty Bottle', '', 'Collecting', '', 1.25, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90583, 0, 0, 0, 0, 27843), -- Ian's Empty Bottle
(276242, 50, 48459, 'Anchor Weed', '', '', '', 0.65, 2862, 76087, 0, 0, 150, 150, 30, 0, 0, 0, 0, 0, 292, 1, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Anchor Weed
(282332, 5, 47685, 'Azerite', '', '', '', 0.7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Azerite
(287211, 5, 43221, 'Caromzar Cactus', '', '', '', 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Caromzar Cactus
(282445, 5, 47686, 'Azerite', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Azerite
(282418, 5, 48379, 'Azerite', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Azerite
(282449, 5, 48438, 'Cleaner Repair Kit', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Cleaner Repair Kit
(282444, 5, 9549, 'Sand Bags', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sand Bags
(278401, 25, 6435, 'Sand Shifter School', '', '', '', 1, 4, 77463, 3, 5, 1628, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sand Shifter School
(281872, 50, 48461, 'Sea Stalks', '', '', '', 1, 2862, 76083, 0, 0, 100, 150, 30, 0, 0, 0, 0, 0, 292, 1, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Sea Stalks
(296258, 8, 33316, 'Campfire', '', '', '', 0.7900001, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(294330, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(297494, 10, 13518, 'Tales of de Loa: Kimbul', 'inspect', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 7858, 0, 1, 280885, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Tales of de Loa: Kimbul
(284417, 50, 48632, 'Treasure Chest', '', '', '', 0.5, 1690, 87483, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2821, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(282498, 2, 48479, 'Desert Flute', 'questinteract', '', '', 1, 0, 21971, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Desert Flute
(289364, 10, 43249, 'Sethrak Cage', 'questinteract', 'Opening', '', 1.3, 43, 51389, 0, 3000, 0, 0, 0, 0, 0, 0, 270377, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 1, 0, 61570, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Cage
(277876, 10, 49138, 'Sethrak Cage', 'questinteract', 'Opening', '', 1.5, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 255799, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Cage
(277899, 10, 45230, 'Sethrak War Banner', 'questinteract', 'Burning', '', 1, 1690, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30602, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak War Banner
(296256, 8, 48031, 'Anvil', '', '', '', 0.8400005, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(296255, 8, 48031, 'Anvil', '', '', '', 0.84, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(296254, 8, 48976, 'Forge', '', '', '', 1, 3, 10, 215916, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(296554, 19, 50361, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mailbox
(296257, 8, 51464, 'Grill', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Grill
(287441, 2, 45786, 'Wanted: Sandscout Vesarik', '', '', '', 1, 0, 22054, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Wanted: Sandscout Vesarik
(277911, 10, 45524, 'Sethrak Spire', 'questinteract', 'Destroying', '', 1, 2668, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24585, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Spire
(278403, 25, 6435, 'Slimy Mackerel School', '', '', '', 1, 4, 77464, 3, 5, 1628, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Slimy Mackerel School
(296580, 3, 1128, 'Ofer\'s Bound Journal', '', 'Collecting', '', 0.75, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90586, 0, 0, 0, 0, 27843), -- Ofer's Bound Journal
(296581, 3, 51769, 'Skye\'s Pet Rock', '', 'Collecting', '', 1, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90587, 0, 0, 0, 0, 27843), -- Skye's Pet Rock
(273837, 3, 16155, 'Supply Pouch', 'questinteract', 'Collecting', '', 0.2, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 75994, 0, 0, 0, 0, 27843), -- Supply Pouch
(273834, 5, 44343, 'Troll Bones - Arm', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Troll Bones - Arm
(273836, 3, 14316, 'Backpack', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 75994, 0, 0, 0, 0, 27843), -- Backpack
(273835, 5, 44344, 'Troll Bones - Skeleton', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Troll Bones - Skeleton
(282740, 10, 29547, 'Mysterious Trashpile', 'questinteract', 'Rummaging', '', 2, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 266283, 0, 0, 0, 103044, 0, 0, 0, 0, 0, 1, 0, 56377, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mysterious Trashpile
(276394, 5, 44616, 'Stolen Relics', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stolen Relics
(276393, 5, 44616, 'Stolen Relics', '', '', '', 1.3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stolen Relics
(276392, 5, 43044, 'Stolen Relics', '', '', '', 1.3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stolen Relics
(281583, 2, 47974, 'Ancient Reliquary', 'questinteract', '', '', 0.5, 0, 21908, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Ancient Reliquary
(281552, 5, 34276, 'Polished Onyx', '', '', '', 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Polished Onyx
(281558, 3, 34276, 'Glittering Sapphire', 'questinteract', 'Collecting', '', 2, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 86269, 0, 0, 0, 0, 27843), -- Glittering Sapphire
(281639, 2, 51781, 'Crumbling Statue', '', '', '', 3, 0, 21907, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Crumbling Statue
(281634, 10, 6420, 'Cracked Stone Tablet', 'inspect', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 263680, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Cracked Stone Tablet
(291085, 5, 30824, 'Sand Base', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sand Base
(281229, 5, 48795, 'Magic Barrier', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843); -- Magic Barrier

UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=27843 WHERE `entry`=218384; -- Zandalari Crate 03

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=272622 AND `Idx`=0) OR (`GameObjectEntry`=287493 AND `Idx`=0) OR (`GameObjectEntry`=287490 AND `Idx`=0) OR (`GameObjectEntry`=275099 AND `Idx`=0) OR (`GameObjectEntry`=282636 AND `Idx`=0) OR (`GameObjectEntry`=282635 AND `Idx`=0) OR (`GameObjectEntry`=282633 AND `Idx`=0) OR (`GameObjectEntry`=282634 AND `Idx`=0) OR (`GameObjectEntry`=292784 AND `Idx`=0) OR (`GameObjectEntry`=282632 AND `Idx`=0) OR (`GameObjectEntry`=282631 AND `Idx`=0) OR (`GameObjectEntry`=290712 AND `Idx`=0) OR (`GameObjectEntry`=273837 AND `Idx`=0) OR (`GameObjectEntry`=273836 AND `Idx`=0) OR (`GameObjectEntry`=281558 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(272622, 0, 152659, 27843), -- Cursed Treasure
(287493, 0, 152659, 27843), -- Cursed Treasure
(287490, 0, 152659, 27843), -- Cursed Treasure
(275099, 0, 152647, 27843), -- Saurolisk Egg
(282636, 0, 158905, 27843), -- Sezahjin's Meat Pies
(282635, 0, 158904, 27843), -- Alpaca Hides
(282633, 0, 158903, 27843), -- Alpaca Butter
(282634, 0, 158901, 27843), -- Hyena Jerky
(292784, 0, 161241, 27843), -- Zandalari Dunemelons
(282632, 0, 158902, 27843), -- Fresh Water
(282631, 0, 158876, 27843), -- Medicinal Herbs
(290712, 0, 160515, 27843), -- Sandworn Blade
(273837, 0, 152601, 27843), -- Supply Pouch
(273836, 0, 152601, 27843), -- Backpack
(281558, 0, 157864, 27843); -- Glittering Sapphire


DELETE FROM `page_text` WHERE `ID` IN (7319 /*7319*/, 7318 /*7318*/, 7315 /*7315*/, 7314 /*7314*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(7319, 'Bwonsamdi be damned. He not be stopping the sethrak. No one be stopping them.\n\nExcept us. We got the power now.\n\nDrink deep, ye fiendish idols. Honor our bargain.\n\nThe Port of Zem\'lan be ours. Forever.', 0, 0, 0, 27843), -- 7319
(7318, 'It be even better then I thought.\n\nIf the sethrak set even one scaly foot here, I be ensuring them regret it for eternity.\n\nThe Port of Zem\'lan be mine or no one\'s!', 7319, 0, 0, 27843), -- 7318
(7315, 'Jamboya found something... powerful. Dark idols that whisper and pull at your insides when you be near.\n\nA perk of owning the black market. I get first taste of anything that comes through here, and these ones got real power.\n\nYoksa thinks he can perform a powerful ritual with them. Gonna test them on one of the refugees tonight. We see what happens.', 7318, 0, 0, 27843), -- 7315
(7314, 'It be only a matter of time until the filthy slitherers raid us.\n\nWe don\'t got enough crews to win a fair fight. Luckily, I don\'t fight fair.\n\nFirst Mate Jamboya be searching for our advantage in the remaining contraband caches, but the best goods have already been swindled.\n\nMy mighty port be reduced to this? Fighting over black market crumbs like scarabs? This cannot be. Pirate-King Zem\'lan don\'t beg for scraps.', 7315, 0, 0, 27843); -- 7314


DELETE FROM `npc_text` WHERE `ID` IN (32766 /*32766*/, 32767 /*32767*/, 34672 /*34672*/, 34539 /*34539*/, 34671 /*34671*/, 34538 /*34538*/, 32760 /*32760*/, 32759 /*32759*/, 32799 /*32799*/, 32703 /*32703*/, 32800 /*32800*/, 32704 /*32704*/, 32702 /*32702*/, 33574 /*33574*/, 35871 /*35871*/, 35099 /*35099*/, 36069 /*36069*/, 33314 /*33314*/, 33309 /*33309*/, 34263 /*34263*/, 34262 /*34262*/, 34261 /*34261*/, 34260 /*34260*/, 33320 /*33320*/, 33098 /*33098*/, 33099 /*33099*/, 33191 /*33191*/, 33232 /*33232*/, 32578 /*32578*/, 32860 /*32860*/, 33303 /*33303*/, 32362 /*32362*/, 35030 /*35030*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(32766, 1, 0, 0, 0, 0, 0, 0, 0, 136766, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32766
(32767, 1, 0, 0, 0, 0, 0, 0, 0, 136769, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32767
(34672, 1, 0, 0, 0, 0, 0, 0, 0, 152812, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34672
(34539, 1, 0, 0, 0, 0, 0, 0, 0, 152811, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34539
(34671, 1, 0, 0, 0, 0, 0, 0, 0, 151919, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34671
(34538, 1, 0, 0, 0, 0, 0, 0, 0, 151911, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34538
(32760, 1, 0, 0, 0, 0, 0, 0, 0, 136747, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32760
(32759, 1, 0, 0, 0, 0, 0, 0, 0, 136746, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32759
(32799, 1, 0, 0, 0, 0, 0, 0, 0, 136904, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32799
(32703, 1, 0, 0, 0, 0, 0, 0, 0, 136414, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32703
(32800, 1, 0, 0, 0, 0, 0, 0, 0, 136907, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32800
(32704, 1, 0, 0, 0, 0, 0, 0, 0, 136415, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32704
(32702, 1, 0, 0, 0, 0, 0, 0, 0, 136413, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32702
(33574, 1, 0, 0, 0, 0, 0, 0, 0, 143440, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33574
(35871, 1, 0, 0, 0, 0, 0, 0, 0, 160848, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35871
(35099, 1, 0, 0, 0, 0, 0, 0, 0, 156568, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35099
(36069, 1, 0, 0, 0, 0, 0, 0, 0, 161524, 0, 0, 0, 0, 0, 0, 0, 27843), -- 36069
(33314, 1, 0, 0, 0, 0, 0, 0, 0, 140747, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33314
(33309, 1, 0, 0, 0, 0, 0, 0, 0, 140761, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33309
(34263, 1, 0, 0, 0, 0, 0, 0, 0, 148986, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34263
(34262, 1, 0, 0, 0, 0, 0, 0, 0, 148985, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34262
(34261, 1, 0, 0, 0, 0, 0, 0, 0, 148984, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34261
(34260, 1, 0, 0, 0, 0, 0, 0, 0, 148983, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34260
(33320, 1, 0, 0, 0, 0, 0, 0, 0, 140779, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33320
(33098, 1, 0, 0, 0, 0, 0, 0, 0, 138589, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33098
(33099, 1, 0, 0, 0, 0, 0, 0, 0, 138615, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33099
(33191, 1, 0, 0, 0, 0, 0, 0, 0, 138833, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33191
(33232, 1, 1, 1, 1, 1, 0, 0, 0, 139978, 148965, 148966, 148968, 148971, 0, 0, 0, 27843), -- 33232
(32578, 1, 0, 0, 0, 0, 0, 0, 0, 135286, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32578
(32860, 1, 0, 0, 0, 0, 0, 0, 0, 137241, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32860
(33303, 1, 0, 0, 0, 0, 0, 0, 0, 140702, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33303
(32362, 1, 0, 0, 0, 0, 0, 0, 0, 133561, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32362
(35030, 1, 0, 0, 0, 0, 0, 0, 0, 156037, 0, 0, 0, 0, 0, 0, 0, 27843); -- 35030


