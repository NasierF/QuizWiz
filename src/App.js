import NavBar from './UI/NavBar/NavBar.js';
import './UI/NavBar/NavBar.css';
import './App.css';
import CalculatorImage from './photos/ti84.png';
import { BrowserRouter as Router, Routes, Route, Link } from 'react-router-dom';
import MeetTheTeam from './pages/MeetTheTeam/MeetTheTeam.js';
import QuestionAnswers from './UI/QuestionAnswers/QuestionAnswers.js';
import './UI/QuestionAnswers/QuestionAnswers.css';
import FlashCards from './pages/FlashCards/FlashCards.js';
import Footer from './UI/Footer/Footer.js';

function App() {
  return (
    <Router>
      <NavBar />
      <Routes>
        <Route path="/" element={<HomePage />} />
        <Route path="/pages/MeetTheTeam/MeetTheTeam.js" element={<MeetTheTeam />} />
        <Route path="/pages/FlashCards/FlashCards.js" element={<FlashCards />} />
      </Routes>
    </Router>
  );
}

  const HomePage = () => {
    return (
      <>
        <div className="main-container">
          <div>
            <h1>Are you looking <br></br>to study between <br></br>classes?</h1>
          </div>
          <div className="calculator-container">
            <img src={CalculatorImage} alt="The texas ti-84 calculator" className="calculator-image" />
          </div>
        </div>
        <div className="questions-container">
          <h2>QuizWiz is the new revolutionary software <br></br>bringing flashcards to the calculator</h2>
          <h4>(Hover Over Cards For Answers)</h4>
          <QuestionAnswers />
          <div className="flashcard-container">
            <h2 class="flashcard-container-title">Make Your First Set Today!</h2>
            <Link class="flash-card-button" to="/pages/FlashCards/FlashCards.js">Flash Cards</Link>
        </div>
        <Footer />
        </div>
      </>
    );
  }

export default App;
