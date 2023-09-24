import React, { useState } from 'react';
import QuestionOne from '../../photos/QuestionsAnswers/QuestionOne.png';
import AnswerOne from '../../photos/QuestionsAnswers/AnswerOne.png';
import QuestionTwo from '../../photos/QuestionsAnswers/QuestionTwo.png';
import AnswerTwo from '../../photos/QuestionsAnswers/AnswerTwo.png';
import QuestionThree from '../../photos/QuestionsAnswers/QuestionThree.png';
import AnswerThree from '../../photos/QuestionsAnswers/AnswerThree.png';


function BannerImage() {
    const [hoveredItem, setHoveredItem] = useState(null);
    return (
      <>
        <div className="question-answer-container">
            <div className="question-container">
                <img 
                    src={QuestionOne} 
                    alt="Biology question." 
                    class="question"
                /> 
                <img 
                    src={AnswerOne} 
                    alt="Biology answer." 
                    onMouseEnter={() => setHoveredItem('questionOne')}
                    onMouseLeave={() => setHoveredItem(null)}
                    className={`answer ${hoveredItem === 'questionOne' ? 'active' : ''}`}
                    />
            </div>
            
            <div className="question-container">
                <img 
                    src={QuestionTwo} 
                    alt="Physics question." 
                    class="question"
                />
                <img
                    src={AnswerTwo}
                    alt="Physics Answer."
                    onMouseEnter={() => setHoveredItem('questionTwo')}
                    onMouseLeave={() => setHoveredItem(null)}
                    className={`answer ${hoveredItem === 'questionTwo' ? 'active' : ''}`}
                />
            </div>
            <div className="question-container">
                <img 
                    src={QuestionThree}
                    alt="Economics question."
                    class="question"
                />
                <img 
                    src={AnswerThree} 
                    alt="Economics question." 
                    onMouseEnter={() => setHoveredItem('questionThree')}
                    onMouseLeave={() => setHoveredItem(null)}
                    className={`answer ${hoveredItem === 'questionThree' ? 'active' : ''}`}

                />
            </div>
        </div>
      </>
    );
  }

export default BannerImage;