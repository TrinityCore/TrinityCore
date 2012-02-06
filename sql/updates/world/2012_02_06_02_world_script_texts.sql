DELETE FROM `script_texts` WHERE `entry` IN (-1601000, -1601001, -1601002, -1601003, -1601004, -1601005, -1601006, -1601007, -1601008, -1601009, -1601010);
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1601000,'I was king of this empire once, long ago. In life I stood as champion. In death I returned as conqueror. Now I protect the kingdom once more. Ironic, yes?',14053,1,0,0,'anubarak SAY_INTRO'),
(-1601001,'Eternal agony awaits you!',14054,1,0,0,'anubarak SAY_AGGRO'),
(-1601002,'You shall experience my torment, first-hand!',14055,1,0,0,'anubarak SAY_KILL_1'),
(-1601003,'You have made your choice.',14056,1,0,0,'anubarak SAY_KILL_2'),
(-1601004,'Soon, the Master\'s voice will call to you.',14057,1,0,0,'anubarak SAY_KILL_3'),
(-1601005,'Come forth, my brethren. Feast on their flesh!',14059,1,0,0,'anubarak SAY_SUBMERGE_1'),
(-1601006,'Auum na-l ak-k-k-k, isshhh.',14058,1,0,0,'anubarak SAY_SUBMERGE_2'),
(-1601007,'Your armor is useless against my locusts!',14060,1,0,0,'anubarak SAY_LOCUST_1'),
(-1601008,'The pestilence upon you!',14068,1,0,0,'anubarak SAY_LOCUST_2'),
(-1601009,'Uunak-hissss tik-k-k-k-k!',14067,1,0,0,'anubarak SAY_LOCUST_3'),
(-1601010,'Ahhh... RAAAAAGH! Never thought... I would be free of him...',14069,1,0,0,'anubarak SAY_DEATH');
