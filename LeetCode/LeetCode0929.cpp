//
//  main.cpp
//  LeedCode0929
//
//  Created by Nuri Ra on 20.02.19.
//  Copyright © 2019 Nuri Ra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

std::string organizeEmail(std::string* email)
{
    size_t atPos = email->find("@");
    size_t uqPos;
    
    std::string* local;
    std::string* domain;
    
    local->assign(email->begin(), email->begin()+atPos);
    domain->assign(email->begin()+atPos+1, email->end());
    
    uqPos = local->find("+");
    
    if(uqPos > 0)
        local->assign(local->begin(), local->begin()+uqPos);
    
    uqPos = local->find(".");
    
    if(uqPos > 0)
    {
        while(uqPos != std::string::npos)
        {
            local->erase(local->begin()+uqPos);
            uqPos = local->find(".", uqPos+1);
        }
    }

    *email = *local + "@" + *domain;
    
    delete local;
    delete domain;
    
    return *email;
}

int numUniqueEmails2(std::vector<std::string>& emails) {
    int i = 0, result = 0;
    
    for(i = 0; i < emails.size() ; i++)
    {
        std::cout << emails[i] << "\n";
        
        emails[i] = organizeEmail(&emails[i]);
    
        std::cout << emails[i] << "\n";
    }
    
    auto remain = unique(emails.begin(), emails.end());
    emails.erase(remain, emails.end());
    
    result = (int)emails.size();
    
    return result;
}

// Runtime: 40 ms, faster than 50.75% of C++ online submissions for Unique Email Addresses.
// Memory Usage: 14.2 MB, less than 54.48% of C++ online submissions for Unique Email Addresses.

int numUniqueEmails(vector<string>& emails) {
    int i = 0, result = 0;
    size_t atPos, uqPos;
    
    for(i = 0; i < emails.size() ; i++)
    {
        atPos = emails[i].find("@");
        
        string local = emails[i].substr(0, atPos);
        string domain = emails[i].substr(atPos+1);
        
        uqPos = local.find("+");
        
        if(uqPos > 0)
            local = local.substr(0, uqPos);
        
        uqPos = local.find(".");
        
        if(uqPos > 0)
            while(uqPos != std::string::npos)
            {
                local.replace(uqPos, 1, "");
                uqPos = local.find(".", uqPos+1);
            }
        
        emails[i] = local + "@" + domain;
    }
    
    sort(emails.begin(), emails.end());
    auto remain = unique(emails.begin(), emails.end());
    emails.erase(remain, emails.end());
    
    result = emails.size();
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    std::vector<std::string> emails(17);
    
    emails[0] = "fg.r.u.uzj+o.pw@kziczvh.com";
    emails[1] = "r.cyo.g+d.h+b.ja@tgsg.z.com";
    emails[2] = "fg.r.u.uzj+o.f.d@kziczvh.com";
    emails[3] = "r.cyo.g+ng.r.iq@tgsg.z.com";
    emails[4] = "fg.r.u.uzj+lp.k@kziczvh.com";
    emails[5] = "r.cyo.g+n.h.e+n.g@tgsg.z.com";
    emails[6] = "fg.r.u.uzj+k+p.j@kziczvh.com";
    emails[7] = "fg.r.u.uzj+w.y+b@kziczvh.com";
    emails[8] = "r.cyo.g+x+d.c+f.t@tgsg.z.com";
    emails[9] = "r.cyo.g+x+t.y.l.i@tgsg.z.com";
    emails[10] = "r.cyo.g+brxxi@tgsg.z.com";
    emails[11] = "r.cyo.g+z+dr.k.u@tgsg.z.com";
    emails[12] = "r.cyo.g+d+l.c.n+g@tgsg.z.com";
    emails[13] = "fg.r.u.uzj+vq.o@kziczvh.com";
    emails[14] = "fg.r.u.uzj+uzq@kziczvh.com";
    emails[15] = "fg.r.u.uzj+mvz@kziczvh.com";
    emails[16] = "fg.r.u.uzj+taj@kziczvh.com";
    emails[17] = "fg.r.u.uzj+fek@kziczvh.com";
    
    int i = numUniqueEmails(emails);
    
    std::cout << i << "\n";
    
    return 0;
}


