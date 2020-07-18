-- Stone Is Better than Cloth: Use actual player name ($N) instead of "Orthanc"
UPDATE `quest_request_items` SET `CompletionText`= "I wouldn't wait too long to get that bracer, $N.$b$bWho knows what's going to happen next?" WHERE `ID`=716;
