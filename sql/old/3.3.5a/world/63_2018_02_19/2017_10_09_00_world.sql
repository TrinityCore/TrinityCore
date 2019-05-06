-- Thrallmar: Report to Nazgrel (10875)
UPDATE `quest_offer_reward` SET `RewardText`= "It is good to hear of all your moves against the fel orcs, $N.  The apothecaries have spent much time and resources studying the cause of their corruption, and although such information is invaluable... my orc blood burns to strike a severe blow against these betrayers!$b$bListen close, and I will explain my task..." WHERE `ID`=10875;

-- Shadowmoon Village: Chief Apothecary Hildagard, Spectrecles (10625)
UPDATE `quest_offer_reward` SET `RewardText`="Gorefiend? T... Teron Gorefiend? But... How?$b$bHow could Gorefiend be here? This is impossible!$b$bThe legend of Teron Gorefiend is one that causes even the Forsaken to tremble in fear. By all accounts, Gorefiend was a warlock of Gul'dan - extremely powerful in his own right. When Gorefiend was slain by Orgrim Doomhammer, Gul'dan took the soul of the fallen warlock and placed it inside the broken shell of a slain knight of Stormwind. And so was born the first death knight of the Horde." WHERE `ID`=10625;

-- Researcher Tiorus, Felspine the Greater (10673)
UPDATE `quest_request_items` SET `CompletionText`="Snap to it! That gnome's appetite knows no limit!" WHERE `ID`=10673;

-- Before Darkness Falls (10878)
UPDATE `quest_offer_reward` SET `RewardText`="I can breathe a sigh of relief for now, $N.  The Shadow Council will be held off for the time being.$b$bThey are murderers and cowards and your display of courage will keep them at bay." WHERE `ID`=10878;
