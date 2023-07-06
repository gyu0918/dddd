package Spring.springboot.controller;


import Spring.springboot.domain.Member;
import Spring.springboot.service.MemberService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

@Controller
public class MemberController {
    private final MemberService memberService;

    @Autowired                                                   //springContainer 에서 memberService를 가져오는 역할을한다.
    public MemberController(MemberService memberService) {
        this.memberService = memberService;                          //디펜던신인젝션 : 의존관계를 넣어주는 방법
    }

    @GetMapping("/members/new")
    public String createForm(){
        return "members/createMemberForm";
    }

    /**
     * 회원 이름
     */
    @PostMapping("/members/new")
    public String create(MemberForm form){
        Member member = new Member();
        member.setName(form.getName());

        memberService.join(member);
        return "redirect:/";
    }

    /**
     *
     */
    @GetMapping("/members")
    public String list(Model model){
        List<Member> members = memberService.findMembers();
        model.addAttribute("members", members);
        return "members/memberList";
    }
}
