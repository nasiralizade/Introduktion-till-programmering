  bool svar1 = fodelsedag(födelsedag);
    while (svar1 != 1)
    {
        cout << "Ogiltigt födelsedag, försök igen! ";
        cin >> födelsedag;
        bool svar1 = fodelsedag(födelsedag);
        if (svar1)
        {
            cout << födelsedag << ": Giltigt" << endl;
            break;
        }
        else
            cout << "Ogiltigt, Försök igen:  " << endl;
    }