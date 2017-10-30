-- Correct gossip menu option lines, text found in broadcast_text:
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (6186,6185,6187,6208,6209,6210,6211);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(6186, 0,0, "I am ready to discover where my fortune lies!",10047,1,1,6185,0,0,0,'',0),
(6185, 0,0, "I slay the man on the spot as my liege would expect me to do, as he is nothing more than a thief and a liar.", 10049,1,1,6187,0,0,0,'',0),
(6185, 1,0, "I turn over the man to my liege for punishment, as he has broken the law of the land and it is my sworn duty to enforce it.", 10050,1,1,6187,0,0,0,'',0),
(6185, 2,0, "I confiscate the corn he has stolen, warn him that stealing is a path towards doom and destruction, but I let him go to return to his family.", 10051,1,1,6187,0,0,0,'',0),
(6185, 3,0, "I allow the man to take enough corn to feed his family for a couple of days, encouraging him to leave the land.", 10052,1,1,6187,0,0,0,'',0),
(6187, 0,0, "I execute him as per my liege's instructions, and do it in such a manner that he suffers painfully before he dies as retribution for his crimes against my people.", 10075,1,1,6208,0,0,0,'',0),
(6187, 1,0, "I execute him as per my liege's instructions, but doing so in as painless of a way as possible.  Justice must be served, but I can show some compassion.", 10076,1,1,6208,0,0,0,'',0),
(6187, 2,0, "I risk my own life and free him so that he may prove his innocence.  If I can, I'll help him in any way.", 10077,1,1,6208,0,0,0,'',0),
(6208, 0,0, "I confront the ruler on his malicious behavior, upholding my liege's honor at the risk of any future diplomacy.", 10079,1,1,6209,0,0,0,'',0),
(6208, 1,0, "I not-so-quietly ignore the insult, hoping to instill a fear in the ruler that he may have gaffed.  I then inform my liege of the insult when I return.", 10080,1,1,6209,0,0,0,'',0),
(6208, 2,0, "I quietly ignore the insult.  I will not tell my liege, as I am to secure peace at all costs.  It's only an insult - not a declaration of war.", 10081,1,1,6209,0,0,0,'',0),
(6209, 0,0, "I would speak against my brother joining the order, rushing a permanent breach in our relationship.  He would be a danger to himself and those around him, and that is too great a risk hoping he would improve over time.", 10083,1,1,6210,0,0,0,'',0),
(6209, 1,0, "I would speak for my brother joining the order, potentially risking the safety of the order.  I could help him with the order's regimens, and I'd have faith in his ability to adapt and learn.", 10084,1,1,6210,0,0,0,'',0),
(6209, 2,0, "I would create some surreptitious means to keep my brother out of the order.  I can keep him out without him being any bit wiser, thereby saving our familial bonds.", 10085,1,1,6210,0,0,0,'',0),
(6210, 0,0, "I would show my liege the beast's ear and claim the beast's death as my own, taking the reward for my own use.  It is wrong to claim a deed as your own that someone else in fact did.", 10086,1,1,6211,0,0,0,'',0),
(6210, 1,0, "I would show my liege the beast's ear and claim the beast's death as my own - after all, I did slay it.  I would then offer some of the reward to the destitute knight to help his family.", 10088,1,1,6211,0,0,0,'',0),
(6210, 2,0, "I would remain silent about the kill and allow the knight to claim the reward to aid his family.", 10089,1,1,6211,0,0,0,'',0),
(6211, 0,0, "I'd love to get one of those written fortunes you mentioned!  I've got the space in my inventory for it.", 10091,1,1,0,0,0,0,'',0);
