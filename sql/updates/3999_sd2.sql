DELETE FROM script_texts WHERE entry BETWEEN -1000342 AND -1000340;
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000340, 'We made it! Thanks, $N. I couldn''t have gotten without you.', 0, 0, 0, 0, 'npc_deathstalker_erland - SAY_THANKS'),
(-1000341, 'It''s good to see you again, Erland. What is your report?', 0, 0, 0, 0, 'npc_deathstalker_erland - SAY_RANE'),
(-1000342, 'Masses of wolves are to the east, and whoever lived at Malden''s Orchard is gone.', 0, 0, 0, 0, 'npc_deathstalker_erland - SAY_ANSWER');