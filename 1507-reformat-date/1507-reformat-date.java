import java.util.*;

class Solution {
    public String reformatDate(String date) {
        Map<String, String> monthMap = Map.ofEntries(
            Map.entry("Jan", "01"), Map.entry("Feb", "02"), Map.entry("Mar", "03"),
            Map.entry("Apr", "04"), Map.entry("May", "05"), Map.entry("Jun", "06"),
            Map.entry("Jul", "07"), Map.entry("Aug", "08"), Map.entry("Sep", "09"),
            Map.entry("Oct", "10"), Map.entry("Nov", "11"), Map.entry("Dec", "12")
        );

        String[] parts = date.split(" ");
        String day = parts[0].replaceAll("\\D", "");
        String month = monthMap.get(parts[1]);
        String year = parts[2];

        if (day.length() == 1) day = "0" + day;

        return year + "-" + month + "-" + day;
    }
}
