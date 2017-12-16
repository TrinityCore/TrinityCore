-- Put "claw" instead of "head" in the Progress gossip of quest 6162, A Husband's Last Battle
UPDATE `quest_request_items` SET `CompletionText` = "Do you have the beast's claw yet, $N? It will pay for its crimes. I don't care if it's corrupt or just angry for living in such a dismal forest. No furbolg will live for long committing such crimes against my family!" WHERE `ID`= 6162;
