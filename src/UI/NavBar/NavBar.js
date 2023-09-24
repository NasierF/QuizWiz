import logo from '../../photos/QuizWizLogo.png';
import './NavBar.css';
import { Link } from 'react-router-dom';

function NavBar() {
    return (
        <>
        <header>
            <nav className="nav-bar">
                <Link to="/" className="company-logo">
                    <img src = {logo} alt="Company Logo of wizard with calculator." />
                </Link>
                <div className="nav-link-container">
                    <Link to="/" class="link">Home</Link>
                    <Link to="../pages/MeetTheTeam/MeetTheTeam.js" class="link">Meet The Team</Link>
                    <Link to="../pages/FlashCards/FlashCards.js" class="link">Make Flashcards</Link>
                </div>
            </nav>
        </header>
        </>
    );
}

export default NavBar;