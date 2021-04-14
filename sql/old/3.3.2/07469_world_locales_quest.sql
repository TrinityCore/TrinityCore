ALTER TABLE locales_quest ADD COLUMN CompletedText_loc1 text AFTER EndText_loc8;
ALTER TABLE locales_quest ADD COLUMN CompletedText_loc2 text AFTER CompletedText_loc1;
ALTER TABLE locales_quest ADD COLUMN CompletedText_loc3 text AFTER CompletedText_loc2;
ALTER TABLE locales_quest ADD COLUMN CompletedText_loc4 text AFTER CompletedText_loc3;
ALTER TABLE locales_quest ADD COLUMN CompletedText_loc5 text AFTER CompletedText_loc4;
ALTER TABLE locales_quest ADD COLUMN CompletedText_loc6 text AFTER CompletedText_loc5;
ALTER TABLE locales_quest ADD COLUMN CompletedText_loc7 text AFTER CompletedText_loc6;
ALTER TABLE locales_quest ADD COLUMN CompletedText_loc8 text AFTER CompletedText_loc7;
