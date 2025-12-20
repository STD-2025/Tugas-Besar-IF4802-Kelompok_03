#include "random_data.h"

const std::vector<std::string> passengerNames = {
    "James", "Liam", "Noah", "Oliver", "Elijah", "William",
    "Benjamin", "Lucas", "Henry", "Alexander", "Mason", "Michael",
    "Ethan", "Daniel", "Jacob", "Logan", "Jackson", "Levi",
    "Sebastian", "Mateo", "Jack", "Owen", "Theodore", "Aiden",
    "Samuel", "Joseph", "John", "David", "Wyatt", "Matthew",
    "Luke", "Asher", "Carter", "Julian", "Grayson", "Leo",
    "Jayden", "Gabriel", "Isaac", "Lincoln", "Anthony", "Hudson",
    "Dylan", "Ezra", "Thomas", "Charles", "Christopher", "Jaxon",
    "Maverick", "Josiah", "Isaiah", "Andrew", "Elias", "Joshua",
    "Nathan", "Caleb", "Ryan", "Adrian", "Miles", "Eli",
    "Nolan", "Christian", "Aaron", "Cameron", "Ezekiel", "Colton",
    "Luca", "Landon", "Hunter", "Santiago", "Axel", "Easton",
    "Cooper", "Jeremiah", "Angel", "Roman", "Connor", "Jameson",
    "Robert", "Greyson", "Jordan", "Ian", "Carson", "Jaxson",
    "Leonardo", "Nicholas", "Dominic", "Austin", "Everett", "Brooks",
    "Xavier", "Kai", "Jose", "Parker", "Adam", "Jace",
    "Wesley", "Kayden", "Silas", "Bennett", "Declan", "Waylon",
    "Weston", "Evan", "Emmett", "Micah", "Ryder", "Beau",
    "Damian", "Jonah", "Brayden", "Gael", "Ivan", "Francisco",
    "Thiago", "Max", "Diego", "Rafael", "Rowan", "Kaleb",
    "Luis", "Archer", "Jasper", "Enzo", "Messiah", "Malachi",
    "Maddox", "Kingston", "Malcolm", "Gavin", "Paul", "Pedro",
    "Rory", "Soren", "Orion", "Atticus", "Marcus", "Victor",
    "Felix", "Hector", "Oscar", "Ruben", "Sergio", "Mateus",
    "Fabian", "Hugo", "Andres", "Matteo", "Amir", "Omar",
    "Ibrahim", "Hassan", "Samir", "Zayd", "Kian", "Rayan",
    "Sami", "Asha", "Maya", "Sophia", "Olivia", "Emma",
    "Ava", "Isabella", "Mia", "Amelia", "Harper", "Evelyn",
    "Abigail", "Emily", "Ella", "Elizabeth", "Camila", "Luna",
    "Sofia", "Avery", "Mila", "Aria", "Scarlett", "Penelope",
    "Layla", "Chloe", "Victoria", "Madison", "Eleanor", "Grace",
    "Nora", "Riley", "Zoey", "Hannah", "Hazel", "Lily",
    "Ellie", "Violet", "Lillian", "Zoe", "Stella", "Aurora",
    "Natalie", "Emilia", "Everly", "Leah", "Aubrey", "Willow",
    "Addison", "Lucy", "Audrey", "Anna", "Samantha", "Caroline",
    "Genesis", "Aaliyah", "Kennedy", "Kinsley", "Allison", "Sarah",
    "Madelyn", "Adeline", "Alexa", "Arianna", "Elena", "Gabriella",
    "Naomi", "Alice", "Sadie", "Hailey", "Eva", "Clara",
    "Cora", "Ivy", "Ruby", "Serenity", "Autumn", "Piper",
    "Sienna", "Jade", "Mckenna", "Melody", "Sloane", "Harley",
    "Dakota", "Skye", "June", "Raven", "Rosa", "Yara",
    "Leila", "Farah", "Fatima", "Aisha", "Priya", "Ananya",
    "Sana", "Meera", "Isha", "Neha", "Kavya", "Simran",
    "Xinyi", "Yuna", "Sakura", "Hana", "Mina", "Aiko",
    "Yuri", "Soo", "Ji", "Min", "Hyun", "Hye",
    "Mi", "Svetlana", "Anastasia", "Olga", "Irina", "Ekaterina",
    "Ingrid", "Astrid", "Frida", "Greta", "Helga", "Isla",
    "Imani", "Amina", "Nadia", "Amara", "Ngozi", "Chinara",
    "Fatou", "Ama", "Zainab", "Hawa", "Adwoa", "Kwame",
    "Kofi", "Ade", "Chike", "Ifeanyi", "Thabo", "Mandisa",
    "Zola", "Sibusiso", "Musa", "Adebayo", "Oluwaseun", "Emeka",
    "Chinedu", "Amadou", "Mckenna", "Lena", "Nina", "Tessa",
    "Miriam", "Bianca", "Sofia", "Cecilia", "Leona", "Helena",
    "Paula", "Rosa", "Mariana", "Isabel", "Lucia", "Catalina",
    "Monica", "Valeria", "Liliana", "Adriana", "Estela", "Noemi",
    "Rita", "Claudia", "Marta", "Silvia", "Beatriz", "Raquel",
    "Lorena", "Marisol", "Yolanda", "Paloma", "Arielle", "Nora",
    "Talia", "Mira", "Sanae", "Kira", "Maya", "Rina",
    "Yuki", "Keiko", "Mai", "Nao", "Etsuko", "Miho",
    "Yasmin", "Lina", "Ari", "Zara", "Lola", "Maya",
    "Ivy", "Nora", "Diana", "Erin", "Olive", "Iris",
    "Mabel", "Fiona", "Giselle", "Ramona", "Bianca", "Celeste",
    "Daphne", "Elise", "Gwen", "Holly", "Ilana", "Jocelyn",
    "Kelsey", "Lydia", "Marin", "Nadia", "Ophelia", "Quinn",
    "Rowena", "Selah", "Thalia", "Uma", "Vera", "Willa",
    "Ximena", "Yvette", "Zoe", "Ariya", "Brielle", "Celia",
    "Delilah", "Eden", "Fern", "Giana", "Hanae", "Indira",
    "Jada", "Kaia", "Lana", "Maia", "Nola", "Odessa",
    "Pippa", "Quiana", "Reina", "Sabine", "Tori", "Ursula",
    "Violeta", "Wendy", "Xara", "Yelena", "Zadie", "Abel",
    "Alonzo", "Arman", "Boris", "Bruno", "Cyrus", "Dimitri",
    "Dante", "Emiliano", "Fabio", "Gustavo", "Hugo", "Iker",
    "Jordi", "Klaus", "Lorenzo", "Matias", "Nico", "Orlando",
    "Pablo", "Quentin", "Rafael", "Salvador", "Thierry", "Ulises",
    "Valentino", "Walid", "Xander", "Yahir", "Zayn", "Alden",
    "Blaine", "Cillian", "Dorian", "Eamon", "Fletcher", "Gideon",
    "Harlan", "Ilan", "Jalen", "Kellan", "Leif", "Magnus",
    "Nevin", "Orson", "Percy", "Quincy", "Rosco", "Sterling",
    "Tate", "Ugo", "Vaughn", "Wes", "Xeno", "Yves",
    "Zeke", "Rowland", "Piers", "Amias", "Benson", "Cory",
    "Dallas", "Efrain", "Franco", "Galen", "Heath", "Isaias",
    "Joaquin", "Korben", "Lamont", "Marcel", "Niklas", "Odin",
    "Perry", "Quint", "Ronan", "Stuart", "Tristan", "Uriah",
    "Vito", "Westin", "Xavian", "Yarden", "Zared", "Alessio",
    "Brennan", "Cassian", "Dario", "Emery", "Finnegan", "Grady",
    "Hendrix", "Lucian"
};

