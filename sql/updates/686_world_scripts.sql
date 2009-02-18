UPDATE `creature_template` SET `Scriptname`='npc_willix' WHERE entry=4508;

DELETE FROM script_texts WHERE entry BETWEEN -1047000 and -1047010;
INSERT INTO script_texts (entry, content_default, sound, type, language, comment) VALUES
(-1047000, 'Phew! Finally,out here. However, it will not become easy. Detain your eyes after annoyance.', 0, 0, 0, 'Willix'),
(-1047001, 'There on top resides Charlga Razorflank. The damned old Crone.', 0, 0, 0, 'Willix'),
(-1047002, 'Help! Get this Raging Agam\'ar from me!', 0, 0, 0, 'Willix'),
(-1047003, 'In this ditch there are Blueleaf Tuber! As if the gold waited only to be dug out, I say it you!', 0, 0, 0, 'Willix'),
(-1047004, 'Danger is behind every corner.', 0, 0, 0, 'Willix'),
(-1047005, 'I do not understand how these disgusting animals can live at such a place.... puh as this stinks!', 0, 0, 0, 'Willix'),
(-1047006, 'I think, I see a way how we come out of this damned thorn tangle.', 0, 0, 0, 'Willix'),
(-1047007, 'I am glad that we are out again from this damned ditch. However, up here it is not much better!', 0, 0, 0, 'Willix'),
(-1047008, 'Finally! I am glad that I come, finally out here.', 0, 0, 0, 'Willix'),
(-1047009, 'I will rather rest a moment and come again to breath, before I return to Ratchet.', 0, 0, 0, 'Willix'),
(-1047010, 'Many thanks for your help.', 0, 0, 0, 'Willix');

