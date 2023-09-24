import React from 'react';
import './MeetTheTeam.css';
import Logo from '../../photos/QuizWizLogo.png';
import TeamBios from '../../UI/TeamBios/TeamBios.js';
import '../../UI/TeamBios/TeamBios.css';
import ColeHeadShot from '../../photos/HeadShots/ColeRobertsHS.png';
import NasierHeadShot from '../../photos/HeadShots/NasierFowlkesHS.png';
import JacobShinHeadShot from '../../photos/HeadShots/JacobShinHS.jpeg';
import MalinkKussiHeadShot from '../../photos/HeadShots/MalinKussiHS.png';
import Footer from '../../UI/Footer/Footer.js';


const MeetTheTeam = () => {
    return (
      <>
        <div className="Meet-The-Team-Title">
          <h1>Meet The Team</h1>
        </div>
        <TeamBios 
        BioPhotoOne={NasierHeadShot}
        OneAlt={"Collaborator Nasier Fowlkes"}
        OneName={"Nasier Fowlkes"}
        OneBio={
        <ul>
          <li><a href="https://www.linkedin.com/in/nasierfowlkes/" target="_Blank">LinkedIn</a></li>
          <li><a href="https://github.com/NasierF" target="_Blannk">GitHub</a></li>
        </ul>
        }
        
        BioPhotoTwo={JacobShinHeadShot}
        TwoAlt={"Collaborator Jacob Shin"}
        TwoName={"Jacob Shin"}
        TwoBio={
        <ul>
          <li><a href="https://www.linkedin.com/in/jacob-shin/" target="_Blank">LinkedIn</a></li>
          <li><a href="https://github.com/jshin313" target="_Blank">GitHub</a></li>
        </ul>
          }        
        />
        <TeamBios 
        BioPhotoOne={MalinkKussiHeadShot}
        OneAlt={"Collaborator Malin Kussi"}
        OneName={"Malin Kussi"}
        OneBio={
        <ul>
          <li><a href="https://www.linkedin.com/in/malin-kussi-064643292/" target="_Blank">LinkedIn</a></li>
          <li><a href="https://github.com/monty2464" target="_Blank">GitHub</a></li>
        </ul>
        }
        
        BioPhotoTwo={ColeHeadShot}
        TwoAlt={"Collaborator Cole Roberts"}
        TwoName={"Cole Roberts"}
        TwoBio={
          <ul>
            <li><a href="https://www.linkedin.com/in/cole-alexanders/" target="_Blank">LinkedIn</a></li>
            <li><a href="https://github.com/colealexanders" target="_Blank">GitHub</a></li>
          </ul>
        }        
        />
        <Footer />
      </>
    );
  }
  
  export default MeetTheTeam;