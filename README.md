# Closure_Automated-Blinds-System



Although we don't think much about it, light illuminance can be pretty important when it comes to maintaining a healthy lifestyle.

Natural light is important to our health and it allows us to see and experience the world around
us.

But at the same time, Over illumination has been linked to headaches,
fatigue, medically defined stress, and even anxiety

Because of this its recommended that certain illuminance levels are
maintained within different sectors of a household since its one of the most time spent places by a normal human being.

Other than the ordinary blinds and shades which work manually, There are quite a few devices already in the market which block natural light entering a room in an automated way.

As exmaples, sansa smart wand, Switchbot curtain, IKEA fyrtur, Lutrin serena, ive shown them in my slides as well but what these do is that it opens and folds blinds with respect to a time frame given by the user or else on command. Actually These work connected to a mobile app, or a remote specifically built for the device but the issue is what i mentioned earlier which is the illuminance level recommended to maintain, therfore the user would have to decide on whether the light is enough or not according to his preference and act accordingly so that the device works as needed by the user.

Closure provides all of it and on top of that there are some extra features that makes it special.




## Specialities


    1.The camera module which comes with the device would be able to identify the people ouccupying the room and adjust its settings according to priority. What i meant by priority is that when there are multiple people there would be an issue for the device to decide which set of settings to execute. So there would be order in which the settings are priritized depending on the person.
    
It was point out that phones can be used to identify the person in the room since we plan on developing a mobile app for the functionalities. But since a mobile phone would not be used at all times by a person, the system would not be able to adjust its settings accordingly. Therfore a camera based identification system would be the ideal choice.

    2. In addition, the users would be able to adjust settings in their own preference through a special mobile and connected to the device features and functionalities. These settings mainly consist of two types of modes. Which is auto and manual.

Manual mode is the one in which the user gets to decide when to open and close the blinds providing a specific time. Auto mode is the key feature focused through the device.

In auto mode, A sensor would be measureing the overoll illuminance level in the room, natural and artificial light combined, and balance out the natural light entering the room adjusting the blind levels.




## Project TimeLine

![image](https://user-images.githubusercontent.com/77055565/192230852-0549f6ae-f051-42b6-98a1-fb1c9fa4ea2b.jpg)




## Sensors used and their Configurations 

![Screenshot 2022-09-19 231100](https://user-images.githubusercontent.com/77055565/191079791-27ae389f-3905-44cb-8cd2-f8187a39d96f.png)

**NodeMCU ESP8266** would be used as the micro-controller for the device and the sensors would be connected accordingly.
**BH1750** is used as the main Light Sensor Used for detection of Illuminance in an indoor environment. I2C is used as the communication method.

![image](https://user-images.githubusercontent.com/77055565/191073987-1c251a4e-0f96-4dc8-9f5d-dcd9676680b2.png)


## Recommended Luminance Levels that needs to be maintained inside a household

Several Researches have been carried out by different parties in order to arrive at conclusions regarding lumminance levels that needs to be maintained in different sectors of a household. These v



alues would be directly connected with the human health that we have discussed above[1][2].



![Screenshot 2022-09-26 143736](https://user-images.githubusercontent.com/77055565/192237910-99259aac-b8da-4723-a72f-8a06ecc32adb.png)

The BH1750 Sensor Was initialized and made to balance the illuminance levels according to recomendded levels given in the research papers. The video below is a slight demonstration on how the system is implemented so far.

https://user-images.githubusercontent.com/77055565/199193488-96ac916a-cd35-4a17-b90e-af169e1418a1.mp4



## Facial Recognition

For the live feed, there can be two options for us to try on. Its either to use the laptop webcam as a prototype or else we can directly use ESP32-Cam module directly as the micro controller. But the only issure is that it doesn't provide much periferals as the ESP8266 and the availability factor should be checked with the IoT lab. For now just to test how it goes Open CV code has been analysed.

Few Steps should be considered when implementing Face Detection.

    Step 1: Access to webcam
    step 2: Face identification.
    step 3: Data collection
    Step 4: Training
    step 5: Face recognition
    step 6: Programming ESP8266
    
 
An openCV code has been extrected and applied as the first step in detecting people on live footages. That code has been enhanced in order to recognize people and to output the name of that particular person occupying the room. Google dataset search was used as an online resource on finding the appropriate dataset. In adition few familiar faces were used in training the model to get a more live feedback and to check whether the code actually works.


![Face Detection](https://user-images.githubusercontent.com/77055565/199195084-aaae4171-520d-4b9d-bc9b-cb9c449b7e4b.png)

## Refereneces
[1] - https://www.archtoolbox.com/recommended-lighting-levels/
[2] - https://www.luxgeneral-lighting.co.uk/recommended-lighting-levels/
