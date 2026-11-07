-- Quest "What We Don't Know..." (9756) is missing "CompletionText".
UPDATE `quest_request_items` SET `CompletionText`="Do not return until you have succeeded!" WHERE `ID`=9756;

-- Quest "Matis the Cruel" (9711) is missing "CompletionText"
UPDATE `quest_request_items` SET `CompletionText`="A soldier of Matis' stature won't be traveling alone. Be careful out there." WHERE `ID`=9711;
