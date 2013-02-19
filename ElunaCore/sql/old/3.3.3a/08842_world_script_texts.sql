DELETE FROM script_texts where entry IN (-1000474, -1000475, -1000476);
INSERT INTO script_texts (`npc_entry`, `entry`, `content_default`, `type`, `language`, `comment`) VALUE
(17375, -1000474, '[Fulborg] The Stillpine furbolgs will not soon forget your bravery!', 0, 0, 'Stillpine Capitive free say text 1'),
(17375, -1000475, '[Fulborg] Thank you, $N', 0, 0, 'Stillpine Capitive free say text 2'),
(17375, -1000476, '[Fulborg] Those remaining at Stillpine Hold will welcome you as a hero!', 0, 0, 'Stillpine Capitive free say text 3');
