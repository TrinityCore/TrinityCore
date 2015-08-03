DELETE FROM `page_text` WHERE `entry` IN (3611,3612,3613,3280,3281,3282) AND `WDBVerified`=1;
DELETE FROM `page_text` WHERE `entry`=9999;
INSERT INTO `page_text` (`entry`, `text`, `next_page`,`WDBVerified`) VALUES
(3611, 'When the flames consume Azeroth, where will you be?\r\n\r\nWe know that no one wants to dwell on their impending doom, but it''s worth thinking about where you''ll be spending the hereafter.\r\n\r\nOur sages have predicted that the end of the world is nigh, and only the prepared will survive. We can help you survive the raging inferno that will cleanse this world of the wicked. Isn''t it time you found some peace of mind?', 0,1),
(3612, 'You''ve no doubt heard the phrase "all good things must come to an end" and so it is with your life on Azeroth. It won''t be long before the world erupts into chaos as the elements reclaim their birthright.\r\n\r\nBut you don''t have to be afraid during these harrowing times. You don''t have to die. We can help you ascend to a new way of life, beyond death, beyond fear, and beyond the powerlessness of mortality. Join us today.', 0,1),
(3613, 'We live in tumultuous times. War, invasion, and famine have swept the world, but the real trial is yet to come: the end of Azeroth itself.\r\n\r\nHow will you cope with the loss and destruction of everything you hold dear? The answer is that you don''t have to. Bring your friends and family to one of our gatherings and learn how you can survive the apocalypse together, with us.', 0,1),
(3280, 'Long ago, when the North Wind ruled these peaks alone, a powerful Taunka Chieftain''s brother coveted these lands for himself.', 0,1),
(3281, 'The Chieftain''s brother, Stormhoof gathered all his strength and set out to conquer the Storm Peaks from its rightful ruler, the North Wind.', 0,1),
(3282, 'Stormhoof ambushed the North Wind in the heart of it''s domain, and nearly succeeded in his plot. But the North Wind survived Stormhoof''s treachery and executed the Taunka as punishment for his invasion.', 0,1);

UPDATE `page_text` SET `text`='Missing WDB data.',`WDBVerified`=1 WHERE `entry` IN (3487,3469,3454,3403,3346,3079,3562,2822);
