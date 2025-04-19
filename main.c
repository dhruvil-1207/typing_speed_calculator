#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>

int num_of_para = 10;
//Paragraphs to be printed when the easy level is selected.
char* easy_paragraphs[10] = {
    "The cat sat on the mat.",
    "I like to read books.",
    "She enjoys playing with her dog.",
    "The sun is shining brightly.",
    "This is a simple test sentence.",
    "He runs fast every morning.",
    "I am learning how to type.",
    "My house is near the park.",
    "The sky is blue today.",
    "She plays the piano well."
};

//Paragraphs to be printed when the medium level is selected.
char* medium_paragraphs[10] = {
    "The dog chased the ball across the yard while the kids watched.The dog was fast and energetic, enjoying the game.",
    "He was reading a book about space exploration and science.The book described the mysteries of black holes and galaxies.",
    "Typing speed is an important skill for many office jobs.It helps increase productivity and reduces time spent on tasks.",
    "She enjoys swimming in the pool on hot summer days.The cool water feels refreshing after a long, warm day.",
    "Writing is a great way to express your thoughts and ideas.Many writers use journaling as a method of personal reflection.",
    "The city streets were busy with people and cars during rush hour.The noise from traffic echoed through the urban landscape.",
    "Learning new skills every day helps improve your career prospects.Mastering new technologies and techniques is vital for success.",
    "The team worked hard to complete the project on time and within budget.They held multiple meetings to ensure everything was on track.",
    "It's always important to stay positive and motivated during challenges.Keeping a growth mindset helps in overcoming obstacles.",
    "The weather forecast predicts rain tomorrow afternoon.People should carry umbrellas to avoid getting wet in the showers."
};

//Paragraphs to be printed when the hard level is selected.
char* hard_paragraphs[10] = {
    "Quantum computing holds the potential to revolutionize industries by solving complex problems faster than classical computers. It uses quantum bits, or qubits, which can represent multiple states simultaneously—this allows quantum computers to tackle tasks like cryptography, optimization, and more efficiently. However, the technology is still in its early stages of development, and faces many challenges that hinder its widespread adoption in real-world applications, especially in areas like cryptographic security, artificial intelligence, and beyond.",
    
    "Artificial intelligence has made significant advancements in fields like natural language processing and computer vision. Machine learning algorithms are now able to recognize objects in images, understand human speech with remarkable accuracy, and even predict outcomes in various industries. These developments are driving progress in autonomous systems, healthcare, data analytics, robotics, and more. Despite its success, AI still requires ethical considerations regarding its impact on jobs, privacy, and potential misuse in surveillance or warfare.",
    
    "The future of autonomous vehicles relies heavily on machine learning algorithms and real-time data processing capabilities. Self-driving cars use sensors—like cameras, radar, and LiDAR—to perceive their environment and make driving decisions. Machine learning models enable the car to improve over time, learning from experiences, diverse road conditions, and unexpected challenges. As the technology advances, legal and safety regulations will play a significant role in its widespread adoption, while cybersecurity risks must also be addressed.",
    
    "Climate change is one of the most pressing issues facing the world today, with its effects on ecosystems, agriculture, and human societies. Rising temperatures, extreme weather events, and melting ice caps threaten biodiversity and biodiversity hotspots. Efforts to reduce greenhouse gas emissions through renewable energy sources—such as wind, solar, and hydropower—and conservation strategies are critical to mitigating the global impact of climate change. International cooperation, innovation, and policy changes will be necessary for long-term sustainability.",
    
    "The impact of globalization on economies is profound, with trade and technology playing central roles in shaping global markets. As nations become more interconnected, businesses have access to new markets, resources, and technologies, leading to greater efficiency and economic growth. However, globalization also brings challenges like income inequality, environmental degradation, and exploitation of labor in developing countries. Global supply chains and outsourcing have shifted manufacturing jobs to regions with lower labor costs, often at the expense of workers' rights and environmental standards.",
    
    "Understanding the fundamental principles of thermodynamics is essential for advancements in energy production, especially in sustainable technologies. The laws of thermodynamics govern the flow of energy in physical systems, dictating how heat and work are exchanged—these principles are critical for designing more efficient engines, power plants, and renewable energy systems. Innovations in energy generation, such as solar, wind, and geothermal power, rely on these principles to maximize efficiency and minimize waste, but improving energy storage and reducing environmental impact remain key challenges.",
    
    "Data privacy concerns are increasing as more personal information is shared online, raising questions about security, ethics, and the potential for abuse. Breaches in data security can lead to identity theft, financial loss, and significant privacy violations. Governments, corporations, and individuals must ensure robust encryption methods, transparent data collection policies, and effective privacy laws to protect users. Public awareness of privacy risks, along with personal responsibility in protecting data, are also important aspects of maintaining security in the digital world.",
    
    "Cybersecurity has become a critical aspect of modern technology, with constant efforts to protect systems from hacking, cyberattacks, and data breaches. As cyber threats evolve, businesses, governments, and organizations must implement advanced security measures—such as firewalls, encryption, multi-factor authentication, and real-time monitoring—to safeguard sensitive information. A single security breach can lead to significant financial loss, reputational damage, and legal consequences, making proactive defense strategies essential for maintaining trust in digital platforms.",
    
    "The development of new medical technologies, from genomics to telemedicine, is transforming healthcare, allowing for more personalized and efficient treatments. Advancements in wearable devices, remote monitoring, and artificial intelligence are enabling doctors to track patient health in real-time and offer tailored solutions to complex medical conditions. These innovations improve patient outcomes, reduce healthcare costs, and increase access to care in underserved regions. However, challenges remain, including regulatory approval, patient consent, and the protection of sensitive data.",
    
    "Exploring the deep ocean remains a major scientific challenge, as researchers work to uncover the mysteries of marine life, ecosystems, and underwater geology. The deep sea is home to a vast array of species, many of which remain undiscovered due to the extreme environmental conditions—high pressure, low temperature, and lack of light. Technological advancements in submersible vehicles, remote sensing tools, and data analytics are allowing scientists to explore previously inaccessible regions of the ocean floor. As ocean ecosystems are threatened by pollution, overfishing, and climate change, understanding their delicate balance is more important than ever to preserve biodiversity."
};

