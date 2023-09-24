import React from 'react';
import './aboutus.css';
import Logo from '../../photos/QuizWizLogo.png';

const AboutUs = () => {
    return (
      <>
        <div className="container-aboutus">
          <h1>About Us</h1>
          <div className="container-aboutus-flex">
            <div className="aboutus-content">
              <h2>About QuizWiz:</h2>
              <p>QuizWiz is an application developed by four students </p>
            </div>
            <img src={ Logo } alt="QuizWiz Logo" />
          </div>
        </div>
      </>
    );
  }
  
  export default AboutUs;