const std::vector<std::string> busNames = {
    "Atlas Line", "Orion Express", "Nova Transit", "Falcon Way", "Horizon Link",
    "Titan Route", "Comet Shuttle", "Apex Bus", "Vector Transit", "Summit Line",
    "Polaris Express", "Voyager Route", "Eclipse Bus", "MetroSwift", "Silverline Transit",
    "Crossway Express", "UrbanStar", "Skyway Bus", "Ironclad Route", "Northwind Line",

    "Eastgate Transit", "Westbound Express", "Southridge Bus", "Northcrest Line", "BlueArrow Transit",
    "Redstone Route", "Goldleaf Express", "Harborway Bus", "Ridgepoint Line", "CityPulse",

    "RapidWay", "MetroLinker", "StreetRunner", "UrbanLoop", "CityGlide",
    "Roadspire", "Wayfarer Line", "TransitCore", "Velocity Bus", "Swiftline",

    "Crown Route", "Keystone Express", "Landmark Transit", "Pathway Bus", "Greenfield Line",
    "Oakridge Express", "Pinecrest Route", "Riverbend Transit", "Brookstone Line", "Hilltop Bus",

    "Grandway", "PrimeRoute", "Unity Transit", "Everline", "Clearway Express",
    "CityAxis", "Gridline Bus", "Mainstreet Route", "Capital Transit", "UrbanEdge",

    "Crosslink Express", "Jetway Bus", "Starpath Line", "Coreway Transit", "Midtown Express",
    "Downtown Loop", "Uptown Route", "Skyline Transit", "Borough Line", "District Express",

    "Ironway", "Steelroute", "Copperline", "Platinum Transit", "Sapphire Route",
    "Emerald Express", "Ruby Line", "Onyx Bus", "Quartz Transit", "Crystalway",

    "Sunrise Express", "Sunset Line", "Daybreak Route", "Nightfall Transit", "Moonline Bus",
    "Starlight Express", "Aurora Route", "Dawnway", "Twilight Transit", "Horizon Nightline",

    "Pathfinder", "Trailblazer Bus", "Frontline Express", "Pioneer Route", "Explorer Transit",
    "Nomad Line", "Venture Bus", "Odyssey Express", "Passageway", "Crossroad Transit",

    "MetroDrive", "Roadlink Express", "Pathline", "Waypoint Bus", "CityTrack",
    "RouteMaster", "TransitWay", "Streetline", "Roadcraft", "CityVoyage",

    "Arrowhead Express", "Longhaul Line", "Fastlane Transit", "Overland Bus", "Milepost Route",
    "Turnpike Express", "Highway Line", "Freeway Transit", "Parkway Bus", "Bypass Route",

    "Cornerstone Transit", "Stronghold Express", "Bridgeway Line", "Gateway Bus", "Threshold Transit",
    "Entryway Express", "Passline", "Linkpoint Bus", "Connector Route", "Junction Transit",

    "Silvercrest Line", "Goldpath Express", "Bronze Route", "Ironpeak Transit", "Stoneway Bus",
    "Brickline Express", "Mason Route", "Foundry Transit", "Forgeway", "Anvil Express",

    "Crestline", "Ridgeway Transit", "Valley Express", "Lowland Route", "Plainview Bus",
    "Highland Transit", "Summit Ridge Line", "Peakway Express", "Canyon Route", "Basin Transit",

    "Cityward", "Townlink Express", "Boroughway", "Suburb Transit", "Ringroad Bus",
    "Loopline Express", "Radial Route", "Spokeway Transit", "Gridway", "Network Line",

    "Northstar Express", "Southstar Route", "Eaststar Transit", "Weststar Line", "Cardinal Bus",
    "Meridian Express", "Latitude Route", "Longitude Transit", "Compass Line", "Bearing Bus",

    "TransitOne", "RouteTwo", "LineThree", "BusFour", "WayFive",
    "PathSix", "LinkSeven", "MoveEight", "FlowNine", "GoTen",

    "VelocityOne", "VelocityTwo", "VelocityThree", "VelocityFour", "VelocityFive",
    "VelocitySix", "VelocitySeven", "VelocityEight", "VelocityNine", "VelocityTen",

    "MetroAlpha", "MetroBeta", "MetroGamma", "MetroDelta", "MetroEpsilon",
    "MetroZeta", "MetroEta", "MetroTheta", "MetroIota", "MetroKappa",

    "TransitPrime", "TransitNova", "TransitUltra", "TransitMax", "TransitCore",
    "TransitEdge", "TransitFlow", "TransitAxis", "TransitPulse", "TransitWave",

    "Busline Alpha", "Busline Beta", "Busline Gamma",
    "Busline Delta", "Busline Sigma", "Busline Omega"
};

const std::vector<std::string> busStops = {
    "Merdeka", "Sudirman", "Thamrin", "Gatot Subroto", "Asia Afrika",
    "Cendrawasih", "Pahlawan", "Diponegoro", "Ahmad Yani", "Juanda",

    "Senayan", "Blok M", "Kuningan", "Tebet", "Manggarai",
    "Tanah Abang", "Pasar Baru", "Harmoni", "Kota Tua", "Monas",

    "Rawamangun", "Kelapa Gading", "Sunter", "Ancol", "Pluit",
    "Cawang", "Kalideres", "Slipi", "Palmerah", "Lebak Bulus",

    "Fatmawati", "Cipete"
};