// Function that selects a random paragraph based on the selected level
int RandomPara(const char* level) {
    int random_index = 0;
    if (strcmp(level, "easy") == 0) {
        random_index = rand() % num_of_para;  // Random index for easy level
        printf("\n\n%s\n\n", easy_paragraphs[random_index]);
        return random_index;
    }
    else if (strcmp(level, "med") == 0) {
        random_index = rand() % num_of_para;  // Random index for medium level
        printf("\n\n%s\n\n", medium_paragraphs[random_index]);
        return random_index;

    }
    else if (strcmp(level, "hard") == 0) {
        random_index = rand() % num_of_para;  // Random index for hard level
        printf("\n\n%s\n\n", hard_paragraphs[random_index]);
        return random_index;

    }
    else {
        printf("Invalid level!\n"); // Prints "Invalid level!" if the input does not match any level
        return 0;

    }
}

// Function to count correctly typed characters and words
int comparison(int index, char* user, int length, char* level, float time) {
    int count = 0;
    float word_count = 0.0;
    int max_words = 200;

    // Choose the paragraph to compare based on the selected level
    char* comp_para;
    if(strcmp(level, "easy") == 0)
        comp_para = easy_paragraphs[index];
    else if(strcmp(level, "med") == 0)
        comp_para = medium_paragraphs[index];
    else if(strcmp(level, "hard") == 0)
        comp_para = hard_paragraphs[index];
    else {
        printf("Invalid level!\n");
        return -1;
    }

    // Count matching characters between user input and selected paragraph
    for (int i = 0; i < length; i++) {
        if (user[i] == comp_para[i]) {
            count++;
        }
    }

    // Split user input
    char* arr1[max_words];
    char* user_copy = strdup(user); // strtok modifies the string, so use a copy
    char* token = strtok(user_copy, " ");
    int i = 0;
    while (token != NULL) {
        arr1[i++] = token;
        token = strtok(NULL, " ");
    }

    // Split original paragraph
    char* arr2[max_words];
    char* para_copy = strdup(comp_para);
    token = strtok(para_copy, " ");
    int j = 0;
    while (token != NULL) {
        arr2[j++] = token;
        token = strtok(NULL, " ");
    }

    // Count matching words
    int word_limit = (i < j) ? i : j;
    for (int k = 0; k < word_limit; k++) {
        if (strcmp(arr1[k], arr2[k]) == 0) {
            word_count += 1.0;
        }
    }

    printf("\n\nYOUR RESULT:\n");
    printf("WPM: %.0f\n", (word_count * 60.0) / time);

    free(user_copy);
    free(para_copy);
    return count;
}

void main() {
    do {
    time_t start, end;
    double elapsed;
    srand(time(NULL)); 
    char level[6];
    // Asking the user to select a difficulty level
    printf("select level(easy/med/hard): ");
    scanf("%s",level);
    printf("\npress any key to start the test!");
    getch();
    printf("\nyour timer has started...");
    printf("\n\nenter the paragraph mentioned below:\n");

    // Calling the function to print a random paragraph based on level
    int index = RandomPara(level);
    int length;
    if(strcmp(level,"easy") == 0){
        length = strlen(easy_paragraphs[index]);
    }
    else if(strcmp(level,"med") == 0) {
        length = strlen(medium_paragraphs[index]);
    }
    else if(strcmp(level,"hard") == 0) {
        length = strlen(hard_paragraphs[index]);
    }
    getchar(); // Clear the input buffer
    char user[length+1];
    //start the timer
    time(&start);
    //get input untill enter is pressed
    scanf("%[^\n]", user);
    //stop the timer
    time(&end);

    // Calculate the time taken by the user
    float time = difftime(end, start); // end time - start time

    // Call the comparison function to calculate WPM and correct characters
    int mistakes = comparison(index, user, length, level, time);
    float accuracy = (mistakes * 100.0) / length; //calculating typing accuracy

    printf("Time taken: %.2f seconds\n", time);
    printf("accuracy: %.2f\%\n", accuracy);

    char exit[] = "yes";
    printf("\nYou want to test again?(yes/no): "); // Ask the user if they want to try again
    scanf(" %s", exit);
    if (strcmp(exit, "no") == 0) break;
    } while (true);

    printf("Thanks for joining :)");
}