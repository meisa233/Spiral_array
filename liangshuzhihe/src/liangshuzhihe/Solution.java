package liangshuzhihe;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


class Solution {
    public static ListNode CreateSingleLinkImpl(int val) {
    	ListNode header=null;
    	header=new ListNode(val);
    	header.next=null;
    	return header;
    	
    }
    public static void InsertNewNode(int val, ListNode old) {
    	ListNode newNode=new ListNode(val); 
    	ListNode tmp=old;
    	while(tmp.next!=null) {
    	tmp=tmp.next;}
    	tmp.next=newNode;
    }
    
    public static int Reverse(int a) {
    	int b=0;
    	while(a!=0) {
    		b=a%10+b*10;
    		a=a/10;
    	}
    	return b;
    }
    
    public static int List2int(ListNode node) {
    	int sum=0;
    	while(node.next!=null) {
    		sum=node.val+sum*10;
    		node=node.next;
    	}
    	sum=node.val+sum*10;
    	return sum;
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	int sum=0;
    	int Re_sum;
        
   // 	int num1=List2int(l1);
  //  	int num2=List2int(l2);
    	ListNode Result2=new ListNode(0);  
        ListNode tmp=l1,tmp2=l2;
        int tmp_val=0,tmp_carry=0;
        int tmpl1_val=0,tmpl2_val=0;
        
        while(tmp!=null||tmp2!=null) {
        	if(tmp!=null) {
        	if(tmp.val>=0&&tmp.val<=9)tmpl1_val=tmp.val;}
        	else tmpl1_val=0;
        	
        	if(tmp2!=null) {
        	if(tmp2.val>=0&&tmp2.val<=9)tmpl2_val=tmp2.val;}
        	else tmpl2_val=0;
        	
        	if(tmpl1_val+tmpl2_val+tmp_carry<10) {
        		tmp_val=tmpl1_val+tmpl2_val+tmp_carry;
        		tmp_carry=0;
        	}
        	else {
        		tmp_val=tmpl1_val+tmpl2_val+tmp_carry-10;
        		tmp_carry=1;
        	}
        	
        	InsertNewNode(tmp_val,Result2);
        	if(tmp!=null)
        	if(tmp.next==null) {tmpl1_val=0;tmp=null;}
        	else {tmp=tmp.next;}
        	
        	if(tmp2!=null)
        	if(tmp2.next==null) {tmpl2_val=0;tmp2=null;}
        	else {tmp2=tmp2.next;}
        	
        	if(tmp==null&&tmp2==null&&tmp_carry>0) {
        		InsertNewNode(tmp_carry,Result2);
        	}
        
    }
        return Result2;}
    
   // 	sum=Reverse(List2int(l1))+Reverse(List2int(l2));
    	//Re_sum=Reverse(sum);
   // 	ListNode Result=new ListNode(sum%10);   
   // 	sum=sum/10;
   // 	while(sum!=0) {
   // 		InsertNewNode(sum%10,Result);
    //		sum/=10;
   // 	}
	//	return Result;
        
    
    
    public static void main(String args[]) {
    	String str1="[9]";
    	String str2="[1,9,9,9,9,9,9,9,9,9]";
    	
    	String str2list1=str1.substring(1,str1.length()-1);
    	String str2list2=str2.substring(1,str2.length()-1);
    	
    	String[] list1=str2list1.split(",");
    	String[] list2=str2list2.split(",");
    	ListNode l1=CreateSingleLinkImpl(Integer.parseInt(list1[0]));
    	ListNode l2=CreateSingleLinkImpl(Integer.parseInt(list2[0]));
    	for(int i=1;i<list1.length;i++) {
    		InsertNewNode(Integer.parseInt(list1[i]), l1);
    	}
    	for(int i=1;i<list2.length;i++) {	
  		InsertNewNode(Integer.parseInt(list2[i]), l2);}
    	 ListNode Result= addTwoNumbers(l1,l2);
    	 System.out.print(Result.next.next.val);
    }
}
