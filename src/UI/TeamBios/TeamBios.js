function TeamBios({BioPhotoOne, OneAlt, OneName, OneBio, BioPhotoTwo, TwoAlt, TwoName, TwoBio}) {
    return (
        <>
        <div className="main-bio-container">
            <div className="bio-one-container bio-container">
                <div className="bio-content">
                    <h2>{OneName}</h2>
                    <p>{OneBio}</p>
                </div>
                <div className="bio-one-image bio-img">
                    <img src={BioPhotoOne} alt={OneAlt} />
                </div>
            </div>

            <div className="bio-two-container bio-container">
                <div className="bio-two-image bio-img">
                    <img src={BioPhotoTwo} alt={TwoAlt} />
                </div>
                <div className="bio-content">
                    <h2>{TwoName}</h2>
                    <p>{TwoBio}</p>
                </div>
            </div>
        </div>
        </>
    );
}

export default TeamBios;