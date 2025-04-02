import time
import os
import platform

class SmartCitySimulator:
    def __init__(self):
        # Weights for smartness, functionality, and attractiveness
        self.criteria_weights = {
            "Infrastructure": 0.25,
            "Sustainability": 0.20,
            "Mobility": 0.05,
            "Health & Safety": 0.15,
            "Governance": 0.15,
            "Technology": 0.20
        }
        
        # Weights for functionality
        self.functionality_weights = {
            "Infrastructure": 0.30,
            "Sustainability": 0.05,
            "Mobility": 0.20,
            "Health & Safety": 0.20,
            "Governance": 0.20,
            "Technology": 0.05
        }
        
        # Weights for attractiveness - focus on the luxuries
        self.attractiveness_weights = {
            "Infrastructure": 0.25,
            "Sustainability": 0.15,
            "Mobility": 0.10,
            "Health & Safety": 0.15,
            "Governance": 0.05,
            "Technology": 0.30
        }

        self.max_focus_currency = 20  # Total focus currency
        self.focus_currency = self.max_focus_currency
        self.user_inputs = {}

    def clear_screen(self):
        # Check the operating system
        if platform.system() == "Windows":
            os.system('cls')  # Clear screen for Windows
        else:
            os.system('clear')  # Clear screen for Unix/Linux and macOS

    def display_criteria(self):
        ascii_art = """

 /$$$$$$$$ /$$                       /$$   /$$           /$$                                 /$$$$$$$  /$$                                                   /$$                      
|__  $$__/| $$                      | $$  | $$          | $$                                | $$__  $$| $$                                                  | $/                      
   | $$   | $$$$$$$   /$$$$$$       | $$  | $$  /$$$$$$ | $$$$$$$   /$$$$$$  /$$$$$$$       | $$  \ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$ |_/   /$$$$$$$            
   | $$   | $$__  $$ /$$__  $$      | $$  | $$ /$$__  $$| $$__  $$ |____  $$| $$__  $$      | $$$$$$$/| $$ |____  $$| $$__  $$| $$__  $$ /$$__  $$ /$$__  $$     /$$_____/            
   | $$   | $$  \ $$| $$$$$$$$      | $$  | $$| $$  \__/| $$  \ $$  /$$$$$$$| $$  \ $$      | $$____/ | $$  /$$$$$$$| $$  \ $$| $$  \ $$| $$$$$$$$| $$  \__/    |  $$$$$$             
   | $$   | $$  | $$| $$_____/      | $$  | $$| $$      | $$  | $$ /$$__  $$| $$  | $$      | $$      | $$ /$$__  $$| $$  | $$| $$  | $$| $$_____/| $$           \____  $$            
   | $$   | $$  | $$|  $$$$$$$      |  $$$$$$/| $$      | $$$$$$$/|  $$$$$$$| $$  | $$      | $$      | $$|  $$$$$$$| $$  | $$| $$  | $$|  $$$$$$$| $$           /$$$$$$$/            
   |__/   |__/  |__/ \_______/       \______/ |__/      |_______/  \_______/|__/  |__/      |__/      |__/ \_______/|__/  |__/|__/  |__/ \_______/|__/          |_______/             
                                                                                                                                                                                      
                                                                                                                                                                                      
                                                                                                                                                                                      
  /$$$$$$                                      /$$            /$$$$$$  /$$   /$$                      /$$$$$$  /$$                         /$$             /$$                        
 /$$__  $$                                    | $$           /$$__  $$|__/  | $$                     /$$__  $$|__/                        | $$            | $$                        
| $$  \__/ /$$$$$$/$$$$   /$$$$$$   /$$$$$$  /$$$$$$        | $$  \__/ /$$ /$$$$$$   /$$   /$$      | $$  \__/ /$$ /$$$$$$/$$$$  /$$   /$$| $$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ 
|  $$$$$$ | $$_  $$_  $$ |____  $$ /$$__  $$|_  $$_/        | $$      | $$|_  $$_/  | $$  | $$      |  $$$$$$ | $$| $$_  $$_  $$| $$  | $$| $$ |____  $$|_  $$_/   /$$__  $$ /$$__  $$
 \____  $$| $$ \ $$ \ $$  /$$$$$$$| $$  \__/  | $$          | $$      | $$  | $$    | $$  | $$       \____  $$| $$| $$ \ $$ \ $$| $$  | $$| $$  /$$$$$$$  | $$    | $$  \ $$| $$  \__/
 /$$  \ $$| $$ | $$ | $$ /$$__  $$| $$        | $$ /$$      | $$    $$| $$  | $$ /$$| $$  | $$       /$$  \ $$| $$| $$ | $$ | $$| $$  | $$| $$ /$$__  $$  | $$ /$$| $$  | $$| $$      
|  $$$$$$/| $$ | $$ | $$|  $$$$$$$| $$        |  $$$$/      |  $$$$$$/| $$  |  $$$$/|  $$$$$$$      |  $$$$$$/| $$| $$ | $$ | $$|  $$$$$$/| $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$      
 \______/ |__/ |__/ |__/ \_______/|__/         \___/         \______/ |__/   \___/   \____  $$       \______/ |__/|__/ |__/ |__/ \______/ |__/ \_______/   \___/   \______/ |__/      
                                                                                     /$$  | $$                                                                                        
                                                                                    |  $$$$$$/                                                                                        
                                                                                     \______/                                                                                         
                                                         
        """
        print(ascii_art)
        print(f"\nTotal Focus Currency: {self.focus_currency}\n")

    def type_out_text(self, text, delay=0.05):
        for char in text:
            print(char, end="", flush=True)
            time.sleep(delay)
        print()  # Print newline at the end

    def collect_inputs(self):
        for criterion in self.criteria_weights:
            while True:
                try:
                    self.type_out_text(f"How much focus (0-5) do you give to {criterion}?")
                    value = float(input(f"Enter a value for {criterion} (out of {self.focus_currency}): "))
                    
                    if value < 0 or value > 5:
                        print("Value must be between 0 and 5.")
                        continue
                    
                    if value > self.focus_currency:
                        print(f"You have {self.focus_currency} focus currency left. Please enter a value within this limit.")
                        continue
                    
                    self.user_inputs[criterion] = value
                    self.focus_currency -= value
                    break
                except ValueError:
                    print("Invalid input. Please enter a numeric value.")

    def calculate_score(self, weights):
        score = 0
        for criterion, value in self.user_inputs.items():
            weighted_score = (value / 5) * weights[criterion]
            score += weighted_score
        return score * 100  # Convert to percentage

    def run_simulation(self):
        self.clear_screen()  # Clear the terminal screen
        self.display_criteria()
        self.collect_inputs()
        
        # Calculate scores for smartness, functionality, and attractiveness
        smartness_score = self.calculate_score(self.criteria_weights)
        functionality_score = self.calculate_score(self.functionality_weights)
        attractiveness_score = self.calculate_score(self.attractiveness_weights)

        print(f"\nYour Smart City Scores:")
        print(f"Smartness Score: {smartness_score:.2f}%")
        print(f"Functionality Score: {functionality_score:.2f}%")
        print(f"Attractiveness Score: {attractiveness_score:.2f}%")

        # Evaluate the results
        for score, label in zip([smartness_score, functionality_score, attractiveness_score], 
                                ["Smartness", "Functionality", "Attractiveness"]):
            if score >= 80:
                print(f"{label}: Excellent!")
            elif score >= 60:
                print(f"{label}: Good.")
            else:
                print(f"{label}: Needs improvement.")


if __name__ == "__main__":
    simulator = SmartCitySimulator()
    simulator.run_simulation()
