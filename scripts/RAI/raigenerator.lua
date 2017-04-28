local RaiGenerator = {}

function RaiGenerator.new()
  --[[
  OVERVIEW
  SelectAdventurerDisplayID()
  --]]

  function RaiGenerator:SelectAdventurerDisplayID()
    local displays = {
      ["humans"] = {3363, 12954, 4395, 4393, 19228, 14668},
      ["nightelfs"] = {6868},
      ["dwarfs"] = {10471, 14668},
      ["gnomes"] = {14774, 6881},
      ["dreanais"] = {17427, 16789, 17027, 17410, 20109},
      ["undeads"] = {29204},
    }
    
    local combinedDisplays = {}

    for k, arr in pairs(displays) do 
      for i=1, #arr do 
        combinedDisplays[#combinedDisplays+1] = arr[i]
      end
    end

    return combinedDisplays[math.random(1, #combinedDisplays)]
  end

  return RaiGenerator
end

return RaiGenerator